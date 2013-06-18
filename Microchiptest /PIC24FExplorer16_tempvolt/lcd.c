/*****************************************************************************
 *
 * LCD Driver for PIC24.
 *
 *****************************************************************************
 * FileName:        lcd.c
 * Dependencies:    system.h, uart2.c
 * Processor:       PIC24
 * Compiler:       	MPLAB C30
 * Linker:          MPLAB LINK30
 * Company:         Microchip Technology Incorporated
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the "Company") is intended and supplied to you, the Company's
 * customer, for use solely and exclusively with products manufactured
 * by the Company. 
 *
 * The software is owned by the Company and/or its supplier, and is 
 * protected under applicable copyright laws. All rights are reserved. 
 * Any use in violation of the foregoing restrictions may subject the 
 * user to criminal sanctions under applicable laws, as well as to 
 * civil liability for the breach of the terms and conditions of this 
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES, 
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED 
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A 
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT, 
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR 
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *
 * A simple LCD driver for LCDs interface through the PMP
 * 
 *
 *
 * Author               Date        Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Ross Fosler			08/13/04	...	
 * Anton Alkhimenok		10/18/05	added message copying to UART	
 * Brant Ivey			3/14/06		Changed PMPEN register to PMAEN
 *****************************************************************************/
#include "system.h"

// Define a fast instruction execution time in terms of loop time
// typically > 43us
#define	LCD_F_INSTR		10

// Define a slow instruction execution time in terms of loop time
// typically > 1.35ms
#define	LCD_S_INSTR		150

// Define the startup time for the LCD in terms of loop time
// typically > 30ms
#define	LCD_STARTUP		2000


#define		_LCD_IDLE(__cnt)	_uLCDstate = 1; _uLCDloops = __cnt;
#define		_LCD_INIT(__cnt)	_uLCDstate++; _uLCDloops = __cnt;


unsigned int	_uLCDloops;
unsigned char	_uLCDstate;
unsigned char 	_uLCDchar;


#if defined(__PIC24FJ256GB210__)||(__PIC24FJ128GA310__)
	#define CS1_BASE_ADDRESS   		0x00020000ul 
	#define CS2_BASE_ADDRESS   		0x000A0000ul 
	__eds__ unsigned int __attribute__((noload, section("epmp_cs1"), address(CS1_BASE_ADDRESS))) ADDR0 __attribute__((space(eds)));
	__eds__ unsigned int __attribute__((noload, section("epmp_cs1"), address(CS1_BASE_ADDRESS))) ADDR1 __attribute__((space(eds)));
	void InitializeEPMP(void);

#endif

#if defined(__PIC24F32KA304__) 
/*************************************************************/

void Send_LCD_Command(unsigned char cmd)
{	//note: the bit shifting is for the LED display
	int holder = (LATC&0xF00)>>8;
	clrLCD_RS();
	clrLCD_RW();
	LATC = cmd|(holder<<8);
	setLCD_E();
	Nop();
	clrLCD_E();
	setLCD_RW();
	LATC |= 0x00FF;
}

/*************************************************************/

void Send_LCD_Data(unsigned char data)
{	//note: the bit shifting is for the LED display
	int holder = (LATC&0xF00)>>8;
	clrLCD_RW();
	setLCD_RS();
	LATC = data|(holder<<8);
	setLCD_E();
	Nop();	// 7.5us on the pmp
	clrLCD_E();
	setLCD_RW();
	LATC |= 0x00FF;
}
#endif
/*****************************************************************************
 * Function: LCDProcessEvents
 *
 * Preconditions: None.
 *
 * Overview: This is a state mashine to issue commands and data to LCD. Must be
 * called periodically to make LCD message processing.
 *
 * Input: None.
 *
 * Output: None.
 *
 *****************************************************************************/

#if defined(__PIC24FJ256GB210__)||(__PIC24FJ128GA310__)

