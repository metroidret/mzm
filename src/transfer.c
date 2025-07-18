#include "cable_link.h"
#include "macros.h"
#include "gba.h"
#include "transfer.h"

#include "constants/transfer.h"
#include "structs/cable_link.h"
#include "structs/transfer.h"

static u16 TransferHandleTransfer(u32 transferMode, u32 size, const u32* pData, u32* recvBuffer);
static u16 TransferDetermineSendRecvState(u8 transferMode);
static void TransferSetUpTransferManager(u32 size, const u32* pData, u32* recvBuffer);
static void TransferInitTimer(void);
static void TransferStartTransfer(void);
static void TransferStopTimer(void);
static void TransferBackupIoRegs(void);
static void TransferRetrieveIoRegs(void);

/**
 * @brief 8980c | ac | Process the serial transfer
 * 
 * @param size Data size
 * @param pData Pointer to data to transfer
 * @return u32 Result of serial transfer update, 0 is finished, otherwise failure
 */
u32 TransferProcessSend(u32 size, const u32* pData)
{
    // pData is transfer rom, size is size of transfer rom
    u32 result;

    TransferBackupIoRegs();

    while (TRUE)
    {
        // bits 0-1 is gTransferManager.dataTransferStage, bits 2-3 is gTransferManager.verifyTransferResult
        // bits 4-7 is gTransferManager.errorDuringTransfer, bits 8+ is gTransferManager.unk_2
        gTransferUpdateResult = TransferHandleTransfer(1, size, pData, NULL);

        // if serial transfer stopped and the data was verified
        if ((gTransferUpdateResult & TRANSFER_DATA_STAGE_MASK) == TRANSFER_DATA_STAGE_NONE && gTransferUpdateResult & TRANSFER_VERIFY_MASK)
        {
            result = 0;
            break;
        }

        if (gTransferUpdateResult & (TRANSFER_ERROR_UNK2 << TRANSFER_ERROR_SHIFT))
        {
            result = 1;
            break;
        }

        if (gTransferUpdateResult & (TRANSFER_ERROR_VERIFY_TIMEOUT << TRANSFER_ERROR_SHIFT))
        {
            result = 2;
            break;
        }

        if (gTransferUpdateResult & (TRANSFER_ERROR_INIT_TIMEOUT << TRANSFER_ERROR_SHIFT))
        {
            result = 3;
            break;
        }

        if (gTransferUpdateResult & (TRANSFER_ERROR_INIT_TOO_MANY_CONNECTIONS << TRANSFER_ERROR_SHIFT))
        {
            result = 4;
            break;
        }

        // Only reaches here if verifyTransferResult is 0
        if (gIoTransferInfo.pFunction)
            gIoTransferInfo.pFunction(); // always FileSelectProcessOAM?

        VBlankIntrWait();
    }

    CPU_FILL_32(0, &gTransferManager, sizeof(gTransferManager));

    TransferRetrieveIoRegs();

    return result;
}

/**
 * @brief 898b8 | 54 | Initialize data for transfer
 * 
 */
static void TransferInit(void)
{
    gTransferUnk_30058aa = 0;
    gTransferDataTimer = 0;
    gTransferStartupTimer = 0;
    gTransferUnk_30058af = 0;
    gTransferGbaDetectedCount = 0;
    gTransferGbaId = 0;

    CPU_FILL_32(0, &gTransferManager, sizeof(gTransferManager));
}

/**
 * @brief 8990c | 40 | Stop serial transfer and timer 3
 * 
 */
static void TransferCloseSerial(void)
{
    // Disable timer 3 and serial interrupt
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~(IF_TIMER3 | IF_SERIAL));
    WRITE_16(REG_IME, TRUE);

    // Reset timer 3 and serial and acknowledge outstanding interrupt requests
    WRITE_16(REG_SIO, 0);
    WRITE_16(REG_TM3CNT_H, 0);
    WRITE_16(REG_IF, IF_TIMER3 | IF_SERIAL);
}

/**
 * @brief 8994c | 58 | Set serial transfer to multi mode
 * 
 */
static void TransferOpenSerialMulti(void)
{
    // Disable timer 3 and serial interrupt
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_IE, READ_16(REG_IE) & ~(IF_TIMER3 | IF_SERIAL));
    WRITE_16(REG_IME, TRUE);

    WRITE_16(REG_RNCT, 0);

    // Multi mode, baud rate = 115200 bits per second, request interrupt upon completion
    WRITE_16(REG_SIO, SIO_MULTI_MODE);
    WRITE_16(REG_SIO, READ_16(REG_SIO) | SIO_BAUD_RATE_115200 | SIO_IRQ_ENABLE);

    // Enable serial port interrupt
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_IE, READ_16(REG_IE) | IF_SERIAL);
    WRITE_16(REG_IME, TRUE);
}

