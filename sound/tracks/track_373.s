.align 2

.global track_373

track_373_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 37
	.byte VOL, 44
	.byte PAN, c_v
	.byte N11, Cn3, v052
	.byte W11
	.byte FINE

.align 2

track_373:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voicegroup003
	.word track_373_0

.align 2
