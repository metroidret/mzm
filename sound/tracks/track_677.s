.align 2

.global track_677

track_677_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 99
	.byte PAN, c_v+6
	.byte N24, Cn3, v120
	.byte W24
	.byte FINE

.align 2

track_677:
	.byte 1
	.byte 0
	.byte 200
	.byte 0
	.word voicegroup014
	.word track_677_0

.align 2
