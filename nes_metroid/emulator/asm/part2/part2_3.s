    .include "asm/constants.inc"
    .include "asm/macros.inc"

    .syntax unified

	thumb_func_start sub_030009A0
sub_030009A0: @ 0x030009A0
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r0, _030009D0 @ =gUnk_03005A9E
	strh r1, [r0]
	movs r0, #7
	ands r0, r1
	lsls r0, r0, #8
	ldr r1, _030009D4 @ =gUnk_03005A9C
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
_030009D0: .4byte gUnk_03005A9E
_030009D4: .4byte gUnk_03005A9C
_030009D8: .4byte gUnk_03005FCC

	thumb_func_start sub_030009DC
sub_030009DC: @ 0x030009DC
	ldr r1, _03000A28 @ =gUnk_03005A90
	movs r0, #0
	str r0, [r1]
	ldr r1, _03000A2C @ =gUnk_03005FD0
	str r0, [r1]
	ldr r1, _03000A30 @ =gUnk_03005A94
	movs r2, #0
	strh r0, [r1]
	ldr r1, _03000A34 @ =gUnk_03005A96
	strh r0, [r1]
	ldr r1, _03000A38 @ =gUnk_03005A98
	strh r0, [r1]
	ldr r1, _03000A3C @ =gUnk_03005A9A
	strh r0, [r1]
	ldr r1, _03000A40 @ =gUnk_03005A9C
	strh r0, [r1]
	ldr r1, _03000A44 @ =gUnk_03005A9E
	strh r0, [r1]
	ldr r1, _03000A48 @ =gUnk_03005AA0
	strh r0, [r1]
	ldr r1, _03000A4C @ =gUnk_03005AA2
	strh r0, [r1]
	ldr r1, _03000A50 @ =gUnk_03005FCC
	strh r0, [r1]
	ldr r1, _03000A54 @ =gUnk_03005AA4
	strh r0, [r1]
	ldr r1, _03000A58 @ =gUnk_03005AA6
	strh r0, [r1]
	ldr r1, _03000A5C @ =gUnk_03005AA8
	strh r0, [r1]
	ldr r1, _03000A60 @ =gUnk_03005AAA
	strh r0, [r1]
	ldr r0, _03000A64 @ =gUnk_03005AAC
	strb r2, [r0]
	ldr r0, _03000A68 @ =gUnk_03005AAD
	strb r2, [r0]
	bx lr
	.align 2, 0
_03000A28: .4byte gUnk_03005A90
_03000A2C: .4byte gUnk_03005FD0
_03000A30: .4byte gUnk_03005A94
_03000A34: .4byte gUnk_03005A96
_03000A38: .4byte gUnk_03005A98
_03000A3C: .4byte gUnk_03005A9A
_03000A40: .4byte gUnk_03005A9C
_03000A44: .4byte gUnk_03005A9E
_03000A48: .4byte gUnk_03005AA0
_03000A4C: .4byte gUnk_03005AA2
_03000A50: .4byte gUnk_03005FCC
_03000A54: .4byte gUnk_03005AA4
_03000A58: .4byte gUnk_03005AA6
_03000A5C: .4byte gUnk_03005AA8
_03000A60: .4byte gUnk_03005AAA
_03000A64: .4byte gUnk_03005AAC
_03000A68: .4byte gUnk_03005AAD

	thumb_func_start sub_03000A6C
sub_03000A6C: @ 0x03000A6C
	bx pc
	nop

	arm_func_start sub_03000A70
sub_03000A70: @ 0x03000A70
	push {r4, r5, r6, r7, r8, sb, sl}
	ldr r3, _0300125C @ =gUnk_03005AA4
	ldrh r3, [r3]
	cmp r3, #0
	beq _03000A94
_03000A84:
	mov r6, #0
	ldr r3, _03001260 @ =gUnk_03005A94
	strh r6, [r3]
	b _03000B50
