.align 2

.global track_104

track_104_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 24
	.byte VOL, 35
	.byte PAN, c_v
	.byte N06, Cn3, v112
	.byte W08
	.byte FINE

.align 2

track_104:
	.byte 1
	.byte 0
	.byte 162
	.byte 0
	.word voicegroup001
	.word track_104_0

.align 2
