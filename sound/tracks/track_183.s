.align 2

.global track_183

track_183_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 62
	.byte PAN, c_v+20
	.byte N16, Cn3, v100
	.byte W16
	.byte FINE

.align 2

track_183:
	.byte 1
	.byte 0
	.byte 200
	.byte 0
	.word voicegroup011
	.word track_183_0

.align 2