_03000A94:
	ldr r3, _03001264 @ =gUnk_03005A9A
	ldrh r2, [r3]
	tst r2, #0x80
	beq _03000AFC
	ldr r4, _03001268 @ =gUnk_03005AAA
	ldrh r5, [r4]
	subs r5, r5, #1
	strh r5, [r4]
	bpl _03000AFC
	mov r5, #0xe
	and r5, r5, r2, lsr #3
	orr r5, r5, #1
	strh r5, [r4]
	ldr r4, _0300126C @ =gUnk_03005AA0
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
	ldr r6, _03001270 @ =gUnk_03005A94
	ldr r3, _03001274 @ =gUnk_03005A98
	ldrh r2, [r3]
	and r5, r2, #0xf
	tst r2, #0x10
	bne _03000B4C
	ldrh r5, [r6]
	ldr r4, _03001278 @ =gUnk_03005AA2
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
	ldr r6, _0300127C @ =gUnk_03005AA0
	ldrh r6, [r6]
	cmp r6, #8
	ldr r6, _03001280 @ =gUnk_03005A94
	ldrh r6, [r6]
	movmi r6, #0
	ldr r5, _03001284 @ =gUnk_03005A96
	ldrh r5, [r5]
	ldr sl, _03001288 @ =sUnk_030025FC
	ldr r4, _0300128C @ =gUnk_03005A98
	ldrh r4, [r4]
	lsr r4, r4, #6
	ldr r8, _03001290 @ =sUnk_0300263C
	ldrb r8, [r8, r4]
	ldr sb, _03001294 @ =sUnk_03002640
	ldrb sb, [sb, r4]
	ldr r2, _03001298 @ =gUnk_03005A90
	ldr r2, [r2]
	ldr r3, _0300129C @ =gUnk_03005FD0
	ldr r3, [r3]
	ldr r4, _030012A0 @ =gUnk_03005A98
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
	ldr r3, _030012A4 @ =gUnk_03005A96
	strh r5, [r3]
	ldr r3, _030012A8 @ =gUnk_03005A90
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
	ldr r3, _030012AC @ =gUnk_03005A90
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
	ldr r3, _030012B0 @ =gUnk_03005A90
	str r2, [r3]
	pop {r4, r5, r6, r7, r8, sb, sl}
	bx lr
_03000CF8:
	ldr r3, _030012B4 @ =gUnk_03005AA4
	mov r2, #2
	strh r2, [r3]
	b _03000A84
_03000D08:
	ldr r3, _030012B8 @ =gUnk_03005AA4
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
	ldr r1, _03000D28 @ =gUnk_03005AB0
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_03000D28: .4byte gUnk_03005AB0

	thumb_func_start sub_03000D2C
sub_03000D2C: @ 0x03000D2C
	ldr r1, _03000D34 @ =gUnk_03005AC8
	strh r0, [r1]
	bx lr
	.align 2, 0
_03000D34: .4byte gUnk_03005AC8

	thumb_func_start sub_03000D38
sub_03000D38: @ 0x03000D38
	push {lr}
	ldr r0, _03000D48 @ =gUnk_03005AC4
	ldrh r1, [r0]
	cmp r1, #0
	beq _03000D50
	ldr r1, _03000D4C @ =gUnk_03005AC6
	movs r0, #1
	b _03000DCE
	.align 2, 0
_03000D48: .4byte gUnk_03005AC4
_03000D4C: .4byte gUnk_03005AC6
_03000D50:
	ldr r0, _03000D68 @ =gUnk_03005AC6
	strh r1, [r0]
	ldr r0, _03000D6C @ =gUnk_03005AB8
	ldrh r2, [r0]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _03000D74
	ldr r1, _03000D70 @ =gUnk_03005AB4
	movs r0, #0xf
	ands r0, r2
	b _03000D78
	.align 2, 0
_03000D68: .4byte gUnk_03005AC6
_03000D6C: .4byte gUnk_03005AB8
_03000D70: .4byte gUnk_03005AB4
_03000D74:
	ldr r1, _03000D90 @ =gUnk_03005AB4
	movs r0, #0xf
_03000D78:
	strh r0, [r1]
	ldr r1, _03000D94 @ =gUnk_03005AC2
	movs r0, #0xf
	strh r0, [r1]
	ldr r0, _03000D98 @ =gUnk_03005FD8
	ldrh r0, [r0]
	cmp r0, #0
	beq _03000DA0
	ldr r1, _03000D9C @ =gUnk_03005ACA
	movs r0, #1
	b _03000DA4
	.align 2, 0
_03000D90: .4byte gUnk_03005AB4
_03000D94: .4byte gUnk_03005AC2
_03000D98: .4byte gUnk_03005FD8
_03000D9C: .4byte gUnk_03005ACA
_03000DA0:
	ldr r1, _03000DD4 @ =gUnk_03005ACA
	movs r0, #4
_03000DA4:
	strh r0, [r1]
	ldr r1, _03000DD8 @ =sUnk_030023DC
	ldr r0, _03000DDC @ =gUnk_03005ABE
	ldrh r0, [r0]
	lsrs r0, r0, #3
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #2
	bl sub_03000D2C
	ldr r0, _03000DE0 @ =gUnk_03005A7A
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _03000DD0
	ldr r1, _03000DE4 @ =gUnk_03005FD8
	movs r0, #1
	strh r0, [r1]
	ldr r1, _03000DE8 @ =gUnk_03005AC4
	movs r0, #0
