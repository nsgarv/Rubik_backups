
	; HI-TECH dsPIC/PIC24 V9.60PL2
	; Copyright (C) 1984-2008 HI-TECH Software
	;Serial no. HCDSPIC-437079963

	; Auto-generated runtime startup code for final link stage.

	;
	; Compiler options:
	;
	; -oDFMAIN.cof -mDFMAIN.map --runtime=default,+clear,+init,+keep,+stack \
	; DFDISPLY.obj DFMAIN.obj DFHW.obj dfcrc.obj -lf --chip=24HJ256GP610 \
	; -IC:\Program Files (x86)\HI-TECH Software\DSPICC\STD\9.60\include -P \
	; --opt=none,-asm,+debug,-9 -v --warn=9 -Bsmall -q -g --asmlist \
	; --errformat=Error   [%n] %f; %l.%c %s --msgformat=Advisory[%n] %s \
	; --warnformat=Warning [%n] %f; %l.%c %s
	;


	psect	init,class=CODE,delta=2,reloc=4
	psect	end_init,class=CODE,delta=2,reloc=4
	psect	reset_vec,class=VECTORS,delta=2
	psect	powerup,class=CODE,delta=2,reloc=4
	psect	vectors,class=VECTORS,delta=2
	psect	altvectors,class=ALTVECTOR,delta=2
	psect	config,class=CONFIG,delta=2,reloc=4
	psect	eeprom,class=EEPROM,delta=2
	psect	data,class=XDATA,space=1,reloc=2
	psect	neardata,class=NEARXDATA,space=1,reloc=2
	psect	heap,class=XDATA,space=1,reloc=2
	psect	strings,class=CONST,delta=1,reloc=4,width=2
	psect	mstrings,class=MCONST
	psect	bss,space=1,class=XDATA
	psect	nearbss,space=1,class=NEARXDATA
	psect	ydata,class=YDATA,space=1,reloc=2
	psect	nearydata,class=NEARYDATA,space=1,reloc=2
	psect	ybss,space=1,class=YDATA
	psect	nearybss,space=1,class=NEARYDATA
	psect	ybitbss,space=1,bit,class=YDATA
	psect	nearybitbss,space=1,bit,class=NEARYDATA
	psect	ynvram,class=YDATA,space=1,reloc=2,pad=2
	psect	nearynvram,class=NEARYDATA,space=1,reloc=2,pad=2
	psect	ynvbit,space=1,bit,class=YDATA
	psect	nearynvbit,space=1,bit,class=NEARYDATA
	psect	bitbss,space=1,bit,class=XDATA
	psect	nearbitbss,space=1,bit,class=NEARXDATA
	psect	nvram,class=XDATA,space=1,reloc=2,pad=2
	psect	nearnvram,class=NEARXDATA,space=1,reloc=2,pad=2
	psect	nvbit,space=1,bit,class=XDATA
	psect	nearnvbit,space=1,bit,class=NEARXDATA
	psect	const,global,reloc=4,class=CONST,delta=1,pad=4,width=2
	psect	mconst,global,reloc=2,class=MCONST,space=1,delta=1,pad=2

	;Interrupt Vector Table

	; vector 0x6
psect vectors
	;	not defined
	; vector 0x8
psect vectors
	;	not defined
	; vector 0xA
psect vectors
	;	not defined
	; vector 0xC
psect vectors
	;	not defined
	; vector 0xE
psect vectors
	;	not defined
	;Reserved memory (0x10)
	;Reserved memory (0x12)
	; vector 0x14
psect vectors
	;	not defined
	; vector 0x16
psect vectors
	;	not defined
	; vector 0x18
psect vectors
	;	not defined
	; vector 0x1A
psect vectors
	;	not defined
	; vector 0x1C
psect vectors
	;	not defined
	; vector 0x1E
psect vectors
	;	not defined
	; vector 0x20
psect vectors
	;	not defined
	; vector 0x22
psect vectors
	;	not defined
	; vector 0x24
