	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    .align 2

gUnk_08120AE8:: @ 08120AE8
	.incbin "baserom.gba", 0x120AE8, 0x0000005

gUnk_08120AED:: @ 08120AED
	.incbin "baserom.gba", 0x120AED, 0x0000014

gUnk_08120B01:: @ 08120B01
	.incbin "baserom.gba", 0x120B01, 0x000000F

gUnk_08120B10:: @ 08120B10
	.4byte gUnk_08120AE8
	.4byte gUnk_08120AED
	.4byte gUnk_08120B01
	.4byte 00000000

