.align 2

.global track_212

track_212_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 27
	.byte VOL, 44
	.byte PAN, c_v
	.byte N18, Cn3, v080
	.byte W18
	.byte FINE

.align 2

track_212:
	.byte 1
	.byte 0
	.byte 195
	.byte 0
	.word voicegroup002
	.word track_212_0

.align 2
