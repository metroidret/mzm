.align 2

.global track_152

track_152_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 3
	.byte VOL, 37
	.byte PAN, c_v
	.byte N07, Cn3, v080
	.byte W07
	.byte FINE

.align 2

track_152:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voicegroup001
	.word track_152_0

.align 2
