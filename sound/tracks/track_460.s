.align 2

.global track_460

track_460_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 0
	.byte VOL, 74
	.byte PAN, c_v-20
	.byte N15, Cn3, v112
	.byte W15
	.byte VOICE, 1
	.byte N19, Cn3, v092
	.byte W42
	.byte FINE

track_460_1:
	.byte KEYSH, 0
	.byte VOICE, 2
	.byte VOL, 86
	.byte PAN, c_v-28
	.byte N05, Fn2, v100
	.byte W56
	.byte W01
	.byte FINE

.align 2

track_460:
	.byte 2
	.byte 0
	.byte 200
	.byte 0
	.word voicegroup010
	.word track_460_0
	.word track_460_1

.align 2
