.align 2

.global track_81

track_81_0:
	.byte KEYSH, 0
track_81_lbl_22b8be:
	.byte TEMPO, 60
	.byte VOICE, 2
	.byte VOL, 0
	.byte N24, Cn3, v012
	.byte W96
	.byte GOTO
		.word track_81_lbl_22b8be
	.byte FINE

.align 2

track_81:
	.byte 1
	.byte 0
	.byte 130
	.byte 0
	.word voicegroup020
	.word track_81_0

.align 2
