.align 2

.global track_678

track_678_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 69
	.byte PAN, c_v
	.byte W24
	.byte W01
	.byte N12, Cn3, v100
	.byte W12
	.byte FINE

.align 2

track_678:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voicegroup014
	.word track_678_0

.align 2
