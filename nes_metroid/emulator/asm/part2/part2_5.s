    .include "asm/constants.inc"
    .include "asm/macros.inc"

    .syntax unified

	thumb_func_start sub_03001730
sub_03001730: @ 0x03001730
	ldr r1, _03001738 @ =gUnk_03005AEC
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_03001738: .4byte gUnk_03005AEC

	thumb_func_start sub_0300173C
sub_0300173C: @ 0x0300173C
	push {r4, r5, lr}
	movs r3, #0
	movs r0, #0x80
	lsls r0, r0, #9
	ldr r1, _0300177C @ =gUnk_03005B10
_03001746:
	stm r1!, {r0}
	adds r3, #1
	cmp r3, #2
	bls _03001746
	movs r3, #3
	ldr r0, _0300177C @ =gUnk_03005B10
	ldr r1, _03001780 @ =sUnk_0600E008
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
_0300177C: .4byte gUnk_03005B10
_03001780: .4byte sUnk_0600E008
_03001784: .4byte 0x0000FFFF

	thumb_func_start sub_03001788
sub_03001788: @ 0x03001788
	ldr r1, _03001790 @ =gUnk_03005AFA
	strh r0, [r1]
	bx lr
	.align 2, 0
_03001790: .4byte gUnk_03005AFA

	thumb_func_start sub_03001794
sub_03001794: @ 0x03001794
	push {r4, r5, lr}
	ldr r0, _030017C0 @ =gUnk_03005A7A
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _030017A8
	ldr r1, _030017C4 @ =gUnk_03005FC0
	movs r0, #1
	strh r0, [r1]
_030017A8:
	ldr r1, _030017C8 @ =gUnk_03005B00
	ldrh r2, [r1]
	movs r0, #0x10
	ands r0, r2
	adds r3, r1, #0
	cmp r0, #0
	beq _030017D0
	ldr r1, _030017CC @ =gUnk_03005AF4
	movs r0, #0xf
	ands r0, r2
	b _030017D4
	.align 2, 0
_030017C0: .4byte gUnk_03005A7A
_030017C4: .4byte gUnk_03005FC0
_030017C8: .4byte gUnk_03005B00
_030017CC: .4byte gUnk_03005AF4
_030017D0:
	ldr r1, _03001828 @ =gUnk_03005AF4
	movs r0, #0xf
_030017D4:
	strh r0, [r1]
	ldr r2, _0300182C @ =gUnk_03005AF8
	ldrh r1, [r3]
	movs r0, #0xf
	ands r0, r1
	strh r0, [r2]
	ldr r1, _03001830 @ =sUnk_030023DC
	ldr r2, _03001834 @ =gUnk_03005B06
	ldrh r0, [r2]
	lsrs r0, r0, #3
	adds r0, r0, r1
	ldrb r4, [r0]
	ldr r0, _03001838 @ =sUnk_03002988
	ldr r0, [r0]
	cmp r0, #0x7f
	bne _030017FA
	cmp r4, #1
	bne _030017FA
	movs r4, #2
_030017FA:
	ldr r0, _0300183C @ =gUnk_03005AF6
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
	ldr r0, _03001838 @ =sUnk_03002988
	str r4, [r0]
	lsls r0, r4, #2
	adds r0, r0, r5
	bl sub_03001788
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_03001828: .4byte gUnk_03005AF4
_0300182C: .4byte gUnk_03005AF8
_03001830: .4byte sUnk_030023DC
_03001834: .4byte gUnk_03005B06
_03001838: .4byte sUnk_03002988
_0300183C: .4byte gUnk_03005AF6

	thumb_func_start sub_03001840
sub_03001840: @ 0x03001840
	push {lr}
	ldr r0, _0300185C @ =gUnk_03005FC0
	ldrh r0, [r0]
	cmp r0, #0
	beq _03001856
	ldr r1, _03001860 @ =gUnk_03005AFE
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
_03001860: .4byte gUnk_03005AFE

	thumb_func_start sub_03001864
