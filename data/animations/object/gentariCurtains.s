	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    .align 2

gUnk_0812261C:: @ 0812261C
	.incbin "baserom.gba", 0x12261C, 0x0000015

gUnk_08122631:: @ 08122631
	.incbin "baserom.gba", 0x122631, 0x0000007

gUnk_08122638:: @ 08122638
	.4byte gUnk_0812261C
	.4byte gUnk_08122631
	.4byte 00000000
