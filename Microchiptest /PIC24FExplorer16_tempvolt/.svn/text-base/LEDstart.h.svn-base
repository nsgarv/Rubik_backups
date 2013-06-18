/*****************************************************************************
 *  LEDstart
 *****************************************************************************
 * FileName:        LEDstart.h
 * Dependencies:    
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
 * External functions and data declaration to display
 * temperature sensor and potentiometer
 *
 * Author               Date        Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *Kevin Hengehold		9/30/10		...
**********************************************************************************/

/*********************************************************************************
 * Function: LEDInit
 *
 * Preconditions: None.
 * 
 * Overview:  This function initializes the LED process
 *
 * Input: None
 *
 * Output: None
 *
 *********************************************************************************/
 void LEDInit(void);

/********************************************************************************
 * Function: LEDProcessEvents
 * 
 * Preconditions:  None.
 *
 * Overview: this function creates the LED startup pattern.
 *
 * Input: None.
 * 
 * Output: None.
 *
 ********************************************************************************/
void LEDProcessEvent(void);

/*******************************************************************************
 * Function: Delay
 * 
 * Preconditions: None
 *
 * Overview: Creates a delay between LED state changes
 *
 * Input: None.
 *
 * Output: None.
 *
 ********************************************************************************/
void Delay(void);  

/*********************************************************************************
* Function: LED_PotUpdate
* 
* Preconditions: LEDInit must be called before use
*
* Overview:  Sets LED's proportionally to the ADC value read by
*            the potentiometer.
*
* Input: Result, the ADC value from the potentiometer
*
* Output: None.
*
**********************************************************************************/

extern void LED_Update(unsigned int Result);


//define statement to map LED port and tris pins to the correct register values

#if defined(__PIC24F32KA304__) 
	#define LED3	LATAbits.LATA9
	#define LED4	LATAbits.LATA10
	#define LED5	LATAbits.LATA11
	#define LED6	LATCbits.LATC8
	#define	LED7	LATCbits.LATC9
	#define LED8	LATBbits.LATB12
	#define LED9	LATBbits.LATB2
	#define LED10	LATBbits.LATB3

	#define TRIS_LED3	TRISAbits.TRISA9
	#define TRIS_LED4	TRISAbits.TRISA10
	#define TRIS_LED5	TRISAbits.TRISA11
	#define TRIS_LED6	TRISCbits.TRISC8
	#define	TRIS_LED7	TRISCbits.TRISC9
	#define TRIS_LED8	TRISBbits.TRISB12
	#define TRIS_LED9	TRISBbits.TRISB2
	#define TRIS_LED10	TRISBbits.TRISB3
	
#endif
