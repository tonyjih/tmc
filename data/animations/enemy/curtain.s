	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    .align 2


gUnk_080D1CF0:: @ 080D1CF0
	.incbin "baserom.gba", 0x0D1CF0, 0x0000009

gUnk_080D1CF9:: @ 080D1CF9
	.incbin "baserom.gba", 0x0D1CF9, 0x0000009

gUnk_080D1D02:: @ 080D1D02
	.incbin "baserom.gba", 0x0D1D02, 0x0000024

gUnk_080D1D26:: @ 080D1D26
	.incbin "baserom.gba", 0x0D1D26, 0x000000E

gUnk_080D1D34:: @ 080D1D34
	.4byte gUnk_080D1CF0
	.4byte gUnk_080D1CF9
	.4byte gUnk_080D1D02
	.4byte gUnk_080D1D26
	.4byte 00000000
