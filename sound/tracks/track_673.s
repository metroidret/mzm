.align 2

.global track_673

track_673_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 70
	.byte PAN, c_v
	.byte N12, Cn3, v100
	.byte W12
	.byte FINE

.align 2

track_673:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voicegroup014
	.word track_673_0

.align 2