/**
 * @brief 899a4 | 24 | Set serial transfer to 32 bit transfer and set serial out to ready
 * 
 */
static void TransferOpenSerial32(void)
{
    WRITE_16(REG_RNCT, 0);
    WRITE_16(REG_SIO, SIO_32BIT_MODE | SIO_IRQ_ENABLE);
    WRITE_16(REG_SIO, READ_16(REG_SIO) | SIO_MULTI_CONNECTION_READY);
}

/**
 * @brief 899c8 | 174 | Handle the serial transfer
 * 
 * @param transferMode (Unused) Transfer mode, 0 is receiving, 1 is sending
 * @param Size Data size
 * @param pData Pointer to data to transfer
 * @param recvBuffer (Unused) Pointer to data to receive
 * @return u16 Bits 0-1 is dataTransferStage, bits 2-3 is verifyTransferResult, bits 4-7 is errorDuringTransfer, bits 8+ is unk_2
 */
static u16 TransferHandleTransfer(u32 transferMode, u32 size, const u32* pData, u32* recvBuffer)
{
    // pData is transfer rom, size is size of transfer rom
    switch (gTransferManager.status.stage)
    {
        case TRANSFER_STAGE_INIT:
            // Clear and set up transfer
            TransferInit();
            TransferOpenSerialMulti();
            gTransferManager.status.dataTransferStage = TRANSFER_DATA_STAGE_INIT;
            gTransferManager.status.stage = TRANSFER_STAGE_SETUP_CONNECTION;
            break;

        case TRANSFER_STAGE_SETUP_CONNECTION:
            if (TransferDetermineSendRecvState(TRUE))
                TransferStartTransfer();

            if (gTransferManager.status.errorDuringTransfer != TRANSFER_ERROR_NONE)
                gTransferManager.status.stage = TRANSFER_STAGE_TERMINATE_CONNECTION;

            APPLY_DELTA_TIME_INC(gTransferStartupTimer);
            // If more than half a second passes, fail
            if (gTransferStartupTimer > CONVERT_SECONDS(.5f))
            {
                gTransferManager.status.errorDuringTransfer = TRANSFER_ERROR_INIT_TIMEOUT;
                gTransferManager.status.stage = TRANSFER_STAGE_TERMINATE_CONNECTION;
            }
            break;

        case TRANSFER_STAGE_SETUP_DATA:
            // Set up transmission for size of data to transfer?
            TransferOpenSerial32();
            TransferSetUpTransferManager(size, pData, recvBuffer);
            gTransferManager.status.stage = TRANSFER_STAGE_TRANSFER_DATA;

        case TRANSFER_STAGE_TRANSFER_DATA:
            if (gTransferManager.status.dataTransferStage == TRANSFER_DATA_STAGE_SENDING)
                break;

            if (gTransferManager.status.isParent)
            {
                APPLY_DELTA_TIME_INC(gTransferDataTimer);
                if (gTransferDataTimer >= CONVERT_SECONDS(1.f / 6))
                {
                    TransferStartTransfer();
                    gTransferManager.status.dataTransferStage = TRANSFER_DATA_STAGE_SENDING;
                    break;
                }
            }
            
            TransferStartTransfer();
            gTransferManager.status.dataTransferStage = TRANSFER_DATA_STAGE_SENDING;
            break;

        case TRANSFER_STAGE_SETUP_VERIFICATION:
            TransferOpenSerialMulti();
            gTransferManager.status.stage = TRANSFER_STAGE_VERIFY_DATA;
            break;

        case TRANSFER_STAGE_VERIFY_DATA:
            if (gTransferManager.status.isParent == TRUE && gTransferDataTimer >= CONVERT_SECONDS(1.f / 6))
                TransferStartTransfer();

            APPLY_DELTA_TIME_INC(gTransferDataTimer);
            if (gTransferDataTimer > CONVERT_SECONDS(.5f))
            {
                gTransferManager.status.errorDuringTransfer = TRANSFER_ERROR_VERIFY_TIMEOUT;
                gTransferManager.status.stage = TRANSFER_STAGE_TERMINATE_CONNECTION;
            }
            break;

        case TRANSFER_STAGE_TERMINATE_CONNECTION:
            if (gTransferManager.status.dataTransferStage != TRANSFER_DATA_STAGE_NONE)
            {
                TransferCloseSerial();
                gTransferManager.status.dataTransferStage = TRANSFER_DATA_STAGE_NONE;
            }
            break;
    }

    gTransferManager.status.unk_2 = gTransferManager.data.cursor * 100 / gTransferManager.data.sizeInt;

    return gTransferManager.status.dataTransferStage << TRANSFER_DATA_STAGE_SHIFT | 
           gTransferManager.status.verifyTransferResult << TRANSFER_VERIFY_SHIFT | 
           gTransferManager.status.errorDuringTransfer << TRANSFER_ERROR_SHIFT | 
           gTransferManager.status.unk_2 << 8;
}

