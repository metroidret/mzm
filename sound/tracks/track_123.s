.align 2

.global track_123

track_123_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 56
	.byte PAN, c_v
	.byte N05, Cn3, v080
	.byte W04
	.byte VOL, 39
	.byte W04
	.byte VOICE, 2
	.byte N03 @ Cn3, v080
	.byte W03
	.byte FINE

.align 2

track_123:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voicegroup001
	.word track_123_0

.align 2
