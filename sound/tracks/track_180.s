.align 2

.global track_180

track_180_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 31
	.byte PAN, c_v-34
	.byte N16, Cn3, v100
	.byte W16
	.byte FINE

.align 2

track_180:
	.byte 1
	.byte 0
	.byte 180
	.byte 0
	.word voicegroup011
	.word track_180_0

.align 2
