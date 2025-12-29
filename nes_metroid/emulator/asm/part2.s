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
	ldr r2, _03000978 @ =0x03005A80
	ldr r2, [r2]
	ldr r3, _0300097C @ =0x03005A84
	ldr r3, [r3]
	ldr r4, _03000980 @ =0x03005A88
	ldr r4, [r4]
	ldr r5, _03000984 @ =0x03005A8C
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
	ldr r2, _03000990 @ =0x03005A80
	ldr r2, [r2]
	ldr r3, _03000994 @ =0x03005A84
	ldr r3, [r3]
	ldr r4, _03000998 @ =0x03005A88
	ldr r4, [r4]
	ldr r5, _0300099C @ =0x03005A8C
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
	ldr r1, _03000780 @ =0x03005A90
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_03000780: .4byte 0x03005A90

	thumb_func_start sub_03000784
sub_03000784: @ 0x03000784
	ldr r1, _0300078C @ =0x03005AA8
	strh r0, [r1]
	bx lr
	.align 2, 0
_0300078C: .4byte 0x03005AA8

	thumb_func_start sub_03000790
sub_03000790: @ 0x03000790
	push {lr}
	ldr r0, _030007A0 @ =0x03005AA4
	ldrh r1, [r0]
	cmp r1, #0
	beq _030007A8
	ldr r1, _030007A4 @ =0x03005AA6
	movs r0, #1
	b _03000800
	.align 2, 0
_030007A0: .4byte 0x03005AA4
_030007A4: .4byte 0x03005AA6
_030007A8:
	ldr r0, _030007C0 @ =0x03005AA6
	strh r1, [r0]
	ldr r0, _030007C4 @ =0x03005A98
	ldrh r2, [r0]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _030007CC
	ldr r1, _030007C8 @ =0x03005A94
	movs r0, #0xf
	ands r0, r2
	b _030007D0
	.align 2, 0
_030007C0: .4byte 0x03005AA6
_030007C4: .4byte 0x03005A98
_030007C8: .4byte 0x03005A94
_030007CC:
	ldr r1, _03000808 @ =0x03005A94
	movs r0, #0xf
_030007D0:
	strh r0, [r1]
	ldr r1, _0300080C @ =0x03005AA2
	movs r0, #0xf
	strh r0, [r1]
	ldr r1, _03000810 @ =0x030023DC
	ldr r0, _03000814 @ =0x03005A9E
	ldrh r0, [r0]
	lsrs r0, r0, #3
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #2
	bl sub_03000784
	ldr r0, _03000818 @ =0x03005A7A
	ldrh r1, [r0]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _03000802
	ldr r0, _0300081C @ =gUnk_03005FCC
	strh r2, [r0]
	ldr r1, _03000820 @ =0x03005AA4
	movs r0, #0
_03000800:
	strh r0, [r1]
_03000802:
	pop {r0}
	bx r0
	.align 2, 0
_03000808: .4byte 0x03005A94
_0300080C: .4byte 0x03005AA2
_03000810: .4byte 0x030023DC
_03000814: .4byte 0x03005A9E
_03000818: .4byte 0x03005A7A
_0300081C: .4byte gUnk_03005FCC
_03000820: .4byte 0x03005AA4

	thumb_func_start sub_03000824
sub_03000824: @ 0x03000824
	push {lr}
	ldr r0, _03000840 @ =gUnk_03005FCC
	ldrh r0, [r0]
	cmp r0, #0
	beq _0300083A
	ldr r1, _03000844 @ =0x03005AA4
	ldrh r0, [r1]
	cmp r0, #0
	bne _0300083A
	movs r0, #2
	strh r0, [r1]
_0300083A:
	pop {r0}
	bx r0
	.align 2, 0
_03000840: .4byte gUnk_03005FCC
_03000844: .4byte 0x03005AA4

	thumb_func_start sub_03000848
sub_03000848: @ 0x03000848
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r1, _03000864 @ =0x03005AAC
	movs r0, #0
	strb r0, [r1]
	ldr r0, _03000868 @ =0x03005AA0
	strh r2, [r0]
	cmp r2, #0
	bne _03000870
	ldr r0, _0300086C @ =0x03005A94
	strh r2, [r0]
	b _03000888
	.align 2, 0
_03000864: .4byte 0x03005AAC
_03000868: .4byte 0x03005AA0
_0300086C: .4byte 0x03005A94
_03000870:
	ldr r4, _03000890 @ =0x03005FD0
	adds r1, r2, #1
	ldr r0, _03000894 @ =0x001B4F4D
	bl __udivsi3
	str r0, [r4]
	ldr r2, _03000898 @ =0x03005FC4
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
_03000890: .4byte 0x03005FD0
_03000894: .4byte 0x001B4F4D
_03000898: .4byte 0x03005FC4

	thumb_func_start sub_0300089C
sub_0300089C: @ 0x0300089C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _030008AC @ =0x03005A94
	strh r0, [r1]
	ldr r1, _030008B0 @ =0x03005AA2
	movs r0, #1
	strh r0, [r1]
	bx lr
	.align 2, 0
_030008AC: .4byte 0x03005A94
_030008B0: .4byte 0x03005AA2

	thumb_func_start sub_030008B4
sub_030008B4: @ 0x030008B4
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r4, _03000908 @ =0x03005A98
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
	ldr r2, _0300090C @ =0x03005AAD
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
	ldr r0, _03000910 @ =gUnk_03005FCC
	ldrh r0, [r0]
	cmp r0, #0
	beq _03000900
	movs r0, #4
	strb r0, [r2]
	ldr r1, _03000914 @ =0x03005AA2
	movs r0, #1
	strh r0, [r1]
_03000900:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_03000908: .4byte 0x03005A98
_0300090C: .4byte 0x03005AAD
_03000910: .4byte gUnk_03005FCC
_03000914: .4byte 0x03005AA2

	thumb_func_start sub_03000918
sub_03000918: @ 0x03000918
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _03000928 @ =0x03005A9A
	strh r0, [r1]
	ldr r1, _0300092C @ =0x03005AAA
	movs r0, #1
	strh r0, [r1]
	bx lr
	.align 2, 0
_03000928: .4byte 0x03005A9A
_0300092C: .4byte 0x03005AAA

	thumb_func_start sub_03000930
sub_03000930: @ 0x03000930
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _03000940 @ =0x03005A9C
	strh r0, [r1]
	ldr r1, _03000944 @ =0x03005AAC
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_03000940: .4byte 0x03005A9C
_03000944: .4byte 0x03005AAC

	thumb_func_start sub_03000948
sub_03000948: @ 0x03000948
	push {lr}
	ldr r0, _0300096C @ =0x03005AAC
	ldrb r0, [r0]
	cmp r0, #0
	beq _03000966
	ldr r0, _03000970 @ =0x03005AA0
	ldrh r1, [r0]
	movs r0, #0xf0
	lsls r0, r0, #4
	ands r0, r1
	ldr r1, _03000974 @ =0x03005A9C
	ldrh r1, [r1]
	orrs r0, r1
	bl sub_03000848
_03000966:
	pop {r0}
	bx r0
	.align 2, 0
_0300096C: .4byte 0x03005AAC
_03000970: .4byte 0x03005AA0
_03000974: .4byte 0x03005A9C
_03000978: .4byte 0x03005A80
_0300097C: .4byte 0x03005A84
_03000980: .4byte 0x03005A88
_03000984: .4byte 0x03005A8C
_03000988: .4byte 0x03005FE0
_0300098C: .4byte 0x03005FE0
_03000990: .4byte 0x03005A80
_03000994: .4byte 0x03005A84
_03000998: .4byte 0x03005A88
_0300099C: .4byte 0x03005A8C

@ file split

	thumb_func_start sub_030009A0
sub_030009A0: @ 0x030009A0
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r0, _030009D0 @ =0x03005A9E
	strh r1, [r0]
	movs r0, #7
	ands r0, r1
	lsls r0, r0, #8
	ldr r1, _030009D4 @ =0x03005A9C
	ldrh r1, [r1]
	orrs r0, r1
	bl sub_03000848
	ldr r0, _030009D8 @ =gUnk_03005FCC
	ldrh r0, [r0]
	cmp r0, #0
	bne _030009C8
	bl sub_03000778
_030009C8:
	bl sub_03000790
	pop {r0}
	bx r0
	.align 2, 0
_030009D0: .4byte 0x03005A9E
_030009D4: .4byte 0x03005A9C
_030009D8: .4byte gUnk_03005FCC

	thumb_func_start sub_030009DC
sub_030009DC: @ 0x030009DC
	ldr r1, _03000A28 @ =0x03005A90
	movs r0, #0
	str r0, [r1]
	ldr r1, _03000A2C @ =0x03005FD0
	str r0, [r1]
	ldr r1, _03000A30 @ =0x03005A94
	movs r2, #0
	strh r0, [r1]
	ldr r1, _03000A34 @ =0x03005A96
	strh r0, [r1]
	ldr r1, _03000A38 @ =0x03005A98
	strh r0, [r1]
	ldr r1, _03000A3C @ =0x03005A9A
	strh r0, [r1]
	ldr r1, _03000A40 @ =0x03005A9C
	strh r0, [r1]
	ldr r1, _03000A44 @ =0x03005A9E
	strh r0, [r1]
	ldr r1, _03000A48 @ =0x03005AA0
	strh r0, [r1]
	ldr r1, _03000A4C @ =0x03005AA2
	strh r0, [r1]
	ldr r1, _03000A50 @ =gUnk_03005FCC
	strh r0, [r1]
	ldr r1, _03000A54 @ =0x03005AA4
	strh r0, [r1]
	ldr r1, _03000A58 @ =0x03005AA6
	strh r0, [r1]
	ldr r1, _03000A5C @ =0x03005AA8
	strh r0, [r1]
	ldr r1, _03000A60 @ =0x03005AAA
	strh r0, [r1]
	ldr r0, _03000A64 @ =0x03005AAC
	strb r2, [r0]
	ldr r0, _03000A68 @ =0x03005AAD
	strb r2, [r0]
	bx lr
	.align 2, 0
_03000A28: .4byte 0x03005A90
_03000A2C: .4byte 0x03005FD0
_03000A30: .4byte 0x03005A94
_03000A34: .4byte 0x03005A96
_03000A38: .4byte 0x03005A98
_03000A3C: .4byte 0x03005A9A
_03000A40: .4byte 0x03005A9C
_03000A44: .4byte 0x03005A9E
_03000A48: .4byte 0x03005AA0
_03000A4C: .4byte 0x03005AA2
_03000A50: .4byte gUnk_03005FCC
_03000A54: .4byte 0x03005AA4
_03000A58: .4byte 0x03005AA6
_03000A5C: .4byte 0x03005AA8
_03000A60: .4byte 0x03005AAA
_03000A64: .4byte 0x03005AAC
_03000A68: .4byte 0x03005AAD

	thumb_func_start sub_03000A6C
sub_03000A6C: @ 0x03000A6C
	bx pc
	nop

	arm_func_start sub_03000A70
sub_03000A70: @ 0x03000A70
	push {r4, r5, r6, r7, r8, sb, sl}
	ldr r3, _0300125C @ =0x03005AA4
	ldrh r3, [r3]
	cmp r3, #0
	beq _03000A94
_03000A84:
	mov r6, #0
	ldr r3, _03001260 @ =0x03005A94
	strh r6, [r3]
	b _03000B50
