/*****************************************************************************
 *
 * Basic Explorer 16 I/O Mapping functionality for PPS peripherals.
 *
 *****************************************************************************
 * FileName:        iomapping.c
 * Dependencies:    system.h
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
 * Author               Date        Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Brant Ivey			3/14/06    Modified for PIC24FJ64GA004 family
 *****************************************************************************/

#include "system.h"

#if !defined(__PIC24FJ128GA010__) || !defined(__PIC24F32KA304__)
    #define IO_MAPPING_REQUIRED
#endif

void ioMap(){
    #if defined(IO_MAPPING_REQUIRED)
        #if defined(__PIC24FJ64GB004__)
            //INPUTS **********************
            
            //U2RX = RP19
            RPINR19bits.U2RXR = 19;
            //SDI2 = RP20
            RPINR22bits.SDI2R = 20;
            
            //OUTPUTS *********************
            
            //RP25 = U2TX   
            RPOR12bits.RP25R = U2TX_IO;
            //RP24 = SCK2
            RPOR12bits.RP24R = SCK2OUT_IO;
            //RP21 = SDO2
            RPOR10bits.RP21R = SDO2_IO;
       
       #elif defined(__PIC24FJ64GA004__)
            //INPUTS **********************
            
            //U2RX = RP19
            RPINR19bits.U2RXR = 19;
            //SDI2 = RP20
            RPINR22bits.SDI2R = 20;
            
            //OUTPUTS *********************
            
            //RP25 = U2TX   
            RPOR12bits.RP25R = U2TX_IO;
            //RP24 = SCK2
            RPOR12bits.RP24R = SCK2OUT_IO;
            //RP21 = SDO2
            RPOR10bits.RP21R = SDO2_IO;

          #elif defined(__PIC24FJ64GA104__)
            //INPUTS **********************
            
            //U2RX = RP19
            RPINR19bits.U2RXR = 19;
            //SDI2 = RP20
            RPINR22bits.SDI2R = 20;
            
            //OUTPUTS *********************
            
            //RP25 = U2TX   
            RPOR12bits.RP25R = U2TX_IO;
            //RP24 = SCK2
            RPOR12bits.RP24R = SCK2OUT_IO;
            //RP21 = SDO2
            RPOR10bits.RP21R = SDO2_IO;
         #elif defined(__PIC24FJ256GB110__) || defined(__PIC24FJ256GA110__) || defined(__PIC24FJ256GB210__)|| defined(__PIC24FJ128GA310__)
            //INPUTS **********************
            
            //U2RX = RP19
            RPINR19bits.U2RXR = 10;
            //SDI2 = RP20
            RPINR22bits.SDI2R = 26;

            //OUTPUTS *********************
            
            //RP25 = U2TX   
            RPOR8bits.RP17R = U2TX_IO;
            //RP24 = SCK2
            RPOR10bits.RP21R = SCK2OUT_IO;
            //RP21 = SDO2
            RPOR9bits.RP19R = SDO2_IO;
        #endif
    #endif
}


/*****************************************************************************
 * Function: lockIO
 *
 * Preconditions: None.
 *
 * Overview: This executes the necessary process to set the IOLOCK bit to lock
 * I/O mapping from being modified.
 *
 * Input: None.
 *
 * Output: None.
 *
 *****************************************************************************/

void lockIO(){
    #if defined(IO_MAPPING_REQUIRED)
        asm volatile ("mov #OSCCON,w1 \n"
        				"mov #0x46, w2 \n"
        				"mov #0x57, w3 \n"
        				"mov.b w2,[w1] \n"
        				"mov.b w3,[w1] \n"
        				"bset OSCCON, #6");
    
    #endif
}


/*****************************************************************************
 * Function: unlockIO
 *
 * Preconditions: None.
 *
 * Overview: This executes the necessary process to clear the IOLOCK bit to 
 * allow I/O mapping to be modified.
 *
 * Input: None.
 *
 * Output: None.
 *
 *****************************************************************************/

void unlockIO(){
    #if defined(IO_MAPPING_REQUIRED)
        asm volatile ("mov #OSCCON,w1 \n"
        				"mov #0x46, w2 \n"
        				"mov #0x57, w3 \n"
        				"mov.b w2,[w1] \n"
        				"mov.b w3,[w1] \n"
        				"bclr OSCCON, #6");
    #endif
}

