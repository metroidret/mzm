.align 2

.global track_21

track_21_0:
	.byte KEYSH, 0
	.byte TEMPO, 28
	.byte VOICE, 27
	.byte VOL, 75
	.byte PAN, c_v
	.byte N12, Gn1, v112
	.byte W72
	.byte VOICE, 28
	.byte FINE

track_21_1:
	.byte KEYSH, 0
	.byte VOICE, 14
	.byte VOL, 75
	.byte PAN, c_v
	.byte N12, Gn3, v112
	.byte W12
	.byte FINE

.align 2

track_21:
	.byte 2
	.byte 0
	.byte 130
	.byte 0
	.word voicegroup000
	.word track_21_0
	.word track_21_1

.align 2
