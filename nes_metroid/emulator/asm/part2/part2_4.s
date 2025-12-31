    .include "asm/constants.inc"
    .include "asm/macros.inc"

    .syntax unified

	thumb_func_start sub_03001318
sub_03001318: @ 0x03001318
	push {lr}
	ldr r0, _0300132C @ =gUnk_03005FB0
	ldrh r1, [r0]
	cmp r1, #0
	bne _03001326
	ldr r0, _03001330 @ =gUnk_03005AD0
	str r1, [r0]
_03001326:
	pop {r0}
	bx r0
	.align 2, 0
_0300132C: .4byte gUnk_03005FB0
_03001330: .4byte gUnk_03005AD0

	thumb_func_start sub_03001334
sub_03001334: @ 0x03001334
	ldr r1, _0300133C @ =gUnk_03005AD4
	strh r0, [r1]
	bx lr
	.align 2, 0
_0300133C: .4byte gUnk_03005AD4

	thumb_func_start sub_03001340
sub_03001340: @ 0x03001340
	push {r4, lr}
	ldr r1, _030013A4 @ =sUnk_030023DC
	ldr r0, _030013A8 @ =gUnk_03005AE2
	ldrh r0, [r0]
	lsrs r0, r0, #3
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #2
	bl sub_03001334
	ldr r0, _030013AC @ =gUnk_03005ADE
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0
	beq _03001382
	ldr r0, _030013B0 @ =gUnk_03005A7A
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
	ldr r1, _030013B8 @ =gUnk_03005AD8
	movs r0, #0
	strh r0, [r1]
_03001382:
	ldr r2, _030013BC @ =gUnk_03005AD6
	ldr r0, _030013AC @ =gUnk_03005ADE
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	adds r0, #1
	strh r0, [r2]
	ldr r2, _030013C0 @ =gUnk_03005ADA
	ldr r0, _030013C4 @ =gUnk_03005ADC
	ldrh r0, [r0]
	ldrh r1, [r2]
	adds r0, r0, r1
	asrs r0, r0, #1
	strh r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_030013A4: .4byte sUnk_030023DC
_030013A8: .4byte gUnk_03005AE2
_030013AC: .4byte gUnk_03005ADE
_030013B0: .4byte gUnk_03005A7A
_030013B4: .4byte gUnk_03005FB0
_030013B8: .4byte gUnk_03005AD8
_030013BC: .4byte gUnk_03005AD6
_030013C0: .4byte gUnk_03005ADA
_030013C4: .4byte gUnk_03005ADC

	thumb_func_start sub_030013C8
sub_030013C8: @ 0x030013C8
	push {lr}
	ldr r0, _030013E4 @ =gUnk_03005FB0
	ldrh r0, [r0]
	cmp r0, #0
	beq _030013E0
	ldr r1, _030013E8 @ =gUnk_03005AD8
	ldrh r0, [r1]
	cmp r0, #0
	bne _030013E0
	ldr r0, _030013EC @ =gUnk_03005ADA
	ldrh r0, [r0]
	strh r0, [r1]
_030013E0:
	pop {r0}
	bx r0
	.align 2, 0
_030013E4: .4byte gUnk_03005FB0
_030013E8: .4byte gUnk_03005AD8
_030013EC: .4byte gUnk_03005ADA

	thumb_func_start sub_030013F0
sub_030013F0: @ 0x030013F0
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r6, r5, #0
	ldr r2, _0300140C @ =gUnk_03005FD4
	ldr r1, _03001410 @ =sUnk_03002845
	movs r0, #0
	strb r0, [r1]
	strh r5, [r2]
	cmp r5, #0
	bne _03001418
	ldr r0, _03001414 @ =gUnk_03005ADC
	strh r5, [r0]
	b _03001446
	.align 2, 0
_0300140C: .4byte gUnk_03005FD4
_03001410: .4byte sUnk_03002845
_03001414: .4byte gUnk_03005ADC
_03001418:
	ldr r4, _0300144C @ =gUnk_03005FDC
	adds r1, r5, #1
	ldr r0, _03001450 @ =0x006D3D34
	bl __udivsi3
	str r0, [r4]
	ldr r1, _03001454 @ =gUnk_03005ADC
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
_0300144C: .4byte gUnk_03005FDC
_03001450: .4byte 0x006D3D34
_03001454: .4byte gUnk_03005ADC

	thumb_func_start sub_03001458
