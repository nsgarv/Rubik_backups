/*****************************************************************************
 *
 * Explorer 16 Development Board Demo Program.
 * Modified for PIC24FJ64GA004/GB004/GA104 family with PPS.
 *
 *****************************************************************************
 * FileName:        PIC24ExplDemo.c
 * Dependencies:    system.h
 * Processor:       PIC24
 * Compiler:       	MPLAB C30 v3.00 or later
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
 * Ross Fosler	        XXX         ...	
 * Anton Alkhimenok     10/21/05    ...
 * Brant Ivey			3/14/06     Modified for PIC24FJ64GA004 family
 * C11842               5/27/2009   Added support for PIC24FJGB004, PIC24FJGA104
 * C11824               5/16/2010   Added support for PIC24FJ256GB210 PIM
 * Kevin Hengehold		4/27/2011	Added support for PIC24F32KA304 PIM
 * Naveen Raj           10/12/2011  Added support for PIC24FJ128GA310 PIM
 *****************************************************************************/

#include "system.h"

//----------- Setup configuration bits
#ifdef __PIC24FJ64GA004__ //Defined by MPLAB when using 24FJ64GA004 device
_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & COE_OFF & FWDTEN_OFF & ICS_PGx1) 
_CONFIG2( FCKSM_CSDCMD & OSCIOFNC_OFF & POSCMOD_XT & FNOSC_PRI & I2C1SEL_SEC & IOL1WAY_ON)

#elif __PIC24FJ64GB004__ //Defined by MPLAB when using 24FJ64GB004 device
_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & /*COE_OFF*/ FWDTEN_OFF & ICS_PGx1) 
_CONFIG2( FCKSM_CSDCMD & OSCIOFNC_OFF & POSCMOD_XT & FNOSC_PRI & I2C1SEL_SEC & IOL1WAY_ON)
_CONFIG3(SOSCSEL_SOSC & WUTSEL_LEG & WPDIS_WPDIS & WPCFG_WPCFGDIS)
_CONFIG4(DSWDTEN_OFF & RTCOSC_SOSC & DSWDTPS_DSWDTPS6 & DSWDTOSC_SOSC & DSBOREN_OFF)

#elif __PIC24FJ64GA104__ //Defined by MPLAB when using 24FJ64GA104 device
_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & /*COE_OFF*/ FWDTEN_OFF & ICS_PGx1) 
_CONFIG2( FCKSM_CSDCMD & OSCIOFNC_OFF & POSCMOD_XT & FNOSC_PRI & I2C1SEL_SEC & IOL1WAY_ON)
_CONFIG3(SOSCSEL_SOSC & WUTSEL_LEG & WPDIS_WPDIS & WPCFG_WPCFGDIS)
_CONFIG4(DSWDTEN_OFF & RTCOSC_SOSC & DSWDTPS_DSWDTPS6 & DSWDTOSC_SOSC & DSBOREN_OFF)

#elif __PIC24FJ256GB110__ //Defined by MPLAB when using 24FJ256GB110 device
_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & COE_OFF & FWDTEN_OFF & ICS_PGx2 ) 
_CONFIG2( FCKSM_CSDCMD & OSCIOFNC_OFF & POSCMOD_XT & FNOSC_PRI & DISUVREG_OFF & PLL_96MHZ_ON & IOL1WAY_ON)

#elif __PIC24FJ256GA110__ //Defined by MPLAB when using 24FJ256GA110 device
_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & COE_OFF & FWDTEN_OFF & ICS_PGx2 ) 
_CONFIG2( FCKSM_CSDCMD & OSCIOFNC_OFF & POSCMOD_XT & FNOSC_PRI & IOL1WAY_ON)