sub_03001864: @ 0x03001864
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _03001874 @ =gUnk_03005AF4
	strh r0, [r1]
	ldr r1, _03001878 @ =gUnk_03005AF8
	movs r0, #1
	strh r0, [r1]
	bx lr
	.align 2, 0
_03001874: .4byte gUnk_03005AF4
_03001878: .4byte gUnk_03005AF8

	thumb_func_start sub_0300187C
sub_0300187C: @ 0x0300187C
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r5, r4, #0
	ldr r3, _030018AC @ =gUnk_03005B00
	ldrb r1, [r3]
	movs r2, #0x10
	adds r0, r2, #0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	adds r1, r4, #0
	ands r1, r2
	strh r4, [r3]
	ldr r2, _030018B0 @ =gUnk_03005B08
	movs r0, #0
	strb r0, [r2]
	cmp r1, #1
	bne _030018B8
	ldr r1, _030018B4 @ =gUnk_03005AF4
	movs r0, #0xf
	ands r0, r4
	strh r0, [r1]
	b _030018D0
	.align 2, 0
_030018AC: .4byte gUnk_03005B00
_030018B0: .4byte gUnk_03005B08
_030018B4: .4byte gUnk_03005AF4
_030018B8:
	cmp r6, #0
	beq _030018D0
	ldr r0, _030018D8 @ =gUnk_03005FC0
	ldrh r0, [r0]
	cmp r0, #0
	beq _030018D0
	movs r0, #4
	strb r0, [r2]
	ldr r1, _030018DC @ =gUnk_03005AF8
	movs r0, #0xf
	ands r5, r0
	strh r5, [r1]
_030018D0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_030018D8: .4byte gUnk_03005FC0
_030018DC: .4byte gUnk_03005AF8

	thumb_func_start sub_030018E0
sub_030018E0: @ 0x030018E0
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _03001918 @ =gUnk_03005B04
	strh r0, [r1]
	ldr r3, _0300191C @ =gUnk_03005AF6
	movs r1, #0xf
	ands r1, r0
	strh r1, [r3]
	ldr r4, _03001920 @ =gUnk_03005AF0
	ldr r2, _03001924 @ =gUnk_03005B10
	ldrh r1, [r3]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	str r1, [r4]
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq _03001930
	ldr r1, _03001928 @ =sUnk_03002846
	movs r0, #0x40
	strh r0, [r1]
	ldr r1, _0300192C @ =gUnk_03005AE8
	movs r0, #1
	str r0, [r1]
	b _0300193A
	.align 2, 0
_03001918: .4byte gUnk_03005B04
_0300191C: .4byte gUnk_03005AF6
_03001920: .4byte gUnk_03005AF0
_03001924: .4byte gUnk_03005B10
_03001928: .4byte sUnk_03002846
_0300192C: .4byte gUnk_03005AE8
_03001930:
	ldr r1, _03001940 @ =sUnk_03002846
	movs r2, #0x80
	lsls r2, r2, #7
	adds r0, r2, #0
	strh r0, [r1]
_0300193A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_03001940: .4byte sUnk_03002846

	thumb_func_start sub_03001944
sub_03001944: @ 0x03001944
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r0, _03001964 @ =gUnk_03005B04
	ldrh r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _03001970
	ldr r1, _03001968 @ =sUnk_03002846
	movs r0, #0x40
	strh r0, [r1]
	ldr r1, _0300196C @ =gUnk_03005AE8
	movs r0, #1
	str r0, [r1]
	b _0300197A
	.align 2, 0
_03001964: .4byte gUnk_03005B04
_03001968: .4byte sUnk_03002846
_0300196C: .4byte gUnk_03005AE8
_03001970:
	ldr r1, _03001988 @ =sUnk_03002846
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	strh r0, [r1]
_0300197A:
	ldr r0, _0300198C @ =gUnk_03005B06
	strh r2, [r0]
	bl sub_03001794
	pop {r0}
	bx r0
	.align 2, 0
