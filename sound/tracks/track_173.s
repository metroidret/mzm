.align 2

.global track_173

track_173_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 78
	.byte PAN, c_v+16
	.byte N36, Cn3, v100, 3
	.byte W36
	.byte W03
	.byte FINE

.align 2

track_173:
	.byte 1
	.byte 0
	.byte 199
	.byte 0
	.word voicegroup007
	.word track_173_0

.align 2
