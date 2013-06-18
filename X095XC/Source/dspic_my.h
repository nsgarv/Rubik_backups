
#ifndef _DSPIC_H
//#define _DSPIC_H

#ifndef _HTC_H_
//#include <htc.h>
#endif

/* Macros to access bytes within words and words within longs */
#define LOW_BYTE(x)     ((unsigned char)((x)&0xFF))
#define HIGH_BYTE(x)    ((unsigned char)(((x)>>8)&0xFF))
#define LOW_WORD(x)     ((unsigned short)((x)&0xFFFF))
#define HIGH_WORD(x)    ((unsigned short)(((x)>>16)&0xFFFF))
        
#define CLRWDT()        asm("clrwdt")
#define NOP()           asm("nop")
#define RESET()         asm("reset")
#define	SLEEP()		asm("pwrsav #0")
#define IDLE()		asm("pwrsav #1")
#define PWRSAV(x)	asm("pwrsav #" ___mkstr(x))


/* Disable interrupts (and save settings for later),
   by setting CPU Interrupt Priority Level to 7. */
#define DI() do { \
	  asm("PUSH _SR"); \
	  SR |= 0x00e0;	   \
} while(0)

/* Restore saved interrupt-enable status.
   To narrow the window of opportunity for the Address Trap errata,
   disable (level 1-6) interrupts while restoring IPL. */
#define EI() do { \
	  asm("DISI #1"); \
	  asm("POP _SR"); \
} while(0)

/* Disable interrupts for the next x cycles */
#define DISI(x)	asm("disi #" ___mkstr(x))


// EEPROM
#if __EEPROM_SIZE__

#define __EEPROM_DATA(a, b, c, d, e, f, g, h) \
		 asm("\tpsect eeprom,class=EEPROM,delta=2"); \
		 asm("\tddw\t" ___mkstr(a) "," ___mkstr(b) "," ___mkstr(c) "," ___mkstr(d) "," \
		       ___mkstr(e) "," ___mkstr(f) "," ___mkstr(g) "," ___mkstr(h))

#endif // __EEPROM_SIZE__


/* Error Trap Vectors */

#define OSCFAIL_VCTR	0x6	// Oscillator Fail Trap
#define ADDRERR_VCTR	0x8 // Address Error Trap
#define STCKERR_VCTR	0xa // Stack Error Trap
#define MATHERR_VCTR	0xc // Math Error Trap

#if defined(__dsPIC33F__) || defined(__PIC24HJ__)
#define DMAERR_VCTR		0xe	// DMA Error Trap
#endif


/* Interrupt vector table locations for peripherals */

#define INT0_VCTR	0x14	// External Interrupt 0
#define IC1_VCTR	0x16	// Input Capture 1
#define OC1_VCTR	0x18	// Output Compare 1
#define T1_VCTR		0x1a	// Timer 1

/* Alternate Error Trap Vectors */

#define OSCFAIL_AVCTR	(0x6+__AIVT_OFFSET__) // Oscillator Fail Trap
#define ADDRERR_AVCTR	(0x8+__AIVT_OFFSET__) // Address Error Trap
#define STCKERR_AVCTR	(0xa+__AIVT_OFFSET__) // Stack Error Trap
#define MATHERR_AVCTR	(0xc+__AIVT_OFFSET__) // Math Error Trap

#if defined(__dsPIC33F__) || defined(__PIC24HJ__)
#define DMAERR_AVCTR	(0xe+__AIVT_OFFSET__) // DMA Error Trap
#endif


#define INT0_AVCTR	(0x14+__AIVT_OFFSET__)	// External Interrupt 0
#define IC1_AVCTR	(0x16+__AIVT_OFFSET__)	// Input Capture 1
#define OC1_AVCTR	(0x18+__AIVT_OFFSET__)	// Output Compare 1
#define T1_AVCTR	(0x1a+__AIVT_OFFSET__)	// Timer 1


/* Writing to OSCCON requires tight timing not guaranteeable in C */
#define write_to_OSCCON __write_to_OSCCON
void write_to_OSCCON(unsigned __newval);

//
/* Configuration bit values */
//

// Flash Configuration Words and Values


#define __CONFIG(n, x)  asm("\tpsect config,class=CONFIG,delta=2");\
                        asm("global config_word" ___mkstr(n)); \
                        asm("\torg ("___mkstr(n)"-1)*2"); \
                        asm("config_word" ___mkstr(n)":"); \
                        asm("\tddw "___mkstr(x))

//
// dsPIC33F & PIC24HJ Devices
//

// Boot Segment Configuration Word
#define FBS			1

// Boot Segment Program Flash Write Protection Bit
#define BWRPU		0xFFFFFF	// Boot segment may be written
#define BWRPP		0xFFFFFE	// Boot segment is write-protected

