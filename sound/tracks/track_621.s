.align 2

.global track_621

track_621_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 44
	.byte VOL, 50
	.byte PAN, c_v
	.byte BENDR, 18
	.byte BEND, c_v+47
	.byte N09, Gn2, v100
	.byte W01
	.byte BEND, c_v+31
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W01
	.byte c_v-16 @ BEND
	.byte W01
	.byte c_v-32 @ BEND
	.byte W01
	.byte c_v-16 @ BEND
	.byte W01
	.byte VOL, 37
	.byte BEND, c_v
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 50
	.byte BEND, c_v+47
	.byte N09, Gn2, v048
	.byte W01
	.byte BEND, c_v+31
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W01
	.byte c_v-16 @ BEND
	.byte W01
	.byte c_v-32 @ BEND
	.byte W01
	.byte c_v-16 @ BEND
	.byte W01
	.byte VOL, 37
	.byte BEND, c_v
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v+16
	.byte W01
	.byte VOL, 50
	.byte BEND, c_v+47
	.byte N09, Gn2, v020
	.byte W01
	.byte BEND, c_v+31
	.byte W01
	.byte c_v+15 @ BEND
	.byte W01
	.byte c_v @ BEND
	.byte W01
	.byte c_v-16 @ BEND
	.byte W01
	.byte c_v-32 @ BEND
	.byte W01
	.byte c_v-16 @ BEND
	.byte W01
	.byte VOL, 37
	.byte BEND, c_v
	.byte W01
	.byte VOL, 18
	.byte BEND, c_v+16
	.byte W01
	.byte FINE

.align 2

track_621:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voicegroup004
	.word track_621_0

.align 2
