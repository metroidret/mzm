.align 2

.global track_630

track_630_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 11
	.byte VOL, 67
	.byte PAN, c_v
	.byte N03, Cn3, v092
	.byte W03
	.byte VOICE, 19
	.byte N21 @ Cn3, v092
	.byte W44
	.byte W01
	.byte FINE

track_630_1:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 70
	.byte PAN, c_v
	.byte PRIO, 55
	.byte W02
	.byte N04, Fn2, v112
	.byte W44
	.byte W02
	.byte FINE

.align 2

track_630:
	.byte 2
	.byte 0
	.byte 180
	.byte 0
	.word voicegroup005
	.word track_630_0
	.word track_630_1

.align 2
