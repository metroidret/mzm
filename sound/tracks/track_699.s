.align 2

.global track_699

track_699_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 17
	.byte VOL, 75
	.byte PAN, c_v-14
	.byte N32, Gn2, v120, 2
	.byte W32
	.byte W02
	.byte FINE

.align 2

track_699:
	.byte 1
	.byte 0
	.byte 181
	.byte 0
	.word voicegroup014
	.word track_699_0

.align 2