// Boot Segment Program Flash Code Protection Size Bits
#define BSSNB		0xFFFFFF	// No boot program Flash segment
#define BSSSTSM		0xFFFFFD	// Standard security; small boot segment
#define BSSHISM		0xFFFFF5	// High security; small boot segment
#define BSSSTMD		0xFFFFFB	// Standard security; medium boot segment
#define BSSHIMD		0xFFFFF3	// High security; medium boot segment
#define BSSSTLG		0xFFFFF9	// Standard security; large boot segment
#define BSSHILG		0xFFFFF1	// High security; large boot segment

// Boot Segment RAM Code Protection Bits
#define NORBS		0xFFFFFF	// No Boot RAM defined
#define	RBS128		0xFFFFBF	// Boot RAM is 128 Bytes
#define	RBS256		0xFFFF7F	// Boot RAM is 256 Bytes
#define	RBS1024		0xFFFF3F	// Boot RAM is 1024 Bytes

// Secure Segment Configuration Word
#define	FSS			2

// Secure Segment Program Flash Write Protection Bit
#define	SWRPU		0xFFFFFF	// Secure segment may be written
#define SWRPP		0xFFFFFE	//  Secure segment is write-protected

// Secure Segment Program Flash Code Protection Size Bits
#define SSSNS		0xFFFFFF	// No secure program Flash segment
#define SSSSTSM		0xFFFFFD	// Standard security; small secure segment
#define SSSHISM		0xFFFFF5	// High security; small secure segment
#define SSSSTMD		0xFFFFFB	// Standard security; medium secure segment
#define SSSHIMD		0xFFFFF3	// High security; medium secure segment
#define SSSSTLG		0xFFFFF9	// Standard security; large secure segment
#define SSSHILG		0xFFFFF1	// High security; large secure segment

// secure Segment RAM Code Protection Bits
#define NORSS		0xFFFFFF	// No secure RAM defined
#define	RSS256		0xFFFFBF	// secure RAM is 256 Bytes
#define	RSS2048		0xFFFF7F	// secure RAM is 2048 Bytes
#define	RSS4096		0xFFFF3F	// secure RAM is 4096 Bytes

// General Code Segment Configuration
#define FGS			3

#define GCPU		0xFFFFFF	// User Program Memory Code Unprotected
#define GCPP		0xFFFFFD	// User Program Memory Code Protected
#define GWRU		0xFFFFFF	// User Program Memory Write Unprotected
#define GWRP		0xFFFFFE	// User Program Memory Write Protected

// General Segment Code-Protect bits
#define	GSSU		0xFFFFFF	// User program memory is not code-protected	
#define	GSSPST		0xFFFFFD	// Standard Security
#define GSSPHI		0xFFFFFB	// High Security

// Oscillator Two-Speed Startup, Temperature Protection and Initial Oscillator Source Selection
#define FOSCSEL		4

#define IESOEN		0xFFFFFF	// Two-speed Oscillator Start-up Enabled
#define IESODIS		0xFFFF7F	// Two-speed Oscillator Start-up Disabled
#define TEMPDIS		0xFFFFFF	// Temperature Protection Disabled
#define TEMPEN		0xFFFFDF	// Temperature Protection Enabled
#define FRCPS		0xFFFFFF	// Internal Fast RC (FRC) oscillator with postscaler
#ifdef __dsPIC33F__
#define FRCDIV16	0xFFFFFE	// Internal Fast RC (FRC) oscillator with divide-by-16
#endif
#define LPRC		0xFFFFFD	// LPRC oscillator
#define LP			0xFFFFFC	// Secondary (LP) oscillator
#define OSCPLL		0xFFFFFB	// Primary (XT, HS, EC) oscillator with PLL
#define OSC			0xFFFFFA	// Primary (XT, HS, EC) oscillator
#define FRCPLL		0xFFFFF9	// Internal Fast RC (FRC) oscillator with PLL
#define FRC			0xFFFFF8	// FRC oscillator

// Oscillator Clock Switching Modes, OSC2 Pin Function and Primary Oscillator Modes
#define FOSC		5

#define FCKSMDIS	0xFFFFFF	// Clock switching is disabled, Fail-Safe Clock Monitor is disabled
#define CLKSWEN		0xFFFF7F	// Clock switching is enabled, Fail-Safe Clock Monitor is disabled
#define FCKSMEN		0xFFFF3F	// Clock switching is enabled, Fail-Safe Clock Monitor is enabled
#define	OSC2OUT		0xFFFFFF	// OSC2 is clock output
#define OSC2DIO		0xFFFFFB	// OSC2 is general purpose digital I/O pin
#define POSCDIS		0xFFFFFF	// Primary oscillator disabled
#define POSCHS		0xFFFFFE	// HS Crystal Oscillator mode
#define POSCXT		0xFFFFFD	// XT Crystal Oscillator mode
#define	POSCEC		0xFFFFFC	// EC (External Clock) mode

