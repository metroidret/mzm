.align 2

.global track_600

track_600_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 13
	.byte VOL, 44
	.byte PAN, c_v
	.byte N04, Cn4, v080
	.byte W04
	.byte FINE

.align 2

track_600:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voicegroup005
	.word track_600_0

.align 2