_03001988: .4byte sUnk_03002846
_0300198C: .4byte gUnk_03005B06

	thumb_func_start sub_03001990
sub_03001990: @ 0x03001990
	push {r4, lr}
	ldr r1, _030019E4 @ =gUnk_03005AE8
	movs r0, #1
	str r0, [r1]
	ldr r0, _030019E8 @ =gUnk_03005AEC
	movs r1, #0
	str r1, [r0]
	ldr r0, _030019EC @ =gUnk_03005AF0
	str r1, [r0]
	ldr r0, _030019F0 @ =gUnk_03005AF4
	movs r3, #0
	strh r1, [r0]
	ldr r0, _030019F4 @ =gUnk_03005AF6
	strh r1, [r0]
	ldr r0, _030019F8 @ =gUnk_03005AF8
	strh r1, [r0]
	ldr r0, _030019FC @ =gUnk_03005AFA
	strh r1, [r0]
	ldr r0, _03001A00 @ =gUnk_03005AFC
	strh r1, [r0]
	ldr r2, _03001A04 @ =sUnk_03002846
	movs r4, #0x80
	lsls r4, r4, #8
	adds r0, r4, #0
	strh r0, [r2]
	ldr r0, _03001A08 @ =gUnk_03005FC0
	strh r1, [r0]
	ldr r0, _03001A0C @ =gUnk_03005AFE
	strh r1, [r0]
	ldr r0, _03001A10 @ =gUnk_03005B00
	strh r1, [r0]
	ldr r0, _03001A14 @ =gUnk_03005B02
	strh r1, [r0]
	ldr r0, _03001A18 @ =gUnk_03005B04
	strh r1, [r0]
	ldr r0, _03001A1C @ =gUnk_03005B06
	strh r1, [r0]
	ldr r0, _03001A20 @ =gUnk_03005B08
	strb r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_030019E4: .4byte gUnk_03005AE8
_030019E8: .4byte gUnk_03005AEC
_030019EC: .4byte gUnk_03005AF0
_030019F0: .4byte gUnk_03005AF4
_030019F4: .4byte gUnk_03005AF6
_030019F8: .4byte gUnk_03005AF8
_030019FC: .4byte gUnk_03005AFA
_03001A00: .4byte gUnk_03005AFC
_03001A04: .4byte sUnk_03002846
_03001A08: .4byte gUnk_03005FC0
_03001A0C: .4byte gUnk_03005AFE
_03001A10: .4byte gUnk_03005B00
_03001A14: .4byte gUnk_03005B02
_03001A18: .4byte gUnk_03005B04
_03001A1C: .4byte gUnk_03005B06
_03001A20: .4byte gUnk_03005B08

	thumb_func_start sub_03001A24
sub_03001A24: @ 0x03001A24
	bx pc
	nop

	arm_func_start sub_03001A28
sub_03001A28: @ 0x03001A28
	push {r4, r5, r6, r7, r8, sb, sl, fp}
	ldr r6, _030021AC @ =gUnk_03005AF4
	ldr r3, _030021B0 @ =gUnk_03005B00
	ldrh r2, [r3]
	and r5, r2, #0xf
	tst r2, #0x10
	bne _03001A7C
	ldrh r5, [r6]
	ldr r4, _030021B4 @ =gUnk_03005AF8
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
	ldr r2, _030021B8 @ =gUnk_03005AEC
	ldr r2, [r2]
	ldr r3, _030021BC @ =gUnk_03005AF0
	ldr r3, [r3]
	ldr r6, _030021C0 @ =gUnk_03005AF4
	ldrh r6, [r6]
	ldr r4, _030021C4 @ =gUnk_03005AF6
	ldrh r5, [r4]
	lsl r5, r5, #2
	ldr r4, _030021C8 @ =sUnk_03002948
	ldr sl, [r4, r5]
	ldrb sl, [sl, r6]
	mov r5, #0x10000
	sub r4, r5, #1
	ldr r8, _030021CC @ =gUnk_03005AE8
	ldr r8, [r8]
	ldr fp, _030021D0 @ =sUnk_03002846
	ldrh fp, [fp]