void LCDProcessEvents(void)
	{

	switch (_uLCDstate) {
		case 1:								// *** wait *** 
			if (_uLCDloops) _uLCDloops--;
			else _uLCDstate = 0;
			break;
		case 2:								// *** init ***
			InitializeEPMP();
			ADDR0=0x00;		
			_uLCDstate = 64;				// Set the next state
			_uLCDloops = LCD_STARTUP;		// Set the entry delay
			break;
		case 3:								// *** put ***
			_LCD_IDLE(LCD_F_INSTR);
			ADDR1=_uLCDchar;	
            UART2PutChar(_uLCDchar);        // Copy character to UART
			break;
		case 4:								// *** clear ***
			_LCD_IDLE(LCD_S_INSTR);
			ADDR0= 0b00000001;	
           UART2PutChar('\r');             // Send return to UART
			break;
		case 5:								// *** home ***
			_LCD_IDLE(LCD_S_INSTR);		
			ADDR0=	 0b00000010;
           UART2PutChar('\r');             // Send return to UART
			break;	
		case 6:								// *** command ***
			_LCD_IDLE(LCD_F_INSTR);
			ADDR0 = _uLCDchar;	
			break;

		// This is the LCD init state machine
		case 64:							// Standard delay states for the init
		case 66:
		case 68:
		case 70:							// Programmable delay loop
			if (_uLCDloops) _uLCDloops--;
			else _uLCDstate++;
			break;
		case 65:
			_LCD_INIT(LCD_F_INSTR);
			ADDR0= 0b00111100;
			break;
		case 67:
			_LCD_INIT(LCD_F_INSTR);
			ADDR0 = 0b00001100;
			break;
		case 69:	
			_LCD_INIT(LCD_S_INSTR);
			ADDR0 = 0b00000001;
			break;
		case 71:
			_LCD_INIT(LCD_S_INSTR);
			ADDR0 = 0b00000110;
			break;
		case 72:
			_uLCDstate = 0;
			break;
		default:
			_uLCDstate = 0;
			break;
	}

}

void InitializeEPMP(void)
{
	// set the following pins to be used as digital ports	
	

	PMCON1bits.ADRMUX = 0;	    				// address is not multiplexed
	PMCON1bits.MODE = 3;        				// master mode
	PMCON1bits.CSF = 0;         				// PMCS1 pin used for chip select 1, PMCS2 pin used for chip select 2
	PMCON1bits.ALP = 0;         				// 
	PMCON1bits.ALMODE = 0;      				// "smart" address strobes are not used
	PMCON1bits.BUSKEEP = 0;     				// bus keeper is not used
	
	
	PMCS1BS = (CS1_BASE_ADDRESS>>8);			// CS1 start address
		
 
	PMCS1CFbits.CSDIS = 0;      				// enable CS
	PMCS1CFbits.CSP = 1;      // CS1 polarity 
	PMCS1CFbits.BEP = 1;      // byte enable polarity
	PMCS1CFbits.WRSP = 1;     // write strobe polarity
	PMCS1CFbits.RDSP =1;     // read strobe polarity
	PMCS1CFbits.CSPTEN = 1;     				// enable CS port
	PMCS1CFbits.SM = 0;         				// read and write strobes on separate lines 
	PMCS1CFbits.PTSZ = 2;       				// data bus width is 16-bit 
	PMCS1MDbits.ACKM = 0;        				// PMACK is not used

	// The device timing parameters. Set the proper timing
	// according to the device used (the timing macros are defined in the hardware profile)
	PMCS1MDbits.DWAITB = 1;      	// access time 1 Tcy
	PMCS1MDbits.DWAITM = 1;
	PMCS1MDbits.DWAITE = 1;

	PMCON2bits.RADDR = 0; 						// don't care since CS2 is not be used 
	PMCON4 = 0x0001;							// PMA0 - PMA15 address lines are enabled
	

	PMCON3bits.PTWREN = 1;      				// enable write strobe port
	PMCON3bits.PTRDEN = 1;      				// enable read strobe port
	PMCON3bits.PTBE0EN = 1;     				// enable byte enable port
	PMCON3bits.PTBE1EN = 1;     				// enable byte enable port
	PMCON3bits.AWAITM = 0;      				// set address latch pulses width to 1/2 Tcy
	PMCON3bits.AWAITE = 0;      				// set address hold time to 1/4 Tcy
	
	PMCON1bits.PMPEN = 1;						// enable the module
	
}