/**
 * @brief 89b3c | 34 | Determine if all GBAs are ready and the GBA is the parent or child
 * 
 * @param transferMode Transfer mode, 0 is receiving, 1 is sending
 * @return u16 bool Is GBA parent
 */
static u16 TransferDetermineSendRecvState(u8 transferMode)
{
    u16 isParent;
    // If all GBAs are ready and is currently the parent GBA
    if ((READ_32(REG_SIO) & (SIO_MULTI_CONNECTION_READY | SIO_MULTI_RECEIVE_ID)) == (SIO_MULTI_CONNECTION_READY | SIO_MULTI_PARENT) && transferMode  != 0)
    {
        isParent = gTransferManager.status.isParent = TRUE;
    }
    else
    {
        isParent = gTransferManager.status.isParent = FALSE;
    }
    return isParent;
}

/**
 * @brief 89b70 | 30 | Set up the data to transfer
 * 
 * @param size Data size
 * @param pData Pointer to data to send
 * @param recvBuffer (Unused) Pointer to data to receive
 */
static void TransferSetUpTransferManager(u32 size, const u32* pData, u32* recvBuffer)
{
    WRITE_16(REG_SIO, READ_16(REG_SIO) | SIO_BAUD_RATE_38400);
    
    gTransferManager.data.pData = pData;
    WRITE_32(REG_SIO_MULTI, size); // transmit the size of data to transfer

    gTransferManager.data.sizeInt = (size / sizeof(u32)) + 1; // 32740 / 4 + 1 = 8186

    TransferInitTimer();
}

/**
 * @brief 89ba0 | 34 | Initialize timer 3 for transfer
 * 
 */
static void TransferInitTimer(void)
{
    // Load -101 into timer 3 (what is -101?)
    WRITE_16(REG_TM3CNT_L, -101);
    WRITE_16(REG_TM3CNT_H, TIMER_CONTROL_IRQ_ENABLE);

    // Enable timer 3 interrupt
    WRITE_16(REG_IME, FALSE);
    WRITE_16(REG_IE, READ_16(REG_IE) | IF_TIMER3);
    WRITE_16(REG_IME, TRUE);
}

/**
 * @brief 89bd4 | 10 | Reload timer 3 and start serial transfer
 * 
 */
void TransferReloadTransfer(void)
{
    // Called when timer 3 interrupts
    TransferStopTimer();
    TransferStartTransfer();
}

/**
 * @brief 89be4 | 180 | Exchange data over serial
 * 
 */
