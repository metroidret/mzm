    .include "asm/constants.inc"
    .include "asm/macros.inc"

    .syntax unified

	thumb_func_start sub_03000590
sub_03000590: @ 0x03000590
	push {r0, r1, r2, r3}
	add sp, #0x10
	bx lr
	.align 2, 0

	thumb_func_start sub_03000598
sub_03000598: @ 0x03000598
	bx lr
	.align 2, 0

	thumb_func_start sub_0300059C
sub_0300059C: @ 0x0300059C
	bx pc
	nop

	arm_func_start sub_030005A0
sub_030005A0: @ 0x030005A0
	push {r4, r5, r6}
	mov r5, r0
	mov r6, r1
_030005AC:
	ldrb r4, [r0], #1
	cmp r4, #0
	beq _030005CC
	subs r1, r1, #1
	bne _030005AC
	mov r0, r5
	mov r1, r6
	b _030005E0
_030005CC:
	mov ip, #0
	strb r4, [r0], #1
	subs r1, r1, #1
	bhi _030005CC
	b _0300060C
_030005E0:
	mov ip, #1
_030005E4:
	mov r3, r2
_030005E8:
	ldrb r4, [r0]
	subs r4, r4, ip
	movmi r4, #0
	strb r4, [r0], #1
	subs r3, r3, #1
	bhi _030005E8
	add ip, ip, #1
	subs r1, r1, r2
	bhi _030005E4
_0300060C:
	pop {r4, r5, r6}
	bx lr

	thumb_func_start sub_03000614
sub_03000614: @ 0x03000614
	bx lr
	.align 2, 0

	thumb_func_start sub_03000618
sub_03000618: @ 0x03000618
	bx pc
	nop

	arm_func_start sub_0300061C
sub_0300061C: @ 0x0300061C
	mov r2, #0
_03000620:
	str r2, [r0], #4
	subs r1, r1, #4
	bhi _03000620
	bx lr

	thumb_func_start sub_03000630
sub_03000630: @ 0x03000630
	bx lr
	.align 2, 0

	thumb_func_start sub_03000634
sub_03000634: @ 0x03000634
	bx pc
	nop

	arm_func_start sub_03000638
sub_03000638: @ 0x03000638
	push {r4, r5}
	ldr r2, _03000978 @ =gEmuAudio_Pulse1_BufferPtr
	ldr r2, [r2]
	ldr r3, _0300097C @ =gEmuAudio_Pulse2_BufferPtr
	ldr r3, [r3]
	ldr r4, _03000980 @ =gEmuAudio_Triangle_BufferPtr
	ldr r4, [r4]
	ldr r5, _03000984 @ =gEmuAudio_Noise_BufferPtr
	ldr r5, [r5]
	mov ip, #0
_03000660:
	msr apsr_nzcvq, r0
	strmi ip, [r2], #4
	streq ip, [r3], #4
	strhs ip, [r4], #4
	strvs ip, [r5], #4
	subs r1, r1, #4
	bhi _03000660
	pop {r4, r5}
	bx lr

	thumb_func_start sub_03000684
sub_03000684: @ 0x03000684
	bx lr
	.align 2, 0

	thumb_func_start sub_03000688
sub_03000688: @ 0x03000688
	bx pc
	nop

	arm_func_start sub_0300068C
sub_0300068C: @ 0x0300068C
	ldr r3, _03000988 @ =0x03005FE0
	ldrsb r3, [r3]
_03000694:
	ldrsb ip, [r0]
	add r3, ip, r3
	asr r3, r3, #1
	strb r3, [r0], #1
	ldrsb r3, [r0]
	add ip, ip, r3
	asr ip, ip, #1
	strb ip, [r0], #1
	subs r1, r1, #2
	bhi _03000694
	ldr ip, _0300098C @ =0x03005FE0
	strb r3, [ip]
	bx lr

	thumb_func_start sub_030006C8
sub_030006C8: @ 0x030006C8
	bx lr
	.align 2, 0

	thumb_func_start sub_030006CC
sub_030006CC: @ 0x030006CC
	bx pc
	nop

	arm_func_start sub_030006D0
sub_030006D0: @ 0x030006D0
	mov r2, #0x7f
	mvn r3, #0x7f
_030006D8:
	ldrsb ip, [r0]
	add ip, ip, ip
	cmp ip, r2
	movge ip, r2
	cmp ip, r3
	movlt ip, r3
	strb ip, [r0], #1
	subs r1, r1, #1
	bhi _030006D8
	bx lr

	thumb_func_start sub_03000700
sub_03000700: @ 0x03000700
	bx lr
	.align 2, 0

	thumb_func_start sub_03000704
sub_03000704: @ 0x03000704
	bx pc
	nop

	arm_func_start sub_03000708
sub_03000708: @ 0x03000708
	push {r4, r5, r6, r7, r8, sb}
	ldr r2, _03000990 @ =gEmuAudio_Pulse1_BufferPtr
	ldr r2, [r2]
	ldr r3, _03000994 @ =gEmuAudio_Pulse2_BufferPtr
	ldr r3, [r3]
	ldr r4, _03000998 @ =gEmuAudio_Triangle_BufferPtr
	ldr r4, [r4]
	ldr r5, _0300099C @ =gEmuAudio_Noise_BufferPtr
	ldr r5, [r5]
	mov r8, #0x80
	orr r8, r8, r8, lsl #8
	orr r8, r8, r8, lsl #16
