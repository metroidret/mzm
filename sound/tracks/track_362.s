.align 2

.global track_362

track_362_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 27
	.byte VOL, 55
	.byte PAN, c_v
	.byte N17, Cn3, v080
	.byte W17
	.byte FINE

.align 2

track_362:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voicegroup003
	.word track_362_0

.align 2