_03000DCE:
	strh r0, [r1]
_03000DD0:
	pop {r0}
	bx r0
	.align 2, 0
_03000DD4: .4byte gUnk_03005ACA
_03000DD8: .4byte sUnk_030023DC
_03000DDC: .4byte gUnk_03005ABE
_03000DE0: .4byte gUnk_03005A7A
_03000DE4: .4byte gUnk_03005FD8
_03000DE8: .4byte gUnk_03005AC4

	thumb_func_start sub_03000DEC
sub_03000DEC: @ 0x03000DEC
	push {lr}
	ldr r0, _03000E08 @ =gUnk_03005FD8
	ldrh r0, [r0]
	cmp r0, #0
	beq _03000E02
	ldr r1, _03000E0C @ =gUnk_03005AC4
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
_03000E0C: .4byte gUnk_03005AC4

	thumb_func_start sub_03000E10
sub_03000E10: @ 0x03000E10
	push {lr}
	ldr r0, _03000E34 @ =gUnk_03005ACC
	ldrb r0, [r0]
	cmp r0, #0
	beq _03000E2E
	ldr r0, _03000E38 @ =gUnk_03005AC0
	ldrh r1, [r0]
	movs r0, #0xf0
	lsls r0, r0, #4
	ands r0, r1
	ldr r1, _03000E3C @ =gUnk_03005ABC
	ldrh r1, [r1]
	orrs r0, r1
	bl sub_03000E40
_03000E2E:
	pop {r0}
	bx r0
	.align 2, 0
_03000E34: .4byte gUnk_03005ACC
_03000E38: .4byte gUnk_03005AC0
_03000E3C: .4byte gUnk_03005ABC

	thumb_func_start sub_03000E40
sub_03000E40: @ 0x03000E40
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r1, _03000E5C @ =gUnk_03005ACC
	movs r0, #0
	strb r0, [r1]
	ldr r0, _03000E60 @ =gUnk_03005AC0
	strh r2, [r0]
	cmp r2, #0
	bne _03000E68
	ldr r0, _03000E64 @ =gUnk_03005AB4
	strh r2, [r0]
	b _03000E82
	.align 2, 0
_03000E5C: .4byte gUnk_03005ACC
_03000E60: .4byte gUnk_03005AC0
_03000E64: .4byte gUnk_03005AB4
_03000E68:
	ldr r4, _03000E88 @ =gUnk_03005FC4
	adds r1, r2, #1
	ldr r0, _03000E8C @ =0x001B4F4D
	bl __udivsi3
	adds r1, r0, #0
	str r1, [r4]
	ldr r0, _03000E90 @ =gUnk_03005FD0
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
_03000E88: .4byte gUnk_03005FC4
_03000E8C: .4byte 0x001B4F4D
_03000E90: .4byte gUnk_03005FD0

	thumb_func_start sub_03000E94
sub_03000E94: @ 0x03000E94
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _03000EA4 @ =gUnk_03005AB4
	strh r0, [r1]
	ldr r1, _03000EA8 @ =gUnk_03005AC2
	movs r0, #1
	strh r0, [r1]
	bx lr
	.align 2, 0
_03000EA4: .4byte gUnk_03005AB4
_03000EA8: .4byte gUnk_03005AC2

	thumb_func_start sub_03000EAC
sub_03000EAC: @ 0x03000EAC
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r4, _03000F00 @ =gUnk_03005AB8
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
	ldr r2, _03000F04 @ =gUnk_03005ACD
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
	ldr r1, _03000F0C @ =gUnk_03005AC2
	movs r0, #1
	strh r0, [r1]
_03000EF8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_03000F00: .4byte gUnk_03005AB8
_03000F04: .4byte gUnk_03005ACD
_03000F08: .4byte gUnk_03005FD8
_03000F0C: .4byte gUnk_03005AC2

	thumb_func_start sub_03000F10
sub_03000F10: @ 0x03000F10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _03000F20 @ =gUnk_03005ABA
	strh r0, [r1]
	ldr r1, _03000F24 @ =gUnk_03005ACA
	movs r0, #1
	strh r0, [r1]
	bx lr
	.align 2, 0
_03000F20: .4byte gUnk_03005ABA
_03000F24: .4byte gUnk_03005ACA

	thumb_func_start sub_03000F28
