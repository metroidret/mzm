.align 2

.global track_202

track_202_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 10
	.byte VOL, 37
	.byte PAN, c_v
	.byte N18, Cn3, v080
	.byte W18
	.byte FINE

.align 2

track_202:
	.byte 1
	.byte 0
	.byte 195
	.byte 0
	.word voicegroup002
	.word track_202_0

.align 2
