.align 2

.global track_201

track_201_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 49
	.byte PAN, c_v
	.byte N28, Cn3, v080, 1
	.byte W28
	.byte W01
	.byte FINE

.align 2

track_201:
	.byte 1
	.byte 0
	.byte 195
	.byte 0
	.word voicegroup002
	.word track_201_0

.align 2
