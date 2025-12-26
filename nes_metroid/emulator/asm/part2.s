    .include "asm/constants.inc"
    .include "asm/macros.inc"

    .syntax unified

	thumb_func_start sub_03000000
sub_03000000: @ 0x03000000
	push {lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r1, _0300001C @ =0x03005FBC
	ldr r0, [r1]
	cmp r0, r2
	beq _03000016
	str r2, [r1]
	ldr r1, _03000020 @ =0x04000104
	rsbs r0, r2, #0
	strh r0, [r1]
_03000016:
	pop {r0}
	bx r0
	.align 2, 0
_0300001C: .4byte 0x03005FBC
_03000020: .4byte 0x04000104

	thumb_func_start sub_03000024
sub_03000024: @ 0x03000024
	push {lr}
	lsls r0, r0, #0x18
	ldr r1, _03000048 @ =_03002330
	lsrs r0, r0, #0x16
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _0300004C @ =0x01000AE0
	bl sub_030022B8
	adds r1, r0, #0
	movs r0, #0x80
	lsls r0, r0, #9
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
	.align 2, 0
_03000048: .4byte _03002330
_0300004C: .4byte 0x01000AE0

	thumb_func_start sub_03000050
sub_03000050: @ 0x03000050
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _03000078 @ =0x01000AE0
	bl sub_03002220
	adds r1, r0, #0
	ldr r0, _0300007C @ =0x0000FFFF
	cmp r1, r0
	bls _03000068
	adds r1, r0, #0
_03000068:
	movs r0, #0x80
	lsls r0, r0, #9
	subs r1, r0, r1
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
	.align 2, 0
_03000078: .4byte 0x01000AE0
_0300007C: .4byte 0x0000FFFF

	thumb_func_start sub_03000080
sub_03000080: @ 0x03000080
	push {lr}
	ldr r1, _030000AC @ =0x040000C4
	ldr r0, _030000B0 @ =0x84400004
	str r0, [r1]
	adds r1, #2
	ldr r0, _030000B4 @ =0x03002370
	ldr r0, [r0]
	strh r0, [r1]
	ldr r0, _030000B8 @ =0x03005A5C
	ldrb r0, [r0]
	cmp r0, #0
	beq _03000180
	ldr r1, _030000BC @ =0x03005A5D
	ldrb r0, [r1]
	cmp r0, #0
	beq _03000170
	adds r1, r0, #0
	cmp r1, #1
	beq _030000C0
	cmp r1, #2
	beq _030000E8
	b _03000184
	.align 2, 0
_030000AC: .4byte 0x040000C4
_030000B0: .4byte 0x84400004
_030000B4: .4byte 0x03002370
_030000B8: .4byte 0x03005A5C
_030000BC: .4byte 0x03005A5D
_030000C0:
	ldr r2, _030000D8 @ =0x03005A5E
	ldrb r0, [r2]
	cmp r0, #0
	bne _03000140
	strb r1, [r2]
	ldr r0, _030000DC @ =0x03005A54
	ldr r0, [r0]
	bl sub_030001C4
	ldr r2, _030000E0 @ =0x03005A64
	ldr r0, _030000E4 @ =0x03005A50
	b _03000150
	.align 2, 0
_030000D8: .4byte 0x03005A5E
_030000DC: .4byte 0x03005A54
_030000E0: .4byte 0x03005A64
_030000E4: .4byte 0x03005A50
_030000E8:
	ldr r2, _030000FC @ =0x03005A5E
	ldrb r0, [r2]
	cmp r0, #1
	beq _03000124
	cmp r0, #1
	bgt _03000100
	cmp r0, #0
	beq _03000106
	b _03000184
	.align 2, 0
_030000FC: .4byte 0x03005A5E
_03000100:
	cmp r0, #2
	beq _03000140
	b _03000184
_03000106:
	movs r0, #1
	strb r0, [r2]
	ldr r0, _03000118 @ =0x03005A54
	ldr r0, [r0]
	bl sub_030001C4
	ldr r2, _0300011C @ =0x03005A64
	ldr r0, _03000120 @ =0x03005A58
	b _03000150
	.align 2, 0
_03000118: .4byte 0x03005A54
_0300011C: .4byte 0x03005A64
_03000120: .4byte 0x03005A58
_03000124:
	strb r1, [r2]
	ldr r0, _03000134 @ =0x03005A58
	ldr r0, [r0]
	bl sub_030001C4
	ldr r2, _03000138 @ =0x03005A64
	ldr r0, _0300013C @ =0x03005A50
	b _03000150
	.align 2, 0
_03000134: .4byte 0x03005A58
_03000138: .4byte 0x03005A64
_0300013C: .4byte 0x03005A50
_03000140:
	movs r0, #0
	strb r0, [r2]
	ldr r0, _03000160 @ =0x03005A50
	ldr r0, [r0]
	bl sub_030001C4
	ldr r2, _03000164 @ =0x03005A64
	ldr r0, _03000168 @ =0x03005A54
_03000150:
	ldr r0, [r0]
	ldr r1, _0300016C @ =0x03005FBC
	ldr r1, [r1]
	ldr r2, [r2]
	bl sub_030021EC
	b _03000184
	.align 2, 0
_03000160: .4byte 0x03005A50
_03000164: .4byte 0x03005A64
_03000168: .4byte 0x03005A54
_0300016C: .4byte 0x03005FBC
_03000170:
	ldr r0, _0300017C @ =0x03005A50
	ldr r0, [r0]
	bl sub_030001C4
	b _03000184
	.align 2, 0
_0300017C: .4byte 0x03005A50
_03000180:
	bl sub_030001B4
_03000184:
	pop {r0}
	bx r0

	thumb_func_start sub_03000188
sub_03000188: @ 0x03000188
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _030001A8 @ =0x04000104
	ldr r1, _030001AC @ =0x03005FBC
	ldr r1, [r1]
	rsbs r1, r1, #0
	strh r1, [r2]
	adds r2, #2
	movs r1, #0xc4
	strh r1, [r2]
	ldr r1, _030001B0 @ =0x04000100
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x80
	strh r0, [r1]
	bx lr
	.align 2, 0
_030001A8: .4byte 0x04000104
_030001AC: .4byte 0x03005FBC
_030001B0: .4byte 0x04000100

	thumb_func_start sub_030001B4
sub_030001B4: @ 0x030001B4
	ldr r0, _030001C0 @ =0x04000102
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	bx lr
	.align 2, 0
_030001C0: .4byte 0x04000102

	thumb_func_start sub_030001C4
sub_030001C4: @ 0x030001C4
	ldr r1, _030001EC @ =0x040000BC
	strh r0, [r1]
	adds r1, #2
	lsrs r0, r0, #0x10
	strh r0, [r1]
	adds r1, #2
	movs r0, #0xa0
	strh r0, [r1]
	adds r1, #2
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #4
	movs r2, #0xb2
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r1]
	bx lr
	.align 2, 0
_030001EC: .4byte 0x040000BC

	thumb_func_start sub_030001F0
sub_030001F0: @ 0x030001F0
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r4, _03000224 @ =0x04000082
	ldr r6, _03000228 @ =0x00000B06
	adds r1, r6, #0
	strh r1, [r4]
	ldr r1, _0300022C @ =0x03005FBC
	str r2, [r1]
	ldr r1, _03000230 @ =0x03005A5C
	strb r3, [r1]
	ldr r1, _03000234 @ =0x03005A50
	str r0, [r1]
	ldr r2, _03000238 @ =0x03005A5D
	movs r1, #0
	strb r1, [r2]
	bl sub_030001C4
	adds r0, r5, #0
	bl sub_03000188
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_03000224: .4byte 0x04000082
_03000228: .4byte 0x00000B06
_0300022C: .4byte 0x03005FBC
_03000230: .4byte 0x03005A5C
_03000234: .4byte 0x03005A50
_03000238: .4byte 0x03005A5D

	thumb_func_start sub_0300023C
