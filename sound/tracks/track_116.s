.align 2

.global track_116

track_116_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 25
	.byte VOL, 42
	.byte PAN, c_v
	.byte N07, Cn3, v112
	.byte W07
	.byte FINE

.align 2

track_116:
	.byte 1
	.byte 0
	.byte 164
	.byte 0
	.word voicegroup001
	.word track_116_0

.align 2