#elif defined (__PIC24F32KA304__) 	 //Defined by MPLAB when using 24F32KA304 device
_FBS(BWRP_OFF & BSS_OFF)
_FGS(GWRP_OFF & GSS0_OFF)
_FICD(ICS_PGx3)
_FDS(DSWDTPS_DSWDTPS0 & DSWDTOSC_LPRC & DSBOREN_OFF & DSWDTEN_OFF)
	#if __C30_VERSION__ > 325		//Work around for different names in C30 v3.25
	_FOSCSEL(FNOSC_PRI & LPRCSEL_HP & SOSCSRC_ANA & IESO_OFF)
	_FPOR(BOREN_BOR1 & PWRTEN_ON & I2C1SEL_SEC & BORV_V18 & MCLRE_ON)
	_FOSC(POSCMOD_HS & OSCIOFNC_ON & POSCFREQ_MS & SOSCSEL_SOSCLP & FCKSM_CSDCMD)
	_FWDT(FWDTEN_OFF & WINDIS_OFF & FWPSA_PR32 & WDTPS_PS1)
	#else
	_FOSCSEL(FNOSC_PRI & INTOSCSEL_ON & SOSCSEL0_ON & IESO_OFF)
	_FPOR(BOREN_BOR1 & PWRTEN_ON & I2C1SEL_SEC & BORV_V20 & MCLRE_ON)
	_FOSC(POSCMOD_HS & OSCIOFNC_ON & POSCFREQ_MS & SOSCSEL1_SOSCLP & FCKSM_CSDCMD)
	_FWDT(FWTEN_OFF & WINDIS_OFF & FWPSA_PR32 & WDTPS_PS1)
	#endif

#elif __PIC24FJ128GA310__ //Defined by MPLAB when using 24FJ128GA310 device

_CONFIG1(FWDTEN_WDT_DIS & ICS_PGx2 & JTAGEN_OFF & GCP_OFF & GWRP_OFF & LPCFG_ON & WINDIS_OFF & FWDTEN_WDT_DIS & FWPSA_PR32);  //we use PGEC2 for the REAL ICE
_CONFIG2(POSCMD_NONE   & IOL1WAY_ON & OSCIOFCN_ON & FCKSM_CSDCMD & FNOSC_FRC & IESO_ON );                                         // FRC Oscillator with PLL
_CONFIG3(BOREN_OFF & WPCFG_WPCFGDIS );
_CONFIG4(DSWDTEN_OFF & DSBOREN_OFF & DSWDTOSC_LPRC & DSWDTPS_DSWDTPSD);

#elif __PIC24FJ128GA010__  //Default to the PIC24FJ128GA010
_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & COE_OFF & FWDTEN_OFF & ICS_PGx2) 
_CONFIG2( FCKSM_CSDCMD & OSCIOFNC_OFF & POSCMOD_XT & FNOSC_PRI)

#elif __PIC24FJ256GB210__ //Defined by MPLAB when using 24FJ256GB210 device
_CONFIG1( WDTPS_PS32768 & FWPSA_PR128 & ALTVREF_ALTVREDIS & WINDIS_OFF & FWDTEN_OFF & ICS_PGx2 & GWRP_OFF & GCP_OFF & JTAGEN_OFF) 
_CONFIG2( POSCMOD_HS & IOL1WAY_ON & OSCIOFNC_OFF & OSCIOFNC_OFF & FCKSM_CSDCMD & FNOSC_PRI & PLL96MHZ_ON & PLLDIV_DIV2 & IESO_OFF)
_CONFIG3( WPFP_WPFP255 & SOSCSEL_SOSC & WUTSEL_LEG & WPDIS_WPDIS & WPCFG_WPCFGDIS & WPEND_WPENDMEM) 

#endif
//--------- End of configuation bits


#define     DISP_MAX        2
#define     DISP_HELLO      0
#define     DISP_CLOCK      2
#define     DISP_VOLTAGE    1

#if defined(__PIC24F32KA304__) 
	int monitor_display_state = 0x56;
#endif
unsigned char _display_state;

