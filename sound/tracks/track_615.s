.align 2

.global track_615

track_615_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 0
	.byte PAN, c_v
	.byte N12, Gn3, v080
	.byte W12
	.byte FINE

.align 2

track_615:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voicegroup001
	.word track_615_0

.align 2
