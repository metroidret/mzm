.align 2

.global track_483

track_483_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 5
	.byte VOL, 66
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N09, Cn3, v080
	.byte W04
	.byte BEND, c_v+63
	.byte W01
	.byte VOL, 41
	.byte W01
	.byte 24 @ VOL
	.byte W01
	.byte 8 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_483:
	.byte 1
	.byte 0
	.byte 181
	.byte 0
	.word voicegroup013
	.word track_483_0

.align 2
