    .include "asm/constants.inc"
    .include "asm/macros.inc"
	.include "asm/emulator_constants.inc"

    .syntax unified

_0600C000: .4byte sub_0600C024
_0600C004: .4byte 0x00000005
_0600C008: .4byte sub_06006000

	arm_func_start sub_0600C00C
sub_0600C00C: @ 0x0600C00C
	ldr r0, _0600C004 @ =0x00000005
	bl sub_0600C020
	mov r6, #0x7c00
	orr r6, r6, #0x6000000
	ldr pc, _0600C008 @ =sub_06006000

	arm_func_start sub_0600C020
sub_0600C020: @ 0x0600C020
	ldr pc, _0600C000 @ =sub_0600C024

	arm_func_start sub_0600C024
sub_0600C024: @ 0x0600C024
	strb r0, [sp, #SP_A54]
	mov r0, #0x8f
	strb r0, [sp, #SP_A4F]
	ldr r2, [sp, #SP_870]
	cmp r2, #0x80000
	bxne lr
	mov r0, #1
	strb r0, [sp, #SP_A53]
	mov r0, #0x10
	strb r0, [sp, #SP_A50]
	bx lr

	arm_func_start sub_0600C050
sub_0600C050: @ 0x0600C050
	ldr r2, _0600C05C @ =0x030029E4
	str r3, [r2]
	bx lr
	.align 2, 0
_0600C05C: .4byte 0x030029E4
