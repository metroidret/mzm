.align 2

.global track_214

track_214_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 29
	.byte VOL, 37
	.byte PAN, c_v
	.byte N18, Cn3, v080
	.byte W18
	.byte FINE

.align 2

track_214:
	.byte 1
	.byte 0
	.byte 195
	.byte 0
	.word voicegroup002
	.word track_214_0

.align 2
