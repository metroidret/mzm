.align 2

.global track_501

track_501_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 37
	.byte PAN, c_v
	.byte BENDR, 14
	.byte BEND, c_v+63
	.byte N24, En3, v040
	.byte W01
	.byte BEND, c_v+58
	.byte W01
	.byte c_v+52 @ BEND
	.byte W01
	.byte c_v+47 @ BEND
	.byte W01
	.byte c_v+41 @ BEND
	.byte W01
	.byte c_v+36 @ BEND
	.byte W01
	.byte c_v+30 @ BEND
	.byte W01
	.byte c_v+25 @ BEND
	.byte W01
	.byte VOL, 37
	.byte BEND, c_v+19
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v+14
	.byte W01
	.byte VOL, 26
	.byte BEND, c_v+8
	.byte W01
	.byte VOL, 22
	.byte BEND, c_v+3
	.byte W01
	.byte VOL, 17
	.byte BEND, c_v-3
	.byte W01
	.byte VOL, 14
	.byte BEND, c_v-8
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v-14
	.byte W01
	.byte VOL, 9
	.byte BEND, c_v-19
	.byte W01
	.byte VOL, 7
	.byte BEND, c_v-25
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v-30
	.byte W01
	.byte VOL, 4
	.byte BEND, c_v-36
	.byte W01
	.byte VOL, 3
	.byte BEND, c_v-41
	.byte W01
	.byte VOL, 2
	.byte BEND, c_v-47
	.byte W01
	.byte VOL, 1
	.byte BEND, c_v-52
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v-58
	.byte W01
	.byte VOL, 0
	.byte BEND, c_v-63
	.byte W07
	.byte VOICE, 3
	.byte BEND, c_v
	.byte N13, Cn3, v072
	.byte W01
	.byte VOL, 12
	.byte W01
	.byte 25 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 37 @ VOL
	.byte W01
	.byte 28 @ VOL
	.byte N06, Gn3, v032
	.byte W01
	.byte VOL, 18
	.byte W01
	.byte 18 @ VOL
	.byte W01
	.byte 15 @ VOL
	.byte W01
	.byte 11 @ VOL
	.byte W01
	.byte 7 @ VOL
	.byte W01
	.byte 3 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte W01
	.byte FINE

.align 2

track_501:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voicegroup016
	.word track_501_0

.align 2
