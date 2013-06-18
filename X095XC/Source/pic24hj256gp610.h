/*
 * Header file for the pic24hj256gp610 microcontroller.
 */

#ifndef __PIC24HJ256GP610_H
#define __PIC24HJ256GP610_H

//------------------------------------------------------------------------------
// Special Function Registers
//------------------------------------------------------------------------------

static volatile unsigned int  WREG0              @ 0x0;
static volatile unsigned int  WREG1              @ 0x2;
static volatile unsigned int  WREG2              @ 0x4;
static volatile unsigned int  WREG3              @ 0x6;
static volatile unsigned int  WREG4              @ 0x8;
static volatile unsigned int  WREG5              @ 0xA;
static volatile unsigned int  WREG6              @ 0xC;
static volatile unsigned int  WREG7              @ 0xE;
static volatile unsigned int  WREG8              @ 0x10;
static volatile unsigned int  WREG9              @ 0x12;
static volatile unsigned int  WREG10             @ 0x14;
static volatile unsigned int  WREG11             @ 0x16;
static volatile unsigned int  WREG12             @ 0x18;
static volatile unsigned int  WREG13             @ 0x1A;
static volatile unsigned int  WREG14             @ 0x1C;
static volatile unsigned int  WREG15             @ 0x1E;
static volatile unsigned int  SPLIM              @ 0x20;
static volatile unsigned int  PCL                @ 0x2E;
static volatile unsigned int  PCH                @ 0x30;
static volatile unsigned int  TBLPAG             @ 0x32;
static volatile unsigned int  PSVPAG             @ 0x34;
static volatile unsigned int  RCOUNT             @ 0x36;
static volatile unsigned int  SR                 @ 0x42;
static volatile bit           C                  @ ((unsigned)&SR*8)+0;
static volatile bit           Z                  @ ((unsigned)&SR*8)+1;
static volatile bit           OV                 @ ((unsigned)&SR*8)+2;
static volatile bit           N                  @ ((unsigned)&SR*8)+3;
static volatile bit           RA                 @ ((unsigned)&SR*8)+4;
static volatile bit           IPL0               @ ((unsigned)&SR*8)+5;
static volatile bit           IPL1               @ ((unsigned)&SR*8)+6;
static volatile bit           IPL2               @ ((unsigned)&SR*8)+7;
static volatile bit           DC                 @ ((unsigned)&SR*8)+8;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      DC                 : 1;
       volatile unsigned      IPL                : 3;
       volatile unsigned      RA                 : 1;
       volatile unsigned      N                  : 1;
       volatile unsigned      OV                 : 1;
       volatile unsigned      Z                  : 1;
       volatile unsigned      C                  : 1;
} SRbits @ 0x42;

static volatile unsigned int  CORCON             @ 0x44;
static volatile bit           PSV                @ ((unsigned)&CORCON*8)+2;
static volatile bit           IPL3               @ ((unsigned)&CORCON*8)+3;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      IPL3               : 1;
       volatile unsigned      PSV                : 1;
                unsigned                         : 1;
                unsigned                         : 1;
} CORCONbits @ 0x44;

static volatile unsigned int  DISICNT            @ 0x52;
static volatile unsigned int  CNEN1              @ 0x60;
static volatile bit           CN0IE              @ ((unsigned)&CNEN1*8)+0;
static volatile bit           CN1IE              @ ((unsigned)&CNEN1*8)+1;
static volatile bit           CN2IE              @ ((unsigned)&CNEN1*8)+2;
static volatile bit           CN3IE              @ ((unsigned)&CNEN1*8)+3;
static volatile bit           CN4IE              @ ((unsigned)&CNEN1*8)+4;
static volatile bit           CN5IE              @ ((unsigned)&CNEN1*8)+5;
static volatile bit           CN6IE              @ ((unsigned)&CNEN1*8)+6;
static volatile bit           CN7IE              @ ((unsigned)&CNEN1*8)+7;
static volatile bit           CN8IE              @ ((unsigned)&CNEN1*8)+8;
static volatile bit           CN9IE              @ ((unsigned)&CNEN1*8)+9;
static volatile bit           CN10IE             @ ((unsigned)&CNEN1*8)+10;
static volatile bit           CN11IE             @ ((unsigned)&CNEN1*8)+11;
static volatile bit           CN12IE             @ ((unsigned)&CNEN1*8)+12;
static volatile bit           CN13IE             @ ((unsigned)&CNEN1*8)+13;
static volatile bit           CN14IE             @ ((unsigned)&CNEN1*8)+14;
static volatile bit           CN15IE             @ ((unsigned)&CNEN1*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      CN15IE             : 1;
       volatile unsigned      CN14IE             : 1;
       volatile unsigned      CN13IE             : 1;
       volatile unsigned      CN12IE             : 1;
       volatile unsigned      CN11IE             : 1;
       volatile unsigned      CN10IE             : 1;
       volatile unsigned      CN9IE              : 1;
       volatile unsigned      CN8IE              : 1;
       volatile unsigned      CN7IE              : 1;
       volatile unsigned      CN6IE              : 1;
       volatile unsigned      CN5IE              : 1;
       volatile unsigned      CN4IE              : 1;
       volatile unsigned      CN3IE              : 1;
       volatile unsigned      CN2IE              : 1;
       volatile unsigned      CN1IE              : 1;
       volatile unsigned      CN0IE              : 1;
} CNEN1bits @ 0x60;

static volatile unsigned int  CNEN2              @ 0x62;
static volatile bit           CN16IE             @ ((unsigned)&CNEN2*8)+0;
static volatile bit           CN17IE             @ ((unsigned)&CNEN2*8)+1;
static volatile bit           CN18IE             @ ((unsigned)&CNEN2*8)+2;
static volatile bit           CN19IE             @ ((unsigned)&CNEN2*8)+3;
static volatile bit           CN20IE             @ ((unsigned)&CNEN2*8)+4;
static volatile bit           CN21IE             @ ((unsigned)&CNEN2*8)+5;
static volatile bit           CN22IE             @ ((unsigned)&CNEN2*8)+6;
static volatile bit           CN23IE             @ ((unsigned)&CNEN2*8)+7;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      CN23IE             : 1;
       volatile unsigned      CN22IE             : 1;
       volatile unsigned      CN21IE             : 1;
       volatile unsigned      CN20IE             : 1;
       volatile unsigned      CN19IE             : 1;
       volatile unsigned      CN18IE             : 1;
       volatile unsigned      CN17IE             : 1;
       volatile unsigned      CN16IE             : 1;
} CNEN2bits @ 0x62;

static volatile unsigned int  CNPU1              @ 0x68;
static volatile bit           CN0PUE             @ ((unsigned)&CNPU1*8)+0;
static volatile bit           CN1PUE             @ ((unsigned)&CNPU1*8)+1;
static volatile bit           CN2PUE             @ ((unsigned)&CNPU1*8)+2;
static volatile bit           CN3PUE             @ ((unsigned)&CNPU1*8)+3;
static volatile bit           CN4PUE             @ ((unsigned)&CNPU1*8)+4;
static volatile bit           CN5PUE             @ ((unsigned)&CNPU1*8)+5;
static volatile bit           CN6PUE             @ ((unsigned)&CNPU1*8)+6;
static volatile bit           CN7PUE             @ ((unsigned)&CNPU1*8)+7;
static volatile bit           CN8PUE             @ ((unsigned)&CNPU1*8)+8;
static volatile bit           CN9PUE             @ ((unsigned)&CNPU1*8)+9;
static volatile bit           CN10PUE            @ ((unsigned)&CNPU1*8)+10;
static volatile bit           CN11PUE            @ ((unsigned)&CNPU1*8)+11;
static volatile bit           CN12PUE            @ ((unsigned)&CNPU1*8)+12;
static volatile bit           CN13PUE            @ ((unsigned)&CNPU1*8)+13;
static volatile bit           CN14PUE            @ ((unsigned)&CNPU1*8)+14;
static volatile bit           CN15PUE            @ ((unsigned)&CNPU1*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      CN15PUE            : 1;
       volatile unsigned      CN14PUE            : 1;
       volatile unsigned      CN13PUE            : 1;
       volatile unsigned      CN12PUE            : 1;
       volatile unsigned      CN11PUE            : 1;
       volatile unsigned      CN10PUE            : 1;
       volatile unsigned      CN9PUE             : 1;
       volatile unsigned      CN8PUE             : 1;
       volatile unsigned      CN7PUE             : 1;
       volatile unsigned      CN6PUE             : 1;
       volatile unsigned      CN5PUE             : 1;
       volatile unsigned      CN4PUE             : 1;
       volatile unsigned      CN3PUE             : 1;
       volatile unsigned      CN2PUE             : 1;
       volatile unsigned      CN1PUE             : 1;
       volatile unsigned      CN0PUE             : 1;
} CNPU1bits @ 0x68;

static volatile unsigned int  CNPU2              @ 0x6A;
static volatile bit           CN16PUE            @ ((unsigned)&CNPU2*8)+0;
static volatile bit           CN17PUE            @ ((unsigned)&CNPU2*8)+1;
static volatile bit           CN18PUE            @ ((unsigned)&CNPU2*8)+2;
static volatile bit           CN19PUE            @ ((unsigned)&CNPU2*8)+3;
static volatile bit           CN20PUE            @ ((unsigned)&CNPU2*8)+4;
static volatile bit           CN21PUE            @ ((unsigned)&CNPU2*8)+5;
static volatile bit           CN22PUE            @ ((unsigned)&CNPU2*8)+6;
static volatile bit           CN23PUE            @ ((unsigned)&CNPU2*8)+7;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      CN23PUE            : 1;
       volatile unsigned      CN22PUE            : 1;
       volatile unsigned      CN21PUE            : 1;
       volatile unsigned      CN20PUE            : 1;
       volatile unsigned      CN19PUE            : 1;
       volatile unsigned      CN18PUE            : 1;
       volatile unsigned      CN17PUE            : 1;
       volatile unsigned      CN16PUE            : 1;
} CNPU2bits @ 0x6A;

static volatile unsigned int  INTCON1            @ 0x80;
static volatile bit           OSCFAIL            @ ((unsigned)&INTCON1*8)+1;
static volatile bit           STKERR             @ ((unsigned)&INTCON1*8)+2;
static volatile bit           ADDRERR            @ ((unsigned)&INTCON1*8)+3;
static volatile bit           MATHERR            @ ((unsigned)&INTCON1*8)+4;
static volatile bit           DMAC               @ ((unsigned)&INTCON1*8)+5;
static volatile bit           NSTDIS             @ ((unsigned)&INTCON1*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      NSTDIS             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      DMAC               : 1;
       volatile unsigned      MATHERR            : 1;
       volatile unsigned      ADDRERR            : 1;
       volatile unsigned      STKERR             : 1;
       volatile unsigned      OSCFAIL            : 1;
                unsigned                         : 1;
} INTCON1bits @ 0x80;

static volatile unsigned int  INTCON2            @ 0x82;
static volatile bit           INT0EP             @ ((unsigned)&INTCON2*8)+0;
static volatile bit           INT1EP             @ ((unsigned)&INTCON2*8)+1;
static volatile bit           INT2EP             @ ((unsigned)&INTCON2*8)+2;
static volatile bit           INT3EP             @ ((unsigned)&INTCON2*8)+3;
static volatile bit           INT4EP             @ ((unsigned)&INTCON2*8)+4;
static volatile bit           DISI               @ ((unsigned)&INTCON2*8)+14;
static volatile bit           ALTIVT             @ ((unsigned)&INTCON2*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      ALTIVT             : 1;
       volatile unsigned      DISI               : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      INT4EP             : 1;
       volatile unsigned      INT3EP             : 1;
       volatile unsigned      INT2EP             : 1;
       volatile unsigned      INT1EP             : 1;
       volatile unsigned      INT0EP             : 1;
} INTCON2bits @ 0x82;

static volatile unsigned int  IFS0               @ 0x84;
static volatile bit           INT0IF             @ ((unsigned)&IFS0*8)+0;
static volatile bit           IC1IF              @ ((unsigned)&IFS0*8)+1;
static volatile bit           OC1IF              @ ((unsigned)&IFS0*8)+2;
static volatile bit           T1IF               @ ((unsigned)&IFS0*8)+3;
static volatile bit           DMA0IF             @ ((unsigned)&IFS0*8)+4;
static volatile bit           IC2IF              @ ((unsigned)&IFS0*8)+5;
static volatile bit           OC2IF              @ ((unsigned)&IFS0*8)+6;
static volatile bit           T2IF               @ ((unsigned)&IFS0*8)+7;
static volatile bit           T3IF               @ ((unsigned)&IFS0*8)+8;
static volatile bit           SPF1IF             @ ((unsigned)&IFS0*8)+9;
static volatile bit           SPI1IF             @ ((unsigned)&IFS0*8)+10;
static volatile bit           U1RXIF             @ ((unsigned)&IFS0*8)+11;
static volatile bit           U1TXIF             @ ((unsigned)&IFS0*8)+12;
static volatile bit           ADIF               @ ((unsigned)&IFS0*8)+13;
static volatile bit           DMA1IF             @ ((unsigned)&IFS0*8)+14;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
       volatile unsigned      DMA1IF             : 1;
       volatile unsigned      ADIF               : 1;
       volatile unsigned      U1TXIF             : 1;
       volatile unsigned      U1RXIF             : 1;
       volatile unsigned      SPI1IF             : 1;
       volatile unsigned      SPI1FLTIF          : 1;
       volatile unsigned      T3IF               : 1;
       volatile unsigned      T2IF               : 1;
       volatile unsigned      OC2IF              : 1;
       volatile unsigned      IC2IF              : 1;
       volatile unsigned      DMA0IF             : 1;
       volatile unsigned      T1IF               : 1;
       volatile unsigned      OC1IF              : 1;
       volatile unsigned      IC1IF              : 1;
       volatile unsigned      INT0IF             : 1;
} IFS0bits @ 0x84;

static volatile unsigned int  IEC0               @ 0x94;
static volatile bit           INT0IE             @ ((unsigned)&IEC0*8)+0;
static volatile bit           IC1IE              @ ((unsigned)&IEC0*8)+1;
static volatile bit           OC1IE              @ ((unsigned)&IEC0*8)+2;
static volatile bit           T1IE               @ ((unsigned)&IEC0*8)+3;
static volatile bit           DMA0IE             @ ((unsigned)&IEC0*8)+4;
static volatile bit           IC2IE              @ ((unsigned)&IEC0*8)+5;
static volatile bit           OC2IE              @ ((unsigned)&IEC0*8)+6;
static volatile bit           T2IE               @ ((unsigned)&IEC0*8)+7;
static volatile bit           T3IE               @ ((unsigned)&IEC0*8)+8;
static volatile bit           SPF1IE             @ ((unsigned)&IEC0*8)+9;
static volatile bit           SPI1IE             @ ((unsigned)&IEC0*8)+10;
static volatile bit           U1RXIE             @ ((unsigned)&IEC0*8)+11;
static volatile bit           U1TXIE             @ ((unsigned)&IEC0*8)+12;
static volatile bit           ADIE               @ ((unsigned)&IEC0*8)+13;
static volatile bit           DMA1IE             @ ((unsigned)&IEC0*8)+14;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
       volatile unsigned      DMA1IE             : 1;
       volatile unsigned      ADIE               : 1;
       volatile unsigned      U1TXIE             : 1;
       volatile unsigned      U1RXIE             : 1;
       volatile unsigned      SPI1IE             : 1;
       volatile unsigned      SPI1FLTIE          : 1;
       volatile unsigned      T3IE               : 1;
       volatile unsigned      T2IE               : 1;
       volatile unsigned      OC2IE              : 1;
       volatile unsigned      IC2IE              : 1;
       volatile unsigned      DMA0IE             : 1;
       volatile unsigned      T1IE               : 1;
       volatile unsigned      OC1IE              : 1;
       volatile unsigned      IC1IE              : 1;
       volatile unsigned      INT0IE             : 1;
} IEC0bits @ 0x94;

static volatile unsigned int  IPC0               @ 0xA4;
static volatile bit           INT0IP0            @ ((unsigned)&IPC0*8)+0;
static volatile bit           INT0IP1            @ ((unsigned)&IPC0*8)+1;
static volatile bit           INT0IP2            @ ((unsigned)&IPC0*8)+2;
static volatile bit           IC1IP0             @ ((unsigned)&IPC0*8)+4;
static volatile bit           IC1IP1             @ ((unsigned)&IPC0*8)+5;
static volatile bit           IC1IP2             @ ((unsigned)&IPC0*8)+6;
static volatile bit           OC1IP0             @ ((unsigned)&IPC0*8)+8;
static volatile bit           OC1IP1             @ ((unsigned)&IPC0*8)+9;
static volatile bit           OC1IP2             @ ((unsigned)&IPC0*8)+10;
static volatile bit           T1IP0              @ ((unsigned)&IPC0*8)+12;
static volatile bit           T1IP1              @ ((unsigned)&IPC0*8)+13;
static volatile bit           T1IP2              @ ((unsigned)&IPC0*8)+14;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
       volatile unsigned      T1IP               : 3;
                unsigned                         : 1;
       volatile unsigned      OC1IP              : 3;
                unsigned                         : 1;
       volatile unsigned      IC1IP              : 3;
                unsigned                         : 1;
       volatile unsigned      INT0IP             : 3;
} IPC0bits @ 0xA4;

static volatile unsigned int  IPC1               @ 0xA6;
static volatile bit           DMA0IP0            @ ((unsigned)&IPC1*8)+0;
static volatile bit           DMA0IP1            @ ((unsigned)&IPC1*8)+1;
static volatile bit           DMA0IP2            @ ((unsigned)&IPC1*8)+2;
static volatile bit           IC2IP0             @ ((unsigned)&IPC1*8)+4;
static volatile bit           IC2IP1             @ ((unsigned)&IPC1*8)+5;
static volatile bit           IC2IP2             @ ((unsigned)&IPC1*8)+6;
static volatile bit           OC2IP0             @ ((unsigned)&IPC1*8)+8;
static volatile bit           OC2IP1             @ ((unsigned)&IPC1*8)+9;
static volatile bit           OC2IP2             @ ((unsigned)&IPC1*8)+10;
static volatile bit           T2IP0              @ ((unsigned)&IPC1*8)+12;
static volatile bit           T2IP1              @ ((unsigned)&IPC1*8)+13;
static volatile bit           T2IP2              @ ((unsigned)&IPC1*8)+14;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
       volatile unsigned      T2IP               : 3;
                unsigned                         : 1;
       volatile unsigned      OC2IP              : 3;
                unsigned                         : 1;
       volatile unsigned      IC2IP              : 3;
                unsigned                         : 1;
       volatile unsigned      DMA0IP             : 3;
} IPC1bits @ 0xA6;

static volatile unsigned int  IPC2               @ 0xA8;
static volatile bit           T3IP0              @ ((unsigned)&IPC2*8)+0;
static volatile bit           T3IP1              @ ((unsigned)&IPC2*8)+1;
static volatile bit           T3IP2              @ ((unsigned)&IPC2*8)+2;
static volatile bit           SPF1IP0            @ ((unsigned)&IPC2*8)+4;
static volatile bit           SPF1IP1            @ ((unsigned)&IPC2*8)+5;
static volatile bit           SPF1IP2            @ ((unsigned)&IPC2*8)+6;
static volatile bit           SP1IP0             @ ((unsigned)&IPC2*8)+8;
static volatile bit           SP1IP1             @ ((unsigned)&IPC2*8)+9;
static volatile bit           SP1IP2             @ ((unsigned)&IPC2*8)+10;
static volatile bit           U1RXIP0            @ ((unsigned)&IPC2*8)+12;
static volatile bit           U1RXIP1            @ ((unsigned)&IPC2*8)+13;
static volatile bit           U1RXIP2            @ ((unsigned)&IPC2*8)+14;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
       volatile unsigned      U1RXIP             : 3;
                unsigned                         : 1;
       volatile unsigned      SP1IP              : 3;
                unsigned                         : 1;
       volatile unsigned      SPI1FLTIP          : 3;
                unsigned                         : 1;
       volatile unsigned      T3IP               : 3;
} IPC2bits @ 0xA8;

static volatile unsigned int  IPC3               @ 0xAA;
static volatile bit           U1TXIP0            @ ((unsigned)&IPC3*8)+0;
static volatile bit           U1TXIP1            @ ((unsigned)&IPC3*8)+1;
static volatile bit           U1TXIP2            @ ((unsigned)&IPC3*8)+2;
static volatile bit           ADIP0              @ ((unsigned)&IPC3*8)+4;
static volatile bit           ADIP1              @ ((unsigned)&IPC3*8)+5;
static volatile bit           ADIP2              @ ((unsigned)&IPC3*8)+6;
static volatile bit           DMA1IP0            @ ((unsigned)&IPC3*8)+8;
static volatile bit           DMA1IP1            @ ((unsigned)&IPC3*8)+9;
static volatile bit           DMA1IP2            @ ((unsigned)&IPC3*8)+10;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      DMA1IP             : 3;
                unsigned                         : 1;
       volatile unsigned      ADIP               : 3;
                unsigned                         : 1;
       volatile unsigned      U1TXIP             : 3;
} IPC3bits @ 0xAA;

static volatile unsigned int  IPC4               @ 0xAC;
static volatile bit           SI2C1IP0           @ ((unsigned)&IPC4*8)+0;
static volatile bit           SI2C1IP1           @ ((unsigned)&IPC4*8)+1;
static volatile bit           SI2C1IP2           @ ((unsigned)&IPC4*8)+2;
static volatile bit           MI2C1P0            @ ((unsigned)&IPC4*8)+4;
static volatile bit           MI2C1P1            @ ((unsigned)&IPC4*8)+5;
static volatile bit           MI2C1P2            @ ((unsigned)&IPC4*8)+6;
static volatile bit           CNIP0              @ ((unsigned)&IPC4*8)+12;
static volatile bit           CNIP1              @ ((unsigned)&IPC4*8)+13;
static volatile bit           CNIP2              @ ((unsigned)&IPC4*8)+14;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
       volatile unsigned      CNIP               : 3;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      MI2C1P             : 3;
                unsigned                         : 1;
       volatile unsigned      SI2C1IP            : 3;
} IPC4bits @ 0xAC;

static volatile unsigned int  IPC6               @ 0xB0;
static volatile bit           DMA2IP0            @ ((unsigned)&IPC6*8)+0;
static volatile bit           DMA2IP1            @ ((unsigned)&IPC6*8)+1;
static volatile bit           DMA2IP2            @ ((unsigned)&IPC6*8)+2;
static volatile bit           OC3IP0             @ ((unsigned)&IPC6*8)+4;
static volatile bit           OC3IP1             @ ((unsigned)&IPC6*8)+5;
static volatile bit           OC3IP2             @ ((unsigned)&IPC6*8)+6;
static volatile bit           OC4IP0             @ ((unsigned)&IPC6*8)+8;
static volatile bit           OC4IP1             @ ((unsigned)&IPC6*8)+9;
static volatile bit           OC4IP2             @ ((unsigned)&IPC6*8)+10;
static volatile bit           T4IP0              @ ((unsigned)&IPC6*8)+12;
static volatile bit           T4IP1              @ ((unsigned)&IPC6*8)+13;
static volatile bit           T4IP2              @ ((unsigned)&IPC6*8)+14;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
       volatile unsigned      T4IP               : 3;
                unsigned                         : 1;
       volatile unsigned      OC4IP              : 3;
                unsigned                         : 1;
       volatile unsigned      OC3IP              : 3;
                unsigned                         : 1;
       volatile unsigned      DMA2IP             : 3;
} IPC6bits @ 0xB0;

static volatile unsigned int  IPC7               @ 0xB2;
static volatile bit           T5IP0              @ ((unsigned)&IPC7*8)+0;
static volatile bit           T5IP1              @ ((unsigned)&IPC7*8)+1;
static volatile bit           T5IP2              @ ((unsigned)&IPC7*8)+2;
static volatile bit           INT2IP0            @ ((unsigned)&IPC7*8)+4;
static volatile bit           INT2IP1            @ ((unsigned)&IPC7*8)+5;
static volatile bit           INT2IP2            @ ((unsigned)&IPC7*8)+6;
static volatile bit           U2RXIP0            @ ((unsigned)&IPC7*8)+8;
static volatile bit           U2RXIP1            @ ((unsigned)&IPC7*8)+9;
static volatile bit           U2RXIP2            @ ((unsigned)&IPC7*8)+10;
static volatile bit           U2TXIP0            @ ((unsigned)&IPC7*8)+12;
static volatile bit           U2TXIP1            @ ((unsigned)&IPC7*8)+13;
static volatile bit           U2TXIP2            @ ((unsigned)&IPC7*8)+14;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
       volatile unsigned      U2TXIP             : 3;
                unsigned                         : 1;
       volatile unsigned      U2RXIP             : 3;
                unsigned                         : 1;
       volatile unsigned      INT2IP             : 3;
                unsigned                         : 1;
       volatile unsigned      T5IP               : 3;
} IPC7bits @ 0xB2;

static volatile unsigned int  IPC9               @ 0xB6;
static volatile bit           DMA3IP0            @ ((unsigned)&IPC9*8)+0;
static volatile bit           DMA3IP1            @ ((unsigned)&IPC9*8)+1;
static volatile bit           DMA3IP2            @ ((unsigned)&IPC9*8)+2;
static volatile bit           IC3IP0             @ ((unsigned)&IPC9*8)+4;
static volatile bit           IC3IP1             @ ((unsigned)&IPC9*8)+5;
static volatile bit           IC3IP2             @ ((unsigned)&IPC9*8)+6;
static volatile bit           IC4IP0             @ ((unsigned)&IPC9*8)+8;
static volatile bit           IC4IP1             @ ((unsigned)&IPC9*8)+9;
static volatile bit           IC4IP2             @ ((unsigned)&IPC9*8)+10;
static volatile bit           IC5IP0             @ ((unsigned)&IPC9*8)+12;
static volatile bit           IC5IP1             @ ((unsigned)&IPC9*8)+13;
static volatile bit           IC5IP2             @ ((unsigned)&IPC9*8)+14;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
       volatile unsigned      IC5IP              : 3;
                unsigned                         : 1;
       volatile unsigned      IC4IP              : 3;
                unsigned                         : 1;
       volatile unsigned      IC3IP              : 3;
                unsigned                         : 1;
       volatile unsigned      DMA3IP             : 3;
} IPC9bits @ 0xB6;

static volatile unsigned int  IPC15              @ 0xC2;
static volatile bit           DMA5IP0            @ ((unsigned)&IPC15*8)+4;
static volatile bit           DMA5IP1            @ ((unsigned)&IPC15*8)+5;
static volatile bit           DMA5IP2            @ ((unsigned)&IPC15*8)+6;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      DMA5IP             : 3;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
} IPC15bits @ 0xC2;

static volatile unsigned int  IPC16              @ 0xC4;
static volatile bit           U1EIP0             @ ((unsigned)&IPC16*8)+4;
static volatile bit           U1EIP1             @ ((unsigned)&IPC16*8)+5;
static volatile bit           U1EIP2             @ ((unsigned)&IPC16*8)+6;
static volatile bit           U2EIP0             @ ((unsigned)&IPC16*8)+8;
static volatile bit           U2EIP1             @ ((unsigned)&IPC16*8)+9;
static volatile bit           U2EIP2             @ ((unsigned)&IPC16*8)+10;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      U2EIP              : 3;
                unsigned                         : 1;
       volatile unsigned      U1EIP              : 3;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
} IPC16bits @ 0xC4;

static volatile unsigned int  INTREG             @ 0xE0;
static volatile bit           VECNUM0            @ ((unsigned)&INTREG*8)+0;
static volatile bit           VECNUM1            @ ((unsigned)&INTREG*8)+1;
static volatile bit           VECNUM2            @ ((unsigned)&INTREG*8)+2;
static volatile bit           VECNUM3            @ ((unsigned)&INTREG*8)+3;
static volatile bit           VECNUM4            @ ((unsigned)&INTREG*8)+4;
static volatile bit           VECNUM5            @ ((unsigned)&INTREG*8)+5;
static volatile bit           ILR0               @ ((unsigned)&INTREG*8)+8;
static volatile bit           ILR1               @ ((unsigned)&INTREG*8)+9;
static volatile bit           ILR2               @ ((unsigned)&INTREG*8)+10;
static volatile bit           ILR3               @ ((unsigned)&INTREG*8)+11;
static volatile bit           TMODE              @ ((unsigned)&INTREG*8)+14;
static volatile bit           IRQTOCPU           @ ((unsigned)&INTREG*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      IRQtoCPU           : 1;
       volatile unsigned      TMODE              : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      ILR                : 4;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      VECNUM             : 6;
} INTREGbits @ 0xE0;

static volatile unsigned int  IFS1               @ 0x86;
static volatile bit           SI2C1IF            @ ((unsigned)&IFS1*8)+0;
static volatile bit           MI2C1IF            @ ((unsigned)&IFS1*8)+1;
static volatile bit           CNIF               @ ((unsigned)&IFS1*8)+3;
static volatile bit           INT1IF             @ ((unsigned)&IFS1*8)+4;
static volatile bit           AD2IF              @ ((unsigned)&IFS1*8)+5;
static volatile bit           IC7IF              @ ((unsigned)&IFS1*8)+6;
static volatile bit           IC8IF              @ ((unsigned)&IFS1*8)+7;
static volatile bit           DMA2IF             @ ((unsigned)&IFS1*8)+8;
static volatile bit           OC3IF              @ ((unsigned)&IFS1*8)+9;
static volatile bit           OC4IF              @ ((unsigned)&IFS1*8)+10;
static volatile bit           T4IF               @ ((unsigned)&IFS1*8)+11;
static volatile bit           T5IF               @ ((unsigned)&IFS1*8)+12;
static volatile bit           INT2IF             @ ((unsigned)&IFS1*8)+13;
static volatile bit           U2RXIF             @ ((unsigned)&IFS1*8)+14;
static volatile bit           U2TXIF             @ ((unsigned)&IFS1*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      U2TXIF             : 1;
       volatile unsigned      U2RXIF             : 1;
       volatile unsigned      INT2IF             : 1;
       volatile unsigned      T5IF               : 1;
       volatile unsigned      T4IF               : 1;
       volatile unsigned      OC4IF              : 1;
       volatile unsigned      OC3IF              : 1;
       volatile unsigned      DMA2IF             : 1;
       volatile unsigned      IC8IF              : 1;
       volatile unsigned      IC7IF              : 1;
       volatile unsigned      AD2IF              : 1;
       volatile unsigned      INT1IF             : 1;
       volatile unsigned      CNIF               : 1;
                unsigned                         : 1;
       volatile unsigned      MI2C1IF            : 1;
       volatile unsigned      SI2C1IF            : 1;
} IFS1bits @ 0x86;

static volatile unsigned int  IFS2               @ 0x88;
static volatile bit           SPI2EIF            @ ((unsigned)&IFS2*8)+0;
static volatile bit           SPI2IF             @ ((unsigned)&IFS2*8)+1;
static volatile bit           C1RXIF             @ ((unsigned)&IFS2*8)+2;
static volatile bit           C1IF               @ ((unsigned)&IFS2*8)+3;
static volatile bit           DMA3IF             @ ((unsigned)&IFS2*8)+4;
static volatile bit           IC3IF              @ ((unsigned)&IFS2*8)+5;
static volatile bit           IC4IF              @ ((unsigned)&IFS2*8)+6;
static volatile bit           IC5IF              @ ((unsigned)&IFS2*8)+7;
static volatile bit           IC6IF              @ ((unsigned)&IFS2*8)+8;
static volatile bit           OC5IF              @ ((unsigned)&IFS2*8)+9;
static volatile bit           OC6IF              @ ((unsigned)&IFS2*8)+10;
static volatile bit           OC7IF              @ ((unsigned)&IFS2*8)+11;
static volatile bit           OC8IF              @ ((unsigned)&IFS2*8)+12;
static volatile bit           DMA4IF             @ ((unsigned)&IFS2*8)+14;
static volatile bit           T6IF               @ ((unsigned)&IFS2*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      T6IF               : 1;
       volatile unsigned      DMA4IF             : 1;
                unsigned                         : 1;
       volatile unsigned      OC8IF              : 1;
       volatile unsigned      OC7IF              : 1;
       volatile unsigned      OC6IF              : 1;
       volatile unsigned      OC5IF              : 1;
       volatile unsigned      IC6IF              : 1;
       volatile unsigned      IC5IF              : 1;
       volatile unsigned      IC4IF              : 1;
       volatile unsigned      IC3IF              : 1;
       volatile unsigned      DMA3IF             : 1;
       volatile unsigned      C1IF               : 1;
       volatile unsigned      C1RXIF             : 1;
       volatile unsigned      SPI2IF             : 1;
       volatile unsigned      SPI2EIF            : 1;
} IFS2bits @ 0x88;

static volatile unsigned int  IFS3               @ 0x8A;
static volatile bit           T7IF               @ ((unsigned)&IFS3*8)+0;
static volatile bit           SI2C2IF            @ ((unsigned)&IFS3*8)+1;
static volatile bit           MI2C2IF            @ ((unsigned)&IFS3*8)+2;
static volatile bit           T8IF               @ ((unsigned)&IFS3*8)+3;
static volatile bit           T9IF               @ ((unsigned)&IFS3*8)+4;
static volatile bit           INT3IF             @ ((unsigned)&IFS3*8)+5;
static volatile bit           INT4IF             @ ((unsigned)&IFS3*8)+6;
static volatile bit           C2RXIF             @ ((unsigned)&IFS3*8)+7;
static volatile bit           C2IF               @ ((unsigned)&IFS3*8)+8;
static volatile bit           DMA5IF             @ ((unsigned)&IFS3*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      DMA5IF             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      C2IF               : 1;
       volatile unsigned      C2RXIF             : 1;
       volatile unsigned      INT4IF             : 1;
       volatile unsigned      INT3IF             : 1;
       volatile unsigned      T9IF               : 1;
       volatile unsigned      T8IF               : 1;
       volatile unsigned      MI2C2IF            : 1;
       volatile unsigned      SI2C2IF            : 1;
       volatile unsigned      T7IF               : 1;
} IFS3bits @ 0x8A;

static volatile unsigned int  IFS4               @ 0x8C;
static volatile bit           U1EIF              @ ((unsigned)&IFS4*8)+1;
static volatile bit           U2EIF              @ ((unsigned)&IFS4*8)+2;
static volatile bit           DMA6IF             @ ((unsigned)&IFS4*8)+4;
static volatile bit           DMA7IF             @ ((unsigned)&IFS4*8)+5;
static volatile bit           C1TXIF             @ ((unsigned)&IFS4*8)+6;
static volatile bit           C2TXIF             @ ((unsigned)&IFS4*8)+7;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      C2TXIF             : 1;
       volatile unsigned      C1TXIF             : 1;
       volatile unsigned      DMA7IF             : 1;
       volatile unsigned      DMA6IF             : 1;
                unsigned                         : 1;
       volatile unsigned      U2EIF              : 1;
       volatile unsigned      U1EIF              : 1;
                unsigned                         : 1;
} IFS4bits @ 0x8C;

static volatile unsigned int  IEC1               @ 0x96;
static volatile bit           SI2C1IE            @ ((unsigned)&IEC1*8)+0;
static volatile bit           MI2C1IE            @ ((unsigned)&IEC1*8)+1;
static volatile bit           CNIE               @ ((unsigned)&IEC1*8)+3;
static volatile bit           INT1IE             @ ((unsigned)&IEC1*8)+4;
static volatile bit           AD2IE              @ ((unsigned)&IEC1*8)+5;
static volatile bit           IC7IE              @ ((unsigned)&IEC1*8)+6;
static volatile bit           IC8IE              @ ((unsigned)&IEC1*8)+7;
static volatile bit           DMA2IE             @ ((unsigned)&IEC1*8)+8;
static volatile bit           OC3IE              @ ((unsigned)&IEC1*8)+9;
static volatile bit           OC4IE              @ ((unsigned)&IEC1*8)+10;
static volatile bit           T4IE               @ ((unsigned)&IEC1*8)+11;
static volatile bit           T5IE               @ ((unsigned)&IEC1*8)+12;
static volatile bit           INT2IE             @ ((unsigned)&IEC1*8)+13;
static volatile bit           U2RXIE             @ ((unsigned)&IEC1*8)+14;
static volatile bit           U2TXIE             @ ((unsigned)&IEC1*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      U2TXIE             : 1;
       volatile unsigned      U2RXIE             : 1;
       volatile unsigned      INT2IE             : 1;
       volatile unsigned      T5IE               : 1;
       volatile unsigned      T4IE               : 1;
       volatile unsigned      OC4IE              : 1;
       volatile unsigned      OC3IE              : 1;
       volatile unsigned      DMA2IE             : 1;
       volatile unsigned      IC8IE              : 1;
       volatile unsigned      IC7IE              : 1;
       volatile unsigned      AD2IE              : 1;
       volatile unsigned      INT1IE             : 1;
       volatile unsigned      CNIE               : 1;
                unsigned                         : 1;
       volatile unsigned      MI2C1IE            : 1;
       volatile unsigned      SI2C1IE            : 1;
} IEC1bits @ 0x96;

static volatile unsigned int  IEC2               @ 0x98;
static volatile bit           SPI2EIE            @ ((unsigned)&IEC2*8)+0;
static volatile bit           SPI2IE             @ ((unsigned)&IEC2*8)+1;
static volatile bit           C1RXIE             @ ((unsigned)&IEC2*8)+2;
static volatile bit           C1IE               @ ((unsigned)&IEC2*8)+3;
static volatile bit           DMA3IE             @ ((unsigned)&IEC2*8)+4;
static volatile bit           IC3IE              @ ((unsigned)&IEC2*8)+5;
static volatile bit           IC4IE              @ ((unsigned)&IEC2*8)+6;
static volatile bit           IC5IE              @ ((unsigned)&IEC2*8)+7;
static volatile bit           IC6IE              @ ((unsigned)&IEC2*8)+8;
static volatile bit           OC5IE              @ ((unsigned)&IEC2*8)+9;
static volatile bit           OC6IE              @ ((unsigned)&IEC2*8)+10;
static volatile bit           OC7IE              @ ((unsigned)&IEC2*8)+11;
static volatile bit           OC8IE              @ ((unsigned)&IEC2*8)+12;
static volatile bit           DMA4IE             @ ((unsigned)&IEC2*8)+14;
static volatile bit           T6IE               @ ((unsigned)&IEC2*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      T6IE               : 1;
       volatile unsigned      DMA4IE             : 1;
                unsigned                         : 1;
       volatile unsigned      OC8IE              : 1;
       volatile unsigned      OC7IE              : 1;
       volatile unsigned      OC6IE              : 1;
       volatile unsigned      OC5IE              : 1;
       volatile unsigned      IC6IE              : 1;
       volatile unsigned      IC5IE              : 1;
       volatile unsigned      IC4IE              : 1;
       volatile unsigned      IC3IE              : 1;
       volatile unsigned      DMA3IE             : 1;
       volatile unsigned      C1IE               : 1;
       volatile unsigned      C1RXIE             : 1;
       volatile unsigned      SPI2IE             : 1;
       volatile unsigned      SPI2EIE            : 1;
} IEC2bits @ 0x98;

static volatile unsigned int  IEC3               @ 0x9A;
static volatile bit           T7IE               @ ((unsigned)&IEC3*8)+0;
static volatile bit           SI2C2IE            @ ((unsigned)&IEC3*8)+1;
static volatile bit           MI2C2IE            @ ((unsigned)&IEC3*8)+2;
static volatile bit           T8IE               @ ((unsigned)&IEC3*8)+3;
static volatile bit           T9IE               @ ((unsigned)&IEC3*8)+4;
static volatile bit           INT3IE             @ ((unsigned)&IEC3*8)+5;
static volatile bit           INT4IE             @ ((unsigned)&IEC3*8)+6;
static volatile bit           C2RXIE             @ ((unsigned)&IEC3*8)+7;
static volatile bit           C2IE               @ ((unsigned)&IEC3*8)+8;
static volatile bit           DMA5IE             @ ((unsigned)&IEC3*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      DMA5IE             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      C2IE               : 1;
       volatile unsigned      C2RXIE             : 1;
       volatile unsigned      INT4IE             : 1;
       volatile unsigned      INT3IE             : 1;
       volatile unsigned      T9IE               : 1;
       volatile unsigned      T8IE               : 1;
       volatile unsigned      MI2C2IE            : 1;
       volatile unsigned      SI2C2IE            : 1;
       volatile unsigned      T7IE               : 1;
} IEC3bits @ 0x9A;

static volatile unsigned int  IEC4               @ 0x9C;
static volatile bit           U1EIE              @ ((unsigned)&IEC4*8)+1;
static volatile bit           U2EIE              @ ((unsigned)&IEC4*8)+2;
static volatile bit           DMA6IE             @ ((unsigned)&IEC4*8)+4;
static volatile bit           DMA7IE             @ ((unsigned)&IEC4*8)+5;
static volatile bit           C1TXIE             @ ((unsigned)&IEC4*8)+6;
static volatile bit           C2TXIE             @ ((unsigned)&IEC4*8)+7;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      C2TXIE             : 1;
       volatile unsigned      C1TXIE             : 1;
       volatile unsigned      DMA7IE             : 1;
       volatile unsigned      DMA6IE             : 1;
                unsigned                         : 1;
       volatile unsigned      U2EIE              : 1;
       volatile unsigned      U1EIE              : 1;
                unsigned                         : 1;
} IEC4bits @ 0x9C;

static volatile unsigned int  IPC5               @ 0xAE;
static volatile bit           INT1IP0            @ ((unsigned)&IPC5*8)+0;
static volatile bit           INT1IP1            @ ((unsigned)&IPC5*8)+1;
static volatile bit           INT1IP2            @ ((unsigned)&IPC5*8)+2;
static volatile bit           AD2IP0             @ ((unsigned)&IPC5*8)+4;
static volatile bit           AD2IP1             @ ((unsigned)&IPC5*8)+5;
static volatile bit           AD2IP2             @ ((unsigned)&IPC5*8)+6;
static volatile bit           IC7IP0             @ ((unsigned)&IPC5*8)+8;
static volatile bit           IC7IP1             @ ((unsigned)&IPC5*8)+9;
static volatile bit           IC7IP2             @ ((unsigned)&IPC5*8)+10;
static volatile bit           IC8IP0             @ ((unsigned)&IPC5*8)+12;
static volatile bit           IC8IP1             @ ((unsigned)&IPC5*8)+13;
static volatile bit           IC8IP2             @ ((unsigned)&IPC5*8)+14;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
       volatile unsigned      IC8IP              : 3;
                unsigned                         : 1;
       volatile unsigned      IC7IP              : 3;
                unsigned                         : 1;
       volatile unsigned      AD2IP              : 3;
                unsigned                         : 1;
       volatile unsigned      INT1IP             : 3;
} IPC5bits @ 0xAE;

static volatile unsigned int  IPC8               @ 0xB4;
static volatile bit           SPI2EIP0           @ ((unsigned)&IPC8*8)+0;
static volatile bit           SPI2EIP1           @ ((unsigned)&IPC8*8)+1;
static volatile bit           SPI2EIP2           @ ((unsigned)&IPC8*8)+2;
static volatile bit           SPI2IP0            @ ((unsigned)&IPC8*8)+4;
static volatile bit           SPI2IP1            @ ((unsigned)&IPC8*8)+5;
static volatile bit           SPI2IP2            @ ((unsigned)&IPC8*8)+6;
static volatile bit           C1RXIP0            @ ((unsigned)&IPC8*8)+8;
static volatile bit           C1RXIP1            @ ((unsigned)&IPC8*8)+9;
static volatile bit           C1RXIP2            @ ((unsigned)&IPC8*8)+10;
static volatile bit           C1IP0              @ ((unsigned)&IPC8*8)+12;
static volatile bit           C1IP1              @ ((unsigned)&IPC8*8)+13;
static volatile bit           C1IP2              @ ((unsigned)&IPC8*8)+14;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
       volatile unsigned      C1IP               : 3;
                unsigned                         : 1;
       volatile unsigned      C1RXIP             : 3;
                unsigned                         : 1;
       volatile unsigned      SPI2IP             : 3;
                unsigned                         : 1;
       volatile unsigned      SPI2EIP            : 3;
} IPC8bits @ 0xB4;

static volatile unsigned int  IPC10              @ 0xB8;
static volatile bit           IC6IP0             @ ((unsigned)&IPC10*8)+0;
static volatile bit           IC6IP1             @ ((unsigned)&IPC10*8)+1;
static volatile bit           IC6IP2             @ ((unsigned)&IPC10*8)+2;
static volatile bit           OC5IP0             @ ((unsigned)&IPC10*8)+4;
static volatile bit           OC5IP1             @ ((unsigned)&IPC10*8)+5;
static volatile bit           OC5IP2             @ ((unsigned)&IPC10*8)+6;
static volatile bit           OC6IP0             @ ((unsigned)&IPC10*8)+8;
static volatile bit           OC6IP1             @ ((unsigned)&IPC10*8)+9;
static volatile bit           OC6IP2             @ ((unsigned)&IPC10*8)+10;
static volatile bit           OC7IP0             @ ((unsigned)&IPC10*8)+12;
static volatile bit           OC7IP1             @ ((unsigned)&IPC10*8)+13;
static volatile bit           OC7IP2             @ ((unsigned)&IPC10*8)+14;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
       volatile unsigned      OC7IP              : 3;
                unsigned                         : 1;
       volatile unsigned      OC6IP              : 3;
                unsigned                         : 1;
       volatile unsigned      OC5IP              : 3;
                unsigned                         : 1;
       volatile unsigned      IC6IP              : 3;
} IPC10bits @ 0xB8;

static volatile unsigned int  IPC11              @ 0xBA;
static volatile bit           OC8IP0             @ ((unsigned)&IPC11*8)+0;
static volatile bit           OC8IP1             @ ((unsigned)&IPC11*8)+1;
static volatile bit           OC8IP2             @ ((unsigned)&IPC11*8)+2;
static volatile bit           DMA4IP0            @ ((unsigned)&IPC11*8)+8;
static volatile bit           DMA4IP1            @ ((unsigned)&IPC11*8)+9;
static volatile bit           DMA4IP2            @ ((unsigned)&IPC11*8)+10;
static volatile bit           T6IP0              @ ((unsigned)&IPC11*8)+12;
static volatile bit           T6IP1              @ ((unsigned)&IPC11*8)+13;
static volatile bit           T6IP2              @ ((unsigned)&IPC11*8)+14;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
       volatile unsigned      T6IP               : 3;
                unsigned                         : 1;
       volatile unsigned      DMA4IP             : 3;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      OC8IP              : 3;
} IPC11bits @ 0xBA;

static volatile unsigned int  IPC12              @ 0xBC;
static volatile bit           T7IP0              @ ((unsigned)&IPC12*8)+0;
static volatile bit           T7IP1              @ ((unsigned)&IPC12*8)+1;
static volatile bit           T7IP2              @ ((unsigned)&IPC12*8)+2;
static volatile bit           SI2C2IP0           @ ((unsigned)&IPC12*8)+4;
static volatile bit           SI2C2IP1           @ ((unsigned)&IPC12*8)+5;
static volatile bit           SI2C2IP2           @ ((unsigned)&IPC12*8)+6;
static volatile bit           MI2C2IP0           @ ((unsigned)&IPC12*8)+8;
static volatile bit           MI2C2IP1           @ ((unsigned)&IPC12*8)+9;
static volatile bit           MI2C2IP2           @ ((unsigned)&IPC12*8)+10;
static volatile bit           T8IP0              @ ((unsigned)&IPC12*8)+12;
static volatile bit           T8IP1              @ ((unsigned)&IPC12*8)+13;
static volatile bit           T8IP2              @ ((unsigned)&IPC12*8)+14;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
       volatile unsigned      T8IP               : 3;
                unsigned                         : 1;
       volatile unsigned      MI2C2IP            : 3;
                unsigned                         : 1;
       volatile unsigned      SI2C2IP            : 3;
                unsigned                         : 1;
       volatile unsigned      T7IP               : 3;
} IPC12bits @ 0xBC;

static volatile unsigned int  IPC13              @ 0xBE;
static volatile bit           T9IP0              @ ((unsigned)&IPC13*8)+0;
static volatile bit           T9IP1              @ ((unsigned)&IPC13*8)+1;
static volatile bit           T9IP2              @ ((unsigned)&IPC13*8)+2;
static volatile bit           INT3IP0            @ ((unsigned)&IPC13*8)+4;
static volatile bit           INT3IP1            @ ((unsigned)&IPC13*8)+5;
static volatile bit           INT3IP2            @ ((unsigned)&IPC13*8)+6;
static volatile bit           INT4IP0            @ ((unsigned)&IPC13*8)+8;
static volatile bit           INT4IP1            @ ((unsigned)&IPC13*8)+9;
static volatile bit           INT4IP2            @ ((unsigned)&IPC13*8)+10;
static volatile bit           C2RXIP0            @ ((unsigned)&IPC13*8)+12;
static volatile bit           C2RXIP1            @ ((unsigned)&IPC13*8)+13;
static volatile bit           C2RXIP2            @ ((unsigned)&IPC13*8)+14;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
       volatile unsigned      C2RXIP             : 3;
                unsigned                         : 1;
       volatile unsigned      INT4IP             : 3;
                unsigned                         : 1;
       volatile unsigned      INT3IP             : 3;
                unsigned                         : 1;
       volatile unsigned      T9IP               : 3;
} IPC13bits @ 0xBE;

static volatile unsigned int  IPC14              @ 0xC0;
static volatile unsigned int  IPC17              @ 0xC6;
static volatile bit           DMA6IP0            @ ((unsigned)&IPC17*8)+0;
static volatile bit           DMA6IP1            @ ((unsigned)&IPC17*8)+1;
static volatile bit           DMA6IP2            @ ((unsigned)&IPC17*8)+2;
static volatile bit           DMA7IP0            @ ((unsigned)&IPC17*8)+4;
static volatile bit           DMA7IP1            @ ((unsigned)&IPC17*8)+5;
static volatile bit           DMA7IP2            @ ((unsigned)&IPC17*8)+6;
static volatile bit           C1TXIP0            @ ((unsigned)&IPC17*8)+8;
static volatile bit           C1TXIP1            @ ((unsigned)&IPC17*8)+9;
static volatile bit           C1TXIP2            @ ((unsigned)&IPC17*8)+10;
static volatile bit           C2TXIP0            @ ((unsigned)&IPC17*8)+12;
static volatile bit           C2TXIP1            @ ((unsigned)&IPC17*8)+13;
static volatile bit           C2TXIP2            @ ((unsigned)&IPC17*8)+14;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
       volatile unsigned      C2TXIP             : 3;
                unsigned                         : 1;
       volatile unsigned      C1TXIP             : 3;
                unsigned                         : 1;
       volatile unsigned      DMA7IP             : 3;
                unsigned                         : 1;
       volatile unsigned      DMA6IP             : 3;
} IPC17bits @ 0xC6;

static volatile unsigned int  TMR1               @ 0x100;
static volatile unsigned int  PR1                @ 0x102;
static volatile unsigned int  T1CON              @ 0x104;
static volatile bit           T1CS               @ ((unsigned)&T1CON*8)+1;
static volatile bit           T1SYNC             @ ((unsigned)&T1CON*8)+2;
static volatile bit           T1CKPS0            @ ((unsigned)&T1CON*8)+4;
static volatile bit           T1CKPS1            @ ((unsigned)&T1CON*8)+5;
static volatile bit           T1GATE             @ ((unsigned)&T1CON*8)+6;
static volatile bit           T1SIDL             @ ((unsigned)&T1CON*8)+13;
static volatile bit           T1ON               @ ((unsigned)&T1CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      T1ON               : 1;
                unsigned                         : 1;
       volatile unsigned      T1SIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      T1GATE             : 1;
       volatile unsigned      T1CKPS             : 2;
                unsigned                         : 1;
       volatile unsigned      T1SYNC             : 1;
       volatile unsigned      T1CS               : 1;
                unsigned                         : 1;
} T1CONbits @ 0x104;

static volatile unsigned int  TMR2               @ 0x106;
static volatile unsigned int  TMR3HLD            @ 0x108;
static volatile unsigned int  TMR3               @ 0x10A;
static volatile unsigned int  PR2                @ 0x10C;
static volatile unsigned int  PR3                @ 0x10E;
static volatile unsigned int  T2CON              @ 0x110;
static volatile bit           T2CS               @ ((unsigned)&T2CON*8)+1;
static volatile bit           T2T32              @ ((unsigned)&T2CON*8)+3;
static volatile bit           T2CKPS0            @ ((unsigned)&T2CON*8)+4;
static volatile bit           T2CKPS1            @ ((unsigned)&T2CON*8)+5;
static volatile bit           T2GATE             @ ((unsigned)&T2CON*8)+6;
static volatile bit           T2SIDL             @ ((unsigned)&T2CON*8)+13;
static volatile bit           T2ON               @ ((unsigned)&T2CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      T2ON               : 1;
                unsigned                         : 1;
       volatile unsigned      T2SIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      T2GATE             : 1;
       volatile unsigned      T2CKPS             : 2;
       volatile unsigned      T32                : 1;
                unsigned                         : 1;
       volatile unsigned      T2CS               : 1;
                unsigned                         : 1;
} T2CONbits @ 0x110;

static volatile unsigned int  T3CON              @ 0x112;
static volatile bit           T3CS               @ ((unsigned)&T3CON*8)+1;
static volatile bit           T3CKPS0            @ ((unsigned)&T3CON*8)+4;
static volatile bit           T3CKPS1            @ ((unsigned)&T3CON*8)+5;
static volatile bit           T3GATE             @ ((unsigned)&T3CON*8)+6;
static volatile bit           T3SIDL             @ ((unsigned)&T3CON*8)+13;
static volatile bit           T3ON               @ ((unsigned)&T3CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      T3ON               : 1;
                unsigned                         : 1;
       volatile unsigned      T3SIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      T3GATE             : 1;
       volatile unsigned      T3CKPS             : 2;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      T3CS               : 1;
                unsigned                         : 1;
} T3CONbits @ 0x112;

static volatile unsigned int  TMR4               @ 0x114;
static volatile unsigned int  TMR5HLD            @ 0x116;
static volatile unsigned int  TMR5               @ 0x118;
static volatile unsigned int  PR4                @ 0x11A;
static volatile unsigned int  PR5                @ 0x11C;
static volatile unsigned int  T4CON              @ 0x11E;
static volatile bit           T4CS               @ ((unsigned)&T4CON*8)+1;
static volatile bit           T4T45              @ ((unsigned)&T4CON*8)+3;
static volatile bit           T4CKPS0            @ ((unsigned)&T4CON*8)+4;
static volatile bit           T4CKPS1            @ ((unsigned)&T4CON*8)+5;
static volatile bit           T4GATE             @ ((unsigned)&T4CON*8)+6;
static volatile bit           T4SIDL             @ ((unsigned)&T4CON*8)+13;
static volatile bit           T4ON               @ ((unsigned)&T4CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      T4ON               : 1;
                unsigned                         : 1;
       volatile unsigned      T4SIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      T4GATE             : 1;
       volatile unsigned      T4CKPS             : 2;
       volatile unsigned      T45                : 1;
                unsigned                         : 1;
       volatile unsigned      T4CS               : 1;
                unsigned                         : 1;
} T4CONbits @ 0x11E;

static volatile unsigned int  T5CON              @ 0x120;
static volatile bit           T5CS               @ ((unsigned)&T5CON*8)+1;
static volatile bit           T5CKPS0            @ ((unsigned)&T5CON*8)+4;
static volatile bit           T5CKPS1            @ ((unsigned)&T5CON*8)+5;
static volatile bit           T5GATE             @ ((unsigned)&T5CON*8)+6;
static volatile bit           T5SIDL             @ ((unsigned)&T5CON*8)+13;
static volatile bit           T5ON               @ ((unsigned)&T5CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      T5ON               : 1;
                unsigned                         : 1;
       volatile unsigned      T5SIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      T5GATE             : 1;
       volatile unsigned      T5CKPS             : 2;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      T5CS               : 1;
                unsigned                         : 1;
} T5CONbits @ 0x120;

static volatile unsigned int  TMR6               @ 0x122;
static volatile unsigned int  TMR7HLD            @ 0x124;
static volatile unsigned int  TMR7               @ 0x126;
static volatile unsigned int  PR6                @ 0x128;
static volatile unsigned int  PR7                @ 0x12A;
static volatile unsigned int  T6CON              @ 0x12C;
static volatile bit           T6CS               @ ((unsigned)&T6CON*8)+1;
static volatile bit           T6T67              @ ((unsigned)&T6CON*8)+3;
static volatile bit           T6CKPS0            @ ((unsigned)&T6CON*8)+4;
static volatile bit           T6CKPS1            @ ((unsigned)&T6CON*8)+5;
static volatile bit           T6GATE             @ ((unsigned)&T6CON*8)+6;
static volatile bit           T6SIDL             @ ((unsigned)&T6CON*8)+13;
static volatile bit           T6ON               @ ((unsigned)&T6CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      T6ON               : 1;
                unsigned                         : 1;
       volatile unsigned      T6SIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      T6GATE             : 1;
       volatile unsigned      T6CKPS             : 2;
       volatile unsigned      T67                : 1;
                unsigned                         : 1;
       volatile unsigned      T6CS               : 1;
                unsigned                         : 1;
} T6CONbits @ 0x12C;

static volatile unsigned int  T7CON              @ 0x12E;
static volatile bit           T7CS               @ ((unsigned)&T7CON*8)+1;
static volatile bit           T7CKPS0            @ ((unsigned)&T7CON*8)+4;
static volatile bit           T7CKPS1            @ ((unsigned)&T7CON*8)+5;
static volatile bit           T7GATE             @ ((unsigned)&T7CON*8)+6;
static volatile bit           T7SIDL             @ ((unsigned)&T7CON*8)+13;
static volatile bit           T7ON               @ ((unsigned)&T7CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      T7ON               : 1;
                unsigned                         : 1;
       volatile unsigned      T7SIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      T7GATE             : 1;
       volatile unsigned      T7CKPS             : 2;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      T7CS               : 1;
                unsigned                         : 1;
} T7CONbits @ 0x12E;

static volatile unsigned int  TMR8               @ 0x130;
static volatile unsigned int  TMR9HLD            @ 0x132;
static volatile unsigned int  TMR9               @ 0x134;
static volatile unsigned int  PR8                @ 0x136;
static volatile unsigned int  PR9                @ 0x138;
static volatile unsigned int  T8CON              @ 0x13A;
static volatile bit           T8CS               @ ((unsigned)&T8CON*8)+1;
static volatile bit           T8T89              @ ((unsigned)&T8CON*8)+3;
static volatile bit           T8CKPS0            @ ((unsigned)&T8CON*8)+4;
static volatile bit           T8CKPS1            @ ((unsigned)&T8CON*8)+5;
static volatile bit           T8GATE             @ ((unsigned)&T8CON*8)+6;
static volatile bit           T8SIDL             @ ((unsigned)&T8CON*8)+13;
static volatile bit           T8ON               @ ((unsigned)&T8CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      T8ON               : 1;
                unsigned                         : 1;
       volatile unsigned      T8SIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      T8GATE             : 1;
       volatile unsigned      T8CKPS             : 2;
       volatile unsigned      T89                : 1;
                unsigned                         : 1;
       volatile unsigned      T8CS               : 1;
                unsigned                         : 1;
} T8CONbits @ 0x13A;

static volatile unsigned int  T9CON              @ 0x13C;
static volatile bit           T9CS               @ ((unsigned)&T9CON*8)+1;
static volatile bit           T9CKPS0            @ ((unsigned)&T9CON*8)+4;
static volatile bit           T9CKPS1            @ ((unsigned)&T9CON*8)+5;
static volatile bit           T9GATE             @ ((unsigned)&T9CON*8)+6;
static volatile bit           T9SIDL             @ ((unsigned)&T9CON*8)+13;
static volatile bit           T9ON               @ ((unsigned)&T9CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      T9ON               : 1;
                unsigned                         : 1;
       volatile unsigned      T9SIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      T9GATE             : 1;
       volatile unsigned      T9CKPS             : 2;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      T9CS               : 1;
                unsigned                         : 1;
} T9CONbits @ 0x13C;

static volatile unsigned int  IC1BUF             @ 0x140;
static volatile unsigned int  IC1CON             @ 0x142;
static volatile bit           IC1_M0             @ ((unsigned)&IC1CON*8)+0;
static volatile bit           IC1_M1             @ ((unsigned)&IC1CON*8)+1;
static volatile bit           IC1_M2             @ ((unsigned)&IC1CON*8)+2;
static volatile bit           IC1_BNE            @ ((unsigned)&IC1CON*8)+3;
static volatile bit           IC1_OV             @ ((unsigned)&IC1CON*8)+4;
static volatile bit           IC1_I0             @ ((unsigned)&IC1CON*8)+5;
static volatile bit           IC1_I1             @ ((unsigned)&IC1CON*8)+6;
static volatile bit           IC1_TMR            @ ((unsigned)&IC1CON*8)+7;
static volatile bit           IC1_SIDL           @ ((unsigned)&IC1CON*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      ICSIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      ICTMR              : 1;
       volatile unsigned      ICI                : 2;
       volatile unsigned      ICOV               : 1;
       volatile unsigned      ICBNE              : 1;
       volatile unsigned      ICM                : 3;
} IC1CONbits @ 0x142;

static volatile unsigned int  IC2BUF             @ 0x144;
static volatile unsigned int  IC2CON             @ 0x146;
static volatile bit           IC2_M0             @ ((unsigned)&IC2CON*8)+0;
static volatile bit           IC2_M1             @ ((unsigned)&IC2CON*8)+1;
static volatile bit           IC2_M2             @ ((unsigned)&IC2CON*8)+2;
static volatile bit           IC2_BNE            @ ((unsigned)&IC2CON*8)+3;
static volatile bit           IC2_OV             @ ((unsigned)&IC2CON*8)+4;
static volatile bit           IC2_I0             @ ((unsigned)&IC2CON*8)+5;
static volatile bit           IC2_I1             @ ((unsigned)&IC2CON*8)+6;
static volatile bit           IC2_TMR            @ ((unsigned)&IC2CON*8)+7;
static volatile bit           IC2_SIDL           @ ((unsigned)&IC2CON*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      ICSIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      ICTMR              : 1;
       volatile unsigned      ICI                : 2;
       volatile unsigned      ICOV               : 1;
       volatile unsigned      ICBNE              : 1;
       volatile unsigned      ICM                : 3;
} IC2CONbits @ 0x146;

static volatile unsigned int  IC3BUF             @ 0x148;
static volatile unsigned int  IC3CON             @ 0x14A;
static volatile bit           IC3_M0             @ ((unsigned)&IC3CON*8)+0;
static volatile bit           IC3_M1             @ ((unsigned)&IC3CON*8)+1;
static volatile bit           IC3_M2             @ ((unsigned)&IC3CON*8)+2;
static volatile bit           IC3_BNE            @ ((unsigned)&IC3CON*8)+3;
static volatile bit           IC3_OV             @ ((unsigned)&IC3CON*8)+4;
static volatile bit           IC3_I0             @ ((unsigned)&IC3CON*8)+5;
static volatile bit           IC3_I1             @ ((unsigned)&IC3CON*8)+6;
static volatile bit           IC3_TMR            @ ((unsigned)&IC3CON*8)+7;
static volatile bit           IC3_SIDL           @ ((unsigned)&IC3CON*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      ICSIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      ICTMR              : 1;
       volatile unsigned      ICI                : 2;
       volatile unsigned      ICOV               : 1;
       volatile unsigned      ICBNE              : 1;
       volatile unsigned      ICM                : 3;
} IC3CONbits @ 0x14A;

static volatile unsigned int  IC4BUF             @ 0x14C;
static volatile unsigned int  IC4CON             @ 0x14E;
static volatile bit           IC4_M0             @ ((unsigned)&IC4CON*8)+0;
static volatile bit           IC4_M1             @ ((unsigned)&IC4CON*8)+1;
static volatile bit           IC4_M2             @ ((unsigned)&IC4CON*8)+2;
static volatile bit           IC4_BNE            @ ((unsigned)&IC4CON*8)+3;
static volatile bit           IC4_OV             @ ((unsigned)&IC4CON*8)+4;
static volatile bit           IC4_I0             @ ((unsigned)&IC4CON*8)+5;
static volatile bit           IC4_I1             @ ((unsigned)&IC4CON*8)+6;
static volatile bit           IC4_TMR            @ ((unsigned)&IC4CON*8)+7;
static volatile bit           IC4_SIDL           @ ((unsigned)&IC4CON*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      ICSIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      ICTMR              : 1;
       volatile unsigned      ICI                : 2;
       volatile unsigned      ICOV               : 1;
       volatile unsigned      ICBNE              : 1;
       volatile unsigned      ICM                : 3;
} IC4CONbits @ 0x14E;

static volatile unsigned int  IC5BUF             @ 0x150;
static volatile unsigned int  IC5CON             @ 0x152;
static volatile bit           IC5_M0             @ ((unsigned)&IC5CON*8)+0;
static volatile bit           IC5_M1             @ ((unsigned)&IC5CON*8)+1;
static volatile bit           IC5_M2             @ ((unsigned)&IC5CON*8)+2;
static volatile bit           IC5_BNE            @ ((unsigned)&IC5CON*8)+3;
static volatile bit           IC5_OV             @ ((unsigned)&IC5CON*8)+4;
static volatile bit           IC5_I0             @ ((unsigned)&IC5CON*8)+5;
static volatile bit           IC5_I1             @ ((unsigned)&IC5CON*8)+6;
static volatile bit           IC5_TMR            @ ((unsigned)&IC5CON*8)+7;
static volatile bit           IC5_SIDL           @ ((unsigned)&IC5CON*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      ICSIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      ICTMR              : 1;
       volatile unsigned      ICI                : 2;
       volatile unsigned      ICOV               : 1;
       volatile unsigned      ICBNE              : 1;
       volatile unsigned      ICM                : 3;
} IC5CONbits @ 0x152;

static volatile unsigned int  IC6BUF             @ 0x154;
static volatile unsigned int  IC6CON             @ 0x156;
static volatile bit           IC6_M0             @ ((unsigned)&IC6CON*8)+0;
static volatile bit           IC6_M1             @ ((unsigned)&IC6CON*8)+1;
static volatile bit           IC6_M2             @ ((unsigned)&IC6CON*8)+2;
static volatile bit           IC6_BNE            @ ((unsigned)&IC6CON*8)+3;
static volatile bit           IC6_OV             @ ((unsigned)&IC6CON*8)+4;
static volatile bit           IC6_I0             @ ((unsigned)&IC6CON*8)+5;
static volatile bit           IC6_I1             @ ((unsigned)&IC6CON*8)+6;
static volatile bit           IC6_TMR            @ ((unsigned)&IC6CON*8)+7;
static volatile bit           IC6_SIDL           @ ((unsigned)&IC6CON*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      ICSIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      ICTMR              : 1;
       volatile unsigned      ICI                : 2;
       volatile unsigned      ICOV               : 1;
       volatile unsigned      ICBNE              : 1;
       volatile unsigned      ICM                : 3;
} IC6CONbits @ 0x156;

static volatile unsigned int  IC7BUF             @ 0x158;
static volatile unsigned int  IC7CON             @ 0x15A;
static volatile bit           IC7_M0             @ ((unsigned)&IC7CON*8)+0;
static volatile bit           IC7_M1             @ ((unsigned)&IC7CON*8)+1;
static volatile bit           IC7_M2             @ ((unsigned)&IC7CON*8)+2;
static volatile bit           IC7_BNE            @ ((unsigned)&IC7CON*8)+3;
static volatile bit           IC7_OV             @ ((unsigned)&IC7CON*8)+4;
static volatile bit           IC7_I0             @ ((unsigned)&IC7CON*8)+5;
static volatile bit           IC7_I1             @ ((unsigned)&IC7CON*8)+6;
static volatile bit           IC7_TMR            @ ((unsigned)&IC7CON*8)+7;
static volatile bit           IC7_SIDL           @ ((unsigned)&IC7CON*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      ICSIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      ICTMR              : 1;
       volatile unsigned      ICI                : 2;
       volatile unsigned      ICOV               : 1;
       volatile unsigned      ICBNE              : 1;
       volatile unsigned      ICM                : 3;
} IC7CONbits @ 0x15A;

static volatile unsigned int  IC8BUF             @ 0x15C;
static volatile unsigned int  IC8CON             @ 0x15E;
static volatile bit           IC8_M0             @ ((unsigned)&IC8CON*8)+0;
static volatile bit           IC8_M1             @ ((unsigned)&IC8CON*8)+1;
static volatile bit           IC8_M2             @ ((unsigned)&IC8CON*8)+2;
static volatile bit           IC8_BNE            @ ((unsigned)&IC8CON*8)+3;
static volatile bit           IC8_OV             @ ((unsigned)&IC8CON*8)+4;
static volatile bit           IC8_I0             @ ((unsigned)&IC8CON*8)+5;
static volatile bit           IC8_I1             @ ((unsigned)&IC8CON*8)+6;
static volatile bit           IC8_TMR            @ ((unsigned)&IC8CON*8)+7;
static volatile bit           IC8_SIDL           @ ((unsigned)&IC8CON*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      ICSIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      ICTMR              : 1;
       volatile unsigned      ICI                : 2;
       volatile unsigned      ICOV               : 1;
       volatile unsigned      ICBNE              : 1;
       volatile unsigned      ICM                : 3;
} IC8CONbits @ 0x15E;

static volatile unsigned int  OC1RS              @ 0x180;
static volatile unsigned int  OC1R               @ 0x182;
static volatile unsigned int  OC1CON             @ 0x184;
static volatile bit           OC1_M0             @ ((unsigned)&OC1CON*8)+0;
static volatile bit           OC1_M1             @ ((unsigned)&OC1CON*8)+1;
static volatile bit           OC1_M2             @ ((unsigned)&OC1CON*8)+2;
static volatile bit           OC1_TSEL           @ ((unsigned)&OC1CON*8)+3;
static volatile bit           OC1_FLT            @ ((unsigned)&OC1CON*8)+4;
static volatile bit           OC1_SIDL           @ ((unsigned)&OC1CON*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      OCSIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      OCFLT1             : 1;
       volatile unsigned      OCTSEL1            : 1;
       volatile unsigned      OCM                : 3;
} OC1CONbits @ 0x184;

static volatile unsigned int  OC2RS              @ 0x186;
static volatile unsigned int  OC2R               @ 0x188;
static volatile unsigned int  OC2CON             @ 0x18A;
static volatile bit           OC2_M0             @ ((unsigned)&OC2CON*8)+0;
static volatile bit           OC2_M1             @ ((unsigned)&OC2CON*8)+1;
static volatile bit           OC2_M2             @ ((unsigned)&OC2CON*8)+2;
static volatile bit           OC2_TSEL           @ ((unsigned)&OC2CON*8)+3;
static volatile bit           OC2_FLT            @ ((unsigned)&OC2CON*8)+4;
static volatile bit           OC2_SIDL           @ ((unsigned)&OC2CON*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      OCSIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      OCFLT2             : 1;
       volatile unsigned      OCTSEL2            : 1;
       volatile unsigned      OCM                : 3;
} OC2CONbits @ 0x18A;

static volatile unsigned int  OC3RS              @ 0x18C;
static volatile unsigned int  OC3R               @ 0x18E;
static volatile unsigned int  OC3CON             @ 0x190;
static volatile bit           OC3_M0             @ ((unsigned)&OC3CON*8)+0;
static volatile bit           OC3_M1             @ ((unsigned)&OC3CON*8)+1;
static volatile bit           OC3_M2             @ ((unsigned)&OC3CON*8)+2;
static volatile bit           OC3_TSEL           @ ((unsigned)&OC3CON*8)+3;
static volatile bit           OC3_FLT            @ ((unsigned)&OC3CON*8)+4;
static volatile bit           OC3_SIDL           @ ((unsigned)&OC3CON*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      OCSIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      OCFLT3             : 1;
       volatile unsigned      OCTSEL3            : 1;
       volatile unsigned      OCM                : 3;
} OC3CONbits @ 0x190;

static volatile unsigned int  OC4RS              @ 0x192;
static volatile unsigned int  OC4R               @ 0x194;
static volatile unsigned int  OC4CON             @ 0x196;
static volatile bit           OC4_M0             @ ((unsigned)&OC4CON*8)+0;
static volatile bit           OC4_M1             @ ((unsigned)&OC4CON*8)+1;
static volatile bit           OC4_M2             @ ((unsigned)&OC4CON*8)+2;
static volatile bit           OC4_TSEL           @ ((unsigned)&OC4CON*8)+3;
static volatile bit           OC4_FLT            @ ((unsigned)&OC4CON*8)+4;
static volatile bit           OC4_SIDL           @ ((unsigned)&OC4CON*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      OCSIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      OCFLT4             : 1;
       volatile unsigned      OCTSEL4            : 1;
       volatile unsigned      OCM                : 3;
} OC4CONbits @ 0x196;

static volatile unsigned int  OC5RS              @ 0x198;
static volatile unsigned int  OC5R               @ 0x19A;
static volatile unsigned int  OC5CON             @ 0x19C;
static volatile bit           OC5_M0             @ ((unsigned)&OC5CON*8)+0;
static volatile bit           OC5_M1             @ ((unsigned)&OC5CON*8)+1;
static volatile bit           OC5_M2             @ ((unsigned)&OC5CON*8)+2;
static volatile bit           OC5_TSEL           @ ((unsigned)&OC5CON*8)+3;
static volatile bit           OC5_FLT            @ ((unsigned)&OC5CON*8)+4;
static volatile bit           OC5_SIDL           @ ((unsigned)&OC5CON*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      OCSIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      OCFLT5             : 1;
       volatile unsigned      OCTSEL5            : 1;
       volatile unsigned      OCM                : 3;
} OC5CONbits @ 0x19C;

static volatile unsigned int  OC6RS              @ 0x19E;
static volatile unsigned int  OC6R               @ 0x1A0;
static volatile unsigned int  OC6CON             @ 0x1A2;
static volatile bit           OC6_M0             @ ((unsigned)&OC6CON*8)+0;
static volatile bit           OC6_M1             @ ((unsigned)&OC6CON*8)+1;
static volatile bit           OC6_M2             @ ((unsigned)&OC6CON*8)+2;
static volatile bit           OC6_TSEL           @ ((unsigned)&OC6CON*8)+3;
static volatile bit           OC6_FLT            @ ((unsigned)&OC6CON*8)+4;
static volatile bit           OC6_SIDL           @ ((unsigned)&OC6CON*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      OCSIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      OCFLT              : 1;
       volatile unsigned      OCTSEL             : 1;
       volatile unsigned      OCM                : 3;
} OC6CONbits @ 0x1A2;

static volatile unsigned int  OC7RS              @ 0x1A4;
static volatile unsigned int  OC7R               @ 0x1A6;
static volatile unsigned int  OC7CON             @ 0x1A8;
static volatile bit           OC7_M0             @ ((unsigned)&OC7CON*8)+0;
static volatile bit           OC7_M1             @ ((unsigned)&OC7CON*8)+1;
static volatile bit           OC7_M2             @ ((unsigned)&OC7CON*8)+2;
static volatile bit           OC7_TSEL           @ ((unsigned)&OC7CON*8)+3;
static volatile bit           OC7_FLT            @ ((unsigned)&OC7CON*8)+4;
static volatile bit           OC7_SIDL           @ ((unsigned)&OC7CON*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      OCSIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      OCFLT              : 1;
       volatile unsigned      OCTSEL             : 1;
       volatile unsigned      OCM                : 3;
} OC7CONbits @ 0x1A8;

static volatile unsigned int  OC8RS              @ 0x1AA;
static volatile unsigned int  OC8R               @ 0x1AC;
static volatile unsigned int  OC8CON             @ 0x1AE;
static volatile bit           OC8_M0             @ ((unsigned)&OC8CON*8)+0;
static volatile bit           OC8_M1             @ ((unsigned)&OC8CON*8)+1;
static volatile bit           OC8_M2             @ ((unsigned)&OC8CON*8)+2;
static volatile bit           OC8_TSEL           @ ((unsigned)&OC8CON*8)+3;
static volatile bit           OC8_FLT            @ ((unsigned)&OC8CON*8)+4;
static volatile bit           OC8_SIDL           @ ((unsigned)&OC8CON*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      OCSIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      OCFLT              : 1;
       volatile unsigned      OCTSEL             : 1;
       volatile unsigned      OCM                : 3;
} OC8CONbits @ 0x1AE;

static volatile unsigned int  I2C1RCV            @ 0x200;
static volatile unsigned int  I2C1TRN            @ 0x202;
static volatile unsigned int  I2C1BRG            @ 0x204;
static volatile unsigned int  I2C1CON            @ 0x206;
static volatile bit           I2C1_SEN           @ ((unsigned)&I2C1CON*8)+0;
static volatile bit           I2C1_RSEN          @ ((unsigned)&I2C1CON*8)+1;
static volatile bit           I2C1_PEN           @ ((unsigned)&I2C1CON*8)+2;
static volatile bit           I2C1_RCEN          @ ((unsigned)&I2C1CON*8)+3;
static volatile bit           I2C1_ACKEN         @ ((unsigned)&I2C1CON*8)+4;
static volatile bit           I2C1_ACKDT         @ ((unsigned)&I2C1CON*8)+5;
static volatile bit           I2C1_STREN         @ ((unsigned)&I2C1CON*8)+6;
static volatile bit           I2C1_GCEN          @ ((unsigned)&I2C1CON*8)+7;
static volatile bit           I2C1_SMEN          @ ((unsigned)&I2C1CON*8)+8;
static volatile bit           I2C1_DISSLW        @ ((unsigned)&I2C1CON*8)+9;
static volatile bit           I2C1_A10M          @ ((unsigned)&I2C1CON*8)+10;
static volatile bit           I2C1_IPMIEN        @ ((unsigned)&I2C1CON*8)+11;
static volatile bit           I2C1_SCLREL        @ ((unsigned)&I2C1CON*8)+12;
static volatile bit           I2C1_SIDL          @ ((unsigned)&I2C1CON*8)+13;
static volatile bit           I2C1_EN            @ ((unsigned)&I2C1CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      I2CEN              : 1;
                unsigned                         : 1;
       volatile unsigned      I2CSIDL            : 1;
       volatile unsigned      SCLREL             : 1;
       volatile unsigned      IPMIEN             : 1;
       volatile unsigned      A10M               : 1;
       volatile unsigned      DISSLW             : 1;
       volatile unsigned      SMEN               : 1;
       volatile unsigned      GCEN               : 1;
       volatile unsigned      STREN              : 1;
       volatile unsigned      ACKDT              : 1;
       volatile unsigned      ACKEN              : 1;
       volatile unsigned      RCEN               : 1;
       volatile unsigned      PEN                : 1;
       volatile unsigned      RSEN               : 1;
       volatile unsigned      SEN                : 1;
} I2C1CONbits @ 0x206;

static volatile unsigned int  I2C1STAT           @ 0x208;
static volatile bit           I2C1_TBF           @ ((unsigned)&I2C1STAT*8)+0;
static volatile bit           I2C1_RBF           @ ((unsigned)&I2C1STAT*8)+1;
static volatile bit           I2C1_R_NW          @ ((unsigned)&I2C1STAT*8)+2;
static volatile bit           I2C1_S             @ ((unsigned)&I2C1STAT*8)+3;
static volatile bit           I2C1_P             @ ((unsigned)&I2C1STAT*8)+4;
static volatile bit           I2C1_D_NA          @ ((unsigned)&I2C1STAT*8)+5;
static volatile bit           I2C1_POV           @ ((unsigned)&I2C1STAT*8)+6;
static volatile bit           I2C1_IWCOL         @ ((unsigned)&I2C1STAT*8)+7;
static volatile bit           I2C1_ADD10         @ ((unsigned)&I2C1STAT*8)+8;
static volatile bit           I2C1_GCSTAT        @ ((unsigned)&I2C1STAT*8)+9;
static volatile bit           I2C1_BCL           @ ((unsigned)&I2C1STAT*8)+10;
static volatile bit           I2C1_TRSTAT        @ ((unsigned)&I2C1STAT*8)+14;
static volatile bit           I2C1_ACKSTAT       @ ((unsigned)&I2C1STAT*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      ACKSTAT            : 1;
       volatile unsigned      TRSTAT             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      BCL                : 1;
       volatile unsigned      GCSTAT             : 1;
       volatile unsigned      ADD10              : 1;
       volatile unsigned      IWCOL              : 1;
       volatile unsigned      I2CPOV             : 1;
       volatile unsigned      D_nA               : 1;
       volatile unsigned      P                  : 1;
       volatile unsigned      S                  : 1;
       volatile unsigned      R_nW               : 1;
       volatile unsigned      RBF                : 1;
       volatile unsigned      TBF                : 1;
} I2C1STATbits @ 0x208;

static volatile unsigned int  I2C1ADD            @ 0x20A;
static volatile bit           I2C1_ADD0          @ ((unsigned)&I2C1ADD*8)+0;
static volatile bit           I2C1_ADD1          @ ((unsigned)&I2C1ADD*8)+1;
static volatile bit           I2C1_ADD2          @ ((unsigned)&I2C1ADD*8)+2;
static volatile bit           I2C1_ADD3          @ ((unsigned)&I2C1ADD*8)+3;
static volatile bit           I2C1_ADD4          @ ((unsigned)&I2C1ADD*8)+4;
static volatile bit           I2C1_ADD5          @ ((unsigned)&I2C1ADD*8)+5;
static volatile bit           I2C1_ADD6          @ ((unsigned)&I2C1ADD*8)+6;
static volatile bit           I2C1_ADD7          @ ((unsigned)&I2C1ADD*8)+7;
static volatile bit           I2C1_ADD8          @ ((unsigned)&I2C1ADD*8)+8;
static volatile bit           I2C1_ADD9          @ ((unsigned)&I2C1ADD*8)+9;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      I2C1ADD            : 10;
} I2C1ADDbits @ 0x20A;

static volatile unsigned int  I2C1MSK            @ 0x20C;
static volatile bit           I2C1_AMSK0         @ ((unsigned)&I2C1MSK*8)+0;
static volatile bit           I2C1_AMSK1         @ ((unsigned)&I2C1MSK*8)+1;
static volatile bit           I2C1_AMSK2         @ ((unsigned)&I2C1MSK*8)+2;
static volatile bit           I2C1_AMSK3         @ ((unsigned)&I2C1MSK*8)+3;
static volatile bit           I2C1_AMSK4         @ ((unsigned)&I2C1MSK*8)+4;
static volatile bit           I2C1_AMSK5         @ ((unsigned)&I2C1MSK*8)+5;
static volatile bit           I2C1_AMSK6         @ ((unsigned)&I2C1MSK*8)+6;
static volatile bit           I2C1_AMSK7         @ ((unsigned)&I2C1MSK*8)+7;
static volatile bit           I2C1_AMSK8         @ ((unsigned)&I2C1MSK*8)+8;
static volatile bit           I2C1_AMSK9         @ ((unsigned)&I2C1MSK*8)+9;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      AMSK               : 10;
} I2C1MSKbits @ 0x20C;

static volatile unsigned int  I2C2RCV            @ 0x210;
static volatile unsigned int  I2C2TRN            @ 0x212;
static volatile unsigned int  I2C2BRG            @ 0x214;
static volatile unsigned int  I2C2CON            @ 0x216;
static volatile bit           I2C2_SEN           @ ((unsigned)&I2C2CON*8)+0;
static volatile bit           I2C2_RSEN          @ ((unsigned)&I2C2CON*8)+1;
static volatile bit           I2C2_PEN           @ ((unsigned)&I2C2CON*8)+2;
static volatile bit           I2C2_RCEN          @ ((unsigned)&I2C2CON*8)+3;
static volatile bit           I2C2_ACKEN         @ ((unsigned)&I2C2CON*8)+4;
static volatile bit           I2C2_ACKDT         @ ((unsigned)&I2C2CON*8)+5;
static volatile bit           I2C2_STREN         @ ((unsigned)&I2C2CON*8)+6;
static volatile bit           I2C2_GCEN          @ ((unsigned)&I2C2CON*8)+7;
static volatile bit           I2C2_SMEN          @ ((unsigned)&I2C2CON*8)+8;
static volatile bit           I2C2_DISSLW        @ ((unsigned)&I2C2CON*8)+9;
static volatile bit           I2C2_A10M          @ ((unsigned)&I2C2CON*8)+10;
static volatile bit           I2C2_IPMIEN        @ ((unsigned)&I2C2CON*8)+11;
static volatile bit           I2C2_SCLREL        @ ((unsigned)&I2C2CON*8)+12;
static volatile bit           I2C2_SIDL          @ ((unsigned)&I2C2CON*8)+13;
static volatile bit           I2C2_EN            @ ((unsigned)&I2C2CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      I2CEN              : 1;
                unsigned                         : 1;
       volatile unsigned      I2CSIDL            : 1;
       volatile unsigned      SCLREL             : 1;
       volatile unsigned      IPMIEN             : 1;
       volatile unsigned      A10M               : 1;
       volatile unsigned      DISSLW             : 1;
       volatile unsigned      SMEN               : 1;
       volatile unsigned      GCEN               : 1;
       volatile unsigned      STREN              : 1;
       volatile unsigned      ACKDT              : 1;
       volatile unsigned      ACKEN              : 1;
       volatile unsigned      RCEN               : 1;
       volatile unsigned      PEN                : 1;
       volatile unsigned      RSEN               : 1;
       volatile unsigned      SEN                : 1;
} I2C2CONbits @ 0x216;

static volatile unsigned int  I2C2STAT           @ 0x218;
static volatile bit           I2C2_TBF           @ ((unsigned)&I2C2STAT*8)+0;
static volatile bit           I2C2_RBF           @ ((unsigned)&I2C2STAT*8)+1;
static volatile bit           I2C2_R_NW          @ ((unsigned)&I2C2STAT*8)+2;
static volatile bit           I2C2_S             @ ((unsigned)&I2C2STAT*8)+3;
static volatile bit           I2C2_P             @ ((unsigned)&I2C2STAT*8)+4;
static volatile bit           I2C2_D_NA          @ ((unsigned)&I2C2STAT*8)+5;
static volatile bit           I2C2_POV           @ ((unsigned)&I2C2STAT*8)+6;
static volatile bit           I2C2_IWCOL         @ ((unsigned)&I2C2STAT*8)+7;
static volatile bit           I2C2_ADD10         @ ((unsigned)&I2C2STAT*8)+8;
static volatile bit           I2C2_GCSTAT        @ ((unsigned)&I2C2STAT*8)+9;
static volatile bit           I2C2_TRSTAT        @ ((unsigned)&I2C2STAT*8)+14;
static volatile bit           I2C2_ACKSTAT       @ ((unsigned)&I2C2STAT*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      ACKSTAT            : 1;
       volatile unsigned      TRSTAT             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      GCSTAT             : 1;
       volatile unsigned      ADD10              : 1;
       volatile unsigned      IWCOL              : 1;
       volatile unsigned      I2CPOV             : 1;
       volatile unsigned      D_nA               : 1;
       volatile unsigned      P                  : 1;
       volatile unsigned      S                  : 1;
       volatile unsigned      R_nW               : 1;
       volatile unsigned      RBF                : 1;
       volatile unsigned      TBF                : 1;
} I2C2STATbits @ 0x218;

static volatile unsigned int  I2C2ADD            @ 0x21A;
static volatile bit           I2C2_ADD0          @ ((unsigned)&I2C2ADD*8)+0;
static volatile bit           I2C2_ADD1          @ ((unsigned)&I2C2ADD*8)+1;
static volatile bit           I2C2_ADD2          @ ((unsigned)&I2C2ADD*8)+2;
static volatile bit           I2C2_ADD3          @ ((unsigned)&I2C2ADD*8)+3;
static volatile bit           I2C2_ADD4          @ ((unsigned)&I2C2ADD*8)+4;
static volatile bit           I2C2_ADD5          @ ((unsigned)&I2C2ADD*8)+5;
static volatile bit           I2C2_ADD6          @ ((unsigned)&I2C2ADD*8)+6;
static volatile bit           I2C2_ADD7          @ ((unsigned)&I2C2ADD*8)+7;
static volatile bit           I2C2_ADD8          @ ((unsigned)&I2C2ADD*8)+8;
static volatile bit           I2C2_ADD9          @ ((unsigned)&I2C2ADD*8)+9;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      I2C2ADD            : 10;
} I2C2ADDbits @ 0x21A;

static volatile unsigned int  I2C2MSK            @ 0x21C;
static volatile bit           I2C2_AMSK0         @ ((unsigned)&I2C2MSK*8)+0;
static volatile bit           I2C2_AMSK1         @ ((unsigned)&I2C2MSK*8)+1;
static volatile bit           I2C2_AMSK2         @ ((unsigned)&I2C2MSK*8)+2;
static volatile bit           I2C2_AMSK3         @ ((unsigned)&I2C2MSK*8)+3;
static volatile bit           I2C2_AMSK4         @ ((unsigned)&I2C2MSK*8)+4;
static volatile bit           I2C2_AMSK5         @ ((unsigned)&I2C2MSK*8)+5;
static volatile bit           I2C2_AMSK6         @ ((unsigned)&I2C2MSK*8)+6;
static volatile bit           I2C2_AMSK7         @ ((unsigned)&I2C2MSK*8)+7;
static volatile bit           I2C2_AMSK8         @ ((unsigned)&I2C2MSK*8)+8;
static volatile bit           I2C2_AMSK9         @ ((unsigned)&I2C2MSK*8)+9;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      AMSK               : 10;
} I2C2MSKbits @ 0x21C;

static volatile unsigned int  U1MODE             @ 0x220;
static volatile bit           U1_STSEL           @ ((unsigned)&U1MODE*8)+0;
static volatile bit           U1_PDSEL0          @ ((unsigned)&U1MODE*8)+1;
static volatile bit           U1_PDSEL1          @ ((unsigned)&U1MODE*8)+2;
static volatile bit           U1_BRGH            @ ((unsigned)&U1MODE*8)+3;
static volatile bit           U1_RXINV           @ ((unsigned)&U1MODE*8)+4;
static volatile bit           U1_ABAUD           @ ((unsigned)&U1MODE*8)+5;
static volatile bit           U1_LPBACK          @ ((unsigned)&U1MODE*8)+6;
static volatile bit           U1_WAKE            @ ((unsigned)&U1MODE*8)+7;
static volatile bit           U1_UEN0            @ ((unsigned)&U1MODE*8)+8;
static volatile bit           U1_UEN1            @ ((unsigned)&U1MODE*8)+9;
static volatile bit           U1_RTSMD           @ ((unsigned)&U1MODE*8)+11;
static volatile bit           U1_IRDAEN          @ ((unsigned)&U1MODE*8)+12;
static volatile bit           U1_USIDL           @ ((unsigned)&U1MODE*8)+13;
static volatile bit           U1_SPEN            @ ((unsigned)&U1MODE*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SPEN               : 1;
                unsigned                         : 1;
       volatile unsigned      USIDL              : 1;
       volatile unsigned      IRDAEN             : 1;
       volatile unsigned      RTSMD              : 1;
                unsigned                         : 1;
       volatile unsigned      UEN1               : 1;
       volatile unsigned      UEN0               : 1;
       volatile unsigned      WAKE               : 1;
       volatile unsigned      LPBACK             : 1;
       volatile unsigned      ABAUD              : 1;
       volatile unsigned      RXINV              : 1;
       volatile unsigned      BRGH               : 1;
       volatile unsigned      PDSEL              : 2;
       volatile unsigned      STSEL              : 1;
} U1MODEbits @ 0x220;

static volatile unsigned int  U1STA              @ 0x222;
static volatile bit           U1_URXDA           @ ((unsigned)&U1STA*8)+0;
static volatile bit           U1_OERR            @ ((unsigned)&U1STA*8)+1;
static volatile bit           U1_FERR            @ ((unsigned)&U1STA*8)+2;
static volatile bit           U1_PERR            @ ((unsigned)&U1STA*8)+3;
static volatile bit           U1_RIDLE           @ ((unsigned)&U1STA*8)+4;
static volatile bit           U1_ADDEN           @ ((unsigned)&U1STA*8)+5;
static volatile bit           U1_RCISEL0         @ ((unsigned)&U1STA*8)+6;
static volatile bit           U1_RCISEL1         @ ((unsigned)&U1STA*8)+7;
static volatile bit           U1_TRMT            @ ((unsigned)&U1STA*8)+8;
static volatile bit           U1_TXBF            @ ((unsigned)&U1STA*8)+9;
static volatile bit           U1_TXEN            @ ((unsigned)&U1STA*8)+10;
static volatile bit           U1_TXBRK           @ ((unsigned)&U1STA*8)+11;
static volatile bit           U1_TXISEL0         @ ((unsigned)&U1STA*8)+13;
static volatile bit           U1_TXINV           @ ((unsigned)&U1STA*8)+14;
static volatile bit           U1_TXISEL1         @ ((unsigned)&U1STA*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      TXISEL1            : 1;
       volatile unsigned      TXINV              : 1;
       volatile unsigned      TXISEL0            : 1;
                unsigned                         : 1;
       volatile unsigned      TXBRK              : 1;
       volatile unsigned      TXEN               : 1;
       volatile unsigned      TXBF               : 1;
       volatile unsigned      TRMT               : 1;
       volatile unsigned      RCISEL             : 2;
       volatile unsigned      ADDEN              : 1;
       volatile unsigned      RIDLE              : 1;
       volatile unsigned      PERR               : 1;
       volatile unsigned      FERR               : 1;
       volatile unsigned      OERR               : 1;
       volatile unsigned      URXDA              : 1;
} U1STAbits @ 0x222;

static volatile unsigned int  U1TXREG            @ 0x224;
static volatile unsigned int  U1RXREG            @ 0x226;
static volatile unsigned int  U1BRG              @ 0x228;
static volatile unsigned int  U2MODE             @ 0x230;
static volatile bit           U2_STSEL           @ ((unsigned)&U2MODE*8)+0;
static volatile bit           U2_PDSEL0          @ ((unsigned)&U2MODE*8)+1;
static volatile bit           U2_PDSEL1          @ ((unsigned)&U2MODE*8)+2;
static volatile bit           U2_BRGH            @ ((unsigned)&U2MODE*8)+3;
static volatile bit           U2_RXINV           @ ((unsigned)&U2MODE*8)+4;
static volatile bit           U2_ABAUD           @ ((unsigned)&U2MODE*8)+5;
static volatile bit           U2_LPBACK          @ ((unsigned)&U2MODE*8)+6;
static volatile bit           U2_WAKE            @ ((unsigned)&U2MODE*8)+7;
static volatile bit           U2_UEN0            @ ((unsigned)&U2MODE*8)+8;
static volatile bit           U2_UEN1            @ ((unsigned)&U2MODE*8)+9;
static volatile bit           U2_RTSMD           @ ((unsigned)&U2MODE*8)+11;
static volatile bit           U2_IRDAEN          @ ((unsigned)&U2MODE*8)+12;
static volatile bit           U2_USIDL           @ ((unsigned)&U2MODE*8)+13;
static volatile bit           U2_SPEN            @ ((unsigned)&U2MODE*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SPEN               : 1;
                unsigned                         : 1;
       volatile unsigned      USIDL              : 1;
       volatile unsigned      IRDAEN             : 1;
       volatile unsigned      RTSMD              : 1;
                unsigned                         : 1;
       volatile unsigned      UEN1               : 1;
       volatile unsigned      UEN0               : 1;
       volatile unsigned      WAKE               : 1;
       volatile unsigned      LPBACK             : 1;
       volatile unsigned      ABAUD              : 1;
       volatile unsigned      RXINV              : 1;
       volatile unsigned      BRGH               : 1;
       volatile unsigned      PDSEL              : 2;
       volatile unsigned      STSEL              : 1;
} U2MODEbits @ 0x230;

static volatile unsigned int  U2STA              @ 0x232;
static volatile bit           U2_URXDA           @ ((unsigned)&U2STA*8)+0;
static volatile bit           U2_OERR            @ ((unsigned)&U2STA*8)+1;
static volatile bit           U2_FERR            @ ((unsigned)&U2STA*8)+2;
static volatile bit           U2_PERR            @ ((unsigned)&U2STA*8)+3;
static volatile bit           U2_RIDLE           @ ((unsigned)&U2STA*8)+4;
static volatile bit           U2_ADDEN           @ ((unsigned)&U2STA*8)+5;
static volatile bit           U2_RCISEL0         @ ((unsigned)&U2STA*8)+6;
static volatile bit           U2_RCISEL1         @ ((unsigned)&U2STA*8)+7;
static volatile bit           U2_TRMT            @ ((unsigned)&U2STA*8)+8;
static volatile bit           U2_TXBF            @ ((unsigned)&U2STA*8)+9;
static volatile bit           U2_TXEN            @ ((unsigned)&U2STA*8)+10;
static volatile bit           U2_TXBRK           @ ((unsigned)&U2STA*8)+11;
static volatile bit           U2_TXISEL0         @ ((unsigned)&U2STA*8)+13;
static volatile bit           U2_TXINV           @ ((unsigned)&U2STA*8)+14;
static volatile bit           U2_TXISEL1         @ ((unsigned)&U2STA*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      TXISEL1            : 1;
       volatile unsigned      TXINV              : 1;
       volatile unsigned      TXISEL0            : 1;
                unsigned                         : 1;
       volatile unsigned      TXBRK              : 1;
       volatile unsigned      TXEN               : 1;
       volatile unsigned      TXBF               : 1;
       volatile unsigned      TRMT               : 1;
       volatile unsigned      RCISEL             : 2;
       volatile unsigned      ADDEN              : 1;
       volatile unsigned      RIDLE              : 1;
       volatile unsigned      PERR               : 1;
       volatile unsigned      FERR               : 1;
       volatile unsigned      OERR               : 1;
       volatile unsigned      URXDA              : 1;
} U2STAbits @ 0x232;

static volatile unsigned int  U2TXREG            @ 0x234;
static volatile unsigned int  U2RXREG            @ 0x236;
static volatile unsigned int  U2BRG              @ 0x238;
static volatile unsigned int  SPI1STAT           @ 0x240;
static volatile bit           SPI1_RBF           @ ((unsigned)&SPI1STAT*8)+0;
static volatile bit           SPI1_TBF           @ ((unsigned)&SPI1STAT*8)+1;
static volatile bit           SPI1_ROV           @ ((unsigned)&SPI1STAT*8)+6;
static volatile bit           SPI1_SIDL          @ ((unsigned)&SPI1STAT*8)+13;
static volatile bit           SPI1_EN            @ ((unsigned)&SPI1STAT*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SPIEN              : 1;
                unsigned                         : 1;
       volatile unsigned      SPISIDL            : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      SPIROV             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      SPITBF             : 1;
       volatile unsigned      SPIRBF             : 1;
} SPI1STATbits @ 0x240;

static volatile unsigned int  SPI1CON1           @ 0x242;
static volatile bit           SPI1_PPRE0         @ ((unsigned)&SPI1CON1*8)+0;
static volatile bit           SPI1_PPRE1         @ ((unsigned)&SPI1CON1*8)+1;
static volatile bit           SPI1_SPRE0         @ ((unsigned)&SPI1CON1*8)+2;
static volatile bit           SPI1_SPRE1         @ ((unsigned)&SPI1CON1*8)+3;
static volatile bit           SPI1_SPRE2         @ ((unsigned)&SPI1CON1*8)+4;
static volatile bit           SPI1_MSTEN         @ ((unsigned)&SPI1CON1*8)+5;
static volatile bit           SPI1_CKP           @ ((unsigned)&SPI1CON1*8)+6;
static volatile bit           SPI1_SSEN          @ ((unsigned)&SPI1CON1*8)+7;
static volatile bit           SPI1_CKE           @ ((unsigned)&SPI1CON1*8)+8;
static volatile bit           SPI1_SMP           @ ((unsigned)&SPI1CON1*8)+9;
static volatile bit           SPI1_MODE16        @ ((unsigned)&SPI1CON1*8)+10;
static volatile bit           SPI1_DISSDO        @ ((unsigned)&SPI1CON1*8)+11;
static volatile bit           SPI1_DISSCK        @ ((unsigned)&SPI1CON1*8)+12;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      DISSCK             : 1;
       volatile unsigned      DISSDO             : 1;
       volatile unsigned      MODE16             : 1;
       volatile unsigned      SMP                : 1;
       volatile unsigned      CKE                : 1;
       volatile unsigned      SSEN               : 1;
       volatile unsigned      CKP                : 1;
       volatile unsigned      MSTEN              : 1;
       volatile unsigned      SPRE               : 3;
       volatile unsigned      PPRE               : 2;
} SPI1CON1bits @ 0x242;

static volatile unsigned int  SPI1CON2           @ 0x244;
static volatile bit           SPI1_ENHBUF        @ ((unsigned)&SPI1CON2*8)+0;
static volatile bit           SPI1_FRMDEL        @ ((unsigned)&SPI1CON2*8)+1;
static volatile bit           SPI1_FRMPOL        @ ((unsigned)&SPI1CON2*8)+13;
static volatile bit           SPI1_FRMSYNC       @ ((unsigned)&SPI1CON2*8)+14;
static volatile bit           SPI1_FRMEN         @ ((unsigned)&SPI1CON2*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      FRMEN              : 1;
       volatile unsigned      FRMSYNC            : 1;
       volatile unsigned      FRMPOL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      FRMDEL             : 1;
       volatile unsigned      ENHBUF             : 1;
} SPI1CON2bits @ 0x244;

static volatile unsigned int  SPI1BUF            @ 0x248;
static volatile unsigned int  SPI2STAT           @ 0x260;
static volatile bit           SPI2_RBF           @ ((unsigned)&SPI2STAT*8)+0;
static volatile bit           SPI2_TBF           @ ((unsigned)&SPI2STAT*8)+1;
static volatile bit           SPI2_ROV           @ ((unsigned)&SPI2STAT*8)+6;
static volatile bit           SPI2_SIDL          @ ((unsigned)&SPI2STAT*8)+13;
static volatile bit           SPI2_EN            @ ((unsigned)&SPI2STAT*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SPIEN              : 1;
                unsigned                         : 1;
       volatile unsigned      SPISIDL            : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      SPIROV             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      SPITBF             : 1;
       volatile unsigned      SPIRBF             : 1;
} SPI2STATbits @ 0x260;

static volatile unsigned int  SPI2CON1           @ 0x262;
static volatile bit           SPI2_PPRE0         @ ((unsigned)&SPI2CON1*8)+0;
static volatile bit           SPI2_PPRE1         @ ((unsigned)&SPI2CON1*8)+1;
static volatile bit           SPI2_SPRE0         @ ((unsigned)&SPI2CON1*8)+2;
static volatile bit           SPI2_SPRE1         @ ((unsigned)&SPI2CON1*8)+3;
static volatile bit           SPI2_SPRE2         @ ((unsigned)&SPI2CON1*8)+4;
static volatile bit           SPI2_MSTEN         @ ((unsigned)&SPI2CON1*8)+5;
static volatile bit           SPI2_CKP           @ ((unsigned)&SPI2CON1*8)+6;
static volatile bit           SPI2_SSEN          @ ((unsigned)&SPI2CON1*8)+7;
static volatile bit           SPI2_CKE           @ ((unsigned)&SPI2CON1*8)+8;
static volatile bit           SPI2_SMP           @ ((unsigned)&SPI2CON1*8)+9;
static volatile bit           SPI2_MODE16        @ ((unsigned)&SPI2CON1*8)+10;
static volatile bit           SPI2_DISSDO        @ ((unsigned)&SPI2CON1*8)+11;
static volatile bit           SPI2_DISSCK        @ ((unsigned)&SPI2CON1*8)+12;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      DISSCK             : 1;
       volatile unsigned      DISSDO             : 1;
       volatile unsigned      MODE16             : 1;
       volatile unsigned      SMP                : 1;
       volatile unsigned      CKE                : 1;
       volatile unsigned      SSEN               : 1;
       volatile unsigned      CKP                : 1;
       volatile unsigned      MSTEN              : 1;
       volatile unsigned      SPRE               : 3;
       volatile unsigned      PPRE               : 2;
} SPI2CON1bits @ 0x262;

static volatile unsigned int  SPI2CON2           @ 0x264;
static volatile bit           SPI2_ENHBUF        @ ((unsigned)&SPI2CON2*8)+0;
static volatile bit           SPI2_FRMDEL        @ ((unsigned)&SPI2CON2*8)+1;
static volatile bit           SPI2_FRMPOL        @ ((unsigned)&SPI2CON2*8)+13;
static volatile bit           SPI2_FRMSYNC       @ ((unsigned)&SPI2CON2*8)+14;
static volatile bit           SPI2_FRMEN         @ ((unsigned)&SPI2CON2*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      FRMEN              : 1;
       volatile unsigned      FRMSYNC            : 1;
       volatile unsigned      FRMPOL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      FRMDEL             : 1;
       volatile unsigned      ENHBUF             : 1;
} SPI2CON2bits @ 0x264;

static volatile unsigned int  SPI2BUF            @ 0x268;
static volatile unsigned int  TRISA              @ 0x2C0;
static volatile bit           TRISA0             @ ((unsigned)&TRISA*8)+0;
static volatile bit           TRISA1             @ ((unsigned)&TRISA*8)+1;
static volatile bit           TRISA2             @ ((unsigned)&TRISA*8)+2;
static volatile bit           TRISA3             @ ((unsigned)&TRISA*8)+3;
static volatile bit           TRISA4             @ ((unsigned)&TRISA*8)+4;
static volatile bit           TRISA5             @ ((unsigned)&TRISA*8)+5;
static volatile bit           TRISA6             @ ((unsigned)&TRISA*8)+6;
static volatile bit           TRISA7             @ ((unsigned)&TRISA*8)+7;
static volatile bit           TRISA9             @ ((unsigned)&TRISA*8)+9;
static volatile bit           TRISA10            @ ((unsigned)&TRISA*8)+10;
static volatile bit           TRISA12            @ ((unsigned)&TRISA*8)+12;
static volatile bit           TRISA13            @ ((unsigned)&TRISA*8)+13;
static volatile bit           TRISA14            @ ((unsigned)&TRISA*8)+14;
static volatile bit           TRISA15            @ ((unsigned)&TRISA*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      TRISA15            : 1;
       volatile unsigned      TRISA14            : 1;
       volatile unsigned      TRISA13            : 1;
       volatile unsigned      TRISA12            : 1;
                unsigned                         : 1;
       volatile unsigned      TRISA10            : 1;
       volatile unsigned      TRISA9             : 1;
                unsigned                         : 1;
       volatile unsigned      TRISA7             : 1;
       volatile unsigned      TRISA6             : 1;
       volatile unsigned      TRISA5             : 1;
       volatile unsigned      TRISA4             : 1;
       volatile unsigned      TRISA3             : 1;
       volatile unsigned      TRISA2             : 1;
       volatile unsigned      TRISA1             : 1;
       volatile unsigned      TRISA0             : 1;
} TRISAbits @ 0x2C0;

static volatile unsigned int  PORTA              @ 0x2C2;
static volatile bit           RA0                @ ((unsigned)&PORTA*8)+0;
static volatile bit           RA1                @ ((unsigned)&PORTA*8)+1;
static volatile bit           RA2                @ ((unsigned)&PORTA*8)+2;
static volatile bit           RA3                @ ((unsigned)&PORTA*8)+3;
static volatile bit           RA4                @ ((unsigned)&PORTA*8)+4;
static volatile bit           RA5                @ ((unsigned)&PORTA*8)+5;
static volatile bit           RA6                @ ((unsigned)&PORTA*8)+6;
static volatile bit           RA7                @ ((unsigned)&PORTA*8)+7;
static volatile bit           RA9                @ ((unsigned)&PORTA*8)+9;
static volatile bit           RA10               @ ((unsigned)&PORTA*8)+10;
static volatile bit           RA12               @ ((unsigned)&PORTA*8)+12;
static volatile bit           RA13               @ ((unsigned)&PORTA*8)+13;
static volatile bit           RA14               @ ((unsigned)&PORTA*8)+14;
static volatile bit           RA15               @ ((unsigned)&PORTA*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      RA15               : 1;
       volatile unsigned      RA14               : 1;
       volatile unsigned      RA13               : 1;
       volatile unsigned      RA12               : 1;
                unsigned                         : 1;
       volatile unsigned      RA10               : 1;
       volatile unsigned      RA9                : 1;
                unsigned                         : 1;
       volatile unsigned      RA7                : 1;
       volatile unsigned      RA6                : 1;
       volatile unsigned      RA5                : 1;
       volatile unsigned      RA4                : 1;
       volatile unsigned      RA3                : 1;
       volatile unsigned      RA2                : 1;
       volatile unsigned      RA1                : 1;
       volatile unsigned      RA0                : 1;
} PORTAbits @ 0x2C2;

static volatile unsigned int  LATA               @ 0x2C4;
static volatile bit           LATA0              @ ((unsigned)&LATA*8)+0;
static volatile bit           LATA1              @ ((unsigned)&LATA*8)+1;
static volatile bit           LATA2              @ ((unsigned)&LATA*8)+2;
static volatile bit           LATA3              @ ((unsigned)&LATA*8)+3;
static volatile bit           LATA4              @ ((unsigned)&LATA*8)+4;
static volatile bit           LATA5              @ ((unsigned)&LATA*8)+5;
static volatile bit           LATA6              @ ((unsigned)&LATA*8)+6;
static volatile bit           LATA7              @ ((unsigned)&LATA*8)+7;
static volatile bit           LATA9              @ ((unsigned)&LATA*8)+9;
static volatile bit           LATA10             @ ((unsigned)&LATA*8)+10;
static volatile bit           LATA12             @ ((unsigned)&LATA*8)+12;
static volatile bit           LATA13             @ ((unsigned)&LATA*8)+13;
static volatile bit           LATA14             @ ((unsigned)&LATA*8)+14;
static volatile bit           LATA15             @ ((unsigned)&LATA*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      LATA15             : 1;
       volatile unsigned      LATA14             : 1;
       volatile unsigned      LATA13             : 1;
       volatile unsigned      LATA12             : 1;
                unsigned                         : 1;
       volatile unsigned      LATA10             : 1;
       volatile unsigned      LATA9              : 1;
                unsigned                         : 1;
       volatile unsigned      LATA7              : 1;
       volatile unsigned      LATA6              : 1;
       volatile unsigned      LATA5              : 1;
       volatile unsigned      LATA4              : 1;
       volatile unsigned      LATA3              : 1;
       volatile unsigned      LATA2              : 1;
       volatile unsigned      LATA1              : 1;
       volatile unsigned      LATA0              : 1;
} LATAbits @ 0x2C4;

static volatile unsigned int  ODCA               @ 0x6C0;
static volatile bit           ODCA0              @ ((unsigned)&ODCA*8)+0;
static volatile bit           ODCA1              @ ((unsigned)&ODCA*8)+1;
static volatile bit           ODCA2              @ ((unsigned)&ODCA*8)+2;
static volatile bit           ODCA3              @ ((unsigned)&ODCA*8)+3;
static volatile bit           ODCA4              @ ((unsigned)&ODCA*8)+4;
static volatile bit           ODCA5              @ ((unsigned)&ODCA*8)+5;
static volatile bit           ODCA12             @ ((unsigned)&ODCA*8)+12;
static volatile bit           ODCA13             @ ((unsigned)&ODCA*8)+13;
static volatile bit           ODCA14             @ ((unsigned)&ODCA*8)+14;
static volatile bit           ODCA15             @ ((unsigned)&ODCA*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      ODCA15             : 1;
       volatile unsigned      ODCA14             : 1;
       volatile unsigned      ODCA13             : 1;
       volatile unsigned      ODCA12             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      ODCA5              : 1;
       volatile unsigned      ODCA4              : 1;
       volatile unsigned      ODCA3              : 1;
       volatile unsigned      ODCA2              : 1;
       volatile unsigned      ODCA1              : 1;
       volatile unsigned      ODCA0              : 1;
} ODCAbits @ 0x6C0;

static volatile unsigned int  TRISB              @ 0x2C6;
static volatile bit           TRISB0             @ ((unsigned)&TRISB*8)+0;
static volatile bit           TRISB1             @ ((unsigned)&TRISB*8)+1;
static volatile bit           TRISB2             @ ((unsigned)&TRISB*8)+2;
static volatile bit           TRISB3             @ ((unsigned)&TRISB*8)+3;
static volatile bit           TRISB4             @ ((unsigned)&TRISB*8)+4;
static volatile bit           TRISB5             @ ((unsigned)&TRISB*8)+5;
static volatile bit           TRISB6             @ ((unsigned)&TRISB*8)+6;
static volatile bit           TRISB7             @ ((unsigned)&TRISB*8)+7;
static volatile bit           TRISB8             @ ((unsigned)&TRISB*8)+8;
static volatile bit           TRISB9             @ ((unsigned)&TRISB*8)+9;
static volatile bit           TRISB10            @ ((unsigned)&TRISB*8)+10;
static volatile bit           TRISB11            @ ((unsigned)&TRISB*8)+11;
static volatile bit           TRISB12            @ ((unsigned)&TRISB*8)+12;
static volatile bit           TRISB13            @ ((unsigned)&TRISB*8)+13;
static volatile bit           TRISB14            @ ((unsigned)&TRISB*8)+14;
static volatile bit           TRISB15            @ ((unsigned)&TRISB*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      TRISB15            : 1;
       volatile unsigned      TRISB14            : 1;
       volatile unsigned      TRISB13            : 1;
       volatile unsigned      TRISB12            : 1;
       volatile unsigned      TRISB11            : 1;
       volatile unsigned      TRISB10            : 1;
       volatile unsigned      TRISB9             : 1;
       volatile unsigned      TRISB8             : 1;
       volatile unsigned      TRISB7             : 1;
       volatile unsigned      TRISB6             : 1;
       volatile unsigned      TRISB5             : 1;
       volatile unsigned      TRISB4             : 1;
       volatile unsigned      TRISB3             : 1;
       volatile unsigned      TRISB2             : 1;
       volatile unsigned      TRISB1             : 1;
       volatile unsigned      TRISB0             : 1;
} TRISBbits @ 0x2C6;

static volatile unsigned int  PORTB              @ 0x2C8;
static volatile bit           RB0                @ ((unsigned)&PORTB*8)+0;
static volatile bit           RB1                @ ((unsigned)&PORTB*8)+1;
static volatile bit           RB2                @ ((unsigned)&PORTB*8)+2;
static volatile bit           RB3                @ ((unsigned)&PORTB*8)+3;
static volatile bit           RB4                @ ((unsigned)&PORTB*8)+4;
static volatile bit           RB5                @ ((unsigned)&PORTB*8)+5;
static volatile bit           RB6                @ ((unsigned)&PORTB*8)+6;
static volatile bit           RB7                @ ((unsigned)&PORTB*8)+7;
static volatile bit           RB8                @ ((unsigned)&PORTB*8)+8;
static volatile bit           RB9                @ ((unsigned)&PORTB*8)+9;
static volatile bit           RB10               @ ((unsigned)&PORTB*8)+10;
static volatile bit           RB11               @ ((unsigned)&PORTB*8)+11;
static volatile bit           RB12               @ ((unsigned)&PORTB*8)+12;
static volatile bit           RB13               @ ((unsigned)&PORTB*8)+13;
static volatile bit           RB14               @ ((unsigned)&PORTB*8)+14;
static volatile bit           RB15               @ ((unsigned)&PORTB*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      RB15               : 1;
       volatile unsigned      RB14               : 1;
       volatile unsigned      RB13               : 1;
       volatile unsigned      RB12               : 1;
       volatile unsigned      RB11               : 1;
       volatile unsigned      RB10               : 1;
       volatile unsigned      RB9                : 1;
       volatile unsigned      RB8                : 1;
       volatile unsigned      RB7                : 1;
       volatile unsigned      RB6                : 1;
       volatile unsigned      RB5                : 1;
       volatile unsigned      RB4                : 1;
       volatile unsigned      RB3                : 1;
       volatile unsigned      RB2                : 1;
       volatile unsigned      RB1                : 1;
       volatile unsigned      RB0                : 1;
} PORTBbits @ 0x2C8;

static volatile unsigned int  LATB               @ 0x2CA;
static volatile bit           LATB0              @ ((unsigned)&LATB*8)+0;
static volatile bit           LATB1              @ ((unsigned)&LATB*8)+1;
static volatile bit           LATB2              @ ((unsigned)&LATB*8)+2;
static volatile bit           LATB3              @ ((unsigned)&LATB*8)+3;
static volatile bit           LATB4              @ ((unsigned)&LATB*8)+4;
static volatile bit           LATB5              @ ((unsigned)&LATB*8)+5;
static volatile bit           LATB6              @ ((unsigned)&LATB*8)+6;
static volatile bit           LATB7              @ ((unsigned)&LATB*8)+7;
static volatile bit           LATB8              @ ((unsigned)&LATB*8)+8;
static volatile bit           LATB9              @ ((unsigned)&LATB*8)+9;
static volatile bit           LATB10             @ ((unsigned)&LATB*8)+10;
static volatile bit           LATB11             @ ((unsigned)&LATB*8)+11;
static volatile bit           LATB12             @ ((unsigned)&LATB*8)+12;
static volatile bit           LATB13             @ ((unsigned)&LATB*8)+13;
static volatile bit           LATB14             @ ((unsigned)&LATB*8)+14;
static volatile bit           LATB15             @ ((unsigned)&LATB*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      LATB15             : 1;
       volatile unsigned      LATB14             : 1;
       volatile unsigned      LATB13             : 1;
       volatile unsigned      LATB12             : 1;
       volatile unsigned      LATB11             : 1;
       volatile unsigned      LATB10             : 1;
       volatile unsigned      LATB9              : 1;
       volatile unsigned      LATB8              : 1;
       volatile unsigned      LATB7              : 1;
       volatile unsigned      LATB6              : 1;
       volatile unsigned      LATB5              : 1;
       volatile unsigned      LATB4              : 1;
       volatile unsigned      LATB3              : 1;
       volatile unsigned      LATB2              : 1;
       volatile unsigned      LATB1              : 1;
       volatile unsigned      LATB0              : 1;
} LATBbits @ 0x2CA;

static volatile unsigned int  TRISC              @ 0x2CC;
static volatile bit           TRISC1             @ ((unsigned)&TRISC*8)+1;
static volatile bit           TRISC2             @ ((unsigned)&TRISC*8)+2;
static volatile bit           TRISC3             @ ((unsigned)&TRISC*8)+3;
static volatile bit           TRISC4             @ ((unsigned)&TRISC*8)+4;
static volatile bit           TRISC12            @ ((unsigned)&TRISC*8)+12;
static volatile bit           TRISC13            @ ((unsigned)&TRISC*8)+13;
static volatile bit           TRISC14            @ ((unsigned)&TRISC*8)+14;
static volatile bit           TRISC15            @ ((unsigned)&TRISC*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      TRISC15            : 1;
       volatile unsigned      TRISC14            : 1;
       volatile unsigned      TRISC13            : 1;
       volatile unsigned      TRISC12            : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      TRISC4             : 1;
       volatile unsigned      TRISC3             : 1;
       volatile unsigned      TRISC2             : 1;
       volatile unsigned      TRISC1             : 1;
                unsigned                         : 1;
} TRISCbits @ 0x2CC;

static volatile unsigned int  PORTC              @ 0x2CE;
static volatile bit           RC1                @ ((unsigned)&PORTC*8)+1;
static volatile bit           RC2                @ ((unsigned)&PORTC*8)+2;
static volatile bit           RC3                @ ((unsigned)&PORTC*8)+3;
static volatile bit           RC4                @ ((unsigned)&PORTC*8)+4;
static volatile bit           RC12               @ ((unsigned)&PORTC*8)+12;
static volatile bit           RC13               @ ((unsigned)&PORTC*8)+13;
static volatile bit           RC14               @ ((unsigned)&PORTC*8)+14;
static volatile bit           RC15               @ ((unsigned)&PORTC*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      RC15               : 1;
       volatile unsigned      RC14               : 1;
       volatile unsigned      RC13               : 1;
       volatile unsigned      RC12               : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      RC4                : 1;
       volatile unsigned      RC3                : 1;
       volatile unsigned      RC2                : 1;
       volatile unsigned      RC1                : 1;
                unsigned                         : 1;
} PORTCbits @ 0x2CE;

static volatile unsigned int  LATC               @ 0x2D0;
static volatile bit           LATC1              @ ((unsigned)&LATC*8)+1;
static volatile bit           LATC2              @ ((unsigned)&LATC*8)+2;
static volatile bit           LATC3              @ ((unsigned)&LATC*8)+3;
static volatile bit           LATC4              @ ((unsigned)&LATC*8)+4;
static volatile bit           LATC12             @ ((unsigned)&LATC*8)+12;
static volatile bit           LATC13             @ ((unsigned)&LATC*8)+13;
static volatile bit           LATC14             @ ((unsigned)&LATC*8)+14;
static volatile bit           LATC15             @ ((unsigned)&LATC*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      LATC15             : 1;
       volatile unsigned      LATC14             : 1;
       volatile unsigned      LATC13             : 1;
       volatile unsigned      LATC12             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      LATC4              : 1;
       volatile unsigned      LATC3              : 1;
       volatile unsigned      LATC2              : 1;
       volatile unsigned      LATC1              : 1;
                unsigned                         : 1;
} LATCbits @ 0x2D0;

static volatile unsigned int  TRISD              @ 0x2D2;
static volatile bit           TRISD0             @ ((unsigned)&TRISD*8)+0;
static volatile bit           TRISD1             @ ((unsigned)&TRISD*8)+1;
static volatile bit           TRISD2             @ ((unsigned)&TRISD*8)+2;
static volatile bit           TRISD3             @ ((unsigned)&TRISD*8)+3;
static volatile bit           TRISD4             @ ((unsigned)&TRISD*8)+4;
static volatile bit           TRISD5             @ ((unsigned)&TRISD*8)+5;
static volatile bit           TRISD6             @ ((unsigned)&TRISD*8)+6;
static volatile bit           TRISD7             @ ((unsigned)&TRISD*8)+7;
static volatile bit           TRISD8             @ ((unsigned)&TRISD*8)+8;
static volatile bit           TRISD9             @ ((unsigned)&TRISD*8)+9;
static volatile bit           TRISD10            @ ((unsigned)&TRISD*8)+10;
static volatile bit           TRISD11            @ ((unsigned)&TRISD*8)+11;
static volatile bit           TRISD12            @ ((unsigned)&TRISD*8)+12;
static volatile bit           TRISD13            @ ((unsigned)&TRISD*8)+13;
static volatile bit           TRISD14            @ ((unsigned)&TRISD*8)+14;
static volatile bit           TRISD15            @ ((unsigned)&TRISD*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      TRISD15            : 1;
       volatile unsigned      TRISD14            : 1;
       volatile unsigned      TRISD13            : 1;
       volatile unsigned      TRISD12            : 1;
       volatile unsigned      TRISD11            : 1;
       volatile unsigned      TRISD10            : 1;
       volatile unsigned      TRISD9             : 1;
       volatile unsigned      TRISD8             : 1;
       volatile unsigned      TRISD7             : 1;
       volatile unsigned      TRISD6             : 1;
       volatile unsigned      TRISD5             : 1;
       volatile unsigned      TRISD4             : 1;
       volatile unsigned      TRISD3             : 1;
       volatile unsigned      TRISD2             : 1;
       volatile unsigned      TRISD1             : 1;
       volatile unsigned      TRISD0             : 1;
} TRISDbits @ 0x2D2;

static volatile unsigned int  PORTD              @ 0x2D4;
static volatile bit           RD0                @ ((unsigned)&PORTD*8)+0;
static volatile bit           RD1                @ ((unsigned)&PORTD*8)+1;
static volatile bit           RD2                @ ((unsigned)&PORTD*8)+2;
static volatile bit           RD3                @ ((unsigned)&PORTD*8)+3;
static volatile bit           RD4                @ ((unsigned)&PORTD*8)+4;
static volatile bit           RD5                @ ((unsigned)&PORTD*8)+5;
static volatile bit           RD6                @ ((unsigned)&PORTD*8)+6;
static volatile bit           RD7                @ ((unsigned)&PORTD*8)+7;
static volatile bit           RD8                @ ((unsigned)&PORTD*8)+8;
static volatile bit           RD9                @ ((unsigned)&PORTD*8)+9;
static volatile bit           RD10               @ ((unsigned)&PORTD*8)+10;
static volatile bit           RD11               @ ((unsigned)&PORTD*8)+11;
static volatile bit           RD12               @ ((unsigned)&PORTD*8)+12;
static volatile bit           RD13               @ ((unsigned)&PORTD*8)+13;
static volatile bit           RD14               @ ((unsigned)&PORTD*8)+14;
static volatile bit           RD15               @ ((unsigned)&PORTD*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      RD15               : 1;
       volatile unsigned      RD14               : 1;
       volatile unsigned      RD13               : 1;
       volatile unsigned      RD12               : 1;
       volatile unsigned      RD11               : 1;
       volatile unsigned      RD10               : 1;
       volatile unsigned      RD9                : 1;
       volatile unsigned      RD8                : 1;
       volatile unsigned      RD7                : 1;
       volatile unsigned      RD6                : 1;
       volatile unsigned      RD5                : 1;
       volatile unsigned      RD4                : 1;
       volatile unsigned      RD3                : 1;
       volatile unsigned      RD2                : 1;
       volatile unsigned      RD1                : 1;
       volatile unsigned      RD0                : 1;
} PORTDbits @ 0x2D4;

static volatile unsigned int  LATD               @ 0x2D6;
static volatile bit           LATD0              @ ((unsigned)&LATD*8)+0;
static volatile bit           LATD1              @ ((unsigned)&LATD*8)+1;
static volatile bit           LATD2              @ ((unsigned)&LATD*8)+2;
static volatile bit           LATD3              @ ((unsigned)&LATD*8)+3;
static volatile bit           LATD4              @ ((unsigned)&LATD*8)+4;
static volatile bit           LATD5              @ ((unsigned)&LATD*8)+5;
static volatile bit           LATD6              @ ((unsigned)&LATD*8)+6;
static volatile bit           LATD7              @ ((unsigned)&LATD*8)+7;
static volatile bit           LATD8              @ ((unsigned)&LATD*8)+8;
static volatile bit           LATD9              @ ((unsigned)&LATD*8)+9;
static volatile bit           LATD10             @ ((unsigned)&LATD*8)+10;
static volatile bit           LATD11             @ ((unsigned)&LATD*8)+11;
static volatile bit           LATD12             @ ((unsigned)&LATD*8)+12;
static volatile bit           LATD13             @ ((unsigned)&LATD*8)+13;
static volatile bit           LATD14             @ ((unsigned)&LATD*8)+14;
static volatile bit           LATD15             @ ((unsigned)&LATD*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      LATD15             : 1;
       volatile unsigned      LATD14             : 1;
       volatile unsigned      LATD13             : 1;
       volatile unsigned      LATD12             : 1;
       volatile unsigned      LATD11             : 1;
       volatile unsigned      LATD10             : 1;
       volatile unsigned      LATD9              : 1;
       volatile unsigned      LATD8              : 1;
       volatile unsigned      LATD7              : 1;
       volatile unsigned      LATD6              : 1;
       volatile unsigned      LATD5              : 1;
       volatile unsigned      LATD4              : 1;
       volatile unsigned      LATD3              : 1;
       volatile unsigned      LATD2              : 1;
       volatile unsigned      LATD1              : 1;
       volatile unsigned      LATD0              : 1;
} LATDbits @ 0x2D6;

static volatile unsigned int  ODCD               @ 0x6D2;
static volatile bit           ODCD0              @ ((unsigned)&ODCD*8)+0;
static volatile bit           ODCD1              @ ((unsigned)&ODCD*8)+1;
static volatile bit           ODCD2              @ ((unsigned)&ODCD*8)+2;
static volatile bit           ODCD3              @ ((unsigned)&ODCD*8)+3;
static volatile bit           ODCD4              @ ((unsigned)&ODCD*8)+4;
static volatile bit           ODCD5              @ ((unsigned)&ODCD*8)+5;
static volatile bit           ODCD6              @ ((unsigned)&ODCD*8)+6;
static volatile bit           ODCD7              @ ((unsigned)&ODCD*8)+7;
static volatile bit           ODCD8              @ ((unsigned)&ODCD*8)+8;
static volatile bit           ODCD9              @ ((unsigned)&ODCD*8)+9;
static volatile bit           ODCD10             @ ((unsigned)&ODCD*8)+10;
static volatile bit           ODCD11             @ ((unsigned)&ODCD*8)+11;
static volatile bit           ODCD12             @ ((unsigned)&ODCD*8)+12;
static volatile bit           ODCD13             @ ((unsigned)&ODCD*8)+13;
static volatile bit           ODCD14             @ ((unsigned)&ODCD*8)+14;
static volatile bit           ODCD15             @ ((unsigned)&ODCD*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      ODCD15             : 1;
       volatile unsigned      ODCD14             : 1;
       volatile unsigned      ODCD13             : 1;
       volatile unsigned      ODCD12             : 1;
       volatile unsigned      ODCD11             : 1;
       volatile unsigned      ODCD10             : 1;
       volatile unsigned      ODCD9              : 1;
       volatile unsigned      ODCD8              : 1;
       volatile unsigned      ODCD7              : 1;
       volatile unsigned      ODCD6              : 1;
       volatile unsigned      ODCD5              : 1;
       volatile unsigned      ODCD4              : 1;
       volatile unsigned      ODCD3              : 1;
       volatile unsigned      ODCD2              : 1;
       volatile unsigned      ODCD1              : 1;
       volatile unsigned      ODCD0              : 1;
} ODCDbits @ 0x6D2;

static volatile unsigned int  TRISE              @ 0x2D8;
static volatile bit           TRISE0             @ ((unsigned)&TRISE*8)+0;
static volatile bit           TRISE1             @ ((unsigned)&TRISE*8)+1;
static volatile bit           TRISE2             @ ((unsigned)&TRISE*8)+2;
static volatile bit           TRISE3             @ ((unsigned)&TRISE*8)+3;
static volatile bit           TRISE4             @ ((unsigned)&TRISE*8)+4;
static volatile bit           TRISE5             @ ((unsigned)&TRISE*8)+5;
static volatile bit           TRISE6             @ ((unsigned)&TRISE*8)+6;
static volatile bit           TRISE7             @ ((unsigned)&TRISE*8)+7;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      TRISE7             : 1;
       volatile unsigned      TRISE6             : 1;
       volatile unsigned      TRISE5             : 1;
       volatile unsigned      TRISE4             : 1;
       volatile unsigned      TRISE3             : 1;
       volatile unsigned      TRISE2             : 1;
       volatile unsigned      TRISE1             : 1;
       volatile unsigned      TRISE0             : 1;
} TRISEbits @ 0x2D8;

static volatile unsigned int  PORTE              @ 0x2DA;
static volatile bit           RE0                @ ((unsigned)&PORTE*8)+0;
static volatile bit           RE1                @ ((unsigned)&PORTE*8)+1;
static volatile bit           RE2                @ ((unsigned)&PORTE*8)+2;
static volatile bit           RE3                @ ((unsigned)&PORTE*8)+3;
static volatile bit           RE4                @ ((unsigned)&PORTE*8)+4;
static volatile bit           RE5                @ ((unsigned)&PORTE*8)+5;
static volatile bit           RE6                @ ((unsigned)&PORTE*8)+6;
static volatile bit           RE7                @ ((unsigned)&PORTE*8)+7;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      RE7                : 1;
       volatile unsigned      RE6                : 1;
       volatile unsigned      RE5                : 1;
       volatile unsigned      RE4                : 1;
       volatile unsigned      RE3                : 1;
       volatile unsigned      RE2                : 1;
       volatile unsigned      RE1                : 1;
       volatile unsigned      RE0                : 1;
} PORTEbits @ 0x2DA;

static volatile unsigned int  LATE               @ 0x2DC;
static volatile bit           LATE0              @ ((unsigned)&LATE*8)+0;
static volatile bit           LATE1              @ ((unsigned)&LATE*8)+1;
static volatile bit           LATE2              @ ((unsigned)&LATE*8)+2;
static volatile bit           LATE3              @ ((unsigned)&LATE*8)+3;
static volatile bit           LATE4              @ ((unsigned)&LATE*8)+4;
static volatile bit           LATE5              @ ((unsigned)&LATE*8)+5;
static volatile bit           LATE6              @ ((unsigned)&LATE*8)+6;
static volatile bit           LATE7              @ ((unsigned)&LATE*8)+7;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      LATE7              : 1;
       volatile unsigned      LATE6              : 1;
       volatile unsigned      LATE5              : 1;
       volatile unsigned      LATE4              : 1;
       volatile unsigned      LATE3              : 1;
       volatile unsigned      LATE2              : 1;
       volatile unsigned      LATE1              : 1;
       volatile unsigned      LATE0              : 1;
} LATEbits @ 0x2DC;

static volatile unsigned int  TRISF              @ 0x2DE;
static volatile bit           TRISF0             @ ((unsigned)&TRISF*8)+0;
static volatile bit           TRISF1             @ ((unsigned)&TRISF*8)+1;
static volatile bit           TRISF2             @ ((unsigned)&TRISF*8)+2;
static volatile bit           TRISF3             @ ((unsigned)&TRISF*8)+3;
static volatile bit           TRISF4             @ ((unsigned)&TRISF*8)+4;
static volatile bit           TRISF5             @ ((unsigned)&TRISF*8)+5;
static volatile bit           TRISF6             @ ((unsigned)&TRISF*8)+6;
static volatile bit           TRISF7             @ ((unsigned)&TRISF*8)+7;
static volatile bit           TRISF8             @ ((unsigned)&TRISF*8)+8;
static volatile bit           TRIS12             @ ((unsigned)&TRISF*8)+12;
static volatile bit           TRIS13             @ ((unsigned)&TRISF*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      TRIS13             : 1;
       volatile unsigned      TRIS12             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      TRISF8             : 1;
       volatile unsigned      TRISF7             : 1;
       volatile unsigned      TRISF6             : 1;
       volatile unsigned      TRISF5             : 1;
       volatile unsigned      TRISF4             : 1;
       volatile unsigned      TRISF3             : 1;
       volatile unsigned      TRISF2             : 1;
       volatile unsigned      TRISF1             : 1;
       volatile unsigned      TRISF0             : 1;
} TRISFbits @ 0x2DE;

static volatile unsigned int  PORTF              @ 0x2E0;
static volatile bit           RF0                @ ((unsigned)&PORTF*8)+0;
static volatile bit           RF1                @ ((unsigned)&PORTF*8)+1;
static volatile bit           RF2                @ ((unsigned)&PORTF*8)+2;
static volatile bit           RF3                @ ((unsigned)&PORTF*8)+3;
static volatile bit           RF4                @ ((unsigned)&PORTF*8)+4;
static volatile bit           RF5                @ ((unsigned)&PORTF*8)+5;
static volatile bit           RF6                @ ((unsigned)&PORTF*8)+6;
static volatile bit           RF7                @ ((unsigned)&PORTF*8)+7;
static volatile bit           RF8                @ ((unsigned)&PORTF*8)+8;
static volatile bit           RF12               @ ((unsigned)&PORTF*8)+12;
static volatile bit           RF13               @ ((unsigned)&PORTF*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      RF13               : 1;
       volatile unsigned      RF12               : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      RF8                : 1;
       volatile unsigned      RF7                : 1;
       volatile unsigned      RF6                : 1;
       volatile unsigned      RF5                : 1;
       volatile unsigned      RF4                : 1;
       volatile unsigned      RF3                : 1;
       volatile unsigned      RF2                : 1;
       volatile unsigned      RF1                : 1;
       volatile unsigned      RF0                : 1;
} PORTFbits @ 0x2E0;

static volatile unsigned int  LATF               @ 0x2E2;
static volatile bit           LATF0              @ ((unsigned)&LATF*8)+0;
static volatile bit           LATF1              @ ((unsigned)&LATF*8)+1;
static volatile bit           LATF2              @ ((unsigned)&LATF*8)+2;
static volatile bit           LATF3              @ ((unsigned)&LATF*8)+3;
static volatile bit           LATF4              @ ((unsigned)&LATF*8)+4;
static volatile bit           LATF5              @ ((unsigned)&LATF*8)+5;
static volatile bit           LATF6              @ ((unsigned)&LATF*8)+6;
static volatile bit           LATF7              @ ((unsigned)&LATF*8)+7;
static volatile bit           LATF8              @ ((unsigned)&LATF*8)+8;
static volatile bit           LATF12             @ ((unsigned)&LATF*8)+12;
static volatile bit           LATF13             @ ((unsigned)&LATF*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      LATF13             : 1;
       volatile unsigned      LATF12             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      LATF8              : 1;
       volatile unsigned      LATF7              : 1;
       volatile unsigned      LATF6              : 1;
       volatile unsigned      LATF5              : 1;
       volatile unsigned      LATF4              : 1;
       volatile unsigned      LATF3              : 1;
       volatile unsigned      LATF2              : 1;
       volatile unsigned      LATF1              : 1;
       volatile unsigned      LATF0              : 1;
} LATFbits @ 0x2E2;

static volatile unsigned int  ODCF               @ 0x6DE;
static volatile bit           ODCF0              @ ((unsigned)&ODCF*8)+0;
static volatile bit           ODCF1              @ ((unsigned)&ODCF*8)+1;
static volatile bit           ODCF2              @ ((unsigned)&ODCF*8)+2;
static volatile bit           ODCF3              @ ((unsigned)&ODCF*8)+3;
static volatile bit           ODCF4              @ ((unsigned)&ODCF*8)+4;
static volatile bit           ODCF5              @ ((unsigned)&ODCF*8)+5;
static volatile bit           ODCF6              @ ((unsigned)&ODCF*8)+6;
static volatile bit           ODCF7              @ ((unsigned)&ODCF*8)+7;
static volatile bit           ODCF8              @ ((unsigned)&ODCF*8)+8;
static volatile bit           ODCF12             @ ((unsigned)&ODCF*8)+12;
static volatile bit           ODCF13             @ ((unsigned)&ODCF*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      ODCF13             : 1;
       volatile unsigned      ODCF12             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      ODCF8              : 1;
       volatile unsigned      ODCF7              : 1;
       volatile unsigned      ODCF6              : 1;
       volatile unsigned      ODCF5              : 1;
       volatile unsigned      ODCF4              : 1;
       volatile unsigned      ODCF3              : 1;
       volatile unsigned      ODCF2              : 1;
       volatile unsigned      ODCF1              : 1;
       volatile unsigned      ODCF0              : 1;
} ODCFbits @ 0x6DE;

static volatile unsigned int  TRISG              @ 0x2E4;
static volatile bit           TRISG0             @ ((unsigned)&TRISG*8)+0;
static volatile bit           TRISG1             @ ((unsigned)&TRISG*8)+1;
static volatile bit           TRISG2             @ ((unsigned)&TRISG*8)+2;
static volatile bit           TRISG3             @ ((unsigned)&TRISG*8)+3;
static volatile bit           TRISG6             @ ((unsigned)&TRISG*8)+6;
static volatile bit           TRISG7             @ ((unsigned)&TRISG*8)+7;
static volatile bit           TRISG8             @ ((unsigned)&TRISG*8)+8;
static volatile bit           TRISG9             @ ((unsigned)&TRISG*8)+9;
static volatile bit           TRISG12            @ ((unsigned)&TRISG*8)+12;
static volatile bit           TRISG13            @ ((unsigned)&TRISG*8)+13;
static volatile bit           TRISG14            @ ((unsigned)&TRISG*8)+14;
static volatile bit           TRISG15            @ ((unsigned)&TRISG*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      TRISG15            : 1;
       volatile unsigned      TRISG14            : 1;
       volatile unsigned      TRISG13            : 1;
       volatile unsigned      TRISG12            : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      TRISG9             : 1;
       volatile unsigned      TRISG8             : 1;
       volatile unsigned      TRISG7             : 1;
       volatile unsigned      TRISG6             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      TRISG3             : 1;
       volatile unsigned      TRISG2             : 1;
       volatile unsigned      TRISG1             : 1;
       volatile unsigned      TRISG0             : 1;
} TRISGbits @ 0x2E4;

static volatile unsigned int  PORTG              @ 0x2E6;
static volatile bit           RG0                @ ((unsigned)&PORTG*8)+0;
static volatile bit           RG1                @ ((unsigned)&PORTG*8)+1;
static volatile bit           RG2                @ ((unsigned)&PORTG*8)+2;
static volatile bit           RG3                @ ((unsigned)&PORTG*8)+3;
static volatile bit           RG6                @ ((unsigned)&PORTG*8)+6;
static volatile bit           RG7                @ ((unsigned)&PORTG*8)+7;
static volatile bit           RG8                @ ((unsigned)&PORTG*8)+8;
static volatile bit           RG9                @ ((unsigned)&PORTG*8)+9;
static volatile bit           RG12               @ ((unsigned)&PORTG*8)+12;
static volatile bit           RG13               @ ((unsigned)&PORTG*8)+13;
static volatile bit           RG14               @ ((unsigned)&PORTG*8)+14;
static volatile bit           RG15               @ ((unsigned)&PORTG*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      RG15               : 1;
       volatile unsigned      RG14               : 1;
       volatile unsigned      RG13               : 1;
       volatile unsigned      RG12               : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      RG9                : 1;
       volatile unsigned      RG8                : 1;
       volatile unsigned      RG7                : 1;
       volatile unsigned      RG6                : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      RG3                : 1;
       volatile unsigned      RG2                : 1;
       volatile unsigned      RG1                : 1;
       volatile unsigned      RG0                : 1;
} PORTGbits @ 0x2E6;

static volatile unsigned int  LATG               @ 0x2E8;
static volatile bit           LATG0              @ ((unsigned)&LATG*8)+0;
static volatile bit           LATG1              @ ((unsigned)&LATG*8)+1;
static volatile bit           LATG2              @ ((unsigned)&LATG*8)+2;
static volatile bit           LATG3              @ ((unsigned)&LATG*8)+3;
static volatile bit           LATG6              @ ((unsigned)&LATG*8)+6;
static volatile bit           LATG7              @ ((unsigned)&LATG*8)+7;
static volatile bit           LATG8              @ ((unsigned)&LATG*8)+8;
static volatile bit           LATG9              @ ((unsigned)&LATG*8)+9;
static volatile bit           LATG12             @ ((unsigned)&LATG*8)+12;
static volatile bit           LATG13             @ ((unsigned)&LATG*8)+13;
static volatile bit           LATG14             @ ((unsigned)&LATG*8)+14;
static volatile bit           LATG15             @ ((unsigned)&LATG*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      LATG15             : 1;
       volatile unsigned      LATG14             : 1;
       volatile unsigned      LATG13             : 1;
       volatile unsigned      LATG12             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      LATG9              : 1;
       volatile unsigned      LATG8              : 1;
       volatile unsigned      LATG7              : 1;
       volatile unsigned      LATG6              : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      LATG3              : 1;
       volatile unsigned      LATG2              : 1;
       volatile unsigned      LATG1              : 1;
       volatile unsigned      LATG0              : 1;
} LATGbits @ 0x2E8;

static volatile unsigned int  ODCG               @ 0x6E4;
static volatile bit           ODCG0              @ ((unsigned)&ODCG*8)+0;
static volatile bit           ODCG1              @ ((unsigned)&ODCG*8)+1;
static volatile bit           ODCG2              @ ((unsigned)&ODCG*8)+2;
static volatile bit           ODCG3              @ ((unsigned)&ODCG*8)+3;
static volatile bit           ODCG6              @ ((unsigned)&ODCG*8)+6;
static volatile bit           ODCG7              @ ((unsigned)&ODCG*8)+7;
static volatile bit           ODCG8              @ ((unsigned)&ODCG*8)+8;
static volatile bit           ODCG9              @ ((unsigned)&ODCG*8)+9;
static volatile bit           ODCG12             @ ((unsigned)&ODCG*8)+12;
static volatile bit           ODCG13             @ ((unsigned)&ODCG*8)+13;
static volatile bit           ODCG14             @ ((unsigned)&ODCG*8)+14;
static volatile bit           ODCG15             @ ((unsigned)&ODCG*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      ODCG15             : 1;
       volatile unsigned      ODCG14             : 1;
       volatile unsigned      ODCG13             : 1;
       volatile unsigned      ODCG12             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      ODCG9              : 1;
       volatile unsigned      ODCG8              : 1;
       volatile unsigned      ODCG7              : 1;
       volatile unsigned      ODCG6              : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      ODCG3              : 1;
       volatile unsigned      ODCG2              : 1;
       volatile unsigned      ODCG1              : 1;
       volatile unsigned      ODCG0              : 1;
} ODCGbits @ 0x6E4;

static volatile unsigned int  ADC1BUF0           @ 0x300;
static volatile unsigned int  AD1CON1            @ 0x320;
static volatile bit           AD1CON_CONV        @ ((unsigned)&AD1CON1*8)+0;
static volatile bit           AD1CON_SAMP        @ ((unsigned)&AD1CON1*8)+1;
static volatile bit           AD1CON_ASAM        @ ((unsigned)&AD1CON1*8)+2;
static volatile bit           AD1CON_SIMSAM      @ ((unsigned)&AD1CON1*8)+3;
static volatile bit           AD1CON_SSRC0       @ ((unsigned)&AD1CON1*8)+5;
static volatile bit           AD1CON_SSRC1       @ ((unsigned)&AD1CON1*8)+6;
static volatile bit           AD1CON_SSRC2       @ ((unsigned)&AD1CON1*8)+7;
static volatile bit           AD1CON_FORM0       @ ((unsigned)&AD1CON1*8)+8;
static volatile bit           AD1CON_FORM1       @ ((unsigned)&AD1CON1*8)+9;
static volatile bit           AD1CON_ADSIDL      @ ((unsigned)&AD1CON1*8)+13;
static volatile bit           AD1CON_ADON        @ ((unsigned)&AD1CON1*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      ADON               : 1;
                unsigned                         : 1;
       volatile unsigned      ADSIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      FORM               : 2;
       volatile unsigned      SSRC               : 3;
                unsigned                         : 1;
       volatile unsigned      SIMSAM             : 1;
       volatile unsigned      ASAM               : 1;
       volatile unsigned      SAMP               : 1;
       volatile unsigned      CONV               : 1;
} AD1CON1bits @ 0x320;

static volatile unsigned int  AD1CON2            @ 0x322;
static volatile bit           AD1CON_ALTS        @ ((unsigned)&AD1CON2*8)+0;
static volatile bit           AD1CON_BUFM        @ ((unsigned)&AD1CON2*8)+1;
static volatile bit           AD1CON_SMPI0       @ ((unsigned)&AD1CON2*8)+2;
static volatile bit           AD1CON_SMPI1       @ ((unsigned)&AD1CON2*8)+3;
static volatile bit           AD1CON_SMPI2       @ ((unsigned)&AD1CON2*8)+4;
static volatile bit           AD1CON_SMPI3       @ ((unsigned)&AD1CON2*8)+5;
static volatile bit           AD1CON_BUFS        @ ((unsigned)&AD1CON2*8)+7;
static volatile bit           AD1CON_CHPS0       @ ((unsigned)&AD1CON2*8)+8;
static volatile bit           AD1CON_CHPS1       @ ((unsigned)&AD1CON2*8)+9;
static volatile bit           AD1CON_CSCNA       @ ((unsigned)&AD1CON2*8)+10;
static volatile bit           AD1CON_OFFCAL      @ ((unsigned)&AD1CON2*8)+12;
static volatile bit           AD1CON_VCFG0       @ ((unsigned)&AD1CON2*8)+13;
static volatile bit           AD1CON_VCFG1       @ ((unsigned)&AD1CON2*8)+14;
static volatile bit           AD1CON_VCFG2       @ ((unsigned)&AD1CON2*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      VCFG               : 3;
       volatile unsigned      OFFCAL             : 1;
                unsigned                         : 1;
       volatile unsigned      CSCNA              : 1;
       volatile unsigned      CHPS               : 2;
       volatile unsigned      BUFS               : 1;
                unsigned                         : 1;
       volatile unsigned      SMPI               : 4;
       volatile unsigned      BUFM               : 1;
       volatile unsigned      ALTS               : 1;
} AD1CON2bits @ 0x322;

static volatile unsigned int  AD1CON3            @ 0x324;
static volatile bit           AD1CON_ADCS0       @ ((unsigned)&AD1CON3*8)+0;
static volatile bit           AD1CON_ADCS1       @ ((unsigned)&AD1CON3*8)+1;
static volatile bit           AD1CON_ADCS2       @ ((unsigned)&AD1CON3*8)+2;
static volatile bit           AD1CON_ADCS3       @ ((unsigned)&AD1CON3*8)+3;
static volatile bit           AD1CON_ADCS4       @ ((unsigned)&AD1CON3*8)+4;
static volatile bit           AD1CON_ADCS5       @ ((unsigned)&AD1CON3*8)+5;
static volatile bit           AD1CON_ADRC        @ ((unsigned)&AD1CON3*8)+7;
static volatile bit           AD1CON_SAMC0       @ ((unsigned)&AD1CON3*8)+8;
static volatile bit           AD1CON_SAMC1       @ ((unsigned)&AD1CON3*8)+9;
static volatile bit           AD1CON_SAMC2       @ ((unsigned)&AD1CON3*8)+10;
static volatile bit           AD1CON_SAMC3       @ ((unsigned)&AD1CON3*8)+11;
static volatile bit           AD1CON_SAMC4       @ ((unsigned)&AD1CON3*8)+12;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      SAMC               : 5;
       volatile unsigned      ADRC               : 1;
                unsigned                         : 1;
       volatile unsigned      ADCS               : 6;
} AD1CON3bits @ 0x324;

static volatile unsigned int  AD1CON4            @ 0x332;
static volatile bit           AD1CON_DMABL0      @ ((unsigned)&AD1CON4*8)+0;
static volatile bit           AD1CON_DMABL1      @ ((unsigned)&AD1CON4*8)+1;
static volatile bit           AD1CON_DMABL2      @ ((unsigned)&AD1CON4*8)+2;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      DMABL              : 3;
} AD1CON4bits @ 0x332;

static volatile unsigned int  AD1CHS123          @ 0x326;
static volatile bit           AD1_CH123SA        @ ((unsigned)&AD1CHS123*8)+0;
static volatile bit           AD1_CH123NA0       @ ((unsigned)&AD1CHS123*8)+1;
static volatile bit           AD1_CH123NA1       @ ((unsigned)&AD1CHS123*8)+2;
static volatile bit           AD1_CH123SB        @ ((unsigned)&AD1CHS123*8)+8;
static volatile bit           AD1_CH123NB0       @ ((unsigned)&AD1CHS123*8)+9;
static volatile bit           AD1_CH123NB1       @ ((unsigned)&AD1CHS123*8)+10;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      CH123NB            : 2;
       volatile unsigned      CH123SB            : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      CH123NA            : 2;
       volatile unsigned      CH123SA            : 1;
} AD1CHS123bits @ 0x326;

static volatile unsigned int  AD1CHS0            @ 0x328;
static volatile bit           AD1_CH0SA0         @ ((unsigned)&AD1CHS0*8)+0;
static volatile bit           AD1_CH0SA1         @ ((unsigned)&AD1CHS0*8)+1;
static volatile bit           AD1_CH0SA2         @ ((unsigned)&AD1CHS0*8)+2;
static volatile bit           AD1_CH0SA3         @ ((unsigned)&AD1CHS0*8)+3;
static volatile bit           AD1_CH0NA          @ ((unsigned)&AD1CHS0*8)+7;
static volatile bit           AD1_CH0SB0         @ ((unsigned)&AD1CHS0*8)+8;
static volatile bit           AD1_CH0SB1         @ ((unsigned)&AD1CHS0*8)+9;
static volatile bit           AD1_CH0SB2         @ ((unsigned)&AD1CHS0*8)+10;
static volatile bit           AD1_CH0SB3         @ ((unsigned)&AD1CHS0*8)+11;
static volatile bit           AD1_CH0NB          @ ((unsigned)&AD1CHS0*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      CH0NB              : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      CH0SB              : 4;
       volatile unsigned      CH0NA              : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      CH0SA              : 4;
} AD1CHS0bits @ 0x328;

static volatile unsigned int  AD1PCFGL           @ 0x32C;
static volatile unsigned int  AD1CSSL            @ 0x330;
static volatile unsigned int  AD1PCFGH           @ 0x32A;
static volatile unsigned int  AD1CSSH            @ 0x32E;
static volatile bit           CSSH0              @ ((unsigned)&AD1CSSH*8)+0;
static volatile bit           CSSH1              @ ((unsigned)&AD1CSSH*8)+1;
static volatile bit           CSSH2              @ ((unsigned)&AD1CSSH*8)+2;
static volatile bit           CSSH3              @ ((unsigned)&AD1CSSH*8)+3;
static volatile bit           CSSH4              @ ((unsigned)&AD1CSSH*8)+4;
static volatile bit           CSSH5              @ ((unsigned)&AD1CSSH*8)+5;
static volatile bit           CSSH6              @ ((unsigned)&AD1CSSH*8)+6;
static volatile bit           CSSH7              @ ((unsigned)&AD1CSSH*8)+7;
static volatile bit           CSSH8              @ ((unsigned)&AD1CSSH*8)+8;
static volatile bit           CSSH9              @ ((unsigned)&AD1CSSH*8)+9;
static volatile bit           CSSH10             @ ((unsigned)&AD1CSSH*8)+10;
static volatile bit           CSSH11             @ ((unsigned)&AD1CSSH*8)+11;
static volatile bit           CSSH12             @ ((unsigned)&AD1CSSH*8)+12;
static volatile bit           CSSH13             @ ((unsigned)&AD1CSSH*8)+13;
static volatile bit           CSSH14             @ ((unsigned)&AD1CSSH*8)+14;
static volatile bit           CSSH15             @ ((unsigned)&AD1CSSH*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      CSSH               : 16;
} AD1CSSHbits @ 0x32E;

static volatile unsigned int  ADC2BUF0           @ 0x340;
static volatile unsigned int  AD2CON1            @ 0x360;
static volatile bit           AD2CON_CONV        @ ((unsigned)&AD2CON1*8)+0;
static volatile bit           AD2CON_SAMP        @ ((unsigned)&AD2CON1*8)+1;
static volatile bit           AD2CON_ASAM        @ ((unsigned)&AD2CON1*8)+2;
static volatile bit           AD2CON_SIMSAM      @ ((unsigned)&AD2CON1*8)+3;
static volatile bit           AD2CON_SSRC0       @ ((unsigned)&AD2CON1*8)+5;
static volatile bit           AD2CON_SSRC1       @ ((unsigned)&AD2CON1*8)+6;
static volatile bit           AD2CON_SSRC2       @ ((unsigned)&AD2CON1*8)+7;
static volatile bit           AD2CON_FORM0       @ ((unsigned)&AD2CON1*8)+8;
static volatile bit           AD2CON_FORM1       @ ((unsigned)&AD2CON1*8)+9;
static volatile bit           AD2CON_ADSIDL      @ ((unsigned)&AD2CON1*8)+13;
static volatile bit           AD2CON_ADON        @ ((unsigned)&AD2CON1*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      ADON               : 1;
                unsigned                         : 1;
       volatile unsigned      ADSIDL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      FORM               : 2;
       volatile unsigned      SSRC               : 3;
                unsigned                         : 1;
       volatile unsigned      SIMSAM             : 1;
       volatile unsigned      ASAM               : 1;
       volatile unsigned      SAMP               : 1;
       volatile unsigned      CONV               : 1;
} AD2CON1bits @ 0x360;

static volatile unsigned int  AD2CON2            @ 0x362;
static volatile bit           AD2CON_ALTS        @ ((unsigned)&AD2CON2*8)+0;
static volatile bit           AD2CON_BUFM        @ ((unsigned)&AD2CON2*8)+1;
static volatile bit           AD2CON_SMPI0       @ ((unsigned)&AD2CON2*8)+2;
static volatile bit           AD2CON_SMPI1       @ ((unsigned)&AD2CON2*8)+3;
static volatile bit           AD2CON_SMPI2       @ ((unsigned)&AD2CON2*8)+4;
static volatile bit           AD2CON_SMPI3       @ ((unsigned)&AD2CON2*8)+5;
static volatile bit           AD2CON_BUFS        @ ((unsigned)&AD2CON2*8)+7;
static volatile bit           AD2CON_CHPS0       @ ((unsigned)&AD2CON2*8)+8;
static volatile bit           AD2CON_CHPS1       @ ((unsigned)&AD2CON2*8)+9;
static volatile bit           AD2CON_CSCNA       @ ((unsigned)&AD2CON2*8)+10;
static volatile bit           AD2CON_OFFCAL      @ ((unsigned)&AD2CON2*8)+12;
static volatile bit           AD2CON_VCFG0       @ ((unsigned)&AD2CON2*8)+13;
static volatile bit           AD2CON_VCFG1       @ ((unsigned)&AD2CON2*8)+14;
static volatile bit           AD2CON_VCFG2       @ ((unsigned)&AD2CON2*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      VCFG               : 3;
       volatile unsigned      OFFCAL             : 1;
                unsigned                         : 1;
       volatile unsigned      CSCNA              : 1;
       volatile unsigned      CHPS               : 2;
       volatile unsigned      BUFS               : 1;
                unsigned                         : 1;
       volatile unsigned      SMPI               : 4;
       volatile unsigned      BUFM               : 1;
       volatile unsigned      ALTS               : 1;
} AD2CON2bits @ 0x362;

static volatile unsigned int  AD2CON3            @ 0x364;
static volatile bit           AD2CON_ADCS0       @ ((unsigned)&AD2CON3*8)+0;
static volatile bit           AD2CON_ADCS1       @ ((unsigned)&AD2CON3*8)+1;
static volatile bit           AD2CON_ADCS2       @ ((unsigned)&AD2CON3*8)+2;
static volatile bit           AD2CON_ADCS3       @ ((unsigned)&AD2CON3*8)+3;
static volatile bit           AD2CON_ADCS4       @ ((unsigned)&AD2CON3*8)+4;
static volatile bit           AD2CON_ADCS5       @ ((unsigned)&AD2CON3*8)+5;
static volatile bit           AD2CON_ADRC        @ ((unsigned)&AD2CON3*8)+7;
static volatile bit           AD2CON_SAMC0       @ ((unsigned)&AD2CON3*8)+8;
static volatile bit           AD2CON_SAMC1       @ ((unsigned)&AD2CON3*8)+9;
static volatile bit           AD2CON_SAMC2       @ ((unsigned)&AD2CON3*8)+10;
static volatile bit           AD2CON_SAMC3       @ ((unsigned)&AD2CON3*8)+11;
static volatile bit           AD2CON_SAMC4       @ ((unsigned)&AD2CON3*8)+12;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      SAMC               : 5;
       volatile unsigned      ADRC               : 1;
                unsigned                         : 1;
       volatile unsigned      ADCS               : 6;
} AD2CON3bits @ 0x364;

static volatile unsigned int  AD2CON4            @ 0x372;
static volatile bit           AD2CON_DMABL0      @ ((unsigned)&AD2CON4*8)+0;
static volatile bit           AD2CON_DMABL1      @ ((unsigned)&AD2CON4*8)+1;
static volatile bit           AD2CON_DMABL2      @ ((unsigned)&AD2CON4*8)+2;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      DMABL              : 3;
} AD2CON4bits @ 0x372;

static volatile unsigned int  AD2CHS123          @ 0x366;
static volatile bit           AD2_CH123SA        @ ((unsigned)&AD2CHS123*8)+0;
static volatile bit           AD2_CH123NA0       @ ((unsigned)&AD2CHS123*8)+1;
static volatile bit           AD2_CH123NA1       @ ((unsigned)&AD2CHS123*8)+2;
static volatile bit           AD2_CH123SB        @ ((unsigned)&AD2CHS123*8)+8;
static volatile bit           AD2_CH123NB0       @ ((unsigned)&AD2CHS123*8)+9;
static volatile bit           AD2_CH123NB1       @ ((unsigned)&AD2CHS123*8)+10;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      CH123NB            : 2;
       volatile unsigned      CH123SB            : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      CH123NA            : 2;
       volatile unsigned      CH123SA            : 1;
} AD2CHS123bits @ 0x366;

static volatile unsigned int  AD2CHS0            @ 0x368;
static volatile bit           AD2_CH0SA0         @ ((unsigned)&AD2CHS0*8)+0;
static volatile bit           AD2_CH0SA1         @ ((unsigned)&AD2CHS0*8)+1;
static volatile bit           AD2_CH0SA2         @ ((unsigned)&AD2CHS0*8)+2;
static volatile bit           AD2_CH0SA3         @ ((unsigned)&AD2CHS0*8)+3;
static volatile bit           AD2_CH0NA          @ ((unsigned)&AD2CHS0*8)+7;
static volatile bit           AD2_CH0SB0         @ ((unsigned)&AD2CHS0*8)+8;
static volatile bit           AD2_CH0SB1         @ ((unsigned)&AD2CHS0*8)+9;
static volatile bit           AD2_CH0SB2         @ ((unsigned)&AD2CHS0*8)+10;
static volatile bit           AD2_CH0SB3         @ ((unsigned)&AD2CHS0*8)+11;
static volatile bit           AD2_CH0NB          @ ((unsigned)&AD2CHS0*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      CH0NB              : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      CH0SB              : 4;
       volatile unsigned      CH0NA              : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      CH0SA              : 4;
} AD2CHS0bits @ 0x368;

static volatile unsigned int  AD2PCFG            @ 0x36C;
static volatile unsigned int  AD2CSSL            @ 0x370;
static volatile unsigned int  DMA0CON            @ 0x380;
static volatile bit           DMA0_MODE0         @ ((unsigned)&DMA0CON*8)+0;
static volatile bit           DMA0_MODE1         @ ((unsigned)&DMA0CON*8)+1;
static volatile bit           DMA0_AMODE0        @ ((unsigned)&DMA0CON*8)+4;
static volatile bit           DMA0_AMODE1        @ ((unsigned)&DMA0CON*8)+5;
static volatile bit           DMA0_NULLW         @ ((unsigned)&DMA0CON*8)+11;
static volatile bit           DMA0_HALF          @ ((unsigned)&DMA0CON*8)+12;
static volatile bit           DMA0_DIR           @ ((unsigned)&DMA0CON*8)+13;
static volatile bit           DMA0_SIZE          @ ((unsigned)&DMA0CON*8)+14;
static volatile bit           DMA0_CHEN          @ ((unsigned)&DMA0CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      CHEN               : 1;
       volatile unsigned      SIZE               : 1;
       volatile unsigned      DIR                : 1;
       volatile unsigned      HALF               : 1;
       volatile unsigned      NULLW              : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      AMODE              : 2;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      MODE               : 2;
} DMA0CONbits @ 0x380;

static volatile unsigned int  DMA0REQ            @ 0x382;
static volatile bit           DMA0_IRQSEL0       @ ((unsigned)&DMA0REQ*8)+0;
static volatile bit           DMA0_IRQSEL1       @ ((unsigned)&DMA0REQ*8)+1;
static volatile bit           DMA0_IRQSEL2       @ ((unsigned)&DMA0REQ*8)+2;
static volatile bit           DMA0_IRQSEL3       @ ((unsigned)&DMA0REQ*8)+3;
static volatile bit           DMA0_IRQSEL4       @ ((unsigned)&DMA0REQ*8)+4;
static volatile bit           DMA0_IRQSEL5       @ ((unsigned)&DMA0REQ*8)+5;
static volatile bit           DMA0_IRQSEL6       @ ((unsigned)&DMA0REQ*8)+6;
static volatile bit           DMA0_FORCE         @ ((unsigned)&DMA0REQ*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      FORCE              : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      IRQSEL             : 7;
} DMA0REQbits @ 0x382;

static volatile unsigned int  DMA0STA            @ 0x384;
static volatile unsigned int  DMA0STB            @ 0x386;
static volatile unsigned int  DMA0PAD            @ 0x388;
static volatile unsigned int  DMA0CNT            @ 0x38A;
static volatile unsigned int  DMA1CON            @ 0x38C;
static volatile bit           DMA1_MODE0         @ ((unsigned)&DMA1CON*8)+0;
static volatile bit           DMA1_MODE1         @ ((unsigned)&DMA1CON*8)+1;
static volatile bit           DMA1_AMODE0        @ ((unsigned)&DMA1CON*8)+4;
static volatile bit           DMA1_AMODE1        @ ((unsigned)&DMA1CON*8)+5;
static volatile bit           DMA1_NULLW         @ ((unsigned)&DMA1CON*8)+11;
static volatile bit           DMA1_HALF          @ ((unsigned)&DMA1CON*8)+12;
static volatile bit           DMA1_DIR           @ ((unsigned)&DMA1CON*8)+13;
static volatile bit           DMA1_SIZE          @ ((unsigned)&DMA1CON*8)+14;
static volatile bit           DMA1_CHEN          @ ((unsigned)&DMA1CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      CHEN               : 1;
       volatile unsigned      SIZE               : 1;
       volatile unsigned      DIR                : 1;
       volatile unsigned      HALF               : 1;
       volatile unsigned      NULLW              : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      AMODE              : 2;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      MODE               : 2;
} DMA1CONbits @ 0x38C;

static volatile unsigned int  DMA1REQ            @ 0x38E;
static volatile bit           DMA1_IRQSEL0       @ ((unsigned)&DMA1REQ*8)+0;
static volatile bit           DMA1_IRQSEL1       @ ((unsigned)&DMA1REQ*8)+1;
static volatile bit           DMA1_IRQSEL2       @ ((unsigned)&DMA1REQ*8)+2;
static volatile bit           DMA1_IRQSEL3       @ ((unsigned)&DMA1REQ*8)+3;
static volatile bit           DMA1_IRQSEL4       @ ((unsigned)&DMA1REQ*8)+4;
static volatile bit           DMA1_IRQSEL5       @ ((unsigned)&DMA1REQ*8)+5;
static volatile bit           DMA1_IRQSEL6       @ ((unsigned)&DMA1REQ*8)+6;
static volatile bit           DMA1_FORCE         @ ((unsigned)&DMA1REQ*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      FORCE              : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      IRQSEL             : 7;
} DMA1REQbits @ 0x38E;

static volatile unsigned int  DMA1STA            @ 0x390;
static volatile unsigned int  DMA1STB            @ 0x392;
static volatile unsigned int  DMA1PAD            @ 0x394;
static volatile unsigned int  DMA1CNT            @ 0x396;
static volatile unsigned int  DMA2CON            @ 0x398;
static volatile bit           DMA2_MODE0         @ ((unsigned)&DMA2CON*8)+0;
static volatile bit           DMA2_MODE1         @ ((unsigned)&DMA2CON*8)+1;
static volatile bit           DMA2_AMODE0        @ ((unsigned)&DMA2CON*8)+4;
static volatile bit           DMA2_AMODE1        @ ((unsigned)&DMA2CON*8)+5;
static volatile bit           DMA2_NULLW         @ ((unsigned)&DMA2CON*8)+11;
static volatile bit           DMA2_HALF          @ ((unsigned)&DMA2CON*8)+12;
static volatile bit           DMA2_DIR           @ ((unsigned)&DMA2CON*8)+13;
static volatile bit           DMA2_SIZE          @ ((unsigned)&DMA2CON*8)+14;
static volatile bit           DMA2_CHEN          @ ((unsigned)&DMA2CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      CHEN               : 1;
       volatile unsigned      SIZE               : 1;
       volatile unsigned      DIR                : 1;
       volatile unsigned      HALF               : 1;
       volatile unsigned      NULLW              : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      AMODE              : 2;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      MODE               : 2;
} DMA2CONbits @ 0x398;

static volatile unsigned int  DMA2REQ            @ 0x39A;
static volatile bit           DMA2_IRQSEL0       @ ((unsigned)&DMA2REQ*8)+0;
static volatile bit           DMA2_IRQSEL1       @ ((unsigned)&DMA2REQ*8)+1;
static volatile bit           DMA2_IRQSEL2       @ ((unsigned)&DMA2REQ*8)+2;
static volatile bit           DMA2_IRQSEL3       @ ((unsigned)&DMA2REQ*8)+3;
static volatile bit           DMA2_IRQSEL4       @ ((unsigned)&DMA2REQ*8)+4;
static volatile bit           DMA2_IRQSEL5       @ ((unsigned)&DMA2REQ*8)+5;
static volatile bit           DMA2_IRQSEL6       @ ((unsigned)&DMA2REQ*8)+6;
static volatile bit           DMA2_FORCE         @ ((unsigned)&DMA2REQ*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      FORCE              : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      IRQSEL             : 7;
} DMA2REQbits @ 0x39A;

static volatile unsigned int  DMA2STA            @ 0x39C;
static volatile unsigned int  DMA2STB            @ 0x39E;
static volatile unsigned int  DMA2PAD            @ 0x3A0;
static volatile unsigned int  DMA2CNT            @ 0x3A2;
static volatile unsigned int  DMA3CON            @ 0x3A4;
static volatile bit           DMA3_MODE0         @ ((unsigned)&DMA3CON*8)+0;
static volatile bit           DMA3_MODE1         @ ((unsigned)&DMA3CON*8)+1;
static volatile bit           DMA3_AMODE0        @ ((unsigned)&DMA3CON*8)+4;
static volatile bit           DMA3_AMODE1        @ ((unsigned)&DMA3CON*8)+5;
static volatile bit           DMA3_NULLW         @ ((unsigned)&DMA3CON*8)+11;
static volatile bit           DMA3_HALF          @ ((unsigned)&DMA3CON*8)+12;
static volatile bit           DMA3_DIR           @ ((unsigned)&DMA3CON*8)+13;
static volatile bit           DMA3_SIZE          @ ((unsigned)&DMA3CON*8)+14;
static volatile bit           DMA3_CHEN          @ ((unsigned)&DMA3CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      CHEN               : 1;
       volatile unsigned      SIZE               : 1;
       volatile unsigned      DIR                : 1;
       volatile unsigned      HALF               : 1;
       volatile unsigned      NULLW              : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      AMODE              : 2;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      MODE               : 2;
} DMA3CONbits @ 0x3A4;

static volatile unsigned int  DMA3REQ            @ 0x3A6;
static volatile bit           DMA3_IRQSEL0       @ ((unsigned)&DMA3REQ*8)+0;
static volatile bit           DMA3_IRQSEL1       @ ((unsigned)&DMA3REQ*8)+1;
static volatile bit           DMA3_IRQSEL2       @ ((unsigned)&DMA3REQ*8)+2;
static volatile bit           DMA3_IRQSEL3       @ ((unsigned)&DMA3REQ*8)+3;
static volatile bit           DMA3_IRQSEL4       @ ((unsigned)&DMA3REQ*8)+4;
static volatile bit           DMA3_IRQSEL5       @ ((unsigned)&DMA3REQ*8)+5;
static volatile bit           DMA3_IRQSEL6       @ ((unsigned)&DMA3REQ*8)+6;
static volatile bit           DMA3_FORCE         @ ((unsigned)&DMA3REQ*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      FORCE              : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      IRQSEL             : 7;
} DMA3REQbits @ 0x3A6;

static volatile unsigned int  DMA3STA            @ 0x3A8;
static volatile unsigned int  DMA3STB            @ 0x3AA;
static volatile unsigned int  DMA3PAD            @ 0x3AC;
static volatile unsigned int  DMA3CNT            @ 0x3AE;
static volatile unsigned int  DMA4CON            @ 0x3B0;
static volatile bit           DMA4_MODE0         @ ((unsigned)&DMA4CON*8)+0;
static volatile bit           DMA4_MODE1         @ ((unsigned)&DMA4CON*8)+1;
static volatile bit           DMA4_AMODE0        @ ((unsigned)&DMA4CON*8)+4;
static volatile bit           DMA4_AMODE1        @ ((unsigned)&DMA4CON*8)+5;
static volatile bit           DMA4_NULLW         @ ((unsigned)&DMA4CON*8)+11;
static volatile bit           DMA4_HALF          @ ((unsigned)&DMA4CON*8)+12;
static volatile bit           DMA4_DIR           @ ((unsigned)&DMA4CON*8)+13;
static volatile bit           DMA4_SIZE          @ ((unsigned)&DMA4CON*8)+14;
static volatile bit           DMA4_CHEN          @ ((unsigned)&DMA4CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      CHEN               : 1;
       volatile unsigned      SIZE               : 1;
       volatile unsigned      DIR                : 1;
       volatile unsigned      HALF               : 1;
       volatile unsigned      NULLW              : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      AMODE              : 2;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      MODE               : 2;
} DMA4CONbits @ 0x3B0;

static volatile unsigned int  DMA4REQ            @ 0x3B2;
static volatile bit           DMA4_IRQSEL0       @ ((unsigned)&DMA4REQ*8)+0;
static volatile bit           DMA4_IRQSEL1       @ ((unsigned)&DMA4REQ*8)+1;
static volatile bit           DMA4_IRQSEL2       @ ((unsigned)&DMA4REQ*8)+2;
static volatile bit           DMA4_IRQSEL3       @ ((unsigned)&DMA4REQ*8)+3;
static volatile bit           DMA4_IRQSEL4       @ ((unsigned)&DMA4REQ*8)+4;
static volatile bit           DMA4_IRQSEL5       @ ((unsigned)&DMA4REQ*8)+5;
static volatile bit           DMA4_IRQSEL6       @ ((unsigned)&DMA4REQ*8)+6;
static volatile bit           DMA4_FORCE         @ ((unsigned)&DMA4REQ*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      FORCE              : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      IRQSEL             : 7;
} DMA4REQbits @ 0x3B2;

static volatile unsigned int  DMA4STA            @ 0x3B4;
static volatile unsigned int  DMA4STB            @ 0x3B6;
static volatile unsigned int  DMA4PAD            @ 0x3B8;
static volatile unsigned int  DMA4CNT            @ 0x3BA;
static volatile unsigned int  DMA5CON            @ 0x3BC;
static volatile bit           DMA5_MODE0         @ ((unsigned)&DMA5CON*8)+0;
static volatile bit           DMA5_MODE1         @ ((unsigned)&DMA5CON*8)+1;
static volatile bit           DMA5_AMODE0        @ ((unsigned)&DMA5CON*8)+4;
static volatile bit           DMA5_AMODE1        @ ((unsigned)&DMA5CON*8)+5;
static volatile bit           DMA5_NULLW         @ ((unsigned)&DMA5CON*8)+11;
static volatile bit           DMA5_HALF          @ ((unsigned)&DMA5CON*8)+12;
static volatile bit           DMA5_DIR           @ ((unsigned)&DMA5CON*8)+13;
static volatile bit           DMA5_SIZE          @ ((unsigned)&DMA5CON*8)+14;
static volatile bit           DMA5_CHEN          @ ((unsigned)&DMA5CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      CHEN               : 1;
       volatile unsigned      SIZE               : 1;
       volatile unsigned      DIR                : 1;
       volatile unsigned      HALF               : 1;
       volatile unsigned      NULLW              : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      AMODE              : 2;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      MODE               : 2;
} DMA5CONbits @ 0x3BC;

static volatile unsigned int  DMA5REQ            @ 0x3BE;
static volatile bit           DMA5_IRQSEL0       @ ((unsigned)&DMA5REQ*8)+0;
static volatile bit           DMA5_IRQSEL1       @ ((unsigned)&DMA5REQ*8)+1;
static volatile bit           DMA5_IRQSEL2       @ ((unsigned)&DMA5REQ*8)+2;
static volatile bit           DMA5_IRQSEL3       @ ((unsigned)&DMA5REQ*8)+3;
static volatile bit           DMA5_IRQSEL4       @ ((unsigned)&DMA5REQ*8)+4;
static volatile bit           DMA5_IRQSEL5       @ ((unsigned)&DMA5REQ*8)+5;
static volatile bit           DMA5_IRQSEL6       @ ((unsigned)&DMA5REQ*8)+6;
static volatile bit           DMA5_FORCE         @ ((unsigned)&DMA5REQ*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      FORCE              : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      IRQSEL             : 7;
} DMA5REQbits @ 0x3BE;

static volatile unsigned int  DMA5STA            @ 0x3C0;
static volatile unsigned int  DMA5STB            @ 0x3C2;
static volatile unsigned int  DMA5PAD            @ 0x3C4;
static volatile unsigned int  DMA5CNT            @ 0x3C6;
static volatile unsigned int  DMA6CON            @ 0x3C8;
static volatile bit           DMA6_MODE0         @ ((unsigned)&DMA6CON*8)+0;
static volatile bit           DMA6_MODE1         @ ((unsigned)&DMA6CON*8)+1;
static volatile bit           DMA6_AMODE0        @ ((unsigned)&DMA6CON*8)+4;
static volatile bit           DMA6_AMODE1        @ ((unsigned)&DMA6CON*8)+5;
static volatile bit           DMA6_NULLW         @ ((unsigned)&DMA6CON*8)+11;
static volatile bit           DMA6_HALF          @ ((unsigned)&DMA6CON*8)+12;
static volatile bit           DMA6_DIR           @ ((unsigned)&DMA6CON*8)+13;
static volatile bit           DMA6_SIZE          @ ((unsigned)&DMA6CON*8)+14;
static volatile bit           DMA6_CHEN          @ ((unsigned)&DMA6CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      CHEN               : 1;
       volatile unsigned      SIZE               : 1;
       volatile unsigned      DIR                : 1;
       volatile unsigned      HALF               : 1;
       volatile unsigned      NULLW              : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      AMODE              : 2;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      MODE               : 2;
} DMA6CONbits @ 0x3C8;

static volatile unsigned int  DMA6REQ            @ 0x3CA;
static volatile bit           DMA6_IRQSEL0       @ ((unsigned)&DMA6REQ*8)+0;
static volatile bit           DMA6_IRQSEL1       @ ((unsigned)&DMA6REQ*8)+1;
static volatile bit           DMA6_IRQSEL2       @ ((unsigned)&DMA6REQ*8)+2;
static volatile bit           DMA6_IRQSEL3       @ ((unsigned)&DMA6REQ*8)+3;
static volatile bit           DMA6_IRQSEL4       @ ((unsigned)&DMA6REQ*8)+4;
static volatile bit           DMA6_IRQSEL5       @ ((unsigned)&DMA6REQ*8)+5;
static volatile bit           DMA6_IRQSEL6       @ ((unsigned)&DMA6REQ*8)+6;
static volatile bit           DMA6_FORCE         @ ((unsigned)&DMA6REQ*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      FORCE              : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      IRQSEL             : 7;
} DMA6REQbits @ 0x3CA;

static volatile unsigned int  DMA6STA            @ 0x3CC;
static volatile unsigned int  DMA6STB            @ 0x3CE;
static volatile unsigned int  DMA6PAD            @ 0x3D0;
static volatile unsigned int  DMA6CNT            @ 0x3D2;
static volatile unsigned int  DMA7CON            @ 0x3D4;
static volatile bit           DMA7_MODE0         @ ((unsigned)&DMA7CON*8)+0;
static volatile bit           DMA7_MODE1         @ ((unsigned)&DMA7CON*8)+1;
static volatile bit           DMA7_AMODE0        @ ((unsigned)&DMA7CON*8)+4;
static volatile bit           DMA7_AMODE1        @ ((unsigned)&DMA7CON*8)+5;
static volatile bit           DMA7_NULLW         @ ((unsigned)&DMA7CON*8)+11;
static volatile bit           DMA7_HALF          @ ((unsigned)&DMA7CON*8)+12;
static volatile bit           DMA7_DIR           @ ((unsigned)&DMA7CON*8)+13;
static volatile bit           DMA7_SIZE          @ ((unsigned)&DMA7CON*8)+14;
static volatile bit           DMA7_CHEN          @ ((unsigned)&DMA7CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      CHEN               : 1;
       volatile unsigned      SIZE               : 1;
       volatile unsigned      DIR                : 1;
       volatile unsigned      HALF               : 1;
       volatile unsigned      NULLW              : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      AMODE              : 2;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      MODE               : 2;
} DMA7CONbits @ 0x3D4;

static volatile unsigned int  DMA7REQ            @ 0x3D6;
static volatile bit           DMA7_IRQSEL0       @ ((unsigned)&DMA7REQ*8)+0;
static volatile bit           DMA7_IRQSEL1       @ ((unsigned)&DMA7REQ*8)+1;
static volatile bit           DMA7_IRQSEL2       @ ((unsigned)&DMA7REQ*8)+2;
static volatile bit           DMA7_IRQSEL3       @ ((unsigned)&DMA7REQ*8)+3;
static volatile bit           DMA7_IRQSEL4       @ ((unsigned)&DMA7REQ*8)+4;
static volatile bit           DMA7_IRQSEL5       @ ((unsigned)&DMA7REQ*8)+5;
static volatile bit           DMA7_IRQSEL6       @ ((unsigned)&DMA7REQ*8)+6;
static volatile bit           DMA7_FORCE         @ ((unsigned)&DMA7REQ*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      FORCE              : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      IRQSEL             : 7;
} DMA7REQbits @ 0x3D6;

static volatile unsigned int  DMA7STA            @ 0x3D8;
static volatile unsigned int  DMA7STB            @ 0x3DA;
static volatile unsigned int  DMA7PAD            @ 0x3DC;
static volatile unsigned int  DMA7CNT            @ 0x3DE;
static volatile unsigned int  DMACS0             @ 0x3E0;
static volatile bit           XWCOL0             @ ((unsigned)&DMACS0*8)+0;
static volatile bit           XWCOL1             @ ((unsigned)&DMACS0*8)+1;
static volatile bit           XWCOL2             @ ((unsigned)&DMACS0*8)+2;
static volatile bit           XWCOL3             @ ((unsigned)&DMACS0*8)+3;
static volatile bit           XWCOL4             @ ((unsigned)&DMACS0*8)+4;
static volatile bit           XWCOL5             @ ((unsigned)&DMACS0*8)+5;
static volatile bit           XWCOL6             @ ((unsigned)&DMACS0*8)+6;
static volatile bit           XWCOL7             @ ((unsigned)&DMACS0*8)+7;
static volatile bit           PWCOL0             @ ((unsigned)&DMACS0*8)+8;
static volatile bit           PWCOL1             @ ((unsigned)&DMACS0*8)+9;
static volatile bit           PWCOL2             @ ((unsigned)&DMACS0*8)+10;
static volatile bit           PWCOL3             @ ((unsigned)&DMACS0*8)+11;
static volatile bit           PWCOL4             @ ((unsigned)&DMACS0*8)+12;
static volatile bit           PWCOL5             @ ((unsigned)&DMACS0*8)+13;
static volatile bit           PWCOL6             @ ((unsigned)&DMACS0*8)+14;
static volatile bit           PWCOL7             @ ((unsigned)&DMACS0*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      PWCOL7             : 1;
       volatile unsigned      PWCOL6             : 1;
       volatile unsigned      PWCOL5             : 1;
       volatile unsigned      PWCOL4             : 1;
       volatile unsigned      PWCOL3             : 1;
       volatile unsigned      PWCOL2             : 1;
       volatile unsigned      PWCOL1             : 1;
       volatile unsigned      PWCOL0             : 1;
       volatile unsigned      XWCOL7             : 1;
       volatile unsigned      XWCOL6             : 1;
       volatile unsigned      XWCOL5             : 1;
       volatile unsigned      XWCOL4             : 1;
       volatile unsigned      XWCOL3             : 1;
       volatile unsigned      XWCOL2             : 1;
       volatile unsigned      XWCOL1             : 1;
       volatile unsigned      XWCOL0             : 1;
} DMACS0bits @ 0x3E0;

static volatile unsigned int  DMACS1             @ 0x3E2;
static volatile bit           PPST0              @ ((unsigned)&DMACS1*8)+0;
static volatile bit           PPST1              @ ((unsigned)&DMACS1*8)+1;
static volatile bit           PPST2              @ ((unsigned)&DMACS1*8)+2;
static volatile bit           PPST3              @ ((unsigned)&DMACS1*8)+3;
static volatile bit           PPST4              @ ((unsigned)&DMACS1*8)+4;
static volatile bit           PPST5              @ ((unsigned)&DMACS1*8)+5;
static volatile bit           PPST6              @ ((unsigned)&DMACS1*8)+6;
static volatile bit           PPST7              @ ((unsigned)&DMACS1*8)+7;
static volatile bit           LSTCH0             @ ((unsigned)&DMACS1*8)+8;
static volatile bit           LSTCH1             @ ((unsigned)&DMACS1*8)+9;
static volatile bit           LSTCH2             @ ((unsigned)&DMACS1*8)+10;
static volatile bit           LSTCH3             @ ((unsigned)&DMACS1*8)+11;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      LSTCH              : 4;
       volatile unsigned      PPST7              : 1;
       volatile unsigned      PPST6              : 1;
       volatile unsigned      PPST5              : 1;
       volatile unsigned      PPST4              : 1;
       volatile unsigned      PPST3              : 1;
       volatile unsigned      PPST2              : 1;
       volatile unsigned      PPST1              : 1;
       volatile unsigned      PPST0              : 1;
} DMACS1bits @ 0x3E2;

static volatile unsigned int  DSADR              @ 0x3E4;
static volatile bit           DSADR0             @ ((unsigned)&DSADR*8)+0;
static volatile bit           DSADR1             @ ((unsigned)&DSADR*8)+1;
static volatile bit           DSADR2             @ ((unsigned)&DSADR*8)+2;
static volatile bit           DSADR3             @ ((unsigned)&DSADR*8)+3;
static volatile bit           DSADR4             @ ((unsigned)&DSADR*8)+4;
static volatile bit           DSADR5             @ ((unsigned)&DSADR*8)+5;
static volatile bit           DSADR6             @ ((unsigned)&DSADR*8)+6;
static volatile bit           DSADR7             @ ((unsigned)&DSADR*8)+7;
static volatile bit           DSADR8             @ ((unsigned)&DSADR*8)+8;
static volatile bit           DSADR9             @ ((unsigned)&DSADR*8)+9;
static volatile bit           DSADR10            @ ((unsigned)&DSADR*8)+10;
static volatile bit           DSADR11            @ ((unsigned)&DSADR*8)+11;
static volatile bit           DSADR12            @ ((unsigned)&DSADR*8)+12;
static volatile bit           DSADR13            @ ((unsigned)&DSADR*8)+13;
static volatile bit           DSADR14            @ ((unsigned)&DSADR*8)+14;
static volatile bit           DSADR15            @ ((unsigned)&DSADR*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      DSADR              : 16;
} DSADRbits @ 0x3E4;

static volatile unsigned int  RCON               @ 0x740;
static volatile bit           POR                @ ((unsigned)&RCON*8)+0;
static volatile bit           BOR                @ ((unsigned)&RCON*8)+1;
static volatile bit           IDLE               @ ((unsigned)&RCON*8)+2;
static volatile bit           SLEEP              @ ((unsigned)&RCON*8)+3;
static volatile bit           WDTO               @ ((unsigned)&RCON*8)+4;
static volatile bit           SWDTEN             @ ((unsigned)&RCON*8)+5;
static volatile bit           SWR                @ ((unsigned)&RCON*8)+6;
static volatile bit           EXTR               @ ((unsigned)&RCON*8)+7;
static volatile bit           VREGS              @ ((unsigned)&RCON*8)+8;
static volatile bit           IOPR               @ ((unsigned)&RCON*8)+14;
static volatile bit           TRAPR              @ ((unsigned)&RCON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      TRAPR              : 1;
       volatile unsigned      IOPR               : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      VREGS              : 1;
       volatile unsigned      EXTR               : 1;
       volatile unsigned      SWR                : 1;
       volatile unsigned      SWDTEN             : 1;
       volatile unsigned      WDTO               : 1;
       volatile unsigned      SLEEP              : 1;
       volatile unsigned      IDLE               : 1;
       volatile unsigned      BOR                : 1;
       volatile unsigned      POR                : 1;
} RCONbits @ 0x740;

static volatile unsigned int  OSCCON             @ 0x742;
static volatile bit           OSWEN              @ ((unsigned)&OSCCON*8)+0;
static volatile bit           LPOSCEN            @ ((unsigned)&OSCCON*8)+1;
static volatile bit           CF                 @ ((unsigned)&OSCCON*8)+3;
static volatile bit           LOCK               @ ((unsigned)&OSCCON*8)+5;
static volatile bit           CLKLOCK            @ ((unsigned)&OSCCON*8)+7;
static volatile bit           NOSCG0             @ ((unsigned)&OSCCON*8)+8;
static volatile bit           NOSCG1             @ ((unsigned)&OSCCON*8)+9;
static volatile bit           NOSCG2             @ ((unsigned)&OSCCON*8)+10;
static volatile bit           COSCG0             @ ((unsigned)&OSCCON*8)+12;
static volatile bit           COSCG1             @ ((unsigned)&OSCCON*8)+13;
static volatile bit           COSCG2             @ ((unsigned)&OSCCON*8)+14;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
       volatile unsigned      COSCG              : 3;
                unsigned                         : 1;
       volatile unsigned      NOSCG              : 3;
       volatile unsigned      CLKLOCK            : 1;
                unsigned                         : 1;
       volatile unsigned      LOCK               : 1;
                unsigned                         : 1;
       volatile unsigned      CF                 : 1;
                unsigned                         : 1;
       volatile unsigned      LPOSCEN            : 1;
       volatile unsigned      OSWEN              : 1;
} OSCCONbits @ 0x742;

static volatile unsigned int  CLKDIV             @ 0x744;
static volatile bit           PRESCLR0           @ ((unsigned)&CLKDIV*8)+0;
static volatile bit           PRESCLR1           @ ((unsigned)&CLKDIV*8)+1;
static volatile bit           PRESCLR2           @ ((unsigned)&CLKDIV*8)+2;
static volatile bit           PRESCLR3           @ ((unsigned)&CLKDIV*8)+3;
static volatile bit           PRESCLR4           @ ((unsigned)&CLKDIV*8)+4;
static volatile bit           PLLPOST0           @ ((unsigned)&CLKDIV*8)+5;
static volatile bit           PLLPOST1           @ ((unsigned)&CLKDIV*8)+6;
static volatile bit           PLLPOST2           @ ((unsigned)&CLKDIV*8)+7;
static volatile bit           RCDIV0             @ ((unsigned)&CLKDIV*8)+8;
static volatile bit           RCDIV1             @ ((unsigned)&CLKDIV*8)+9;
static volatile bit           RCDIV2             @ ((unsigned)&CLKDIV*8)+10;
static volatile bit           DOZEN              @ ((unsigned)&CLKDIV*8)+11;
static volatile bit           DOZE0              @ ((unsigned)&CLKDIV*8)+12;
static volatile bit           DOZE1              @ ((unsigned)&CLKDIV*8)+13;
static volatile bit           DOZE2              @ ((unsigned)&CLKDIV*8)+14;
static volatile bit           ROI                @ ((unsigned)&CLKDIV*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      ROI                : 1;
       volatile unsigned      DOZE               : 3;
       volatile unsigned      DOZEN              : 1;
       volatile unsigned      RCDIV              : 3;
       volatile unsigned      PLLPOST            : 3;
       volatile unsigned      PRESCLR            : 5;
} CLKDIVbits @ 0x744;

static volatile unsigned int  PLLFBD             @ 0x746;
static volatile bit           DIVISOR0           @ ((unsigned)&PLLFBD*8)+0;
static volatile bit           DIVISOR1           @ ((unsigned)&PLLFBD*8)+1;
static volatile bit           DIVISOR2           @ ((unsigned)&PLLFBD*8)+2;
static volatile bit           DIVISOR3           @ ((unsigned)&PLLFBD*8)+3;
static volatile bit           DIVISOR4           @ ((unsigned)&PLLFBD*8)+4;
static volatile bit           DIVISOR5           @ ((unsigned)&PLLFBD*8)+5;
static volatile bit           DIVISOR6           @ ((unsigned)&PLLFBD*8)+6;
static volatile bit           DIVISOR7           @ ((unsigned)&PLLFBD*8)+7;
static volatile bit           DIVISOR8           @ ((unsigned)&PLLFBD*8)+8;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      DIVISOR            : 9;
} PLLFBDbits @ 0x746;

static volatile unsigned int  OSCTRIM            @ 0x748;
static volatile bit           TUN0               @ ((unsigned)&OSCTRIM*8)+0;
static volatile bit           TUN1               @ ((unsigned)&OSCTRIM*8)+1;
static volatile bit           TUN2               @ ((unsigned)&OSCTRIM*8)+2;
static volatile bit           TUN3               @ ((unsigned)&OSCTRIM*8)+3;
static volatile bit           TUN4               @ ((unsigned)&OSCTRIM*8)+4;
static volatile bit           TUN5               @ ((unsigned)&OSCTRIM*8)+5;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      TUN                : 6;
} OSCTRIMbits @ 0x748;

static volatile unsigned int  NVMCON             @ 0x760;
static volatile bit           NVMOP0             @ ((unsigned)&NVMCON*8)+0;
static volatile bit           NVMOP1             @ ((unsigned)&NVMCON*8)+1;
static volatile bit           NVMOP2             @ ((unsigned)&NVMCON*8)+2;
static volatile bit           NVMOP3             @ ((unsigned)&NVMCON*8)+3;
static volatile bit           ERASE              @ ((unsigned)&NVMCON*8)+6;
static volatile bit           WRERR              @ ((unsigned)&NVMCON*8)+13;
static volatile bit           WREN               @ ((unsigned)&NVMCON*8)+14;
static volatile bit           WR                 @ ((unsigned)&NVMCON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      WR                 : 1;
       volatile unsigned      WREN               : 1;
       volatile unsigned      WRERR              : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      ERASE              : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      NVMOP              : 4;
} NVMCONbits @ 0x760;

static volatile unsigned int  NVMKEY             @ 0x766;
static volatile unsigned int  PMD1               @ 0x770;
static volatile unsigned int  PMD2               @ 0x772;
static volatile unsigned int  PMD3               @ 0x774;
static volatile unsigned int  C1CTRL1            @ 0x400;
static volatile bit           C1_WIN             @ ((unsigned)&C1CTRL1*8)+0;
static volatile bit           C1_CANCAP          @ ((unsigned)&C1CTRL1*8)+3;
static volatile bit           C1_OPMODE0         @ ((unsigned)&C1CTRL1*8)+5;
static volatile bit           C1_OPMODE1         @ ((unsigned)&C1CTRL1*8)+6;
static volatile bit           C1_OPMODE2         @ ((unsigned)&C1CTRL1*8)+7;
static volatile bit           C1_REQOP0          @ ((unsigned)&C1CTRL1*8)+8;
static volatile bit           C1_REQOP1          @ ((unsigned)&C1CTRL1*8)+9;
static volatile bit           C1_REQOP2          @ ((unsigned)&C1CTRL1*8)+10;
static volatile bit           C1_CANCKS          @ ((unsigned)&C1CTRL1*8)+11;
static volatile bit           C1_ABAT            @ ((unsigned)&C1CTRL1*8)+12;
static volatile bit           C1_CSIDL           @ ((unsigned)&C1CTRL1*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      CSIDL              : 1;
       volatile unsigned      ABAT               : 1;
       volatile unsigned      CANCKS             : 1;
       volatile unsigned      REQOP              : 3;
       volatile unsigned      OPMODE             : 3;
                unsigned                         : 1;
       volatile unsigned      CANCAP             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      WIN                : 1;
} C1CTRL1bits @ 0x400;

static volatile unsigned int  C1CTRL2            @ 0x402;
static volatile bit           C1_DNCNT0          @ ((unsigned)&C1CTRL2*8)+0;
static volatile bit           C1_DNCNT1          @ ((unsigned)&C1CTRL2*8)+1;
static volatile bit           C1_DNCNT2          @ ((unsigned)&C1CTRL2*8)+2;
static volatile bit           C1_DNCNT3          @ ((unsigned)&C1CTRL2*8)+3;
static volatile bit           C1_DNCNT4          @ ((unsigned)&C1CTRL2*8)+4;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      DNCNT              : 5;
} C1CTRL2bits @ 0x402;

static volatile unsigned int  C1VEC              @ 0x404;
static volatile bit           C1_ICODE0          @ ((unsigned)&C1VEC*8)+0;
static volatile bit           C1_ICODE1          @ ((unsigned)&C1VEC*8)+1;
static volatile bit           C1_ICODE2          @ ((unsigned)&C1VEC*8)+2;
static volatile bit           C1_ICODE3          @ ((unsigned)&C1VEC*8)+3;
static volatile bit           C1_ICODE4          @ ((unsigned)&C1VEC*8)+4;
static volatile bit           C1_ICODE5          @ ((unsigned)&C1VEC*8)+5;
static volatile bit           C1_ICODE6          @ ((unsigned)&C1VEC*8)+6;
static volatile bit           C1_FILHIT0         @ ((unsigned)&C1VEC*8)+8;
static volatile bit           C1_FILHIT1         @ ((unsigned)&C1VEC*8)+9;
static volatile bit           C1_FILHIT2         @ ((unsigned)&C1VEC*8)+10;
static volatile bit           C1_FILHIT3         @ ((unsigned)&C1VEC*8)+11;
static volatile bit           C1_FILHIT4         @ ((unsigned)&C1VEC*8)+12;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      FILHIT             : 5;
                unsigned                         : 1;
       volatile unsigned      ICODE              : 7;
} C1VECbits @ 0x404;

static volatile unsigned int  C1FCTRL            @ 0x406;
static volatile bit           C1_FSA0            @ ((unsigned)&C1FCTRL*8)+0;
static volatile bit           C1_FSA1            @ ((unsigned)&C1FCTRL*8)+1;
static volatile bit           C1_FSA2            @ ((unsigned)&C1FCTRL*8)+2;
static volatile bit           C1_FSA3            @ ((unsigned)&C1FCTRL*8)+3;
static volatile bit           C1_FSA4            @ ((unsigned)&C1FCTRL*8)+4;
static volatile bit           C1_DMABS0          @ ((unsigned)&C1FCTRL*8)+13;
static volatile bit           C1_DMABS1          @ ((unsigned)&C1FCTRL*8)+14;
static volatile bit           C1_DMABS2          @ ((unsigned)&C1FCTRL*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      DMABS              : 3;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      FSA                : 5;
} C1FCTRLbits @ 0x406;

static volatile unsigned int  C1FIFO             @ 0x408;
static volatile bit           C1_FNRB0           @ ((unsigned)&C1FIFO*8)+0;
static volatile bit           C1_FNRB1           @ ((unsigned)&C1FIFO*8)+1;
static volatile bit           C1_FNRB2           @ ((unsigned)&C1FIFO*8)+2;
static volatile bit           C1_FNRB3           @ ((unsigned)&C1FIFO*8)+3;
static volatile bit           C1_FNRB4           @ ((unsigned)&C1FIFO*8)+4;
static volatile bit           C1_FNRB5           @ ((unsigned)&C1FIFO*8)+5;
static volatile bit           C1_FBP0            @ ((unsigned)&C1FIFO*8)+8;
static volatile bit           C1_FBP1            @ ((unsigned)&C1FIFO*8)+9;
static volatile bit           C1_FBP2            @ ((unsigned)&C1FIFO*8)+10;
static volatile bit           C1_FBP3            @ ((unsigned)&C1FIFO*8)+11;
static volatile bit           C1_FBP4            @ ((unsigned)&C1FIFO*8)+12;
static volatile bit           C1_FBP5            @ ((unsigned)&C1FIFO*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      FBP                : 6;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      FNRB               : 6;
} C1FIFObits @ 0x408;

static volatile unsigned int  C1INTF             @ 0x40A;
static volatile bit           C1_TBIF            @ ((unsigned)&C1INTF*8)+0;
static volatile bit           C1_RBIF            @ ((unsigned)&C1INTF*8)+1;
static volatile bit           C1_RBOVIF          @ ((unsigned)&C1INTF*8)+2;
static volatile bit           C1_FIFOIF          @ ((unsigned)&C1INTF*8)+3;
static volatile bit           C1_ERRIF           @ ((unsigned)&C1INTF*8)+5;
static volatile bit           C1_WAKIF           @ ((unsigned)&C1INTF*8)+6;
static volatile bit           C1_IVRIF           @ ((unsigned)&C1INTF*8)+7;
static volatile bit           C1_EWARN           @ ((unsigned)&C1INTF*8)+8;
static volatile bit           C1_RXWAR           @ ((unsigned)&C1INTF*8)+9;
static volatile bit           C1_TXWAR           @ ((unsigned)&C1INTF*8)+10;
static volatile bit           C1_RXBP            @ ((unsigned)&C1INTF*8)+11;
static volatile bit           C1_TXBP            @ ((unsigned)&C1INTF*8)+12;
static volatile bit           C1_TXBO            @ ((unsigned)&C1INTF*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      TXBO               : 1;
       volatile unsigned      TXBP               : 1;
       volatile unsigned      RXBP               : 1;
       volatile unsigned      TXWAR              : 1;
       volatile unsigned      RXWAR              : 1;
       volatile unsigned      EWARN              : 1;
       volatile unsigned      IVRIF              : 1;
       volatile unsigned      WAKIF              : 1;
       volatile unsigned      ERRIF              : 1;
                unsigned                         : 1;
       volatile unsigned      FIFOIF             : 1;
       volatile unsigned      RBOVIF             : 1;
       volatile unsigned      RBIF               : 1;
       volatile unsigned      TBIF               : 1;
} C1INTFbits @ 0x40A;

static volatile unsigned int  C1INTE             @ 0x40C;
static volatile bit           C1_TBIE            @ ((unsigned)&C1INTE*8)+0;
static volatile bit           C1_RBIE            @ ((unsigned)&C1INTE*8)+1;
static volatile bit           C1_RBOVIE          @ ((unsigned)&C1INTE*8)+2;
static volatile bit           C1_FIFOIE          @ ((unsigned)&C1INTE*8)+3;
static volatile bit           C1_ERRIE           @ ((unsigned)&C1INTE*8)+5;
static volatile bit           C1_WAKIE           @ ((unsigned)&C1INTE*8)+6;
static volatile bit           C1_IVRIE           @ ((unsigned)&C1INTE*8)+7;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      IVRIE              : 1;
       volatile unsigned      WAKIE              : 1;
       volatile unsigned      ERRIE              : 1;
       volatile unsigned                         : 1;
       volatile unsigned      FIFOIE             : 1;
       volatile unsigned      RBOVIE             : 1;
       volatile unsigned      RBIE               : 1;
       volatile unsigned      TBIE               : 1;
} C1INTEbits @ 0x40C;

static volatile unsigned int  C1EC               @ 0x40E;
static volatile bit           C1_RERRCNT0        @ ((unsigned)&C1EC*8)+0;
static volatile bit           C1_RERRCNT1        @ ((unsigned)&C1EC*8)+1;
static volatile bit           C1_RERRCNT2        @ ((unsigned)&C1EC*8)+2;
static volatile bit           C1_RERRCNT3        @ ((unsigned)&C1EC*8)+3;
static volatile bit           C1_RERRCNT4        @ ((unsigned)&C1EC*8)+4;
static volatile bit           C1_RERRCNT5        @ ((unsigned)&C1EC*8)+5;
static volatile bit           C1_RERRCNT6        @ ((unsigned)&C1EC*8)+6;
static volatile bit           C1_RERRCNT7        @ ((unsigned)&C1EC*8)+7;
static volatile bit           C1_TERRCNT0        @ ((unsigned)&C1EC*8)+8;
static volatile bit           C1_TERRCNT1        @ ((unsigned)&C1EC*8)+9;
static volatile bit           C1_TERRCNT2        @ ((unsigned)&C1EC*8)+10;
static volatile bit           C1_TERRCNT3        @ ((unsigned)&C1EC*8)+11;
static volatile bit           C1_TERRCNT4        @ ((unsigned)&C1EC*8)+12;
static volatile bit           C1_TERRCNT5        @ ((unsigned)&C1EC*8)+13;
static volatile bit           C1_TERRCNT6        @ ((unsigned)&C1EC*8)+14;
static volatile bit           C1_TERRCNT7        @ ((unsigned)&C1EC*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      TERRCNT            : 8;
       volatile unsigned      RERRCNT            : 8;
} C1ECbits @ 0x40E;

static volatile unsigned int  C1CFG1             @ 0x410;
static volatile bit           C1CFG1_BRP0        @ ((unsigned)&C1CFG1*8)+0;
static volatile bit           C1CFG1_BRP1        @ ((unsigned)&C1CFG1*8)+1;
static volatile bit           C1CFG1_BRP2        @ ((unsigned)&C1CFG1*8)+2;
static volatile bit           C1CFG1_BRP3        @ ((unsigned)&C1CFG1*8)+3;
static volatile bit           C1CFG1_BRP4        @ ((unsigned)&C1CFG1*8)+4;
static volatile bit           C1CFG1_BRP5        @ ((unsigned)&C1CFG1*8)+5;
static volatile bit           C1CFG1_SJW0        @ ((unsigned)&C1CFG1*8)+6;
static volatile bit           C1CFG1_SJW1        @ ((unsigned)&C1CFG1*8)+7;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      SJW                : 2;
       volatile unsigned      BRP                : 6;
} C1CFG1bits @ 0x410;

static volatile unsigned int  C1CFG2             @ 0x412;
static volatile bit           C1CFG2_PRSEG0      @ ((unsigned)&C1CFG2*8)+0;
static volatile bit           C1CFG2_PRSEG1      @ ((unsigned)&C1CFG2*8)+1;
static volatile bit           C1CFG2_PRSEG2      @ ((unsigned)&C1CFG2*8)+2;
static volatile bit           C1CFG2_SEG1PH0     @ ((unsigned)&C1CFG2*8)+3;
static volatile bit           C1CFG2_SEG1PH1     @ ((unsigned)&C1CFG2*8)+4;
static volatile bit           C1CFG2_SEG1PH2     @ ((unsigned)&C1CFG2*8)+5;
static volatile bit           C1CFG2_SAM         @ ((unsigned)&C1CFG2*8)+6;
static volatile bit           C1CFG2_SEG2PHTS    @ ((unsigned)&C1CFG2*8)+7;
static volatile bit           C1CFG2_SEG2PH0     @ ((unsigned)&C1CFG2*8)+8;
static volatile bit           C1CFG2_SEG2PH1     @ ((unsigned)&C1CFG2*8)+9;
static volatile bit           C1CFG2_SEG2PH2     @ ((unsigned)&C1CFG2*8)+10;
static volatile bit           C1CFG2_WAKFIL      @ ((unsigned)&C1CFG2*8)+14;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
       volatile unsigned      WAKFIL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      SEG2PH             : 3;
       volatile unsigned      SEG2PHTS           : 1;
       volatile unsigned      SAM                : 1;
       volatile unsigned      SEG1PH             : 3;
       volatile unsigned      PRSEG              : 3;
} C1CFG2bits @ 0x412;

static volatile unsigned int  C1FEN1             @ 0x414;
static volatile unsigned int  C1FMSKSEL1         @ 0x418;
static volatile bit           C1_F0MSK0          @ ((unsigned)&C1FMSKSEL1*8)+0;
static volatile bit           C1_F0MSK1          @ ((unsigned)&C1FMSKSEL1*8)+1;
static volatile bit           C1_F1MSK0          @ ((unsigned)&C1FMSKSEL1*8)+2;
static volatile bit           C1_F1MSK1          @ ((unsigned)&C1FMSKSEL1*8)+3;
static volatile bit           C1_F2MSK0          @ ((unsigned)&C1FMSKSEL1*8)+4;
static volatile bit           C1_F2MSK1          @ ((unsigned)&C1FMSKSEL1*8)+5;
static volatile bit           C1_F3MSK0          @ ((unsigned)&C1FMSKSEL1*8)+6;
static volatile bit           C1_F3MSK1          @ ((unsigned)&C1FMSKSEL1*8)+7;
static volatile bit           C1_F4MSK0          @ ((unsigned)&C1FMSKSEL1*8)+8;
static volatile bit           C1_F4MSK1          @ ((unsigned)&C1FMSKSEL1*8)+9;
static volatile bit           C1_F5MSK0          @ ((unsigned)&C1FMSKSEL1*8)+10;
static volatile bit           C1_F5MSK1          @ ((unsigned)&C1FMSKSEL1*8)+11;
static volatile bit           C1_F6MSK0          @ ((unsigned)&C1FMSKSEL1*8)+12;
static volatile bit           C1_F6MSK1          @ ((unsigned)&C1FMSKSEL1*8)+13;
static volatile bit           C1_F7MSK0          @ ((unsigned)&C1FMSKSEL1*8)+14;
static volatile bit           C1_F7MSK1          @ ((unsigned)&C1FMSKSEL1*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      F7MSK              : 2;
       volatile unsigned      F6MSK              : 2;
       volatile unsigned      F5MSK              : 2;
       volatile unsigned      F4MSK              : 2;
       volatile unsigned      F3MSK              : 2;
       volatile unsigned      F2MSK              : 2;
       volatile unsigned      F1MSK              : 2;
       volatile unsigned      F0MSK              : 2;
} C1FMSKSEL1bits @ 0x418;

static volatile unsigned int  C1FMSKSEL2         @ 0x41A;
static volatile bit           C1_F8MSK0          @ ((unsigned)&C1FMSKSEL2*8)+0;
static volatile bit           C1_F8MSK1          @ ((unsigned)&C1FMSKSEL2*8)+1;
static volatile bit           C1_F9MSK0          @ ((unsigned)&C1FMSKSEL2*8)+2;
static volatile bit           C1_F9MSK1          @ ((unsigned)&C1FMSKSEL2*8)+3;
static volatile bit           C1_F10MSK0         @ ((unsigned)&C1FMSKSEL2*8)+4;
static volatile bit           C1_F10MSK1         @ ((unsigned)&C1FMSKSEL2*8)+5;
static volatile bit           C1_F11MSK0         @ ((unsigned)&C1FMSKSEL2*8)+6;
static volatile bit           C1_F11MSK1         @ ((unsigned)&C1FMSKSEL2*8)+7;
static volatile bit           C1_F12MSK0         @ ((unsigned)&C1FMSKSEL2*8)+8;
static volatile bit           C1_F12MSK1         @ ((unsigned)&C1FMSKSEL2*8)+9;
static volatile bit           C1_F13MSK0         @ ((unsigned)&C1FMSKSEL2*8)+10;
static volatile bit           C1_F13MSK1         @ ((unsigned)&C1FMSKSEL2*8)+11;
static volatile bit           C1_F14MSK0         @ ((unsigned)&C1FMSKSEL2*8)+12;
static volatile bit           C1_F14MSK1         @ ((unsigned)&C1FMSKSEL2*8)+13;
static volatile bit           C1_F15MSK0         @ ((unsigned)&C1FMSKSEL2*8)+14;
static volatile bit           C1_F15MSK1         @ ((unsigned)&C1FMSKSEL2*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      F15MSK             : 2;
       volatile unsigned      F14MSK             : 2;
       volatile unsigned      F13MSK             : 2;
       volatile unsigned      F12MSK             : 2;
       volatile unsigned      F11MSK             : 2;
       volatile unsigned      F10MSK             : 2;
       volatile unsigned      F9MSK              : 2;
       volatile unsigned      F8MSK              : 2;
} C1FMSKSEL2bits @ 0x41A;

static volatile unsigned int  C1RXFUL1           @ 0x420;
static volatile unsigned int  C1RXFUL2           @ 0x422;
static volatile unsigned int  C1BUFPNT3          @ 0x424;
static volatile bit           C1_F8BP0           @ ((unsigned)&C1BUFPNT3*8)+0;
static volatile bit           C1_F8BP1           @ ((unsigned)&C1BUFPNT3*8)+1;
static volatile bit           C1_F8BP2           @ ((unsigned)&C1BUFPNT3*8)+2;
static volatile bit           C1_F8BP3           @ ((unsigned)&C1BUFPNT3*8)+3;
static volatile bit           C1_F9BP0           @ ((unsigned)&C1BUFPNT3*8)+4;
static volatile bit           C1_F9BP1           @ ((unsigned)&C1BUFPNT3*8)+5;
static volatile bit           C1_F9BP2           @ ((unsigned)&C1BUFPNT3*8)+6;
static volatile bit           C1_F9BP3           @ ((unsigned)&C1BUFPNT3*8)+7;
static volatile bit           C1_F10BP0          @ ((unsigned)&C1BUFPNT3*8)+8;
static volatile bit           C1_F10BP1          @ ((unsigned)&C1BUFPNT3*8)+9;
static volatile bit           C1_F10BP2          @ ((unsigned)&C1BUFPNT3*8)+10;
static volatile bit           C1_F10BP3          @ ((unsigned)&C1BUFPNT3*8)+11;
static volatile bit           C1_F11BP0          @ ((unsigned)&C1BUFPNT3*8)+12;
static volatile bit           C1_F11BP1          @ ((unsigned)&C1BUFPNT3*8)+13;
static volatile bit           C1_F11BP2          @ ((unsigned)&C1BUFPNT3*8)+14;
static volatile bit           C1_F11BP3          @ ((unsigned)&C1BUFPNT3*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      F11BP              : 4;
       volatile unsigned      F10BP              : 4;
       volatile unsigned      F9BP               : 4;
       volatile unsigned      F8BP               : 4;
} C1BUFPNT3bits @ 0x424;

static volatile unsigned int  C1BUFPNT4          @ 0x426;
static volatile bit           C1_F12BP0          @ ((unsigned)&C1BUFPNT4*8)+0;
static volatile bit           C1_F12BP1          @ ((unsigned)&C1BUFPNT4*8)+1;
static volatile bit           C1_F12BP2          @ ((unsigned)&C1BUFPNT4*8)+2;
static volatile bit           C1_F12BP3          @ ((unsigned)&C1BUFPNT4*8)+3;
static volatile bit           C1_F13BP0          @ ((unsigned)&C1BUFPNT4*8)+4;
static volatile bit           C1_F13BP1          @ ((unsigned)&C1BUFPNT4*8)+5;
static volatile bit           C1_F13BP2          @ ((unsigned)&C1BUFPNT4*8)+6;
static volatile bit           C1_F13BP3          @ ((unsigned)&C1BUFPNT4*8)+7;
static volatile bit           C1_F14BP0          @ ((unsigned)&C1BUFPNT4*8)+8;
static volatile bit           C1_F14BP1          @ ((unsigned)&C1BUFPNT4*8)+9;
static volatile bit           C1_F14BP2          @ ((unsigned)&C1BUFPNT4*8)+10;
static volatile bit           C1_F14BP3          @ ((unsigned)&C1BUFPNT4*8)+11;
static volatile bit           C1_F15BP0          @ ((unsigned)&C1BUFPNT4*8)+12;
static volatile bit           C1_F15BP1          @ ((unsigned)&C1BUFPNT4*8)+13;
static volatile bit           C1_F15BP2          @ ((unsigned)&C1BUFPNT4*8)+14;
static volatile bit           C1_F15BP3          @ ((unsigned)&C1BUFPNT4*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      F15BP              : 4;
       volatile unsigned      F14BP              : 4;
       volatile unsigned      F13BP              : 4;
       volatile unsigned      F12BP              : 4;
} C1BUFPNT4bits @ 0x426;

static volatile unsigned int  C1RXOVF1           @ 0x428;
static volatile unsigned int  C1RXOVF2           @ 0x42A;
static volatile unsigned int  C1TR01CON          @ 0x430;
static volatile bit           C1_TX0PRI0         @ ((unsigned)&C1TR01CON*8)+0;
static volatile bit           C1_TX0PRI1         @ ((unsigned)&C1TR01CON*8)+1;
static volatile bit           C1_RTREN0          @ ((unsigned)&C1TR01CON*8)+2;
static volatile bit           C1_TXREQ0          @ ((unsigned)&C1TR01CON*8)+3;
static volatile bit           C1_TXERR0          @ ((unsigned)&C1TR01CON*8)+4;
static volatile bit           C1_TXLARB0         @ ((unsigned)&C1TR01CON*8)+5;
static volatile bit           C1_TXABT0          @ ((unsigned)&C1TR01CON*8)+6;
static volatile bit           C1_TXEN0           @ ((unsigned)&C1TR01CON*8)+7;
static volatile bit           C1_TX1PRI0         @ ((unsigned)&C1TR01CON*8)+8;
static volatile bit           C1_TX1PRI1         @ ((unsigned)&C1TR01CON*8)+9;
static volatile bit           C1_RTREN1          @ ((unsigned)&C1TR01CON*8)+10;
static volatile bit           C1_TXREQ1          @ ((unsigned)&C1TR01CON*8)+11;
static volatile bit           C1_TXERR1          @ ((unsigned)&C1TR01CON*8)+12;
static volatile bit           C1_TXLARB1         @ ((unsigned)&C1TR01CON*8)+13;
static volatile bit           C1_TXABT1          @ ((unsigned)&C1TR01CON*8)+14;
static volatile bit           C1_TXEN1           @ ((unsigned)&C1TR01CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      TXEN1              : 1;
       volatile unsigned      TXABT1             : 1;
       volatile unsigned      TXLARB1            : 1;
       volatile unsigned      TXERR1             : 1;
       volatile unsigned      TXREQ1             : 1;
       volatile unsigned      RTREN1             : 1;
       volatile unsigned      TX1PRI             : 2;
       volatile unsigned      TXEN0              : 1;
       volatile unsigned      TXABT0             : 1;
       volatile unsigned      TXLARB0            : 1;
       volatile unsigned      TXERR0             : 1;
       volatile unsigned      TXREQ0             : 1;
       volatile unsigned      RTREN0             : 1;
       volatile unsigned      TX0PRI             : 2;
} C1TR01CONbits @ 0x430;

static volatile unsigned int  C1TR23CON          @ 0x432;
static volatile bit           C1_TX2PRI0         @ ((unsigned)&C1TR23CON*8)+0;
static volatile bit           C1_TX2PRI1         @ ((unsigned)&C1TR23CON*8)+1;
static volatile bit           C1_RTREN2          @ ((unsigned)&C1TR23CON*8)+2;
static volatile bit           C1_TXREQ2          @ ((unsigned)&C1TR23CON*8)+3;
static volatile bit           C1_TXERR2          @ ((unsigned)&C1TR23CON*8)+4;
static volatile bit           C1_TXLARB2         @ ((unsigned)&C1TR23CON*8)+5;
static volatile bit           C1_TXABT2          @ ((unsigned)&C1TR23CON*8)+6;
static volatile bit           C1_TXEN2           @ ((unsigned)&C1TR23CON*8)+7;
static volatile bit           C1_TX3PRI0         @ ((unsigned)&C1TR23CON*8)+8;
static volatile bit           C1_TX3PRI1         @ ((unsigned)&C1TR23CON*8)+9;
static volatile bit           C1_RTREN3          @ ((unsigned)&C1TR23CON*8)+10;
static volatile bit           C1_TXREQ3          @ ((unsigned)&C1TR23CON*8)+11;
static volatile bit           C1_TXERR3          @ ((unsigned)&C1TR23CON*8)+12;
static volatile bit           C1_TXLARB3         @ ((unsigned)&C1TR23CON*8)+13;
static volatile bit           C1_TXABT3          @ ((unsigned)&C1TR23CON*8)+14;
static volatile bit           C1_TXEN3           @ ((unsigned)&C1TR23CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      TXEN3              : 1;
       volatile unsigned      TXABT3             : 1;
       volatile unsigned      TXLARB3            : 1;
       volatile unsigned      TXERR3             : 1;
       volatile unsigned      TXREQ3             : 1;
       volatile unsigned      RTREN3             : 1;
       volatile unsigned      TX3PRI             : 2;
       volatile unsigned      TXEN2              : 1;
       volatile unsigned      TXABT2             : 1;
       volatile unsigned      TXLARB2            : 1;
       volatile unsigned      TXERR2             : 1;
       volatile unsigned      TXREQ2             : 1;
       volatile unsigned      RTREN2             : 1;
       volatile unsigned      TX2PRI             : 2;
} C1TR23CONbits @ 0x432;

static volatile unsigned int  C1TR45CON          @ 0x434;
static volatile bit           C1_TX4PRI0         @ ((unsigned)&C1TR45CON*8)+0;
static volatile bit           C1_TX4PRI1         @ ((unsigned)&C1TR45CON*8)+1;
static volatile bit           C1_RTREN4          @ ((unsigned)&C1TR45CON*8)+2;
static volatile bit           C1_TXREQ4          @ ((unsigned)&C1TR45CON*8)+3;
static volatile bit           C1_TXERR4          @ ((unsigned)&C1TR45CON*8)+4;
static volatile bit           C1_TXLARB4         @ ((unsigned)&C1TR45CON*8)+5;
static volatile bit           C1_TXABT4          @ ((unsigned)&C1TR45CON*8)+6;
static volatile bit           C1_TXEN4           @ ((unsigned)&C1TR45CON*8)+7;
static volatile bit           C1_TX5PRI0         @ ((unsigned)&C1TR45CON*8)+8;
static volatile bit           C1_TX5PRI1         @ ((unsigned)&C1TR45CON*8)+9;
static volatile bit           C1_RTREN5          @ ((unsigned)&C1TR45CON*8)+10;
static volatile bit           C1_TXREQ5          @ ((unsigned)&C1TR45CON*8)+11;
static volatile bit           C1_TXERR5          @ ((unsigned)&C1TR45CON*8)+12;
static volatile bit           C1_TXLARB5         @ ((unsigned)&C1TR45CON*8)+13;
static volatile bit           C1_TXABT5          @ ((unsigned)&C1TR45CON*8)+14;
static volatile bit           C1_TXEN5           @ ((unsigned)&C1TR45CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      TXEN5              : 1;
       volatile unsigned      TXABT5             : 1;
       volatile unsigned      TXLARB5            : 1;
       volatile unsigned      TXERR5             : 1;
       volatile unsigned      TXREQ5             : 1;
       volatile unsigned      RTREN5             : 1;
       volatile unsigned      TX5PRI             : 2;
       volatile unsigned      TXEN4              : 1;
       volatile unsigned      TXABT4             : 1;
       volatile unsigned      TXLARB4            : 1;
       volatile unsigned      TXERR4             : 1;
       volatile unsigned      TXREQ4             : 1;
       volatile unsigned      RTREN4             : 1;
       volatile unsigned      TX4PRI             : 2;
} C1TR45CONbits @ 0x434;

static volatile unsigned int  C1TR67CON          @ 0x436;
static volatile bit           C1_TX6PRI0         @ ((unsigned)&C1TR67CON*8)+0;
static volatile bit           C1_TX6PRI1         @ ((unsigned)&C1TR67CON*8)+1;
static volatile bit           C1_RTREN6          @ ((unsigned)&C1TR67CON*8)+2;
static volatile bit           C1_TXREQ6          @ ((unsigned)&C1TR67CON*8)+3;
static volatile bit           C1_TXERR6          @ ((unsigned)&C1TR67CON*8)+4;
static volatile bit           C1_TXLARB6         @ ((unsigned)&C1TR67CON*8)+5;
static volatile bit           C1_TXABT6          @ ((unsigned)&C1TR67CON*8)+6;
static volatile bit           C1_TXEN6           @ ((unsigned)&C1TR67CON*8)+7;
static volatile bit           C1_TX7PRI0         @ ((unsigned)&C1TR67CON*8)+8;
static volatile bit           C1_TX7PRI1         @ ((unsigned)&C1TR67CON*8)+9;
static volatile bit           C1_RTREN7          @ ((unsigned)&C1TR67CON*8)+10;
static volatile bit           C1_TXREQ7          @ ((unsigned)&C1TR67CON*8)+11;
static volatile bit           C1_TXERR7          @ ((unsigned)&C1TR67CON*8)+12;
static volatile bit           C1_TXLARB7         @ ((unsigned)&C1TR67CON*8)+13;
static volatile bit           C1_TXABT7          @ ((unsigned)&C1TR67CON*8)+14;
static volatile bit           C1_TXEN7           @ ((unsigned)&C1TR67CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      TXEN7              : 1;
       volatile unsigned      TXABT7             : 1;
       volatile unsigned      TXLARB7            : 1;
       volatile unsigned      TXERR7             : 1;
       volatile unsigned      TXREQ7             : 1;
       volatile unsigned      RTREN7             : 1;
       volatile unsigned      TX7PRI             : 2;
       volatile unsigned      TXEN6              : 1;
       volatile unsigned      TXABT6             : 1;
       volatile unsigned      TXLARB6            : 1;
       volatile unsigned      TXERR6             : 1;
       volatile unsigned      TXREQ6             : 1;
       volatile unsigned      RTREN6             : 1;
       volatile unsigned      TX6PRI             : 2;
} C1TR67CONbits @ 0x436;

static volatile unsigned int  C1RXM2SID          @ 0x438;
static volatile bit           C1RXM2_EID16       @ ((unsigned)&C1RXM2SID*8)+0;
static volatile bit           C1RXM2_EID17       @ ((unsigned)&C1RXM2SID*8)+1;
static volatile bit           C1RXM2_MIDE        @ ((unsigned)&C1RXM2SID*8)+3;
static volatile bit           C1RXM2_SID0        @ ((unsigned)&C1RXM2SID*8)+5;
static volatile bit           C1RXM2_SID1        @ ((unsigned)&C1RXM2SID*8)+6;
static volatile bit           C1RXM2_SID2        @ ((unsigned)&C1RXM2SID*8)+7;
static volatile bit           C1RXM2_SID3        @ ((unsigned)&C1RXM2SID*8)+8;
static volatile bit           C1RXM2_SID4        @ ((unsigned)&C1RXM2SID*8)+9;
static volatile bit           C1RXM2_SID5        @ ((unsigned)&C1RXM2SID*8)+10;
static volatile bit           C1RXM2_SID6        @ ((unsigned)&C1RXM2SID*8)+11;
static volatile bit           C1RXM2_SID7        @ ((unsigned)&C1RXM2SID*8)+12;
static volatile bit           C1RXM2_SID8        @ ((unsigned)&C1RXM2SID*8)+13;
static volatile bit           C1RXM2_SID9        @ ((unsigned)&C1RXM2SID*8)+14;
static volatile bit           C1RXM2_SID10       @ ((unsigned)&C1RXM2SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      MIDE               : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C1RXM2SIDbits @ 0x438;

static volatile unsigned int  C1RXM2EID          @ 0x43A;
static volatile unsigned int  C1RXF0SID          @ 0x440;
static volatile bit           C1RXF0_EID16       @ ((unsigned)&C1RXF0SID*8)+0;
static volatile bit           C1RXF0_EID17       @ ((unsigned)&C1RXF0SID*8)+1;
static volatile bit           C1RXF0_EXIDE       @ ((unsigned)&C1RXF0SID*8)+3;
static volatile bit           C1RXF0_SID0        @ ((unsigned)&C1RXF0SID*8)+5;
static volatile bit           C1RXF0_SID1        @ ((unsigned)&C1RXF0SID*8)+6;
static volatile bit           C1RXF0_SID2        @ ((unsigned)&C1RXF0SID*8)+7;
static volatile bit           C1RXF0_SID3        @ ((unsigned)&C1RXF0SID*8)+8;
static volatile bit           C1RXF0_SID4        @ ((unsigned)&C1RXF0SID*8)+9;
static volatile bit           C1RXF0_SID5        @ ((unsigned)&C1RXF0SID*8)+10;
static volatile bit           C1RXF0_SID6        @ ((unsigned)&C1RXF0SID*8)+11;
static volatile bit           C1RXF0_SID7        @ ((unsigned)&C1RXF0SID*8)+12;
static volatile bit           C1RXF0_SID8        @ ((unsigned)&C1RXF0SID*8)+13;
static volatile bit           C1RXF0_SID9        @ ((unsigned)&C1RXF0SID*8)+14;
static volatile bit           C1RXF0_SID10       @ ((unsigned)&C1RXF0SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C1RXF0SIDbits @ 0x440;

static volatile unsigned int  C1RXF0EID          @ 0x442;
static volatile unsigned int  C1RXF1SID          @ 0x444;
static volatile bit           C1RXF1_EID16       @ ((unsigned)&C1RXF1SID*8)+0;
static volatile bit           C1RXF1_EID17       @ ((unsigned)&C1RXF1SID*8)+1;
static volatile bit           C1RXF1_EXIDE       @ ((unsigned)&C1RXF1SID*8)+3;
static volatile bit           C1RXF1_SID0        @ ((unsigned)&C1RXF1SID*8)+5;
static volatile bit           C1RXF1_SID1        @ ((unsigned)&C1RXF1SID*8)+6;
static volatile bit           C1RXF1_SID2        @ ((unsigned)&C1RXF1SID*8)+7;
static volatile bit           C1RXF1_SID3        @ ((unsigned)&C1RXF1SID*8)+8;
static volatile bit           C1RXF1_SID4        @ ((unsigned)&C1RXF1SID*8)+9;
static volatile bit           C1RXF1_SID5        @ ((unsigned)&C1RXF1SID*8)+10;
static volatile bit           C1RXF1_SID6        @ ((unsigned)&C1RXF1SID*8)+11;
static volatile bit           C1RXF1_SID7        @ ((unsigned)&C1RXF1SID*8)+12;
static volatile bit           C1RXF1_SID8        @ ((unsigned)&C1RXF1SID*8)+13;
static volatile bit           C1RXF1_SID9        @ ((unsigned)&C1RXF1SID*8)+14;
static volatile bit           C1RXF1_SID10       @ ((unsigned)&C1RXF1SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C1RXF1SIDbits @ 0x444;

static volatile unsigned int  C1RXF1EID          @ 0x446;
static volatile unsigned int  C1RXF2SID          @ 0x448;
static volatile bit           C1RXF2_EID16       @ ((unsigned)&C1RXF2SID*8)+0;
static volatile bit           C1RXF2_EID17       @ ((unsigned)&C1RXF2SID*8)+1;
static volatile bit           C1RXF2_EXIDE       @ ((unsigned)&C1RXF2SID*8)+3;
static volatile bit           C1RXF2_SID0        @ ((unsigned)&C1RXF2SID*8)+5;
static volatile bit           C1RXF2_SID1        @ ((unsigned)&C1RXF2SID*8)+6;
static volatile bit           C1RXF2_SID2        @ ((unsigned)&C1RXF2SID*8)+7;
static volatile bit           C1RXF2_SID3        @ ((unsigned)&C1RXF2SID*8)+8;
static volatile bit           C1RXF2_SID4        @ ((unsigned)&C1RXF2SID*8)+9;
static volatile bit           C1RXF2_SID5        @ ((unsigned)&C1RXF2SID*8)+10;
static volatile bit           C1RXF2_SID6        @ ((unsigned)&C1RXF2SID*8)+11;
static volatile bit           C1RXF2_SID7        @ ((unsigned)&C1RXF2SID*8)+12;
static volatile bit           C1RXF2_SID8        @ ((unsigned)&C1RXF2SID*8)+13;
static volatile bit           C1RXF2_SID9        @ ((unsigned)&C1RXF2SID*8)+14;
static volatile bit           C1RXF2_SID10       @ ((unsigned)&C1RXF2SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C1RXF2SIDbits @ 0x448;

static volatile unsigned int  C1RXF2EID          @ 0x44A;
static volatile unsigned int  C1RXF3SID          @ 0x44C;
static volatile bit           C1RXF3_EID16       @ ((unsigned)&C1RXF3SID*8)+0;
static volatile bit           C1RXF3_EID17       @ ((unsigned)&C1RXF3SID*8)+1;
static volatile bit           C1RXF3_EXIDE       @ ((unsigned)&C1RXF3SID*8)+3;
static volatile bit           C1RXF3_SID0        @ ((unsigned)&C1RXF3SID*8)+5;
static volatile bit           C1RXF3_SID1        @ ((unsigned)&C1RXF3SID*8)+6;
static volatile bit           C1RXF3_SID2        @ ((unsigned)&C1RXF3SID*8)+7;
static volatile bit           C1RXF3_SID3        @ ((unsigned)&C1RXF3SID*8)+8;
static volatile bit           C1RXF3_SID4        @ ((unsigned)&C1RXF3SID*8)+9;
static volatile bit           C1RXF3_SID5        @ ((unsigned)&C1RXF3SID*8)+10;
static volatile bit           C1RXF3_SID6        @ ((unsigned)&C1RXF3SID*8)+11;
static volatile bit           C1RXF3_SID7        @ ((unsigned)&C1RXF3SID*8)+12;
static volatile bit           C1RXF3_SID8        @ ((unsigned)&C1RXF3SID*8)+13;
static volatile bit           C1RXF3_SID9        @ ((unsigned)&C1RXF3SID*8)+14;
static volatile bit           C1RXF3_SID10       @ ((unsigned)&C1RXF3SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C1RXF3SIDbits @ 0x44C;

static volatile unsigned int  C1RXF3EID          @ 0x44E;
static volatile unsigned int  C1RXF4SID          @ 0x450;
static volatile bit           C1RXF4_EID16       @ ((unsigned)&C1RXF4SID*8)+0;
static volatile bit           C1RXF4_EID17       @ ((unsigned)&C1RXF4SID*8)+1;
static volatile bit           C1RXF4_EXIDE       @ ((unsigned)&C1RXF4SID*8)+3;
static volatile bit           C1RXF4_SID0        @ ((unsigned)&C1RXF4SID*8)+5;
static volatile bit           C1RXF4_SID1        @ ((unsigned)&C1RXF4SID*8)+6;
static volatile bit           C1RXF4_SID2        @ ((unsigned)&C1RXF4SID*8)+7;
static volatile bit           C1RXF4_SID3        @ ((unsigned)&C1RXF4SID*8)+8;
static volatile bit           C1RXF4_SID4        @ ((unsigned)&C1RXF4SID*8)+9;
static volatile bit           C1RXF4_SID5        @ ((unsigned)&C1RXF4SID*8)+10;
static volatile bit           C1RXF4_SID6        @ ((unsigned)&C1RXF4SID*8)+11;
static volatile bit           C1RXF4_SID7        @ ((unsigned)&C1RXF4SID*8)+12;
static volatile bit           C1RXF4_SID8        @ ((unsigned)&C1RXF4SID*8)+13;
static volatile bit           C1RXF4_SID9        @ ((unsigned)&C1RXF4SID*8)+14;
static volatile bit           C1RXF4_SID10       @ ((unsigned)&C1RXF4SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C1RXF4SIDbits @ 0x450;

static volatile unsigned int  C1RXF4EID          @ 0x452;
static volatile unsigned int  C1RXF5SID          @ 0x454;
static volatile bit           C1RXF5_EID16       @ ((unsigned)&C1RXF5SID*8)+0;
static volatile bit           C1RXF5_EID17       @ ((unsigned)&C1RXF5SID*8)+1;
static volatile bit           C1RXF5_EXIDE       @ ((unsigned)&C1RXF5SID*8)+3;
static volatile bit           C1RXF5_SID0        @ ((unsigned)&C1RXF5SID*8)+5;
static volatile bit           C1RXF5_SID1        @ ((unsigned)&C1RXF5SID*8)+6;
static volatile bit           C1RXF5_SID2        @ ((unsigned)&C1RXF5SID*8)+7;
static volatile bit           C1RXF5_SID3        @ ((unsigned)&C1RXF5SID*8)+8;
static volatile bit           C1RXF5_SID4        @ ((unsigned)&C1RXF5SID*8)+9;
static volatile bit           C1RXF5_SID5        @ ((unsigned)&C1RXF5SID*8)+10;
static volatile bit           C1RXF5_SID6        @ ((unsigned)&C1RXF5SID*8)+11;
static volatile bit           C1RXF5_SID7        @ ((unsigned)&C1RXF5SID*8)+12;
static volatile bit           C1RXF5_SID8        @ ((unsigned)&C1RXF5SID*8)+13;
static volatile bit           C1RXF5_SID9        @ ((unsigned)&C1RXF5SID*8)+14;
static volatile bit           C1RXF5_SID10       @ ((unsigned)&C1RXF5SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C1RXF5SIDbits @ 0x454;

static volatile unsigned int  C1RXF5EID          @ 0x456;
static volatile unsigned int  C1RXF6SID          @ 0x458;
static volatile bit           C1RXF6_EID16       @ ((unsigned)&C1RXF6SID*8)+0;
static volatile bit           C1RXF6_EID17       @ ((unsigned)&C1RXF6SID*8)+1;
static volatile bit           C1RXF6_EXIDE       @ ((unsigned)&C1RXF6SID*8)+3;
static volatile bit           C1RXF6_SID0        @ ((unsigned)&C1RXF6SID*8)+5;
static volatile bit           C1RXF6_SID1        @ ((unsigned)&C1RXF6SID*8)+6;
static volatile bit           C1RXF6_SID2        @ ((unsigned)&C1RXF6SID*8)+7;
static volatile bit           C1RXF6_SID3        @ ((unsigned)&C1RXF6SID*8)+8;
static volatile bit           C1RXF6_SID4        @ ((unsigned)&C1RXF6SID*8)+9;
static volatile bit           C1RXF6_SID5        @ ((unsigned)&C1RXF6SID*8)+10;
static volatile bit           C1RXF6_SID6        @ ((unsigned)&C1RXF6SID*8)+11;
static volatile bit           C1RXF6_SID7        @ ((unsigned)&C1RXF6SID*8)+12;
static volatile bit           C1RXF6_SID8        @ ((unsigned)&C1RXF6SID*8)+13;
static volatile bit           C1RXF6_SID9        @ ((unsigned)&C1RXF6SID*8)+14;
static volatile bit           C1RXF6_SID10       @ ((unsigned)&C1RXF6SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C1RXF6SIDbits @ 0x458;

static volatile unsigned int  C1RXF6EID          @ 0x45A;
static volatile unsigned int  C1RXF7SID          @ 0x45C;
static volatile bit           C1RXF7_EID16       @ ((unsigned)&C1RXF7SID*8)+0;
static volatile bit           C1RXF7_EID17       @ ((unsigned)&C1RXF7SID*8)+1;
static volatile bit           C1RXF7_EXIDE       @ ((unsigned)&C1RXF7SID*8)+3;
static volatile bit           C1RXF7_SID0        @ ((unsigned)&C1RXF7SID*8)+5;
static volatile bit           C1RXF7_SID1        @ ((unsigned)&C1RXF7SID*8)+6;
static volatile bit           C1RXF7_SID2        @ ((unsigned)&C1RXF7SID*8)+7;
static volatile bit           C1RXF7_SID3        @ ((unsigned)&C1RXF7SID*8)+8;
static volatile bit           C1RXF7_SID4        @ ((unsigned)&C1RXF7SID*8)+9;
static volatile bit           C1RXF7_SID5        @ ((unsigned)&C1RXF7SID*8)+10;
static volatile bit           C1RXF7_SID6        @ ((unsigned)&C1RXF7SID*8)+11;
static volatile bit           C1RXF7_SID7        @ ((unsigned)&C1RXF7SID*8)+12;
static volatile bit           C1RXF7_SID8        @ ((unsigned)&C1RXF7SID*8)+13;
static volatile bit           C1RXF7_SID9        @ ((unsigned)&C1RXF7SID*8)+14;
static volatile bit           C1RXF7_SID10       @ ((unsigned)&C1RXF7SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C1RXF7SIDbits @ 0x45C;

static volatile unsigned int  C1RXF7EID          @ 0x45E;
static volatile unsigned int  C1RXF8SID          @ 0x460;
static volatile bit           C1RXF8_EID16       @ ((unsigned)&C1RXF8SID*8)+0;
static volatile bit           C1RXF8_EID17       @ ((unsigned)&C1RXF8SID*8)+1;
static volatile bit           C1RXF8_EXIDE       @ ((unsigned)&C1RXF8SID*8)+3;
static volatile bit           C1RXF8_SID0        @ ((unsigned)&C1RXF8SID*8)+5;
static volatile bit           C1RXF8_SID1        @ ((unsigned)&C1RXF8SID*8)+6;
static volatile bit           C1RXF8_SID2        @ ((unsigned)&C1RXF8SID*8)+7;
static volatile bit           C1RXF8_SID3        @ ((unsigned)&C1RXF8SID*8)+8;
static volatile bit           C1RXF8_SID4        @ ((unsigned)&C1RXF8SID*8)+9;
static volatile bit           C1RXF8_SID5        @ ((unsigned)&C1RXF8SID*8)+10;
static volatile bit           C1RXF8_SID6        @ ((unsigned)&C1RXF8SID*8)+11;
static volatile bit           C1RXF8_SID7        @ ((unsigned)&C1RXF8SID*8)+12;
static volatile bit           C1RXF8_SID8        @ ((unsigned)&C1RXF8SID*8)+13;
static volatile bit           C1RXF8_SID9        @ ((unsigned)&C1RXF8SID*8)+14;
static volatile bit           C1RXF8_SID10       @ ((unsigned)&C1RXF8SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C1RXF8SIDbits @ 0x460;

static volatile unsigned int  C1RXF8EID          @ 0x462;
static volatile unsigned int  C1RXF9SID          @ 0x464;
static volatile bit           C1RXF9_EID16       @ ((unsigned)&C1RXF9SID*8)+0;
static volatile bit           C1RXF9_EID17       @ ((unsigned)&C1RXF9SID*8)+1;
static volatile bit           C1RXF9_EXIDE       @ ((unsigned)&C1RXF9SID*8)+3;
static volatile bit           C1RXF9_SID0        @ ((unsigned)&C1RXF9SID*8)+5;
static volatile bit           C1RXF9_SID1        @ ((unsigned)&C1RXF9SID*8)+6;
static volatile bit           C1RXF9_SID2        @ ((unsigned)&C1RXF9SID*8)+7;
static volatile bit           C1RXF9_SID3        @ ((unsigned)&C1RXF9SID*8)+8;
static volatile bit           C1RXF9_SID4        @ ((unsigned)&C1RXF9SID*8)+9;
static volatile bit           C1RXF9_SID5        @ ((unsigned)&C1RXF9SID*8)+10;
static volatile bit           C1RXF9_SID6        @ ((unsigned)&C1RXF9SID*8)+11;
static volatile bit           C1RXF9_SID7        @ ((unsigned)&C1RXF9SID*8)+12;
static volatile bit           C1RXF9_SID8        @ ((unsigned)&C1RXF9SID*8)+13;
static volatile bit           C1RXF9_SID9        @ ((unsigned)&C1RXF9SID*8)+14;
static volatile bit           C1RXF9_SID10       @ ((unsigned)&C1RXF9SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C1RXF9SIDbits @ 0x464;

static volatile unsigned int  C1RXF9EID          @ 0x466;
static volatile unsigned int  C1RXF10SID         @ 0x468;
static volatile bit           C1RXF10_EID16      @ ((unsigned)&C1RXF10SID*8)+0;
static volatile bit           C1RXF10_EID17      @ ((unsigned)&C1RXF10SID*8)+1;
static volatile bit           C1RXF10_EXIDE      @ ((unsigned)&C1RXF10SID*8)+3;
static volatile bit           C1RXF10_SID0       @ ((unsigned)&C1RXF10SID*8)+5;
static volatile bit           C1RXF10_SID1       @ ((unsigned)&C1RXF10SID*8)+6;
static volatile bit           C1RXF10_SID2       @ ((unsigned)&C1RXF10SID*8)+7;
static volatile bit           C1RXF10_SID3       @ ((unsigned)&C1RXF10SID*8)+8;
static volatile bit           C1RXF10_SID4       @ ((unsigned)&C1RXF10SID*8)+9;
static volatile bit           C1RXF10_SID5       @ ((unsigned)&C1RXF10SID*8)+10;
static volatile bit           C1RXF10_SID6       @ ((unsigned)&C1RXF10SID*8)+11;
static volatile bit           C1RXF10_SID7       @ ((unsigned)&C1RXF10SID*8)+12;
static volatile bit           C1RXF10_SID8       @ ((unsigned)&C1RXF10SID*8)+13;
static volatile bit           C1RXF10_SID9       @ ((unsigned)&C1RXF10SID*8)+14;
static volatile bit           C1RXF10_SID10      @ ((unsigned)&C1RXF10SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C1RXF10SIDbits @ 0x468;

static volatile unsigned int  C1RXF10EID         @ 0x46A;
static volatile bit           C1RXF10_EID0       @ ((unsigned)&C1RXF10EID*8)+0;
static volatile bit           C1RXF10_EID1       @ ((unsigned)&C1RXF10EID*8)+1;
static volatile bit           C1RXF10_EID2       @ ((unsigned)&C1RXF10EID*8)+2;
static volatile bit           C1RXF10_EID3       @ ((unsigned)&C1RXF10EID*8)+3;
static volatile bit           C1RXF10_EID4       @ ((unsigned)&C1RXF10EID*8)+4;
static volatile bit           C1RXF10_EID5       @ ((unsigned)&C1RXF10EID*8)+5;
static volatile bit           C1RXF10_EID6       @ ((unsigned)&C1RXF10EID*8)+6;
static volatile bit           C1RXF10_EID7       @ ((unsigned)&C1RXF10EID*8)+7;
static volatile bit           C1RXF10_EID8       @ ((unsigned)&C1RXF10EID*8)+8;
static volatile bit           C1RXF10_EID9       @ ((unsigned)&C1RXF10EID*8)+9;
static volatile bit           C1RXF10_EID10      @ ((unsigned)&C1RXF10EID*8)+10;
static volatile bit           C1RXF10_EID11      @ ((unsigned)&C1RXF10EID*8)+11;
static volatile bit           C1RXF10_EID12      @ ((unsigned)&C1RXF10EID*8)+12;
static volatile bit           C1RXF10_EID13      @ ((unsigned)&C1RXF10EID*8)+13;
static volatile bit           C1RXF10_EID14      @ ((unsigned)&C1RXF10EID*8)+14;
static volatile bit           C1RXF10_EID15      @ ((unsigned)&C1RXF10EID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      EID15              : 1;
       volatile unsigned      EID14              : 1;
       volatile unsigned      EID13              : 1;
       volatile unsigned      EID12              : 1;
       volatile unsigned      EID11              : 1;
       volatile unsigned      EID10              : 1;
       volatile unsigned      EID9               : 1;
       volatile unsigned      EID8               : 1;
       volatile unsigned      EID7               : 1;
       volatile unsigned      EID6               : 1;
       volatile unsigned      EID5               : 1;
       volatile unsigned      EID4               : 1;
       volatile unsigned      EID3               : 1;
       volatile unsigned      EID2               : 1;
       volatile unsigned      EID1               : 1;
       volatile unsigned      EID0               : 1;
} C1RXF10EIDbits @ 0x46A;

static volatile unsigned int  C1RXF11SID         @ 0x46C;
static volatile bit           C1RXF11_EID16      @ ((unsigned)&C1RXF11SID*8)+0;
static volatile bit           C1RXF11_EID17      @ ((unsigned)&C1RXF11SID*8)+1;
static volatile bit           C1RXF11_EXIDE      @ ((unsigned)&C1RXF11SID*8)+3;
static volatile bit           C1RXF11_SID0       @ ((unsigned)&C1RXF11SID*8)+5;
static volatile bit           C1RXF11_SID1       @ ((unsigned)&C1RXF11SID*8)+6;
static volatile bit           C1RXF11_SID2       @ ((unsigned)&C1RXF11SID*8)+7;
static volatile bit           C1RXF11_SID3       @ ((unsigned)&C1RXF11SID*8)+8;
static volatile bit           C1RXF11_SID4       @ ((unsigned)&C1RXF11SID*8)+9;
static volatile bit           C1RXF11_SID5       @ ((unsigned)&C1RXF11SID*8)+10;
static volatile bit           C1RXF11_SID6       @ ((unsigned)&C1RXF11SID*8)+11;
static volatile bit           C1RXF11_SID7       @ ((unsigned)&C1RXF11SID*8)+12;
static volatile bit           C1RXF11_SID8       @ ((unsigned)&C1RXF11SID*8)+13;
static volatile bit           C1RXF11_SID9       @ ((unsigned)&C1RXF11SID*8)+14;
static volatile bit           C1RXF11_SID10      @ ((unsigned)&C1RXF11SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C1RXF11SIDbits @ 0x46C;

static volatile unsigned int  C1RXF11EID         @ 0x46E;
static volatile bit           C1RXF11_EID0       @ ((unsigned)&C1RXF11EID*8)+0;
static volatile bit           C1RXF11_EID1       @ ((unsigned)&C1RXF11EID*8)+1;
static volatile bit           C1RXF11_EID2       @ ((unsigned)&C1RXF11EID*8)+2;
static volatile bit           C1RXF11_EID3       @ ((unsigned)&C1RXF11EID*8)+3;
static volatile bit           C1RXF11_EID4       @ ((unsigned)&C1RXF11EID*8)+4;
static volatile bit           C1RXF11_EID5       @ ((unsigned)&C1RXF11EID*8)+5;
static volatile bit           C1RXF11_EID6       @ ((unsigned)&C1RXF11EID*8)+6;
static volatile bit           C1RXF11_EID7       @ ((unsigned)&C1RXF11EID*8)+7;
static volatile bit           C1RXF11_EID8       @ ((unsigned)&C1RXF11EID*8)+8;
static volatile bit           C1RXF11_EID9       @ ((unsigned)&C1RXF11EID*8)+9;
static volatile bit           C1RXF11_EID10      @ ((unsigned)&C1RXF11EID*8)+10;
static volatile bit           C1RXF11_EID11      @ ((unsigned)&C1RXF11EID*8)+11;
static volatile bit           C1RXF11_EID12      @ ((unsigned)&C1RXF11EID*8)+12;
static volatile bit           C1RXF11_EID13      @ ((unsigned)&C1RXF11EID*8)+13;
static volatile bit           C1RXF11_EID14      @ ((unsigned)&C1RXF11EID*8)+14;
static volatile bit           C1RXF11_EID15      @ ((unsigned)&C1RXF11EID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      EID15              : 1;
       volatile unsigned      EID14              : 1;
       volatile unsigned      EID13              : 1;
       volatile unsigned      EID12              : 1;
       volatile unsigned      EID11              : 1;
       volatile unsigned      EID10              : 1;
       volatile unsigned      EID9               : 1;
       volatile unsigned      EID8               : 1;
       volatile unsigned      EID7               : 1;
       volatile unsigned      EID6               : 1;
       volatile unsigned      EID5               : 1;
       volatile unsigned      EID4               : 1;
       volatile unsigned      EID3               : 1;
       volatile unsigned      EID2               : 1;
       volatile unsigned      EID1               : 1;
       volatile unsigned      EID0               : 1;
} C1RXF11EIDbits @ 0x46E;

static volatile unsigned int  C1RXF12SID         @ 0x470;
static volatile bit           C1RXF12_EID16      @ ((unsigned)&C1RXF12SID*8)+0;
static volatile bit           C1RXF12_EID17      @ ((unsigned)&C1RXF12SID*8)+1;
static volatile bit           C1RXF12_EXIDE      @ ((unsigned)&C1RXF12SID*8)+3;
static volatile bit           C1RXF12_SID0       @ ((unsigned)&C1RXF12SID*8)+5;
static volatile bit           C1RXF12_SID1       @ ((unsigned)&C1RXF12SID*8)+6;
static volatile bit           C1RXF12_SID2       @ ((unsigned)&C1RXF12SID*8)+7;
static volatile bit           C1RXF12_SID3       @ ((unsigned)&C1RXF12SID*8)+8;
static volatile bit           C1RXF12_SID4       @ ((unsigned)&C1RXF12SID*8)+9;
static volatile bit           C1RXF12_SID5       @ ((unsigned)&C1RXF12SID*8)+10;
static volatile bit           C1RXF12_SID6       @ ((unsigned)&C1RXF12SID*8)+11;
static volatile bit           C1RXF12_SID7       @ ((unsigned)&C1RXF12SID*8)+12;
static volatile bit           C1RXF12_SID8       @ ((unsigned)&C1RXF12SID*8)+13;
static volatile bit           C1RXF12_SID9       @ ((unsigned)&C1RXF12SID*8)+14;
static volatile bit           C1RXF12_SID10      @ ((unsigned)&C1RXF12SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C1RXF12SIDbits @ 0x470;

static volatile unsigned int  C1RXF12EID         @ 0x472;
static volatile bit           C1RXF12_EID0       @ ((unsigned)&C1RXF12EID*8)+0;
static volatile bit           C1RXF12_EID1       @ ((unsigned)&C1RXF12EID*8)+1;
static volatile bit           C1RXF12_EID2       @ ((unsigned)&C1RXF12EID*8)+2;
static volatile bit           C1RXF12_EID3       @ ((unsigned)&C1RXF12EID*8)+3;
static volatile bit           C1RXF12_EID4       @ ((unsigned)&C1RXF12EID*8)+4;
static volatile bit           C1RXF12_EID5       @ ((unsigned)&C1RXF12EID*8)+5;
static volatile bit           C1RXF12_EID6       @ ((unsigned)&C1RXF12EID*8)+6;
static volatile bit           C1RXF12_EID7       @ ((unsigned)&C1RXF12EID*8)+7;
static volatile bit           C1RXF12_EID8       @ ((unsigned)&C1RXF12EID*8)+8;
static volatile bit           C1RXF12_EID9       @ ((unsigned)&C1RXF12EID*8)+9;
static volatile bit           C1RXF12_EID10      @ ((unsigned)&C1RXF12EID*8)+10;
static volatile bit           C1RXF12_EID11      @ ((unsigned)&C1RXF12EID*8)+11;
static volatile bit           C1RXF12_EID12      @ ((unsigned)&C1RXF12EID*8)+12;
static volatile bit           C1RXF12_EID13      @ ((unsigned)&C1RXF12EID*8)+13;
static volatile bit           C1RXF12_EID14      @ ((unsigned)&C1RXF12EID*8)+14;
static volatile bit           C1RXF12_EID15      @ ((unsigned)&C1RXF12EID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      EID15              : 1;
       volatile unsigned      EID14              : 1;
       volatile unsigned      EID13              : 1;
       volatile unsigned      EID12              : 1;
       volatile unsigned      EID11              : 1;
       volatile unsigned      EID10              : 1;
       volatile unsigned      EID9               : 1;
       volatile unsigned      EID8               : 1;
       volatile unsigned      EID7               : 1;
       volatile unsigned      EID6               : 1;
       volatile unsigned      EID5               : 1;
       volatile unsigned      EID4               : 1;
       volatile unsigned      EID3               : 1;
       volatile unsigned      EID2               : 1;
       volatile unsigned      EID1               : 1;
       volatile unsigned      EID0               : 1;
} C1RXF12EIDbits @ 0x472;

static volatile unsigned int  C1RXF13SID         @ 0x474;
static volatile bit           C1RXF13_EID16      @ ((unsigned)&C1RXF13SID*8)+0;
static volatile bit           C1RXF13_EID17      @ ((unsigned)&C1RXF13SID*8)+1;
static volatile bit           C1RXF13_EXIDE      @ ((unsigned)&C1RXF13SID*8)+3;
static volatile bit           C1RXF13_SID0       @ ((unsigned)&C1RXF13SID*8)+5;
static volatile bit           C1RXF13_SID1       @ ((unsigned)&C1RXF13SID*8)+6;
static volatile bit           C1RXF13_SID2       @ ((unsigned)&C1RXF13SID*8)+7;
static volatile bit           C1RXF13_SID3       @ ((unsigned)&C1RXF13SID*8)+8;
static volatile bit           C1RXF13_SID4       @ ((unsigned)&C1RXF13SID*8)+9;
static volatile bit           C1RXF13_SID5       @ ((unsigned)&C1RXF13SID*8)+10;
static volatile bit           C1RXF13_SID6       @ ((unsigned)&C1RXF13SID*8)+11;
static volatile bit           C1RXF13_SID7       @ ((unsigned)&C1RXF13SID*8)+12;
static volatile bit           C1RXF13_SID8       @ ((unsigned)&C1RXF13SID*8)+13;
static volatile bit           C1RXF13_SID9       @ ((unsigned)&C1RXF13SID*8)+14;
static volatile bit           C1RXF13_SID10      @ ((unsigned)&C1RXF13SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C1RXF13SIDbits @ 0x474;

static volatile unsigned int  C1RXF13EID         @ 0x476;
static volatile bit           C1RXF13_EID0       @ ((unsigned)&C1RXF13EID*8)+0;
static volatile bit           C1RXF13_EID1       @ ((unsigned)&C1RXF13EID*8)+1;
static volatile bit           C1RXF13_EID2       @ ((unsigned)&C1RXF13EID*8)+2;
static volatile bit           C1RXF13_EID3       @ ((unsigned)&C1RXF13EID*8)+3;
static volatile bit           C1RXF13_EID4       @ ((unsigned)&C1RXF13EID*8)+4;
static volatile bit           C1RXF13_EID5       @ ((unsigned)&C1RXF13EID*8)+5;
static volatile bit           C1RXF13_EID6       @ ((unsigned)&C1RXF13EID*8)+6;
static volatile bit           C1RXF13_EID7       @ ((unsigned)&C1RXF13EID*8)+7;
static volatile bit           C1RXF13_EID8       @ ((unsigned)&C1RXF13EID*8)+8;
static volatile bit           C1RXF13_EID9       @ ((unsigned)&C1RXF13EID*8)+9;
static volatile bit           C1RXF13_EID10      @ ((unsigned)&C1RXF13EID*8)+10;
static volatile bit           C1RXF13_EID11      @ ((unsigned)&C1RXF13EID*8)+11;
static volatile bit           C1RXF13_EID12      @ ((unsigned)&C1RXF13EID*8)+12;
static volatile bit           C1RXF13_EID13      @ ((unsigned)&C1RXF13EID*8)+13;
static volatile bit           C1RXF13_EID14      @ ((unsigned)&C1RXF13EID*8)+14;
static volatile bit           C1RXF13_EID15      @ ((unsigned)&C1RXF13EID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      EID15              : 1;
       volatile unsigned      EID14              : 1;
       volatile unsigned      EID13              : 1;
       volatile unsigned      EID12              : 1;
       volatile unsigned      EID11              : 1;
       volatile unsigned      EID10              : 1;
       volatile unsigned      EID9               : 1;
       volatile unsigned      EID8               : 1;
       volatile unsigned      EID7               : 1;
       volatile unsigned      EID6               : 1;
       volatile unsigned      EID5               : 1;
       volatile unsigned      EID4               : 1;
       volatile unsigned      EID3               : 1;
       volatile unsigned      EID2               : 1;
       volatile unsigned      EID1               : 1;
       volatile unsigned      EID0               : 1;
} C1RXF13EIDbits @ 0x476;

static volatile unsigned int  C1RXF14SID         @ 0x478;
static volatile bit           C1RXF14_EID16      @ ((unsigned)&C1RXF14SID*8)+0;
static volatile bit           C1RXF14_EID17      @ ((unsigned)&C1RXF14SID*8)+1;
static volatile bit           C1RXF14_EXIDE      @ ((unsigned)&C1RXF14SID*8)+3;
static volatile bit           C1RXF14_SID0       @ ((unsigned)&C1RXF14SID*8)+5;
static volatile bit           C1RXF14_SID1       @ ((unsigned)&C1RXF14SID*8)+6;
static volatile bit           C1RXF14_SID2       @ ((unsigned)&C1RXF14SID*8)+7;
static volatile bit           C1RXF14_SID3       @ ((unsigned)&C1RXF14SID*8)+8;
static volatile bit           C1RXF14_SID4       @ ((unsigned)&C1RXF14SID*8)+9;
static volatile bit           C1RXF14_SID5       @ ((unsigned)&C1RXF14SID*8)+10;
static volatile bit           C1RXF14_SID6       @ ((unsigned)&C1RXF14SID*8)+11;
static volatile bit           C1RXF14_SID7       @ ((unsigned)&C1RXF14SID*8)+12;
static volatile bit           C1RXF14_SID8       @ ((unsigned)&C1RXF14SID*8)+13;
static volatile bit           C1RXF14_SID9       @ ((unsigned)&C1RXF14SID*8)+14;
static volatile bit           C1RXF14_SID10      @ ((unsigned)&C1RXF14SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C1RXF14SIDbits @ 0x478;

static volatile unsigned int  C1RXF14EID         @ 0x47A;
static volatile bit           C1RXF14_EID0       @ ((unsigned)&C1RXF14EID*8)+0;
static volatile bit           C1RXF14_EID1       @ ((unsigned)&C1RXF14EID*8)+1;
static volatile bit           C1RXF14_EID2       @ ((unsigned)&C1RXF14EID*8)+2;
static volatile bit           C1RXF14_EID3       @ ((unsigned)&C1RXF14EID*8)+3;
static volatile bit           C1RXF14_EID4       @ ((unsigned)&C1RXF14EID*8)+4;
static volatile bit           C1RXF14_EID5       @ ((unsigned)&C1RXF14EID*8)+5;
static volatile bit           C1RXF14_EID6       @ ((unsigned)&C1RXF14EID*8)+6;
static volatile bit           C1RXF14_EID7       @ ((unsigned)&C1RXF14EID*8)+7;
static volatile bit           C1RXF14_EID8       @ ((unsigned)&C1RXF14EID*8)+8;
static volatile bit           C1RXF14_EID9       @ ((unsigned)&C1RXF14EID*8)+9;
static volatile bit           C1RXF14_EID10      @ ((unsigned)&C1RXF14EID*8)+10;
static volatile bit           C1RXF14_EID11      @ ((unsigned)&C1RXF14EID*8)+11;
static volatile bit           C1RXF14_EID12      @ ((unsigned)&C1RXF14EID*8)+12;
static volatile bit           C1RXF14_EID13      @ ((unsigned)&C1RXF14EID*8)+13;
static volatile bit           C1RXF14_EID14      @ ((unsigned)&C1RXF14EID*8)+14;
static volatile bit           C1RXF14_EID15      @ ((unsigned)&C1RXF14EID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      EID15              : 1;
       volatile unsigned      EID14              : 1;
       volatile unsigned      EID13              : 1;
       volatile unsigned      EID12              : 1;
       volatile unsigned      EID11              : 1;
       volatile unsigned      EID10              : 1;
       volatile unsigned      EID9               : 1;
       volatile unsigned      EID8               : 1;
       volatile unsigned      EID7               : 1;
       volatile unsigned      EID6               : 1;
       volatile unsigned      EID5               : 1;
       volatile unsigned      EID4               : 1;
       volatile unsigned      EID3               : 1;
       volatile unsigned      EID2               : 1;
       volatile unsigned      EID1               : 1;
       volatile unsigned      EID0               : 1;
} C1RXF14EIDbits @ 0x47A;

static volatile unsigned int  C1RXF15SID         @ 0x47C;
static volatile bit           C1RXF15_EID16      @ ((unsigned)&C1RXF15SID*8)+0;
static volatile bit           C1RXF15_EID17      @ ((unsigned)&C1RXF15SID*8)+1;
static volatile bit           C1RXF15_EXIDE      @ ((unsigned)&C1RXF15SID*8)+3;
static volatile bit           C1RXF15_SID0       @ ((unsigned)&C1RXF15SID*8)+5;
static volatile bit           C1RXF15_SID1       @ ((unsigned)&C1RXF15SID*8)+6;
static volatile bit           C1RXF15_SID2       @ ((unsigned)&C1RXF15SID*8)+7;
static volatile bit           C1RXF15_SID3       @ ((unsigned)&C1RXF15SID*8)+8;
static volatile bit           C1RXF15_SID4       @ ((unsigned)&C1RXF15SID*8)+9;
static volatile bit           C1RXF15_SID5       @ ((unsigned)&C1RXF15SID*8)+10;
static volatile bit           C1RXF15_SID6       @ ((unsigned)&C1RXF15SID*8)+11;
static volatile bit           C1RXF15_SID7       @ ((unsigned)&C1RXF15SID*8)+12;
static volatile bit           C1RXF15_SID8       @ ((unsigned)&C1RXF15SID*8)+13;
static volatile bit           C1RXF15_SID9       @ ((unsigned)&C1RXF15SID*8)+14;
static volatile bit           C1RXF15_SID10      @ ((unsigned)&C1RXF15SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C1RXF15SIDbits @ 0x47C;

static volatile unsigned int  C1RXF15EID         @ 0x47E;
static volatile bit           C1RXF15_EID0       @ ((unsigned)&C1RXF15EID*8)+0;
static volatile bit           C1RXF15_EID1       @ ((unsigned)&C1RXF15EID*8)+1;
static volatile bit           C1RXF15_EID2       @ ((unsigned)&C1RXF15EID*8)+2;
static volatile bit           C1RXF15_EID3       @ ((unsigned)&C1RXF15EID*8)+3;
static volatile bit           C1RXF15_EID4       @ ((unsigned)&C1RXF15EID*8)+4;
static volatile bit           C1RXF15_EID5       @ ((unsigned)&C1RXF15EID*8)+5;
static volatile bit           C1RXF15_EID6       @ ((unsigned)&C1RXF15EID*8)+6;
static volatile bit           C1RXF15_EID7       @ ((unsigned)&C1RXF15EID*8)+7;
static volatile bit           C1RXF15_EID8       @ ((unsigned)&C1RXF15EID*8)+8;
static volatile bit           C1RXF15_EID9       @ ((unsigned)&C1RXF15EID*8)+9;
static volatile bit           C1RXF15_EID10      @ ((unsigned)&C1RXF15EID*8)+10;
static volatile bit           C1RXF15_EID11      @ ((unsigned)&C1RXF15EID*8)+11;
static volatile bit           C1RXF15_EID12      @ ((unsigned)&C1RXF15EID*8)+12;
static volatile bit           C1RXF15_EID13      @ ((unsigned)&C1RXF15EID*8)+13;
static volatile bit           C1RXF15_EID14      @ ((unsigned)&C1RXF15EID*8)+14;
static volatile bit           C1RXF15_EID15      @ ((unsigned)&C1RXF15EID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      EID15              : 1;
       volatile unsigned      EID14              : 1;
       volatile unsigned      EID13              : 1;
       volatile unsigned      EID12              : 1;
       volatile unsigned      EID11              : 1;
       volatile unsigned      EID10              : 1;
       volatile unsigned      EID9               : 1;
       volatile unsigned      EID8               : 1;
       volatile unsigned      EID7               : 1;
       volatile unsigned      EID6               : 1;
       volatile unsigned      EID5               : 1;
       volatile unsigned      EID4               : 1;
       volatile unsigned      EID3               : 1;
       volatile unsigned      EID2               : 1;
       volatile unsigned      EID1               : 1;
       volatile unsigned      EID0               : 1;
} C1RXF15EIDbits @ 0x47E;

static volatile unsigned int  C2CTRL1            @ 0x500;
static volatile bit           C2_WIN             @ ((unsigned)&C2CTRL1*8)+0;
static volatile bit           C2_CANCAP          @ ((unsigned)&C2CTRL1*8)+3;
static volatile bit           C2_OPMODE0         @ ((unsigned)&C2CTRL1*8)+5;
static volatile bit           C2_OPMODE1         @ ((unsigned)&C2CTRL1*8)+6;
static volatile bit           C2_OPMODE2         @ ((unsigned)&C2CTRL1*8)+7;
static volatile bit           C2_REQOP0          @ ((unsigned)&C2CTRL1*8)+8;
static volatile bit           C2_REQOP1          @ ((unsigned)&C2CTRL1*8)+9;
static volatile bit           C2_REQOP2          @ ((unsigned)&C2CTRL1*8)+10;
static volatile bit           C2_CANCKS          @ ((unsigned)&C2CTRL1*8)+11;
static volatile bit           C2_ABAT            @ ((unsigned)&C2CTRL1*8)+12;
static volatile bit           C2_CSIDL           @ ((unsigned)&C2CTRL1*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      CSIDL              : 1;
       volatile unsigned      ABAT               : 1;
       volatile unsigned      CANCKS             : 1;
       volatile unsigned      REQOP              : 3;
       volatile unsigned      OPMODE             : 3;
                unsigned                         : 1;
       volatile unsigned      CANCAP             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      WIN                : 1;
} C2CTRL1bits @ 0x500;

static volatile unsigned int  C2CTRL2            @ 0x502;
static volatile bit           C2_DNCNT0          @ ((unsigned)&C2CTRL2*8)+0;
static volatile bit           C2_DNCNT1          @ ((unsigned)&C2CTRL2*8)+1;
static volatile bit           C2_DNCNT2          @ ((unsigned)&C2CTRL2*8)+2;
static volatile bit           C2_DNCNT3          @ ((unsigned)&C2CTRL2*8)+3;
static volatile bit           C2_DNCNT4          @ ((unsigned)&C2CTRL2*8)+4;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      DNCNT              : 5;
} C2CTRL2bits @ 0x502;

static volatile unsigned int  C2VEC              @ 0x504;
static volatile bit           C2_ICODE0          @ ((unsigned)&C2VEC*8)+0;
static volatile bit           C2_ICODE1          @ ((unsigned)&C2VEC*8)+1;
static volatile bit           C2_ICODE2          @ ((unsigned)&C2VEC*8)+2;
static volatile bit           C2_ICODE3          @ ((unsigned)&C2VEC*8)+3;
static volatile bit           C2_ICODE4          @ ((unsigned)&C2VEC*8)+4;
static volatile bit           C2_ICODE5          @ ((unsigned)&C2VEC*8)+5;
static volatile bit           C2_ICODE6          @ ((unsigned)&C2VEC*8)+6;
static volatile bit           C2_FILHIT0         @ ((unsigned)&C2VEC*8)+8;
static volatile bit           C2_FILHIT1         @ ((unsigned)&C2VEC*8)+9;
static volatile bit           C2_FILHIT2         @ ((unsigned)&C2VEC*8)+10;
static volatile bit           C2_FILHIT3         @ ((unsigned)&C2VEC*8)+11;
static volatile bit           C2_FILHIT4         @ ((unsigned)&C2VEC*8)+12;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      FILHIT             : 5;
                unsigned                         : 1;
       volatile unsigned      ICODE              : 7;
} C2VECbits @ 0x504;

static volatile unsigned int  C2FCTRL            @ 0x506;
static volatile bit           C2_FSA0            @ ((unsigned)&C2FCTRL*8)+0;
static volatile bit           C2_FSA1            @ ((unsigned)&C2FCTRL*8)+1;
static volatile bit           C2_FSA2            @ ((unsigned)&C2FCTRL*8)+2;
static volatile bit           C2_FSA3            @ ((unsigned)&C2FCTRL*8)+3;
static volatile bit           C2_FSA4            @ ((unsigned)&C2FCTRL*8)+4;
static volatile bit           C2_DMABS0          @ ((unsigned)&C2FCTRL*8)+13;
static volatile bit           C2_DMABS1          @ ((unsigned)&C2FCTRL*8)+14;
static volatile bit           C2_DMABS2          @ ((unsigned)&C2FCTRL*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      DMABS              : 3;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      FSA                : 5;
} C2FCTRLbits @ 0x506;

static volatile unsigned int  C2FIFO             @ 0x508;
static volatile bit           C2_FNRB0           @ ((unsigned)&C2FIFO*8)+0;
static volatile bit           C2_FNRB1           @ ((unsigned)&C2FIFO*8)+1;
static volatile bit           C2_FNRB2           @ ((unsigned)&C2FIFO*8)+2;
static volatile bit           C2_FNRB3           @ ((unsigned)&C2FIFO*8)+3;
static volatile bit           C2_FNRB4           @ ((unsigned)&C2FIFO*8)+4;
static volatile bit           C2_FNRB5           @ ((unsigned)&C2FIFO*8)+5;
static volatile bit           C2_FBP0            @ ((unsigned)&C2FIFO*8)+8;
static volatile bit           C2_FBP1            @ ((unsigned)&C2FIFO*8)+9;
static volatile bit           C2_FBP2            @ ((unsigned)&C2FIFO*8)+10;
static volatile bit           C2_FBP3            @ ((unsigned)&C2FIFO*8)+11;
static volatile bit           C2_FBP4            @ ((unsigned)&C2FIFO*8)+12;
static volatile bit           C2_FBP5            @ ((unsigned)&C2FIFO*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      FBP                : 6;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      FNRB               : 6;
} C2FIFObits @ 0x508;

static volatile unsigned int  C2INTF             @ 0x50A;
static volatile bit           C2_TBIF            @ ((unsigned)&C2INTF*8)+0;
static volatile bit           C2_RBIF            @ ((unsigned)&C2INTF*8)+1;
static volatile bit           C2_RBOVIF          @ ((unsigned)&C2INTF*8)+2;
static volatile bit           C2_FIFOIF          @ ((unsigned)&C2INTF*8)+3;
static volatile bit           C2_ERRIF           @ ((unsigned)&C2INTF*8)+5;
static volatile bit           C2_WAKIF           @ ((unsigned)&C2INTF*8)+6;
static volatile bit           C2_IVRIF           @ ((unsigned)&C2INTF*8)+7;
static volatile bit           C2_EWARN           @ ((unsigned)&C2INTF*8)+8;
static volatile bit           C2_RXWAR           @ ((unsigned)&C2INTF*8)+9;
static volatile bit           C2_TXWAR           @ ((unsigned)&C2INTF*8)+10;
static volatile bit           C2_RXBP            @ ((unsigned)&C2INTF*8)+11;
static volatile bit           C2_TXBP            @ ((unsigned)&C2INTF*8)+12;
static volatile bit           C2_TXBO            @ ((unsigned)&C2INTF*8)+13;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      TXBO               : 1;
       volatile unsigned      TXBP               : 1;
       volatile unsigned      RXBP               : 1;
       volatile unsigned      TXWAR              : 1;
       volatile unsigned      RXWAR              : 1;
       volatile unsigned      EWARN              : 1;
       volatile unsigned      IVRIF              : 1;
       volatile unsigned      WAKIF              : 1;
       volatile unsigned      ERRIF              : 1;
                unsigned                         : 1;
       volatile unsigned      FIFOIF             : 1;
       volatile unsigned      RBOVIF             : 1;
       volatile unsigned      RBIF               : 1;
       volatile unsigned      TBIF               : 1;
} C2INTFbits @ 0x50A;

static volatile unsigned int  C2INTE             @ 0x50C;
static volatile bit           C2_TBIE            @ ((unsigned)&C2INTE*8)+0;
static volatile bit           C2_RBIE            @ ((unsigned)&C2INTE*8)+1;
static volatile bit           C2_RBOVIE          @ ((unsigned)&C2INTE*8)+2;
static volatile bit           C2_FIFOIE          @ ((unsigned)&C2INTE*8)+3;
static volatile bit           C2_ERRIE           @ ((unsigned)&C2INTE*8)+5;
static volatile bit           C2_WAKIE           @ ((unsigned)&C2INTE*8)+6;
static volatile bit           C2_IVRIE           @ ((unsigned)&C2INTE*8)+7;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      IVRIE              : 1;
       volatile unsigned      WAKIE              : 1;
       volatile unsigned      ERRIE              : 1;
       volatile unsigned                         : 1;
       volatile unsigned      FIFOIE             : 1;
       volatile unsigned      RBOVIE             : 1;
       volatile unsigned      RBIE               : 1;
       volatile unsigned      TBIE               : 1;
} C2INTEbits @ 0x50C;

static volatile unsigned int  C2EC               @ 0x50E;
static volatile bit           C2_RERRCNT0        @ ((unsigned)&C2EC*8)+0;
static volatile bit           C2_RERRCNT1        @ ((unsigned)&C2EC*8)+1;
static volatile bit           C2_RERRCNT2        @ ((unsigned)&C2EC*8)+2;
static volatile bit           C2_RERRCNT3        @ ((unsigned)&C2EC*8)+3;
static volatile bit           C2_RERRCNT4        @ ((unsigned)&C2EC*8)+4;
static volatile bit           C2_RERRCNT5        @ ((unsigned)&C2EC*8)+5;
static volatile bit           C2_RERRCNT6        @ ((unsigned)&C2EC*8)+6;
static volatile bit           C2_RERRCNT7        @ ((unsigned)&C2EC*8)+7;
static volatile bit           C2_TERRCNT0        @ ((unsigned)&C2EC*8)+8;
static volatile bit           C2_TERRCNT1        @ ((unsigned)&C2EC*8)+9;
static volatile bit           C2_TERRCNT2        @ ((unsigned)&C2EC*8)+10;
static volatile bit           C2_TERRCNT3        @ ((unsigned)&C2EC*8)+11;
static volatile bit           C2_TERRCNT4        @ ((unsigned)&C2EC*8)+12;
static volatile bit           C2_TERRCNT5        @ ((unsigned)&C2EC*8)+13;
static volatile bit           C2_TERRCNT6        @ ((unsigned)&C2EC*8)+14;
static volatile bit           C2_TERRCNT7        @ ((unsigned)&C2EC*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      TERRCNT            : 8;
       volatile unsigned      RERRCNT            : 8;
} C2ECbits @ 0x50E;

static volatile unsigned int  C2CFG1             @ 0x510;
static volatile bit           C2CFG1_BRP0        @ ((unsigned)&C2CFG1*8)+0;
static volatile bit           C2CFG1_BRP1        @ ((unsigned)&C2CFG1*8)+1;
static volatile bit           C2CFG1_BRP2        @ ((unsigned)&C2CFG1*8)+2;
static volatile bit           C2CFG1_BRP3        @ ((unsigned)&C2CFG1*8)+3;
static volatile bit           C2CFG1_BRP4        @ ((unsigned)&C2CFG1*8)+4;
static volatile bit           C2CFG1_BRP5        @ ((unsigned)&C2CFG1*8)+5;
static volatile bit           C2CFG1_SJW0        @ ((unsigned)&C2CFG1*8)+6;
static volatile bit           C2CFG1_SJW1        @ ((unsigned)&C2CFG1*8)+7;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      SJW                : 2;
       volatile unsigned      BRP                : 6;
} C2CFG1bits @ 0x510;

static volatile unsigned int  C2CFG2             @ 0x512;
static volatile bit           C2CFG2_PRSEG0      @ ((unsigned)&C2CFG2*8)+0;
static volatile bit           C2CFG2_PRSEG1      @ ((unsigned)&C2CFG2*8)+1;
static volatile bit           C2CFG2_PRSEG2      @ ((unsigned)&C2CFG2*8)+2;
static volatile bit           C2CFG2_SEG1PH0     @ ((unsigned)&C2CFG2*8)+3;
static volatile bit           C2CFG2_SEG1PH1     @ ((unsigned)&C2CFG2*8)+4;
static volatile bit           C2CFG2_SEG1PH2     @ ((unsigned)&C2CFG2*8)+5;
static volatile bit           C2CFG2_SAM         @ ((unsigned)&C2CFG2*8)+6;
static volatile bit           C2CFG2_SEG2PHTS    @ ((unsigned)&C2CFG2*8)+7;
static volatile bit           C2CFG2_SEG2PH0     @ ((unsigned)&C2CFG2*8)+8;
static volatile bit           C2CFG2_SEG2PH1     @ ((unsigned)&C2CFG2*8)+9;
static volatile bit           C2CFG2_SEG2PH2     @ ((unsigned)&C2CFG2*8)+10;
static volatile bit           C2CFG2_WAKFIL      @ ((unsigned)&C2CFG2*8)+14;
/* Microchip compatible bit field */
static volatile struct {
                unsigned                         : 1;
       volatile unsigned      WAKFIL             : 1;
                unsigned                         : 1;
                unsigned                         : 1;
                unsigned                         : 1;
       volatile unsigned      SEG2PH             : 3;
       volatile unsigned      SEG2PHTS           : 1;
       volatile unsigned      SAM                : 1;
       volatile unsigned      SEG1PH             : 3;
       volatile unsigned      PRSEG              : 3;
} C2CFG2bits @ 0x512;

static volatile unsigned int  C2FEN1             @ 0x514;
static volatile unsigned int  C2FMSKSEL1         @ 0x518;
static volatile bit           C2_F0MSK0          @ ((unsigned)&C2FMSKSEL1*8)+0;
static volatile bit           C2_F0MSK1          @ ((unsigned)&C2FMSKSEL1*8)+1;
static volatile bit           C2_F1MSK0          @ ((unsigned)&C2FMSKSEL1*8)+2;
static volatile bit           C2_F1MSK1          @ ((unsigned)&C2FMSKSEL1*8)+3;
static volatile bit           C2_F2MSK0          @ ((unsigned)&C2FMSKSEL1*8)+4;
static volatile bit           C2_F2MSK1          @ ((unsigned)&C2FMSKSEL1*8)+5;
static volatile bit           C2_F3MSK0          @ ((unsigned)&C2FMSKSEL1*8)+6;
static volatile bit           C2_F3MSK1          @ ((unsigned)&C2FMSKSEL1*8)+7;
static volatile bit           C2_F4MSK0          @ ((unsigned)&C2FMSKSEL1*8)+8;
static volatile bit           C2_F4MSK1          @ ((unsigned)&C2FMSKSEL1*8)+9;
static volatile bit           C2_F5MSK0          @ ((unsigned)&C2FMSKSEL1*8)+10;
static volatile bit           C2_F5MSK1          @ ((unsigned)&C2FMSKSEL1*8)+11;
static volatile bit           C2_F6MSK0          @ ((unsigned)&C2FMSKSEL1*8)+12;
static volatile bit           C2_F6MSK1          @ ((unsigned)&C2FMSKSEL1*8)+13;
static volatile bit           C2_F7MSK0          @ ((unsigned)&C2FMSKSEL1*8)+14;
static volatile bit           C2_F7MSK1          @ ((unsigned)&C2FMSKSEL1*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      F7MSK              : 2;
       volatile unsigned      F6MSK              : 2;
       volatile unsigned      F5MSK              : 2;
       volatile unsigned      F4MSK              : 2;
       volatile unsigned      F3MSK              : 2;
       volatile unsigned      F2MSK              : 2;
       volatile unsigned      F1MSK              : 2;
       volatile unsigned      F0MSK              : 2;
} C2FMSKSEL1bits @ 0x518;

static volatile unsigned int  C2FMSKSEL2         @ 0x51A;
static volatile bit           C2_F8MSK0          @ ((unsigned)&C2FMSKSEL2*8)+0;
static volatile bit           C2_F8MSK1          @ ((unsigned)&C2FMSKSEL2*8)+1;
static volatile bit           C2_F9MSK0          @ ((unsigned)&C2FMSKSEL2*8)+2;
static volatile bit           C2_F9MSK1          @ ((unsigned)&C2FMSKSEL2*8)+3;
static volatile bit           C2_F10MSK0         @ ((unsigned)&C2FMSKSEL2*8)+4;
static volatile bit           C2_F10MSK1         @ ((unsigned)&C2FMSKSEL2*8)+5;
static volatile bit           C2_F11MSK0         @ ((unsigned)&C2FMSKSEL2*8)+6;
static volatile bit           C2_F11MSK1         @ ((unsigned)&C2FMSKSEL2*8)+7;
static volatile bit           C2_F12MSK0         @ ((unsigned)&C2FMSKSEL2*8)+8;
static volatile bit           C2_F12MSK1         @ ((unsigned)&C2FMSKSEL2*8)+9;
static volatile bit           C2_F13MSK0         @ ((unsigned)&C2FMSKSEL2*8)+10;
static volatile bit           C2_F13MSK1         @ ((unsigned)&C2FMSKSEL2*8)+11;
static volatile bit           C2_F14MSK0         @ ((unsigned)&C2FMSKSEL2*8)+12;
static volatile bit           C2_F14MSK1         @ ((unsigned)&C2FMSKSEL2*8)+13;
static volatile bit           C2_F15MSK0         @ ((unsigned)&C2FMSKSEL2*8)+14;
static volatile bit           C2_F15MSK1         @ ((unsigned)&C2FMSKSEL2*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      F15MSK             : 2;
       volatile unsigned      F14MSK             : 2;
       volatile unsigned      F13MSK             : 2;
       volatile unsigned      F12MSK             : 2;
       volatile unsigned      F11MSK             : 2;
       volatile unsigned      F10MSK             : 2;
       volatile unsigned      F9MSK              : 2;
       volatile unsigned      F8MSK              : 2;
} C2FMSKSEL2bits @ 0x51A;

static volatile unsigned int  C2RXFUL1           @ 0x520;
static volatile unsigned int  C2RXFUL2           @ 0x522;
static volatile unsigned int  C2BUFPNT3          @ 0x524;
static volatile bit           C2_F8BP0           @ ((unsigned)&C2BUFPNT3*8)+0;
static volatile bit           C2_F8BP1           @ ((unsigned)&C2BUFPNT3*8)+1;
static volatile bit           C2_F8BP2           @ ((unsigned)&C2BUFPNT3*8)+2;
static volatile bit           C2_F8BP3           @ ((unsigned)&C2BUFPNT3*8)+3;
static volatile bit           C2_F9BP0           @ ((unsigned)&C2BUFPNT3*8)+4;
static volatile bit           C2_F9BP1           @ ((unsigned)&C2BUFPNT3*8)+5;
static volatile bit           C2_F9BP2           @ ((unsigned)&C2BUFPNT3*8)+6;
static volatile bit           C2_F9BP3           @ ((unsigned)&C2BUFPNT3*8)+7;
static volatile bit           C2_F10BP0          @ ((unsigned)&C2BUFPNT3*8)+8;
static volatile bit           C2_F10BP1          @ ((unsigned)&C2BUFPNT3*8)+9;
static volatile bit           C2_F10BP2          @ ((unsigned)&C2BUFPNT3*8)+10;
static volatile bit           C2_F10BP3          @ ((unsigned)&C2BUFPNT3*8)+11;
static volatile bit           C2_F11BP0          @ ((unsigned)&C2BUFPNT3*8)+12;
static volatile bit           C2_F11BP1          @ ((unsigned)&C2BUFPNT3*8)+13;
static volatile bit           C2_F11BP2          @ ((unsigned)&C2BUFPNT3*8)+14;
static volatile bit           C2_F11BP3          @ ((unsigned)&C2BUFPNT3*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      F11BP              : 4;
       volatile unsigned      F10BP              : 4;
       volatile unsigned      F9BP               : 4;
       volatile unsigned      F8BP               : 4;
} C2BUFPNT3bits @ 0x524;

static volatile unsigned int  C2BUFPNT4          @ 0x526;
static volatile bit           C2_F12BP0          @ ((unsigned)&C2BUFPNT4*8)+0;
static volatile bit           C2_F12BP1          @ ((unsigned)&C2BUFPNT4*8)+1;
static volatile bit           C2_F12BP2          @ ((unsigned)&C2BUFPNT4*8)+2;
static volatile bit           C2_F12BP3          @ ((unsigned)&C2BUFPNT4*8)+3;
static volatile bit           C2_F13BP0          @ ((unsigned)&C2BUFPNT4*8)+4;
static volatile bit           C2_F13BP1          @ ((unsigned)&C2BUFPNT4*8)+5;
static volatile bit           C2_F13BP2          @ ((unsigned)&C2BUFPNT4*8)+6;
static volatile bit           C2_F13BP3          @ ((unsigned)&C2BUFPNT4*8)+7;
static volatile bit           C2_F14BP0          @ ((unsigned)&C2BUFPNT4*8)+8;
static volatile bit           C2_F14BP1          @ ((unsigned)&C2BUFPNT4*8)+9;
static volatile bit           C2_F14BP2          @ ((unsigned)&C2BUFPNT4*8)+10;
static volatile bit           C2_F14BP3          @ ((unsigned)&C2BUFPNT4*8)+11;
static volatile bit           C2_F15BP0          @ ((unsigned)&C2BUFPNT4*8)+12;
static volatile bit           C2_F15BP1          @ ((unsigned)&C2BUFPNT4*8)+13;
static volatile bit           C2_F15BP2          @ ((unsigned)&C2BUFPNT4*8)+14;
static volatile bit           C2_F15BP3          @ ((unsigned)&C2BUFPNT4*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      F15BP              : 4;
       volatile unsigned      F14BP              : 4;
       volatile unsigned      F13BP              : 4;
       volatile unsigned      F12BP              : 4;
} C2BUFPNT4bits @ 0x526;

static volatile unsigned int  C2RXOVF1           @ 0x528;
static volatile unsigned int  C2RXOVF2           @ 0x52A;
static volatile unsigned int  C2TR01CON          @ 0x530;
static volatile bit           C2_TX0PRI0         @ ((unsigned)&C2TR01CON*8)+0;
static volatile bit           C2_TX0PRI1         @ ((unsigned)&C2TR01CON*8)+1;
static volatile bit           C2_RTREN0          @ ((unsigned)&C2TR01CON*8)+2;
static volatile bit           C2_TXREQ0          @ ((unsigned)&C2TR01CON*8)+3;
static volatile bit           C2_TXERR0          @ ((unsigned)&C2TR01CON*8)+4;
static volatile bit           C2_TXLARB0         @ ((unsigned)&C2TR01CON*8)+5;
static volatile bit           C2_TXABT0          @ ((unsigned)&C2TR01CON*8)+6;
static volatile bit           C2_TXEN0           @ ((unsigned)&C2TR01CON*8)+7;
static volatile bit           C2_TX1PRI0         @ ((unsigned)&C2TR01CON*8)+8;
static volatile bit           C2_TX1PRI1         @ ((unsigned)&C2TR01CON*8)+9;
static volatile bit           C2_RTREN1          @ ((unsigned)&C2TR01CON*8)+10;
static volatile bit           C2_TXREQ1          @ ((unsigned)&C2TR01CON*8)+11;
static volatile bit           C2_TXERR1          @ ((unsigned)&C2TR01CON*8)+12;
static volatile bit           C2_TXLARB1         @ ((unsigned)&C2TR01CON*8)+13;
static volatile bit           C2_TXABT1          @ ((unsigned)&C2TR01CON*8)+14;
static volatile bit           C2_TXEN1           @ ((unsigned)&C2TR01CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      TXEN1              : 1;
       volatile unsigned      TXABT1             : 1;
       volatile unsigned      TXLARB1            : 1;
       volatile unsigned      TXERR1             : 1;
       volatile unsigned      TXREQ1             : 1;
       volatile unsigned      RTREN1             : 1;
       volatile unsigned      TX1PRI             : 2;
       volatile unsigned      TXEN0              : 1;
       volatile unsigned      TXABT0             : 1;
       volatile unsigned      TXLARB0            : 1;
       volatile unsigned      TXERR0             : 1;
       volatile unsigned      TXREQ0             : 1;
       volatile unsigned      RTREN0             : 1;
       volatile unsigned      TX0PRI             : 2;
} C2TR01CONbits @ 0x530;

static volatile unsigned int  C2TR23CON          @ 0x532;
static volatile bit           C2_TX2PRI0         @ ((unsigned)&C2TR23CON*8)+0;
static volatile bit           C2_TX2PRI1         @ ((unsigned)&C2TR23CON*8)+1;
static volatile bit           C2_RTREN2          @ ((unsigned)&C2TR23CON*8)+2;
static volatile bit           C2_TXREQ2          @ ((unsigned)&C2TR23CON*8)+3;
static volatile bit           C2_TXERR2          @ ((unsigned)&C2TR23CON*8)+4;
static volatile bit           C2_TXLARB2         @ ((unsigned)&C2TR23CON*8)+5;
static volatile bit           C2_TXABT2          @ ((unsigned)&C2TR23CON*8)+6;
static volatile bit           C2_TXEN2           @ ((unsigned)&C2TR23CON*8)+7;
static volatile bit           C2_TX3PRI0         @ ((unsigned)&C2TR23CON*8)+8;
static volatile bit           C2_TX3PRI1         @ ((unsigned)&C2TR23CON*8)+9;
static volatile bit           C2_RTREN3          @ ((unsigned)&C2TR23CON*8)+10;
static volatile bit           C2_TXREQ3          @ ((unsigned)&C2TR23CON*8)+11;
static volatile bit           C2_TXERR3          @ ((unsigned)&C2TR23CON*8)+12;
static volatile bit           C2_TXLARB3         @ ((unsigned)&C2TR23CON*8)+13;
static volatile bit           C2_TXABT3          @ ((unsigned)&C2TR23CON*8)+14;
static volatile bit           C2_TXEN3           @ ((unsigned)&C2TR23CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      TXEN3              : 1;
       volatile unsigned      TXABT3             : 1;
       volatile unsigned      TXLARB3            : 1;
       volatile unsigned      TXERR3             : 1;
       volatile unsigned      TXREQ3             : 1;
       volatile unsigned      RTREN3             : 1;
       volatile unsigned      TX3PRI             : 2;
       volatile unsigned      TXEN2              : 1;
       volatile unsigned      TXABT2             : 1;
       volatile unsigned      TXLARB2            : 1;
       volatile unsigned      TXERR2             : 1;
       volatile unsigned      TXREQ2             : 1;
       volatile unsigned      RTREN2             : 1;
       volatile unsigned      TX2PRI             : 2;
} C2TR23CONbits @ 0x532;

static volatile unsigned int  C2TR45CON          @ 0x534;
static volatile bit           C2_TX4PRI0         @ ((unsigned)&C2TR45CON*8)+0;
static volatile bit           C2_TX4PRI1         @ ((unsigned)&C2TR45CON*8)+1;
static volatile bit           C2_RTREN4          @ ((unsigned)&C2TR45CON*8)+2;
static volatile bit           C2_TXREQ4          @ ((unsigned)&C2TR45CON*8)+3;
static volatile bit           C2_TXERR4          @ ((unsigned)&C2TR45CON*8)+4;
static volatile bit           C2_TXLARB4         @ ((unsigned)&C2TR45CON*8)+5;
static volatile bit           C2_TXABT4          @ ((unsigned)&C2TR45CON*8)+6;
static volatile bit           C2_TXEN4           @ ((unsigned)&C2TR45CON*8)+7;
static volatile bit           C2_TX5PRI0         @ ((unsigned)&C2TR45CON*8)+8;
static volatile bit           C2_TX5PRI1         @ ((unsigned)&C2TR45CON*8)+9;
static volatile bit           C2_RTREN5          @ ((unsigned)&C2TR45CON*8)+10;
static volatile bit           C2_TXREQ5          @ ((unsigned)&C2TR45CON*8)+11;
static volatile bit           C2_TXERR5          @ ((unsigned)&C2TR45CON*8)+12;
static volatile bit           C2_TXLARB5         @ ((unsigned)&C2TR45CON*8)+13;
static volatile bit           C2_TXABT5          @ ((unsigned)&C2TR45CON*8)+14;
static volatile bit           C2_TXEN5           @ ((unsigned)&C2TR45CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      TXEN5              : 1;
       volatile unsigned      TXABT5             : 1;
       volatile unsigned      TXLARB5            : 1;
       volatile unsigned      TXERR5             : 1;
       volatile unsigned      TXREQ5             : 1;
       volatile unsigned      RTREN5             : 1;
       volatile unsigned      TX5PRI             : 2;
       volatile unsigned      TXEN4              : 1;
       volatile unsigned      TXABT4             : 1;
       volatile unsigned      TXLARB4            : 1;
       volatile unsigned      TXERR4             : 1;
       volatile unsigned      TXREQ4             : 1;
       volatile unsigned      RTREN4             : 1;
       volatile unsigned      TX4PRI             : 2;
} C2TR45CONbits @ 0x534;

static volatile unsigned int  C2TR67CON          @ 0x536;
static volatile bit           C2_TX6PRI0         @ ((unsigned)&C2TR67CON*8)+0;
static volatile bit           C2_TX6PRI1         @ ((unsigned)&C2TR67CON*8)+1;
static volatile bit           C2_RTREN6          @ ((unsigned)&C2TR67CON*8)+2;
static volatile bit           C2_TXREQ6          @ ((unsigned)&C2TR67CON*8)+3;
static volatile bit           C2_TXERR6          @ ((unsigned)&C2TR67CON*8)+4;
static volatile bit           C2_TXLARB6         @ ((unsigned)&C2TR67CON*8)+5;
static volatile bit           C2_TXABT6          @ ((unsigned)&C2TR67CON*8)+6;
static volatile bit           C2_TXEN6           @ ((unsigned)&C2TR67CON*8)+7;
static volatile bit           C2_TX7PRI0         @ ((unsigned)&C2TR67CON*8)+8;
static volatile bit           C2_TX7PRI1         @ ((unsigned)&C2TR67CON*8)+9;
static volatile bit           C2_RTREN7          @ ((unsigned)&C2TR67CON*8)+10;
static volatile bit           C2_TXREQ7          @ ((unsigned)&C2TR67CON*8)+11;
static volatile bit           C2_TXERR7          @ ((unsigned)&C2TR67CON*8)+12;
static volatile bit           C2_TXLARB7         @ ((unsigned)&C2TR67CON*8)+13;
static volatile bit           C2_TXABT7          @ ((unsigned)&C2TR67CON*8)+14;
static volatile bit           C2_TXEN7           @ ((unsigned)&C2TR67CON*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      TXEN7              : 1;
       volatile unsigned      TXABT7             : 1;
       volatile unsigned      TXLARB7            : 1;
       volatile unsigned      TXERR7             : 1;
       volatile unsigned      TXREQ7             : 1;
       volatile unsigned      RTREN7             : 1;
       volatile unsigned      TX7PRI             : 2;
       volatile unsigned      TXEN6              : 1;
       volatile unsigned      TXABT6             : 1;
       volatile unsigned      TXLARB6            : 1;
       volatile unsigned      TXERR6             : 1;
       volatile unsigned      TXREQ6             : 1;
       volatile unsigned      RTREN6             : 1;
       volatile unsigned      TX6PRI             : 2;
} C2TR67CONbits @ 0x536;

static volatile unsigned int  C2RXM2SID          @ 0x538;
static volatile bit           C2RXM2_EID16       @ ((unsigned)&C2RXM2SID*8)+0;
static volatile bit           C2RXM2_EID17       @ ((unsigned)&C2RXM2SID*8)+1;
static volatile bit           C2RXM2_MIDE        @ ((unsigned)&C2RXM2SID*8)+3;
static volatile bit           C2RXM2_SID0        @ ((unsigned)&C2RXM2SID*8)+5;
static volatile bit           C2RXM2_SID1        @ ((unsigned)&C2RXM2SID*8)+6;
static volatile bit           C2RXM2_SID2        @ ((unsigned)&C2RXM2SID*8)+7;
static volatile bit           C2RXM2_SID3        @ ((unsigned)&C2RXM2SID*8)+8;
static volatile bit           C2RXM2_SID4        @ ((unsigned)&C2RXM2SID*8)+9;
static volatile bit           C2RXM2_SID5        @ ((unsigned)&C2RXM2SID*8)+10;
static volatile bit           C2RXM2_SID6        @ ((unsigned)&C2RXM2SID*8)+11;
static volatile bit           C2RXM2_SID7        @ ((unsigned)&C2RXM2SID*8)+12;
static volatile bit           C2RXM2_SID8        @ ((unsigned)&C2RXM2SID*8)+13;
static volatile bit           C2RXM2_SID9        @ ((unsigned)&C2RXM2SID*8)+14;
static volatile bit           C2RXM2_SID10       @ ((unsigned)&C2RXM2SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      MIDE               : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C2RXM2SIDbits @ 0x538;

static volatile unsigned int  C2RXM2EID          @ 0x53A;
static volatile unsigned int  C2RXF0SID          @ 0x540;
static volatile bit           C2RXF0_EID16       @ ((unsigned)&C2RXF0SID*8)+0;
static volatile bit           C2RXF0_EID17       @ ((unsigned)&C2RXF0SID*8)+1;
static volatile bit           C2RXF0_EXIDE       @ ((unsigned)&C2RXF0SID*8)+3;
static volatile bit           C2RXF0_SID0        @ ((unsigned)&C2RXF0SID*8)+5;
static volatile bit           C2RXF0_SID1        @ ((unsigned)&C2RXF0SID*8)+6;
static volatile bit           C2RXF0_SID2        @ ((unsigned)&C2RXF0SID*8)+7;
static volatile bit           C2RXF0_SID3        @ ((unsigned)&C2RXF0SID*8)+8;
static volatile bit           C2RXF0_SID4        @ ((unsigned)&C2RXF0SID*8)+9;
static volatile bit           C2RXF0_SID5        @ ((unsigned)&C2RXF0SID*8)+10;
static volatile bit           C2RXF0_SID6        @ ((unsigned)&C2RXF0SID*8)+11;
static volatile bit           C2RXF0_SID7        @ ((unsigned)&C2RXF0SID*8)+12;
static volatile bit           C2RXF0_SID8        @ ((unsigned)&C2RXF0SID*8)+13;
static volatile bit           C2RXF0_SID9        @ ((unsigned)&C2RXF0SID*8)+14;
static volatile bit           C2RXF0_SID10       @ ((unsigned)&C2RXF0SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C2RXF0SIDbits @ 0x540;

static volatile unsigned int  C2RXF0EID          @ 0x542;
static volatile unsigned int  C2RXF1SID          @ 0x544;
static volatile bit           C2RXF1_EID16       @ ((unsigned)&C2RXF1SID*8)+0;
static volatile bit           C2RXF1_EID17       @ ((unsigned)&C2RXF1SID*8)+1;
static volatile bit           C2RXF1_EXIDE       @ ((unsigned)&C2RXF1SID*8)+3;
static volatile bit           C2RXF1_SID0        @ ((unsigned)&C2RXF1SID*8)+5;
static volatile bit           C2RXF1_SID1        @ ((unsigned)&C2RXF1SID*8)+6;
static volatile bit           C2RXF1_SID2        @ ((unsigned)&C2RXF1SID*8)+7;
static volatile bit           C2RXF1_SID3        @ ((unsigned)&C2RXF1SID*8)+8;
static volatile bit           C2RXF1_SID4        @ ((unsigned)&C2RXF1SID*8)+9;
static volatile bit           C2RXF1_SID5        @ ((unsigned)&C2RXF1SID*8)+10;
static volatile bit           C2RXF1_SID6        @ ((unsigned)&C2RXF1SID*8)+11;
static volatile bit           C2RXF1_SID7        @ ((unsigned)&C2RXF1SID*8)+12;
static volatile bit           C2RXF1_SID8        @ ((unsigned)&C2RXF1SID*8)+13;
static volatile bit           C2RXF1_SID9        @ ((unsigned)&C2RXF1SID*8)+14;
static volatile bit           C2RXF1_SID10       @ ((unsigned)&C2RXF1SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C2RXF1SIDbits @ 0x544;

static volatile unsigned int  C2RXF1EID          @ 0x546;
static volatile unsigned int  C2RXF2SID          @ 0x548;
static volatile bit           C2RXF2_EID16       @ ((unsigned)&C2RXF2SID*8)+0;
static volatile bit           C2RXF2_EID17       @ ((unsigned)&C2RXF2SID*8)+1;
static volatile bit           C2RXF2_EXIDE       @ ((unsigned)&C2RXF2SID*8)+3;
static volatile bit           C2RXF2_SID0        @ ((unsigned)&C2RXF2SID*8)+5;
static volatile bit           C2RXF2_SID1        @ ((unsigned)&C2RXF2SID*8)+6;
static volatile bit           C2RXF2_SID2        @ ((unsigned)&C2RXF2SID*8)+7;
static volatile bit           C2RXF2_SID3        @ ((unsigned)&C2RXF2SID*8)+8;
static volatile bit           C2RXF2_SID4        @ ((unsigned)&C2RXF2SID*8)+9;
static volatile bit           C2RXF2_SID5        @ ((unsigned)&C2RXF2SID*8)+10;
static volatile bit           C2RXF2_SID6        @ ((unsigned)&C2RXF2SID*8)+11;
static volatile bit           C2RXF2_SID7        @ ((unsigned)&C2RXF2SID*8)+12;
static volatile bit           C2RXF2_SID8        @ ((unsigned)&C2RXF2SID*8)+13;
static volatile bit           C2RXF2_SID9        @ ((unsigned)&C2RXF2SID*8)+14;
static volatile bit           C2RXF2_SID10       @ ((unsigned)&C2RXF2SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C2RXF2SIDbits @ 0x548;

static volatile unsigned int  C2RXF2EID          @ 0x54A;
static volatile unsigned int  C2RXF3SID          @ 0x54C;
static volatile bit           C2RXF3_EID16       @ ((unsigned)&C2RXF3SID*8)+0;
static volatile bit           C2RXF3_EID17       @ ((unsigned)&C2RXF3SID*8)+1;
static volatile bit           C2RXF3_EXIDE       @ ((unsigned)&C2RXF3SID*8)+3;
static volatile bit           C2RXF3_SID0        @ ((unsigned)&C2RXF3SID*8)+5;
static volatile bit           C2RXF3_SID1        @ ((unsigned)&C2RXF3SID*8)+6;
static volatile bit           C2RXF3_SID2        @ ((unsigned)&C2RXF3SID*8)+7;
static volatile bit           C2RXF3_SID3        @ ((unsigned)&C2RXF3SID*8)+8;
static volatile bit           C2RXF3_SID4        @ ((unsigned)&C2RXF3SID*8)+9;
static volatile bit           C2RXF3_SID5        @ ((unsigned)&C2RXF3SID*8)+10;
static volatile bit           C2RXF3_SID6        @ ((unsigned)&C2RXF3SID*8)+11;
static volatile bit           C2RXF3_SID7        @ ((unsigned)&C2RXF3SID*8)+12;
static volatile bit           C2RXF3_SID8        @ ((unsigned)&C2RXF3SID*8)+13;
static volatile bit           C2RXF3_SID9        @ ((unsigned)&C2RXF3SID*8)+14;
static volatile bit           C2RXF3_SID10       @ ((unsigned)&C2RXF3SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C2RXF3SIDbits @ 0x54C;

static volatile unsigned int  C2RXF3EID          @ 0x54E;
static volatile unsigned int  C2RXF4SID          @ 0x550;
static volatile bit           C2RXF4_EID16       @ ((unsigned)&C2RXF4SID*8)+0;
static volatile bit           C2RXF4_EID17       @ ((unsigned)&C2RXF4SID*8)+1;
static volatile bit           C2RXF4_EXIDE       @ ((unsigned)&C2RXF4SID*8)+3;
static volatile bit           C2RXF4_SID0        @ ((unsigned)&C2RXF4SID*8)+5;
static volatile bit           C2RXF4_SID1        @ ((unsigned)&C2RXF4SID*8)+6;
static volatile bit           C2RXF4_SID2        @ ((unsigned)&C2RXF4SID*8)+7;
static volatile bit           C2RXF4_SID3        @ ((unsigned)&C2RXF4SID*8)+8;
static volatile bit           C2RXF4_SID4        @ ((unsigned)&C2RXF4SID*8)+9;
static volatile bit           C2RXF4_SID5        @ ((unsigned)&C2RXF4SID*8)+10;
static volatile bit           C2RXF4_SID6        @ ((unsigned)&C2RXF4SID*8)+11;
static volatile bit           C2RXF4_SID7        @ ((unsigned)&C2RXF4SID*8)+12;
static volatile bit           C2RXF4_SID8        @ ((unsigned)&C2RXF4SID*8)+13;
static volatile bit           C2RXF4_SID9        @ ((unsigned)&C2RXF4SID*8)+14;
static volatile bit           C2RXF4_SID10       @ ((unsigned)&C2RXF4SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C2RXF4SIDbits @ 0x550;

static volatile unsigned int  C2RXF4EID          @ 0x552;
static volatile unsigned int  C2RXF5SID          @ 0x554;
static volatile bit           C2RXF5_EID16       @ ((unsigned)&C2RXF5SID*8)+0;
static volatile bit           C2RXF5_EID17       @ ((unsigned)&C2RXF5SID*8)+1;
static volatile bit           C2RXF5_EXIDE       @ ((unsigned)&C2RXF5SID*8)+3;
static volatile bit           C2RXF5_SID0        @ ((unsigned)&C2RXF5SID*8)+5;
static volatile bit           C2RXF5_SID1        @ ((unsigned)&C2RXF5SID*8)+6;
static volatile bit           C2RXF5_SID2        @ ((unsigned)&C2RXF5SID*8)+7;
static volatile bit           C2RXF5_SID3        @ ((unsigned)&C2RXF5SID*8)+8;
static volatile bit           C2RXF5_SID4        @ ((unsigned)&C2RXF5SID*8)+9;
static volatile bit           C2RXF5_SID5        @ ((unsigned)&C2RXF5SID*8)+10;
static volatile bit           C2RXF5_SID6        @ ((unsigned)&C2RXF5SID*8)+11;
static volatile bit           C2RXF5_SID7        @ ((unsigned)&C2RXF5SID*8)+12;
static volatile bit           C2RXF5_SID8        @ ((unsigned)&C2RXF5SID*8)+13;
static volatile bit           C2RXF5_SID9        @ ((unsigned)&C2RXF5SID*8)+14;
static volatile bit           C2RXF5_SID10       @ ((unsigned)&C2RXF5SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C2RXF5SIDbits @ 0x554;

static volatile unsigned int  C2RXF5EID          @ 0x556;
static volatile unsigned int  C2RXF6SID          @ 0x558;
static volatile bit           C2RXF6_EID16       @ ((unsigned)&C2RXF6SID*8)+0;
static volatile bit           C2RXF6_EID17       @ ((unsigned)&C2RXF6SID*8)+1;
static volatile bit           C2RXF6_EXIDE       @ ((unsigned)&C2RXF6SID*8)+3;
static volatile bit           C2RXF6_SID0        @ ((unsigned)&C2RXF6SID*8)+5;
static volatile bit           C2RXF6_SID1        @ ((unsigned)&C2RXF6SID*8)+6;
static volatile bit           C2RXF6_SID2        @ ((unsigned)&C2RXF6SID*8)+7;
static volatile bit           C2RXF6_SID3        @ ((unsigned)&C2RXF6SID*8)+8;
static volatile bit           C2RXF6_SID4        @ ((unsigned)&C2RXF6SID*8)+9;
static volatile bit           C2RXF6_SID5        @ ((unsigned)&C2RXF6SID*8)+10;
static volatile bit           C2RXF6_SID6        @ ((unsigned)&C2RXF6SID*8)+11;
static volatile bit           C2RXF6_SID7        @ ((unsigned)&C2RXF6SID*8)+12;
static volatile bit           C2RXF6_SID8        @ ((unsigned)&C2RXF6SID*8)+13;
static volatile bit           C2RXF6_SID9        @ ((unsigned)&C2RXF6SID*8)+14;
static volatile bit           C2RXF6_SID10       @ ((unsigned)&C2RXF6SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C2RXF6SIDbits @ 0x558;

static volatile unsigned int  C2RXF6EID          @ 0x55A;
static volatile unsigned int  C2RXF7SID          @ 0x55C;
static volatile bit           C2RXF7_EID16       @ ((unsigned)&C2RXF7SID*8)+0;
static volatile bit           C2RXF7_EID17       @ ((unsigned)&C2RXF7SID*8)+1;
static volatile bit           C2RXF7_EXIDE       @ ((unsigned)&C2RXF7SID*8)+3;
static volatile bit           C2RXF7_SID0        @ ((unsigned)&C2RXF7SID*8)+5;
static volatile bit           C2RXF7_SID1        @ ((unsigned)&C2RXF7SID*8)+6;
static volatile bit           C2RXF7_SID2        @ ((unsigned)&C2RXF7SID*8)+7;
static volatile bit           C2RXF7_SID3        @ ((unsigned)&C2RXF7SID*8)+8;
static volatile bit           C2RXF7_SID4        @ ((unsigned)&C2RXF7SID*8)+9;
static volatile bit           C2RXF7_SID5        @ ((unsigned)&C2RXF7SID*8)+10;
static volatile bit           C2RXF7_SID6        @ ((unsigned)&C2RXF7SID*8)+11;
static volatile bit           C2RXF7_SID7        @ ((unsigned)&C2RXF7SID*8)+12;
static volatile bit           C2RXF7_SID8        @ ((unsigned)&C2RXF7SID*8)+13;
static volatile bit           C2RXF7_SID9        @ ((unsigned)&C2RXF7SID*8)+14;
static volatile bit           C2RXF7_SID10       @ ((unsigned)&C2RXF7SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C2RXF7SIDbits @ 0x55C;

static volatile unsigned int  C2RXF7EID          @ 0x55E;
static volatile unsigned int  C2RXF8SID          @ 0x560;
static volatile bit           C2RXF8_EID16       @ ((unsigned)&C2RXF8SID*8)+0;
static volatile bit           C2RXF8_EID17       @ ((unsigned)&C2RXF8SID*8)+1;
static volatile bit           C2RXF8_EXIDE       @ ((unsigned)&C2RXF8SID*8)+3;
static volatile bit           C2RXF8_SID0        @ ((unsigned)&C2RXF8SID*8)+5;
static volatile bit           C2RXF8_SID1        @ ((unsigned)&C2RXF8SID*8)+6;
static volatile bit           C2RXF8_SID2        @ ((unsigned)&C2RXF8SID*8)+7;
static volatile bit           C2RXF8_SID3        @ ((unsigned)&C2RXF8SID*8)+8;
static volatile bit           C2RXF8_SID4        @ ((unsigned)&C2RXF8SID*8)+9;
static volatile bit           C2RXF8_SID5        @ ((unsigned)&C2RXF8SID*8)+10;
static volatile bit           C2RXF8_SID6        @ ((unsigned)&C2RXF8SID*8)+11;
static volatile bit           C2RXF8_SID7        @ ((unsigned)&C2RXF8SID*8)+12;
static volatile bit           C2RXF8_SID8        @ ((unsigned)&C2RXF8SID*8)+13;
static volatile bit           C2RXF8_SID9        @ ((unsigned)&C2RXF8SID*8)+14;
static volatile bit           C2RXF8_SID10       @ ((unsigned)&C2RXF8SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C2RXF8SIDbits @ 0x560;

static volatile unsigned int  C2RXF8EID          @ 0x562;
static volatile unsigned int  C2RXF9SID          @ 0x564;
static volatile bit           C2RXF9_EID16       @ ((unsigned)&C2RXF9SID*8)+0;
static volatile bit           C2RXF9_EID17       @ ((unsigned)&C2RXF9SID*8)+1;
static volatile bit           C2RXF9_EXIDE       @ ((unsigned)&C2RXF9SID*8)+3;
static volatile bit           C2RXF9_SID0        @ ((unsigned)&C2RXF9SID*8)+5;
static volatile bit           C2RXF9_SID1        @ ((unsigned)&C2RXF9SID*8)+6;
static volatile bit           C2RXF9_SID2        @ ((unsigned)&C2RXF9SID*8)+7;
static volatile bit           C2RXF9_SID3        @ ((unsigned)&C2RXF9SID*8)+8;
static volatile bit           C2RXF9_SID4        @ ((unsigned)&C2RXF9SID*8)+9;
static volatile bit           C2RXF9_SID5        @ ((unsigned)&C2RXF9SID*8)+10;
static volatile bit           C2RXF9_SID6        @ ((unsigned)&C2RXF9SID*8)+11;
static volatile bit           C2RXF9_SID7        @ ((unsigned)&C2RXF9SID*8)+12;
static volatile bit           C2RXF9_SID8        @ ((unsigned)&C2RXF9SID*8)+13;
static volatile bit           C2RXF9_SID9        @ ((unsigned)&C2RXF9SID*8)+14;
static volatile bit           C2RXF9_SID10       @ ((unsigned)&C2RXF9SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C2RXF9SIDbits @ 0x564;

static volatile unsigned int  C2RXF9EID          @ 0x566;
static volatile unsigned int  C2RXF10SID         @ 0x568;
static volatile bit           C2RXF10_EID16      @ ((unsigned)&C2RXF10SID*8)+0;
static volatile bit           C2RXF10_EID17      @ ((unsigned)&C2RXF10SID*8)+1;
static volatile bit           C2RXF10_EXIDE      @ ((unsigned)&C2RXF10SID*8)+3;
static volatile bit           C2RXF10_SID0       @ ((unsigned)&C2RXF10SID*8)+5;
static volatile bit           C2RXF10_SID1       @ ((unsigned)&C2RXF10SID*8)+6;
static volatile bit           C2RXF10_SID2       @ ((unsigned)&C2RXF10SID*8)+7;
static volatile bit           C2RXF10_SID3       @ ((unsigned)&C2RXF10SID*8)+8;
static volatile bit           C2RXF10_SID4       @ ((unsigned)&C2RXF10SID*8)+9;
static volatile bit           C2RXF10_SID5       @ ((unsigned)&C2RXF10SID*8)+10;
static volatile bit           C2RXF10_SID6       @ ((unsigned)&C2RXF10SID*8)+11;
static volatile bit           C2RXF10_SID7       @ ((unsigned)&C2RXF10SID*8)+12;
static volatile bit           C2RXF10_SID8       @ ((unsigned)&C2RXF10SID*8)+13;
static volatile bit           C2RXF10_SID9       @ ((unsigned)&C2RXF10SID*8)+14;
static volatile bit           C2RXF10_SID10      @ ((unsigned)&C2RXF10SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C2RXF10SIDbits @ 0x568;

static volatile unsigned int  C2RXF10EID         @ 0x56A;
static volatile bit           C2RXF10_EID0       @ ((unsigned)&C2RXF10EID*8)+0;
static volatile bit           C2RXF10_EID1       @ ((unsigned)&C2RXF10EID*8)+1;
static volatile bit           C2RXF10_EID2       @ ((unsigned)&C2RXF10EID*8)+2;
static volatile bit           C2RXF10_EID3       @ ((unsigned)&C2RXF10EID*8)+3;
static volatile bit           C2RXF10_EID4       @ ((unsigned)&C2RXF10EID*8)+4;
static volatile bit           C2RXF10_EID5       @ ((unsigned)&C2RXF10EID*8)+5;
static volatile bit           C2RXF10_EID6       @ ((unsigned)&C2RXF10EID*8)+6;
static volatile bit           C2RXF10_EID7       @ ((unsigned)&C2RXF10EID*8)+7;
static volatile bit           C2RXF10_EID8       @ ((unsigned)&C2RXF10EID*8)+8;
static volatile bit           C2RXF10_EID9       @ ((unsigned)&C2RXF10EID*8)+9;
static volatile bit           C2RXF10_EID10      @ ((unsigned)&C2RXF10EID*8)+10;
static volatile bit           C2RXF10_EID11      @ ((unsigned)&C2RXF10EID*8)+11;
static volatile bit           C2RXF10_EID12      @ ((unsigned)&C2RXF10EID*8)+12;
static volatile bit           C2RXF10_EID13      @ ((unsigned)&C2RXF10EID*8)+13;
static volatile bit           C2RXF10_EID14      @ ((unsigned)&C2RXF10EID*8)+14;
static volatile bit           C2RXF10_EID15      @ ((unsigned)&C2RXF10EID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      EID15              : 1;
       volatile unsigned      EID14              : 1;
       volatile unsigned      EID13              : 1;
       volatile unsigned      EID12              : 1;
       volatile unsigned      EID11              : 1;
       volatile unsigned      EID10              : 1;
       volatile unsigned      EID9               : 1;
       volatile unsigned      EID8               : 1;
       volatile unsigned      EID7               : 1;
       volatile unsigned      EID6               : 1;
       volatile unsigned      EID5               : 1;
       volatile unsigned      EID4               : 1;
       volatile unsigned      EID3               : 1;
       volatile unsigned      EID2               : 1;
       volatile unsigned      EID1               : 1;
       volatile unsigned      EID0               : 1;
} C2RXF10EIDbits @ 0x56A;

static volatile unsigned int  C2RXF11SID         @ 0x56C;
static volatile bit           C2RXF11_EID16      @ ((unsigned)&C2RXF11SID*8)+0;
static volatile bit           C2RXF11_EID17      @ ((unsigned)&C2RXF11SID*8)+1;
static volatile bit           C2RXF11_EXIDE      @ ((unsigned)&C2RXF11SID*8)+3;
static volatile bit           C2RXF11_SID0       @ ((unsigned)&C2RXF11SID*8)+5;
static volatile bit           C2RXF11_SID1       @ ((unsigned)&C2RXF11SID*8)+6;
static volatile bit           C2RXF11_SID2       @ ((unsigned)&C2RXF11SID*8)+7;
static volatile bit           C2RXF11_SID3       @ ((unsigned)&C2RXF11SID*8)+8;
static volatile bit           C2RXF11_SID4       @ ((unsigned)&C2RXF11SID*8)+9;
static volatile bit           C2RXF11_SID5       @ ((unsigned)&C2RXF11SID*8)+10;
static volatile bit           C2RXF11_SID6       @ ((unsigned)&C2RXF11SID*8)+11;
static volatile bit           C2RXF11_SID7       @ ((unsigned)&C2RXF11SID*8)+12;
static volatile bit           C2RXF11_SID8       @ ((unsigned)&C2RXF11SID*8)+13;
static volatile bit           C2RXF11_SID9       @ ((unsigned)&C2RXF11SID*8)+14;
static volatile bit           C2RXF11_SID10      @ ((unsigned)&C2RXF11SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C2RXF11SIDbits @ 0x56C;

static volatile unsigned int  C2RXF11EID         @ 0x56E;
static volatile bit           C2RXF11_EID0       @ ((unsigned)&C2RXF11EID*8)+0;
static volatile bit           C2RXF11_EID1       @ ((unsigned)&C2RXF11EID*8)+1;
static volatile bit           C2RXF11_EID2       @ ((unsigned)&C2RXF11EID*8)+2;
static volatile bit           C2RXF11_EID3       @ ((unsigned)&C2RXF11EID*8)+3;
static volatile bit           C2RXF11_EID4       @ ((unsigned)&C2RXF11EID*8)+4;
static volatile bit           C2RXF11_EID5       @ ((unsigned)&C2RXF11EID*8)+5;
static volatile bit           C2RXF11_EID6       @ ((unsigned)&C2RXF11EID*8)+6;
static volatile bit           C2RXF11_EID7       @ ((unsigned)&C2RXF11EID*8)+7;
static volatile bit           C2RXF11_EID8       @ ((unsigned)&C2RXF11EID*8)+8;
static volatile bit           C2RXF11_EID9       @ ((unsigned)&C2RXF11EID*8)+9;
static volatile bit           C2RXF11_EID10      @ ((unsigned)&C2RXF11EID*8)+10;
static volatile bit           C2RXF11_EID11      @ ((unsigned)&C2RXF11EID*8)+11;
static volatile bit           C2RXF11_EID12      @ ((unsigned)&C2RXF11EID*8)+12;
static volatile bit           C2RXF11_EID13      @ ((unsigned)&C2RXF11EID*8)+13;
static volatile bit           C2RXF11_EID14      @ ((unsigned)&C2RXF11EID*8)+14;
static volatile bit           C2RXF11_EID15      @ ((unsigned)&C2RXF11EID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      EID15              : 1;
       volatile unsigned      EID14              : 1;
       volatile unsigned      EID13              : 1;
       volatile unsigned      EID12              : 1;
       volatile unsigned      EID11              : 1;
       volatile unsigned      EID10              : 1;
       volatile unsigned      EID9               : 1;
       volatile unsigned      EID8               : 1;
       volatile unsigned      EID7               : 1;
       volatile unsigned      EID6               : 1;
       volatile unsigned      EID5               : 1;
       volatile unsigned      EID4               : 1;
       volatile unsigned      EID3               : 1;
       volatile unsigned      EID2               : 1;
       volatile unsigned      EID1               : 1;
       volatile unsigned      EID0               : 1;
} C2RXF11EIDbits @ 0x56E;

static volatile unsigned int  C2RXF12SID         @ 0x570;
static volatile bit           C2RXF12_EID16      @ ((unsigned)&C2RXF12SID*8)+0;
static volatile bit           C2RXF12_EID17      @ ((unsigned)&C2RXF12SID*8)+1;
static volatile bit           C2RXF12_EXIDE      @ ((unsigned)&C2RXF12SID*8)+3;
static volatile bit           C2RXF12_SID0       @ ((unsigned)&C2RXF12SID*8)+5;
static volatile bit           C2RXF12_SID1       @ ((unsigned)&C2RXF12SID*8)+6;
static volatile bit           C2RXF12_SID2       @ ((unsigned)&C2RXF12SID*8)+7;
static volatile bit           C2RXF12_SID3       @ ((unsigned)&C2RXF12SID*8)+8;
static volatile bit           C2RXF12_SID4       @ ((unsigned)&C2RXF12SID*8)+9;
static volatile bit           C2RXF12_SID5       @ ((unsigned)&C2RXF12SID*8)+10;
static volatile bit           C2RXF12_SID6       @ ((unsigned)&C2RXF12SID*8)+11;
static volatile bit           C2RXF12_SID7       @ ((unsigned)&C2RXF12SID*8)+12;
static volatile bit           C2RXF12_SID8       @ ((unsigned)&C2RXF12SID*8)+13;
static volatile bit           C2RXF12_SID9       @ ((unsigned)&C2RXF12SID*8)+14;
static volatile bit           C2RXF12_SID10      @ ((unsigned)&C2RXF12SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C2RXF12SIDbits @ 0x570;

static volatile unsigned int  C2RXF12EID         @ 0x572;
static volatile bit           C2RXF12_EID0       @ ((unsigned)&C2RXF12EID*8)+0;
static volatile bit           C2RXF12_EID1       @ ((unsigned)&C2RXF12EID*8)+1;
static volatile bit           C2RXF12_EID2       @ ((unsigned)&C2RXF12EID*8)+2;
static volatile bit           C2RXF12_EID3       @ ((unsigned)&C2RXF12EID*8)+3;
static volatile bit           C2RXF12_EID4       @ ((unsigned)&C2RXF12EID*8)+4;
static volatile bit           C2RXF12_EID5       @ ((unsigned)&C2RXF12EID*8)+5;
static volatile bit           C2RXF12_EID6       @ ((unsigned)&C2RXF12EID*8)+6;
static volatile bit           C2RXF12_EID7       @ ((unsigned)&C2RXF12EID*8)+7;
static volatile bit           C2RXF12_EID8       @ ((unsigned)&C2RXF12EID*8)+8;
static volatile bit           C2RXF12_EID9       @ ((unsigned)&C2RXF12EID*8)+9;
static volatile bit           C2RXF12_EID10      @ ((unsigned)&C2RXF12EID*8)+10;
static volatile bit           C2RXF12_EID11      @ ((unsigned)&C2RXF12EID*8)+11;
static volatile bit           C2RXF12_EID12      @ ((unsigned)&C2RXF12EID*8)+12;
static volatile bit           C2RXF12_EID13      @ ((unsigned)&C2RXF12EID*8)+13;
static volatile bit           C2RXF12_EID14      @ ((unsigned)&C2RXF12EID*8)+14;
static volatile bit           C2RXF12_EID15      @ ((unsigned)&C2RXF12EID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      EID15              : 1;
       volatile unsigned      EID14              : 1;
       volatile unsigned      EID13              : 1;
       volatile unsigned      EID12              : 1;
       volatile unsigned      EID11              : 1;
       volatile unsigned      EID10              : 1;
       volatile unsigned      EID9               : 1;
       volatile unsigned      EID8               : 1;
       volatile unsigned      EID7               : 1;
       volatile unsigned      EID6               : 1;
       volatile unsigned      EID5               : 1;
       volatile unsigned      EID4               : 1;
       volatile unsigned      EID3               : 1;
       volatile unsigned      EID2               : 1;
       volatile unsigned      EID1               : 1;
       volatile unsigned      EID0               : 1;
} C2RXF12EIDbits @ 0x572;

static volatile unsigned int  C2RXF13SID         @ 0x574;
static volatile bit           C2RXF13_EID16      @ ((unsigned)&C2RXF13SID*8)+0;
static volatile bit           C2RXF13_EID17      @ ((unsigned)&C2RXF13SID*8)+1;
static volatile bit           C2RXF13_EXIDE      @ ((unsigned)&C2RXF13SID*8)+3;
static volatile bit           C2RXF13_SID0       @ ((unsigned)&C2RXF13SID*8)+5;
static volatile bit           C2RXF13_SID1       @ ((unsigned)&C2RXF13SID*8)+6;
static volatile bit           C2RXF13_SID2       @ ((unsigned)&C2RXF13SID*8)+7;
static volatile bit           C2RXF13_SID3       @ ((unsigned)&C2RXF13SID*8)+8;
static volatile bit           C2RXF13_SID4       @ ((unsigned)&C2RXF13SID*8)+9;
static volatile bit           C2RXF13_SID5       @ ((unsigned)&C2RXF13SID*8)+10;
static volatile bit           C2RXF13_SID6       @ ((unsigned)&C2RXF13SID*8)+11;
static volatile bit           C2RXF13_SID7       @ ((unsigned)&C2RXF13SID*8)+12;
static volatile bit           C2RXF13_SID8       @ ((unsigned)&C2RXF13SID*8)+13;
static volatile bit           C2RXF13_SID9       @ ((unsigned)&C2RXF13SID*8)+14;
static volatile bit           C2RXF13_SID10      @ ((unsigned)&C2RXF13SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C2RXF13SIDbits @ 0x574;

static volatile unsigned int  C2RXF13EID         @ 0x576;
static volatile bit           C2RXF13_EID0       @ ((unsigned)&C2RXF13EID*8)+0;
static volatile bit           C2RXF13_EID1       @ ((unsigned)&C2RXF13EID*8)+1;
static volatile bit           C2RXF13_EID2       @ ((unsigned)&C2RXF13EID*8)+2;
static volatile bit           C2RXF13_EID3       @ ((unsigned)&C2RXF13EID*8)+3;
static volatile bit           C2RXF13_EID4       @ ((unsigned)&C2RXF13EID*8)+4;
static volatile bit           C2RXF13_EID5       @ ((unsigned)&C2RXF13EID*8)+5;
static volatile bit           C2RXF13_EID6       @ ((unsigned)&C2RXF13EID*8)+6;
static volatile bit           C2RXF13_EID7       @ ((unsigned)&C2RXF13EID*8)+7;
static volatile bit           C2RXF13_EID8       @ ((unsigned)&C2RXF13EID*8)+8;
static volatile bit           C2RXF13_EID9       @ ((unsigned)&C2RXF13EID*8)+9;
static volatile bit           C2RXF13_EID10      @ ((unsigned)&C2RXF13EID*8)+10;
static volatile bit           C2RXF13_EID11      @ ((unsigned)&C2RXF13EID*8)+11;
static volatile bit           C2RXF13_EID12      @ ((unsigned)&C2RXF13EID*8)+12;
static volatile bit           C2RXF13_EID13      @ ((unsigned)&C2RXF13EID*8)+13;
static volatile bit           C2RXF13_EID14      @ ((unsigned)&C2RXF13EID*8)+14;
static volatile bit           C2RXF13_EID15      @ ((unsigned)&C2RXF13EID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      EID15              : 1;
       volatile unsigned      EID14              : 1;
       volatile unsigned      EID13              : 1;
       volatile unsigned      EID12              : 1;
       volatile unsigned      EID11              : 1;
       volatile unsigned      EID10              : 1;
       volatile unsigned      EID9               : 1;
       volatile unsigned      EID8               : 1;
       volatile unsigned      EID7               : 1;
       volatile unsigned      EID6               : 1;
       volatile unsigned      EID5               : 1;
       volatile unsigned      EID4               : 1;
       volatile unsigned      EID3               : 1;
       volatile unsigned      EID2               : 1;
       volatile unsigned      EID1               : 1;
       volatile unsigned      EID0               : 1;
} C2RXF13EIDbits @ 0x576;

static volatile unsigned int  C2RXF14SID         @ 0x578;
static volatile bit           C2RXF14_EID16      @ ((unsigned)&C2RXF14SID*8)+0;
static volatile bit           C2RXF14_EID17      @ ((unsigned)&C2RXF14SID*8)+1;
static volatile bit           C2RXF14_EXIDE      @ ((unsigned)&C2RXF14SID*8)+3;
static volatile bit           C2RXF14_SID0       @ ((unsigned)&C2RXF14SID*8)+5;
static volatile bit           C2RXF14_SID1       @ ((unsigned)&C2RXF14SID*8)+6;
static volatile bit           C2RXF14_SID2       @ ((unsigned)&C2RXF14SID*8)+7;
static volatile bit           C2RXF14_SID3       @ ((unsigned)&C2RXF14SID*8)+8;
static volatile bit           C2RXF14_SID4       @ ((unsigned)&C2RXF14SID*8)+9;
static volatile bit           C2RXF14_SID5       @ ((unsigned)&C2RXF14SID*8)+10;
static volatile bit           C2RXF14_SID6       @ ((unsigned)&C2RXF14SID*8)+11;
static volatile bit           C2RXF14_SID7       @ ((unsigned)&C2RXF14SID*8)+12;
static volatile bit           C2RXF14_SID8       @ ((unsigned)&C2RXF14SID*8)+13;
static volatile bit           C2RXF14_SID9       @ ((unsigned)&C2RXF14SID*8)+14;
static volatile bit           C2RXF14_SID10      @ ((unsigned)&C2RXF14SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C2RXF14SIDbits @ 0x578;

static volatile unsigned int  C2RXF14EID         @ 0x57A;
static volatile bit           C2RXF14_EID0       @ ((unsigned)&C2RXF14EID*8)+0;
static volatile bit           C2RXF14_EID1       @ ((unsigned)&C2RXF14EID*8)+1;
static volatile bit           C2RXF14_EID2       @ ((unsigned)&C2RXF14EID*8)+2;
static volatile bit           C2RXF14_EID3       @ ((unsigned)&C2RXF14EID*8)+3;
static volatile bit           C2RXF14_EID4       @ ((unsigned)&C2RXF14EID*8)+4;
static volatile bit           C2RXF14_EID5       @ ((unsigned)&C2RXF14EID*8)+5;
static volatile bit           C2RXF14_EID6       @ ((unsigned)&C2RXF14EID*8)+6;
static volatile bit           C2RXF14_EID7       @ ((unsigned)&C2RXF14EID*8)+7;
static volatile bit           C2RXF14_EID8       @ ((unsigned)&C2RXF14EID*8)+8;
static volatile bit           C2RXF14_EID9       @ ((unsigned)&C2RXF14EID*8)+9;
static volatile bit           C2RXF14_EID10      @ ((unsigned)&C2RXF14EID*8)+10;
static volatile bit           C2RXF14_EID11      @ ((unsigned)&C2RXF14EID*8)+11;
static volatile bit           C2RXF14_EID12      @ ((unsigned)&C2RXF14EID*8)+12;
static volatile bit           C2RXF14_EID13      @ ((unsigned)&C2RXF14EID*8)+13;
static volatile bit           C2RXF14_EID14      @ ((unsigned)&C2RXF14EID*8)+14;
static volatile bit           C2RXF14_EID15      @ ((unsigned)&C2RXF14EID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      EID15              : 1;
       volatile unsigned      EID14              : 1;
       volatile unsigned      EID13              : 1;
       volatile unsigned      EID12              : 1;
       volatile unsigned      EID11              : 1;
       volatile unsigned      EID10              : 1;
       volatile unsigned      EID9               : 1;
       volatile unsigned      EID8               : 1;
       volatile unsigned      EID7               : 1;
       volatile unsigned      EID6               : 1;
       volatile unsigned      EID5               : 1;
       volatile unsigned      EID4               : 1;
       volatile unsigned      EID3               : 1;
       volatile unsigned      EID2               : 1;
       volatile unsigned      EID1               : 1;
       volatile unsigned      EID0               : 1;
} C2RXF14EIDbits @ 0x57A;

static volatile unsigned int  C2RXF15SID         @ 0x57C;
static volatile bit           C2RXF15_EID16      @ ((unsigned)&C2RXF15SID*8)+0;
static volatile bit           C2RXF15_EID17      @ ((unsigned)&C2RXF15SID*8)+1;
static volatile bit           C2RXF15_EXIDE      @ ((unsigned)&C2RXF15SID*8)+3;
static volatile bit           C2RXF15_SID0       @ ((unsigned)&C2RXF15SID*8)+5;
static volatile bit           C2RXF15_SID1       @ ((unsigned)&C2RXF15SID*8)+6;
static volatile bit           C2RXF15_SID2       @ ((unsigned)&C2RXF15SID*8)+7;
static volatile bit           C2RXF15_SID3       @ ((unsigned)&C2RXF15SID*8)+8;
static volatile bit           C2RXF15_SID4       @ ((unsigned)&C2RXF15SID*8)+9;
static volatile bit           C2RXF15_SID5       @ ((unsigned)&C2RXF15SID*8)+10;
static volatile bit           C2RXF15_SID6       @ ((unsigned)&C2RXF15SID*8)+11;
static volatile bit           C2RXF15_SID7       @ ((unsigned)&C2RXF15SID*8)+12;
static volatile bit           C2RXF15_SID8       @ ((unsigned)&C2RXF15SID*8)+13;
static volatile bit           C2RXF15_SID9       @ ((unsigned)&C2RXF15SID*8)+14;
static volatile bit           C2RXF15_SID10      @ ((unsigned)&C2RXF15SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      EXIDE              : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C2RXF15SIDbits @ 0x57C;

static volatile unsigned int  C2RXF15EID         @ 0x57E;
static volatile bit           C2RXF15_EID0       @ ((unsigned)&C2RXF15EID*8)+0;
static volatile bit           C2RXF15_EID1       @ ((unsigned)&C2RXF15EID*8)+1;
static volatile bit           C2RXF15_EID2       @ ((unsigned)&C2RXF15EID*8)+2;
static volatile bit           C2RXF15_EID3       @ ((unsigned)&C2RXF15EID*8)+3;
static volatile bit           C2RXF15_EID4       @ ((unsigned)&C2RXF15EID*8)+4;
static volatile bit           C2RXF15_EID5       @ ((unsigned)&C2RXF15EID*8)+5;
static volatile bit           C2RXF15_EID6       @ ((unsigned)&C2RXF15EID*8)+6;
static volatile bit           C2RXF15_EID7       @ ((unsigned)&C2RXF15EID*8)+7;
static volatile bit           C2RXF15_EID8       @ ((unsigned)&C2RXF15EID*8)+8;
static volatile bit           C2RXF15_EID9       @ ((unsigned)&C2RXF15EID*8)+9;
static volatile bit           C2RXF15_EID10      @ ((unsigned)&C2RXF15EID*8)+10;
static volatile bit           C2RXF15_EID11      @ ((unsigned)&C2RXF15EID*8)+11;
static volatile bit           C2RXF15_EID12      @ ((unsigned)&C2RXF15EID*8)+12;
static volatile bit           C2RXF15_EID13      @ ((unsigned)&C2RXF15EID*8)+13;
static volatile bit           C2RXF15_EID14      @ ((unsigned)&C2RXF15EID*8)+14;
static volatile bit           C2RXF15_EID15      @ ((unsigned)&C2RXF15EID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      EID15              : 1;
       volatile unsigned      EID14              : 1;
       volatile unsigned      EID13              : 1;
       volatile unsigned      EID12              : 1;
       volatile unsigned      EID11              : 1;
       volatile unsigned      EID10              : 1;
       volatile unsigned      EID9               : 1;
       volatile unsigned      EID8               : 1;
       volatile unsigned      EID7               : 1;
       volatile unsigned      EID6               : 1;
       volatile unsigned      EID5               : 1;
       volatile unsigned      EID4               : 1;
       volatile unsigned      EID3               : 1;
       volatile unsigned      EID2               : 1;
       volatile unsigned      EID1               : 1;
       volatile unsigned      EID0               : 1;
} C2RXF15EIDbits @ 0x57E;

static volatile unsigned int  C1BUFPNT1          @ 0x420;
static volatile bit           C1_F0BP0           @ ((unsigned)&C1BUFPNT1*8)+0;
static volatile bit           C1_F0BP1           @ ((unsigned)&C1BUFPNT1*8)+1;
static volatile bit           C1_F0BP2           @ ((unsigned)&C1BUFPNT1*8)+2;
static volatile bit           C1_F0BP3           @ ((unsigned)&C1BUFPNT1*8)+3;
static volatile bit           C1_F1BP0           @ ((unsigned)&C1BUFPNT1*8)+4;
static volatile bit           C1_F1BP1           @ ((unsigned)&C1BUFPNT1*8)+5;
static volatile bit           C1_F1BP2           @ ((unsigned)&C1BUFPNT1*8)+6;
static volatile bit           C1_F1BP3           @ ((unsigned)&C1BUFPNT1*8)+7;
static volatile bit           C1_F2BP0           @ ((unsigned)&C1BUFPNT1*8)+8;
static volatile bit           C1_F2BP1           @ ((unsigned)&C1BUFPNT1*8)+9;
static volatile bit           C1_F2BP2           @ ((unsigned)&C1BUFPNT1*8)+10;
static volatile bit           C1_F2BP3           @ ((unsigned)&C1BUFPNT1*8)+11;
static volatile bit           C1_F3BP0           @ ((unsigned)&C1BUFPNT1*8)+12;
static volatile bit           C1_F3BP1           @ ((unsigned)&C1BUFPNT1*8)+13;
static volatile bit           C1_F3BP2           @ ((unsigned)&C1BUFPNT1*8)+14;
static volatile bit           C1_F3BP3           @ ((unsigned)&C1BUFPNT1*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      F3BP               : 4;
       volatile unsigned      F2BP               : 4;
       volatile unsigned      F1BP               : 4;
       volatile unsigned      F0BP               : 4;
} C1BUFPNT1bits @ 0x420;

static volatile unsigned int  C1BUFPNT2          @ 0x422;
static volatile bit           C1_F4BP0           @ ((unsigned)&C1BUFPNT2*8)+0;
static volatile bit           C1_F4BP1           @ ((unsigned)&C1BUFPNT2*8)+1;
static volatile bit           C1_F4BP2           @ ((unsigned)&C1BUFPNT2*8)+2;
static volatile bit           C1_F4BP3           @ ((unsigned)&C1BUFPNT2*8)+3;
static volatile bit           C1_F5BP0           @ ((unsigned)&C1BUFPNT2*8)+4;
static volatile bit           C1_F5BP1           @ ((unsigned)&C1BUFPNT2*8)+5;
static volatile bit           C1_F5BP2           @ ((unsigned)&C1BUFPNT2*8)+6;
static volatile bit           C1_F5BP3           @ ((unsigned)&C1BUFPNT2*8)+7;
static volatile bit           C1_F6BP0           @ ((unsigned)&C1BUFPNT2*8)+8;
static volatile bit           C1_F6BP1           @ ((unsigned)&C1BUFPNT2*8)+9;
static volatile bit           C1_F6BP2           @ ((unsigned)&C1BUFPNT2*8)+10;
static volatile bit           C1_F6BP3           @ ((unsigned)&C1BUFPNT2*8)+11;
static volatile bit           C1_F7BP0           @ ((unsigned)&C1BUFPNT2*8)+12;
static volatile bit           C1_F7BP1           @ ((unsigned)&C1BUFPNT2*8)+13;
static volatile bit           C1_F7BP2           @ ((unsigned)&C1BUFPNT2*8)+14;
static volatile bit           C1_F7BP3           @ ((unsigned)&C1BUFPNT2*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      F7BP               : 4;
       volatile unsigned      F6BP               : 4;
       volatile unsigned      F5BP               : 4;
       volatile unsigned      F4BP               : 4;
} C1BUFPNT2bits @ 0x422;

static volatile unsigned int  C1RXM0SID          @ 0x430;
static volatile bit           C1RXM0_EID16       @ ((unsigned)&C1RXM0SID*8)+0;
static volatile bit           C1RXM0_EID17       @ ((unsigned)&C1RXM0SID*8)+1;
static volatile bit           C1RXM0_MIDE        @ ((unsigned)&C1RXM0SID*8)+3;
static volatile bit           C1RXM0_SID0        @ ((unsigned)&C1RXM0SID*8)+5;
static volatile bit           C1RXM0_SID1        @ ((unsigned)&C1RXM0SID*8)+6;
static volatile bit           C1RXM0_SID2        @ ((unsigned)&C1RXM0SID*8)+7;
static volatile bit           C1RXM0_SID3        @ ((unsigned)&C1RXM0SID*8)+8;
static volatile bit           C1RXM0_SID4        @ ((unsigned)&C1RXM0SID*8)+9;
static volatile bit           C1RXM0_SID5        @ ((unsigned)&C1RXM0SID*8)+10;
static volatile bit           C1RXM0_SID6        @ ((unsigned)&C1RXM0SID*8)+11;
static volatile bit           C1RXM0_SID7        @ ((unsigned)&C1RXM0SID*8)+12;
static volatile bit           C1RXM0_SID8        @ ((unsigned)&C1RXM0SID*8)+13;
static volatile bit           C1RXM0_SID9        @ ((unsigned)&C1RXM0SID*8)+14;
static volatile bit           C1RXM0_SID10       @ ((unsigned)&C1RXM0SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      MIDE               : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C1RXM0SIDbits @ 0x430;

static volatile unsigned int  C1RXM0EID          @ 0x432;
static volatile unsigned int  C2RXM1SID          @ 0x534;
static volatile bit           C2RXM1_EID16       @ ((unsigned)&C2RXM1SID*8)+0;
static volatile bit           C2RXM1_EID17       @ ((unsigned)&C2RXM1SID*8)+1;
static volatile bit           C2RXM1_MIDE        @ ((unsigned)&C2RXM1SID*8)+3;
static volatile bit           C2RXM1_SID0        @ ((unsigned)&C2RXM1SID*8)+5;
static volatile bit           C2RXM1_SID1        @ ((unsigned)&C2RXM1SID*8)+6;
static volatile bit           C2RXM1_SID2        @ ((unsigned)&C2RXM1SID*8)+7;
static volatile bit           C2RXM1_SID3        @ ((unsigned)&C2RXM1SID*8)+8;
static volatile bit           C2RXM1_SID4        @ ((unsigned)&C2RXM1SID*8)+9;
static volatile bit           C2RXM1_SID5        @ ((unsigned)&C2RXM1SID*8)+10;
static volatile bit           C2RXM1_SID6        @ ((unsigned)&C2RXM1SID*8)+11;
static volatile bit           C2RXM1_SID7        @ ((unsigned)&C2RXM1SID*8)+12;
static volatile bit           C2RXM1_SID8        @ ((unsigned)&C2RXM1SID*8)+13;
static volatile bit           C2RXM1_SID9        @ ((unsigned)&C2RXM1SID*8)+14;
static volatile bit           C2RXM1_SID10       @ ((unsigned)&C2RXM1SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      MIDE               : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C2RXM1SIDbits @ 0x534;

static volatile unsigned int  C1RXM1EID          @ 0x436;
static volatile unsigned int  C2BUFPNT1          @ 0x520;
static volatile bit           C2_F0BP0           @ ((unsigned)&C2BUFPNT1*8)+0;
static volatile bit           C2_F0BP1           @ ((unsigned)&C2BUFPNT1*8)+1;
static volatile bit           C2_F0BP2           @ ((unsigned)&C2BUFPNT1*8)+2;
static volatile bit           C2_F0BP3           @ ((unsigned)&C2BUFPNT1*8)+3;
static volatile bit           C2_F1BP0           @ ((unsigned)&C2BUFPNT1*8)+4;
static volatile bit           C2_F1BP1           @ ((unsigned)&C2BUFPNT1*8)+5;
static volatile bit           C2_F1BP2           @ ((unsigned)&C2BUFPNT1*8)+6;
static volatile bit           C2_F1BP3           @ ((unsigned)&C2BUFPNT1*8)+7;
static volatile bit           C2_F2BP0           @ ((unsigned)&C2BUFPNT1*8)+8;
static volatile bit           C2_F2BP1           @ ((unsigned)&C2BUFPNT1*8)+9;
static volatile bit           C2_F2BP2           @ ((unsigned)&C2BUFPNT1*8)+10;
static volatile bit           C2_F2BP3           @ ((unsigned)&C2BUFPNT1*8)+11;
static volatile bit           C2_F3BP0           @ ((unsigned)&C2BUFPNT1*8)+12;
static volatile bit           C2_F3BP1           @ ((unsigned)&C2BUFPNT1*8)+13;
static volatile bit           C2_F3BP2           @ ((unsigned)&C2BUFPNT1*8)+14;
static volatile bit           C2_F3BP3           @ ((unsigned)&C2BUFPNT1*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      F3BP               : 4;
       volatile unsigned      F2BP               : 4;
       volatile unsigned      F1BP               : 4;
       volatile unsigned      F0BP               : 4;
} C2BUFPNT1bits @ 0x520;

static volatile unsigned int  C2BUFPNT2          @ 0x522;
static volatile bit           C2_F4BP0           @ ((unsigned)&C2BUFPNT2*8)+0;
static volatile bit           C2_F4BP1           @ ((unsigned)&C2BUFPNT2*8)+1;
static volatile bit           C2_F4BP2           @ ((unsigned)&C2BUFPNT2*8)+2;
static volatile bit           C2_F4BP3           @ ((unsigned)&C2BUFPNT2*8)+3;
static volatile bit           C2_F5BP0           @ ((unsigned)&C2BUFPNT2*8)+4;
static volatile bit           C2_F5BP1           @ ((unsigned)&C2BUFPNT2*8)+5;
static volatile bit           C2_F5BP2           @ ((unsigned)&C2BUFPNT2*8)+6;
static volatile bit           C2_F5BP3           @ ((unsigned)&C2BUFPNT2*8)+7;
static volatile bit           C2_F6BP0           @ ((unsigned)&C2BUFPNT2*8)+8;
static volatile bit           C2_F6BP1           @ ((unsigned)&C2BUFPNT2*8)+9;
static volatile bit           C2_F6BP2           @ ((unsigned)&C2BUFPNT2*8)+10;
static volatile bit           C2_F6BP3           @ ((unsigned)&C2BUFPNT2*8)+11;
static volatile bit           C2_F7BP0           @ ((unsigned)&C2BUFPNT2*8)+12;
static volatile bit           C2_F7BP1           @ ((unsigned)&C2BUFPNT2*8)+13;
static volatile bit           C2_F7BP2           @ ((unsigned)&C2BUFPNT2*8)+14;
static volatile bit           C2_F7BP3           @ ((unsigned)&C2BUFPNT2*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      F7BP               : 4;
       volatile unsigned      F6BP               : 4;
       volatile unsigned      F5BP               : 4;
       volatile unsigned      F4BP               : 4;
} C2BUFPNT2bits @ 0x522;

static volatile unsigned int  C2RXM0SID          @ 0x530;
static volatile bit           C2RXM0_EID16       @ ((unsigned)&C2RXM0SID*8)+0;
static volatile bit           C2RXM0_EID17       @ ((unsigned)&C2RXM0SID*8)+1;
static volatile bit           C2RXM0_MIDE        @ ((unsigned)&C2RXM0SID*8)+3;
static volatile bit           C2RXM0_SID0        @ ((unsigned)&C2RXM0SID*8)+5;
static volatile bit           C2RXM0_SID1        @ ((unsigned)&C2RXM0SID*8)+6;
static volatile bit           C2RXM0_SID2        @ ((unsigned)&C2RXM0SID*8)+7;
static volatile bit           C2RXM0_SID3        @ ((unsigned)&C2RXM0SID*8)+8;
static volatile bit           C2RXM0_SID4        @ ((unsigned)&C2RXM0SID*8)+9;
static volatile bit           C2RXM0_SID5        @ ((unsigned)&C2RXM0SID*8)+10;
static volatile bit           C2RXM0_SID6        @ ((unsigned)&C2RXM0SID*8)+11;
static volatile bit           C2RXM0_SID7        @ ((unsigned)&C2RXM0SID*8)+12;
static volatile bit           C2RXM0_SID8        @ ((unsigned)&C2RXM0SID*8)+13;
static volatile bit           C2RXM0_SID9        @ ((unsigned)&C2RXM0SID*8)+14;
static volatile bit           C2RXM0_SID10       @ ((unsigned)&C2RXM0SID*8)+15;
/* Microchip compatible bit field */
static volatile struct {
       volatile unsigned      SID10              : 1;
       volatile unsigned      SID9               : 1;
       volatile unsigned      SID8               : 1;
       volatile unsigned      SID7               : 1;
       volatile unsigned      SID6               : 1;
       volatile unsigned      SID5               : 1;
       volatile unsigned      SID4               : 1;
       volatile unsigned      SID3               : 1;
       volatile unsigned      SID2               : 1;
       volatile unsigned      SID1               : 1;
       volatile unsigned      SID0               : 1;
                unsigned                         : 1;
       volatile unsigned      MIDE               : 1;
                unsigned                         : 1;
       volatile unsigned      EID17              : 1;
       volatile unsigned      EID16              : 1;
} C2RXM0SIDbits @ 0x530;

static volatile unsigned int  C2RXM0EID          @ 0x532;
static volatile unsigned int  C2RXM1EID          @ 0x536;

#endif