sub_03000F28: @ 0x03000F28
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _03000F38 @ =gUnk_03005ABC
	strh r0, [r1]
	ldr r1, _03000F3C @ =gUnk_03005ACC
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_03000F38: .4byte gUnk_03005ABC
_03000F3C: .4byte gUnk_03005ACC

	thumb_func_start sub_03000F40
sub_03000F40: @ 0x03000F40
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r0, _03000F70 @ =gUnk_03005ABE
	strh r1, [r0]
	movs r0, #7
	ands r0, r1
	lsls r0, r0, #8
	ldr r1, _03000F74 @ =gUnk_03005ABC
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
_03000F70: .4byte gUnk_03005ABE
_03000F74: .4byte gUnk_03005ABC
_03000F78: .4byte gUnk_03005FD8

	thumb_func_start sub_03000F7C
sub_03000F7C: @ 0x03000F7C
	ldr r1, _03000FC8 @ =gUnk_03005AB0
	movs r0, #0
	str r0, [r1]
	ldr r1, _03000FCC @ =gUnk_03005FC4
	str r0, [r1]
	ldr r1, _03000FD0 @ =gUnk_03005AB4
	movs r2, #0
	strh r0, [r1]
	ldr r1, _03000FD4 @ =gUnk_03005AB6
	strh r0, [r1]
	ldr r1, _03000FD8 @ =gUnk_03005AB8
	strh r0, [r1]
	ldr r1, _03000FDC @ =gUnk_03005ABA
	strh r0, [r1]
	ldr r1, _03000FE0 @ =gUnk_03005ABC
	strh r0, [r1]
	ldr r1, _03000FE4 @ =gUnk_03005ABE
	strh r0, [r1]
	ldr r1, _03000FE8 @ =gUnk_03005AC0
	strh r0, [r1]
	ldr r1, _03000FEC @ =gUnk_03005AC2
	strh r0, [r1]
	ldr r1, _03000FF0 @ =gUnk_03005FD8
	strh r0, [r1]
	ldr r1, _03000FF4 @ =gUnk_03005AC4
	strh r0, [r1]
	ldr r1, _03000FF8 @ =gUnk_03005AC6
	strh r0, [r1]
	ldr r1, _03000FFC @ =gUnk_03005AC8
	strh r0, [r1]
	ldr r1, _03001000 @ =gUnk_03005ACA
	strh r0, [r1]
	ldr r0, _03001004 @ =gUnk_03005ACC
	strb r2, [r0]
	ldr r0, _03001008 @ =gUnk_03005ACD
	strb r2, [r0]
	bx lr
	.align 2, 0
_03000FC8: .4byte gUnk_03005AB0
_03000FCC: .4byte gUnk_03005FC4
_03000FD0: .4byte gUnk_03005AB4
_03000FD4: .4byte gUnk_03005AB6
_03000FD8: .4byte gUnk_03005AB8
_03000FDC: .4byte gUnk_03005ABA
_03000FE0: .4byte gUnk_03005ABC
_03000FE4: .4byte gUnk_03005ABE
_03000FE8: .4byte gUnk_03005AC0
_03000FEC: .4byte gUnk_03005AC2
_03000FF0: .4byte gUnk_03005FD8
_03000FF4: .4byte gUnk_03005AC4
_03000FF8: .4byte gUnk_03005AC6
_03000FFC: .4byte gUnk_03005AC8
_03001000: .4byte gUnk_03005ACA
_03001004: .4byte gUnk_03005ACC
_03001008: .4byte gUnk_03005ACD

	thumb_func_start sub_0300100C
sub_0300100C: @ 0x0300100C
	bx pc
	nop

	arm_func_start sub_03001010
sub_03001010: @ 0x03001010
	push {r4, r5, r6, r7, r8, sb, sl}
	ldr r3, _030012BC @ =gUnk_03005AC4
	ldrh r3, [r3]
	cmp r3, #0
	beq _03001034
_03001024:
	mov r6, #0
	ldr r3, _030012C0 @ =gUnk_03005AB4
	strh r6, [r3]
	b _030010EC