_03001AC8:
	ldr r6, _030021D4 @ =gUnk_03005AF4
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
	ldr r3, _030021D8 @ =gUnk_03005AE8
	str r8, [r3]
	ldr r3, _030021DC @ =gUnk_03005AEC
	str r2, [r3]
	pop {r4, r5, r6, r7, r8, sb, sl, fp}
	bx lr
_03001BF8:
	ldr r3, _030021E0 @ =gUnk_03005AFE
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
	ldr r0, _03001C54 @ =gUnk_03005A7A
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
_03001C54: .4byte gUnk_03005A7A

	thumb_func_start sub_03001C58
sub_03001C58: @ 0x03001C58
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _03001C74 @ =gUnk_03005A7C
	strh r0, [r1]
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq _03001C78
	movs r0, #0xa0
	bl sub_03000000
	b _03001C7E
	.align 2, 0
_03001C74: .4byte gUnk_03005A7C
_03001C78:
	movs r0, #0x80
	bl sub_03000000
_03001C7E:
	ldr r1, _03001CFC @ =gUnk_03005AA2
	ldrh r0, [r1]
	cmp r0, #1
	bls _03001C8A
	subs r0, #1
	strh r0, [r1]
_03001C8A:
	ldr r1, _03001D00 @ =gUnk_03005AC2
	ldrh r0, [r1]
	cmp r0, #1
	bls _03001C96
	subs r0, #1
	strh r0, [r1]
_03001C96:
	ldr r1, _03001D04 @ =gUnk_03005AF8
	ldrh r0, [r1]
	cmp r0, #1
	bls _03001CA2
	subs r0, #1
	strh r0, [r1]
_03001CA2:
	ldr r1, _03001D08 @ =gUnk_03005AD6
	ldrh r0, [r1]
	cmp r0, #1
	bls _03001CAE
	subs r0, #1
	strh r0, [r1]
_03001CAE:
	ldr r1, _03001D0C @ =gUnk_03005AAA
	ldrh r0, [r1]
	cmp r0, #1
	bls _03001CBA
	subs r0, #1
	strh r0, [r1]
_03001CBA:
	ldr r1, _03001D10 @ =gUnk_03005ACA
	ldrh r0, [r1]
	cmp r0, #1
	bls _03001CC6
	subs r0, #1
	strh r0, [r1]
_03001CC6:
	ldr r1, _03001D14 @ =gUnk_03005AA8
	ldrh r0, [r1]
	cmp r0, #0
	beq _03001CD2
	subs r0, #1
	strh r0, [r1]
_03001CD2:
	ldr r1, _03001D18 @ =gUnk_03005AC8
	ldrh r0, [r1]
	cmp r0, #0
	beq _03001CDE
	subs r0, #1
	strh r0, [r1]
_03001CDE:
	ldr r1, _03001D1C @ =gUnk_03005AD4
	ldrh r0, [r1]
	cmp r0, #0
	beq _03001CEA
	subs r0, #1
	strh r0, [r1]
_03001CEA:
	ldr r1, _03001D20 @ =gUnk_03005AFA
	ldrh r0, [r1]
	cmp r0, #0
	beq _03001CF6
	subs r0, #1
	strh r0, [r1]
_03001CF6:
	pop {r0}
	bx r0
	.align 2, 0
_03001CFC: .4byte gUnk_03005AA2
_03001D00: .4byte gUnk_03005AC2
_03001D04: .4byte gUnk_03005AF8
_03001D08: .4byte gUnk_03005AD6
_03001D0C: .4byte gUnk_03005AAA
_03001D10: .4byte gUnk_03005ACA
_03001D14: .4byte gUnk_03005AA8
_03001D18: .4byte gUnk_03005AC8
_03001D1C: .4byte gUnk_03005AD4
_03001D20: .4byte gUnk_03005AFA

	thumb_func_start sub_03001D24
