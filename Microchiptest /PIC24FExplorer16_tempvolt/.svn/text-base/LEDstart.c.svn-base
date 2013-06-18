/*****************************************************************************
 *  LEDstart
  *****************************************************************************
 * FileName:        LEDstart.c
 * Dependencies:    system.h, LEDstart.h
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
 * this code performs an LED startup routine
  *
 * Author               Date        Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Kevin Hengehold		09/30/10	...
************************************************************************************/

#include "system.h"

#if defined(__PIC24F32KA304__)

extern int monitor_display_state;


//Initiaizes LED ports as outputs
void LEDInit(void)
{
	TRIS_LED3 = 0;
	TRIS_LED4 = 0;
	TRIS_LED5 = 0;
	TRIS_LED6 = 0;
	TRIS_LED7 = 0;
	TRIS_LED8 = 0;
	TRIS_LED9 = 0;
	TRIS_LED10 = 0;

#if defined(__PIC24F32KA304__) 
	ANSELBbits.ANSB2 = 0;
#endif
}

//Perform startup routine on LED's
void LEDProcessEvent(void)
{
	LEDInit();

	LED3 = 1;
	Delay();
	LED4 = 1;
	Delay();
	LED5 = 1;
	Delay();
	LED6 = 1;
	Delay();
	LED7 = 1;
	Delay();
	LED8 = 1;
	Delay();
	LED9 = 1;
	Delay();
	LED10 = 1;
	Delay();
	LED10 = 0;
	Delay();
	LED9 = 0;
	Delay();
	LED8 = 0;
	Delay();
	LED7= 0;
	Delay();
	LED6 = 0;
	Delay();
	LED5= 0;
	Delay();
	LED4= 0;
	Delay();
	LED3= 0;
}

void Delay(void)
{
	int i;
	for(i=0;i<0x28ff;i++);
}

//Quantize ADC measurement, display it proportionally on the 8 LED's
void LED_Update(unsigned int Result)
{
	if(monitor_display_state==1) //DISP_VOLTAGE = 1
	{		TRIS_LED10 = 0;
		  	if(Result > 910)
			{	LED3=1;LED4=1;LED5=1;LED6=1;LED7=1;LED8=1;LED9=1;LED10=1;
			}	
			else if(Result > 795)
			{	LED3=0;LED4=1;LED5=1;LED6=1;LED7=1;LED8=1;LED9=1;LED10=1;
			}
			else if(Result > 683)
			{	LED3=0;LED4=0;LED5=1;LED6=1;LED7=1;LED8=1;LED9=1;LED10=1;
			}
			else if(Result > 568)
			{	LED3=0;LED4=0;LED5=0;LED6=1;LED7=1;LED8=1;LED9=1;LED10=1;
			}
			else if(Result > 455)
			{	LED3=0;LED4=0;LED5=0;LED6=0;LED7=1;LED8=1;LED9=1;LED10=1;
			}
			else if(Result > 341)
			{	LED3=0;LED4=0;LED5=0;LED6=0;LED7=0;LED8=1;LED9=1;LED10=1;
			}
			else if(Result > 227)
			{	LED3=0;LED4=0;LED5=0;LED6=0;LED7=0;LED8=0;LED9=1;LED10=1;
			}
			else if(Result > 113)
			{	LED3=0;LED4=0;LED5=0;LED6=0;LED7=0;LED8=0;LED9=0;LED10=1;
			}
			else
			{	LED3=0;LED4=0;LED5=0;LED6=0;LED7=0;LED8=0;LED9=0;LED10=0;
			}
	}		
	else
	{	
		LED9=0;LED8=0;LED7=0;LED6=0;LED5=0;LED4=0;LED3=0;

		if(TRIS_LED10 == 0)
		{	LED10=0;
			Nop();
			TRIS_LED10 = 1;	
		}
	}
}

#endif
