.align 2

.global track_484

track_484_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 6
	.byte VOL, 17
	.byte PAN, c_v
	.byte BENDR, 12
	.byte BEND, c_v-47
	.byte N30, En3, v080, 1
	.byte W02
	.byte VOL, 25
	.byte BEND, c_v-42
	.byte W02
	.byte VOL, 32
	.byte BEND, c_v-37
	.byte W02
	.byte VOL, 40
	.byte BEND, c_v-31
	.byte W02
	.byte VOL, 48
	.byte BEND, c_v-26
	.byte W02
	.byte VOL, 55
	.byte BEND, c_v-21
	.byte W02
	.byte VOL, 63
	.byte BEND, c_v-16
	.byte W02
	.byte VOL, 71
	.byte BEND, c_v-10
	.byte W02
	.byte VOL, 78
	.byte BEND, c_v-5
	.byte W02
	.byte VOL, 86
	.byte BEND, c_v
	.byte W02
	.byte c_v+11 @ BEND
	.byte W02
	.byte c_v+21 @ BEND
	.byte W02
	.byte c_v+32 @ BEND
	.byte W02
	.byte c_v+42 @ BEND
	.byte W02
	.byte VOL, 86
	.byte BEND, c_v+53
	.byte W02
	.byte VOL, 52
	.byte BEND, c_v+63
	.byte W01
	.byte FINE

.align 2

track_484:
	.byte 1
	.byte 0
	.byte 181
	.byte 0
	.word voicegroup013
	.word track_484_0

.align 2