sub_03001D24: @ 0x03001D24
	ldr r1, _03001D2C @ =gUnk_03005FB8
	strb r0, [r1]
	bx lr
	.align 2, 0
_03001D2C: .4byte gUnk_03005FB8

	thumb_func_start sub_03001D30
sub_03001D30: @ 0x03001D30
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	adds r4, r1, #0
	ldr r6, _03001D68 @ =gUnk_03005B50
	ldr r0, _03001D6C @ =gUnk_03005BF0
	mov r8, r0
	ldr r0, _03001D70 @ =gUnk_03005C90
	mov sb, r0
	ldr r0, _03001D74 @ =gUnk_03005D30
	mov sl, r0
	movs r5, #0
	ldr r0, _03001D78 @ =gUnk_03005FB8
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
_03001D68: .4byte gUnk_03005B50
_03001D6C: .4byte gUnk_03005BF0
_03001D70: .4byte gUnk_03005C90
_03001D74: .4byte gUnk_03005D30
_03001D78: .4byte gUnk_03005FB8
_03001D7C:
	ldr r0, _03001EAC @ =gUnk_03005FCC
	ldrh r0, [r0]
	cmp r0, #0
	beq _03001DD6
	bl sub_03000948
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_03000A6C
	ldr r2, _03001EB0 @ =gUnk_03005AAD
	ldrb r0, [r2]
	cmp r0, #0
	beq _03001DA0
	ldr r1, _03001EB4 @ =gUnk_03005A94
	movs r0, #0xf
	strh r0, [r1]
	strb r5, [r2]
_03001DA0:
	ldr r0, _03001EB8 @ =gUnk_03005A9A
	ldrh r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _03001DB4
	ldr r0, _03001EBC @ =gUnk_03005AA0
	ldrh r0, [r0]
	bl sub_03000848
_03001DB4:
	ldr r2, _03001EC0 @ =gUnk_03005AA8
	ldrh r0, [r2]
	cmp r0, #0
	beq _03001DC0
	subs r0, #1
	strh r0, [r2]
_03001DC0:
	ldr r0, _03001EC4 @ =gUnk_03005A98
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
	ldr r1, _03001EC8 @ =gUnk_03005AA4
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
	ldr r0, _03001ECC @ =gUnk_03005AA6
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
	ldr r2, _03001ED4 @ =gUnk_03005ACD
	ldrb r0, [r2]
	cmp r0, #0
	beq _03001E26
	ldr r0, _03001ED8 @ =gUnk_03005AB4
	movs r1, #0xf
	strh r1, [r0]
	movs r0, #0
	strb r0, [r2]
_03001E26:
	ldr r0, _03001EDC @ =gUnk_03005ABA
	ldrh r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _03001E3A
	ldr r0, _03001EE0 @ =gUnk_03005AC0
	ldrh r0, [r0]
	bl sub_03000E40
_03001E3A:
	ldr r2, _03001EE4 @ =gUnk_03005AC8
	ldrh r0, [r2]
	cmp r0, #0
	beq _03001E46
	subs r0, #1
	strh r0, [r2]
_03001E46:
	ldr r0, _03001EE8 @ =gUnk_03005AB8
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
	ldr r1, _03001EEC @ =gUnk_03005AC4
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
	ldr r0, _03001EF0 @ =gUnk_03005AC6
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
	ldr r0, _03001EF8 @ =gUnk_03005FD4
	ldrh r0, [r0]
	cmp r0, #0
	bne _03001F00
	ldr r0, _03001EFC @ =gUnk_03005ADA
	ldrh r0, [r0]
	cmp r0, #0
	bne _03001F00
	movs r0, #0x80
	lsls r0, r0, #0x16
	orrs r5, r0
	b _03001F08
	.align 2, 0
