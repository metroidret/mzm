.align 2

.global track_113

track_113_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 62
	.byte PAN, c_v
	.byte N03, Cn3, v100
	.byte W03
	.byte FINE

.align 2

track_113:
	.byte 1
	.byte 0
	.byte 163
	.byte 0
	.word voicegroup001
	.word track_113_0

.align 2
