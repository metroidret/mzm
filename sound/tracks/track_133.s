.align 2

.global track_133

track_133_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 30
	.byte VOL, 50
	.byte PAN, c_v
	.byte N08, Cn3, v080
	.byte W08
	.byte FINE

.align 2

track_133:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voicegroup001
	.word track_133_0

.align 2
