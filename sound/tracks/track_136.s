.align 2

.global track_136

track_136_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 27
	.byte VOL, 59
	.byte PAN, c_v
	.byte N02, Cn3, v080
	.byte W04
	.byte N02 @ Cn3, v080
	.byte W04
	.byte Cn3, v060 @ N02
	.byte W04
	.byte Cn3, v040 @ N02
	.byte W02
	.byte FINE

.align 2

track_136:
	.byte 1
	.byte 0
	.byte 220
	.byte 0
	.word voicegroup001
	.word track_136_0

.align 2