psect vectors
	;	not defined
	; vector 0x26
psect vectors
	;	not defined
	; vector 0x28
psect vectors
	;	not defined
	; vector 0x2A
psect vectors
	;	not defined
	; vector 0x2C
psect vectors
	;	not defined
	; vector 0x2E
psect vectors
	;	not defined
	; vector 0x30
psect vectors
	;	not defined
	; vector 0x32
psect vectors
	;	not defined
	; vector 0x34
psect vectors
	;	not defined
	; vector 0x36
psect vectors
	;	not defined
	; vector 0x38
psect vectors
	;	not defined
	; vector 0x3A
psect vectors
	;	not defined
	; vector 0x3C
psect vectors
	;	not defined
	; vector 0x3E
psect vectors
	;	not defined
	; vector 0x40
psect vectors
	;	not defined
	; vector 0x42
psect vectors
	;	not defined
	; vector 0x44
psect vectors
	;	not defined
	; vector 0x46
psect vectors
	;	not defined
	; vector 0x48
psect vectors
	;	not defined
	; vector 0x4A
psect vectors
	;	not defined
	; vector 0x4C
psect vectors
	;	not defined
	; vector 0x4E
psect vectors
	;	not defined
	; vector 0x50
psect vectors
	;	not defined
	; vector 0x52
psect vectors
	;	not defined
	; vector 0x54
psect vectors
	;	not defined
	; vector 0x56
psect vectors
	;	not defined
	; vector 0x58
psect vectors
	;	not defined
	; vector 0x5A
psect vectors
	;	not defined
	; vector 0x5C
psect vectors
	;	not defined
	; vector 0x5E
psect vectors
	;	not defined
	; vector 0x60
psect vectors
	;	not defined
	; vector 0x62
psect vectors
	;	not defined
	; vector 0x64
psect vectors
	;	not defined
	; vector 0x66
psect vectors
	;	not defined
	; vector 0x68
psect vectors
	;	not defined
	; vector 0x6A
psect vectors
	;	not defined
	; vector 0x6C
psect vectors
	;	not defined
	; vector 0x6E
psect vectors
	;	not defined
	; vector 0x70
psect vectors
	;	not defined
	; vector 0x72
psect vectors
	;	not defined
	; vector 0x74
psect vectors
	;	not defined
	; vector 0x76
psect vectors
	;	not defined
	; vector 0x78
psect vectors
	;	not defined
	; vector 0x7A
psect vectors
	;	not defined
	; vector 0x7C
psect vectors
	;	not defined
	; vector 0x7E
psect vectors
	;	not defined
	; vector 0x80
psect vectors
	;	not defined
	; vector 0x82
psect vectors
	;	not defined
	; vector 0x84
psect vectors
	;	not defined
	; vector 0x86
psect vectors
	;	not defined
	; vector 0x88
psect vectors
	;	not defined
	; vector 0x8A
psect vectors
	;	not defined
	; vector 0x8C
psect vectors
	;	not defined
	; vector 0x8E
psect vectors
	;	not defined
	; vector 0x90
psect vectors
	;	not defined
	; vector 0x92
psect vectors
	;	not defined
	; vector 0x94
psect vectors
	;	not defined
	; vector 0x96
psect vectors
	;	not defined
	; vector 0x98
psect vectors
	;	not defined
	; vector 0x9A
psect vectors
	;	not defined
	; vector 0x9C
psect vectors
	;	not defined
	; vector 0x9E
psect vectors
	;	not defined
	; vector 0xA0
psect vectors
	;	not defined
	; vector 0xA2
psect vectors
	;	not defined
	; vector 0xA4
psect vectors
	;	not defined
	; vector 0xA6
psect vectors
	;	not defined
	; vector 0xA8
psect vectors
	;	not defined
	; vector 0xAA
psect vectors
	;	not defined
	; vector 0xAC
psect vectors
	;	not defined
	; vector 0xAE
psect vectors
	;	not defined
	; vector 0xB0
psect vectors
	;	not defined
	; vector 0xB2
