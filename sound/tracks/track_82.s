.align 2

.global track_82

track_82_0:
	.byte KEYSH, 0
track_82_lbl_22b8de:
	.byte TEMPO, 60
	.byte VOICE, 2
	.byte VOL, 0
	.byte N24, Cn3, v012
	.byte W96
	.byte GOTO
		.word track_82_lbl_22b8de
	.byte FINE

.align 2

track_82:
	.byte 1
	.byte 0
	.byte 130
	.byte 0
	.word voicegroup020
	.word track_82_0

.align 2
