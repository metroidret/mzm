.align 2

.global track_399

track_399_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 13
	.byte VOL, 44
	.byte PAN, c_v
	.byte N06, An3, v080
	.byte W06
	.byte FINE

.align 2

track_399:
	.byte 1
	.byte 0
	.byte 161
	.byte 0
	.word voicegroup005
	.word track_399_0

.align 2
