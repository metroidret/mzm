.align 2

.global track_357

track_357_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 24
	.byte VOL, 47
	.byte PAN, c_v
	.byte N04, Dn4, v080
	.byte W04
	.byte FINE

.align 2

track_357:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voicegroup003
	.word track_357_0

.align 2
