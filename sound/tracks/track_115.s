.align 2

.global track_115

track_115_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 22
	.byte VOL, 49
	.byte PAN, c_v
	.byte BEND, c_v
	.byte N05, Cn3, v112
	.byte W05
	.byte VOICE, 23
	.byte BENDR, 8
	.byte BEND, c_v
	.byte N15, Cn1, v072
	.byte W01
	.byte BEND, c_v-2
	.byte W01
	.byte c_v-3 @ BEND
	.byte W01
	.byte c_v-5 @ BEND
	.byte W01
	.byte c_v-7 @ BEND
	.byte W01
	.byte c_v-9 @ BEND
	.byte W01
	.byte c_v-10 @ BEND
	.byte W01
	.byte c_v-12 @ BEND
	.byte W01
	.byte VOL, 49
	.byte BEND, c_v-14
	.byte W01
	.byte VOL, 31
	.byte BEND, c_v-15
	.byte W01
	.byte VOL, 19
	.byte BEND, c_v-17
	.byte W01
	.byte VOL, 11
	.byte BEND, c_v-19
	.byte W01
	.byte VOL, 6
	.byte BEND, c_v-21
	.byte W01
	.byte VOL, 2
	.byte BEND, c_v-22
	.byte W01
	.byte VOL, 0
	.byte W01
	.byte FINE

.align 2

track_115:
	.byte 1
	.byte 0
	.byte 164
	.byte 0
	.word voicegroup001
	.word track_115_0

.align 2