psect vectors
	;	not defined
	; vector 0xB4
psect vectors
	;	not defined
	; vector 0xB6
psect vectors
	;	not defined
	; vector 0xB8
psect vectors
	;	not defined
	; vector 0xBA
psect vectors
	;	not defined
	; vector 0xBC
psect vectors
	;	not defined
	; vector 0xBE
psect vectors
	;	not defined
	; vector 0xC0
psect vectors
	;	not defined
	; vector 0xC2
psect vectors
	;	not defined
	; vector 0xC4
psect vectors
	;	not defined
	; vector 0xC6
psect vectors
	;	not defined
	; vector 0xC8
psect vectors
	;	not defined
	; vector 0xCA
psect vectors
	;	not defined
	; vector 0xCC
psect vectors
	;	not defined
	; vector 0xCE
psect vectors
	;	not defined
	; vector 0xD0
psect vectors
	;	not defined
	; vector 0xD2
psect vectors
	;	not defined
	; vector 0xD4
psect vectors
	;	not defined
	; vector 0xD6
psect vectors
	;	not defined
	; vector 0xD8
psect vectors
	;	not defined
	; vector 0xDA
psect vectors
	;	not defined
	; vector 0xDC
psect vectors
	;	not defined
	; vector 0xDE
psect vectors
	;	not defined
	; vector 0xE0
psect vectors
	;	not defined
	; vector 0xE2
psect vectors
	;	not defined
	; vector 0xE4
psect vectors
	;	not defined
	; vector 0xE6
psect vectors
	;	not defined
	; vector 0xE8
psect vectors
	;	not defined
	; vector 0xEA
psect vectors
	;	not defined
	; vector 0xEC
psect vectors
	;	not defined
	; vector 0xEE
psect vectors
	;	not defined
	; vector 0xF0
psect vectors
	;	not defined
	; vector 0xF2
psect vectors
	;	not defined
	; vector 0xF4
psect vectors
	;	not defined
	; vector 0xF6
psect vectors
	;	not defined
	; vector 0xF8
psect vectors
	;	not defined
	; vector 0xFA
psect vectors
	;	not defined
	; vector 0xFC
psect vectors
	;	not defined
	; vector 0xFE
psect vectors
	;	not defined
	;Reserved memory (0x100)
	;Reserved memory (0x102)
	;Reserved memory (0x104)
	; vector 0x106
psect altvectors
	;	not defined
	; vector 0x108
psect altvectors
	;	not defined
	; vector 0x10A
psect altvectors
	;	not defined
	; vector 0x10C
psect altvectors
	;	not defined
	; vector 0x10E
psect altvectors
	;	not defined
	;Reserved memory (0x110)
	;Reserved memory (0x112)
	; vector 0x114
psect altvectors
	;	not defined
	; vector 0x116
psect altvectors
	;	not defined
	; vector 0x118
psect altvectors
	;	not defined
	; vector 0x11A
psect altvectors
	;	not defined
	; vector 0x11C
psect altvectors
	;	not defined
	; vector 0x11E
psect altvectors
	;	not defined
	; vector 0x120
psect altvectors
	;	not defined
	; vector 0x122
psect altvectors
	;	not defined
	; vector 0x124
psect altvectors
	;	not defined
	; vector 0x126
psect altvectors
	;	not defined
	; vector 0x128
psect altvectors
	;	not defined
	; vector 0x12A
psect altvectors
	;	not defined
	; vector 0x12C
psect altvectors
	;	not defined
	; vector 0x12E
psect altvectors
	;	not defined
	; vector 0x130
psect altvectors
	;	not defined
	; vector 0x132
psect altvectors
	;	not defined
	; vector 0x134
psect altvectors
	;	not defined
	; vector 0x136
psect altvectors
	;	not defined
	; vector 0x138
psect altvectors
	;	not defined
	; vector 0x13A
psect altvectors
	;	not defined
	; vector 0x13C
psect altvectors
	;	not defined
	; vector 0x13E
