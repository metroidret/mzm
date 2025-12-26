    .include "asm/constants.inc"
    .include "asm/macros.inc"

    .syntax unified

_0600E000:
	.byte 0x34, 0x3D, 0x6D, 0x00, 0x4D, 0x4F, 0x1B, 0x00, 0xD3, 0xD3, 0x06, 0x00, 0xEA, 0x69, 0x03, 0x00
	.byte 0xF5, 0xB4, 0x01, 0x00, 0x7A, 0xDA, 0x00, 0x00, 0x3D, 0x6D, 0x00, 0x00, 0xD3, 0x48, 0x00, 0x00
	.byte 0x9F, 0x36, 0x00, 0x00, 0xB2, 0x2B, 0x00, 0x00, 0x9C, 0x22, 0x00, 0x00, 0x86, 0x1B, 0x00, 0x00
	.byte 0x66, 0x12, 0x00, 0x00, 0xC3, 0x0D, 0x00, 0x00, 0x2D, 0x09, 0x00, 0x00, 0xE2, 0x06, 0x00, 0x00
	.byte 0x70, 0x03, 0x00, 0x00, 0x6B, 0x03, 0x00, 0x00

	thumb_func_start sub_0600E048
sub_0600E048: @ 0x0600E048
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r2, r0, #0
	str r1, [sp]
	ldr r5, _0600E0E0 @ =0x03005840
_0600E05A:
	movs r0, #0x92
	lsls r0, r0, #4
	cmp r2, r0
	bne _0600E05A
	ldr r1, [sp]
	ldr r2, _0600E0E4 @ =0x00000924
	adds r0, r1, r2
	ldr r4, [r0]
	adds r4, #0xd0
	ldr r4, [r4]
	ldr r5, [r5]
	adds r0, r4, #0
	adds r1, r5, #0
	svc #0x12
	ldr r3, _0600E0E8 @ =0x0600B800
	adds r3, #0x80
	mov sl, r3
	movs r7, #1
	movs r5, #0xf8
	lsls r5, r5, #5
	movs r0, #0x80
	lsls r0, r0, #4
	mov sb, r0