sub_03001458: @ 0x03001458
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, _03001488 @ =gUnk_03005AD6
	ldrh r2, [r3]
	ldr r1, _0300148C @ =gUnk_03005ADE
	strh r0, [r1]
	movs r1, #0x7f
	ands r1, r0
	cmp r1, #0
	bne _030014A4
	movs r1, #0x80
	ands r1, r2
	cmp r1, #0
	bne _03001494
	ldr r2, _03001490 @ =gUnk_03005AE4
	ldrh r0, [r2]
	cmp r0, #0
	beq _03001494
	movs r0, #1
	strh r0, [r3]
	strh r1, [r2]
	b _030014BC
	.align 2, 0
_03001488: .4byte gUnk_03005AD6
_0300148C: .4byte gUnk_03005ADE
_03001490: .4byte gUnk_03005AE4
_03001494:
	bl sub_030013C8
	ldr r1, _030014A0 @ =gUnk_03005AE4
	movs r0, #0
	strh r0, [r1]
	b _030014BC
	.align 2, 0
_030014A0: .4byte gUnk_03005AE4
_030014A4:
	ldr r0, _030014C0 @ =gUnk_03005FB0
	ldrh r0, [r0]
	ldr r2, _030014C4 @ =gUnk_03005AE4
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
_030014C4: .4byte gUnk_03005AE4

	thumb_func_start sub_030014C8
sub_030014C8: @ 0x030014C8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _030014D8 @ =gUnk_03005AE0
	strh r0, [r1]
	ldr r1, _030014DC @ =sUnk_03002845
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_030014D8: .4byte gUnk_03005AE0
_030014DC: .4byte sUnk_03002845

	thumb_func_start sub_030014E0
sub_030014E0: @ 0x030014E0
	push {lr}
	ldr r1, _0300150C @ =sUnk_03002845
	ldrb r0, [r1]
	cmp r0, #0
	beq _03001508
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _03001508
	ldr r0, _03001510 @ =gUnk_03005AE2
	ldrh r1, [r0]
	movs r0, #7
	ands r0, r1
	lsls r0, r0, #8
	ldr r1, _03001514 @ =gUnk_03005AE0
	ldrh r1, [r1]
	orrs r0, r1
	bl sub_030013F0
_03001508:
	pop {r0}
	bx r0
	.align 2, 0
_0300150C: .4byte sUnk_03002845
_03001510: .4byte gUnk_03005AE2
_03001514: .4byte gUnk_03005AE0

	thumb_func_start sub_03001518
sub_03001518: @ 0x03001518
	push {r4, lr}
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r4, _03001548 @ =gUnk_03005AE2
	strh r1, [r4]
	ldr r2, _0300154C @ =gUnk_03005AE4
	movs r0, #1
	strh r0, [r2]
	movs r0, #7
	ands r0, r1
	lsls r0, r0, #8
	ldr r1, _03001550 @ =gUnk_03005AE0
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
_03001548: .4byte gUnk_03005AE2
_0300154C: .4byte gUnk_03005AE4
_03001550: .4byte gUnk_03005AE0
_03001554: .4byte gUnk_03005FB0
_03001558:
	ldr r1, _03001584 @ =sUnk_030023DC
	ldrh r0, [r4]
	lsrs r0, r0, #3
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #2
	bl sub_03001334
	ldr r2, _03001588 @ =gUnk_03005AD6
	ldr r0, _0300158C @ =gUnk_03005ADE
	ldrh r1, [r0]
	movs r0, #0x7f
	ands r0, r1
	adds r0, #1
	strh r0, [r2]
	ldr r1, _03001590 @ =gUnk_03005AD8
	movs r0, #0
	strh r0, [r1]
_0300157C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_03001584: .4byte sUnk_030023DC
_03001588: .4byte gUnk_03005AD6
_0300158C: .4byte gUnk_03005ADE
_03001590: .4byte gUnk_03005AD8

	thumb_func_start sub_03001594