// Watchdog Timer
#define FWDT		6

#define WDTEN		0xFFFFFF	// Watchdog Timer always enabled
#define WDTDIS		0xFFFF7F	// Watchdog Timer enabled/disabled by user software
#define WINDIS		0xFFFFFF	// Watchdog Timer in Non-Window mode
#define WINEN		0xFFFFBF	// Watchdog Timer in Window mode
#define WDTPRE128	0xFFFFFF	// 1:128 Watchdog Timer Prescaler
#define WDTPRE32	0xFFFFEF	// 1:32 Watchdog Timer Prescaler
#define	WDTPS32768	0xFFFFFF	// Postscaler ratio 1:32768
#define	WDTPS16384	0xFFFFFE	// Postscaler ratio 1:16384
#define	WDTPS8192	0xFFFFFD	// Postscaler ratio 1:8192
#define	WDTPS4096	0xFFFFFC	// Postscaler ratio 1:4096
#define	WDTPS2048	0xFFFFFB	// Postscaler ratio 1:2048
#define	WDTPS1024	0xFFFFFA	// Postscaler ratio 1:1024
#define	WDTPS512	0xFFFFF9	// Postscaler ratio 1:512
#define	WDTPS256	0xFFFFF8	// Postscaler ratio 1:256
#define	WDTPS128	0xFFFFF7	// Postscaler ratio 1:128
#define	WDTPS64		0xFFFFF6	// Postscaler ratio 1:64
#define	WDTPS32		0xFFFFF5	// Postscaler ratio 1:32
#define	WDTPS16		0xFFFFF4	// Postscaler ratio 1:16
#define	WDTPS8		0xFFFFF3	// Postscaler ratio 1:8
#define	WDTPS4		0xFFFFF2	// Postscaler ratio 1:4
#define	WDTPS2		0xFFFFF1	// Postscaler ratio 1:2
#define	WDTPS1		0xFFFFF0	// Postscaler ratio 1:1

// Motor Control and Power-on Reset Timer Value
#define FPOR		7
#ifdef __dsPIC33F__
#define PWMPORT		0xFFFFFF	// PWM module pins controlled by PORT register
#define PWMPWM		0xFFFF7F	// PWM module pins controlled by PWM module
#define PWMHPAH		0xFFFFFF	// PWM module high side output pins have active-high output polarity
#define PWMHPAL		0xFFFFBF	// PWM module high side output pins have active-low output polarity
#define PWMLPAH		0xFFFFFF	// PWM module low side output pins have active-high output polarity
#define	PWMLPAL		0xFFFFDF	// PWM module low side output pins have active-low output polarity
#endif
#define PWRT128		0xFFFFFF	// 128 ms Power-on Reset Timer Value
#define PWRT64		0xFFFFFE	// 64 ms Power-on Reset Timer Value
#define PWRT32		0xFFFFFD	// 32 ms Power-on Reset Timer Value
#define	PWRT16		0xFFFFFC	// 16 ms Power-on Reset Timer Value
#define PWRT8		0xFFFFFB	// 8 ms Power-on Reset Timer Value
#define	PWRT4		0xFFFFFA	// 4 ms Power-on Reset Timer Value
#define PWRT2		0xFFFFF9	// 2 ms Power-on Reset Timer Value
#define PWRTDIS		0xFFFFF8	// Power-on Reset Timer Disabled

// ICD Config Word
#define FICD	8
// Background Debugger Enable bit
#define DEBUGDIS	0xFFFFFF	// Device resets into Operational mode
#define DEBUGEN		0xFFFF7F	// Device resets into Debug mode
// Set Clip On Emulation bit
#define COEDIS		0xFFFFFF	// Device resets into Operational mode
#define COEEN		0xFFFFBF	// Device resets into Clip On Emulation mode
// JTAG Port Enable Bit
#define	JTAGEN		0xFFFFFF	// JTAG port is enabled
#define JTAGDIS		0xFFFFDF	// JTAG port is disabled
// ICS: ICD Communication Channel Select bits
#define ICS1		0xFFFFFF	// Communicate on PGC1/EMUC1 and PGD1/EMU1
#define ICS2		0xFFFFFE	// Communicate on PGC2/EMUC2 and PGD2/EMU2
#define ICS3		0xFFFFFD	// Communicate on PGC3/EMUC3 and PGD3/EMU3

/* Add the advanced EEPROM/FLASH routines */
//#include <nvm_interface.h>

#endif // _DSPIC_H
