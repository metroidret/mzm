.align 2

.global track_601

track_601_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 1
	.byte VOL, 50
	.byte PAN, c_v
	.byte BENDR, 20
	.byte BEND, c_v-16
	.byte N22, Fn1, v080
	.byte W05
	.byte BEND, c_v
	.byte W15
	.byte VOL, 18
	.byte W01
	.byte 6 @ VOL
	.byte W01
	.byte 0 @ VOL
	.byte FINE

.align 2

track_601:
	.byte 1
	.byte 0
	.byte 165
	.byte 0
	.word voicegroup003
	.word track_601_0

.align 2