_03001EAC: .4byte gUnk_03005FCC
_03001EB0: .4byte gUnk_03005AAD
_03001EB4: .4byte gUnk_03005A94
_03001EB8: .4byte gUnk_03005A9A
_03001EBC: .4byte gUnk_03005AA0
_03001EC0: .4byte gUnk_03005AA8
_03001EC4: .4byte gUnk_03005A98
_03001EC8: .4byte gUnk_03005AA4
_03001ECC: .4byte gUnk_03005AA6
_03001ED0: .4byte gUnk_03005FD8
_03001ED4: .4byte gUnk_03005ACD
_03001ED8: .4byte gUnk_03005AB4
_03001EDC: .4byte gUnk_03005ABA
_03001EE0: .4byte gUnk_03005AC0
_03001EE4: .4byte gUnk_03005AC8
_03001EE8: .4byte gUnk_03005AB8
_03001EEC: .4byte gUnk_03005AC4
_03001EF0: .4byte gUnk_03005AC6
_03001EF4: .4byte gUnk_03005FB0
_03001EF8: .4byte gUnk_03005FD4
_03001EFC: .4byte gUnk_03005ADA
_03001F00:
	mov r0, sb
	adds r1, r4, #0
	bl sub_0300160C
_03001F08:
	ldr r0, _03001F30 @ =gUnk_03005AD4
	ldrh r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq _03001F16
	subs r0, r1, #1
	strh r0, [r6]
_03001F16:
	ldr r0, _03001F34 @ =gUnk_03005AD8
	ldrh r0, [r0]
	cmp r0, #0
	bne _03001F48
	ldr r0, _03001F38 @ =gUnk_03005ADC
	ldr r3, _03001F3C @ =gUnk_03005ADA
	ldrh r1, [r3]
	ldrh r2, [r0]
	adds r0, r1, #0
	cmp r2, r0
	bls _03001F40
	adds r0, r1, #1
	b _03001F46
	.align 2, 0
_03001F30: .4byte gUnk_03005AD4
_03001F34: .4byte gUnk_03005AD8
_03001F38: .4byte gUnk_03005ADC
_03001F3C: .4byte gUnk_03005ADA
_03001F40:
	cmp r2, r0
	bhs _03001F48
	subs r0, r1, #1
_03001F46:
	strh r0, [r3]
_03001F48:
	ldr r0, _03001FE4 @ =gUnk_03005ADE
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
	ldr r1, _03001FE8 @ =gUnk_03005AD8
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _03001F80
	lsrs r0, r0, #0x11
	strh r0, [r1]
	ldr r1, _03001FEC @ =gUnk_03005ADA
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
	ldr r2, _03001FF8 @ =gUnk_03005B08
	ldrb r0, [r2]
	cmp r0, #0
	beq _03001FA2
	ldr r0, _03001FFC @ =gUnk_03005AF4
	movs r1, #0xf
	strh r1, [r0]
	movs r0, #0
	strb r0, [r2]
_03001FA2:
	ldr r2, _03002000 @ =gUnk_03005AFA
	ldrh r0, [r2]
	cmp r0, #0
	beq _03001FAE
	subs r0, #1
	strh r0, [r2]