sub_0300023C: @ 0x0300023C
	push {r4, r5, r6, r7, lr}
	adds r5, r2, #0
	ldr r6, [sp, #0x14]
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r4, _03000280 @ =0x04000082
	ldr r7, _03000284 @ =0x00000B06
	adds r2, r7, #0
	strh r2, [r4]
	ldr r2, _03000288 @ =0x03005FBC
	str r3, [r2]
	ldr r2, _0300028C @ =0x03005A5C
	movs r3, #1
	strb r3, [r2]
	ldr r2, _03000290 @ =0x03005A50
	str r0, [r2]
	ldr r2, _03000294 @ =0x03005A54
	str r1, [r2]
	ldr r1, _03000298 @ =0x03005A5D
	strb r3, [r1]
	ldr r2, _0300029C @ =0x03005A5E
	movs r1, #0
	strb r1, [r2]
	ldr r1, _030002A0 @ =0x03005A64
	str r6, [r1]
	bl sub_030001C4
	adds r0, r5, #0
	bl sub_03000188
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_03000280: .4byte 0x04000082
_03000284: .4byte 0x00000B06
_03000288: .4byte 0x03005FBC
_0300028C: .4byte 0x03005A5C
_03000290: .4byte 0x03005A50
_03000294: .4byte 0x03005A54
_03000298: .4byte 0x03005A5D
_0300029C: .4byte 0x03005A5E
_030002A0: .4byte 0x03005A64

	thumb_func_start sub_030002A4
sub_030002A4: @ 0x030002A4
	push {r4, r5, r6, r7, lr}
	adds r5, r3, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r4, _03000304 @ =0x04000084
	movs r3, #0x80
	strh r3, [r4]
	ldr r3, _03000308 @ =0x04000080
	movs r6, #0
	strh r6, [r3]
	subs r4, #2
	movs r7, #0xb0
	lsls r7, r7, #4
	adds r3, r7, #0
	strh r3, [r4]
	adds r7, #4
	adds r3, r7, #0
	strh r3, [r4]
	ldr r3, _0300030C @ =0x03005FBC
	ldr r4, [sp, #0x14]
	str r4, [r3]
	ldr r4, _03000310 @ =0x03005A5C
	movs r3, #1
	strb r3, [r4]
	ldr r3, _03000314 @ =0x03005A50
	str r0, [r3]
	ldr r3, _03000318 @ =0x03005A54
	str r1, [r3]
	ldr r1, _0300031C @ =0x03005A58
	str r2, [r1]
	ldr r2, _03000320 @ =0x03005A5D
	movs r1, #2
	strb r1, [r2]
	ldr r1, _03000324 @ =0x03005A5E
	strb r6, [r1]
	ldr r1, _03000328 @ =0x03005A60
	strh r5, [r1]
	ldr r1, _0300032C @ =0x03005A64
	ldr r7, [sp, #0x18]
	str r7, [r1]
	bl sub_030001C4
	adds r0, r5, #0
	bl sub_03000188
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_03000304: .4byte 0x04000084
_03000308: .4byte 0x04000080
_0300030C: .4byte 0x03005FBC
_03000310: .4byte 0x03005A5C
_03000314: .4byte 0x03005A50
_03000318: .4byte 0x03005A54
_0300031C: .4byte 0x03005A58
_03000320: .4byte 0x03005A5D
_03000324: .4byte 0x03005A5E
_03000328: .4byte 0x03005A60
_0300032C: .4byte 0x03005A64

	thumb_func_start sub_03000330
sub_03000330: @ 0x03000330
	push {lr}
	bl sub_030001B4
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_0300033C
sub_0300033C: @ 0x0300033C
	ldr r1, _03000344 @ =0x03005FB4
	str r0, [r1]
	bx lr
	.align 2, 0
_03000344: .4byte 0x03005FB4

	thumb_func_start sub_03000348
sub_03000348: @ 0x03000348
	ldr r1, _03000350 @ =0x03005FC8
	str r0, [r1]
	bx lr
	.align 2, 0
_03000350: .4byte 0x03005FC8

	thumb_func_start sub_03000354
sub_03000354: @ 0x03000354
	push {r4, lr}
	adds r4, r1, #0
	bl sub_0300033C
	adds r0, r4, #0
	bl sub_03000348
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start sub_03000368
sub_03000368: @ 0x03000368
	ldr r1, _03000378 @ =0x03005FB4
	str r0, [r1]
	ldr r1, _0300037C @ =0x03005FC8
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r0, r2
	str r0, [r1]
	bx lr
	.align 2, 0
_03000378: .4byte 0x03005FB4
_0300037C: .4byte 0x03005FC8

	thumb_func_start sub_03000380
sub_03000380: @ 0x03000380
	push {r4, r5, lr}
	sub sp, #0xc
	lsls r0, r0, #0x10
	movs r3, #0
	ldr r1, _030003BC @ =0x40150000
	cmp r0, r1
	bne _030003F8
	mov r1, sp
	ldr r0, _030003C0 @ =0x03005FCC
	ldrb r0, [r0]
	strh r0, [r1]
	ldr r0, _030003C4 @ =0x03005FD8
	ldrb r0, [r0]
	strh r0, [r1, #2]
	ldr r0, _030003C8 @ =0x03005FB0
	ldrh r0, [r0]
	strh r0, [r1, #4]
	ldr r0, _030003CC @ =0x03005FC0
	ldrb r0, [r0]
	strh r0, [r1, #6]
	movs r4, #0
	ldr r5, _030003D0 @ =0x03005A68
_030003AC:
	lsls r2, r4, #1
	adds r1, r2, r5
	ldrh r0, [r1]
	cmp r0, #0
	beq _030003D4
	subs r0, #1
	b _030003DA
	.align 2, 0
_030003BC: .4byte 0x40150000
_030003C0: .4byte 0x03005FCC
_030003C4: .4byte 0x03005FD8
_030003C8: .4byte 0x03005FB0
_030003CC: .4byte 0x03005FC0
_030003D0: .4byte 0x03005A68
_030003D4:
	mov r1, sp
	adds r0, r1, r2
	ldrh r0, [r0]
_030003DA:
	lsls r0, r4
	orrs r3, r0
	lsls r0, r3, #0x18
	lsrs r3, r0, #0x18
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _030003AC
	mov r0, sp
	ldrb r0, [r0, #8]
	lsls r0, r0, #4
	orrs r3, r0
	lsls r0, r3, #0x18
	lsrs r3, r0, #0x18
_030003F8:
	adds r0, r3, #0
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_03000404
sub_03000404: @ 0x03000404
	bx lr
	.align 2, 0

	thumb_func_start sub_03000408
sub_03000408: @ 0x03000408
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _0300046C @ =0x03002374
	ldrb r0, [r0]
	cmp r0, #0
	bne _03000466
	ldr r1, _03000470 @ =0xFFFFC000
	adds r0, r5, r1
	lsls r6, r0, #0x10
	lsrs r5, r6, #0x10
	cmp r5, #0x17
	bhi _03000448
	ldr r1, _03000474 @ =0x03002378
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl sub_030021E8
	movs r0, #3
	ands r0, r5
	cmp r0, #3
	bne _03000448
	ldr r0, _03000478 @ =0x03005A68
	lsrs r1, r6, #0x12
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r0, #2
	strh r0, [r1]
_03000448:
	cmp r5, #0x15
	bne _03000466
	movs r2, #0
	movs r3, #1
	ldr r1, _03000478 @ =0x03005A68
_03000452:
	adds r0, r4, #0
	ands r0, r3
	cmp r0, #0
	beq _0300045C
	strh r3, [r1]
_0300045C:
	lsrs r4, r4, #1
	adds r1, #2
	adds r2, #1
	cmp r2, #3
	bls _03000452
_03000466:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0300046C: .4byte 0x03002374
_03000470: .4byte 0xFFFFC000
_03000474: .4byte 0x03002378
_03000478: .4byte 0x03005A68

	thumb_func_start sub_0300047C
sub_0300047C: @ 0x0300047C
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	strb r1, [r0]
	bx lr

	thumb_func_start sub_03000484
sub_03000484: @ 0x03000484
	ldrb r0, [r0]
	bx lr

	thumb_func_start sub_03000488
sub_03000488: @ 0x03000488
	push {lr}
	ldr r1, _030004C8 @ =0x03002374
	movs r0, #0
	strb r0, [r1]
	bl sub_03000564
	ldr r0, _030004CC @ =0x04000084
	movs r1, #0xff
	bl sub_0300047C
	ldr r0, _030004D0 @ =0x04000080
	movs r1, #0x77
	bl sub_0300047C
	ldr r0, _030004D4 @ =0x04000081
	movs r1, #0xff
	bl sub_0300047C
	ldr r2, _030004D8 @ =0x04000088
	ldrh r1, [r2]
	ldr r0, _030004DC @ =0x000003FF
	ands r0, r1
	movs r3, #0x80
	lsls r3, r3, #7
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	bl sub_0300203C
	pop {r0}
	bx r0
	.align 2, 0
_030004C8: .4byte 0x03002374
_030004CC: .4byte 0x04000084
_030004D0: .4byte 0x04000080
_030004D4: .4byte 0x04000081
_030004D8: .4byte 0x04000088
_030004DC: .4byte 0x000003FF

	thumb_func_start sub_030004E0
sub_030004E0: @ 0x030004E0
	push {lr}
	bl sub_03000080
	movs r1, #0
	movs r2, #0
	ldr r0, _030004FC @ =0x03005A68
_030004EC:
	strh r2, [r0]
	adds r0, #2
	adds r1, #1
	cmp r1, #4
	bls _030004EC
	pop {r0}
	bx r0
	.align 2, 0
_030004FC: .4byte 0x03005A68

	thumb_func_start sub_03000500
sub_03000500: @ 0x03000500
	push {lr}
	ldr r0, _03000528 @ =0x00004015
	movs r1, #0
	bl sub_03000408
	ldr r1, _0300052C @ =0x03002374
	movs r0, #1
	strb r0, [r1]
	bl sub_03000330
	ldr r1, _03000530 @ =0x040000C4
	ldr r0, _03000534 @ =0x84400004
	str r0, [r1]
	adds r1, #2
	ldr r0, _03000538 @ =0x030023D8
	ldr r0, [r0]
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_03000528: .4byte 0x00004015
_0300052C: .4byte 0x03002374
_03000530: .4byte 0x040000C4
_03000534: .4byte 0x84400004
_03000538: .4byte 0x030023D8

	thumb_func_start sub_0300053C
sub_0300053C: @ 0x0300053C
	push {r4, lr}
	ldr r0, _0300055C @ =0x040000A0
	movs r4, #0
	str r4, [r0]
	adds r0, #4
	str r4, [r0]
	bl sub_0300203C
	bl sub_03000564
	ldr r0, _03000560 @ =0x03002374
	strb r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0300055C: .4byte 0x040000A0
_03000560: .4byte 0x03002374

	thumb_func_start sub_03000564
sub_03000564: @ 0x03000564
	push {lr}
	movs r1, #0
	movs r2, #0
	ldr r0, _0300058C @ =0x03005A68
_0300056C:
	strh r2, [r0]
	adds r0, #2
	adds r1, #1
	cmp r1, #4
	bls _0300056C
	bl sub_030009DC
	bl sub_03000F7C
	bl sub_03001594
	bl sub_03001990
	pop {r0}
	bx r0
	.align 2, 0
_0300058C: .4byte 0x03005A68

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
	ldr r0, _0300081C @ =0x03005FCC
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
_0300081C: .4byte 0x03005FCC
_03000820: .4byte 0x03005AA4

	thumb_func_start sub_03000824
sub_03000824: @ 0x03000824
	push {lr}
	ldr r0, _03000840 @ =0x03005FCC
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
_03000840: .4byte 0x03005FCC
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
	bl sub_030022B8
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
	ldr r0, _03000910 @ =0x03005FCC
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
_03000910: .4byte 0x03005FCC
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
	ldr r0, _030009D8 @ =0x03005FCC
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
_030009D8: .4byte 0x03005FCC

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
	ldr r1, _03000A50 @ =0x03005FCC
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
_03000A50: .4byte 0x03005FCC
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
	ldr r0, _03000D98 @ =0x03005FD8
	ldrh r0, [r0]
	cmp r0, #0
	beq _03000DA0
	ldr r1, _03000D9C @ =0x03005ACA
	movs r0, #1
	b _03000DA4
	.align 2, 0
_03000D90: .4byte 0x03005AB4
_03000D94: .4byte 0x03005AC2
_03000D98: .4byte 0x03005FD8
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
	ldr r1, _03000DE4 @ =0x03005FD8
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
_03000DE4: .4byte 0x03005FD8
_03000DE8: .4byte 0x03005AC4

	thumb_func_start sub_03000DEC
sub_03000DEC: @ 0x03000DEC
	push {lr}
	ldr r0, _03000E08 @ =0x03005FD8
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
_03000E08: .4byte 0x03005FD8
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
	bl sub_030022B8
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
	ldr r0, _03000F08 @ =0x03005FD8
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
_03000F08: .4byte 0x03005FD8
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
	ldr r0, _03000F78 @ =0x03005FD8
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
_03000F78: .4byte 0x03005FD8

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
	ldr r1, _03000FF0 @ =0x03005FD8
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
_03000FF0: .4byte 0x03005FD8
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

	thumb_func_start sub_03001318
sub_03001318: @ 0x03001318
	push {lr}
	ldr r0, _0300132C @ =0x03005FB0
	ldrh r1, [r0]
	cmp r1, #0
	bne _03001326
	ldr r0, _03001330 @ =0x03005AD0
	str r1, [r0]
_03001326:
	pop {r0}
	bx r0
	.align 2, 0
_0300132C: .4byte 0x03005FB0
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
	ldr r4, _030013B4 @ =0x03005FB0
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
_030013B4: .4byte 0x03005FB0
_030013B8: .4byte 0x03005AD8
_030013BC: .4byte 0x03005AD6
_030013C0: .4byte 0x03005ADA
_030013C4: .4byte 0x03005ADC

	thumb_func_start sub_030013C8
sub_030013C8: @ 0x030013C8
	push {lr}
	ldr r0, _030013E4 @ =0x03005FB0
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
_030013E4: .4byte 0x03005FB0
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
	bl sub_030022B8
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
	ldr r0, _030014C0 @ =0x03005FB0
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
_030014C0: .4byte 0x03005FB0
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
	ldr r0, _03001554 @ =0x03005FB0
	ldrh r0, [r0]
	cmp r0, #0
	bne _03001558
	bl sub_03001340
	b _0300157C
	.align 2, 0
_03001548: .4byte 0x03005AE2
_0300154C: .4byte 0x03005AE4
_03001550: .4byte 0x03005AE0
_03001554: .4byte 0x03005FB0
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
	ldr r0, _030015E4 @ =0x03005FB0
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
_030015E4: .4byte 0x03005FB0
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
	ldr r1, _030017C4 @ =0x03005FC0
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
_030017C4: .4byte 0x03005FC0
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
	ldr r0, _0300185C @ =0x03005FC0
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
_0300185C: .4byte 0x03005FC0
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
	ldr r0, _030018D8 @ =0x03005FC0
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
_030018D8: .4byte 0x03005FC0
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
	ldr r0, _03001A08 @ =0x03005FC0
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
_03001A08: .4byte 0x03005FC0
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
	ldr r0, _03001EAC @ =0x03005FCC
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
	ldr r0, _03001EAC @ =0x03005FCC
	strh r1, [r0]
	ldr r0, _03001ECC @ =0x03005AA6
	ldrh r0, [r0]
	cmp r0, #0
	beq _03001E00
	bl sub_03000790
_03001E00:
	ldr r0, _03001ED0 @ =0x03005FD8
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
	ldr r0, _03001ED0 @ =0x03005FD8
	strh r1, [r0]
	ldr r0, _03001EF0 @ =0x03005AC6
	ldrh r0, [r0]
	cmp r0, #0
	beq _03001E86
	bl sub_03000D38
_03001E86:
	ldr r0, _03001EF4 @ =0x03005FB0
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
_03001EAC: .4byte 0x03005FCC
_03001EB0: .4byte 0x03005AAD
_03001EB4: .4byte 0x03005A94
_03001EB8: .4byte 0x03005A9A
_03001EBC: .4byte 0x03005AA0
_03001EC0: .4byte 0x03005AA8
_03001EC4: .4byte 0x03005A98
_03001EC8: .4byte 0x03005AA4
_03001ECC: .4byte 0x03005AA6
_03001ED0: .4byte 0x03005FD8
_03001ED4: .4byte 0x03005ACD
_03001ED8: .4byte 0x03005AB4
_03001EDC: .4byte 0x03005ABA
_03001EE0: .4byte 0x03005AC0
_03001EE4: .4byte 0x03005AC8
_03001EE8: .4byte 0x03005AB8
_03001EEC: .4byte 0x03005AC4
_03001EF0: .4byte 0x03005AC6
_03001EF4: .4byte 0x03005FB0
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
	ldr r0, _03001FF0 @ =0x03005FB0
	strh r1, [r0]
_03001F80:
	ldr r0, _03001FF4 @ =0x03005FC0
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
	ldr r0, _03001FF4 @ =0x03005FC0
	strh r1, [r0]
	b _03002016
	.align 2, 0
_03001FE4: .4byte 0x03005ADE
_03001FE8: .4byte 0x03005AD8
_03001FEC: .4byte 0x03005ADA
_03001FF0: .4byte 0x03005FB0
_03001FF4: .4byte 0x03005FC0
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

	thumb_func_start sub_030021E4
sub_030021E4: @ 0x030021E4
	bx r0
	nop

	thumb_func_start sub_030021E8
sub_030021E8: @ 0x030021E8
	bx r1
	nop

	thumb_func_start sub_030021EC
sub_030021EC: @ 0x030021EC
	bx r2
	nop

	thumb_func_start sub_030021F0
sub_030021F0: @ 0x030021F0
	bx r3
	nop

	thumb_func_start sub_030021F4
sub_030021F4: @ 0x030021F4
	bx r4
	nop

	thumb_func_start sub_030021F8
sub_030021F8: @ 0x030021F8
	bx r5
	nop

	thumb_func_start sub_030021FC
sub_030021FC: @ 0x030021FC
	bx r6
	nop

	thumb_func_start sub_03002200
sub_03002200: @ 0x03002200
	bx r7
	nop

	thumb_func_start sub_03002204
sub_03002204: @ 0x03002204
	bx r8
	nop

	thumb_func_start sub_03002208
sub_03002208: @ 0x03002208
	bx sb
	nop

	thumb_func_start sub_0300220C
sub_0300220C: @ 0x0300220C
	bx sl
	nop

	thumb_func_start sub_03002210
sub_03002210: @ 0x03002210
	bx fp
	nop

	thumb_func_start sub_03002214
sub_03002214: @ 0x03002214
	bx ip
	nop

	thumb_func_start sub_03002218
sub_03002218: @ 0x03002218
	bx sp
	nop

	thumb_func_start sub_0300221C
sub_0300221C: @ 0x0300221C
	bx lr
	nop

	thumb_func_start sub_03002220
sub_03002220: @ 0x03002220
	cmp r1, #0
	beq _030022A8
	push {r4}
	adds r4, r0, #0
	eors r4, r1
	mov ip, r4
	movs r3, #1
	movs r2, #0
	cmp r1, #0
	bpl _03002236
	rsbs r1, r1, #0
_03002236:
	cmp r0, #0
	bpl _0300223C
	rsbs r0, r0, #0
_0300223C:
	cmp r0, r1
	blo _0300229A
	movs r4, #1
	lsls r4, r4, #0x1c
_03002244:
	cmp r1, r4
	bhs _03002252
	cmp r1, r0
	bhs _03002252
	lsls r1, r1, #4
	lsls r3, r3, #4
	b _03002244
_03002252:
	lsls r4, r4, #3
_03002254:
	cmp r1, r4
	bhs _03002262
	cmp r1, r0
	bhs _03002262
	lsls r1, r1, #1
	lsls r3, r3, #1
	b _03002254
_03002262:
	cmp r0, r1
	blo _0300226A
	subs r0, r0, r1
	orrs r2, r3
_0300226A:
	lsrs r4, r1, #1
	cmp r0, r4
	blo _03002276
	subs r0, r0, r4
	lsrs r4, r3, #1
	orrs r2, r4
_03002276:
	lsrs r4, r1, #2
	cmp r0, r4
	blo _03002282
	subs r0, r0, r4
	lsrs r4, r3, #2
	orrs r2, r4
_03002282:
	lsrs r4, r1, #3
	cmp r0, r4
	blo _0300228E
	subs r0, r0, r4
	lsrs r4, r3, #3
	orrs r2, r4
_0300228E:
	cmp r0, #0
	beq _0300229A
	lsrs r3, r3, #4
	beq _0300229A
	lsrs r1, r1, #4
	b _03002262
_0300229A:
	adds r0, r2, #0
	mov r4, ip
	cmp r4, #0
	bpl _030022A4
	rsbs r0, r0, #0
_030022A4:
	pop {r4}
	mov pc, lr
_030022A8:
	push {lr}
	bl sub_030022B4
	movs r0, #0
	pop {pc}
	.align 2, 0

	thumb_func_start sub_030022B4
sub_030022B4: @ 0x030022B4
	mov pc, lr
	.align 2, 0

	thumb_func_start sub_030022B8
sub_030022B8: @ 0x030022B8
	cmp r1, #0
	beq _03002326
	movs r3, #1
	movs r2, #0
	push {r4}
	cmp r0, r1
	blo _03002320
	movs r4, #1
	lsls r4, r4, #0x1c
_030022CA:
	cmp r1, r4
	bhs _030022D8
	cmp r1, r0
	bhs _030022D8
	lsls r1, r1, #4
	lsls r3, r3, #4
	b _030022CA
_030022D8:
	lsls r4, r4, #3
_030022DA:
	cmp r1, r4
	bhs _030022E8
	cmp r1, r0
	bhs _030022E8
	lsls r1, r1, #1
	lsls r3, r3, #1
	b _030022DA
_030022E8:
	cmp r0, r1
	blo _030022F0
	subs r0, r0, r1
	orrs r2, r3
_030022F0:
	lsrs r4, r1, #1
	cmp r0, r4
	blo _030022FC
	subs r0, r0, r4
	lsrs r4, r3, #1
	orrs r2, r4
_030022FC:
	lsrs r4, r1, #2
	cmp r0, r4
	blo _03002308
	subs r0, r0, r4
	lsrs r4, r3, #2
	orrs r2, r4
_03002308:
	lsrs r4, r1, #3
	cmp r0, r4
	blo _03002314
	subs r0, r0, r4
	lsrs r4, r3, #3
	orrs r2, r4
_03002314:
	cmp r0, #0
	beq _03002320
	lsrs r3, r3, #4
	beq _03002320
	lsrs r1, r1, #4
	b _030022E8
_03002320:
	adds r0, r2, #0
	pop {r4}
	mov pc, lr
_03002326:
	push {lr}
	bl sub_030022B4
	movs r0, #0
	pop {pc}
_03002330:
	.byte 0x56, 0x10, 0x00, 0x00, 0x66, 0x12, 0x00, 0x00, 0x90, 0x14, 0x00, 0x00, 0xD9, 0x15, 0x00, 0x00
	.byte 0x72, 0x18, 0x00, 0x00, 0x86, 0x1B, 0x00, 0x00, 0xEF, 0x1E, 0x00, 0x00, 0xAB, 0x20, 0x00, 0x00
	.byte 0xCC, 0x24, 0x00, 0x00, 0xB2, 0x2B, 0x00, 0x00, 0x3C, 0x31, 0x00, 0x00, 0x9F, 0x36, 0x00, 0x00
	.byte 0xF5, 0x41, 0x00, 0x00, 0x68, 0x52, 0x00, 0x00, 0x1A, 0x61, 0x00, 0x00, 0x78, 0x81, 0x00, 0x00
	.byte 0x40, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB5, 0x08, 0x00, 0x03, 0x19, 0x09, 0x00, 0x03
	.byte 0x31, 0x09, 0x00, 0x03, 0xA1, 0x09, 0x00, 0x03, 0xAD, 0x0E, 0x00, 0x03, 0x11, 0x0F, 0x00, 0x03
	.byte 0x29, 0x0F, 0x00, 0x03, 0x41, 0x0F, 0x00, 0x03, 0x59, 0x14, 0x00, 0x03, 0x05, 0x04, 0x00, 0x03
	.byte 0xC9, 0x14, 0x00, 0x03, 0x19, 0x15, 0x00, 0x03, 0x7D, 0x18, 0x00, 0x03, 0x05, 0x04, 0x00, 0x03
	.byte 0xE1, 0x18, 0x00, 0x03, 0x45, 0x19, 0x00, 0x03, 0x05, 0x04, 0x00, 0x03, 0x05, 0x04, 0x00, 0x03
	.byte 0x05, 0x04, 0x00, 0x03, 0x05, 0x04, 0x00, 0x03, 0x05, 0x04, 0x00, 0x03, 0x11, 0x1C, 0x00, 0x03
	.byte 0x05, 0x04, 0x00, 0x03, 0x59, 0x1C, 0x00, 0x03, 0x40, 0x04, 0x00, 0x00, 0x05, 0x7F, 0x0A, 0x01
	.byte 0x13, 0x02, 0x28, 0x03, 0x50, 0x04, 0x1E, 0x05, 0x07, 0x06, 0x0D, 0x07, 0x06, 0x08, 0x0C, 0x09
	.byte 0x18, 0x0A, 0x30, 0x0B, 0x60, 0x0C, 0x24, 0x0D, 0x08, 0x0E, 0x10, 0x0F, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x04, 0x04
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x05, 0x05, 0x05
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x06, 0x06
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x08, 0x08
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x0A, 0x0A, 0x0A
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x0C, 0x0C
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x0E
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x10, 0x10
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x12, 0x12, 0x12
	.byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
	.byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x14, 0x14, 0x14, 0x14
	.byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
	.byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x16, 0x16, 0x16, 0x16
	.byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
	.byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x19, 0x19, 0x19, 0x19
	.byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
	.byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFC, 0x23, 0x00, 0x03
	.byte 0x1C, 0x24, 0x00, 0x03, 0x3C, 0x24, 0x00, 0x03, 0x5C, 0x24, 0x00, 0x03, 0x7C, 0x24, 0x00, 0x03
	.byte 0x9C, 0x24, 0x00, 0x03, 0xBC, 0x24, 0x00, 0x03, 0xDC, 0x24, 0x00, 0x03, 0xFC, 0x24, 0x00, 0x03
	.byte 0x1C, 0x25, 0x00, 0x03, 0x3C, 0x25, 0x00, 0x03, 0x5C, 0x25, 0x00, 0x03, 0x7C, 0x25, 0x00, 0x03
	.byte 0x9C, 0x25, 0x00, 0x03, 0xBC, 0x25, 0x00, 0x03, 0xDC, 0x25, 0x00, 0x03, 0x0E, 0x0F, 0x10, 0x0F
	.byte 0x1F, 0x0F, 0x07, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02
	.byte 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01
	.byte 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE
	.byte 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFD, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03
	.byte 0x03, 0x04, 0x04, 0x04, 0x05, 0x05, 0x05, 0x04, 0x04, 0x04, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02
	.byte 0x02, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFD, 0xFD, 0xFD
	.byte 0xFD, 0xFC, 0xFC, 0xFC, 0xFB, 0xFB, 0xFB, 0xFC, 0xFC, 0xFC, 0xFD, 0xFD, 0xFD, 0xFD, 0xFE, 0xFE
	.byte 0xFE, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x03, 0x03, 0x04, 0x04, 0x05
	.byte 0x05, 0x06, 0x06, 0x07, 0x07, 0x08, 0x07, 0x07, 0x06, 0x06, 0x05, 0x05, 0x04, 0x04, 0x03, 0x03
	.byte 0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFE, 0xFE, 0xFD, 0xFD, 0xFC, 0xFC, 0xFB
	.byte 0xFB, 0xFA, 0xFA, 0xF9, 0xF9, 0xF8, 0xF9, 0xF9, 0xFA, 0xFA, 0xFB, 0xFB, 0xFC, 0xFC, 0xFD, 0xFD
	.byte 0xFE, 0xFE, 0xFF, 0xFF, 0x00, 0x00, 0x01, 0x01, 0x02, 0x03, 0x03, 0x04, 0x04, 0x05, 0x06, 0x06
	.byte 0x07, 0x08, 0x08, 0x09, 0x09, 0x0A, 0x09, 0x09, 0x08, 0x08, 0x07, 0x06, 0x06, 0x05, 0x04, 0x04
	.byte 0x03, 0x03, 0x02, 0x01, 0x01, 0x00, 0xFF, 0xFF, 0xFE, 0xFD, 0xFD, 0xFC, 0xFC, 0xFB, 0xFA, 0xFA
	.byte 0xF9, 0xF8, 0xF8, 0xF7, 0xF7, 0xF6, 0xF7, 0xF7, 0xF8, 0xF8, 0xF9, 0xFA, 0xFA, 0xFB, 0xFC, 0xFC
	.byte 0xFD, 0xFD, 0xFE, 0xFF, 0xFF, 0x00, 0x01, 0x02, 0x02, 0x03, 0x04, 0x05, 0x05, 0x06, 0x07, 0x08
	.byte 0x09, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x09, 0x08, 0x07, 0x06, 0x05, 0x05
	.byte 0x04, 0x03, 0x02, 0x02, 0x01, 0x00, 0xFF, 0xFE, 0xFE, 0xFD, 0xFC, 0xFB, 0xFB, 0xFA, 0xF9, 0xF8
	.byte 0xF7, 0xF7, 0xF6, 0xF5, 0xF4, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFB
	.byte 0xFC, 0xFD, 0xFE, 0xFE, 0xFF, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x08, 0x09
	.byte 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x08, 0x07, 0x06
	.byte 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0xFF, 0xFE, 0xFD, 0xFC, 0xFB, 0xFA, 0xF9, 0xF8, 0xF8, 0xF7
	.byte 0xF6, 0xF5, 0xF4, 0xF3, 0xF2, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF8, 0xF9, 0xFA
	.byte 0xFB, 0xFC, 0xFD, 0xFE, 0xFF, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x07, 0x08, 0x09, 0x0A, 0x0B
	.byte 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x12, 0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08, 0x07
	.byte 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0xFF, 0xFE, 0xFD, 0xFC, 0xFB, 0xF9, 0xF8, 0xF7, 0xF6, 0xF5
	.byte 0xF4, 0xF3, 0xF2, 0xF1, 0xF0, 0xEE, 0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9
	.byte 0xFB, 0xFC, 0xFD, 0xFE, 0xFF, 0x00, 0x01, 0x03, 0x04, 0x05, 0x06, 0x08, 0x09, 0x0A, 0x0B, 0x0D
	.byte 0x0E, 0x0F, 0x10, 0x12, 0x13, 0x14, 0x13, 0x12, 0x10, 0x0F, 0x0E, 0x0D, 0x0B, 0x0A, 0x09, 0x08
	.byte 0x06, 0x05, 0x04, 0x03, 0x01, 0x00, 0xFF, 0xFD, 0xFC, 0xFB, 0xFA, 0xF8, 0xF7, 0xF6, 0xF5, 0xF3
	.byte 0xF2, 0xF1, 0xF0, 0xEE, 0xED, 0xEC, 0xED, 0xEE, 0xF0, 0xF1, 0xF2, 0xF3, 0xF5, 0xF6, 0xF7, 0xF8
	.byte 0xFA, 0xFB, 0xFC, 0xFD, 0xFF, 0x00, 0x00, 0x80, 0x00, 0x01, 0x01, 0x02, 0x02, 0x03, 0x03, 0x04
	.byte 0x04, 0x05, 0x05, 0x06, 0x06, 0x07, 0x07, 0x08, 0x00, 0x01, 0x01, 0x02, 0x02, 0x03, 0x03, 0x04
	.byte 0x04, 0x05, 0x05, 0x06, 0x06, 0x07, 0x07, 0x08, 0x00, 0x01, 0x01, 0x02, 0x02, 0x03, 0x03, 0x04
	.byte 0x04, 0x05, 0x05, 0x06, 0x06, 0x07, 0x07, 0x08, 0x00, 0x01, 0x01, 0x02, 0x02, 0x03, 0x03, 0x04
	.byte 0x04, 0x05, 0x05, 0x06, 0x06, 0x07, 0x07, 0x08, 0x00, 0x00, 0x01, 0x01, 0x01, 0x02, 0x02, 0x03
	.byte 0x03, 0x03, 0x04, 0x04, 0x04, 0x05, 0x05, 0x06, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x02
	.byte 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01
	.byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF
	.byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF
	.byte 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFD, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE
	.byte 0xFE, 0xFE, 0xFE, 0xFD, 0xFD, 0xFD, 0xFD, 0xFC, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE
	.byte 0xFE, 0xFD, 0xFD, 0xFD, 0xFC, 0xFC, 0xFC, 0xFB, 0x00, 0xFF, 0xFF, 0xFE, 0xFE, 0xFD, 0xFD, 0xFC
	.byte 0xFC, 0xFB, 0xFB, 0xFA, 0xFA, 0xF9, 0xF9, 0xF8, 0x00, 0xFF, 0xFE, 0xFD, 0xFC, 0xFB, 0xFA, 0xF9
	.byte 0xF8, 0xF7, 0xF6, 0xF5, 0xF4, 0xF3, 0xF2, 0xF1, 0x00, 0xFF, 0xFE, 0xFD, 0xFC, 0xFB, 0xFA, 0xF9
	.byte 0xF8, 0xF7, 0xF6, 0xF5, 0xF4, 0xF3, 0xF2, 0xF1, 0x48, 0x28, 0x00, 0x03, 0x58, 0x28, 0x00, 0x03
	.byte 0x68, 0x28, 0x00, 0x03, 0x78, 0x28, 0x00, 0x03, 0x88, 0x28, 0x00, 0x03, 0x98, 0x28, 0x00, 0x03
	.byte 0xA8, 0x28, 0x00, 0x03, 0xB8, 0x28, 0x00, 0x03, 0xC8, 0x28, 0x00, 0x03, 0xD8, 0x28, 0x00, 0x03
	.byte 0xE8, 0x28, 0x00, 0x03, 0xF8, 0x28, 0x00, 0x03, 0x08, 0x29, 0x00, 0x03, 0x18, 0x29, 0x00, 0x03
	.byte 0x28, 0x29, 0x00, 0x03, 0x38, 0x29, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x50, 0x52, 0x00, 0x03
	.byte 0x38, 0x2E, 0x00, 0x03, 0x38, 0x2E, 0x00, 0x03, 0x38, 0x2E, 0x00, 0x03, 0x38, 0x2E, 0x00, 0x03
	.byte 0x2C, 0x2E, 0x00, 0x03, 0xFC, 0x2E, 0x00, 0x03, 0x44, 0x2E, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0xB0, 0x00, 0x06, 0x44, 0x58, 0x00, 0x03, 0x44, 0x58, 0x00, 0x03, 0x44, 0x58, 0x00, 0x03
	.byte 0x44, 0x58, 0x00, 0x03, 0x44, 0x30, 0x00, 0x03, 0xA4, 0x33, 0x00, 0x03, 0x5C, 0x30, 0x00, 0x03
	.byte 0xB0, 0x4F, 0x00, 0x03, 0xD8, 0x41, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x2C, 0x51, 0x00, 0x03, 0x34, 0x42, 0x00, 0x03, 0xB4, 0x48, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0xC0, 0x4F, 0x00, 0x03, 0x18, 0x42, 0x00, 0x03, 0x98, 0x48, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x2C, 0x51, 0x00, 0x03, 0x7C, 0x42, 0x00, 0x03, 0xD8, 0x48, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x2C, 0x4D, 0x00, 0x03, 0x20, 0x43, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x2C, 0x51, 0x00, 0x03, 0x54, 0x42, 0x00, 0x03, 0x7C, 0x49, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0xC0, 0x39, 0x00, 0x03, 0xE8, 0x42, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x2C, 0x51, 0x00, 0x03, 0xB0, 0x42, 0x00, 0x03, 0x28, 0x49, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x40, 0x4E, 0x00, 0x03, 0xF4, 0x43, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0xE0, 0x44, 0x00, 0x03, 0x78, 0x43, 0x00, 0x03, 0xD8, 0x4A, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0xF0, 0x4F, 0x00, 0x03, 0x5C, 0x43, 0x00, 0x03, 0xB8, 0x4A, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x14, 0x45, 0x00, 0x03, 0xC0, 0x43, 0x00, 0x03, 0x30, 0x4B, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x60, 0x4D, 0x00, 0x03, 0xA4, 0x44, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x2C, 0x51, 0x00, 0x03, 0x98, 0x43, 0x00, 0x03, 0x00, 0x4B, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0xC0, 0x39, 0x00, 0x03, 0x6C, 0x44, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x2C, 0x51, 0x00, 0x03, 0x34, 0x44, 0x00, 0x03, 0x88, 0x4B, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x38, 0x50, 0x00, 0x03, 0x64, 0x46, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x2C, 0x51, 0x00, 0x03, 0x78, 0x45, 0x00, 0x03, 0xC4, 0x49, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x84, 0x4E, 0x00, 0x03, 0x5C, 0x45, 0x00, 0x03, 0xA8, 0x49, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0xF8, 0x4E, 0x00, 0x03, 0xC0, 0x45, 0x00, 0x03, 0x14, 0x4A, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x80, 0x4D, 0x00, 0x03, 0xA4, 0x46, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x2C, 0x51, 0x00, 0x03, 0x98, 0x45, 0x00, 0x03, 0xE8, 0x49, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x9C, 0x50, 0x00, 0x03, 0x2C, 0x46, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x2C, 0x51, 0x00, 0x03, 0xF4, 0x45, 0x00, 0x03, 0x64, 0x4A, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0xC0, 0x4E, 0x00, 0x03, 0x38, 0x3F, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x2C, 0x51, 0x00, 0x03, 0x68, 0x3D, 0x00, 0x03, 0x08, 0x4C, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x9C, 0x4E, 0x00, 0x03, 0x30, 0x3D, 0x00, 0x03, 0xE4, 0x4B, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x24, 0x4F, 0x00, 0x03, 0xE8, 0x3D, 0x00, 0x03, 0x68, 0x4C, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0xA0, 0x4D, 0x00, 0x03, 0xE0, 0x3E, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x2C, 0x51, 0x00, 0x03, 0xA4, 0x3D, 0x00, 0x03, 0x34, 0x4C, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0xC4, 0x50, 0x00, 0x03, 0x8C, 0x3E, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x2C, 0x51, 0x00, 0x03, 0x38, 0x3E, 0x00, 0x03, 0xC8, 0x4C, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x2C, 0x51, 0x00, 0x03, 0x4C, 0x39, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0xDC, 0x37, 0x00, 0x03, 0xAC, 0x37, 0x00, 0x03, 0xC4, 0x37, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x04, 0x3A, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03, 0x34, 0x3A, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0xB4, 0x38, 0x00, 0x03, 0x54, 0x38, 0x00, 0x03, 0x84, 0x38, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0xC0, 0x4D, 0x00, 0x03, 0x88, 0x39, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x34, 0x38, 0x00, 0x03, 0xF4, 0x37, 0x00, 0x03, 0x14, 0x38, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x4C, 0x3A, 0x00, 0x03, 0x18, 0x39, 0x00, 0x03, 0xD8, 0x50, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x2C, 0x51, 0x00, 0x03, 0xE4, 0x38, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x00, 0x35, 0x00, 0x03, 0x70, 0x37, 0x00, 0x03, 0xE8, 0x34, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x50, 0x35, 0x00, 0x03, 0x18, 0x35, 0x00, 0x03, 0x34, 0x35, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x7C, 0x3A, 0x00, 0x03, 0xD0, 0x34, 0x00, 0x03, 0x64, 0x3A, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x38, 0x36, 0x00, 0x03, 0xD8, 0x35, 0x00, 0x03, 0x08, 0x36, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0xE0, 0x4D, 0x00, 0x03, 0x38, 0x37, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0xB4, 0x35, 0x00, 0x03, 0x6C, 0x35, 0x00, 0x03, 0x90, 0x35, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x08, 0x51, 0x00, 0x03, 0x9C, 0x36, 0x00, 0x03, 0xF0, 0x50, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x04, 0x37, 0x00, 0x03, 0x68, 0x36, 0x00, 0x03, 0xD0, 0x36, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0xD4, 0x3A, 0x00, 0x03, 0xAC, 0x3C, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x3C, 0x3B, 0x00, 0x03, 0xF4, 0x3A, 0x00, 0x03, 0xBC, 0x47, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x1C, 0x3A, 0x00, 0x03, 0x94, 0x3A, 0x00, 0x03, 0xD4, 0x39, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0xFC, 0x3B, 0x00, 0x03, 0x8C, 0x3B, 0x00, 0x03, 0x04, 0x48, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x00, 0x4E, 0x00, 0x03, 0xF0, 0x3C, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x2C, 0x51, 0x00, 0x03, 0x60, 0x3B, 0x00, 0x03, 0xDC, 0x47, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x1C, 0x51, 0x00, 0x03, 0x70, 0x3C, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x2C, 0x51, 0x00, 0x03, 0x34, 0x3C, 0x00, 0x03, 0x4C, 0x48, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0xB4, 0x3A, 0x00, 0x03, 0x94, 0x3F, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x18, 0x3B, 0x00, 0x03, 0x20, 0x40, 0x00, 0x03, 0xE0, 0x46, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0xEC, 0x39, 0x00, 0x03, 0xEC, 0x3F, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0xC4, 0x3B, 0x00, 0x03, 0x98, 0x40, 0x00, 0x03, 0x28, 0x47, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x20, 0x4E, 0x00, 0x03, 0x84, 0x41, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x2C, 0x51, 0x00, 0x03, 0x58, 0x40, 0x00, 0x03, 0x00, 0x47, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x1C, 0x51, 0x00, 0x03, 0x34, 0x41, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03
	.byte 0x2C, 0x51, 0x00, 0x03, 0xE4, 0x40, 0x00, 0x03, 0x70, 0x47, 0x00, 0x03, 0x2C, 0x51, 0x00, 0x03

	arm_func_start sub_03002DF0
sub_03002DF0: @ 0x03002DF0
	eor r8, r8, sb
	mov ip, #0x20
_03002DF8:
	lsrs r8, r8, #1
	eorhs r8, r8, sl
	subs ip, ip, #1
	bne _03002DF8
	bx lr

	arm_func_start sub_03002E0C
sub_03002E0C: @ 0x03002E0C
	ldrb r1, [r5], #1
	ldrb r0, [sp, #0xa33]
	cmp r0, #0
	ldrbne r1, [sp, #0xa32]
	movne r0, #0
	strbne r0, [sp, #0xa32]
	strbne r0, [sp, #0xa33]
	ldr pc, [ip, r1, lsl #2]
	ldr r1, [sp, #0x858]
	ldrb r3, [r0, r1, lsl #8]
	mov pc, lr

	arm_func_start sub_03002E38
sub_03002E38: @ 0x03002E38
	ldr r1, [fp, r2, lsl #2]
	ldrb r3, [r0, r1, lsl #8]
	mov pc, lr

	arm_func_start sub_03002E44
sub_03002E44: @ 0x03002E44
	and r1, r0, #7
	lsr r3, fp, #0x10
	and r3, r3, #0xc0
	cmp r1, #7
	beq _03002E84
	bic fp, fp, #0xe00000
	ldr r1, [sp, #0x9b0]
	cmp r1, r5
	strne r5, [sp, #0x9b0]
	movne pc, lr
_03002E6C:
	ldr r1, [sp, #0x8b4]
	ldrb r2, [sp, #0xa35]
	cmp r1, r2
	movhs pc, lr
_03002E7C:
	bic r4, r4, #0xff000000
	mov pc, lr
_03002E84:
	ldr r1, [sp, #0x8b8]
	cmp r1, #0x3000
	bge _03002EC8
	cmp r1, #0x2000
	blt _03002EE4
	add r2, sp, r1, lsr #10 @ WARNING: disassembler produces wrong instruction here
	ldrb r2, [r2, #0x8a8]
	tst r2, #0xfe
	bne _03002EC8
	bic ip, r1, #0x2c00
	add ip, ip, r2, lsl #10
	lsl ip, ip, #1
	add ip, ip, #0x6000000
	add ip, ip, #0x2000
	ldrh r2, [ip]
	ldrb r3, [sp, #0xa3f]
	strb r2, [sp, #0xa3f]
_03002EC8:
	ldrb r2, [sp, #0x8bc]
	tst r2, #4
	addeq r1, r1, #1
	addne r1, r1, #0x20
	str r1, [sp, #0x8b8]
	add ip, fp, #0x44
	mov pc, lr
_03002EE4:
	add r2, r1, #0x6000000
	add r2, r2, #0x14000
	ldrh r2, [r2, r1]
	ldrb r3, [sp, #0xa3f]
	strb r2, [sp, #0xa3f]
	b _03002EC8

	arm_func_start sub_03002EFC
sub_03002EFC: @ 0x03002EFC
	tst r0, #0x1f00
	bne _03002F2C
	and r2, r0, #0xff
	cmp r2, #0x15
	beq _03002F58
	blo _03002F2C
	cmp r2, #0x17
	blo _03002F68
	beq _03003010
	cmp r2, #0x30
	blo _03002F2C
	bhs _03002F34
_03002F2C:
	lsr r3, r0, #8
	mov pc, lr
_03002F34:
	str r0, [sp, #0x93c]
	str lr, [sp, #0x938]
	add lr, pc, #0x4 @ =_03002F48
	ldr r2, _030031C8 @ =sub_03000380
	bx r2
_03002F48:
	add ip, fp, #0x44
	mov r3, r0
	ldr r0, [sp, #0x93c]
	ldr pc, [sp, #0x938]
_03002F58:
	ldr r3, [sp, #0x908]
	bic r2, r3, #0xc0
	str r2, [sp, #0x908]
	mov pc, lr
_03002F68:
	ldr r2, [sp, #0x828]
	mov r3, #0x40
	orr r3, r3, r2, lsr #31
	ldrb r1, [sp, #0xa3b]
	tst r1, #1
	movne pc, lr
_03002F80:
	lsl r2, r2, #1
	str r2, [sp, #0x828]
	ldr r0, [sp, #0x820]
	tst r0, #0x20000000
	moveq pc, lr
_03002F94:
	ldrb r0, [sp, #0xa34]
	add r0, r0, #1
	strb r0, [sp, #0xa34]
	tst r0, #2
	orrne r3, r3, #4
	mov pc, lr
_03002FAC:
	lsl r1, r0, #0x1c
	add r2, pc, r1, lsr #27
	ldrh r3, [r2, #0x18]
	and r1, r0, #0xf0
	add r2, pc, r1, lsr #3
	ldrh r4, [r2, #0x2c]
	orr r3, r3, r4
	strb r3, [sp, #0x823]
	bx lr
_03002FD0:
	.byte 0x00, 0x00, 0x80, 0x00, 0x40, 0x00, 0xC0, 0x00, 0x20, 0x00, 0xA0, 0x00, 0x60, 0x00, 0xE0, 0x00
	.byte 0x10, 0x00, 0x90, 0x00, 0x50, 0x00, 0xD0, 0x00, 0x30, 0x00, 0xB0, 0x00, 0x70, 0x00, 0xF0, 0x00
	.byte 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x08, 0x00, 0x09, 0x00, 0x0A, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x05, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_03003010:
	ldr r2, [sp, #0x82c]
	mov r3, #0x40
	orr r3, r3, r2, lsr #31
	ldrb r1, [sp, #0xa3b]
	tst r1, #1
	movne pc, lr
_03003028:
	lsl r2, r2, #1
	str r2, [sp, #0x82c]
	mov pc, lr
_03003034:
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003044:
	ldr r2, [sp, #0x858]
	strb r1, [r0, r2, lsl #8]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_0300305C:
	and r0, r0, #7
	ldr pc, [pc, r0, lsl #2]
	andeq r0, r0, r0
_03003068:
	.byte 0x18, 0xB0, 0x00, 0x06, 0x78, 0xB0, 0x00, 0x06
	.byte 0x34, 0x30, 0x00, 0x03, 0x78, 0xB0, 0x00, 0x06, 0x68, 0xB0, 0x00, 0x06, 0x90, 0xB0, 0x00, 0x06
	.byte 0xD4, 0x31, 0x00, 0x03, 0x88, 0x30, 0x00, 0x03
_03003088:
	ldr r0, [sp, #0x8b8]
	cmp r0, #0x3000
	bge _03003348
	cmp r0, #0x2000
	bge _03003220
	add r2, r0, #0x6000000
	add r2, r2, #0x14000
	strh r1, [r2, r0]!
	bic r2, r2, #0x1e
	ldr r1, [sp, #0x9b8]
	cmp r1, r2
	beq _03003260
	str r2, [sp, #0x9b8]
	cmp r1, #0
	beq _03003260
	add lr, sp, #0x900
	add lr, lr, #0xe4
	stm lr, {r0, r3, r4, r5, r6, r7, r8, sb, sl, fp}
	bl sub_030030E8
	add lr, sp, #0x900
	add lr, lr, #0xe4
	ldm lr, {r0, r3, r4, r5, r6, r7, r8, sb, sl, fp}
	add ip, fp, #0x44
	b _03003260

	arm_func_start sub_030030E8
sub_030030E8: @ 0x030030E8
	ldr r3, _030031CC @ =0x06015400
	cmp r1, r3
	blo _03003100
	ldr r3, _030031D0 @ =0x06015540
	cmp r1, r3
	bxlo lr
_03003100:
	ldm r1, {r3, r4, r5, r6, r7, r8, sb, sl}
	sub fp, r1, #0x4000
	mov ip, #0x7c00
	orr ip, ip, #0x6000000
	and r0, r3, #0xff
	ldr r0, [ip, r0, lsl #2]
	and r1, r7, #0xff
	ldr r1, [ip, r1, lsl #2]
	orr r1, r0, r1, lsl #1
	and r3, r3, #0xff0000
	ldr r3, [ip, r3, lsr #14]
	and r7, r7, #0xff0000
	ldr r7, [ip, r7, lsr #14]
	orr r2, r3, r7, lsl #1
	and r0, r4, #0xff
	ldr r0, [ip, r0, lsl #2]
	and r7, r8, #0xff
	ldr r7, [ip, r7, lsl #2]
	orr r3, r0, r7, lsl #1
	and r4, r4, #0xff0000
	ldr r4, [ip, r4, lsr #14]
	and r8, r8, #0xff0000
	ldr r8, [ip, r8, lsr #14]
	orr r4, r4, r8, lsl #1
	and r0, r6, #0xff
	ldr r0, [ip, r0, lsl #2]
	and r7, sl, #0xff
	ldr r7, [ip, r7, lsl #2]
	orr r7, r0, r7, lsl #1
	and r6, r6, #0xff0000
	ldr r6, [ip, r6, lsr #14]
	and sl, sl, #0xff0000
	ldr sl, [ip, sl, lsr #14]
	orr r8, r6, sl, lsl #1
	and r0, r5, #0xff0000
	ldr r0, [ip, r0, lsr #14]
	and r6, sb, #0xff0000
	ldr r6, [ip, r6, lsr #14]
	orr r6, r0, r6, lsl #1
	and r5, r5, #0xff
	ldr r5, [ip, r5, lsl #2]
	and sb, sb, #0xff
	ldr sb, [ip, sb, lsl #2]
	orr r5, r5, sb, lsl #1
	stm fp, {r1, r2, r3, r4, r5, r6, r7, r8}
	tst fp, #0x2000
	subeq fp, fp, #0x10000
	subne fp, fp, #0xe000
	stm fp, {r1, r2, r3, r4, r5, r6, r7, r8}
	bx lr
	.align 2, 0
_030031C8: .4byte sub_03000380
_030031CC: .4byte 0x06015400
_030031D0: .4byte 0x06015540
_030031D4:
	tst fp, #0x200000
	eor fp, fp, #0x200000
	bne _030031F8
	bic r1, r1, #0xc0
	strb r1, [sp, #0x8b9]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030031F8:
	strb r1, [sp, #0x8b8]
	ldr r0, [sp, #0x8b8]
	lsr r2, r0, #2
	and r2, r2, #0x3f8
	orr r2, r2, r0, lsr #12
	str r2, [sp, #0x9c0]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003220:
	add r2, sp, r0, lsr #10 @ WARNING: disassembler produces wrong instruction here
	ldrb r2, [r2, #0x8a8]
	tst r2, #0xfe
	bne _03003260
	bic lr, r0, #0x2c00
	cmp lr, #0x3c0
	add lr, lr, r2, lsl #10
	add r0, lr, #0x6000000
	add r0, r0, #0x2000
	ldrh r0, [lr, r0]!
	and r0, r0, #0x3000
	orr r0, r0, r1
	strh r0, [lr]
	lsr lr, lr, #1
	bge _03003284
_0300325C:
	ldr r0, [sp, #0x8b8]
_03003260:
	ldrb r1, [sp, #0x8bc]
	tst r1, #4
	addeq r0, r0, #1
	addne r0, r0, #0x20
	str r0, [sp, #0x8b8]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003284:
	lsls sl, sl, #1
	and r0, lr, #7
	and lr, lr, #0x38
	lsl lr, lr, #5
	orr lr, lr, r0, lsl #3
	orr lr, lr, r2, lsl #11
	add lr, lr, #0x6000000
	add lr, lr, #0x2000
	orr r1, r1, r1, lsl #16
	mov ip, #0x3000
	orr ip, ip, ip, lsl #16
	ldm lr, {r0, r2}
	and sl, ip, r1, lsl #12
	bic r0, r0, ip
	orr r0, r0, sl
	and sl, ip, r1, lsl #10
	bic r2, r2, ip
	orr r2, r2, sl
	stm lr, {r0, r2}
	add lr, lr, #0x40
	ldm lr, {r0, r2}
	and sl, ip, r1, lsl #12
	bic r0, r0, ip
	orr r0, r0, sl
	and sl, ip, r1, lsl #10
	bic r2, r2, ip
	orr r2, r2, sl
	stm lr, {r0, r2}
	add lr, lr, #0x40
	ldm lr, {r0, r2}
	and sl, ip, r1, lsl #8
	bic r0, r0, ip
	orr r0, r0, sl
	and sl, ip, r1, lsl #6
	bic r2, r2, ip
	orr r2, r2, sl
	stm lr, {r0, r2}
	add lr, lr, #0x40
	ldm lr, {r0, r2}
	and sl, ip, r1, lsl #8
	bic r0, r0, ip
	orr r0, r0, sl
	and sl, ip, r1, lsl #6
	bic r2, r2, ip
	orr r2, r2, sl
	stm lr, {r0, r2}
	rrx sl, sl
	add ip, fp, #0x44
	b _0300325C
_03003348:
	subs r2, r0, #0x3f00
	blt _03003260
	cmp r2, #0x20
	bhs _03003260
	and r1, r1, #0x3f
	lsl r1, r1, #1
	tst r0, #0xf
	beq _03003380
	tst r0, #3
	beq _03003260
	and r2, r0, #0x1f
	add r2, r2, sp
	strb r1, [r2, #0x8c4]
	b _03003260
_03003380:
	strb r1, [sp, #0x8c4]
	strb r1, [sp, #0x8c8]
	strb r1, [sp, #0x8cc]
	strb r1, [sp, #0x8d0]
	strb r1, [sp, #0x8d4]
	strb r1, [sp, #0x8d8]
	strb r1, [sp, #0x8dc]
	strb r1, [sp, #0x8e0]
	b _03003260
_030033A4:
	tst r0, #0x1fc0
	bne _030034A8
	and r2, r0, #0x3f
	cmp r2, #0x20
	bge _030034A8
	subs r2, r2, #0x14
	blt _030034A8
	ldr pc, [pc, r2, lsl #2]
	andeq r0, r0, r0
_030033C8:
	.byte 0xF8, 0x33, 0x00, 0x03, 0xA8, 0x34, 0x00, 0x03
	.byte 0x44, 0x34, 0x00, 0x03, 0x94, 0x34, 0x00, 0x03, 0x34, 0x30, 0x00, 0x03, 0x34, 0x30, 0x00, 0x03
	.byte 0x34, 0x30, 0x00, 0x03, 0x34, 0x30, 0x00, 0x03, 0x34, 0x30, 0x00, 0x03, 0x34, 0x30, 0x00, 0x03
	.byte 0x34, 0x30, 0x00, 0x03, 0x34, 0x30, 0x00, 0x03
_030033F8:
	mov lr, #0x4000000
	add lr, lr, #0xd4
	lsr r0, r1, #0xd
	ldr r0, [fp, r0, lsl #2]
	add r0, r0, r1
	lsl r0, r0, #8
	mov r1, #0x6700
	orr r1, r1, #0x6000000
	mov r2, #-0x7c000000
	orr r2, r2, #0x40
	stm lr, {r0, r1, r2}
	ldr r0, [sp, #0x8b4]
	cmp r0, #0x80
	addlt r0, r0, #4
	str r0, [sp, #0x8b4]
	adds r4, r4, #0x38000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003444:
	strb r1, [sp, #0xa3b]
	tst r1, #1
	beq _03003484
	str r3, [sp, #0x92c]
	str r4, [sp, #0x930]
	mov lr, #0x4000000
	ldr r0, [lr, #0x130]
	mvn r0, r0, lsl #24
	lsr r0, r0, #0x18
	bl _03002FAC
	ldr r3, [sp, #0x92c]
	ldr r4, [sp, #0x930]
	add r0, sp, #0x820
	add r1, r0, #8
	ldm r0!, {r2, lr}
	stm r1!, {r2, lr}
_03003484:
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003494:
	ands r2, r1, #0xc0
	strb r2, [sp, #0xa3c]
	bne _030034A8
	mov r2, #0x40
	str r2, [sp, #0x9d0]
_030034A8:
	str r3, [sp, #0x884]
	ldr r3, [sp, #0x9b4]
	add lr, pc, #0x0 @ =0x030034B8
	bx r3
	ldr r3, [sp, #0x884]
	add ip, fp, #0x44
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030034D0:
	ldrb r3, [r5], #1
	and r7, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030034E8:
	ldrb r3, [r5], #1
	and r8, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003500:
	ldrb r3, [r5], #1
	and sb, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003518:
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	and r7, r3, #0xff
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003534:
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	and r8, r3, #0xff
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003550:
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	and sb, r3, #0xff
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_0300356C:
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003590:
	ldrb r0, [r5], #1
	add r0, r0, sb
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	and r8, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030035B4:
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	and sb, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030035D8:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x030035F4
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003608:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03003624
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	and r8, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003638:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03003654
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	and sb, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003668:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03003688
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_0300369C:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, sb
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x030036BC
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030036D0:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, sb
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x030036F0
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	and r8, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003704:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03003724
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	and sb, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003738:
	ldrb r0, [r5], #1
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	add r0, r0, sb
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x0300375C
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	and r7, r3, #0xff
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003770:
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03003798
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	and r7, r3, #0xff
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030037AC:
	ldrb r0, [r5], #1
	strb r7, [sp, r0]
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030037C4:
	ldrb r0, [r5], #1
	strb r8, [sp, r0]
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030037DC:
	ldrb r0, [r5], #1
	strb sb, [sp, r0]
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030037F4:
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	strb r7, [sp, r0]
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003814:
	ldrb r0, [r5], #1
	add r0, r0, sb
	and r0, r0, #0xff
	strb r8, [sp, r0]
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003834:
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	strb sb, [sp, r0]
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003854:
	add r4, r4, #0x4000000
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	mov r1, r7
	ldrne pc, [ip, -r2, lsl #2]
	strb r1, [sp, r0]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003884:
	add r4, r4, #0x4000000
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	mov r1, r8
	ldrne pc, [ip, -r2, lsl #2]
	strb r1, [sp, r0]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030038B4:
	add r4, r4, #0x4000000
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	mov r1, sb
	ldrne pc, [ip, -r2, lsl #2]
	strb r1, [sp, r0]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030038E4:
	add r4, r4, #0x5000000
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	mov r1, r7
	ldrne pc, [ip, -r2, lsl #2]
	strb r1, [sp, r0]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003918:
	add r4, r4, #0x5000000
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, sb
	lsrs r2, r0, #0xd
	mov r1, r7
	ldrne pc, [ip, -r2, lsl #2]
	strb r1, [sp, r0]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_0300394C:
	add r4, r4, #0x6000000
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	lsrs r2, r0, #0xd
	mov r1, r7
	ldrne pc, [ip, -r2, lsl #2]
	strb r1, [sp, r0]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003988:
	add r4, r4, #0x6000000
	ldrb r0, [r5], #1
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	add r0, r0, sb
	lsrs r2, r0, #0xd
	mov r1, r7
	ldrne pc, [ip, -r2, lsl #2]
	strb r1, [sp, r0]
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030039C0:
	lsl sl, r1, #0x1a
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030039D4:
	sub r3, r8, #1
	and r8, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030039EC:
	add r3, r8, #1
	and r8, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003A04:
	sub r3, sb, #1
	and sb, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003A1C:
	add r3, sb, #1
	and sb, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003A34:
	mov r3, r8
	and r7, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003A4C:
	mov r3, sb
	and r7, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003A64:
	mov r3, r7
	and r8, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003A7C:
	mov r3, r7
	and sb, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003A94:
	ldrb r3, [r5], #1
	subs r3, r7, r3
	rrx sl, sl
	and r3, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003AB4:
	ldrb r3, [r5], #1
	subs r3, r8, r3
	rrx sl, sl
	and r3, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003AD4:
	ldrb r3, [r5], #1
	subs r3, sb, r3
	rrx sl, sl
	and r3, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003AF4:
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	subs r3, r7, r3
	rrx sl, sl
	and r3, r3, #0xff
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003B18:
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	subs r3, r8, r3
	rrx sl, sl
	and r3, r3, #0xff
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003B3C:
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	subs r3, sb, r3
	rrx sl, sl
	and r3, r3, #0xff
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003B60:
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	subs r3, r7, r3
	rrx sl, sl
	and r3, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003B8C:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03003BA8
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	subs r3, r7, r3
	rrx sl, sl
	and r3, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003BC4:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03003BE0
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	subs r3, r8, r3
	rrx sl, sl
	and r3, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003BFC:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03003C18
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	subs r3, sb, r3
	rrx sl, sl
	and r3, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003C34:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03003C54
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	subs r3, r7, r3
	rrx sl, sl
	and r3, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003C70:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, sb
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03003C90
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	subs r3, r7, r3
	rrx sl, sl
	and r3, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003CAC:
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03003CD4
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	subs r3, r7, r3
	rrx sl, sl
	and r3, r3, #0xff
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003CF0:
	ldrb r0, [r5], #1
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	add r0, r0, sb
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03003D14
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	subs r3, r7, r3
	rrx sl, sl
	and r3, r3, #0xff
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003D30:
	ldrb r3, [r5], #1
	lsr sl, sl, #8
	orr r7, sl, r7, lsl #24
	orr r3, sl, r3, lsl #24
	adds r3, r7, r3
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx sl, sl
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003D68:
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	lsr sl, sl, #8
	orr r7, sl, r7, lsl #24
	orr r3, sl, r3, lsl #24
	adds r3, r7, r3
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx sl, sl
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003DA4:
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	lsr sl, sl, #8
	orr r7, sl, r7, lsl #24
	orr r3, sl, r3, lsl #24
	adds r3, r7, r3
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx sl, sl
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003DE8:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03003E04
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	lsr sl, sl, #8
	orr r7, sl, r7, lsl #24
	orr r3, sl, r3, lsl #24
	adds r3, r7, r3
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx sl, sl
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003E38:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03003E58
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	lsr sl, sl, #8
	orr r7, sl, r7, lsl #24
	orr r3, sl, r3, lsl #24
	adds r3, r7, r3
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx sl, sl
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003E8C:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, sb
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03003EAC
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	lsr sl, sl, #8
	orr r7, sl, r7, lsl #24
	orr r3, sl, r3, lsl #24
	adds r3, r7, r3
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx sl, sl
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003EE0:
	ldrb r0, [r5], #1
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	add r0, r0, sb
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03003F04
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	lsr sl, sl, #8
	orr r7, sl, r7, lsl #24
	orr r3, sl, r3, lsl #24
	adds r3, r7, r3
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx sl, sl
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003F38:
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03003F60
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	lsr sl, sl, #8
	orr r7, sl, r7, lsl #24
	orr r3, sl, r3, lsl #24
	adds r3, r7, r3
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx sl, sl
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003F94:
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03003FBC
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	lsls sl, sl, #1
	lsl r7, r7, #0x18
	sbcs r3, r7, r3, lsl #24
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx sl, sl
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03003FEC:
	ldrb r3, [r5], #1
	lsls sl, sl, #1
	lsl r7, r7, #0x18
	sbcs r3, r7, r3, lsl #24
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx sl, sl
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004020:
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	lsls sl, sl, #1
	lsl r7, r7, #0x18
	sbcs r3, r7, r3, lsl #24
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx sl, sl
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004058:
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	lsls sl, sl, #1
	lsl r7, r7, #0x18
	sbcs r3, r7, r3, lsl #24
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx sl, sl
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004098:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x030040B4
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	lsls sl, sl, #1
	lsl r7, r7, #0x18
	sbcs r3, r7, r3, lsl #24
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx sl, sl
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030040E4:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03004104
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	lsls sl, sl, #1
	lsl r7, r7, #0x18
	sbcs r3, r7, r3, lsl #24
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx sl, sl
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004134:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, sb
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03004154
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	lsls sl, sl, #1
	lsl r7, r7, #0x18
	sbcs r3, r7, r3, lsl #24
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx sl, sl
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004184:
	ldrb r0, [r5], #1
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	add r0, r0, sb
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x030041A8
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	lsls sl, sl, #1
	lsl r7, r7, #0x18
	sbcs r3, r7, r3, lsl #24
	bic sp, sp, #0x200000
	orrvs sp, sp, #0x200000
	rrx sl, sl
	lsr r3, r3, #0x18
	and r7, r3, #0xff
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030041D8:
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03004200
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	orr r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004218:
	ldrb r3, [r5], #1
	orr r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004234:
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	orr r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004254:
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	orr r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_0300427C:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03004298
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	orr r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030042B0:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x030042D0
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	orr r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030042E8:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, sb
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03004308
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	orr r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004320:
	ldrb r0, [r5], #1
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	add r0, r0, sb
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03004344
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	orr r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_0300435C:
	ldrb r3, [r5], #1
	and r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004378:
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	and r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004398:
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	and r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030043C0:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x030043DC
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	and r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030043F4:
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x0300441C
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	and r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004434:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03004454
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	and r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_0300446C:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, sb
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x0300448C
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	and r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030044A4:
	ldrb r0, [r5], #1
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	add r0, r0, sb
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x030044C8
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	and r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030044E0:
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	bic sp, sp, #0x200000
	tst r3, #0x40
	orrne sp, sp, #0x200000
	tst r3, r7
	and r3, r3, #0x80
	lsl r3, r3, #2
	orrne r3, r3, #2
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004514:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03004530
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	bic sp, sp, #0x200000
	tst r3, #0x40
	orrne sp, sp, #0x200000
	tst r3, r7
	and r3, r3, #0x80
	lsl r3, r3, #2
	orrne r3, r3, #2
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_0300455C:
	ldrb r3, [r5], #1
	eor r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004578:
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	eor r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004598:
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	eor r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030045C0:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x030045DC
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	eor r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030045F4:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x03004614
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	eor r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_0300462C:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, sb
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x0300464C
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	eor r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004664:
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x0300468C
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	eor r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030046A4:
	ldrb r0, [r5], #1
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	add r0, r0, sb
	lsrs r2, r0, #0xd
	add lr, pc, #0x4 @ =0x030046C8
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [sp, r0]
	eor r3, r7, r3
	and r7, r3, #0xff
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030046E0:
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	add r3, r3, #1
	strb r3, [sp, r0]
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004700:
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	add r3, r3, #1
	strb r3, [sp, r0]
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004728:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	add lr, pc, #0x1C @ =_0300475C
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [r0, sp]!
	add r3, r3, #1
	strb r3, [r0]
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_0300475C:
	add r4, r4, #0x6000000
	add r3, r3, #1
	and r1, r3, #0xff
	lsrs r2, r0, #0xd
	ldr pc, [ip, -r2, lsl #2]
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	add lr, pc, #0x1C @ =_030047A8
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [r0, sp]!
	add r3, r3, #1
	strb r3, [r0]
	adds r4, r4, #0x7000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030047A8:
	add r4, r4, #0x7000000
	add r3, r3, #1
	and r1, r3, #0xff
	lsrs r2, r0, #0xd
	ldr pc, [ip, -r2, lsl #2]
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	sub r3, r3, #1
	strb r3, [sp, r0]
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030047DC:
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	sub r3, r3, #1
	strb r3, [sp, r0]
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004804:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	add lr, pc, #0x1C @ =_03004838
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [r0, sp]!
	sub r3, r3, #1
	strb r3, [r0]
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004838:
	add r4, r4, #0x6000000
	sub r3, r3, #1
	and r1, r3, #0xff
	lsrs r2, r0, #0xd
	ldr pc, [ip, -r2, lsl #2]
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	add lr, pc, #0x1C @ =_03004884
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [r0, sp]!
	sub r3, r3, #1
	strb r3, [r0]
	adds r4, r4, #0x7000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004884:
	add r4, r4, #0x7000000
	sub r3, r3, #1
	and r1, r3, #0xff
	lsrs r2, r0, #0xd
	ldr pc, [ip, -r2, lsl #2]
	lsl r3, r7, #1
	lsl sl, r3, #0x17
	and r7, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030048B4:
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	lsl r3, r3, #1
	lsl sl, r3, #0x17
	strb r3, [sp, r0]
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030048D8:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	add lr, pc, #0x20 @ =_03004910
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [r0, sp]!
	lsl r3, r3, #1
	lsl sl, r3, #0x17
	strb r3, [r0]
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004910:
	add r4, r4, #0x6000000
	lsl r3, r3, #1
	lsl sl, r3, #0x17
	and r1, r3, #0xff
	lsrs r2, r0, #0xd
	ldr pc, [ip, -r2, lsl #2]
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	add lr, pc, #0x20 @ =_03004964
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [r0, sp]!
	lsl r3, r3, #1
	lsl sl, r3, #0x17
	strb r3, [r0]
	adds r4, r4, #0x7000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004964:
	add r4, r4, #0x7000000
	lsl r3, r3, #1
	lsl sl, r3, #0x17
	and r1, r3, #0xff
	lsrs r2, r0, #0xd
	ldr pc, [ip, -r2, lsl #2]
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	lsl r3, r3, #1
	lsl sl, r3, #0x17
	strb r3, [sp, r0]
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030049A8:
	lsr r3, r7, #1
	lsl sl, r7, #0x1f
	and r7, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030049C4:
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	lsl sl, r3, #0x1f
	lsr r3, r3, #1
	strb r3, [sp, r0]
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030049E8:
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	lsl sl, r3, #0x1f
	lsr r3, r3, #1
	strb r3, [sp, r0]
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004A14:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	add lr, pc, #0x20 @ =_03004A4C
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [r0, sp]!
	lsl sl, r3, #0x1f
	lsr r3, r3, #1
	strb r3, [r0]
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004A4C:
	add r4, r4, #0x6000000
	lsl sl, r3, #0x1f
	lsr r3, r3, #1
	and r1, r3, #0xff
	lsrs r2, r0, #0xd
	ldr pc, [ip, -r2, lsl #2]
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	add lr, pc, #0x20 @ =_03004AA0
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [r0, sp]!
	lsl sl, r3, #0x1f
	lsr r3, r3, #1
	strb r3, [r0]
	adds r4, r4, #0x7000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004AA0:
	add r4, r4, #0x7000000
	lsl sl, r3, #0x1f
	lsr r3, r3, #1
	and r1, r3, #0xff
	lsrs r2, r0, #0xd
	ldr pc, [ip, -r2, lsl #2]
	lsl r3, r7, #1
	orr r3, r3, sl, lsr #31
	lsl sl, r3, #0x17
	and r7, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004AD8:
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	lsl r3, r3, #1
	orr r3, r3, sl, lsr #31
	lsl sl, r3, #0x17
	strb r3, [sp, r0]
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004B00:
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	lsl r3, r3, #1
	orr r3, r3, sl, lsr #31
	lsl sl, r3, #0x17
	strb r3, [sp, r0]
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004B30:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	add lr, pc, #0x24 @ =_03004B6C
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [r0, sp]!
	lsl r3, r3, #1
	orr r3, r3, sl, lsr #31
	lsl sl, r3, #0x17
	strb r3, [r0]
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004B6C:
	add r4, r4, #0x6000000
	lsl r3, r3, #1
	orr r3, r3, sl, lsr #31
	lsl sl, r3, #0x17
	and r1, r3, #0xff
	lsrs r2, r0, #0xd
	ldr pc, [ip, -r2, lsl #2]
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	add lr, pc, #0x24 @ =_03004BC8
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [r0, sp]!
	lsl r3, r3, #1
	orr r3, r3, sl, lsr #31
	lsl sl, r3, #0x17
	strb r3, [r0]
	adds r4, r4, #0x7000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004BC8:
	add r4, r4, #0x7000000
	lsl r3, r3, #1
	orr r3, r3, sl, lsr #31
	lsl sl, r3, #0x17
	and r1, r3, #0xff
	lsrs r2, r0, #0xd
	ldr pc, [ip, -r2, lsl #2]
	tst sl, #-0x80000000
	orrne r7, r7, #0x100
	lsl sl, r7, #0x1f
	lsr r3, r7, #1
	and r7, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004C08:
	ldrb r0, [r5], #1
	ldrb r3, [sp, r0]
	tst sl, #-0x80000000
	orrne r3, r3, #0x100
	lsl sl, r3, #0x1f
	lsr r3, r3, #1
	strb r3, [sp, r0]
	adds r4, r4, #0x5000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004C34:
	ldrb r0, [r5], #1
	add r0, r0, r8
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	tst sl, #-0x80000000
	orrne r3, r3, #0x100
	lsl sl, r3, #0x1f
	lsr r3, r3, #1
	strb r3, [sp, r0]
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004C68:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	add lr, pc, #0x28 @ =_03004CA8
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [r0, sp]!
	tst sl, #-0x80000000
	orrne r3, r3, #0x100
	lsl sl, r3, #0x1f
	lsr r3, r3, #1
	strb r3, [r0]
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004CA8:
	add r4, r4, #0x6000000
	tst sl, #-0x80000000
	orrne r3, r3, #0x100
	lsl sl, r3, #0x1f
	lsr r3, r3, #1
	and r1, r3, #0xff
	lsrs r2, r0, #0xd
	ldr pc, [ip, -r2, lsl #2]
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	add r0, r0, r8
	lsrs r2, r0, #0xd
	add lr, pc, #0x28 @ =_03004D0C
	ldrne pc, [fp, -r2, lsl #2]
	ldrb r3, [r0, sp]!
	tst sl, #-0x80000000
	orrne r3, r3, #0x100
	lsl sl, r3, #0x1f
	lsr r3, r3, #1
	strb r3, [r0]
	adds r4, r4, #0x7000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004D0C:
	add r4, r4, #0x7000000
	tst sl, #-0x80000000
	orrne r3, r3, #0x100
	lsl sl, r3, #0x1f
	lsr r3, r3, #1
	and r1, r3, #0xff
	lsrs r2, r0, #0xd
	ldr pc, [ip, -r2, lsl #2]
	tst r3, #0x280
	bne _03004D4C
	ldrsb r0, [r5], #1
	add r5, r5, r0
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004D4C:
	add r5, r5, #1
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004D60:
	tst r3, #0x280
	beq _03004D4C
	ldrsb r0, [r5], #1
	add r5, r5, r0
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004D80:
	tst sp, #0x200000
	bne _03004D4C
	ldrsb r0, [r5], #1
	add r5, r5, r0
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004DA0:
	tst sp, #0x200000
	beq _03004D4C
	ldrsb r0, [r5], #1
	add r5, r5, r0
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004DC0:
	tst sl, #-0x80000000
	bne _03004D4C
	ldrsb r0, [r5], #1
	add r5, r5, r0
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004DE0:
	tst sl, #-0x80000000
	beq _03004D4C
	ldrsb r0, [r5], #1
	add r5, r5, r0
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004E00:
	tst r3, #0xff
	beq _03004D4C
	ldrsb r0, [r5], #1
	add r5, r5, r0
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004E20:
	tst r3, #0xff
	bne _03004D4C
	ldrsb r0, [r5], #1
	add r5, r5, r0
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004E40:
	ldrb r0, [r5], #1
	sub r2, r5, r4, lsl #8
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsr r1, r2, #8
	strb r1, [r6], #-1
	orr r6, r6, #0x100
	strb r2, [r6], #-1
	orr r6, r6, #0x100
	lsr r1, r0, #0xd
	ldr r1, [fp, r1, lsl #2]
	add r5, r0, r1, lsl #8
	and r4, r4, #0xff000000
	adds r4, r4, r1
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004E84:
	strb r7, [r6], #-1
	orr r6, r6, #0x100
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004E9C:
	and r0, r6, #0xff
	cmp r0, #0xff
	subeq r6, r6, #0x100
	ldrb r3, [r6, #1]!
	and r7, r3, #0xff
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004EC0:
	ldrb r0, [r6, #1]!
	ldrb r1, [r6, #1]!
	tst r6, #0x100
	subeq r6, r6, #0x100
	orr r0, r0, r1, lsl #8
	add r0, r0, #1
	lsr r1, r0, #0xd
	ldr r1, [fp, r1, lsl #2]
	add r5, r0, r1, lsl #8
	and r4, r4, #0xff000000
	adds r4, r4, r1
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004EF8:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsr r1, r0, #0xd
	ldr r1, [fp, r1, lsl #2]
	adds r5, r0, r1, lsl #8
	rsc r4, sp, r4, lsr #24
	adds r4, r1, r4, lsl #24
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004F24:
	ldrb r0, [r5], #1
	ldrb r1, [r5], #1
	orr r0, r0, r1, lsl #8
	lsrs r2, r0, #0xd
	bne _03004F64
	ldrb r1, [r0, sp]!
	ldrb r0, [r0, #1]
	orr r0, r1, r0, lsl #8
	lsr r1, r0, #0xd
	ldr r1, [fp, r1, lsl #2]
	adds r5, r0, r1, lsl #8
	rsc r4, sp, r4, lsr #24
	adds r4, r1, r4, lsl #24
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004F64:
	str r3, [sp, #0x884]
	add lr, pc, #0x0 @ =0x03004F70
	ldr pc, [fp, -r2, lsl #2]
	strb r3, [sp, #0xa3e]
	add r0, r0, #1
	lsrs r2, r0, #0xd
	add lr, pc, #0x0 @ =0x03004F84
	ldr pc, [fp, -r2, lsl #2]
	ldrb r0, [sp, #0xa3e]
	orr r0, r0, r3, lsl #8
	ldr r3, [sp, #0x884]
	lsr r1, r0, #0xd
	ldr r1, [fp, r1, lsl #2]
	adds r5, r0, r1, lsl #8
	rsc r4, sp, r4, lsr #24
	adds r4, r1, r4, lsl #24
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004FB0:
	add r5, r5, #1
	mvn r0, #1
	mov lr, #0xa0000
	b _0300516C
_03004FC0:
	lsr r1, sl, #0x1f
	tst r3, #0xff
	orreq r1, r1, #2
	orr r1, r1, sp, lsr #15
	tst r3, #0x280
	orrne r1, r1, #0x80
	strb r1, [r6], #-1
	orr r6, r6, #0x100
	adds r4, r4, #0x3000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03004FF0:
	and r0, r6, #0xff
	cmp r0, #0xff
	subeq r6, r6, #0x100
	ldrb r1, [r6, #1]!
	lsl sl, r1, #0x1f
	and r3, r1, #2
	eor r3, r3, #2
	tst r1, #0x80
	orrne r3, r3, #0x200
	and r1, r1, #0x7c
	bic sp, sp, #0x3e0000
	orr sp, sp, r1, lsl #15
	tst sp, #0x820000
	beq _030050B8
	adds r4, r4, #0x4000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03005038:
	ldrb r0, [r6, #1]!
	lsl sl, r0, #0x1f
	and r3, r0, #2
	eor r3, r3, #2
	tst r0, #0x80
	orrne r3, r3, #0x200
	and r0, r0, #0x7c
	bic sp, sp, #0x3e0000
	orr sp, sp, r0, lsl #15
	ldrb r0, [r6, #1]!
	ldrb r1, [r6, #1]!
	tst r6, #0x100
	subeq r6, r6, #0x100
	orr r0, r0, r1, lsl #8
	lsr r1, r0, #0xd
	ldr r1, [fp, r1, lsl #2]
	add r5, r0, r1, lsl #8
	and r4, r4, #0xff000000
	adds r4, r4, r1
	tst sp, #0x820000
	beq _030050B8
	adds r4, r4, #0x6000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_0300509C:
	bic sp, sp, #0x20000
	tst sp, #0x800000
	beq _030050B8
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030050B8:
	orr sp, sp, #0x800000
_030050BC:
	mvn r0, #1
	b _03005168
_030050C4:
	orr sp, sp, #0x20000
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030050D8:
	bic r6, r6, #0xff
	orr r6, r6, r8
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_030050F0:
	and r3, r6, #0xff
	and r8, r3, #0xff
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03005108:
	bic sp, sp, #0x200000
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_0300511C:
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_0300512C:
	adds r4, r4, #0x2000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_0300513C:
	strb r1, [sp, #0xa32]
	sub r5, r5, #1
	adds r4, r4, #0x7000000
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03005154:
	add ip, ip, #1
	str ip, [sp, #0x8b4]
	add ip, fp, #0x44
	adds r4, r4, #-0x72000000
	mvn r0, #5
_03005168:
	mov lr, #0x20000
_0300516C:
	sub r2, r5, r4, lsl #8
	lsr r1, r2, #8
	strb r1, [r6], #-1
	orr r6, r6, #0x100
	strb r2, [r6], #-1
	orr r6, r6, #0x100
	bic sp, sp, #0x80000
	lsr r1, sl, #0x1f
	tst r3, #0xff
	orreq r1, r1, #2
	orr r1, r1, sp, lsr #15
	tst r3, #0x280
	orrne r1, r1, #0x80
	strb r1, [r6], #-1
	orr r6, r6, #0x100
	orr sp, sp, lr
	add r2, r0, #0x10000
	ldr r1, [fp, #0x1c]
	add r1, r2, r1, lsl #8
	ldrh r0, [r1]
	lsr r1, r0, #0xd
	ldr r1, [fp, r1, lsl #2]
	add r5, r0, r1, lsl #8
	and r4, r4, #0xff000000
	adds r4, r4, r1
	ldrb r1, [r5], #1
	ldr pc, [ip, r1, lsl #2]
_030051D8:
	mov lr, #0x4000000
	ldrh r1, [lr]
	ldrb r2, [sp, #0x8bd]
	ldrb r0, [sp, #0xa41]
	subs r0, r0, #1
	strbpl r0, [sp, #0xa41]
	bhs _030051FC
	tst r2, #8
	orrne r1, r1, #0x800
_030051FC:
	ldrb r0, [sp, #0xa42]
	subs r0, r0, #1
	strbpl r0, [sp, #0xa42]
	bhs _03005214
	tst r2, #0x10
	orrne r1, r1, #0x1000
_03005214:
	strh r1, [lr]
	bic fp, fp, #0x400000
	orr fp, fp, #0x800000
	mov r1, #0xff
	strb r1, [sp, #0xa35]
	mvn ip, #0x15
	str ip, [sp, #0x8b4]
	adds r4, r4, #-0x72000000
	add r0, sp, #0x800
	add r0, r0, #0x84
	stm r0!, {r3, r4, r5, r6, r7, r8, sb, sl, fp}
	and r1, sp, #0xfe0000
	str r1, [r0, #4]
	mov r0, #0
	ldr pc, [sp, #0x9bc]
	and r0, r0, #0xff
	ldrb r3, [sp, r0]
	mov pc, lr
_0300525C:
	add ip, r0, #0x800
	stm ip, {r4, r5, r6, r7, r8, lr}
	ldr r4, [r0, #0x840]
	add r4, r4, #1
	str r4, [r0, #0x840]
	mov lr, #0x4000000
	ldr r4, [lr, #0x130]
	mvn r4, r4, lsl #22
	lsr r4, r4, #0x16
	ldr r5, [r0, #0x90c]
	str r4, [r0, #0x90c]
	eor r1, r4, r5
	and r1, r1, r4
	str r1, [r0, #0x910]
	str r4, [r0, #0x914]
	mov r4, #0
	str r4, [lr, #0xb8]
	str r4, [lr, #0xd0]!
	ldrb r5, [r0, #0xa48]
	cmp r5, #0
	ldrbne r5, [r0, #0xa49]
	strbne r5, [r0, #0xa48]
	bne _03005390
	ldr r1, [r0, #0x8f0]
	cmp r1, #0
	strne r4, [r0, #0x8f0]
	strne r1, [r0, #0x8f4]
	ldreq r1, [r0, #0x8f4]
	cmpeq r1, #0
	beq _03005390
	mov r3, #0x7000000
	add r3, r3, #0x1e0
	mov r5, #-0x7c000000
	orr r5, r5, #0x80
	stmib lr, {r1, r3, r5}
	add r1, r1, #0x200
	ldm r1!, {r2}
	sub r3, lr, #0xb4
	str r2, [r3]
	ldr r5, _03005394 @ =0xA2600002
	stmda lr, {r1, r3, r5}
	add r1, r1, #0x27c
	ldrh r2, [r1], #2
	strh r2, [r3, #-0xe]!
	sub r5, r5, #1
	sub lr, lr, #0x20
	stm lr, {r1, r3, r5}
	add r1, r0, #0x800
	add r1, r1, #0xc4
	mov r2, #0xb800
	orr r2, r2, #0x6000000
	ldrb r6, [r0, #0x8bd]
	tst r6, #1
	addne r2, r2, #0x400
	and r6, r6, #0xe0
	add r2, r2, r6, lsl #2
	mov lr, #0x5000000
	ldrb r6, [r1], #1
	ldrh r6, [r2, r6]
_03005348:
	ldrb r3, [r1], #1
	ldrh r3, [r2, r3]
	orr r3, r6, r3, lsl #16
	ldrb r4, [r1], #1
	ldrh r4, [r2, r4]
	ldrb r5, [r1], #2
	ldrh r5, [r2, r5]
	orr r4, r4, r5, lsl #16
	stm lr, {r3, r4}
	add lr, lr, #0x20
	tst lr, #0x60
	bne _03005348
	tst lr, #0x200
	addeq lr, lr, #0x180
	beq _03005348
	mov lr, #0x5000000
	ldr r6, [lr, #0x40]
	str r6, [lr, #0x84]
_03005390:
	ldm ip, {r4, r5, r6, r7, r8, pc}
	.align 2, 0
_03005394: .4byte 0xA2600002
_03005398:
	ldr ip, [sp, #0x8b4]
	cmp ip, #0xf0
	bhs _0300552C
	cmp ip, #0xe2
	bhs _03005478
	subs r0, ip, #0xc
	ldrlo r0, [sp, #0x9c0]
	blo _03005478
	bne _03005418
	mov lr, #0x4000000
	ldrh r1, [lr]
	ldrb r2, [sp, #0x8bd]
	tst r2, #8
	biceq r1, r1, #0x800
	moveq r2, #2
	strbeq r2, [sp, #0xa41]
	ldrbeq r2, [sp, #0x8bd]
	tst r2, #0x10
	biceq r1, r1, #0x1000
	moveq r2, #2
	strbeq r2, [sp, #0xa42]
	strh r1, [lr]
	bic fp, fp, #0xc0000
	ldr r1, [sp, #0x8e4]
	ldr r2, [sp, #0x8e8]
	str r1, [sp, #0x96c]
	str r2, [sp, #0x970]
	tst fp, #0x100000
	streq r1, [sp, #0x94c]
	strne r2, [sp, #0x94c]
	mov r1, #0
	strb r1, [sp, #0xa40]
_03005418:
	mov lr, #0x6000
	orr lr, lr, #0x6000000
	add lr, lr, r0, lsl #3
	ldrb r0, [sp, #0x8e4]
	cmp r0, #0
	movne r0, #0xa
	tst fp, #0x100000
	orrne r0, r0, #5
	strh r0, [lr, #2]
	ldrb r0, [sp, #0x9c1]
	add r1, sp, r0 @ WARNING: disassembler produces wrong instruction here
	ldrb r1, [r1, #0x8b0]
	eor r0, r0, #1
	add r0, sp, r0 @ WARNING: disassembler produces wrong instruction here
	ldrb r0, [r0, #0x8b0]
	orr r0, r0, r1, lsl #6
	ldr r1, [sp, #0x8bc]
	bic r1, r1, #0xc3
	orr r1, r1, r0
	strh r1, [lr]
	ldr r0, [sp, #0x9c0]
	ldrb r1, [sp, #0xa39]
	orr r1, r1, r0, lsl #8
	strh r1, [lr, #4]
_03005478:
	add r0, r0, #1
	ands r1, r0, #0xff
	subeq r0, r0, #0x100
	cmp r1, #0xf0
	addeq r0, r0, #0x110
	bic r0, r0, #0xfc00
	str r0, [sp, #0x9c0]
	mov r2, #0x6700
	orr r2, r2, #0x6000000
	ldrh r2, [r2]
	and r2, r2, #0xff
	cmp r2, ip
	bne _030054B0
	strb r2, [sp, #0xa35]
_030054B0:
	ldrb r2, [sp, #0xa35]
	cmp ip, r2
	orreq fp, fp, #0x400000
	ldr r2, [sp, #0x9d0]
	cmp ip, r2
	bne _03005504
	ldrb r0, [sp, #0xa3c]
	tst r0, #0xc0
	bne _03005504
	ldrb r0, [sp, #0x908]
	orr r0, r0, #0x40
	strb r0, [sp, #0x908]
	tst sp, #0x20000
	bicne sp, sp, #0x800000
	bne _03005504
	orr sp, sp, #0x800000
	add ip, ip, #1
	str ip, [sp, #0x8b4]
	add ip, fp, #0x44
	adds r4, r4, #-0x72000000
	b _030050BC
_03005504:
	add ip, ip, #1
	str ip, [sp, #0x8b4]
	add ip, fp, #0x44
	adds r4, r4, #-0x72000000
	ldrb r1, [r5], #1
	ldr pc, [ip, r1, lsl #2]
_0300551C:
	ldrb r0, [sp, #0x8bc]
	tst r0, #0x80
	bne _03005154
	b _03005504
_0300552C:
	beq _030051D8
	cmn ip, #0x15
	beq _0300551C
	cmn ip, #1
	bne _03005504
	bic fp, fp, #0xc00000
	ldr r1, [sp, #0x9c4]
	ldr r0, [sp, #0x830]
	add r1, r1, r0
	str r1, [sp, #0x9c0]
	b _03005504
_03005558:
	.byte 0xD4, 0x00, 0x00, 0x04, 0x34, 0xE6, 0x03, 0x02
	.byte 0x60, 0x30, 0x00, 0x06, 0x10, 0x00, 0x00, 0x80

	arm_func_start sub_03005568
sub_03005568: @ 0x03005568
	ldrb r0, [sp, #0xa46]
	cmp r0, #0x18
	movhs r0, #0
	lsr r1, r0, #2
	add r0, r0, #1
	strb r0, [sp, #0xa46]
	sub r0, pc, #0x30
	ldm r0, {r2, r3, r4, r5}
	add r3, r3, r1, lsl #5
	stm r2, {r3, r4, r5}
_03005590:
	ldr ip, [sp, #0x8ec]
	ldr r0, [sp, #0x8f4]
	cmp r0, ip
	svceq #0x20000
	beq _03005590
	ldr r0, [sp, #0x830]
	cmp r0, #0
	moveq r0, #0x9600000
	lslne r0, r0, #0x18
	addne r0, r0, #0xc000000
	str r0, [sp, #0x838]
	moveq r0, #0xc00000
	movne r0, #0x1000000
	str r0, [sp, #0x834]
	ldr r1, [sp, #0x8f8]
	sub r1, r1, ip
	str r1, [sp, #0x8ec]
	mov r7, #0x6700
	orr r7, r7, #0x6000000
	add r6, ip, #0x200
	sub lr, r7, #0x760
_030055E4:
	ldr sl, [r7], #4
	and sb, sl, #0xff
	add sb, sb, #1
	cmp sb, #0xf0
	bhs _0300567C
	subs r0, sb, #0xc
	addhs fp, lr, sb, lsl #3
	addlo fp, lr, #0x60
	ldrh r8, [fp]
	tst r8, #0x1000
	beq _0300567C
	and r0, sl, #0xc00000
	lsl r0, r0, #6
	and r1, sl, #0xff000000
	lsr r1, r1, #1
	sub r1, r1, #0x4000000
	lsr r1, r1, #7
	orr r0, r0, r1
	ldr r2, [sp, #0x834]
	mul r1, sb, r2
	ldr r2, [sp, #0x838]
	sub r1, r1, r2
	orr r0, r0, r1, lsr #24
	and r1, sl, #0x30000
	lsr r1, r1, #4
	tst sl, #0x200000
	orreq r1, r1, #0x400
	orrne r1, r1, #0x800
	and sl, sl, #0xff00
	tst r8, #0x20
	andeq r2, r8, #8
	orrne r0, r0, #0x8000
	andne r2, sl, #0x100
	bicne sl, sl, #0x100
	cmp r2, #0
	orrne sl, sl, #0x10000
	orr r1, r1, sl, lsr #8
	stm ip!, {r0, r1}
_0300567C:
	tst r7, #0xff
	bne _030055E4
	mov r0, #0xa0
_03005688:
	cmp ip, r6
	strlo r0, [ip], #8
	blo _03005688
	add sb, ip, #0x280
	mov sl, #0
	ldr lr, [sp, #0x900]
	ldr r0, [sp, #0x830]
	cmp r0, #0
	beq _030056B4
	mov r4, #0
	b _030056E8
_030056B4:
	ldr r0, [sp, #0x8fc]
	ror r0, r0, #0x10
	lsl r0, r0, #0x10
	orr r4, r0, r0, lsr #16
	ldr r0, [sp, #0x9c4]
	and r0, r0, #3
	rsb r0, r0, #0x20
	rors r4, r4, r0
	rorpl r4, r4, #1
	addmi lr, lr, #8
	b _030056E8
_030056E0:
	lsl r0, r0, #0x10
	orr r4, r0, r0, lsr #16
_030056E8:
	ldrh r8, [lr]
	tst r8, #0x800
	beq _03005794
	mov r7, #0x400
	orr r7, r7, #1
	and r0, r8, r8, lsr #6
	ands r2, r0, #1
	orrne r7, r7, #0x8000
	eor r0, r8, r8, lsr #6
	tst r0, #1
	orrne r7, r7, #0x4000
	ldrh r0, [lr, #2]
	and r0, r0, #0xc
	ldr r1, [sp, #0x830]
	cmp r1, #0
	movne r0, #0xc
	orr r7, r7, r0
	orr r7, r7, r7, lsl #16
	ldrh r0, [lr, #4]
	and r1, r0, #0xff
	tst r8, #0x40
	orrne r1, r1, #0x100
	add r5, r1, #8
	and r0, r0, #0xff00
	orr r0, r0, r2, lsl #16
	sub r0, r0, sl, lsl #8
	orr r5, r5, r0, lsl #8
_03005754:
	strh r7, [sb], #2
	str r5, [ip], #4
	add lr, lr, #8
	rors r4, r4, #0x1f
	addmi lr, lr, #8
	rormi r4, r4, #0x1f
	add sl, sl, #1
	cmp sl, #0xa0
	blo _030056E8
_03005778:
	ldr r0, [sp, #0x8f0]
	cmp r0, #0
	bne _03005778
	sub r1, ip, #0x480
	str r1, [sp, #0x8f0]
	ldr pc, _03005790 @ =0x0600E2C4
	.align 2, 0
_03005790: .4byte 0x0600E2C4
_03005794:
	ldr r7, _030057A4 @ =0x0000C401
	mov r0, #0x1000000
	sub r5, r0, sl, lsl #16
	b _03005754
	.align 2, 0
_030057A4: .4byte 0x0000C401

	arm_func_start sub_030057A8
sub_030057A8: @ 0x030057A8
	mov ip, #0x4000000
	ldr r2, [ip, #0x200]
	and r1, r2, r2, lsr #16
	ands r2, r1, #0x2000
	bne _0300580C
	ands r0, r1, #0x10
	bne _030057E4
	add r2, r2, #4
	ands r0, r1, #1
	strhne r0, [ip, #-8]
	bne _030057E4
	add r2, r2, #4
	ands r0, r1, #0x40
	bne _030057E4
	add r2, r2, #4
_030057E4:
	add ip, ip, #0x200
	strh r0, [ip, #2]
	ldr r0, _03005808 @ =0x00000000
	ldr ip, [pc, r2]
	bx ip
_030057F8:
	.byte 0xE1, 0x04, 0x00, 0x03, 0x5C, 0x52, 0x00, 0x03
	.byte 0x2C, 0x58, 0x00, 0x03, 0x3C, 0x58, 0x00, 0x03
_03005808: .4byte 0x00000000
_0300580C:
	strb r2, [ip, #0x84]
	ldr r0, _03005808 @ =0x00000000
	ldr r1, [r0, #0x928]
	strh r1, [ip]
	mov ip, #0x5000000
	mov r1, #0
	strh r1, [ip]
_03005828:
	b _03005828

	arm_func_start sub_0300582C
sub_0300582C: @ 0x0300582C
	ldr ip, [r0, #0x918]
	cmp ip, #0
	bxeq lr
	bx ip

	arm_func_start sub_0300583C
sub_0300583C: @ 0x0300583C
	bx lr

	arm_func_start sub_03005840
sub_03005840: @ 0x03005840
	streq fp, [r0], -r0, lsl #16
	tst r1, #0x80
	bne _03005880
	ldrb r2, [sp, #0xa55]
	tst r1, #1
	orrne r2, r2, #0x20
	lsr r2, r2, #1
	ldrb r1, [sp, #0xa54]
	subs r1, r1, #1
	beq _0300588C
	strb r2, [sp, #0xa55]
	strb r1, [sp, #0xa54]
_03005870:
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
_03005880:
	ldrb r2, [sp, #0xa4f]
	orr r2, r2, #0xc
	movs r0, #0x8000
_0300588C:
	mov r1, #5
	strb r1, [sp, #0xa54]
	add r0, sp, r0, lsr #13 @ WARNING: disassembler produces wrong instruction here
	ldrb r1, [r0, #0xa4b]
	cmp r1, r2
	beq _03005870
	strb r2, [r0, #0xa4b]
	ldrb r0, [sp, #0xa4f]
	ldr r2, [sp, #0x874]
	ldrb lr, [sp, #0xa52]
	tst r0, #8
	biceq lr, lr, #1
	and lr, r2, lr, lsl #6
	ldr r2, [sp, #0x85c]
	bne _030058E0
	add r2, r2, lr
	str r2, [fp, #0x10]
	str r2, [fp, #0x14]
	str r2, [fp, #0x18]
	str r2, [fp, #0x1c]
	b _0300594C
_030058E0:
	tst r0, #4
	bne _0300591C
	ldrb r1, [sp, #0xa53]
	cmp r1, #0
	ldrbne r1, [sp, #0xa50]
	tstne r1, #0x10
	addne r2, r2, #0x400
	str r2, [fp, #0x10]
	str r2, [fp, #0x14]
	ldr r2, [sp, #0x86c]
	subeq r2, r2, #0x400
	add r2, r2, lr
	str r2, [fp, #0x18]
	str r2, [fp, #0x1c]
	b _0300594C
_0300591C:
	ldrb r1, [sp, #0xa53]
	cmp r1, #0
	ldrbne r1, [sp, #0xa50]
	tstne r1, #0x10
	addne r2, r2, #0x400
	add r2, r2, lr
	str r2, [fp, #0x10]
	str r2, [fp, #0x14]
	ldr r2, [sp, #0x86c]
	subeq r2, r2, #0x400
	str r2, [fp, #0x18]
	str r2, [fp, #0x1c]
_0300594C:
	ldr r1, [sp, #0x878]
	cmp r1, #0
	beq _030059F8
	tst r0, #0x10
	ldrb r1, [sp, #0xa50]
	ldr r2, [sp, #0x87c]
	bne _030059AC
	bic r1, r1, #1
	and r1, r2, r1, lsl #2
	orr r1, r1, r1, lsl #8
	orr r1, r1, r1, lsl #16
	ldr lr, _03005A34 @ =0x03020100
	orr lr, lr, r1
	ldr r2, [sp, #0x8e4]
	cmp r2, lr
	orrne fp, fp, #0xc0000
	strne lr, [sp, #0x8e4]
	ldr lr, _03005A38 @ =0x07060504
	orr lr, lr, r1
	ldreq r2, [sp, #0x8e8]
	cmpeq r2, lr
	orrne fp, fp, #0xc0000
	strne lr, [sp, #0x8e8]
	b _030059F8
_030059AC:
	and r1, r2, r1, lsl #2
	orr r1, r1, r1, lsl #8
	orr r1, r1, r1, lsl #16
	ldr lr, _03005A34 @ =0x03020100
	orr lr, lr, r1
	ldr r1, [sp, #0x8e4]
	cmp r1, lr
	orrne fp, fp, #0xc0000
	strne lr, [sp, #0x8e4]
	ldrb r1, [sp, #0xa51]
	and r1, r2, r1, lsl #2
	orr r1, r1, r1, lsl #8
	orr r1, r1, r1, lsl #16
	ldr lr, _03005A34 @ =0x03020100
	orr lr, lr, r1
	ldr r1, [sp, #0x8e8]
	cmp r1, lr
	orrne fp, fp, #0xc0000
	strne lr, [sp, #0x8e8]
_030059F8:
	add r1, pc, #0x3C @ =_03005A3C
	and r0, r0, #3
	ldr r0, [r1, r0, lsl #2]
	str r0, [sp, #0x8b0]
	sub r2, r5, r4, lsl #8
	lsr r1, r2, #0xd
	ldr r1, [fp, r1, lsl #2]
	add r5, r2, r1, lsl #8
	and r4, r4, #0xff000000
	sub r4, r4, #0x6000000
	adds r4, r4, r1
	cmp r4, #0
	ldrblt r1, [r5], #1
	ldrlt pc, [ip, r1, lsl #2]
	b _03005398
	.align 2, 0
_03005A34: .4byte 0x03020100
_03005A38: .4byte 0x07060504
_03005A3C: .4byte 0x00000000
_03005A40: .4byte 0x01010101
_03005A44: .4byte 0x01000100
_03005A48: .4byte 0x01010000
