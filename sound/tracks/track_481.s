.align 2

.global track_481

track_481_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte VOL, 78
	.byte PAN, c_v
	.byte W08
	.byte N15, Cn3, v100
	.byte W15
	.byte FINE

.align 2

track_481:
	.byte 1
	.byte 0
	.byte 171
	.byte 0
	.word voicegroup013
	.word track_481_0

.align 2