_03000738:
	mov ip, r8
	ldr r7, [r2], #4
	add ip, ip, r7
	ldr r7, [r3], #4
	add ip, ip, r7
	ldr r7, [r4], #4
	sub ip, ip, r7
	ldr r7, [r5], #4
	sub ip, ip, r7
	eor ip, ip, r8
	str ip, [r0], #4
	subs r1, r1, #4
	bhi _03000738
	pop {r4, r5, r6, r7, r8, sb}
	bx lr

	thumb_func_start sub_03000774
sub_03000774: @ 0x03000774
	bx lr
	.align 2, 0

	thumb_func_start sub_03000778
sub_03000778: @ 0x03000778
	ldr r1, _03000780 @ =gUnk_03005A90
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_03000780: .4byte gUnk_03005A90

	thumb_func_start EmulatorAudio_Pulse1_SetLengthCounter
EmulatorAudio_Pulse1_SetLengthCounter: @ 0x03000784
	ldr r1, _0300078C @ =gEmuAudio_Pulse1_LengthCounter
	strh r0, [r1]
	bx lr
	.align 2, 0
_0300078C: .4byte gEmuAudio_Pulse1_LengthCounter

	thumb_func_start sub_03000790
sub_03000790: @ 0x03000790
	push {lr}
	ldr r0, _030007A0 @ =gUnk_03005AA4
	ldrh r1, [r0]
	cmp r1, #0
	beq _030007A8
	ldr r1, _030007A4 @ =gUnk_03005AA6
	movs r0, #1
	b _03000800
	.align 2, 0
_030007A0: .4byte gUnk_03005AA4
_030007A4: .4byte gUnk_03005AA6
_030007A8:
	ldr r0, _030007C0 @ =gUnk_03005AA6
	strh r1, [r0]
	ldr r0, _030007C4 @ =gEmuAudio_Pulse1_Vol
	ldrh r2, [r0]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _030007CC
	ldr r1, _030007C8 @ =gUnk_03005A94
	movs r0, #0xf
	ands r0, r2
	b _030007D0
	.align 2, 0
_030007C0: .4byte gUnk_03005AA6
_030007C4: .4byte gEmuAudio_Pulse1_Vol
_030007C8: .4byte gUnk_03005A94
_030007CC:
	ldr r1, _03000808 @ =gUnk_03005A94
	movs r0, #0xf
_030007D0:
	strh r0, [r1]
	ldr r1, _0300080C @ =gUnk_03005AA2
	movs r0, #0xf
	strh r0, [r1]
	ldr r1, _03000810 @ =sEmulatorAudio_LengthCounterTable
	ldr r0, _03000814 @ =gEmuAudio_Pulse1_Hi
	ldrh r0, [r0]
	lsrs r0, r0, #3
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #2
	bl EmulatorAudio_Pulse1_SetLengthCounter
	ldr r0, _03000818 @ =gEmuAudio_SndChn
	ldrh r1, [r0]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _03000802
	ldr r0, _0300081C @ =gEmuAudio_Pulse1_Enable
	strh r2, [r0]
	ldr r1, _03000820 @ =gUnk_03005AA4
	movs r0, #0
_03000800:
	strh r0, [r1]
_03000802:
	pop {r0}
	bx r0
	.align 2, 0
_03000808: .4byte gUnk_03005A94
_0300080C: .4byte gUnk_03005AA2
_03000810: .4byte sEmulatorAudio_LengthCounterTable
_03000814: .4byte gEmuAudio_Pulse1_Hi
_03000818: .4byte gEmuAudio_SndChn
_0300081C: .4byte gEmuAudio_Pulse1_Enable
_03000820: .4byte gUnk_03005AA4

	thumb_func_start sub_03000824
sub_03000824: @ 0x03000824
	push {lr}
	ldr r0, _03000840 @ =gEmuAudio_Pulse1_Enable
	ldrh r0, [r0]
	cmp r0, #0
	beq _0300083A
	ldr r1, _03000844 @ =gUnk_03005AA4
	ldrh r0, [r1]
	cmp r0, #0
	bne _0300083A
	movs r0, #2
	strh r0, [r1]
_0300083A:
	pop {r0}
	bx r0
	.align 2, 0
_03000840: .4byte gEmuAudio_Pulse1_Enable
_03000844: .4byte gUnk_03005AA4

	thumb_func_start sub_03000848
sub_03000848: @ 0x03000848
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r1, _03000864 @ =gUnk_03005AAC
	movs r0, #0
	strb r0, [r1]
	ldr r0, _03000868 @ =gEmuAudio_Pulse1_Timer
	strh r2, [r0]
	cmp r2, #0
	bne _03000870
	ldr r0, _0300086C @ =gUnk_03005A94
	strh r2, [r0]
	b _03000888
	.align 2, 0
