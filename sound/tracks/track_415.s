.align 2

.global track_415

track_415_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 4
	.byte VOL, 78
	.byte PAN, c_v
	.byte N12, An2, v100
	.byte W12
	.byte Cn3, v060 @ N12
	.byte W06
	.byte VOL, 78
	.byte W01
	.byte 68 @ VOL
	.byte W01
	.byte 59 @ VOL
	.byte W01
	.byte 51 @ VOL
	.byte W01
	.byte 43 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 31 @ VOL
	.byte N12, En3, v020
	.byte W01
	.byte VOL, 27
	.byte W01
	.byte 22 @ VOL
	.byte W01
	.byte 19 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 13 @ VOL
	.byte W01
	.byte 10 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 5 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 2 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

track_415_1:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 62
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v
	.byte N24, Fn2, v080
	.byte W02
	.byte BEND, c_v+2
	.byte W02
	.byte c_v+5 @ BEND
	.byte W02
	.byte c_v+9 @ BEND
	.byte W02
	.byte VOL, 62
	.byte BEND, c_v+15
	.byte W01
	.byte VOL, 55
	.byte W01
	.byte 48 @ VOL
	.byte BEND, c_v+23
	.byte W01
	.byte VOL, 41
	.byte W01
	.byte 35 @ VOL
	.byte BEND, c_v+32
	.byte W01
	.byte VOL, 30
	.byte W01
	.byte 25 @ VOL
	.byte BEND, c_v+30
	.byte W01
	.byte VOL, 21
	.byte W01
	.byte 18 @ VOL
	.byte BEND, c_v+27
	.byte W01
	.byte VOL, 14
	.byte W01
	.byte 11 @ VOL
	.byte BEND, c_v+23
	.byte W01
	.byte VOL, 8
	.byte W01
	.byte 6 @ VOL
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 3
	.byte W01
	.byte 2 @ VOL
	.byte BEND, c_v+6
	.byte W01
	.byte VOL, 0
	.byte W01
	.byte FINE

.align 2

track_415:
	.byte 2
	.byte 0
	.byte 161
	.byte 0
	.word voicegroup008
	.word track_415_0
	.word track_415_1

.align 2
