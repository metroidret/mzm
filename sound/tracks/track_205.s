.align 2

.global track_205

track_205_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 49
	.byte PAN, c_v
	.byte N28, Cn3, v080
	.byte W28
	.byte FINE

.align 2

track_205:
	.byte 1
	.byte 0
	.byte 195
	.byte 0
	.word voicegroup002
	.word track_205_0

.align 2
