.align 2

.global track_249

track_249_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 56
	.byte PAN, c_v
	.byte W06
	.byte N30, Cn3, v080
	.byte W30
	.byte FINE

.align 2

track_249:
	.byte 1
	.byte 0
	.byte 171
	.byte 0
	.word voicegroup002
	.word track_249_0

.align 2