psect altvectors
	;	not defined
	; vector 0x140
psect altvectors
	;	not defined
	; vector 0x142
psect altvectors
	;	not defined
	; vector 0x144
psect altvectors
	;	not defined
	; vector 0x146
psect altvectors
	;	not defined
	; vector 0x148
psect altvectors
	;	not defined
	; vector 0x14A
psect altvectors
	;	not defined
	; vector 0x14C
psect altvectors
	;	not defined
	; vector 0x14E
psect altvectors
	;	not defined
	; vector 0x150
psect altvectors
	;	not defined
	; vector 0x152
psect altvectors
	;	not defined
	; vector 0x154
psect altvectors
	;	not defined
	; vector 0x156
psect altvectors
	;	not defined
	; vector 0x158
psect altvectors
	;	not defined
	; vector 0x15A
psect altvectors
	;	not defined
	; vector 0x15C
psect altvectors
	;	not defined
	; vector 0x15E
psect altvectors
	;	not defined
	; vector 0x160
psect altvectors
	;	not defined
	; vector 0x162
psect altvectors
	;	not defined
	; vector 0x164
psect altvectors
	;	not defined
	; vector 0x166
psect altvectors
	;	not defined
	; vector 0x168
psect altvectors
	;	not defined
	; vector 0x16A
psect altvectors
	;	not defined
	; vector 0x16C
psect altvectors
	;	not defined
	; vector 0x16E
psect altvectors
	;	not defined
	; vector 0x170
psect altvectors
	;	not defined
	; vector 0x172
psect altvectors
	;	not defined
	; vector 0x174
psect altvectors
	;	not defined
	; vector 0x176
psect altvectors
	;	not defined
	; vector 0x178
psect altvectors
	;	not defined
	; vector 0x17A
psect altvectors
	;	not defined
	; vector 0x17C
psect altvectors
	;	not defined
	; vector 0x17E
psect altvectors
	;	not defined
	; vector 0x180
psect altvectors
	;	not defined
	; vector 0x182
psect altvectors
	;	not defined
	; vector 0x184
psect altvectors
	;	not defined
	; vector 0x186
psect altvectors
	;	not defined
	; vector 0x188
psect altvectors
	;	not defined
	; vector 0x18A
psect altvectors
	;	not defined
	; vector 0x18C
psect altvectors
	;	not defined
	; vector 0x18E
psect altvectors
	;	not defined
	; vector 0x190
psect altvectors
	;	not defined
	; vector 0x192
psect altvectors
	;	not defined
	; vector 0x194
psect altvectors
	;	not defined
	; vector 0x196
psect altvectors
	;	not defined
	; vector 0x198
psect altvectors
	;	not defined
	; vector 0x19A
psect altvectors
	;	not defined
	; vector 0x19C
psect altvectors
	;	not defined
	; vector 0x19E
psect altvectors
	;	not defined
	; vector 0x1A0
psect altvectors
	;	not defined
	; vector 0x1A2
psect altvectors
	;	not defined
	; vector 0x1A4
psect altvectors
	;	not defined
	; vector 0x1A6
psect altvectors
	;	not defined
	; vector 0x1A8
psect altvectors
	;	not defined
	; vector 0x1AA
psect altvectors
	;	not defined
	; vector 0x1AC
psect altvectors
	;	not defined
	; vector 0x1AE
psect altvectors
	;	not defined
	; vector 0x1B0
psect altvectors
	;	not defined
	; vector 0x1B2
psect altvectors
	;	not defined
	; vector 0x1B4
psect altvectors
	;	not defined
	; vector 0x1B6
psect altvectors
	;	not defined
	; vector 0x1B8
psect altvectors
	;	not defined
	; vector 0x1BA
psect altvectors
	;	not defined
	; vector 0x1BC
psect altvectors
	;	not defined
	; vector 0x1BE
psect altvectors
	;	not defined
	; vector 0x1C0
psect altvectors
	;	not defined
	; vector 0x1C2
psect altvectors
	;	not defined
	; vector 0x1C4