_03001FAE:
	ldr r0, _03002004 @ =gUnk_03005B00
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
	ldr r1, _03002008 @ =gUnk_03005AFE
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
_03001FE4: .4byte gUnk_03005ADE
_03001FE8: .4byte gUnk_03005AD8
_03001FEC: .4byte gUnk_03005ADA
_03001FF0: .4byte gUnk_03005FB0
_03001FF4: .4byte gUnk_03005FC0
_03001FF8: .4byte gUnk_03005B08
_03001FFC: .4byte gUnk_03005AF4
_03002000: .4byte gUnk_03005AFA
_03002004: .4byte gUnk_03005B00
_03002008: .4byte gUnk_03005AFE
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
	ldr r0, _03002154 @ =gUnk_03005B50
	mov r8, r0
	bl sub_0300173C
	movs r3, #0
	movs r2, #0
	mov sl, r8
	ldr r1, _03002158 @ =gUnk_03005BF0
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
	ldr r0, _0300215C @ =gUnk_03005C90
	adds r0, r1, r0
	str r2, [r0]
	ldr r0, _03002160 @ =gUnk_03005D30
	adds r0, r1, r0
	str r2, [r0]
	ldr r7, _03002164 @ =gUnk_03005DD0
	adds r0, r1, r7
	str r2, [r0]
	ldr r6, _03002168 @ =gUnk_03005E70
	adds r0, r1, r6
	str r2, [r0]
	ldr r5, _0300216C @ =gUnk_03005F10
	adds r1, r1, r5
	str r2, [r1]
	adds r3, #1
	cmp r3, #0x27
	bls _0300205E
	ldr r0, _03002170 @ =gUnk_03005A80
	mov r1, sl
	str r1, [r0]
	ldr r0, _03002174 @ =gUnk_03005A84
	mov r1, sb
	str r1, [r0]
	ldr r0, _03002178 @ =gUnk_03005A88
	ldr r1, _0300215C @ =gUnk_03005C90
	str r1, [r0]
	ldr r0, _0300217C @ =gUnk_03005A8C
	ldr r1, _03002160 @ =gUnk_03005D30
	str r1, [r0]
	ldr r0, _03002180 @ =gUnk_03005A90
	movs r4, #0
	str r4, [r0]
	ldr r0, _03002184 @ =gUnk_03005FD0
	str r4, [r0]
	ldr r0, _03002188 @ =gUnk_03005AD0
	str r4, [r0]
	ldr r0, _0300218C @ =gUnk_03005FDC
	str r4, [r0]
	ldr r1, _03002190 @ =gUnk_03005AE8
	movs r0, #0x88
	lsls r0, r0, #7
	str r0, [r1]
	ldr r0, _03002194 @ =gUnk_03005A96
	strh r4, [r0]
	ldr r0, _03002198 @ =gUnk_03005AB6
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
	ldr r0, _0300219C @ =gUnk_03005A7A
	strh r4, [r0]
	ldr r0, _030021A0 @ =gUnk_03005A7C
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
_03002154: .4byte gUnk_03005B50
_03002158: .4byte gUnk_03005BF0
_0300215C: .4byte gUnk_03005C90
_03002160: .4byte gUnk_03005D30
_03002164: .4byte gUnk_03005DD0
_03002168: .4byte gUnk_03005E70
_0300216C: .4byte gUnk_03005F10
_03002170: .4byte gUnk_03005A80
_03002174: .4byte gUnk_03005A84
_03002178: .4byte gUnk_03005A88
_0300217C: .4byte gUnk_03005A8C
_03002180: .4byte gUnk_03005A90
_03002184: .4byte gUnk_03005FD0
_03002188: .4byte gUnk_03005AD0
_0300218C: .4byte gUnk_03005FDC
_03002190: .4byte gUnk_03005AE8
_03002194: .4byte gUnk_03005A96
_03002198: .4byte gUnk_03005AB6
_0300219C: .4byte gUnk_03005A7A
_030021A0: .4byte gUnk_03005A7C
_030021A4: .4byte sub_03001D30

	thumb_func_start sub_030021A8
sub_030021A8: @ 0x030021A8
	bx lr
	.align 2, 0

_030021AC: .4byte gUnk_03005AF4
_030021B0: .4byte gUnk_03005B00
_030021B4: .4byte gUnk_03005AF8
_030021B8: .4byte gUnk_03005AEC
_030021BC: .4byte gUnk_03005AF0
_030021C0: .4byte gUnk_03005AF4
_030021C4: .4byte gUnk_03005AF6
_030021C8: .4byte sUnk_03002948
_030021CC: .4byte gUnk_03005AE8
_030021D0: .4byte sUnk_03002846
_030021D4: .4byte gUnk_03005AF4
_030021D8: .4byte gUnk_03005AE8
_030021DC: .4byte gUnk_03005AEC
_030021E0: .4byte gUnk_03005AFE
