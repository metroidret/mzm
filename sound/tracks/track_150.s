.align 2

.global track_150

track_150_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 44
	.byte VOL, 34
	.byte PAN, c_v
	.byte N02, An3, v112
	.byte W02
	.byte FINE

.align 2

track_150:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voicegroup001
	.word track_150_0

.align 2
