.align 2

.global track_127

track_127_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 32
	.byte VOL, 27
	.byte PAN, c_v
	.byte N01, Cn3, v080
	.byte W01
	.byte FINE

.align 2

track_127:
	.byte 1
	.byte 0
	.byte 164
	.byte 0
	.word voicegroup001
	.word track_127_0

.align 2