_03000864: .4byte gUnk_03005AAC
_03000868: .4byte gEmuAudio_Pulse1_Timer
_0300086C: .4byte gUnk_03005A94
_03000870:
	ldr r4, _03000890 @ =gEmuAudio_Pulse1_Frequency
	adds r1, r2, #1
	ldr r0, _03000894 @ =0x001B4F4D
	bl __udivsi3
	str r0, [r4]
	ldr r2, _03000898 @ =gEmuAudio_Pulse2_Frequency
	ldr r1, [r2]
	cmp r0, r1
	bne _03000888
	subs r0, r1, #1
	str r0, [r2]
_03000888:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_03000890: .4byte gEmuAudio_Pulse1_Frequency
_03000894: .4byte 0x001B4F4D
_03000898: .4byte gEmuAudio_Pulse2_Frequency

	thumb_func_start sub_0300089C
sub_0300089C: @ 0x0300089C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _030008AC @ =gUnk_03005A94
	strh r0, [r1]
	ldr r1, _030008B0 @ =gUnk_03005AA2
	movs r0, #1
	strh r0, [r1]
	bx lr
	.align 2, 0
_030008AC: .4byte gUnk_03005A94
_030008B0: .4byte gUnk_03005AA2

	thumb_func_start EmulatorAudio_Pulse1_WriteVolume
EmulatorAudio_Pulse1_WriteVolume: @ 0x030008B4
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r4, _03000908 @ =gEmuAudio_Pulse1_Vol
	ldrb r1, [r4]
	movs r2, #0x10
	adds r0, r2, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r3, #0
	ands r0, r2
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	strh r3, [r4]
	ldr r2, _0300090C @ =gUnk_03005AAD
	movs r0, #0
	strb r0, [r2]
	movs r0, #0xc0
	ands r0, r3
	cmp r0, #0xc0
	bne _030008E6
	movs r0, #0x7f
	ands r0, r3
	strh r0, [r4]
_030008E6:
	cmp r5, #0
	beq _03000900
	cmp r1, #0
	bne _03000900
	ldr r0, _03000910 @ =gEmuAudio_Pulse1_Enable
	ldrh r0, [r0]
	cmp r0, #0
	beq _03000900
	movs r0, #4
	strb r0, [r2]
	ldr r1, _03000914 @ =gUnk_03005AA2
	movs r0, #1
	strh r0, [r1]
_03000900:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_03000908: .4byte gEmuAudio_Pulse1_Vol
_0300090C: .4byte gUnk_03005AAD
_03000910: .4byte gEmuAudio_Pulse1_Enable
_03000914: .4byte gUnk_03005AA2

	thumb_func_start EmulatorAudio_Pulse1_WriteSweep
EmulatorAudio_Pulse1_WriteSweep: @ 0x03000918
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _03000928 @ =gEmuAudio_Pulse1_Sweep
	strh r0, [r1]
	ldr r1, _0300092C @ =gUnk_03005AAA
	movs r0, #1
	strh r0, [r1]
	bx lr
	.align 2, 0
_03000928: .4byte gEmuAudio_Pulse1_Sweep
_0300092C: .4byte gUnk_03005AAA

	thumb_func_start EmulatorAudio_Pulse1_WriteLo
EmulatorAudio_Pulse1_WriteLo: @ 0x03000930
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _03000940 @ =gEmuAudio_Pulse1_Lo
	strh r0, [r1]
	ldr r1, _03000944 @ =gUnk_03005AAC
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_03000940: .4byte gEmuAudio_Pulse1_Lo
_03000944: .4byte gUnk_03005AAC

	thumb_func_start sub_03000948
sub_03000948: @ 0x03000948
	push {lr}
	ldr r0, _0300096C @ =gUnk_03005AAC
	ldrb r0, [r0]
	cmp r0, #0
	beq _03000966
	ldr r0, _03000970 @ =gEmuAudio_Pulse1_Timer
	ldrh r1, [r0]
	movs r0, #0xf0
	lsls r0, r0, #4
	ands r0, r1
	ldr r1, _03000974 @ =gEmuAudio_Pulse1_Lo
	ldrh r1, [r1]
	orrs r0, r1
	bl sub_03000848
_03000966:
	pop {r0}
	bx r0
	.align 2, 0
_0300096C: .4byte gUnk_03005AAC
_03000970: .4byte gEmuAudio_Pulse1_Timer
_03000974: .4byte gEmuAudio_Pulse1_Lo

_03000978: .4byte gEmuAudio_Pulse1_BufferPtr
_0300097C: .4byte gEmuAudio_Pulse2_BufferPtr
_03000980: .4byte gEmuAudio_Triangle_BufferPtr
_03000984: .4byte gEmuAudio_Noise_BufferPtr

_03000988: .4byte 0x03005FE0
_0300098C: .4byte 0x03005FE0

_03000990: .4byte gEmuAudio_Pulse1_BufferPtr
_03000994: .4byte gEmuAudio_Pulse2_BufferPtr
_03000998: .4byte gEmuAudio_Triangle_BufferPtr
_0300099C: .4byte gEmuAudio_Noise_BufferPtr
