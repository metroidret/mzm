.align 2

.global track_122

track_122_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 8
	.byte VOL, 54
	.byte PAN, c_v
	.byte N02, Cn3, v080
	.byte W02
	.byte FINE

.align 2

track_122:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voicegroup001
	.word track_122_0

.align 2
