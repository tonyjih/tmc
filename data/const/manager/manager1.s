	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    .align 2

gUnk_08107C1C:: @ 08107C1C
	.incbin "baserom.gba", 0x107C1C, 0x0000014

gUnk_08107C30:: @ 08107C30
	.incbin "baserom.gba", 0x107C30, 0x0000010

gUnk_08107C40:: @ 08107C40
	.incbin "baserom.gba", 0x107C40, 0x0000008

gUnk_08107C48:: @ 08107C48
	.4byte nullsub_494
	.4byte nullsub_494
	.4byte sub_080573AC
	.4byte nullsub_494
	.4byte sub_08057450

gUnk_08107C5C:: @ 08107C5C
	.4byte sub_08057118
	.4byte sub_08057174
	.4byte sub_0805728C
	.4byte sub_080572D4
