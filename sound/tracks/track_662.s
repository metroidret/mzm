.align 2

.global track_662

track_662_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 28
	.byte VOL, 50
	.byte PAN, c_v
	.byte N36, Cn3, v080
	.byte W96
track_662_lbl_21e73a:
	.byte W01
	.byte N36, Dn3, v072
	.byte W92
	.byte W03
	.byte W01
	.byte Cs3, v064 @ N36
	.byte W60
	.byte Cn3, v080 @ N36
	.byte W32
	.byte W03
	.byte W36
	.byte W02
	.byte GOTO
		.word track_662_lbl_21e73a
	.byte FINE

track_662_1:
	.byte KEYSH, 0
	.byte VOICE, 28
	.byte VOL, 19
	.byte PAN, c_v
	.byte W60
	.byte N36, Fn3, v072
	.byte W36
track_662_lbl_21e75d:
	.byte W60
	.byte W01
	.byte N36, En3, v064
	.byte W32
	.byte W03
	.byte W36
	.byte W03
	.byte En3, v052 @ N36
	.byte W56
	.byte W01
	.byte W12
	.byte Fn3, v068 @ N36
	.byte W24
	.byte W02
	.byte GOTO
		.word track_662_lbl_21e75d
	.byte W10
	.byte FINE

.align 2

track_662:
	.byte 2
	.byte 0
	.byte 228
	.byte 0
	.word voicegroup003
	.word track_662_0
	.word track_662_1

.align 2
