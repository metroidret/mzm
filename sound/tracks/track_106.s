.align 2

.global track_106

track_106_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 53
	.byte PAN, c_v
	.byte N12, Cn3, v100
	.byte W12
	.byte FINE

.align 2

track_106:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voicegroup001
	.word track_106_0

.align 2
