.align 2

.global track_550

track_550_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 9
	.byte VOL, 31
	.byte PAN, c_v
	.byte N02, Cn3, v080
	.byte W02
	.byte FINE

.align 2

track_550:
	.byte 1
	.byte 0
.ifdef REGION_US_BETA
	.byte 251
.else
	.byte 229
.endif
	.byte 128
	.word voicegroup017
	.word track_550_0

.align 2
