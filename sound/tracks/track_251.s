.align 2

.global track_251

track_251_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 67
	.byte PAN, c_v
	.byte N13, Cn3, v100
	.byte W13
	.byte FINE

.align 2

track_251:
	.byte 1
	.byte 0
	.byte 195
	.byte 0
	.word voicegroup002
	.word track_251_0

.align 2