void TransferExchangeData(void)
{
    // Called when serial communication interrupts
    u16 recv[4];
    u32 control;
    u16 i;
    u16 numGbaDetected;
    u16 numGbaSendingData;

    control = READ_32(REG_SIO);

    switch (gTransferManager.status.stage)
    {
        case TRANSFER_STAGE_SETUP_CONNECTION:
            WRITE_16(REG_SIO_DATA8, TRANSFER_HANDSHAKE); // Outgoing data
            WRITE_64(recv, READ_64(REG_SIO_MULTI));

            i = 0;
            numGbaDetected = 0;
            numGbaSendingData = 0;

            for (; i < ARRAY_SIZE(recv); i++)
            {
                // if GBA either sent or is receiving data
                if (recv[i] == TRANSFER_HANDSHAKE)
                    numGbaDetected++;
                // if receiving some data
                else if (recv[i] != USHORT_MAX)
                    numGbaSendingData++;
            }

            gTransferGbaDetectedCount = numGbaDetected;
            gTransferGbaId = (control << 26) >> 30; // SIO_MULTI_CONNECTION_ID_FLAG

            // If 0-2 GBAs detected
            if (numGbaDetected <= 2)
            {
                // If 2 GBAs detected and not sending anymore data
                if (numGbaDetected >= 2 && numGbaSendingData == 0)
                    gTransferManager.status.stage = TRANSFER_STAGE_SETUP_DATA;
            }
            else
                gTransferManager.status.errorDuringTransfer = TRANSFER_ERROR_INIT_TOO_MANY_CONNECTIONS;
            break;

        case TRANSFER_STAGE_TRANSFER_DATA:
            READ_32(REG_SIO_MULTI); // why the read?

            // If data still left to transfer
            if (gTransferManager.data.cursor < gTransferManager.data.sizeInt)
            {
                // Transfer current byte and update checksum
                WRITE_32(REG_SIO_MULTI, gTransferManager.data.pData[gTransferManager.data.cursor]);
                gTransferManager.data.checksum += gTransferManager.data.pData[gTransferManager.data.cursor];
            }
            // If data all transferred
            else if (gTransferManager.data.cursor == gTransferManager.data.sizeInt)
            {
                // Transfer checksum
                WRITE_32(REG_SIO_MULTI, gTransferManager.data.checksum);
            }
            // Sanity check to make sure more data than available not transferred?
            else
            {
                WRITE_32(REG_SIO_MULTI, 0);
            }

            gTransferManager.data.cursor++;

            // Continue timer if still data to transfer (extra time for each GBA active?)
            if (gTransferManager.data.cursor < gTransferManager.data.sizeInt + gTransferGbaDetectedCount)
            {
                WRITE_16(REG_TM3CNT_H, READ_16(REG_TM3CNT_H) | TIMER_CONTROL_ACTIVE);
            }
            else
            {
                gTransferManager.status.stage = TRANSFER_STAGE_SETUP_VERIFICATION;
                gTransferDataTimer = 0;
            }
            break;

        case TRANSFER_STAGE_VERIFY_DATA:
            WRITE_64(recv, READ_64(REG_SIO_MULTI));

            i = 1; // start from GBA receiving data?
            numGbaDetected = 1;

            for (i; i < gTransferGbaDetectedCount; i++)
            {
                // if child GBA 1 correctly sends 1
                if (recv[i] == 1)
                    numGbaDetected++;
                // if another child GBA sends 1 (this shouldn't happen?)
                else if (recv[i] == 2)
                {
                    gTransferManager.status.verifyTransferResult = TRANSFER_VERIFY_FAILURE;
                    gTransferManager.status.stage = TRANSFER_STAGE_TERMINATE_CONNECTION;
                    break;
                }

                // Check if correct number of GBAs sent correct data
                if (numGbaDetected == gTransferGbaDetectedCount)
                {
                    gTransferManager.status.verifyTransferResult = TRANSFER_VERIFY_SUCCESS;
                    gTransferManager.status.stage = TRANSFER_STAGE_TERMINATE_CONNECTION;
                }
            }
            break;
    }
}

/**
 * @brief 89d64 | 10 | Start a serial transfer
 * 
 */
static void TransferStartTransfer(void)
{
    WRITE_16(REG_SIO, READ_16(REG_SIO) | SIO_START_BIT_ACTIVE);
}

/**
 * @brief 89d74 | 24 | Stop and reload timer 3
 * 
 */
static void TransferStopTimer(void)
{
    WRITE_16(REG_TM3CNT_H, READ_16(REG_TM3CNT_H) & ~TIMER_CONTROL_ACTIVE);
    WRITE_16(REG_TM3CNT_L, -101);
}

/**
 * @brief 89d98 | 54 | Makes a backup of the registers used for transfer
 * 
 */
static void TransferBackupIoRegs(void)
{
    gRegIme_Backup = READ_16(REG_IME);
    gRegIe_Backup = READ_16(REG_IE);
    gRegTm3Cnt_H_Backup = READ_16(REG_TM3CNT_H);
    gRegSiocnt_Backup = READ_16(REG_SIO);
    gRegRcnt_Backup = READ_16(REG_RNCT);
}

/**
 * @brief 89dec | 44 | Retrieves the registers used for transfer from the backups
 * 
 */
static void TransferRetrieveIoRegs(void)
{
    WRITE_16(REG_IME, gRegIme_Backup);
    WRITE_16(REG_IE, gRegIe_Backup);
    WRITE_16(REG_TM3CNT_H, gRegTm3Cnt_H_Backup);
    WRITE_16(REG_SIO, gRegSiocnt_Backup);
    WRITE_16(REG_RNCT, gRegRcnt_Backup);
}