_03000A94:
	ldr r3, _03001264 @ =0x03005A9A
	ldrh r2, [r3]
	tst r2, #0x80
	beq _03000AFC
	ldr r4, _03001268 @ =0x03005AAA
	ldrh r5, [r4]
	subs r5, r5, #1
	strh r5, [r4]
	bpl _03000AFC
	mov r5, #0xe
	and r5, r5, r2, lsr #3
	orr r5, r5, #1
	strh r5, [r4]
	ldr r4, _0300126C @ =0x03005AA0
	ldrh r3, [r4]
	ands r5, r2, #7
	beq _03000AFC
	tst r2, #8
	addeq r3, r3, r3, lsr r5
	subne r3, r3, r3, lsr r5
	subne r3, r3, #1
	cmp r3, #8
	bmi _03000CF8
	cmp r3, #0x800
	bpl _03000CF8
	strh r3, [r4]
_03000AFC:
	ldr r6, _03001270 @ =0x03005A94
	ldr r3, _03001274 @ =0x03005A98
	ldrh r2, [r3]
	and r5, r2, #0xf
	tst r2, #0x10
	bne _03000B4C
	ldrh r5, [r6]
	ldr r4, _03001278 @ =0x03005AA2
	ldrh r7, [r4]
	subs r7, r7, #1
	strh r7, [r4]
	bpl _03000B4C
	cmp r5, #0
	bne _03000B40
	tst r2, #0x20
	beq _03000D08
	mov r5, #0x10
_03000B40:
	sub r5, r5, #1
	and r2, r2, #0xf
	strh r2, [r4]
_03000B4C:
	strh r5, [r6]
_03000B50:
	ldr r6, _0300127C @ =0x03005AA0
	ldrh r6, [r6]
	cmp r6, #8
	ldr r6, _03001280 @ =0x03005A94
	ldrh r6, [r6]
	movmi r6, #0
	ldr r5, _03001284 @ =0x03005A96
	ldrh r5, [r5]
	ldr sl, _03001288 @ =0x030025FC
	ldr r4, _0300128C @ =0x03005A98
	ldrh r4, [r4]
	lsr r4, r4, #6
	ldr r8, _03001290 @ =0x0300263C
	ldrb r8, [r8, r4]
	ldr sb, _03001294 @ =0x03002640
	ldrb sb, [sb, r4]
	ldr r2, _03001298 @ =0x03005A90
	ldr r2, [r2]
	ldr r3, _0300129C @ =0x03005FD0
	ldr r3, [r3]
	ldr r4, _030012A0 @ =0x03005A98
	ldrh r4, [r4]
	lsr r4, r4, #6
	lsls r4, r4, #1
	orreq r4, r4, #1