#else // other MCUs that are not PIC24FJ256GB210 or GA310
void LCDProcessEvents(void)
{
	switch (_uLCDstate) {
		case 1:								// *** wait *** 
			if (_uLCDloops) _uLCDloops--;
			else _uLCDstate = 0;
			break;
		case 2:								// *** init ***
			#if defined(__PIC24F32KA304__)
					TRISC &= 0xF00;	//set RC0-7 as data output
					TRISB &= 0xFC7F;	//set RB7,8,9 as control line outputs
					Nop();
					LATC |= 0x00FF;
					clrLCD_E();
					setLCD_RW();
					clrLCD_RS();
			#else
			PMCON = 0x83BF;				    // Setup the PMP
			PMMODE = 0x3FF;
			PMAEN = 0x0001;
			PMADDR = 0x0000;
			#endif
			_uLCDstate = 64;				// Set the next state
			_uLCDloops = LCD_STARTUP;		// Set the entry delay
			break;
		case 3:								// *** put ***
			_LCD_IDLE(LCD_F_INSTR);
			#if defined(__PIC24F32KA304__)
				Send_LCD_Data(_uLCDchar);
			#else
			PMADDR = 0x0001;
			PMDIN1 = _uLCDchar;
			#endif
            UART2PutChar(_uLCDchar);        // Copy character to UART
			break;
		case 4:								// *** clear ***
			_LCD_IDLE(LCD_S_INSTR);
			#if defined(__PIC24F32KA304__) 
				Send_LCD_Command(0b00000001);
			#else
			PMADDR = 0x0000;
			PMDIN1 = 0b00000001;
			#endif
            UART2PutChar('\r');             // Send return to UART
			break;
		case 5:								// *** home ***
			_LCD_IDLE(LCD_S_INSTR);
			#if defined(__PIC24F32KA304__) 
				Send_LCD_Command(0b00000010);
			//	Send_LCD_Command(0x80);
			#else
			PMADDR = 0x0000;
			PMDIN1 = 0b00000010;
			#endif
            UART2PutChar('\r');             // Send return to UART
			break;	
		case 6:								// *** command ***
			_LCD_IDLE(LCD_F_INSTR);
			#if defined(__PIC24F32KA304__)
				Send_LCD_Command(_uLCDchar);
			#else
			PMADDR = 0x0000;
			PMDIN1 = _uLCDchar;
			#endif
			break;
#if defined(__PIC24F32KA304__) 
		// This is the LCD init state machine without the PMP
		case 64:							// Standard delay states for the init
		case 66:
		case 68:
		case 70:							// Programmable delay loop
			if (_uLCDloops) _uLCDloops--;
			else _uLCDstate++;
			break;
		case 65:
			_LCD_INIT(LCD_F_INSTR);
			Send_LCD_Command(0x3C);			// Set the default function
			break;
		case 67:
			_LCD_INIT(LCD_F_INSTR);
			Send_LCD_Command(0x0C);            // Set the display control
			break;
		case 69:	
			_LCD_INIT(LCD_S_INSTR);
			Send_LCD_Command(0x01);			// Clear the display
			break;
		case 71:
			_LCD_INIT(LCD_S_INSTR);
			Send_LCD_Command(0x06);			// Set the entry mode
			break;
		case 72:
			_uLCDstate = 0;
			break;
		default:
			_uLCDstate = 0;
			break;

#else

		// This is the LCD init state machine
		case 64:							// Standard delay states for the init
		case 66:
		case 68:
		case 70:							// Programmable delay loop
			if (_uLCDloops) _uLCDloops--;
			else _uLCDstate++;
			break;
		case 65:
			_LCD_INIT(LCD_F_INSTR);
			PMDIN1 = 0b00111100;			// Set the default function
			break;
		case 67:
			_LCD_INIT(LCD_F_INSTR);
			PMDIN1 = 0b00001100;            // Set the display control
			break;
		case 69:	
			_LCD_INIT(LCD_S_INSTR);
			PMDIN1 = 0b00000001;			// Clear the display
			break;
		case 71:
			_LCD_INIT(LCD_S_INSTR);
			PMDIN1 = 0b00000110;			// Set the entry mode
			break;
		case 72:
			_uLCDstate = 0;
			break;
		default:
			_uLCDstate = 0;
			break;
#endif
	}
}
#endif
/*****************************************************************************
 * EOF
 *****************************************************************************/