_03001034:
	ldr r3, _030012C4 @ =gUnk_03005ABA
	ldrh r2, [r3]
	tst r2, #0x80
	beq _03001098
	ldr r4, _030012C8 @ =gUnk_03005ACA
	ldrh r5, [r4]
	subs r5, r5, #1
	strh r5, [r4]
	bpl _03001098
	mov r5, #0xe
	and r5, r5, r2, lsr #3
	orr r5, r5, #1
	strh r5, [r4]
	ldr r4, _030012CC @ =gUnk_03005AC0
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
	ldr r6, _030012D0 @ =gUnk_03005AB4
	ldr r3, _030012D4 @ =gUnk_03005AB8
	ldrh r2, [r3]
	and r5, r2, #0xf
	tst r2, #0x10
	bne _030010E8
	ldrh r5, [r6]
	ldr r4, _030012D8 @ =gUnk_03005AC2
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
	ldr r6, _030012DC @ =gUnk_03005AC0
	ldrh r6, [r6]
	cmp r6, #8
	ldr r6, _030012E0 @ =gUnk_03005AB4
	ldrh r6, [r6]
	movmi r6, #0
	ldr r5, _030012E4 @ =gUnk_03005AB6
	ldrh r5, [r5]
	ldr sl, _030012E8 @ =sUnk_030025FC
	ldr r4, _030012EC @ =gUnk_03005AB8
	ldrh r4, [r4]
	lsr r4, r4, #6
	ldr r8, _030012F0 @ =sUnk_0300263C
	ldrb r8, [r8, r4]
	ldr sb, _030012F4 @ =sUnk_03002640
	ldrb sb, [sb, r4]
	ldr r2, _030012F8 @ =gUnk_03005AB0
	ldr r2, [r2]
	ldr r3, _030012FC @ =gUnk_03005FC4
	ldr r3, [r3]
	ldr r4, _03001300 @ =gUnk_03005AB8
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
	ldr r3, _03001304 @ =gUnk_03005AB6
	strh r5, [r3]
	ldr r3, _03001308 @ =gUnk_03005AB0
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
	ldr r3, _0300130C @ =gUnk_03005AB0
	str r2, [r3]
	pop {r4, r5, r6, r7, r8, sb, sl}
	bx lr
_03001234:
	ldr r3, _03001310 @ =gUnk_03005AC4
	mov r2, #2
	strh r2, [r3]
	b _03001024
_03001244:
	ldr r3, _03001314 @ =gUnk_03005AC4
	mov r2, #2
	strh r2, [r3]
	pop {r4, r5, r6, r7, r8, sb, sl}
	bx lr

	thumb_func_start sub_03001258
sub_03001258: @ 0x03001258
	bx lr
	.align 2, 0

_0300125C: .4byte gUnk_03005AA4
_03001260: .4byte gUnk_03005A94
_03001264: .4byte gUnk_03005A9A
_03001268: .4byte gUnk_03005AAA
_0300126C: .4byte gUnk_03005AA0
_03001270: .4byte gUnk_03005A94
_03001274: .4byte gUnk_03005A98
_03001278: .4byte gUnk_03005AA2
_0300127C: .4byte gUnk_03005AA0
_03001280: .4byte gUnk_03005A94
_03001284: .4byte gUnk_03005A96
_03001288: .4byte sUnk_030025FC
_0300128C: .4byte gUnk_03005A98
_03001290: .4byte sUnk_0300263C
_03001294: .4byte sUnk_03002640
_03001298: .4byte gUnk_03005A90
_0300129C: .4byte gUnk_03005FD0
_030012A0: .4byte gUnk_03005A98
_030012A4: .4byte gUnk_03005A96
_030012A8: .4byte gUnk_03005A90
_030012AC: .4byte gUnk_03005A90
_030012B0: .4byte gUnk_03005A90
_030012B4: .4byte gUnk_03005AA4
_030012B8: .4byte gUnk_03005AA4

_030012BC: .4byte gUnk_03005AC4
_030012C0: .4byte gUnk_03005AB4
_030012C4: .4byte gUnk_03005ABA
_030012C8: .4byte gUnk_03005ACA
_030012CC: .4byte gUnk_03005AC0
_030012D0: .4byte gUnk_03005AB4
_030012D4: .4byte gUnk_03005AB8
_030012D8: .4byte gUnk_03005AC2
_030012DC: .4byte gUnk_03005AC0
_030012E0: .4byte gUnk_03005AB4
_030012E4: .4byte gUnk_03005AB6
_030012E8: .4byte sUnk_030025FC
_030012EC: .4byte gUnk_03005AB8
_030012F0: .4byte sUnk_0300263C
_030012F4: .4byte sUnk_03002640
_030012F8: .4byte gUnk_03005AB0
_030012FC: .4byte gUnk_03005FC4
_03001300: .4byte gUnk_03005AB8
_03001304: .4byte gUnk_03005AB6
_03001308: .4byte gUnk_03005AB0
_0300130C: .4byte gUnk_03005AB0
_03001310: .4byte gUnk_03005AC4
_03001314: .4byte gUnk_03005AC4
