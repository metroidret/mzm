.align 2

.global track_364

track_364_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 22
	.byte VOL, 50
	.byte PAN, c_v
	.byte N04, Fn3, v060
	.byte W04
	.byte VOICE, 24
	.byte N04, An4, v080
	.byte W04
	.byte FINE

.align 2

track_364:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voicegroup003
	.word track_364_0

.align 2
