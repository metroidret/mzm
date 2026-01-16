    .include "asm/constants.inc"
    .include "asm/macros.inc"
	.include "asm/emulator_constants.inc"

    .syntax unified

	arm_func_start sub_0600B000
sub_0600B000: @ 0x0600B000
	and r0, r0, #0xff
	strb r1, [sp, r0]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	ldr pc, _0600B13C @ =_03005398

	arm_func_start sub_0600B018
sub_0600B018: @ 0x0600B018
	bic r0, fp, #0x100000 @ r0 = fp & ~0x00100000 (no effect?)
	tst r1, #0x10           @ if r1 & 0x10:
	orrne r0, r0, #0x100000     @ r0 |= 0x00100000
	cmp r0, fp              @ if r0 != fp:
	orrne fp, r0, #0x80000      @ r0 |= 0x00080000
	strb r1, [sp, #SP_8BC] @ SP_8BC = r1
	ldrb r2, [sp, #SP_9C1]
	and r0, r1, #1
	and r2, r2, #2
	orr r0, r0, r2
	strb r0, [sp, #SP_9C1] @ SP_9C1 = (r1 & 1) | (SP_9C1 & 2)
	and r0, r1, #3
	strb r0, [sp, #SP_9C5] @ SP_9C5 = r1 & 3
	ldrb r1, [sp, #SP_A38]
	cmp r1, #0       @ if SP_A38 == 0:
	beq sub_0600B068     @ goto sub_0600B068
	ldr r2, [sp, #SP_8B4]
	cmp r2, r1       @ if SP_8B4 > SP_A38:
	bhs sub_0600B068     @ goto sub_0600B068
	strb r0, [sp, #SP_9C1] @ SP_9C1 = SP_9C5

	arm_func_start sub_0600B068
sub_0600B068: @ 0x0600B068
	cmp r4, #0                 @ if r4 < 0:
	ldrblt r1, [r5], #1            @ r1 = *r5++
	ldrlt pc, [ip, r1, lsl #2]     @ goto ip[r1]
	@ goto _03005398
	ldr pc, _0600B140 @ =_03005398

	arm_func_start sub_0600B078
sub_0600B078: @ 0x0600B078
	add r2, sp, r0 @ WARNING: disassembler produces wrong instruction here
	strb r1, [r2, #SP_8BC] @ SP_*BC + r0 = r1
	cmp r4, #0                 @ if r4 < 0:
	ldrblt r1, [r5], #1            @ r1 = *r5++
	ldrlt pc, [ip, r1, lsl #2]     @ goto ip[r1]
	@ goto _0600B144
	ldr pc, _0600B144 @ =_03005398

	arm_func_start sub_0600B090
sub_0600B090: @ 0x0600B090
	tst fp, #0x200000
	eor fp, fp, #0x200000
	bne _0600B0B0
	strb r1, [sp, #SP_A39]
_0600B0A0:
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	ldr pc, _0600B148 @ =_03005398
_0600B0B0:
	strb r1, [sp, #SP_9C4]
	ldrb r0, [sp, #SP_A38]
	cmp r0, #0
	beq _0600B0A0
	ldr r2, [sp, #SP_8B4]
	cmp r2, r0
	bhs _0600B0A0
	add r1, r1, r2
	strb r1, [sp, #SP_9C0]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	ldr pc, _0600B14C @ =_03005398
	.global _0600B0E4
_0600B0E4:
	.byte 0x90, 0x3B, 0x00, 0x06, 0x02, 0x6D, 0x6C, 0x20, 0x67, 0x6B, 0x4D, 0x27
	.byte 0x47, 0x48, 0x4B, 0x20, 0x4D, 0x48, 0x4B, 0x4B, 0x68, 0x00, 0x00, 0x00, 0xD0, 0x3B, 0x00, 0x06
	.byte 0x2C, 0x6C, 0x67, 0x4B, 0x69, 0x20, 0x68, 0x2D, 0x4B, 0x4D, 0x4D, 0x00, 0x16, 0x3C, 0x00, 0x06
	.byte 0x01, 0x48, 0x49, 0x2D, 0x49, 0x4D, 0x4B, 0x48, 0x4B, 0x2B, 0x6D, 0x00, 0x50, 0x3C, 0x00, 0x06
	.byte 0x02, 0x4D, 0x6B, 0x2C, 0x2E, 0x48, 0x6D, 0x27, 0x4C, 0x4B, 0x6C, 0x2E, 0x4D, 0x48, 0x29, 0x2A
	.byte 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
	.global _0600B138
_0600B138: .4byte 0xFFFFFFFF
_0600B13C: .4byte _03005398
_0600B140: .4byte _03005398
_0600B144: .4byte _03005398
_0600B148: .4byte _03005398
_0600B14C: .4byte _03005398
