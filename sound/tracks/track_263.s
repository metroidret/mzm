.align 2

.global track_263

track_263_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 7
	.byte VOL, 70
	.byte PAN, c_v
	.byte N03, Cn6, v127
	.byte W03
	.byte FINE

.align 2

track_263:
	.byte 1
	.byte 0
	.byte 188
	.byte 0
	.word voicegroup002
	.word track_263_0

.align 2
