.align 2

.global track_548

track_548_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 0
	.byte PAN, c_v
	.byte N12, Cn3, v080
	.byte W12
	.byte FINE

.align 2

track_548:
	.byte 1
	.byte 0
	.byte 1
	.byte 0
	.word voicegroup001
	.word track_548_0

.align 2