_03000BB4:
	ldr r4, [sl, r5, lsl #2]
	cmp r6, r5
	addhi r5, r5, #1
	sublt r5, r5, #1
	add r2, r2, r3
	and r7, sb, r2, lsr r8
	ldrb ip, [r4, r7]
	strb ip, [r0], #1
	add r2, r2, r3
	and r7, sb, r2, lsr r8
	ldrb ip, [r4, r7]
	strb ip, [r0], #1
	add r2, r2, r3
	and r7, sb, r2, lsr r8
	ldrb ip, [r4, r7]
	strb ip, [r0], #1
	add r2, r2, r3
	and r7, sb, r2, lsr r8
	ldrb ip, [r4, r7]
	strb ip, [r0], #1
	add r2, r2, r3
	and r7, sb, r2, lsr r8
	ldrb ip, [r4, r7]
	strb ip, [r0], #1
	add r2, r2, r3
	and r7, sb, r2, lsr r8
	ldrb ip, [r4, r7]
	strb ip, [r0], #1
	add r2, r2, r3
	and r7, sb, r2, lsr r8
	ldrb ip, [r4, r7]
	strb ip, [r0], #1
	add r2, r2, r3
	and r7, sb, r2, lsr r8
	ldrb ip, [r4, r7]
	strb ip, [r0], #1
	subs r1, r1, #8
	bhi _03000BB4
	ldr r3, _030012A4 @ =0x03005A96
	strh r5, [r3]
	ldr r3, _030012A8 @ =0x03005A90
	str r2, [r3]
	pop {r4, r5, r6, r7, r8, sb, sl}
	bx lr
_03000C64:
	mov ip, #0
	add r2, r2, r3
	and r7, r5, r2, lsr #16
	cmp r4, r7
	andhi ip, sb, r2, lsr r8
	ldrbhi ip, [r6, ip]
	strb ip, [r0], #1
	subs r1, r1, #1
	bhi _03000C64
	ldr r3, _030012AC @ =0x03005A90
	str r2, [r3]
	pop {r4, r5, r6, r7, r8, sb, sl}
	bx lr
_03000C98:
	mov ip, #0
	add r2, r2, r3
	and r7, r5, r2, lsr #16
	cmp r4, r7
	orrhi ip, ip, r6
	add r2, r2, r3
	and r7, r5, r2, lsr #16
	cmp r4, r7
	orrhi ip, ip, r6, lsl #8
	add r2, r2, r3
	and r7, r5, r2, lsr #16
	cmp r4, r7
	orrhi ip, ip, r6, lsl #16
	add r2, r2, r3
	and r7, r5, r2, lsr #16
	cmp r4, r7
	orrhi ip, ip, r6, lsl #24
	str ip, [r0], #4
	subs r1, r1, #4
	bhi _03000C98
	ldr r3, _030012B0 @ =0x03005A90
	str r2, [r3]
	pop {r4, r5, r6, r7, r8, sb, sl}
	bx lr
_03000CF8:
	ldr r3, _030012B4 @ =0x03005AA4
	mov r2, #2
	strh r2, [r3]
	b _03000A84
_03000D08:
	ldr r3, _030012B8 @ =0x03005AA4
	mov r2, #2
	strh r2, [r3]
	pop {r4, r5, r6, r7, r8, sb, sl}
	bx lr

	thumb_func_start sub_03000D1C
sub_03000D1C: @ 0x03000D1C
	bx lr
	.align 2, 0

	thumb_func_start sub_03000D20
sub_03000D20: @ 0x03000D20
	ldr r1, _03000D28 @ =0x03005AB0
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_03000D28: .4byte 0x03005AB0

	thumb_func_start sub_03000D2C
sub_03000D2C: @ 0x03000D2C
	ldr r1, _03000D34 @ =0x03005AC8
	strh r0, [r1]
	bx lr
	.align 2, 0
_03000D34: .4byte 0x03005AC8

	thumb_func_start sub_03000D38
sub_03000D38: @ 0x03000D38
	push {lr}
	ldr r0, _03000D48 @ =0x03005AC4
	ldrh r1, [r0]
	cmp r1, #0
	beq _03000D50
	ldr r1, _03000D4C @ =0x03005AC6
	movs r0, #1
	b _03000DCE
	.align 2, 0
_03000D48: .4byte 0x03005AC4
_03000D4C: .4byte 0x03005AC6
_03000D50:
	ldr r0, _03000D68 @ =0x03005AC6
	strh r1, [r0]
	ldr r0, _03000D6C @ =0x03005AB8
	ldrh r2, [r0]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _03000D74
	ldr r1, _03000D70 @ =0x03005AB4
	movs r0, #0xf
	ands r0, r2
	b _03000D78
	.align 2, 0
_03000D68: .4byte 0x03005AC6
_03000D6C: .4byte 0x03005AB8
_03000D70: .4byte 0x03005AB4
_03000D74:
	ldr r1, _03000D90 @ =0x03005AB4
	movs r0, #0xf
_03000D78:
	strh r0, [r1]
	ldr r1, _03000D94 @ =0x03005AC2
	movs r0, #0xf
	strh r0, [r1]
	ldr r0, _03000D98 @ =gUnk_03005FD8
	ldrh r0, [r0]
	cmp r0, #0
	beq _03000DA0
	ldr r1, _03000D9C @ =0x03005ACA
	movs r0, #1
	b _03000DA4
	.align 2, 0
_03000D90: .4byte 0x03005AB4
_03000D94: .4byte 0x03005AC2
_03000D98: .4byte gUnk_03005FD8
_03000D9C: .4byte 0x03005ACA
_03000DA0:
	ldr r1, _03000DD4 @ =0x03005ACA
	movs r0, #4
_03000DA4:
	strh r0, [r1]
	ldr r1, _03000DD8 @ =0x030023DC
	ldr r0, _03000DDC @ =0x03005ABE
	ldrh r0, [r0]
	lsrs r0, r0, #3
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #2
	bl sub_03000D2C
	ldr r0, _03000DE0 @ =0x03005A7A
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _03000DD0
	ldr r1, _03000DE4 @ =gUnk_03005FD8
	movs r0, #1
	strh r0, [r1]
	ldr r1, _03000DE8 @ =0x03005AC4
	movs r0, #0
_03000DCE:
	strh r0, [r1]
_03000DD0:
	pop {r0}
	bx r0
	.align 2, 0
_03000DD4: .4byte 0x03005ACA
_03000DD8: .4byte 0x030023DC
_03000DDC: .4byte 0x03005ABE
_03000DE0: .4byte 0x03005A7A
_03000DE4: .4byte gUnk_03005FD8
_03000DE8: .4byte 0x03005AC4

	thumb_func_start sub_03000DEC
sub_03000DEC: @ 0x03000DEC
	push {lr}
	ldr r0, _03000E08 @ =gUnk_03005FD8
	ldrh r0, [r0]
	cmp r0, #0
	beq _03000E02
	ldr r1, _03000E0C @ =0x03005AC4
	ldrh r0, [r1]
	cmp r0, #0
	bne _03000E02
	movs r0, #2
	strh r0, [r1]
_03000E02:
	pop {r0}
	bx r0
	.align 2, 0
_03000E08: .4byte gUnk_03005FD8
_03000E0C: .4byte 0x03005AC4

	thumb_func_start sub_03000E10
sub_03000E10: @ 0x03000E10
	push {lr}
	ldr r0, _03000E34 @ =0x03005ACC
	ldrb r0, [r0]
	cmp r0, #0
	beq _03000E2E
	ldr r0, _03000E38 @ =0x03005AC0
	ldrh r1, [r0]
	movs r0, #0xf0
	lsls r0, r0, #4
	ands r0, r1
	ldr r1, _03000E3C @ =0x03005ABC
	ldrh r1, [r1]
	orrs r0, r1
	bl sub_03000E40
_03000E2E:
	pop {r0}
	bx r0
	.align 2, 0
_03000E34: .4byte 0x03005ACC
_03000E38: .4byte 0x03005AC0
_03000E3C: .4byte 0x03005ABC

	thumb_func_start sub_03000E40
sub_03000E40: @ 0x03000E40
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r1, _03000E5C @ =0x03005ACC
	movs r0, #0
	strb r0, [r1]
	ldr r0, _03000E60 @ =0x03005AC0
	strh r2, [r0]
	cmp r2, #0
	bne _03000E68
	ldr r0, _03000E64 @ =0x03005AB4
	strh r2, [r0]
	b _03000E82
	.align 2, 0
_03000E5C: .4byte 0x03005ACC
_03000E60: .4byte 0x03005AC0
_03000E64: .4byte 0x03005AB4
_03000E68:
	ldr r4, _03000E88 @ =0x03005FC4
	adds r1, r2, #1
	ldr r0, _03000E8C @ =0x001B4F4D
	bl __udivsi3
	adds r1, r0, #0
	str r1, [r4]
	ldr r0, _03000E90 @ =0x03005FD0
	ldr r0, [r0]
	cmp r0, r1
	bne _03000E82
	subs r0, r1, #1
	str r0, [r4]
_03000E82:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_03000E88: .4byte 0x03005FC4
_03000E8C: .4byte 0x001B4F4D
_03000E90: .4byte 0x03005FD0

	thumb_func_start sub_03000E94
sub_03000E94: @ 0x03000E94
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _03000EA4 @ =0x03005AB4
	strh r0, [r1]
	ldr r1, _03000EA8 @ =0x03005AC2
	movs r0, #1
	strh r0, [r1]
	bx lr
	.align 2, 0
_03000EA4: .4byte 0x03005AB4
_03000EA8: .4byte 0x03005AC2

	thumb_func_start sub_03000EAC
sub_03000EAC: @ 0x03000EAC
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r4, _03000F00 @ =0x03005AB8
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
	ldr r2, _03000F04 @ =0x03005ACD
	movs r0, #0
	strb r0, [r2]
	movs r0, #0xc0
	ands r0, r3
	cmp r0, #0xc0
	bne _03000EDE
	movs r0, #0x7f
	ands r0, r3
	strh r0, [r4]
_03000EDE:
	cmp r5, #0
	beq _03000EF8
	cmp r1, #0
	bne _03000EF8
	ldr r0, _03000F08 @ =gUnk_03005FD8
	ldrh r0, [r0]
	cmp r0, #0
	beq _03000EF8
	movs r0, #4
	strb r0, [r2]
	ldr r1, _03000F0C @ =0x03005AC2
	movs r0, #1
	strh r0, [r1]
_03000EF8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_03000F00: .4byte 0x03005AB8
_03000F04: .4byte 0x03005ACD
_03000F08: .4byte gUnk_03005FD8
_03000F0C: .4byte 0x03005AC2

	thumb_func_start sub_03000F10
sub_03000F10: @ 0x03000F10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _03000F20 @ =0x03005ABA
	strh r0, [r1]
	ldr r1, _03000F24 @ =0x03005ACA
	movs r0, #1
	strh r0, [r1]
	bx lr
	.align 2, 0
_03000F20: .4byte 0x03005ABA
_03000F24: .4byte 0x03005ACA

	thumb_func_start sub_03000F28
sub_03000F28: @ 0x03000F28
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _03000F38 @ =0x03005ABC
	strh r0, [r1]
	ldr r1, _03000F3C @ =0x03005ACC
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_03000F38: .4byte 0x03005ABC
_03000F3C: .4byte 0x03005ACC

	thumb_func_start sub_03000F40
sub_03000F40: @ 0x03000F40
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r0, _03000F70 @ =0x03005ABE
	strh r1, [r0]
	movs r0, #7
	ands r0, r1
	lsls r0, r0, #8
	ldr r1, _03000F74 @ =0x03005ABC
	ldrh r1, [r1]
	orrs r0, r1
	bl sub_03000E40
	ldr r0, _03000F78 @ =gUnk_03005FD8
	ldrh r0, [r0]
	cmp r0, #0
	bne _03000F68
	bl sub_03000D20
_03000F68:
	bl sub_03000D38
	pop {r0}
	bx r0
	.align 2, 0
_03000F70: .4byte 0x03005ABE
_03000F74: .4byte 0x03005ABC
_03000F78: .4byte gUnk_03005FD8

	thumb_func_start sub_03000F7C
sub_03000F7C: @ 0x03000F7C
	ldr r1, _03000FC8 @ =0x03005AB0
	movs r0, #0
	str r0, [r1]
	ldr r1, _03000FCC @ =0x03005FC4
	str r0, [r1]
	ldr r1, _03000FD0 @ =0x03005AB4
	movs r2, #0
	strh r0, [r1]
	ldr r1, _03000FD4 @ =0x03005AB6
	strh r0, [r1]
	ldr r1, _03000FD8 @ =0x03005AB8
	strh r0, [r1]
	ldr r1, _03000FDC @ =0x03005ABA
	strh r0, [r1]
	ldr r1, _03000FE0 @ =0x03005ABC
	strh r0, [r1]
	ldr r1, _03000FE4 @ =0x03005ABE
	strh r0, [r1]
	ldr r1, _03000FE8 @ =0x03005AC0
	strh r0, [r1]
	ldr r1, _03000FEC @ =0x03005AC2
	strh r0, [r1]
	ldr r1, _03000FF0 @ =gUnk_03005FD8
	strh r0, [r1]
	ldr r1, _03000FF4 @ =0x03005AC4
	strh r0, [r1]
	ldr r1, _03000FF8 @ =0x03005AC6
	strh r0, [r1]
	ldr r1, _03000FFC @ =0x03005AC8
	strh r0, [r1]
	ldr r1, _03001000 @ =0x03005ACA
	strh r0, [r1]
	ldr r0, _03001004 @ =0x03005ACC
	strb r2, [r0]
	ldr r0, _03001008 @ =0x03005ACD
	strb r2, [r0]
	bx lr
	.align 2, 0
_03000FC8: .4byte 0x03005AB0
_03000FCC: .4byte 0x03005FC4
_03000FD0: .4byte 0x03005AB4
_03000FD4: .4byte 0x03005AB6
_03000FD8: .4byte 0x03005AB8
_03000FDC: .4byte 0x03005ABA
_03000FE0: .4byte 0x03005ABC
_03000FE4: .4byte 0x03005ABE
_03000FE8: .4byte 0x03005AC0
_03000FEC: .4byte 0x03005AC2
_03000FF0: .4byte gUnk_03005FD8
_03000FF4: .4byte 0x03005AC4
_03000FF8: .4byte 0x03005AC6
_03000FFC: .4byte 0x03005AC8
_03001000: .4byte 0x03005ACA
_03001004: .4byte 0x03005ACC
_03001008: .4byte 0x03005ACD

	thumb_func_start sub_0300100C
sub_0300100C: @ 0x0300100C
	bx pc
	nop

	arm_func_start sub_03001010
sub_03001010: @ 0x03001010
	push {r4, r5, r6, r7, r8, sb, sl}
	ldr r3, _030012BC @ =0x03005AC4
	ldrh r3, [r3]
	cmp r3, #0
	beq _03001034
_03001024:
	mov r6, #0
	ldr r3, _030012C0 @ =0x03005AB4
	strh r6, [r3]
	b _030010EC
_03001034:
	ldr r3, _030012C4 @ =0x03005ABA
	ldrh r2, [r3]
	tst r2, #0x80
	beq _03001098
	ldr r4, _030012C8 @ =0x03005ACA
	ldrh r5, [r4]
	subs r5, r5, #1
	strh r5, [r4]
	bpl _03001098
	mov r5, #0xe
	and r5, r5, r2, lsr #3
	orr r5, r5, #1
	strh r5, [r4]
	ldr r4, _030012CC @ =0x03005AC0
	ldrh r3, [r4]
	ands r5, r2, #7
	beq _03001098
	tst r2, #8
	addeq r3, r3, r3, lsr r5
	subne r3, r3, r3, lsr r5
	cmp r3, #8
	bmi _03001234
	cmp r3, #0x800
	bpl _03001234
	strh r3, [r4]
_03001098:
	ldr r6, _030012D0 @ =0x03005AB4
	ldr r3, _030012D4 @ =0x03005AB8
	ldrh r2, [r3]
	and r5, r2, #0xf
	tst r2, #0x10
	bne _030010E8
	ldrh r5, [r6]
	ldr r4, _030012D8 @ =0x03005AC2
	ldrh r7, [r4]
	subs r7, r7, #1
	strh r7, [r4]
	bpl _030010E8
	cmp r5, #0
	bne _030010DC
	tst r2, #0x20
	beq _03001244
	mov r5, #0x10
_030010DC:
	sub r5, r5, #1
	and r2, r2, #0xf
	strh r2, [r4]
_030010E8:
	strh r5, [r6]
_030010EC:
	ldr r6, _030012DC @ =0x03005AC0
	ldrh r6, [r6]
	cmp r6, #8
	ldr r6, _030012E0 @ =0x03005AB4
	ldrh r6, [r6]
	movmi r6, #0
	ldr r5, _030012E4 @ =0x03005AB6
	ldrh r5, [r5]
	ldr sl, _030012E8 @ =0x030025FC
	ldr r4, _030012EC @ =0x03005AB8
	ldrh r4, [r4]
	lsr r4, r4, #6
	ldr r8, _030012F0 @ =0x0300263C
	ldrb r8, [r8, r4]
	ldr sb, _030012F4 @ =0x03002640
	ldrb sb, [sb, r4]
	ldr r2, _030012F8 @ =0x03005AB0
	ldr r2, [r2]
	ldr r3, _030012FC @ =0x03005FC4
	ldr r3, [r3]
	ldr r4, _03001300 @ =0x03005AB8
	ldrh r4, [r4]
	lsr r4, r4, #6
	lsls r4, r4, #1
	orreq r4, r4, #1
_03001150:
	ldr r4, [sl, r5, lsl #2]
	cmp r6, r5
	addhi r5, r5, #1
	sublt r5, r5, #1
	add r2, r2, r3
	and r7, sb, r2, lsr r8
	ldrb ip, [r4, r7]
	strb ip, [r0], #1
	add r2, r2, r3
	and r7, sb, r2, lsr r8
	ldrb ip, [r4, r7]
	strb ip, [r0], #1
	add r2, r2, r3
	and r7, sb, r2, lsr r8
	ldrb ip, [r4, r7]
	strb ip, [r0], #1
	add r2, r2, r3
	and r7, sb, r2, lsr r8
	ldrb ip, [r4, r7]
	strb ip, [r0], #1
	add r2, r2, r3
	and r7, sb, r2, lsr r8
	ldrb ip, [r4, r7]
	strb ip, [r0], #1
	add r2, r2, r3
	and r7, sb, r2, lsr r8
	ldrb ip, [r4, r7]
	strb ip, [r0], #1
	add r2, r2, r3
	and r7, sb, r2, lsr r8
	ldrb ip, [r4, r7]
	strb ip, [r0], #1
	add r2, r2, r3
	and r7, sb, r2, lsr r8
	ldrb ip, [r4, r7]
	strb ip, [r0], #1
	subs r1, r1, #8
	bhi _03001150
	ldr r3, _03001304 @ =0x03005AB6
	strh r5, [r3]
	ldr r3, _03001308 @ =0x03005AB0
	str r2, [r3]
	pop {r4, r5, r6, r7, r8, sb, sl}
	bx lr
_03001200:
	mov ip, #0
	add r2, r2, r3
	and r7, r5, r2, lsr #16
	cmp r4, r7
	andhi ip, sb, r2, lsr r8
	ldrbhi ip, [r6, ip]
	strb ip, [r0], #1
	subs r1, r1, #1
	bhi _03001200
	ldr r3, _0300130C @ =0x03005AB0
	str r2, [r3]
	pop {r4, r5, r6, r7, r8, sb, sl}
	bx lr
_03001234:
	ldr r3, _03001310 @ =0x03005AC4
	mov r2, #2
	strh r2, [r3]
	b _03001024
_03001244:
	ldr r3, _03001314 @ =0x03005AC4
	mov r2, #2
	strh r2, [r3]
	pop {r4, r5, r6, r7, r8, sb, sl}
	bx lr

	thumb_func_start sub_03001258
sub_03001258: @ 0x03001258
	bx lr
	.align 2, 0
_0300125C: .4byte 0x03005AA4
_03001260: .4byte 0x03005A94
_03001264: .4byte 0x03005A9A
_03001268: .4byte 0x03005AAA
_0300126C: .4byte 0x03005AA0
_03001270: .4byte 0x03005A94
_03001274: .4byte 0x03005A98
_03001278: .4byte 0x03005AA2
_0300127C: .4byte 0x03005AA0
_03001280: .4byte 0x03005A94
_03001284: .4byte 0x03005A96
_03001288: .4byte 0x030025FC
_0300128C: .4byte 0x03005A98
_03001290: .4byte 0x0300263C
_03001294: .4byte 0x03002640
_03001298: .4byte 0x03005A90
_0300129C: .4byte 0x03005FD0
_030012A0: .4byte 0x03005A98
_030012A4: .4byte 0x03005A96
_030012A8: .4byte 0x03005A90
_030012AC: .4byte 0x03005A90
_030012B0: .4byte 0x03005A90
_030012B4: .4byte 0x03005AA4
_030012B8: .4byte 0x03005AA4
_030012BC: .4byte 0x03005AC4
_030012C0: .4byte 0x03005AB4
_030012C4: .4byte 0x03005ABA
_030012C8: .4byte 0x03005ACA
_030012CC: .4byte 0x03005AC0
_030012D0: .4byte 0x03005AB4
_030012D4: .4byte 0x03005AB8
_030012D8: .4byte 0x03005AC2
_030012DC: .4byte 0x03005AC0
_030012E0: .4byte 0x03005AB4
_030012E4: .4byte 0x03005AB6
_030012E8: .4byte 0x030025FC
_030012EC: .4byte 0x03005AB8
_030012F0: .4byte 0x0300263C
_030012F4: .4byte 0x03002640
_030012F8: .4byte 0x03005AB0
_030012FC: .4byte 0x03005FC4
_03001300: .4byte 0x03005AB8
_03001304: .4byte 0x03005AB6
_03001308: .4byte 0x03005AB0
_0300130C: .4byte 0x03005AB0
_03001310: .4byte 0x03005AC4
_03001314: .4byte 0x03005AC4

@ file split

	thumb_func_start sub_03001318
sub_03001318: @ 0x03001318
	push {lr}
	ldr r0, _0300132C @ =gUnk_03005FB0
	ldrh r1, [r0]
	cmp r1, #0
	bne _03001326
	ldr r0, _03001330 @ =0x03005AD0
	str r1, [r0]
_03001326:
	pop {r0}
	bx r0
	.align 2, 0
_0300132C: .4byte gUnk_03005FB0
_03001330: .4byte 0x03005AD0

	thumb_func_start sub_03001334
sub_03001334: @ 0x03001334
	ldr r1, _0300133C @ =0x03005AD4
	strh r0, [r1]
	bx lr
	.align 2, 0
_0300133C: .4byte 0x03005AD4

	thumb_func_start sub_03001340
sub_03001340: @ 0x03001340
	push {r4, lr}
	ldr r1, _030013A4 @ =0x030023DC
	ldr r0, _030013A8 @ =0x03005AE2
	ldrh r0, [r0]
	lsrs r0, r0, #3
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #2
	bl sub_03001334
	ldr r0, _030013AC @ =0x03005ADE
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0
	beq _03001382
	ldr r0, _030013B0 @ =0x03005A7A
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _03001382
	ldr r4, _030013B4 @ =gUnk_03005FB0
	ldrh r0, [r4]
	cmp r0, #0
	bne _03001378
	bl sub_03001318
_03001378:
	movs r0, #1
	strh r0, [r4]
	ldr r1, _030013B8 @ =0x03005AD8
	movs r0, #0
	strh r0, [r1]
_03001382:
	ldr r2, _030013BC @ =0x03005AD6
	ldr r0, _030013AC @ =0x03005ADE
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	adds r0, #1
	strh r0, [r2]
	ldr r2, _030013C0 @ =0x03005ADA
	ldr r0, _030013C4 @ =0x03005ADC
	ldrh r0, [r0]
	ldrh r1, [r2]
	adds r0, r0, r1
	asrs r0, r0, #1
	strh r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_030013A4: .4byte 0x030023DC
_030013A8: .4byte 0x03005AE2
_030013AC: .4byte 0x03005ADE
_030013B0: .4byte 0x03005A7A
_030013B4: .4byte gUnk_03005FB0
_030013B8: .4byte 0x03005AD8
_030013BC: .4byte 0x03005AD6
_030013C0: .4byte 0x03005ADA
_030013C4: .4byte 0x03005ADC

	thumb_func_start sub_030013C8
sub_030013C8: @ 0x030013C8
	push {lr}
	ldr r0, _030013E4 @ =gUnk_03005FB0
	ldrh r0, [r0]
	cmp r0, #0
	beq _030013E0
	ldr r1, _030013E8 @ =0x03005AD8
	ldrh r0, [r1]
	cmp r0, #0
	bne _030013E0
	ldr r0, _030013EC @ =0x03005ADA
	ldrh r0, [r0]
	strh r0, [r1]
_030013E0:
	pop {r0}
	bx r0
	.align 2, 0
_030013E4: .4byte gUnk_03005FB0
_030013E8: .4byte 0x03005AD8
_030013EC: .4byte 0x03005ADA

	thumb_func_start sub_030013F0
sub_030013F0: @ 0x030013F0
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r6, r5, #0
	ldr r2, _0300140C @ =0x03005FD4
	ldr r1, _03001410 @ =0x03002845
	movs r0, #0
	strb r0, [r1]
	strh r5, [r2]
	cmp r5, #0
	bne _03001418
	ldr r0, _03001414 @ =0x03005ADC
	strh r5, [r0]
	b _03001446
	.align 2, 0
_0300140C: .4byte 0x03005FD4
_03001410: .4byte 0x03002845
_03001414: .4byte 0x03005ADC
_03001418:
	ldr r4, _0300144C @ =0x03005FDC
	adds r1, r5, #1
	ldr r0, _03001450 @ =0x006D3D34
	bl __udivsi3
	str r0, [r4]
	ldr r1, _03001454 @ =0x03005ADC
	movs r0, #7
	strh r0, [r1]
	cmp r5, #0x3f
	bhi _03001432
	movs r0, #6
	strh r0, [r1]
_03001432:
	cmp r5, #0x1f
	bhi _0300143C
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
_0300143C:
	cmp r6, #0xf
	bhi _03001446
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
_03001446:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0300144C: .4byte 0x03005FDC
_03001450: .4byte 0x006D3D34
_03001454: .4byte 0x03005ADC

	thumb_func_start sub_03001458
sub_03001458: @ 0x03001458
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, _03001488 @ =0x03005AD6
	ldrh r2, [r3]
	ldr r1, _0300148C @ =0x03005ADE
	strh r0, [r1]
	movs r1, #0x7f
	ands r1, r0
	cmp r1, #0
	bne _030014A4
	movs r1, #0x80
	ands r1, r2
	cmp r1, #0
	bne _03001494
	ldr r2, _03001490 @ =0x03005AE4
	ldrh r0, [r2]
	cmp r0, #0
	beq _03001494
	movs r0, #1
	strh r0, [r3]
	strh r1, [r2]
	b _030014BC
	.align 2, 0
_03001488: .4byte 0x03005AD6
_0300148C: .4byte 0x03005ADE
_03001490: .4byte 0x03005AE4
_03001494:
	bl sub_030013C8
	ldr r1, _030014A0 @ =0x03005AE4
	movs r0, #0
	strh r0, [r1]
	b _030014BC
	.align 2, 0
_030014A0: .4byte 0x03005AE4
_030014A4:
	ldr r0, _030014C0 @ =gUnk_03005FB0
	ldrh r0, [r0]
	ldr r2, _030014C4 @ =0x03005AE4
	cmp r0, #0
	beq _030014B4
	ldrh r0, [r2]
	cmp r0, #0
	beq _030014BC
_030014B4:
	adds r0, r1, #1
	strh r0, [r3]
	movs r0, #0
	strh r0, [r2]
_030014BC:
	pop {r0}
	bx r0
	.align 2, 0
_030014C0: .4byte gUnk_03005FB0
_030014C4: .4byte 0x03005AE4

	thumb_func_start sub_030014C8
sub_030014C8: @ 0x030014C8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _030014D8 @ =0x03005AE0
	strh r0, [r1]
	ldr r1, _030014DC @ =0x03002845
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_030014D8: .4byte 0x03005AE0
_030014DC: .4byte 0x03002845

	thumb_func_start sub_030014E0
sub_030014E0: @ 0x030014E0
	push {lr}
	ldr r1, _0300150C @ =0x03002845
	ldrb r0, [r1]
	cmp r0, #0
	beq _03001508
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _03001508
	ldr r0, _03001510 @ =0x03005AE2
	ldrh r1, [r0]
	movs r0, #7
	ands r0, r1
	lsls r0, r0, #8
	ldr r1, _03001514 @ =0x03005AE0
	ldrh r1, [r1]
	orrs r0, r1
	bl sub_030013F0
_03001508:
	pop {r0}
	bx r0
	.align 2, 0
_0300150C: .4byte 0x03002845
_03001510: .4byte 0x03005AE2
_03001514: .4byte 0x03005AE0

	thumb_func_start sub_03001518
sub_03001518: @ 0x03001518
	push {r4, lr}
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r4, _03001548 @ =0x03005AE2
	strh r1, [r4]
	ldr r2, _0300154C @ =0x03005AE4
	movs r0, #1
	strh r0, [r2]
	movs r0, #7
	ands r0, r1
	lsls r0, r0, #8
	ldr r1, _03001550 @ =0x03005AE0
	ldrh r1, [r1]
	orrs r0, r1
	bl sub_030013F0
	ldr r0, _03001554 @ =gUnk_03005FB0
	ldrh r0, [r0]
	cmp r0, #0
	bne _03001558
	bl sub_03001340
	b _0300157C
	.align 2, 0
_03001548: .4byte 0x03005AE2
_0300154C: .4byte 0x03005AE4
_03001550: .4byte 0x03005AE0
_03001554: .4byte gUnk_03005FB0
_03001558:
	ldr r1, _03001584 @ =0x030023DC
	ldrh r0, [r4]
	lsrs r0, r0, #3
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #2
	bl sub_03001334
	ldr r2, _03001588 @ =0x03005AD6
	ldr r0, _0300158C @ =0x03005ADE
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	adds r0, #1
	strh r0, [r2]
	ldr r1, _03001590 @ =0x03005AD8
	movs r0, #0
	strh r0, [r1]
_0300157C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_03001584: .4byte 0x030023DC
_03001588: .4byte 0x03005AD6
_0300158C: .4byte 0x03005ADE
_03001590: .4byte 0x03005AD8

	thumb_func_start sub_03001594
sub_03001594: @ 0x03001594
	ldr r0, _030015D4 @ =0x03005AD0
	movs r1, #0
	str r1, [r0]
	ldr r0, _030015D8 @ =0x03005FDC
	str r1, [r0]
	ldr r0, _030015DC @ =0x03005AD4
	movs r2, #0
	strh r1, [r0]
	ldr r0, _030015E0 @ =0x03005AD6
	strh r1, [r0]
	ldr r0, _030015E4 @ =gUnk_03005FB0
	strh r1, [r0]
	ldr r0, _030015E8 @ =0x03005AD8
	strh r1, [r0]
	ldr r0, _030015EC @ =0x03005ADA
	strh r1, [r0]
	ldr r0, _030015F0 @ =0x03005ADC
	strh r1, [r0]
	ldr r0, _030015F4 @ =0x03005ADE
	strh r1, [r0]
	ldr r0, _030015F8 @ =0x03005AE0
	strh r1, [r0]
	ldr r0, _030015FC @ =0x03005AE2
	strh r1, [r0]
	ldr r0, _03001600 @ =0x03005AE4
	strh r1, [r0]
	ldr r0, _03001604 @ =0x03005FD4
	strh r1, [r0]
	ldr r0, _03001608 @ =0x03002845
	strb r2, [r0]
	bx lr
	.align 2, 0
_030015D4: .4byte 0x03005AD0
_030015D8: .4byte 0x03005FDC
_030015DC: .4byte 0x03005AD4
_030015E0: .4byte 0x03005AD6
_030015E4: .4byte gUnk_03005FB0
_030015E8: .4byte 0x03005AD8
_030015EC: .4byte 0x03005ADA
_030015F0: .4byte 0x03005ADC
_030015F4: .4byte 0x03005ADE
_030015F8: .4byte 0x03005AE0
_030015FC: .4byte 0x03005AE2
_03001600: .4byte 0x03005AE4
_03001604: .4byte 0x03005FD4
_03001608: .4byte 0x03002845

	thumb_func_start sub_0300160C
sub_0300160C: @ 0x0300160C
	bx pc
	nop

	arm_func_start sub_03001610
sub_03001610: @ 0x03001610
	push {r4, r5, r6, r7}
	ldr r2, _03001700 @ =0x03005AD8
	ldrh r2, [r2]
	cmp r2, #0
	beq _03001634
_03001624:
	ldr r4, _03001704 @ =0x03002645
	sub r2, r2, #1
	add r4, r4, r2, lsl #6
	b _03001674
_03001634:
	ldr r2, _03001708 @ =0x03005AD6
	ldrh r3, [r2]
	subs r3, r3, #1
	strbpl r3, [r2]
	bpl _03001664
	ldr r2, _0300170C @ =0x03005AE4
	mov r3, #0
	strh r3, [r2]
	ldr r2, _03001710 @ =0x03005ADE
	ldrh r2, [r2]
	tst r2, #0x80
	beq _030016E8
_03001664:
	ldr r4, _03001714 @ =0x03002645
	ldr r2, _03001718 @ =0x03005ADA
	ldrh r2, [r2]
	add r4, r4, r2, lsl #6
_03001674:
	ldr r2, _0300171C @ =0x03005AD0
	ldr r2, [r2]
	ldr r3, _03001720 @ =0x03005FDC
	ldr r3, [r3]
	mov r5, #0x3f
_03001688:
	mov ip, #0
	add r2, r2, r3
	and r6, r5, r2, lsr #16
	ldrb r7, [r4, r6]
	orr ip, ip, r7
	add r2, r2, r3
	and r6, r5, r2, lsr #16
	ldrb r7, [r4, r6]
	orr ip, ip, r7, lsl #8
	add r2, r2, r3
	and r6, r5, r2, lsr #16
	ldrb r7, [r4, r6]
	orr ip, ip, r7, lsl #16
	add r2, r2, r3
	and r6, r5, r2, lsr #16
	ldrb r7, [r4, r6]
	orr ip, ip, r7, lsl #24
	str ip, [r0], #4
	subs r1, r1, #4
	bhi _03001688
	ldr r3, _03001724 @ =0x03005AD0
	str r2, [r3]
	pop {r4, r5, r6, r7}
	bx lr
_030016E8:
	ldr r3, _03001728 @ =0x03005AD8
	ldr r4, _0300172C @ =0x03005ADA
	ldrh r2, [r4]
	strh r2, [r3]
	b _03001624

	thumb_func_start sub_030016FC
sub_030016FC: @ 0x030016FC
	bx lr
	.align 2, 0
_03001700: .4byte 0x03005AD8
_03001704: .4byte 0x03002645
_03001708: .4byte 0x03005AD6
_0300170C: .4byte 0x03005AE4
_03001710: .4byte 0x03005ADE
_03001714: .4byte 0x03002645
_03001718: .4byte 0x03005ADA
_0300171C: .4byte 0x03005AD0
_03001720: .4byte 0x03005FDC
_03001724: .4byte 0x03005AD0
_03001728: .4byte 0x03005AD8
_0300172C: .4byte 0x03005ADA

@ file split

	thumb_func_start sub_03001730
sub_03001730: @ 0x03001730
	ldr r1, _03001738 @ =0x03005AEC
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_03001738: .4byte 0x03005AEC

	thumb_func_start sub_0300173C
sub_0300173C: @ 0x0300173C
	push {r4, r5, lr}
	movs r3, #0
	movs r0, #0x80
	lsls r0, r0, #9
	ldr r1, _0300177C @ =0x03005B10
_03001746:
	stm r1!, {r0}
	adds r3, #1
	cmp r3, #2
	bls _03001746
	movs r3, #3
	ldr r0, _0300177C @ =0x03005B10
	ldr r1, _03001780 @ =0x0600E008
	ldr r5, _03001784 @ =0x0000FFFF
	movs r4, #0x80
	lsls r4, r4, #9
	adds r2, r0, #0
	adds r2, #0xc
	adds r1, #0xc
_03001760:
	ldr r0, [r1]
	str r0, [r2]
	cmp r0, r5
	bls _0300176A
	str r4, [r2]
_0300176A:
	adds r2, #4
	adds r1, #4
	adds r3, #1
	cmp r3, #0xf
	bls _03001760
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0300177C: .4byte 0x03005B10
_03001780: .4byte 0x0600E008
_03001784: .4byte 0x0000FFFF

	thumb_func_start sub_03001788
sub_03001788: @ 0x03001788
	ldr r1, _03001790 @ =0x03005AFA
	strh r0, [r1]
	bx lr
	.align 2, 0
_03001790: .4byte 0x03005AFA

	thumb_func_start sub_03001794
sub_03001794: @ 0x03001794
	push {r4, r5, lr}
	ldr r0, _030017C0 @ =0x03005A7A
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _030017A8
	ldr r1, _030017C4 @ =gUnk_03005FC0
	movs r0, #1
	strh r0, [r1]
_030017A8:
	ldr r1, _030017C8 @ =0x03005B00
	ldrh r2, [r1]
	movs r0, #0x10
	ands r0, r2
	adds r3, r1, #0
	cmp r0, #0
	beq _030017D0
	ldr r1, _030017CC @ =0x03005AF4
	movs r0, #0xf
	ands r0, r2
	b _030017D4
	.align 2, 0
_030017C0: .4byte 0x03005A7A
_030017C4: .4byte gUnk_03005FC0
_030017C8: .4byte 0x03005B00
_030017CC: .4byte 0x03005AF4
_030017D0:
	ldr r1, _03001828 @ =0x03005AF4
	movs r0, #0xf
_030017D4:
	strh r0, [r1]
	ldr r2, _0300182C @ =0x03005AF8
	ldrh r1, [r3]
	movs r0, #0xf
	ands r0, r1
	strh r0, [r2]
	ldr r1, _03001830 @ =0x030023DC
	ldr r2, _03001834 @ =0x03005B06
	ldrh r0, [r2]
	lsrs r0, r0, #3
	adds r0, r0, r1
	ldrb r4, [r0]
	ldr r0, _03001838 @ =0x03002988
	ldr r0, [r0]
	cmp r0, #0x7f
	bne _030017FA
	cmp r4, #1
	bne _030017FA
	movs r4, #2
_030017FA:
	ldr r0, _0300183C @ =0x03005AF6
	ldrh r0, [r0]
	movs r5, #0
	cmp r0, #0xb
	bls _03001806
	movs r5, #2
_03001806:
	ldrh r0, [r2]
	lsrs r0, r0, #3
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r5
	bl sub_03001788
	ldr r0, _03001838 @ =0x03002988
	str r4, [r0]
	lsls r0, r4, #2
	adds r0, r0, r5
	bl sub_03001788
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_03001828: .4byte 0x03005AF4
_0300182C: .4byte 0x03005AF8
_03001830: .4byte 0x030023DC
_03001834: .4byte 0x03005B06
_03001838: .4byte 0x03002988
_0300183C: .4byte 0x03005AF6

	thumb_func_start sub_03001840
sub_03001840: @ 0x03001840
	push {lr}
	ldr r0, _0300185C @ =gUnk_03005FC0
	ldrh r0, [r0]
	cmp r0, #0
	beq _03001856
	ldr r1, _03001860 @ =0x03005AFE
	ldrh r0, [r1]
	cmp r0, #0
	bne _03001856
	movs r0, #2
	strh r0, [r1]
_03001856:
	pop {r0}
	bx r0
	.align 2, 0
_0300185C: .4byte gUnk_03005FC0
_03001860: .4byte 0x03005AFE

	thumb_func_start sub_03001864
sub_03001864: @ 0x03001864
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _03001874 @ =0x03005AF4
	strh r0, [r1]
	ldr r1, _03001878 @ =0x03005AF8
	movs r0, #1
	strh r0, [r1]
	bx lr
	.align 2, 0
_03001874: .4byte 0x03005AF4
_03001878: .4byte 0x03005AF8

	thumb_func_start sub_0300187C
sub_0300187C: @ 0x0300187C
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r5, r4, #0
	ldr r3, _030018AC @ =0x03005B00
	ldrb r1, [r3]
	movs r2, #0x10
	adds r0, r2, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	adds r1, r4, #0
	ands r1, r2
	strh r4, [r3]
	ldr r2, _030018B0 @ =0x03005B08
	movs r0, #0
	strb r0, [r2]
	cmp r1, #1
	bne _030018B8
	ldr r1, _030018B4 @ =0x03005AF4
	movs r0, #0xf
	ands r0, r4
	strh r0, [r1]
	b _030018D0
	.align 2, 0
_030018AC: .4byte 0x03005B00
_030018B0: .4byte 0x03005B08
_030018B4: .4byte 0x03005AF4
_030018B8:
	cmp r6, #0
	beq _030018D0
	ldr r0, _030018D8 @ =gUnk_03005FC0
	ldrh r0, [r0]
	cmp r0, #0
	beq _030018D0
	movs r0, #4
	strb r0, [r2]
	ldr r1, _030018DC @ =0x03005AF8
	movs r0, #0xf
	ands r5, r0
	strh r5, [r1]
_030018D0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_030018D8: .4byte gUnk_03005FC0
_030018DC: .4byte 0x03005AF8

	thumb_func_start sub_030018E0
sub_030018E0: @ 0x030018E0
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _03001918 @ =0x03005B04
	strh r0, [r1]
	ldr r3, _0300191C @ =0x03005AF6
	movs r1, #0xf
	ands r1, r0
	strh r1, [r3]
	ldr r4, _03001920 @ =0x03005AF0
	ldr r2, _03001924 @ =0x03005B10
	ldrh r1, [r3]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	str r1, [r4]
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq _03001930
	ldr r1, _03001928 @ =0x03002846
	movs r0, #0x40
	strh r0, [r1]
	ldr r1, _0300192C @ =0x03005AE8
	movs r0, #1
	str r0, [r1]
	b _0300193A
	.align 2, 0
_03001918: .4byte 0x03005B04
_0300191C: .4byte 0x03005AF6
_03001920: .4byte 0x03005AF0
_03001924: .4byte 0x03005B10
_03001928: .4byte 0x03002846
_0300192C: .4byte 0x03005AE8
_03001930:
	ldr r1, _03001940 @ =0x03002846
	movs r2, #0x80
	lsls r2, r2, #7
	adds r0, r2, #0
	strh r0, [r1]
_0300193A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_03001940: .4byte 0x03002846

	thumb_func_start sub_03001944
sub_03001944: @ 0x03001944
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r0, _03001964 @ =0x03005B04
	ldrh r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _03001970
	ldr r1, _03001968 @ =0x03002846
	movs r0, #0x40
	strh r0, [r1]
	ldr r1, _0300196C @ =0x03005AE8
	movs r0, #1
	str r0, [r1]
	b _0300197A
	.align 2, 0
_03001964: .4byte 0x03005B04
_03001968: .4byte 0x03002846
_0300196C: .4byte 0x03005AE8
_03001970:
	ldr r1, _03001988 @ =0x03002846
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	strh r0, [r1]
_0300197A:
	ldr r0, _0300198C @ =0x03005B06
	strh r2, [r0]
	bl sub_03001794
	pop {r0}
	bx r0
	.align 2, 0
_03001988: .4byte 0x03002846
_0300198C: .4byte 0x03005B06

	thumb_func_start sub_03001990
sub_03001990: @ 0x03001990
	push {r4, lr}
	ldr r1, _030019E4 @ =0x03005AE8
	movs r0, #1
	str r0, [r1]
	ldr r0, _030019E8 @ =0x03005AEC
	movs r1, #0
	str r1, [r0]
	ldr r0, _030019EC @ =0x03005AF0
	str r1, [r0]
	ldr r0, _030019F0 @ =0x03005AF4
	movs r3, #0
	strh r1, [r0]
	ldr r0, _030019F4 @ =0x03005AF6
	strh r1, [r0]
	ldr r0, _030019F8 @ =0x03005AF8
	strh r1, [r0]
	ldr r0, _030019FC @ =0x03005AFA
	strh r1, [r0]
	ldr r0, _03001A00 @ =0x03005AFC
	strh r1, [r0]
	ldr r2, _03001A04 @ =0x03002846
	movs r4, #0x80
	lsls r4, r4, #8
	adds r0, r4, #0
	strh r0, [r2]
	ldr r0, _03001A08 @ =gUnk_03005FC0
	strh r1, [r0]
	ldr r0, _03001A0C @ =0x03005AFE
	strh r1, [r0]
	ldr r0, _03001A10 @ =0x03005B00
	strh r1, [r0]
	ldr r0, _03001A14 @ =0x03005B02
	strh r1, [r0]
	ldr r0, _03001A18 @ =0x03005B04
	strh r1, [r0]
	ldr r0, _03001A1C @ =0x03005B06
	strh r1, [r0]
	ldr r0, _03001A20 @ =0x03005B08
	strb r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_030019E4: .4byte 0x03005AE8
_030019E8: .4byte 0x03005AEC
_030019EC: .4byte 0x03005AF0
_030019F0: .4byte 0x03005AF4
_030019F4: .4byte 0x03005AF6
_030019F8: .4byte 0x03005AF8
_030019FC: .4byte 0x03005AFA
_03001A00: .4byte 0x03005AFC
_03001A04: .4byte 0x03002846
_03001A08: .4byte gUnk_03005FC0
_03001A0C: .4byte 0x03005AFE
_03001A10: .4byte 0x03005B00
_03001A14: .4byte 0x03005B02
_03001A18: .4byte 0x03005B04
_03001A1C: .4byte 0x03005B06
_03001A20: .4byte 0x03005B08

	thumb_func_start sub_03001A24
sub_03001A24: @ 0x03001A24
	bx pc
	nop

	arm_func_start sub_03001A28
sub_03001A28: @ 0x03001A28
	push {r4, r5, r6, r7, r8, sb, sl, fp}
	ldr r6, _030021AC @ =0x03005AF4
	ldr r3, _030021B0 @ =0x03005B00
	ldrh r2, [r3]
	and r5, r2, #0xf
	tst r2, #0x10
	bne _03001A7C
	ldrh r5, [r6]
	ldr r4, _030021B4 @ =0x03005AF8
	ldrh r7, [r4]
	subs r7, r7, #1
	strh r7, [r4]
	bpl _03001A7C
	cmp r5, #0
	bne _03001A70
	tst r2, #0x20
	beq _03001BF8
	mov r5, #0x10
_03001A70:
	sub r5, r5, #1
	and r2, r2, #0xf
	strh r2, [r4]
_03001A7C:
	strh r5, [r6]
	ldr r2, _030021B8 @ =0x03005AEC
	ldr r2, [r2]
	ldr r3, _030021BC @ =0x03005AF0
	ldr r3, [r3]
	ldr r6, _030021C0 @ =0x03005AF4
	ldrh r6, [r6]
	ldr r4, _030021C4 @ =0x03005AF6
	ldrh r5, [r4]
	lsl r5, r5, #2
	ldr r4, _030021C8 @ =0x03002948
	ldr sl, [r4, r5]
	ldrb sl, [sl, r6]
	mov r5, #0x10000
	sub r4, r5, #1
	ldr r8, _030021CC @ =0x03005AE8
	ldr r8, [r8]
	ldr fp, _030021D0 @ =0x03002846
	ldrh fp, [fp]
_03001AC8:
	ldr r6, _030021D4 @ =0x03005AF4
	ldrh r6, [r6]
	mov ip, #0
	add r2, r2, r3
	ands r7, r5, r2
	beq _03001B08
	and r2, r2, r4
	mov sb, #0
	and r7, r8, #3
	eor r7, r7, r7, lsr #1
	ands r7, r7, #1
	orrne r8, r8, #0x8000
	biceq r8, r8, #0x8000
	orrne r8, r8, fp
	biceq r8, r8, fp
	lsr r8, r8, #1
_03001B08:
	tst r8, #1
	orrne ip, ip, r6
	orreq ip, ip, sl
	add r2, r2, r3
	ands r7, r5, r2
	beq _03001B48
	and r2, r2, r4
	mov sb, #0
	and r7, r8, #3
	eor r7, r7, r7, lsr #1
	ands r7, r7, #1
	orrne r8, r8, #0x8000
	biceq r8, r8, #0x8000
	orrne r8, r8, fp
	biceq r8, r8, fp
	lsr r8, r8, #1
_03001B48:
	tst r8, #1
	orrne ip, ip, r6, lsl #8
	orreq ip, ip, sl, lsl #8
	add r2, r2, r3
	ands r7, r5, r2
	beq _03001B88
	and r2, r2, r4
	mov sb, #0
	and r7, r8, #3
	eor r7, r7, r7, lsr #1
	ands r7, r7, #1
	orrne r8, r8, #0x8000
	biceq r8, r8, #0x8000
	orrne r8, r8, fp
	biceq r8, r8, fp
	lsr r8, r8, #1
_03001B88:
	tst r8, #1
	orrne ip, ip, r6, lsl #16
	orreq ip, ip, sl, lsl #16
	add r2, r2, r3
	ands r7, r5, r2
	beq _03001BC8
	and r2, r2, r4
	mov sb, #0
	and r7, r8, #3
	eor r7, r7, r7, lsr #1
	ands r7, r7, #1
	orrne r8, r8, #0x8000
	biceq r8, r8, #0x8000
	orrne r8, r8, fp
	biceq r8, r8, fp
	lsr r8, r8, #1
_03001BC8:
	tst r8, #1
	orrne ip, ip, r6, lsl #24
	orreq ip, ip, sl, lsl #24
	str ip, [r0], #4
	subs r1, r1, #4
	bhi _03001AC8
	ldr r3, _030021D8 @ =0x03005AE8
	str r8, [r3]
	ldr r3, _030021DC @ =0x03005AEC
	str r2, [r3]
	pop {r4, r5, r6, r7, r8, sb, sl, fp}
	bx lr
_03001BF8:
	ldr r3, _030021E0 @ =0x03005AFE
	mov r2, #2
	strh r2, [r3]
	pop {r4, r5, r6, r7, r8, sb, sl, fp}
	bx lr

	thumb_func_start sub_03001C0C
sub_03001C0C: @ 0x03001C0C
	bx lr
	.align 2, 0

	thumb_func_start sub_03001C10
sub_03001C10: @ 0x03001C10
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r5, r4, #0
	ldr r0, _03001C54 @ =0x03005A7A
	strh r4, [r0]
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	bne _03001C28
	bl sub_03000824
_03001C28:
	movs r0, #2
	ands r0, r4
	cmp r0, #0
	bne _03001C34
	bl sub_03000DEC
_03001C34:
	movs r0, #4
	ands r0, r4
	cmp r0, #0
	bne _03001C40
	bl sub_030013C8
_03001C40:
	movs r0, #8
	ands r5, r0
	cmp r5, #0
	bne _03001C4C
	bl sub_03001840
_03001C4C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_03001C54: .4byte 0x03005A7A

	thumb_func_start sub_03001C58
sub_03001C58: @ 0x03001C58
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _03001C74 @ =0x03005A7C
	strh r0, [r1]
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq _03001C78
	movs r0, #0xa0
	bl sub_03000000
	b _03001C7E
	.align 2, 0
_03001C74: .4byte 0x03005A7C
_03001C78:
	movs r0, #0x80
	bl sub_03000000
_03001C7E:
	ldr r1, _03001CFC @ =0x03005AA2
	ldrh r0, [r1]
	cmp r0, #1
	bls _03001C8A
	subs r0, #1
	strh r0, [r1]
_03001C8A:
	ldr r1, _03001D00 @ =0x03005AC2
	ldrh r0, [r1]
	cmp r0, #1
	bls _03001C96
	subs r0, #1
	strh r0, [r1]
_03001C96:
	ldr r1, _03001D04 @ =0x03005AF8
	ldrh r0, [r1]
	cmp r0, #1
	bls _03001CA2
	subs r0, #1
	strh r0, [r1]
_03001CA2:
	ldr r1, _03001D08 @ =0x03005AD6
	ldrh r0, [r1]
	cmp r0, #1
	bls _03001CAE
	subs r0, #1
	strh r0, [r1]
_03001CAE:
	ldr r1, _03001D0C @ =0x03005AAA
	ldrh r0, [r1]
	cmp r0, #1
	bls _03001CBA
	subs r0, #1
	strh r0, [r1]
_03001CBA:
	ldr r1, _03001D10 @ =0x03005ACA
	ldrh r0, [r1]
	cmp r0, #1
	bls _03001CC6
	subs r0, #1
	strh r0, [r1]
_03001CC6:
	ldr r1, _03001D14 @ =0x03005AA8
	ldrh r0, [r1]
	cmp r0, #0
	beq _03001CD2
	subs r0, #1
	strh r0, [r1]
_03001CD2:
	ldr r1, _03001D18 @ =0x03005AC8
	ldrh r0, [r1]
	cmp r0, #0
	beq _03001CDE
	subs r0, #1
	strh r0, [r1]
_03001CDE:
	ldr r1, _03001D1C @ =0x03005AD4
	ldrh r0, [r1]
	cmp r0, #0
	beq _03001CEA
	subs r0, #1
	strh r0, [r1]
_03001CEA:
	ldr r1, _03001D20 @ =0x03005AFA
	ldrh r0, [r1]
	cmp r0, #0
	beq _03001CF6
	subs r0, #1
	strh r0, [r1]
_03001CF6:
	pop {r0}
	bx r0
	.align 2, 0
_03001CFC: .4byte 0x03005AA2
_03001D00: .4byte 0x03005AC2
_03001D04: .4byte 0x03005AF8
_03001D08: .4byte 0x03005AD6
_03001D0C: .4byte 0x03005AAA
_03001D10: .4byte 0x03005ACA
_03001D14: .4byte 0x03005AA8
_03001D18: .4byte 0x03005AC8
_03001D1C: .4byte 0x03005AD4
_03001D20: .4byte 0x03005AFA

	thumb_func_start sub_03001D24
sub_03001D24: @ 0x03001D24
	ldr r1, _03001D2C @ =0x03005FB8
	strb r0, [r1]
	bx lr
	.align 2, 0
_03001D2C: .4byte 0x03005FB8

	thumb_func_start sub_03001D30
sub_03001D30: @ 0x03001D30
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	adds r4, r1, #0
	ldr r6, _03001D68 @ =0x03005B50
	ldr r0, _03001D6C @ =0x03005BF0
	mov r8, r0
	ldr r0, _03001D70 @ =0x03005C90
	mov sb, r0
	ldr r0, _03001D74 @ =0x03005D30
	mov sl, r0
	movs r5, #0
	ldr r0, _03001D78 @ =0x03005FB8
	ldrb r0, [r0]
	cmp r0, #0
	beq _03001D7C
	movs r0, #0xf0
	lsls r0, r0, #0x18
	bl sub_03000634
	adds r0, r7, #0
	adds r1, r4, #0
	bl sub_03000704
	b _0300202E
	.align 2, 0
_03001D68: .4byte 0x03005B50
_03001D6C: .4byte 0x03005BF0
_03001D70: .4byte 0x03005C90
_03001D74: .4byte 0x03005D30
_03001D78: .4byte 0x03005FB8
_03001D7C:
	ldr r0, _03001EAC @ =gUnk_03005FCC
	ldrh r0, [r0]
	cmp r0, #0
	beq _03001DD6
	bl sub_03000948
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_03000A6C
	ldr r2, _03001EB0 @ =0x03005AAD
	ldrb r0, [r2]
	cmp r0, #0
	beq _03001DA0
	ldr r1, _03001EB4 @ =0x03005A94
	movs r0, #0xf
	strh r0, [r1]
	strb r5, [r2]
_03001DA0:
	ldr r0, _03001EB8 @ =0x03005A9A
	ldrh r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _03001DB4
	ldr r0, _03001EBC @ =0x03005AA0
	ldrh r0, [r0]
	bl sub_03000848
_03001DB4:
	ldr r2, _03001EC0 @ =0x03005AA8
	ldrh r0, [r2]
	cmp r0, #0
	beq _03001DC0
	subs r0, #1
	strh r0, [r2]
_03001DC0:
	ldr r0, _03001EC4 @ =0x03005A98
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne _03001DD6
	ldrh r0, [r2]
	cmp r0, #0
	bne _03001DD6
	bl sub_03000824
_03001DD6:
	ldr r1, _03001EC8 @ =0x03005AA4
	ldrh r0, [r1]
	cmp r0, #0
	beq _03001E00
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _03001E00
	movs r0, #0x80
	lsls r0, r0, #0x18
	orrs r5, r0
	ldr r0, _03001EAC @ =gUnk_03005FCC
	strh r1, [r0]
	ldr r0, _03001ECC @ =0x03005AA6
	ldrh r0, [r0]
	cmp r0, #0
	beq _03001E00
	bl sub_03000790
_03001E00:
	ldr r0, _03001ED0 @ =gUnk_03005FD8
	ldrh r0, [r0]
	cmp r0, #0
	beq _03001E5C
	bl sub_03000E10
	mov r0, r8
	adds r1, r4, #0
	bl sub_0300100C
	ldr r2, _03001ED4 @ =0x03005ACD
	ldrb r0, [r2]
	cmp r0, #0
	beq _03001E26
	ldr r0, _03001ED8 @ =0x03005AB4
	movs r1, #0xf
	strh r1, [r0]
	movs r0, #0
	strb r0, [r2]
_03001E26:
	ldr r0, _03001EDC @ =0x03005ABA
	ldrh r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _03001E3A
	ldr r0, _03001EE0 @ =0x03005AC0
	ldrh r0, [r0]
	bl sub_03000E40
_03001E3A:
	ldr r2, _03001EE4 @ =0x03005AC8
	ldrh r0, [r2]
	cmp r0, #0
	beq _03001E46
	subs r0, #1
	strh r0, [r2]
_03001E46:
	ldr r0, _03001EE8 @ =0x03005AB8
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne _03001E5C
	ldrh r0, [r2]
	cmp r0, #0
	bne _03001E5C
	bl sub_03000DEC
_03001E5C:
	ldr r1, _03001EEC @ =0x03005AC4
	ldrh r0, [r1]
	cmp r0, #0
	beq _03001E86
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _03001E86
	movs r0, #0x80
	lsls r0, r0, #0x17
	orrs r5, r0
	ldr r0, _03001ED0 @ =gUnk_03005FD8
	strh r1, [r0]
	ldr r0, _03001EF0 @ =0x03005AC6
	ldrh r0, [r0]
	cmp r0, #0
	beq _03001E86
	bl sub_03000D38
_03001E86:
	ldr r0, _03001EF4 @ =gUnk_03005FB0
	ldrh r0, [r0]
	cmp r0, #0
	beq _03001F5E
	bl sub_030014E0
	ldr r0, _03001EF8 @ =0x03005FD4
	ldrh r0, [r0]
	cmp r0, #0
	bne _03001F00
	ldr r0, _03001EFC @ =0x03005ADA
	ldrh r0, [r0]
	cmp r0, #0
	bne _03001F00
	movs r0, #0x80
	lsls r0, r0, #0x16
	orrs r5, r0
	b _03001F08
	.align 2, 0
_03001EAC: .4byte gUnk_03005FCC
_03001EB0: .4byte 0x03005AAD
_03001EB4: .4byte 0x03005A94
_03001EB8: .4byte 0x03005A9A
_03001EBC: .4byte 0x03005AA0
_03001EC0: .4byte 0x03005AA8
_03001EC4: .4byte 0x03005A98
_03001EC8: .4byte 0x03005AA4
_03001ECC: .4byte 0x03005AA6
_03001ED0: .4byte gUnk_03005FD8
_03001ED4: .4byte 0x03005ACD
_03001ED8: .4byte 0x03005AB4
_03001EDC: .4byte 0x03005ABA
_03001EE0: .4byte 0x03005AC0
_03001EE4: .4byte 0x03005AC8
_03001EE8: .4byte 0x03005AB8
_03001EEC: .4byte 0x03005AC4
_03001EF0: .4byte 0x03005AC6
_03001EF4: .4byte gUnk_03005FB0
_03001EF8: .4byte 0x03005FD4
_03001EFC: .4byte 0x03005ADA
_03001F00:
	mov r0, sb
	adds r1, r4, #0
	bl sub_0300160C
_03001F08:
	ldr r0, _03001F30 @ =0x03005AD4
	ldrh r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq _03001F16
	subs r0, r1, #1
	strh r0, [r6]
_03001F16:
	ldr r0, _03001F34 @ =0x03005AD8
	ldrh r0, [r0]
	cmp r0, #0
	bne _03001F48
	ldr r0, _03001F38 @ =0x03005ADC
	ldr r3, _03001F3C @ =0x03005ADA
	ldrh r1, [r3]
	ldrh r2, [r0]
	adds r0, r1, #0
	cmp r2, r0
	bls _03001F40
	adds r0, r1, #1
	b _03001F46
	.align 2, 0
_03001F30: .4byte 0x03005AD4
_03001F34: .4byte 0x03005AD8
_03001F38: .4byte 0x03005ADC
_03001F3C: .4byte 0x03005ADA
_03001F40:
	cmp r2, r0
	bhs _03001F48
	subs r0, r1, #1
_03001F46:
	strh r0, [r3]
_03001F48:
	ldr r0, _03001FE4 @ =0x03005ADE
	ldrh r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _03001F5E
	ldrh r0, [r6]
	cmp r0, #0
	bne _03001F5E
	bl sub_030013C8
_03001F5E:
	ldr r1, _03001FE8 @ =0x03005AD8
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _03001F80
	lsrs r0, r0, #0x11
	strh r0, [r1]
	ldr r1, _03001FEC @ =0x03005ADA
	strh r0, [r1]
	adds r1, r0, #0
	cmp r1, #0
	bne _03001F80
	movs r0, #0x80
	lsls r0, r0, #0x16
	orrs r5, r0
	ldr r0, _03001FF0 @ =gUnk_03005FB0
	strh r1, [r0]
_03001F80:
	ldr r0, _03001FF4 @ =gUnk_03005FC0
	ldrh r0, [r0]
	cmp r0, #0
	beq _03001FC4
	mov r0, sl
	adds r1, r4, #0
	bl sub_03001A24
	ldr r2, _03001FF8 @ =0x03005B08
	ldrb r0, [r2]
	cmp r0, #0
	beq _03001FA2
	ldr r0, _03001FFC @ =0x03005AF4
	movs r1, #0xf
	strh r1, [r0]
	movs r0, #0
	strb r0, [r2]
_03001FA2:
	ldr r2, _03002000 @ =0x03005AFA
	ldrh r0, [r2]
	cmp r0, #0
	beq _03001FAE
	subs r0, #1
	strh r0, [r2]
_03001FAE:
	ldr r0, _03002004 @ =0x03005B00
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne _03001FC4
	ldrh r0, [r2]
	cmp r0, #0
	bne _03001FC4
	bl sub_03001840
_03001FC4:
	ldr r1, _03002008 @ =0x03005AFE
	ldrh r0, [r1]
	cmp r0, #0
	beq _03002016
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _0300200C
	movs r0, #0x80
	lsls r0, r0, #0x15
	orrs r5, r0
	ldr r0, _03001FF4 @ =gUnk_03005FC0
	strh r1, [r0]
	b _03002016
	.align 2, 0
_03001FE4: .4byte 0x03005ADE
_03001FE8: .4byte 0x03005AD8
_03001FEC: .4byte 0x03005ADA
_03001FF0: .4byte gUnk_03005FB0
_03001FF4: .4byte gUnk_03005FC0
_03001FF8: .4byte 0x03005B08
_03001FFC: .4byte 0x03005AF4
_03002000: .4byte 0x03005AFA
_03002004: .4byte 0x03005B00
_03002008: .4byte 0x03005AFE
_0300200C:
	lsrs r2, r4, #4
	mov r0, sl
	adds r1, r4, #0
	bl sub_0300059C
_03002016:
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_03000634
	adds r0, r7, #0
	adds r1, r4, #0
	bl sub_03000704
	adds r0, r7, #0
	adds r1, r4, #0
	bl sub_030006CC
_0300202E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_0300203C
sub_0300203C: @ 0x0300203C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r0, _03002154 @ =0x03005B50
	mov r8, r0
	bl sub_0300173C
	movs r3, #0
	movs r2, #0
	mov sl, r8
	ldr r1, _03002158 @ =0x03005BF0
	mov sb, r1
	mov ip, r8
	mov r4, sb
_0300205E:
	lsls r1, r3, #2
	mov r0, ip
	adds r0, #4
	mov ip, r0
	subs r0, #4
	stm r0!, {r2}
	stm r4!, {r2}
	ldr r0, _0300215C @ =0x03005C90
	adds r0, r1, r0
	str r2, [r0]
	ldr r0, _03002160 @ =0x03005D30
	adds r0, r1, r0
	str r2, [r0]
	ldr r7, _03002164 @ =0x03005DD0
	adds r0, r1, r7
	str r2, [r0]
	ldr r6, _03002168 @ =0x03005E70
	adds r0, r1, r6
	str r2, [r0]
	ldr r5, _0300216C @ =0x03005F10
	adds r1, r1, r5
	str r2, [r1]
	adds r3, #1
	cmp r3, #0x27
	bls _0300205E
	ldr r0, _03002170 @ =0x03005A80
	mov r1, sl
	str r1, [r0]
	ldr r0, _03002174 @ =0x03005A84
	mov r1, sb
	str r1, [r0]
	ldr r0, _03002178 @ =0x03005A88
	ldr r1, _0300215C @ =0x03005C90
	str r1, [r0]
	ldr r0, _0300217C @ =0x03005A8C
	ldr r1, _03002160 @ =0x03005D30
	str r1, [r0]
	ldr r0, _03002180 @ =0x03005A90
	movs r4, #0
	str r4, [r0]
	ldr r0, _03002184 @ =0x03005FD0
	str r4, [r0]
	ldr r0, _03002188 @ =0x03005AD0
	str r4, [r0]
	ldr r0, _0300218C @ =0x03005FDC
	str r4, [r0]
	ldr r1, _03002190 @ =0x03005AE8
	movs r0, #0x88
	lsls r0, r0, #7
	str r0, [r1]
	ldr r0, _03002194 @ =0x03005A96
	strh r4, [r0]
	ldr r0, _03002198 @ =0x03005AB6
	strh r4, [r0]
	bl sub_03000824
	bl sub_03000DEC
	bl sub_030013C8
	bl sub_03001840
	movs r0, #0xf0
	lsls r0, r0, #0x18
	movs r1, #0xa0
	bl sub_03000634
	mov r0, r8
	movs r1, #0xa0
	bl sub_03000618
	adds r0, r7, #0
	movs r1, #0xa0
	bl sub_03000704
	adds r0, r6, #0
	movs r1, #0xa0
	bl sub_03000704
	adds r0, r5, #0
	movs r1, #0xa0
	bl sub_03000704
	adds r0, r7, #0
	movs r1, #0xa0
	bl sub_03000618
	adds r0, r6, #0
	movs r1, #0xa0
	bl sub_03000618
	adds r0, r5, #0
	movs r1, #0xa0
	bl sub_03000618
	ldr r0, _0300219C @ =0x03005A7A
	strh r4, [r0]
	ldr r0, _030021A0 @ =0x03005A7C
	strh r4, [r0]
	movs r0, #0x80
	lsls r0, r0, #8
	bl sub_03000050
	adds r3, r0, #0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #0xa0
	str r0, [sp]
	ldr r0, _030021A4 @ =sub_03001D30
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl sub_030002A4
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_03002154: .4byte 0x03005B50
_03002158: .4byte 0x03005BF0
_0300215C: .4byte 0x03005C90
_03002160: .4byte 0x03005D30
_03002164: .4byte 0x03005DD0
_03002168: .4byte 0x03005E70
_0300216C: .4byte 0x03005F10
_03002170: .4byte 0x03005A80
_03002174: .4byte 0x03005A84
_03002178: .4byte 0x03005A88
_0300217C: .4byte 0x03005A8C
_03002180: .4byte 0x03005A90
_03002184: .4byte 0x03005FD0
_03002188: .4byte 0x03005AD0
_0300218C: .4byte 0x03005FDC
_03002190: .4byte 0x03005AE8
_03002194: .4byte 0x03005A96
_03002198: .4byte 0x03005AB6
_0300219C: .4byte 0x03005A7A
_030021A0: .4byte 0x03005A7C
_030021A4: .4byte sub_03001D30

	thumb_func_start sub_030021A8
sub_030021A8: @ 0x030021A8
	bx lr
	.align 2, 0
_030021AC: .4byte 0x03005AF4
_030021B0: .4byte 0x03005B00
_030021B4: .4byte 0x03005AF8
_030021B8: .4byte 0x03005AEC
_030021BC: .4byte 0x03005AF0
_030021C0: .4byte 0x03005AF4
_030021C4: .4byte 0x03005AF6
_030021C8: .4byte 0x03002948
_030021CC: .4byte 0x03005AE8
_030021D0: .4byte 0x03002846
_030021D4: .4byte 0x03005AF4
_030021D8: .4byte 0x03005AE8
_030021DC: .4byte 0x03005AEC
_030021E0: .4byte 0x03005AFE

@ file split

@ 	thumb_func_start _call_via_r0
@ _call_via_r0: @ 0x030021E4
@ 	bx r0
@ 	nop

@ 	thumb_func_start _call_via_r1
@ _call_via_r1: @ 0x030021E8
@ 	bx r1
@ 	nop

@ 	thumb_func_start _call_via_r2
@ _call_via_r2: @ 0x030021EC
@ 	bx r2
@ 	nop

@ 	thumb_func_start _call_via_r3
@ _call_via_r3: @ 0x030021F0
@ 	bx r3
@ 	nop

@ 	thumb_func_start _call_via_r4
@ _call_via_r4: @ 0x030021F4
@ 	bx r4
@ 	nop

@ 	thumb_func_start _call_via_r5
@ _call_via_r5: @ 0x030021F8
@ 	bx r5
@ 	nop

@ 	thumb_func_start _call_via_r6
@ _call_via_r6: @ 0x030021FC
@ 	bx r6
@ 	nop

@ 	thumb_func_start _call_via_r7
@ _call_via_r7: @ 0x03002200
@ 	bx r7
@ 	nop

@ 	thumb_func_start _call_via_r8
@ _call_via_r8: @ 0x03002204
@ 	bx r8
@ 	nop

@ 	thumb_func_start _call_via_r9
@ _call_via_r9: @ 0x03002208
@ 	bx r9
@ 	nop

@ 	thumb_func_start _call_via_sl
@ _call_via_sl: @ 0x0300220C
@ 	bx sl
@ 	nop

@ 	thumb_func_start _call_via_fp
@ _call_via_fp: @ 0x03002210
@ 	bx fp
@ 	nop

@ 	thumb_func_start _call_via_ip
@ _call_via_ip: @ 0x03002214
@ 	bx ip
@ 	nop

@ 	thumb_func_start _call_via_sp
@ _call_via_sp: @ 0x03002218
@ 	bx sp
@ 	nop

@ 	thumb_func_start _call_via_lr
@ _call_via_lr: @ 0x0300221C
@ 	bx lr
@ 	nop

@ 	thumb_func_start __divsi3
@ __divsi3: @ 0x03002220
@ 	cmp r1, #0
@ 	beq _030022A8
@ 	push {r4}
@ 	adds r4, r0, #0
@ 	eors r4, r1
@ 	mov ip, r4
@ 	movs r3, #1
@ 	movs r2, #0
@ 	cmp r1, #0
@ 	bpl _03002236
@ 	rsbs r1, r1, #0
@ _03002236:
@ 	cmp r0, #0
@ 	bpl _0300223C
@ 	rsbs r0, r0, #0
@ _0300223C:
@ 	cmp r0, r1
@ 	blo _0300229A
@ 	movs r4, #1
@ 	lsls r4, r4, #0x1c
@ _03002244:
@ 	cmp r1, r4
@ 	bhs _03002252
@ 	cmp r1, r0
@ 	bhs _03002252
@ 	lsls r1, r1, #4
@ 	lsls r3, r3, #4
@ 	b _03002244
@ _03002252:
@ 	lsls r4, r4, #3
@ _03002254:
@ 	cmp r1, r4
@ 	bhs _03002262
@ 	cmp r1, r0
@ 	bhs _03002262
@ 	lsls r1, r1, #1
@ 	lsls r3, r3, #1
@ 	b _03002254
@ _03002262:
@ 	cmp r0, r1
@ 	blo _0300226A
@ 	subs r0, r0, r1
@ 	orrs r2, r3
@ _0300226A:
@ 	lsrs r4, r1, #1
@ 	cmp r0, r4
@ 	blo _03002276
@ 	subs r0, r0, r4
@ 	lsrs r4, r3, #1
@ 	orrs r2, r4
@ _03002276:
@ 	lsrs r4, r1, #2
@ 	cmp r0, r4
@ 	blo _03002282
@ 	subs r0, r0, r4
@ 	lsrs r4, r3, #2
@ 	orrs r2, r4
@ _03002282:
@ 	lsrs r4, r1, #3
@ 	cmp r0, r4
@ 	blo _0300228E
@ 	subs r0, r0, r4
@ 	lsrs r4, r3, #3
@ 	orrs r2, r4
@ _0300228E:
@ 	cmp r0, #0
@ 	beq _0300229A
@ 	lsrs r3, r3, #4
@ 	beq _0300229A
@ 	lsrs r1, r1, #4
@ 	b _03002262
@ _0300229A:
@ 	adds r0, r2, #0
@ 	mov r4, ip
@ 	cmp r4, #0
@ 	bpl _030022A4
@ 	rsbs r0, r0, #0
@ _030022A4:
@ 	pop {r4}
@ 	mov pc, lr
@ _030022A8:
@ 	push {lr}
@ 	bl __div_by_zero
@ 	movs r0, #0
@ 	pop {pc}
@ 	.align 2, 0

@ 	thumb_func_start __div_by_zero
@ __div_by_zero: @ 0x030022B4
@ 	mov pc, lr
@ 	.align 2, 0

@ 	thumb_func_start __udivsi3
@ __udivsi3: @ 0x030022B8
@ 	cmp r1, #0
@ 	beq _03002326
@ 	movs r3, #1
@ 	movs r2, #0
@ 	push {r4}
@ 	cmp r0, r1
@ 	blo _03002320
@ 	movs r4, #1
@ 	lsls r4, r4, #0x1c
@ _030022CA:
@ 	cmp r1, r4
@ 	bhs _030022D8
@ 	cmp r1, r0
@ 	bhs _030022D8
@ 	lsls r1, r1, #4
@ 	lsls r3, r3, #4
@ 	b _030022CA
@ _030022D8:
@ 	lsls r4, r4, #3
@ _030022DA:
@ 	cmp r1, r4
@ 	bhs _030022E8
@ 	cmp r1, r0
@ 	bhs _030022E8
@ 	lsls r1, r1, #1
@ 	lsls r3, r3, #1
@ 	b _030022DA
@ _030022E8:
@ 	cmp r0, r1
@ 	blo _030022F0
@ 	subs r0, r0, r1
@ 	orrs r2, r3
@ _030022F0:
@ 	lsrs r4, r1, #1
@ 	cmp r0, r4
@ 	blo _030022FC
@ 	subs r0, r0, r4
@ 	lsrs r4, r3, #1
@ 	orrs r2, r4
@ _030022FC:
@ 	lsrs r4, r1, #2
@ 	cmp r0, r4
@ 	blo _03002308
@ 	subs r0, r0, r4
@ 	lsrs r4, r3, #2
@ 	orrs r2, r4
@ _03002308:
@ 	lsrs r4, r1, #3
@ 	cmp r0, r4
@ 	blo _03002314
@ 	subs r0, r0, r4
@ 	lsrs r4, r3, #3
@ 	orrs r2, r4
@ _03002314:
@ 	cmp r0, #0
@ 	beq _03002320
@ 	lsrs r3, r3, #4
@ 	beq _03002320
@ 	lsrs r1, r1, #4
@ 	b _030022E8
@ _03002320:
@ 	adds r0, r2, #0
@ 	pop {r4}
@ 	mov pc, lr
@ _03002326:
@ 	push {lr}
@ 	bl __div_by_zero
@ 	movs r0, #0
@ 	pop {pc}
