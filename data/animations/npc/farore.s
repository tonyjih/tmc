	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    .align 2

gUnk_0810F9F4:: @ 0810F9F4
	.incbin "baserom.gba", 0x10F9F4, 0x0000005

gUnk_0810F9F9:: @ 0810F9F9
	.incbin "baserom.gba", 0x10F9F9, 0x0000005

gUnk_0810F9FE:: @ 0810F9FE
	.incbin "baserom.gba", 0x10F9FE, 0x0000005

gUnk_0810FA03:: @ 0810FA03
	.incbin "baserom.gba", 0x10FA03, 0x0000011

gUnk_0810FA14:: @ 0810FA14
	.4byte gUnk_0810F9F4
	.4byte gUnk_0810F9FE
	.4byte gUnk_0810F9F4
	.4byte gUnk_0810F9F9
	.4byte gUnk_0810FA03
	.4byte gUnk_0810FA03
	.4byte gUnk_0810FA03
	.4byte gUnk_0810FA03
	.4byte 00000000