_0600E088:
	mov r1, sl
	adds r1, #0x80
	str r1, [sp, #4]
	adds r2, r7, #1
	str r2, [sp, #8]
	mov r8, r7
	mov r3, r8
	movs r0, #7
	ands r3, r0
	mov r8, r3
	mov r4, sl
	ldr r6, _0600E0E8 @ =0x0600B800
	mov ip, r7
	mov r1, ip
	movs r2, #1
	ands r1, r2
	mov ip, r1
_0600E0AA:
	ldrh r0, [r6]
	movs r1, #0x1f
	ands r1, r0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x15
	movs r3, #0x1f
	ands r2, r3
	lsrs r3, r0, #0x1a
	mov r0, r8
	cmp r0, #0
	bne _0600E0EC
	movs r0, #0x3a
	muls r1, r0, r1
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #4
	adds r0, r0, r2
	adds r1, r1, r0
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r3
	adds r1, r1, r0
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r1, r2
	b _0600E0FE
	.align 2, 0
_0600E0E0: .4byte 0x03005840
_0600E0E4: .4byte 0x00000924
_0600E0E8: .4byte 0x0600B800
_0600E0EC:
	movs r0, #0x4d
	muls r1, r0, r1
	movs r0, #0x97
	muls r0, r2, r0
	adds r1, r1, r0
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #2
	adds r1, r1, r0
_0600E0FE:
	cmp r1, r5
	bls _0600E106
	movs r1, #0xf8
	lsls r1, r1, #5
_0600E106:
	adds r3, r1, #0
	adds r2, r3, #0
	mov r0, ip
	cmp r0, #0
	beq _0600E11C
	mov r0, sb
	adds r1, r3, r0
	cmp r1, r5
	bls _0600E11C
	movs r1, #0xf8
	lsls r1, r1, #5
_0600E11C:
	movs r0, #2
	ands r0, r7
	cmp r0, #0
	beq _0600E12E
	add r2, sb
	cmp r2, r5
	bls _0600E12E
	movs r2, #0xf8
	lsls r2, r2, #5
_0600E12E:
	movs r0, #4
	ands r0, r7
	cmp r0, #0
	beq _0600E140
	add r3, sb
	cmp r3, r5
	bls _0600E140
	movs r3, #0xf8
	lsls r3, r3, #5
_0600E140:
	lsrs r1, r1, #8
	ands r2, r5
	lsrs r0, r2, #3
	orrs r1, r0
	ands r3, r5
	lsls r0, r3, #2
	orrs r1, r0
	strh r1, [r4]
	adds r4, #2
	adds r6, #2
	mov r0, sl
	adds r0, #0x7e
	cmp r4, r0
	bls _0600E0AA
	ldr r1, [sp, #4]
	mov sl, r1
	ldr r7, [sp, #8]
	cmp r7, #0xf
	bls _0600E088
	ldr r2, [sp]
	ldr r3, _0600E1BC @ =0x00000924
	adds r0, r2, r3
	ldr r0, [r0]
	adds r0, #0xcc
	ldr r1, [r0]
	adds r6, r1, #0
	adds r6, #0x64
	subs r3, #0xd0
	adds r0, r2, r3
	ldr r2, _0600E1C0 @ =0x0000FFFF
	mov sl, r2
	ldr r0, [r0]
	mov r8, r0
	mov sb, r1
	movs r7, #0x18
_0600E186:
	mov r3, sb
	adds r3, #4
	mov sb, r3
	subs r3, #4
	ldm r3!, {r5}
	adds r4, r5, #0
	mov r0, sl
	ands r4, r0
	lsls r4, r4, #4
	add r4, r8
	adds r0, r6, #0
	adds r1, r4, #0
	svc #0x11
	lsrs r5, r5, #0x10
	adds r6, r6, r5
	subs r7, #1
	cmp r7, #0
	bge _0600E186
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0600E1BC: .4byte 0x00000924
_0600E1C0: .4byte 0x0000FFFF

	arm_func_start sub_0600E1C4
sub_0600E1C4: @ 0x0600E1C4
	mov r4, #0x4000000
	mov r1, #0x1000
	orr r1, r1, #0x60
	strh r1, [r4]
	add r5, r4, #0x208
	mov r0, #0
	strh r0, [r5]
	add r6, r4, #0x100
	strh r0, [r6, #2]
	strh r0, [r6, #6]
	strh r0, [r6, #0xa]
	strh r0, [r6, #0xe]
	mov r1, #8
	strh r1, [r4, #4]
	mov r1, #0x31
	orr r1, r1, #0x2000
	strh r1, [r5, #-8]
	mvn r1, #0
	strh r1, [r5, #-6]
	mov r1, #1
	strh r1, [r5]
	ldr r4, _0600E234 @ =0x03000489
	add lr, pc, #0x0 @ =0x0600E224
	bx r4
	ldr r4, _0600E238 @ =0x03000369
	ldr r0, [sp, #0x91c]
	add lr, pc, #0x8 @ =_0600E23C
	bx r4
	.align 2, 0
_0600E234: .4byte 0x03000489
_0600E238: .4byte 0x03000369
_0600E23C:
	bl _0600EBF8
_0600E240:
	add lr, pc, #0x9C @ =0x0600E2E4
	str lr, [sp, #0x940]
_0600E248:
	ldrb r0, [sp, #0xa30]
	cmp r0, #0
	beq _0600E274
	add lr, pc, #0x14 @ =_0600E270
	mov r0, sp
	ldr r1, _0600E268 @ =0x0600A010
	ldr ip, _0600E26C @ =0x0203E38D
	bx ip
	.align 2, 0
_0600E268: .4byte 0x0600A010
_0600E26C: .4byte 0x0203E38D
_0600E270:
	strb r0, [sp, #0xa30]
_0600E274:
	ldr r1, [sp, #0x9b8]
	cmp r1, #0
	beq _0600E290
	mov r2, #0
	str r2, [sp, #0x9b8]
	add lr, pc, #0x0 @ =_0600E290
	ldr pc, _0600E2BC @ =0x030030E8
_0600E290:
	add r0, sp, #0x800
	add r0, r0, #0x84
	ldm r0!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, ip}
	ldr r0, [r0]
	bic sp, sp, #0xfe0000
	orr sp, sp, r0
	str pc, [sp, #0x9b0]
	ldr r0, [sp, #0x9cc]
	add r0, r0, #1
	str r0, [sp, #0x9cc]
	ldr pc, _0600E2C0 @ =0x03002E0C
	.align 2, 0
_0600E2BC: .4byte 0x030030E8
_0600E2C0: .4byte 0x03002E0C
_0600E2C4:
	ldrb r0, [sp, #0xa44]
	cmp r0, #0
	beq _0600E2E0
	ldr r0, [sp, #0x914]
	cmp r0, #0
	ldrne pc, [sp, #0x9bc]
	strb r0, [sp, #0xa44]
_0600E2E0:
	ldr pc, [sp, #0x940]
	add lr, pc, #0x8 @ =sub_0600E2F4
	ldr ip, _0600E2F0 @ =0x0203E261
	bx ip
	.align 2, 0
_0600E2F0: .4byte 0x0203E261

	arm_func_start sub_0600E2F4
sub_0600E2F4: @ 0x0600E2F4
	mov r0, sp
	add lr, pc, #0x8 @ =sub_0600E308
	ldr ip, _0600E304 @ =0x0203E119
	bx ip
	.align 2, 0
_0600E304: .4byte 0x0203E119

	arm_func_start sub_0600E308
sub_0600E308: @ 0x0600E308
	mov r0, sp
	add lr, pc, #0x8 @ =sub_0600E31C
	ldr ip, _0600E318 @ =0x0203E001
	bx ip
	.align 2, 0
_0600E318: .4byte 0x0203E001

	arm_func_start sub_0600E31C
sub_0600E31C: @ 0x0600E31C
	cmp r0, #0
	bne _0600E588
	ldrb r1, [sp, #0xa33]
	cmp r1, #0
	bne _0600E340
	ldrb r1, [sp, #0xa32]
	cmp r1, #0
	beq _0600E34C
	b _0600E6DC
_0600E340:
	mov r1, #0
	strb r1, [sp, #0xa33]
	b _0600E60C
_0600E34C:
	ldr r0, [sp, #0x914]
	cmp r0, #0xf
	moveq r1, #1
	strbeq r1, [sp, #0xa2c]
	beq _0600EB34
	ldrb r1, [sp, #0xa2c]
	cmp r1, #0
	cmpne r0, #0
	bne _0600EB34
	mov r1, #0
	strb r1, [sp, #0xa2c]
	cmp r0, #0x300
	beq _0600E3B8
	add lr, pc, #0x4 @ =sub_0600E38C
	ldr pc, _0600E388 @ =0x03002FAC
	.align 2, 0
_0600E388: .4byte 0x03002FAC

	arm_func_start sub_0600E38C
sub_0600E38C: @ 0x0600E38C
	add lr, pc, #0xC @ =sub_0600E3A0
	mov r0, #0x4000
	orr r0, r0, #0x15
	ldr r1, _0600E574 @ =0x03000381
	bx r1

	arm_func_start sub_0600E3A0
sub_0600E3A0: @ 0x0600E3A0
	ldr r1, [sp, #0x908]
	and r1, r1, #0xc0
	bic r0, r0, #0xc0
	orr r1, r1, r0
	str r1, [sp, #0x908]
	b _0600E248
_0600E3B8:
	mov r0, #0x41
	bl sub_06006E08
	mov r0, #0
	strb r0, [sp, #0xa45]
	strb r0, [sp, #0xa43]
	bl sub_0600EB0C
	add lr, pc, #0x24 @ =sub_0600E3FC
_0600E3D4:
	str lr, [sp, #0x940]
_0600E3D8:
	ldrb r0, [sp, #0xa48]
	cmp r0, #0
	ldreq pc, [sp, #0x9bc]
	ldr r0, [sp, #0x840]
_0600E3E8:
	ldr r1, [sp, #0x840]
	cmp r0, r1
	svceq #0x20000
	beq _0600E3E8
	b _0600E2C4

	arm_func_start sub_0600E3FC
sub_0600E3FC: @ 0x0600E3FC
	ldrb r0, [sp, #0xa45]
	cmp r0, #0x10
	addlo r0, r0, #1
	strblo r0, [sp, #0xa45]
	mov ip, #0x4000000
	rsb r2, r0, #0x10
	orr r0, r0, r2, lsl #8
	strhlo r0, [ip, #0x52]
	mov r1, #0x3800
	orr r1, r1, #0x41
	strh r1, [ip, #0x50]
	mov r0, #1
	strbhs r0, [sp, #0xa44]
	add lr, pc, #0x3C @ =sub_0600E474
	strhs lr, [sp, #0x940]
	bl sub_0600EB18
	b _0600E3D8

	arm_func_start sub_0600E440
sub_0600E440: @ 0x0600E440
	mov r0, #0
	bl sub_0600EB1C
	ldrb r0, [sp, #0xa2d]
	subs r0, r0, #1
	blo _0600E468
	strb r0, [sp, #0xa2d]
	bne _0600E3D8
	add lr, pc, #0x4 @ =_0600E468
	ldr r2, _0600E578 @ =0x0300053D
	bx r2
_0600E468:
	bl sub_0600EB04
	sub lr, pc, #0x190
	b _0600E3D4

	arm_func_start sub_0600E474
sub_0600E474: @ 0x0600E474
	ldr r0, [sp, #0x914]
	tst r0, #0xcf
	strbne r0, [sp, #0xa44]
	tst r0, #2
	bne _0600E49C
	and r1, r0, #0x300
	cmp r1, #0x300
	bne _0600E4B0
	mov r1, #1
	strb r1, [sp, #0xa44]
_0600E49C:
	mov r1, #0
	strb r1, [sp, #0xa43]
	sub lr, pc, #0x6c
	str lr, [sp, #0x940]
	b _0600EA9C
_0600E4B0:
	tst r0, #9
	ldrb r1, [sp, #0xa43]
	ldrne pc, [pc, r1, lsl #2]
	beq _0600EA58
_0600E4C0:
	.byte 0x9C, 0xE4, 0x00, 0x06, 0x90, 0xEC, 0x00, 0x06, 0x70, 0xE6, 0x00, 0x06, 0x3C, 0xE9, 0x00, 0x06

	arm_func_start sub_0600E4D0
sub_0600E4D0: @ 0x0600E4D0
	mov r7, lr
	ldr r1, [sp, #0x854]
	mov r2, sp
	add lr, pc, #0x4 @ =_0600E4E8
	ldr ip, _0600E57C @ =0x0203E415
	bx ip
_0600E4E8:
	cmp r0, #0
	moveq r0, #4
	bxeq r7
	ldr r3, [sp, #0x924]
	add r3, r3, #0xc0
	add r1, r3, #0xc
	ldr r6, [sp, #0x854]
_0600E504:
	ldr r2, [r3], #4
	ldr r8, [r6], #4
	cmp r2, r8
	movne r0, #2
	bxne r7
	cmp r3, r1
	blo _0600E504
	ldr r2, [sp, #0x854]
	ldrh r6, [r2, #0xe]
	mov r1, #0
	strh r1, [r2, #0xe]
	mov lr, r7

	arm_func_start sub_0600E534
sub_0600E534: @ 0x0600E534
	mov r7, lr
	ldr sl, _0600E584 @ =0x0000C399
	ldr r2, [sp, #0x854]
	mov r8, #0
	add fp, r2, r0
_0600E548:
	ldr sb, [r2], #4
	add lr, pc, #0x0 @ =0x0600E554
	ldr pc, _0600E580 @ =0x03002DF0
	cmp r2, fp
	blo _0600E548
	cmp r8, r6
	movne r0, #3
	bxne r7
	ldr r2, [sp, #0x854]
	ldrb r0, [r2, #0xd]
	bx r7
	.align 2, 0
_0600E574: .4byte 0x03000381
_0600E578: .4byte 0x0300053D
_0600E57C: .4byte 0x0203E415
_0600E580: .4byte 0x03002DF0
_0600E584: .4byte 0x0000C399
_0600E588:
	mov r0, #0x9c
	bl sub_06006E08
	mov r1, #0
	strb r1, [sp, #0xa43]
	mov r0, #0x10
	mov ip, #0x4000000
	rsb r2, r0, #0x10
	orr r0, r0, r2, lsl #8
	strh r0, [ip, #0x52]
	mov r1, #0x3800
	orr r1, r1, #0x41
	strh r1, [ip, #0x50]
	bl sub_0600EB18
	bl _0600E3D4
	ldr r0, [sp, #0x910]
	ldrb r1, [sp, #0xa43]
	tst r0, #0x30
	eorne r1, r1, #1
	tst r0, #2
	movne r1, #1
	strb r1, [sp, #0xa43]
	tst r1, #1
	moveq r0, #0x1d
	movne r0, #0x1e
	bl sub_06006E08
	ldr r0, [sp, #0x910]
	tst r0, #0xb
	beq _0600E3D8
	strb r0, [sp, #0xa44]
	ldrb r1, [sp, #0xa43]
	tst r1, #1
	bne _0600E60C
	b _0600E6DC
_0600E60C:
	mov r0, #0x9f
	bl sub_06006E08
	bl sub_0600EB18
	mov r1, #0
	strb r1, [sp, #0xa43]
	bl _0600E3D4
	ldr r0, [sp, #0x910]
	ldrb r1, [sp, #0xa43]
	tst r0, #0x30
	eorne r1, r1, #1
	tst r0, #2
	movne r1, #1
	strb r1, [sp, #0xa43]
	tst r1, #1
	moveq r0, #0x1d
	movne r0, #0x1e
	bl sub_06006E08
	ldr r0, [sp, #0x910]
	tst r0, #0xb
	beq _0600E3D8
	strb r0, [sp, #0xa44]
	ldrb r1, [sp, #0xa43]
	tst r1, #1
	beq _0600ECE8
	b _0600ECFC

	arm_func_start sub_0600E670
sub_0600E670: @ 0x0600E670
	mov r0, #0xa0
	bl sub_06006E08
	mov r1, #1
	strb r1, [sp, #0xa43]
	bl _0600E3D4
	ldr r0, [sp, #0x910]
	ldrb r1, [sp, #0xa43]
	tst r0, #0x30
	eorne r1, r1, #1
	tst r0, #2
	movne r1, #1
	strb r1, [sp, #0xa43]
	tst r1, #1
	moveq r0, #0x1a
	movne r0, #0x1b
	bl sub_06006E08
	ldr r0, [sp, #0x910]
	tst r0, #0xb
	beq _0600E3D8
	strb r0, [sp, #0xa44]
	mov r0, #0x80
	bl sub_06006E08
	ldrb r1, [sp, #0xa43]
	tst r1, #1
	beq _0600EB40
	ldr lr, _0600E7AC @ =sub_0600E440
	b _0600E3D4
_0600E6DC:
	bl _0600E3D4
	mov ip, #0x4000000
	ldr r1, [ip, #0x200]
	str r1, [sp, #0x944]
	mov r0, #0x10
	bl sub_06006E08
	add lr, pc, #0x4 @ =sub_0600E700
	ldr ip, _0600E7B0 @ =0x0203E391
	bx ip

	arm_func_start sub_0600E700
sub_0600E700: @ 0x0600E700
	cmp r0, #0
	movne r0, #0x18
	blne sub_06006E08
	mov ip, #0x5000000
	mov r0, #0
	strh r0, [ip]
	bl sub_0600ED14
	mov ip, #0x4000000
	mov r0, #0
	str r0, [ip, #0x200]
	ldrb r0, [sp, #0xa30]
	cmp r0, #0
	movne r0, #0
	movne r1, #0x14
	bne _0600E868
	bl sub_0600E754
	add r1, r0, #0x10
	mov r0, sp
	add lr, pc, #0x68 @ =sub_0600E7B8
	ldr ip, _0600E7B4 @ =0x0203E375
	bx ip

	arm_func_start sub_0600E754
sub_0600E754: @ 0x0600E754
	ldr r4, _0600E788 @ =0x040000D4
	ldr r0, [sp, #0x854]
	ldr r1, _0600E784 @ =0x0600A800
	ldr r5, _0600E78C @ =0x84000200
	stm r4, {r0, r1, r5}
	mov r1, r0
	ldr r0, _0600E790 @ =0x0600A000
	mov r0, r0
	mov r0, r0
	stm r4, {r0, r1, r5}
	mov r0, r1
	bx lr
	.align 2, 0
_0600E784: .4byte 0x0600A800
_0600E788: .4byte 0x040000D4
_0600E78C: .4byte 0x84000200
_0600E790: .4byte 0x0600A000

	arm_func_start sub_0600E794
sub_0600E794: @ 0x0600E794
	ldr r1, _0600E784 @ =0x0600A800
	ldr r2, [sp, #0x854]
	ldr r4, _0600E788 @ =0x040000D4
	ldr r5, _0600E78C @ =0x84000200
	stm r4, {r1, r2, r5}
	bx lr
	.align 2, 0
_0600E7AC: .4byte sub_0600E440
_0600E7B0: .4byte 0x0203E391
_0600E7B4: .4byte 0x0203E375

	arm_func_start sub_0600E7B8
sub_0600E7B8: @ 0x0600E7B8
	add r0, r0, #0x10
	ldr r3, [sp, #0x924]
	add r3, r3, #0xc0
	add r1, r3, #0xc
	ldr r6, [sp, #0x854]
_0600E7CC:
	ldr r2, [r3], #4
	str r2, [r6], #4
	cmp r3, r1
	blo _0600E7CC
	ldrb r6, [sp, #0xa2e]
	ldrb r7, [sp, #0xa2f]
	cmp r6, #2
	movhs r6, #0
	bhs _0600E810
	cmp r7, #2
	eorhs r7, r6, #1
	movhs r6, #1
	bhs _0600E810
	cmp r6, r7
	eor r7, r6, #1
	moveq r6, #1
	movne r6, #0
_0600E810:
	mov r3, #1
	add r3, r3, r7, lsl #8
	ldr r1, [sp, #0x854]
	str r3, [r1, #0xc]
	strb r7, [sp, #0xa31]
	bl sub_0600E534
	ldrb r7, [sp, #0xa31]
	mov r0, sp
	ldr r1, [sp, #0x854]
	strh r8, [r1, #0xe]
	mov r2, #0xa000
	orr r2, r2, #0x6000000
	stm r4, {r1, r2, r5}
	movs r2, r6
	ldrne r2, _0600E858 @ =0x0E007FD8
	add lr, pc, #0xC @ =sub_0600E860
	ldr ip, _0600E85C @ =0x0203E3DD
	bx ip
	.align 2, 0
_0600E858: .4byte 0x0E007FD8
_0600E85C: .4byte 0x0203E3DD

	arm_func_start sub_0600E860
sub_0600E860: @ 0x0600E860
	bl sub_0600E794
	mov r1, #3
_0600E868:
	mov r0, #0
	str r0, [sp, #0x9ac]
	strb r1, [sp, #0xa47]
	cmp r0, #0
	addeq r6, sp, r6 @ WARNING: disassembler produces wrong instruction here
	strbeq r7, [r6, #0xa2e]
	mov ip, #0x4000000
	add r2, ip, #0x208
	mov r0, #0
	strh r0, [r2]
	ldr r1, [sp, #0x944]
	str r1, [r2, #-8]
	str r0, [sp, #0x8f4]
	str r0, [sp, #0x8f0]
	strb r0, [sp, #0xa49]
	mov r1, #1
	strh r1, [r2]
	bl _0600E3D4
	ldrb r1, [sp, #0xa47]
	subs r1, r1, #1
	strbne r1, [sp, #0xa47]
	bne _0600E3D8
	ldr r0, [sp, #0x9ac]
	cmp r0, #0
	moveq r0, #0x8e
	movne r0, #0x8f
	blne sub_06006E08
	bl sub_0600EB18
	ldrb r0, [sp, #0xa41]
	cmp r0, #0
	orreq r2, r2, #0x800
	ldrb r0, [sp, #0xa42]
	cmp r0, #0
	orreq r2, r2, #0x1000
	strh r2, [r1]
	bl _0600E3D4
	ldr r0, [sp, #0x9ac]
	cmp r0, #0
	beq _0600E914
	ldr r0, [sp, #0x910]
	tst r0, #0xf
	beq _0600E3D8
	strb r0, [sp, #0xa44]
_0600E914:
	ldr lr, _0600E938 @ =sub_0600E440
	str lr, [sp, #0x940]
	mov r0, #1
	strb r0, [sp, #0xa33]
	mov r0, #0
	bl sub_0600EB1C
	mov r0, #0x80
	bl sub_06006E08
	b _0600E3D8
	.align 2, 0
_0600E938: .4byte sub_0600E440

	arm_func_start sub_0600E93C
sub_0600E93C: @ 0x0600E93C
	bl _0600E3D4
	mov ip, #0x4000000
	mov r0, #0x60
	strh r0, [ip]
	mov r0, #1
	strb r0, [sp, #0xa48]
	add lr, pc, #0x4 @ =sub_0600E960
	str lr, [sp, #0x940]
	b _0600E2C4

	arm_func_start sub_0600E960
sub_0600E960: @ 0x0600E960
	ldrb r0, [sp, #0xa48]
	cmp r0, #0
	bne _0600E2C4
	mov ip, #0x4000000
	mov r0, #0x80
	strh r0, [ip]
	mov r0, #0
	add r2, ip, #0x208
	strh r0, [r2]
	ldr r1, [r2, #-8]
	str r1, [sp, #0x944]
	mov r1, #0x8300
	orr r1, r1, #4
	strh r1, [r2, #-0xd6]
	mov r1, #0x160
	str r1, [sp, #0x928]
	mov r1, #0x3000
	strh r1, [r2, #-8]
	strh r1, [r2, #-6]
	mov r1, #1
	strh r1, [r2]
	mov r0, #0x42
	bl sub_06006E08
	mov r0, #0
	svc #0x190000
	svc #0x30000
	mov r0, #1
	svc #0x190000
	mov ip, #0x4000000
	add r2, ip, #0x208
	mov r0, #0
	strh r0, [r2]
	ldr r1, [sp, #0x944]
	str r1, [r2, #-8]
	str r0, [sp, #0x8f4]
	str r0, [sp, #0x8f0]
	mov r1, #1
	strh r1, [r2]
	str r0, [sp, #0x928]
	mov r1, #0
	orr r1, r1, #0x60
	ldrb r0, [sp, #0xa41]
	cmp r0, #0
	orreq r1, r1, #0x800
	ldrb r0, [sp, #0xa42]
	cmp r0, #0
	orreq r1, r1, #0x1000
	strh r1, [ip]
	mov r0, #0x3c
	strb r0, [sp, #0xa47]
	strb r0, [sp, #0xa44]
	str r0, [sp, #0x914]
	bl _0600E3D4
	ldrb r0, [sp, #0xa47]
	cmp r0, #0
	subne r0, r0, #1
	strbne r0, [sp, #0xa47]
	ldrne pc, [sp, #0x9bc]
	mov r0, #0x80
	bl sub_06006E08
	bl sub_0600EB04
	b _0600E240
_0600EA58:
	tst r0, #0x40
	subne r1, r1, #1
	cmp r1, #0
	movmi r1, #3
	add r2, sp, r1
	ldrb r2, [r2, #0xa4a]
	tst r2, #0x80
	bne _0600EA58
_0600EA78:
	tst r0, #0x84
	addne r1, r1, #1
	cmp r1, #4
	movhs r1, #0
	add r2, sp, r1
	ldrb r2, [r2, #0xa4a]
	tst r2, #0x80
	bne _0600EA78
	strb r1, [sp, #0xa43]
_0600EA9C:
	ldr r2, [sp, #0x934]
	add r2, r2, #0x244
	mov r3, #3
_0600EAA8:
	cmp r1, r3
	moveq r0, #0
	movne r0, #0x8000
	add ip, r2, #0x1e
_0600EAB8:
	ldrh r4, [ip, #-2]!
	bic r4, r4, #0xc000
	add r4, r4, r0
	strh r4, [ip], #-0x40
	ldrh r4, [ip]
	bic r4, r4, #0xc000
	add r4, r4, r0
	strh r4, [ip], #0x40
	cmp r2, ip
	bne _0600EAB8
	cmp r1, r3
	ldreq r4, _0600EB00 @ =0x11840183
	ldrne r4, [pc, #0x12] @ WARNING: disassembler fails to produce this instruction
	strh r4, [ip, #4]
	sub r2, r2, #0x80
	subs r3, r3, #1
	bhs _0600EAA8
	b _0600E3D8
	.align 2, 0
_0600EB00: .4byte 0x11840183

	arm_func_start sub_0600EB04
sub_0600EB04: @ 0x0600EB04
	mov r0, #0
	b _0600EB10

	arm_func_start sub_0600EB0C
sub_0600EB0C: @ 0x0600EB0C
	mov r0, #1
_0600EB10:
	ldr ip, _0600EBE4 @ =0x03001D25
	bx ip

	arm_func_start sub_0600EB18
sub_0600EB18: @ 0x0600EB18
	mov r0, #0x100

	arm_func_start sub_0600EB1C
sub_0600EB1C: @ 0x0600EB1C
	mov r1, #0x4000000
	ldrh r2, [r1]
	bic r2, r2, #0x100
	orr r2, r2, r0
	strh r2, [r1]
	bx lr
_0600EB34:
	mov r0, #0x80
	bl sub_06006E08
	b _0600ECFC
_0600EB40:
	bl sub_0600EC4C
	add r1, sp, #0x800
	add r1, r1, #0xc4
	mov r0, #0x1e
	add r2, r1, #0x20
_0600EB54:
	strb r0, [r1], #1
	teq r1, r2
	bne _0600EB54
	mov r1, #0x200
	orr r1, r1, #0x5000000
	mov r0, #0
_0600EB6C:
	str r0, [r1], #4
	tst r1, #0x1fc
	bne _0600EB6C
	mov r1, #0x5000000
_0600EB7C:
	str r0, [r1], #4
	str r0, [r1], #0x1c
	tst r1, #0x80
	beq _0600EB7C
	ldr r0, [sp, #0x8ac]
	orr r0, r0, #0x820000
	str r0, [sp, #0x8ac]
	ldr r0, [sp, #0x8bc]
	bic r0, r0, #0x80
	bic r0, r0, #0x1800
	str r0, [sp, #0x8bc]
	mvn r0, #0xf3
	eor r0, r0, #0x360
	add r1, sp, #0x200
	stmdb r1!, {r0}
	str r1, [sp, #0x88c]
	ldr lr, _0600EBE8 @ =sub_0600E440
	str lr, [sp, #0x940]
	ldr lr, _0600EBEC @ =_0600E3D8
	mov r1, #0
	strb r1, [sp, #0xa33]
	strb r1, [sp, #0xa32]
	mov r1, #0xa
	strb r1, [sp, #0xa2d]
	ldr r2, _0600EBF0 @ =0x03000501
	bx r2
	.align 2, 0
_0600EBE4: .4byte 0x03001D25
_0600EBE8: .4byte sub_0600E440
_0600EBEC: .4byte _0600E3D8
_0600EBF0: .4byte 0x03000501
_0600EBF4: .4byte 0x0600A000
_0600EBF8:
	ldr r0, _0600EBF4 @ =0x0600A000
	ldr r1, [r0]
	ldr r0, [sp, #0x924]
	ldr r2, [r0, #0xc0]
	cmp r1, r2
	bxne lr
	ldr r0, _0600EC48 @ =0xDADADADA
	mov r1, r0
	mov r2, r0
	mov r3, r0
	mov r4, sp
	add r5, sp, #0x800
	ldr ip, [sp, #0x1fc]
_0600EC2C:
	stmdb r5!, {r0, r1, r2, r3}
	cmp r5, r4
	bne _0600EC2C
	str ip, [sp, #0x1fc]
	mov r0, #1
	strb r0, [sp, #0xa30]
	bx lr
	.align 2, 0
_0600EC48: .4byte 0xDADADADA

	arm_func_start sub_0600EC4C
sub_0600EC4C: @ 0x0600EC4C
	mov fp, lr
	ldrb r0, [sp, #0xa30]
	cmp r0, #0
	bne _0600EC80
	mov r0, sp
	ldr r1, _0600EC88 @ =0x0600A010
	add lr, pc, #0x4 @ =_0600EC70
	ldr ip, _0600EC8C @ =0x0203E375
	bx ip
_0600EC70:
	ldr r3, [sp, #0x924]
	ldr r2, [r3, #0xc0]
	ldr r3, _0600EBF4 @ =0x0600A000
	str r2, [r3]
_0600EC80:
	mov lr, fp
	b _0600EBF8
	.align 2, 0
_0600EC88: .4byte 0x0600A010
_0600EC8C: .4byte 0x0203E375

	arm_func_start sub_0600EC90
sub_0600EC90: @ 0x0600EC90
	mov r0, #0x99
	bl sub_06006E08
	mov r1, #1
	strb r1, [sp, #0xa43]
	bl _0600E3D4
	ldr r0, [sp, #0x910]
	ldrb r1, [sp, #0xa43]
	tst r0, #0x30
	eorne r1, r1, #1
	tst r0, #2
	movne r1, #1
	strb r1, [sp, #0xa43]
	tst r1, #1
	moveq r0, #0x1a
	movne r0, #0x1b
	bl sub_06006E08
	ldr r0, [sp, #0x910]
	tst r0, #0xb
	beq _0600E3D8
	ldrb r1, [sp, #0xa43]
	tst r1, #1
	beq _0600ECFC
_0600ECE8:
	strb r0, [sp, #0xa44]
	mov r0, #0x80
	bl sub_06006E08
	ldr lr, _0600ED0C @ =sub_0600E440
	b _0600E3D4
_0600ECFC:
	add lr, pc, #0x0 @ =0x0600ED04
	ldr pc, _0600ED10 @ =sub_0600ED14
	ldr sp, [sp, #0x920]
	ldm sp!, {pc}
	.align 2, 0
_0600ED0C: .4byte sub_0600E440
_0600ED10: .4byte sub_0600ED14

	arm_func_start sub_0600ED14
sub_0600ED14: @ 0x0600ED14
	mov fp, lr
	bl sub_0600EB0C
	movs r0, fp
	movne r0, #0x100
	bl sub_0600EB1C
	bic r2, r2, #0x1800
	strh r2, [r1]
	add r2, r1, #0x208
	mov r0, #0
	strh r0, [r2]
	ldrh r0, [r2, #-8]
	bic r0, r0, #0x78
	strh r0, [r2, #-8]
	ldr r0, _0600ED84 @ =0x84400004
	str r0, [r1, #0xc4]!
	mov r0, #2
	strb r0, [sp, #0xa48]
	mov r0, #1
	strb r0, [sp, #0xa49]
	mov r0, #1
	strh r0, [r2]
	mov r0, #0x440
	strh r0, [r1, #2]
_0600ED70:
	ldrb r0, [sp, #0xa49]
	ldrb r1, [sp, #0xa48]
	cmp r0, r1
	bne _0600ED70
	bx fp
	.align 2, 0
_0600ED84: .4byte 0x84400004
