	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    .align 2

gUnk_08110BD8:: @ 08110BD8
	.4byte sub_08066CCC
	.4byte sub_08066CF8

gUnk_08110BE0:: @ 08110BE0
	.incbin "baserom.gba", 0x110BE0, 0x0000020

gUnk_08110C00:: @ 08110C00
	.incbin "baserom.gba", 0x110C00, 0x000000C