sub_03001594: @ 0x03001594
	ldr r0, _030015D4 @ =gUnk_03005AD0
	movs r1, #0
	str r1, [r0]
	ldr r0, _030015D8 @ =gUnk_03005FDC
	str r1, [r0]
	ldr r0, _030015DC @ =gUnk_03005AD4
	movs r2, #0
	strh r1, [r0]
	ldr r0, _030015E0 @ =gUnk_03005AD6
	strh r1, [r0]
	ldr r0, _030015E4 @ =gUnk_03005FB0
	strh r1, [r0]
	ldr r0, _030015E8 @ =gUnk_03005AD8
	strh r1, [r0]
	ldr r0, _030015EC @ =gUnk_03005ADA
	strh r1, [r0]
	ldr r0, _030015F0 @ =gUnk_03005ADC
	strh r1, [r0]
	ldr r0, _030015F4 @ =gUnk_03005ADE
	strh r1, [r0]
	ldr r0, _030015F8 @ =gUnk_03005AE0
	strh r1, [r0]
	ldr r0, _030015FC @ =gUnk_03005AE2
	strh r1, [r0]
	ldr r0, _03001600 @ =gUnk_03005AE4
	strh r1, [r0]
	ldr r0, _03001604 @ =gUnk_03005FD4
	strh r1, [r0]
	ldr r0, _03001608 @ =sUnk_03002845
	strb r2, [r0]
	bx lr
	.align 2, 0
_030015D4: .4byte gUnk_03005AD0
_030015D8: .4byte gUnk_03005FDC
_030015DC: .4byte gUnk_03005AD4
_030015E0: .4byte gUnk_03005AD6
_030015E4: .4byte gUnk_03005FB0
_030015E8: .4byte gUnk_03005AD8
_030015EC: .4byte gUnk_03005ADA
_030015F0: .4byte gUnk_03005ADC
_030015F4: .4byte gUnk_03005ADE
_030015F8: .4byte gUnk_03005AE0
_030015FC: .4byte gUnk_03005AE2
_03001600: .4byte gUnk_03005AE4
_03001604: .4byte gUnk_03005FD4
_03001608: .4byte sUnk_03002845

	thumb_func_start sub_0300160C
sub_0300160C: @ 0x0300160C
	bx pc
	nop

	arm_func_start sub_03001610
sub_03001610: @ 0x03001610
	push {r4, r5, r6, r7}
	ldr r2, _03001700 @ =gUnk_03005AD8
	ldrh r2, [r2]
	cmp r2, #0
	beq _03001634
_03001624:
	ldr r4, _03001704 @ =sUnk_03002645
	sub r2, r2, #1
	add r4, r4, r2, lsl #6
	b _03001674
_03001634:
	ldr r2, _03001708 @ =gUnk_03005AD6
	ldrh r3, [r2]
	subs r3, r3, #1
	strbpl r3, [r2]
	bpl _03001664
	ldr r2, _0300170C @ =gUnk_03005AE4
	mov r3, #0
	strh r3, [r2]
	ldr r2, _03001710 @ =gUnk_03005ADE
	ldrh r2, [r2]
	tst r2, #0x80
	beq _030016E8
_03001664:
	ldr r4, _03001714 @ =sUnk_03002645
	ldr r2, _03001718 @ =gUnk_03005ADA
	ldrh r2, [r2]
	add r4, r4, r2, lsl #6
_03001674:
	ldr r2, _0300171C @ =gUnk_03005AD0
	ldr r2, [r2]
	ldr r3, _03001720 @ =gUnk_03005FDC
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
	ldr r3, _03001724 @ =gUnk_03005AD0
	str r2, [r3]
	pop {r4, r5, r6, r7}
	bx lr
_030016E8:
	ldr r3, _03001728 @ =gUnk_03005AD8
	ldr r4, _0300172C @ =gUnk_03005ADA
	ldrh r2, [r4]
	strh r2, [r3]
	b _03001624

	thumb_func_start sub_030016FC
sub_030016FC: @ 0x030016FC
	bx lr
	.align 2, 0

_03001700: .4byte gUnk_03005AD8
_03001704: .4byte sUnk_03002645
_03001708: .4byte gUnk_03005AD6
_0300170C: .4byte gUnk_03005AE4
_03001710: .4byte gUnk_03005ADE
_03001714: .4byte sUnk_03002645
_03001718: .4byte gUnk_03005ADA
_0300171C: .4byte gUnk_03005AD0
_03001720: .4byte gUnk_03005FDC
_03001724: .4byte gUnk_03005AD0
_03001728: .4byte gUnk_03005AD8
_0300172C: .4byte gUnk_03005ADA