int main(void)
{
    // Start from displaying of PIC24 banners
	_display_state = DISP_HELLO;
	#ifdef __PIC24FJ128GA310__
		ANSA=0x0000;
		ANSDbits.ANSD6=0;
		ANSDbits.ANSD7=0;
	#endif


	#if defined(__PIC24F32KA304__)
	//set analog pins as digital
		#if __C30_VERSION__ >= 330	   //workaround for definition issue
			ANSA = 0x0000;
			ANSB = 0x0000;
			ANSC = 0x0000;
		#else
			ANSELA = 0x0000;
			ANSELB = 0x0000;
			ANSELC = 0x0000;
		#endif		
	#else
    // Setup PortA IOs as digital
    #if !(defined(__PIC24FJ256GB210__)||(__PIC24FJ128GA310__))
    AD1PCFG = 0xffff;
    #endif
    
	#endif
	//LED startup display - currently only implemented on PI24F32KA304
	#if defined(__PIC24F32KA304__) 
		LEDProcessEvent();
	#endif
	//IO Mapping
	ioMap();
	lockIO();

    // Setup SPI to communicate to EEPROM
    SPIMPolInit();

    // Setup EEPROM IOs
    EEPROMInit();

    // Setup the UART
    UART2Init();

	// Setup the timer
	TimerInit();
    
	// Setup the LCD
	mLCDInit();

	// Setup debounce processing
	BtnInit(); 

    // Setup the ADC
    ADCInit();

	// Setup the banner processing
	BannerStart();

	// Setup the RTCC
    RTCCInit();
   
	while (1) {
		LCDProcessEvents();
        ADCProcessEvents();

		if (TimerIsOverflowEvent()){

			// Button debounce processing
			BtnProcessEvents();
			// State dependent processing
			switch (_display_state) {
                // Show Microchip banners
				case DISP_HELLO: BannerProcessEvents(); break;
                // Show clock
				case DISP_CLOCK: TBannerProcessEvents(); break;
                // Show voltage and temperature
				case DISP_VOLTAGE: VBannerProcessEvents(); break;

                default: _display_state = DISP_HELLO;
			}// End of switch (_display_state)...

            // If Explorer16 button S4 is pressed show the next example
			if (BtnIsPressed(4)) {

                // Change state and clear display 
                if(!TBannerIsSetup()){
       				_display_state++;
                    if(_display_state > DISP_MAX)
                         _display_state = 0;

                    // Initialize state
                    switch (_display_state) {
                        // Microchip banners
                 	    case DISP_HELLO: BannerInit(); break;
                        // Clock
    				    case DISP_CLOCK: TBannerInit(); break;
                        // Voltage and temperature
	        			case DISP_VOLTAGE: VBannerInit(); break;
                        default:
                             _display_state = 0;
        		    }// End of switch (_display_state)...
                    mLCDClear();
                }else
                    TBannerNext();

			#if defined(__PIC24F32KA304__) 
				monitor_display_state = _display_state;
			#endif
                // wait for button released
                while (BtnIsPressed(4)){
					BtnProcessEvents();
				}
			}// End of 	if (BtnIsPressed(4)){...

            if(_display_state == DISP_CLOCK){
                // Explorer16 button S3
		#if defined(__PIC24F32KA304__) 
			LED3 = 0;
			LED4 = 0;
			LED5 = 0;
			LED6 = 0;
			LED7 = 0;
			LED8 = 0;
			LED9 = 0;
			if(TRIS_LED10 == 0)
			{	LED3 = 0;
				TRIS_LED10 = 1;
			}
		#endif
        		if (BtnIsPressed(1)){
                        TBannerSetup();
                    // wait for button released
                    while (BtnIsPressed(1))	BtnProcessEvents();
                }// End of if (BtnIsPressed(1 ...

                if(TBannerIsSetup()){
                    //Explorer16 button S6
	           		if (BtnIsPressed(2)) {
                        TBannerChangeField(1);
                        // wait for button released
                        while (BtnIsPressed(2))	BtnProcessEvents();
    		    	}// End of if (BtnIsPressed(2)){...
                    //Explorer16 button S5
	    		    if (BtnIsPressed(3)) {
                        // wait for button released
                        TBannerChangeField(0);
                        while (BtnIsPressed(3))	BtnProcessEvents();
        			}// End of if (BtnIsPressed(3)){...
                }// End of if(TBannerIsSetup( ...

            }// End of if(_display_state == DISP_SET_CLOCK ...



            if(_display_state == DISP_VOLTAGE){
		#if defined(__PIC24F32KA304__) 
			TRIS_LED10 = 0;
		#endif
                // Explorer16 button S6
        		if (BtnIsPressed(2)){
                    ADCSetFromMemory();
                    // wait for button released
                    while (BtnIsPressed(2)){
						BtnProcessEvents();
					}
                }// End of if (BtnIsPressed(2 ...
                // Explorer16 button S5
           		if (BtnIsPressed(3)){
                    ADCStoreTemperature();
                    // wait for button released
                    while (BtnIsPressed(3)){
						BtnProcessEvents();
					}
  		    	}// End of if (BtnIsPressed(3)){...

            }// End of if(_display_state ...




    	}// End of if (TimerIsOverflowEvent()...
    }// End of while(1)...
}// End of main()...
