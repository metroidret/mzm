.align 2

.global track_184

track_184_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 85
	.byte PAN, c_v-4
	.byte N16, Cn3, v100
	.byte W16
	.byte FINE

.align 2

track_184:
	.byte 1
	.byte 0
	.byte 200
	.byte 0
	.word voicegroup011
	.word track_184_0

.align 2