psect altvectors
	;	not defined
	; vector 0x1C6
psect altvectors
	;	not defined
	; vector 0x1C8
psect altvectors
	;	not defined
	; vector 0x1CA
psect altvectors
	;	not defined
	; vector 0x1CC
psect altvectors
	;	not defined
	; vector 0x1CE
psect altvectors
	;	not defined
	; vector 0x1D0
psect altvectors
	;	not defined
	; vector 0x1D2
psect altvectors
	;	not defined
	; vector 0x1D4
psect altvectors
	;	not defined
	; vector 0x1D6
psect altvectors
	;	not defined
	; vector 0x1D8
psect altvectors
	;	not defined
	; vector 0x1DA
psect altvectors
	;	not defined
	; vector 0x1DC
psect altvectors
	;	not defined
	; vector 0x1DE
psect altvectors
	;	not defined
	; vector 0x1E0
psect altvectors
	;	not defined
	; vector 0x1E2
psect altvectors
	;	not defined
	; vector 0x1E4
psect altvectors
	;	not defined
	; vector 0x1E6
psect altvectors
	;	not defined
	; vector 0x1E8
psect altvectors
	;	not defined
	; vector 0x1EA
psect altvectors
	;	not defined
	; vector 0x1EC
psect altvectors
	;	not defined
	; vector 0x1EE
psect altvectors
	;	not defined
	; vector 0x1F0
psect altvectors
	;	not defined
	; vector 0x1F2
psect altvectors
	;	not defined
	; vector 0x1F4
psect altvectors
	;	not defined
	; vector 0x1F6
psect altvectors
	;	not defined
	; vector 0x1F8
psect altvectors
	;	not defined
	; vector 0x1FA
psect altvectors
	;	not defined
	; vector 0x1FC
psect altvectors
	;	not defined
	; vector 0x1FE
psect altvectors
	;	not defined

	psect	text,class=CODE,delta=2,reloc=4
	psect	idata,class=NEARCODE,delta=1,reloc=4,width=2
	psect	nearidata,class=NEARCODE,delta=1,reloc=4,width=2
	psect	yidata,class=NEARCODE,delta=1,reloc=4,width=2
	psect	nearyidata,class=NEARCODE,delta=1,reloc=4,width=2
	global	start,_main,_exit,__Hbss,__Lbss,__Lbitbss,__Hbitbss
	global	reset_vec,__Hybss,__Lybss,__Lybitbss,__Hybitbss
	global	__Lnearbss,__Lnearbitbss,__Lnearybss,__Lnearybitbss
	global	__Hnearbss,__Hnearbitbss,__Hnearybss,__Hnearybitbss
	global	__Lconst
SPLIM	equ	0x20
TBLPAG	equ	0x32

	psect	reset_vec
reset_vec:
	goto	start

	psect	init
start:
_exit:
	global	__sp_init,__splim_init
	__sp_init	equ	011D0h
	__splim_init	equ	047FEh
	mov.w	#__sp_init,sp	;initialize the stack pointer
	mov.w	#__splim_init,w0	;initialize the stack limit register
	mov.w	w0,SPLIM

;	Map constants into RAM
PSVPAG	equ	0x34
CORCON	equ	0x44

	mov.w #((__Lconst>>16)&0xFF), w0
	mov.w w0, PSVPAG
	bset.b	CORCON,#2

;	Clear nearbss(XDATA) uninitialized variables
	mov.w	#__Lnearbss,w0
	repeat	#(722)-1
	clr.w	[w0++]

;	No uninitialized bss(XDATA) variables to clear
;	Copy initialized nearidata into neardata(XDATA)
	global	__Lnearidata,__Lneardata,__Hnearidata
	clr.b	TBLPAG
	mov.w	#__Lneardata,w1
	mov.w	#(__Lnearidata>>1),w0
	repeat	#(534)-1
	tblrdl	[w0++],[w1++]

;	No initialized data(XDATA) variables to copy

;	Jump to main()
	goto	_main

	end	start
