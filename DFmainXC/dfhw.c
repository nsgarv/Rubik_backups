/*******************************************************************************
* Copyright (c) 2010 - 2011 Minnetronix, Inc.  All rights reserved.            *
*******************************************************************************/
/*******************************************************************************
*
*   $Source: DFHW.C $
*   $Revision: 1.11 $
*     Project: Balaton
*       $Date: 2011/09/07 12:27:40CDT $
*
*-------------------------------------------------------------------------------
*
*  This file is <IEC 62304 CLASS C>
*
* Description:  This is the hardware access support file for the
*               Balaton DFine ablation device.
*
*  Files and or functions marked with <IEC 62304 CLASS C> are considered
*     IEC 62304 Class 'C' and shall be treated accordingly. Changes to these
*     software components shall be tracked by issue. The altered code shall
*     be HUT (Heavy Unit Test) tested or data shall be provided of complete
*     testing during verification.
*
*******************************************************************************/

// htc.h is a HI-TECH file and for this project calls "pic24hj256gp610.h" which was added below.
//#include <htc.h>
//#include <dspic.h>
//#include "pic24hj256gp610.h"
//#include "dspic_my.h"
//#include "nvm_interface_my.h"
//#include "htc_my.h"
#include <xc.h>


// set the configuration bits

// FBS     Boot Segment Configuration Word
// BWRPU   Boot segment may be written
// BSSNB   No boot program Flash segment
// NORBS   No Boot RAM defined


//__CONFIG(FBS, BWRPU & BSSNB & NORBS);
#pragma config BWRP = WRPROTECT_OFF, BSS = NO_BOOT_CODE, RBS = NO_BOOT_RAM

// FSS     Secure Segment Configuration Word
// SWRPU   Secure segment may be written
// SSSNS   No secure program Flash segment

//__CONFIG(FSS, SWRPU & SSSNS);
#pragma config SWRP = WRPROTECT_OFF, SSS = NO_FLASH

// FGS     General Code Segment Configuration
// GWRU    User Program Memory Write Unprotected
// GCPU    User Program Memory Code Unprotected

//__CONFIG(FGS, GWRU & GCPU);
#pragma config GWRP = OFF, GSS = OFF

// FOSCSEL Oscillator Two-Speed Startup, Temperature Protection and
//         Initial Oscillator Source Selection
// IESOEN  Two-speed Oscillator Start-up Enabled
// TEMPDIS Temperature Protection Disabled
// OSC     Primary (XT, HS, EC) oscillator

//__CONFIG(FOSCSEL, IESOEN & TEMPDIS & OSC);
#pragma config IESO = ON, FNOSC = PRI

// FOSC     Oscillator Clock Switching Modes, OSC2 Pin Function and Primary Oscillator Modes
// CLKSWEN  Clock switching is enabled, Fail-Safe Clock Monitor is disabled
// OSC2OUT  OSC2 is clock output
// POSCXT   XT Crystal Oscillator mode

//__CONFIG(FOSC, CLKSWEN & OSC2OUT & POSCXT);
#pragma config FCKSM = CSECMD, OSCIOFNC = OFF, POSCMD = XT

// FWDT     Watchdog Timer
// WDTDIS   Watchdog Timer enabled/disabled by user software

//__CONFIG(FWDT, WDTDIS);
#pragma config FWDTEN = OFF

// FPOR     Motor Control and Power-on Reset Timer Value
// PWRT128  128 ms Power-on Reset Timer Value

//__CONFIG(FPOR, PWRT128);
#pragma config FPWRT = PWR128

// set PGC/PGD pair to 2 (vs 1, 3 or 4) - only debug lines supported by this hw
//
// FICD     ICD Config Word
// JTAGDIS  JTAG port is disabled
// ICS2     Communicate on PGC2/EMUC2 and PGD2/EMU2

//__CONFIG(FICD, JTAGDIS & ICS2);
#pragma config JTAGEN = OFF, ICS = PGD2


/*
#define BWRPU	0xFFFFFF	// Boot segment may be written
#define BSSNB	0xFFFFFF	// No boot program Flash segment

// expected data in config registers for POST
static const unsigned char config_data[7] = {	0xCF & BWRPU & BSSNB & NORBS,
						0xCF & SWRPU & SSSNS,
						0x07 & GWRU & GCPU,
						0xA7 & IESOEN & TEMPDIS & OSC,
						0xC7 & CLKSWEN & OSC2OUT & POSCXT, //IOL1WAY = 0
						0xDF & WDTDIS,
						0xE7 & PWRT128};		 // ALTI2C = 0, bit 5 - 7 = 1
*/
#include "DFine.h"
#include <stdio.h>
#include <string.h>


/* local function prototypes */
static U16 DAC_ADC_test(void);      /* DAC to RF ADC test */
static U8 wait_for_i2c(void);			/* wait for I2C1 master interrupt flag */


/*****************************************************************************
* NAME:  powercontrol()
*
* DESCRIPTION:  performs PI control of RF power.
*
* PARMETERS:
*   DACvalue       - Old DAC value scaled to 0 - FFFF
*   setPower       - Power setpoint scaled to 1 mW per bit
*   Power          - actual power from ADC scaled to 1 mW per bit
*
* NOTES: Should be executed once with actual power as initialization, since last data is used in routine.
*        Should be executed every 20 ms.
*
*
* RETURN VALUE:
*    New DAC value scaled to 0 - FFFF
*
* This function is <IEC 62304 CLASS C>
*
*****************************************************************************/
U16 powercontrol(U16 DACvalue, U16 setPower, S16 Power)         // PI control of RF Power
{										// DACvalue: 0xFFFF = 100%, setpoint and data 1 mW per bit
	static S16 oldPower = 0;
	S32 newDACvalue;

	newDACvalue = (S32)DACvalue + (S32)(((S16)setPower - Power) / 2)  + (S32)((oldPower - Power) / 6); // gain / 4
	oldPower = Power;

	if (newDACvalue < 0L)
			return 0;
	else if (newDACvalue > 0xFFFFL)
			return 0xFFFF;

	return (U16)newDACvalue;
}
/*****************************************************************************
* NAME:  post_rf()
*
* DESCRIPTION:  performs POST test of RF circuitry.
*
* PARMETERS:    eep - pointer to eeprom structure.
*
* NOTES: Applies RF power to internal 100 ohm resistor and measures V, I and P.
*        V/I is compared to 100 ohms and V * I is compared to P.
*        Tests watchdog (not implemented)
*        Uses about 1000 ms with no update of HC
*
* RETURN VALUE:
*    0 for OK, else error code
*
* This function is <IEC 62304 CLASS C>
*
*****************************************************************************/
U16 post_rf(struct EEPROMstruct *eep)								// do POST test of RF circuitry
{
	S16 data[4]; 								// RF ADC values
	S16 voltage, current, power, power2, impedance, wd_exp_pwr;
	U16 prim_volt, prim_curr, i, DACreadback, stat1, stat2;
	S32 power_delta;
    U32 impedance_scale;

	write_DAC(0, RFDAC_CTRL_RF_MOTOR_AND_RELAY_ALL_OFF);    // turn off RF relay, motor relay off
	KICK_THE_DOG;
	wait_for_20ms();							// sync to timer
	tone(BEEP_CHECK);

	if (   eep->RFpowerscale   > (RF_POWER_SCALE   * 11L) / 10L		// check for reasonable EEPROM values
		|| eep->RFpowerscale   < (RF_POWER_SCALE   *  9L) / 10L
		|| eep->RFvoltagescale > (RF_VOLTAGE_SCALE * 11) / 10
		|| eep->RFvoltagescale < (RF_VOLTAGE_SCALE *  9) / 10
		|| eep->RFcurrentscale > (RF_CURRENT_SCALE * 11) / 10
		|| eep->RFcurrentscale < (RF_CURRENT_SCALE *  9) / 10)
		return ERROR_EEPROM;

	wait_for_20ms();
	tone(BEEP_CHECK);
	if ( ! DAC_ADC_test())						// Check that the DAC and the ADC are OK
		return ERROR_DAC_ADC;
	write_DAC(RF_DAC_1W * 2, RFDAC_CTRL_RF_ON_MTRRLY_OFF_RFRLY_OFF);	// turn on RF with relays off, DAC at 920 *2 (~20VRMS ~4 W)
	write_LEDs(LED_ON | LED_RF);				// RF LED on
	wait_for_20ms();
	tone(BEEP_CHECK);
	wait_for_20ms();							// should stabilize in 40 ms
	tone(BEEP_CHECK);
	wait_for_20ms();							// should stabilize in 40 ms
	tone(BEEP_CHECK);
	read_RF_ADC(data);							// get 13-bit ADC data
	prim_volt = (U16)(((U32)get_ADC(6) * RF_PRIM_V_SCALE) / 4095L); // 25.38 V FS (Typ 5.88)
	prim_curr = (U16)(((U32)get_ADC(7) * RF_PRIM_I_SCALE) / 4095L); // 5.872 A FS (Typ .430)
	voltage = (S16)(((S32)data[0] * eep->RFvoltagescale) / 8191L);		// 37.74 V FS (Typ 9.39)
	current = (S16)(((S32)data[1] * eep->RFcurrentscale) / 8191L);		// 1.167 A FS (Typ .105)
	power = (S16)(((S32)data[2] * eep->RFpowerscale) / 8191L);			// 5.549 W FS (Typ .869)
	// original calculation not rendered correctly
   // impedance_scale = ((U32)(eep->RFvoltagescale) * 10000L) / (U32)(eep->RFcurrentscale);
   impedance_scale = ((U32)(eep->RFvoltagescale) * 10000L);
   impedance_scale /= (U32)(eep->RFcurrentscale);
	impedance = data[1] > 0 ? (((S32)data[0] * impedance_scale) / (S32)data[1]) / 100L : 9999; // (Typ 88.9)
	DACreadback = data[3];												// data[3] is typically 508 / 8191
	for ( i = 0; i < 50; i++) {					// wait 1000 ms for watchdog to expire, NOT!!
		stat1 = get_status();
		wait_for_20ms();
		tone(BEEP_CHECK);
		if ((stat1 & WATCH_DOG) == 0)
			break;
	}
	read_RF_ADC(data);							// get 13-bit ADC data
	wd_exp_pwr = (S16)(((S32)data[2] * eep->RFpowerscale) / 8191L);		// 5.549 W FS (Typ .869)
	KICK_THE_DOG;
	stat2 = get_status();
	wait_for_20ms();
	tone(BEEP_CHECK);
	wait_for_20ms();							// should stabilize in 40 ms
	tone(BEEP_CHECK);
	read_RF_ADC(data);							// get 13-bit ADC data
	power2 = (S16)(((S32)data[2] * eep->RFpowerscale) / 8191L);			// 5.549 W FS (Typ .869)
	write_DAC(0, RFDAC_CTRL_RF_OFF_MTRRLY_ON_RFRLY_OFF); 				// turn off RF, turn on motor relay
	wait_for_20ms();
	tone(BEEP_CHECK);
	write_DAC(0, RFDAC_CTRL_RF_OFF_MTRRLY_OFF_RFRLY_ON); 				// turn off RF, turn RF relay on, turn on motor relay
	write_LEDs(LED_ON);
	if (impedance > (TEST_IMPEDANCE + TEST_IMP_DELTA) * 10 || impedance < (TEST_IMPEDANCE - TEST_IMP_DELTA) * 10)
		return ERROR_IMPEDANCE;											// impedance out of wack
	power_delta = ((S32)voltage * (S32)current) / 100L - (S32)power;
	if (power_delta > TEST_POWER_DIFF || power_delta < -TEST_POWER_DIFF || power < 1000)	// power measurement bad
		return ERROR_POWER;
	if (wd_exp_pwr > 500 || (stat1 & WATCH_DOG) || !(stat2 & WATCH_DOG) || power2 < 1000)	// did watchdog behave badly?
		return ERROR_WATCHDOG;
	return 0;
}

#ifdef   DFTEST
/*****************************************************************************
* NAME:  post_rf_test_mode()
*
* DESCRIPTION:  performs POST test of RF circuitry.
*
* PARMETERS:    eep - pointer to eeprom structure.
*               postRF - pointer to structure to analyse data.
*
* NOTES: Applies RF power to internal 100 ohm resistor and measures V, I and P.
*        V/I is compared to 100 ohms and V * I is compared to P.
*        Tests watchdog (not implemented)
*        Uses about 1000 ms with no update of HC
*
* RETURN VALUE:
*    0 for OK, else error code
*
* This function is <IEC 62304 CLASS C>
*
*****************************************************************************/
U16 post_rf_test_mode(struct EEPROMstruct *eep, struct postRFstruct *postRF)
{
	S16 data[4]; 								// RF ADC values
	S16 voltage, current, power, power2, impedance, wd_exp_pwr;
	U16 prim_volt, prim_curr, i, DACreadback;
   U8 stat1, stat2;
   S32 power_delta;
   U32 impedance_scale;   // was: S32 impedance_scale;

   write_DAC(0, RFDAC_CTRL_RF_MOTOR_AND_RELAY_ALL_OFF);    // turn off RF relay, motor relay off
	KICK_THE_DOG;
	wait_for_20ms();							// sync to timer
	tone(BEEP_CHECK);

	if (   eep->RFpowerscale   > (RF_POWER_SCALE   * 11L) / 10L		// check for reasonable EEPROM values
		|| eep->RFpowerscale   < (RF_POWER_SCALE   *  9L) / 10L
		|| eep->RFvoltagescale > (RF_VOLTAGE_SCALE * 11) / 10
		|| eep->RFvoltagescale < (RF_VOLTAGE_SCALE *  9) / 10
		|| eep->RFcurrentscale > (RF_CURRENT_SCALE * 11) / 10
		|| eep->RFcurrentscale < (RF_CURRENT_SCALE *  9) / 10)
		return ERROR_EEPROM;

	wait_for_20ms();
	tone(BEEP_CHECK);
	if ( ! DAC_ADC_test())						// Check that the DAC and the ADC are OK
		return ERROR_DAC_ADC;
	write_DAC(RF_DAC_1W * 2, RFDAC_CTRL_RF_ON_MTRRLY_OFF_RFRLY_OFF);	// turn on RF with relays off, DAC at 920 *2 (~20VRMS ~4 W)
	write_LEDs(LED_ON | LED_RF);				// RF LED on
	wait_for_20ms();
	tone(BEEP_CHECK);
	wait_for_20ms();							// should stabilize in 40 ms
	tone(BEEP_CHECK);
	wait_for_20ms();							// should stabilize in 40 ms
	tone(BEEP_CHECK);
	read_RF_ADC(data);							// get 13-bit ADC data
	prim_volt = (U16)(((U32)get_ADC(6) * RF_PRIM_V_SCALE) / 4095L); // 25.38 V FS (Typ 5.88)
	prim_curr = (U16)(((U32)get_ADC(7) * RF_PRIM_I_SCALE) / 4095L); // 5.872 A FS (Typ .430)
	voltage = (S16)(((S32)data[0] * eep->RFvoltagescale) / 8191L);		// 37.74 V FS (Typ 9.39)
	current = (S16)(((S32)data[1] * eep->RFcurrentscale) / 8191L);		// 1.167 A FS (Typ .105)
	power = (S16)(((S32)data[2] * eep->RFpowerscale) / 8191L);			// 5.549 W FS (Typ .869)
	// original calculation not rendered correctly
	// impedance_scale = ((U32)(eep->RFvoltagescale) * 10000L) / (U32)(eep->RFcurrentscale);
   impedance_scale = ((U32)(eep->RFvoltagescale) * 10000L);
   impedance_scale /=  (U32)(eep->RFcurrentscale);
	impedance = data[1] > 0 ? (((S32)data[0] * impedance_scale) / (S32)data[1]) / 100L : 9999; // (Typ 88.9)
	DACreadback = data[3];	            		// data[3] is typically 508 / 8191

   for (i = 0; i < 50; i++)
   {	// wait 1000 ms for watchdog to expire, NOT!!
      stat1 = get_status();
      wait_for_20ms();
      tone(BEEP_CHECK);
      if ((stat1 & WATCH_DOG) == 0)
      {
         postRF->wd_expired_time = i;
         break;
      }
   }
   read_RF_ADC(data);							// get 13-bit ADC data
   // 5.549 W FS (Typ .869)
   wd_exp_pwr = (S16)(((S32)data[2] * eep->RFpowerscale) / 8191L);
   KICK_THE_DOG;
   stat2 = get_status();
   wait_for_20ms();
   tone(BEEP_CHECK);
   wait_for_20ms();     // should stabilize in 40 ms
   tone(BEEP_CHECK);
   read_RF_ADC(data);   // get 13-bit ADC data
   // 5.549 W FS (Typ .869)
   power2 = (S16)(((S32)data[2] * eep->RFpowerscale) / 8191L);
   // turn off RF, turn on motor relay
   write_DAC(0, RFDAC_CTRL_RF_OFF_MTRRLY_ON_RFRLY_OFF);
   wait_for_20ms();
   tone(BEEP_CHECK);
   // turn off RF, turn RF relay on, turn on motor relay
   write_DAC(0, RFDAC_CTRL_RF_OFF_MTRRLY_OFF_RFRLY_ON);
   write_LEDs(LED_ON);

   power_delta = (((S32)voltage * (S32)current) / (S32)100L) - (S32)power;

   if (postRF != NULL)
   {
      postRF->data[0] = data[0];
      postRF->data[1] = data[1];
      postRF->data[2] = data[2];
      postRF->data[3] = data[3];
      postRF->prim_volt = prim_volt;
      postRF->prim_curr = prim_curr;
      postRF->voltage = voltage;
      postRF->current = current;
      postRF->power   = power;
      postRF->impedance_scale = impedance_scale;
      postRF->impedance = impedance;
      postRF->power_delta = power_delta;
      postRF->wd_expired_time *= (U16)20;
      postRF->wd_expired_power = wd_exp_pwr;
      postRF->wd_power = power2;
      postRF->wd_stat1 = stat1;
      postRF->wd_stat2 = stat2;
   }

   // impedance out of wack
   if (impedance > (TEST_IMPEDANCE + TEST_IMP_DELTA) * 10
         || impedance < (TEST_IMPEDANCE - TEST_IMP_DELTA) * 10)
		return ERROR_IMPEDANCE;

   // power measurement bad
   if (power_delta > TEST_POWER_DIFF
         || power_delta < -TEST_POWER_DIFF
            || power < 1000)
		return ERROR_POWER;

   // did watchdog behave badly?
   if (wd_exp_pwr > 500 || (stat1 & WATCH_DOG)
         || !(stat2 & WATCH_DOG) || power2 < 1000)
      return ERROR_WATCHDOG;

   return 0;
}
#endif   // ifdef   DFTEST

/*****************************************************************************
* NAME:  DAC_ADC_test()
*
* DESCRIPTION:  performs POST test of DAC and RF ADC.
*
* PARMETERS:       - NONE
*
* NOTES: Outputs data on DAC and reads back on ADC for reasonable values.
*
* RETURN VALUE:
*    1 for OK, 0 for fault
*
*****************************************************************************/
#define DAC_ADC_FS	4005							// DAC to ADC full scale default value

static U16 DAC_ADC_test(void)						// NEW test
{
	U16 outp;
	S16 data[4], old = 0, exp_data;

	write_DAC(0xFFF, RFDAC_CTRL_RF_MOTOR_AND_RELAY_ALL_OFF); // turn off RF relay, motor relay off, max DAC
	wait_for_20ms();
	tone(BEEP_CHECK);
	for (outp = 0xFFF << 1; outp; ) {
		outp = outp >> 1;
		write_DAC(outp, RFDAC_CTRL_RF_MOTOR_AND_RELAY_ALL_OFF); // turn off RF relay, motor relay off
		wait_for_20ms();
		read_RF_ADC(data);							// get 13-bit ADC data
		if (outp == 0xFFF) {						// check full scale for +/- 2%
			if (data[3] > DAC_ADC_FS + DAC_ADC_FS / 50 || data[3] < DAC_ADC_FS - DAC_ADC_FS / 50)
				return 0;
			outp = 0x1000;							// do 0x800 next time
			exp_data = data[3] >> 1;				// next expected data
		} else {									// check last value +/- 1% +/- 8 counts
			if (data[3] > old + 2)					// data should not increase
				return 0;
			if (data[3] > old - exp_data + exp_data / 100 + 4
					|| data[3] < old - exp_data - exp_data / 100 - 4) {	// data decrease OK
				return 0;
			}
			if (old > 0)
				old = old >> 1;
			else
				old = 0;
			if (data[3] > old + old / 100 + 9 || data[3] < old - old / 100 - 9)
				return 0;
			exp_data = exp_data >> 1;				// next expected data
		}
		old = data[3];
		tone(BEEP_CHECK);
		KICK_THE_DOG;								// update watchdog
	}
	return 1;
}
/*****************************************************************************
* NAME:  post_supply_volts()
*
* DESCRIPTION:  performs POST test of power supply voltages.
*
* PARMETERS:       - NONE
*
* NOTES: Measures power supply voltages and compares to +/- 10%.
*        Measures PCB temperature and test for 15 - 50C.
*
* RETURN VALUE:
*    0 for OK, else error code
*
*****************************************************************************/
U16 post_supply_volts(void)					// do POST check of supply voltages and on board temperature
{
	S16 volt_24, volt_12, volt_5, volt_12neg, data, temperature;   // voltages in mv, temp in 1/10 degC

	volt_24 = (S16)(((U32)get_ADC(0) * 31878L) / 4095L);			// FS = (86.6 + 10) / 10 * 3300 mv
	volt_12 = (S16)(((U32)(data = get_ADC(2)) * 15939L) / 4095L);	// FS = (38.3 + 10) / 10 * 3300 mv
	data = (S16)(((U32)data * (U32)(15939L * 50L)) / (U32)((4095L / 2L) * 65L));
	volt_12neg = data - (S16)(((U32)get_ADC(1) * (3300L * 165L)) / (4095L * 65L));
	volt_5 = (S16)(((U32)get_ADC(3) * 6600L) / 4095L);				// FS = (10 + 10) / 10 * 3300 mv
	temperature = (S16)(((U32)get_ADC(4) * 6600L) / 4095L) - 2732; 	// FS = 2 * 330 K
	if (volt_24 > 24000 + (S16)((24000L * (U32)TEST_SUPPLY_TOL) / 100L)
		 || volt_24 < 24000 - (S16)((24000L * (U32)TEST_SUPPLY_TOL) / 100L))
		return ERROR_24V;
	if (volt_12 > 12000 + (S16)((12000L * (U32)TEST_SUPPLY_TOL) / 100L)
		 || volt_12 < 12000 - (S16)((12000L * (U32)TEST_SUPPLY_TOL) / 100L))
		return ERROR_12V;
	if (volt_5 > 5000 + (S16)((5000L * (U32)TEST_SUPPLY_TOL) / 100L)
		 || volt_5 < 5000 - (S16)((5000L * (U32)TEST_SUPPLY_TOL) / 100L))
		return ERROR_5V;
	if (volt_12neg > 12000 + (S16)((12000L * (U32)TEST_SUPPLY_TOL) / 100L)
		 || volt_12neg < 12000 - (S16)((12000L * (U32)TEST_SUPPLY_TOL) / 100L))
		return ERROR_12VNEG;
	if (temperature < TEST_LO_TEMP * 10 || temperature > TEST_HI_TEMP * 10)
		return ERROR_TEMP;
	return 0;
}
/*****************************************************************************
* NAME:  post_spi()
*
* DESCRIPTION:  performs POST test of circuitry on SPI interface.
*
* PARMETERS:       - NONE
*
* NOTES: Checks reference voltage feedback for +/- 2%.
*        Checks unused inputs for < 4 mV.
*        Checks CJC for 15 - 50C.
*
* RETURN VALUE:
*    0 for OK, else error code
*
* This function is <IEC 62304 CLASS C>
*
*****************************************************************************/
U16 post_spi(void)							// do POST check on SPI system
{
	U16 data[8], i;							// 8 data points

	wait_for_20ms();						// sync to timer
	read_SPI_ADC(0);						// start SPI
	for (i = 0; i < 8; i++) {
		wait_for_20ms();												// wait a little
		data[i] = (U16)(((U32)read_SPI_ADC(i + 1) * 1022L)/ 4095L);		// scale data to 1022 mV FS
		tone(BEEP_CHECK);
		KICK_THE_DOG;													// update watchdog
	}
	if (data[3] < 210 || data[3] > 218)									// check reference +/- 2% (214mv)
		return ERROR_SPI;
	if (data[4] < TEST_LO_TEMP * 10 || data[4] > TEST_HI_TEMP * 10)		// CJC should be 15 - 50 C
		return ERROR_CJC;
	if (data[6] > 4 || data[7] > 4)										// unused inputs should be < 4 mV
		return ERROR_SPI;
	return 0;
}
/*****************************************************************************
* NAME:  read_SPI_ADC()
*
* DESCRIPTION:  reads SPI ADC.
*
* PARMETERS:
*   nextinput      - number for next input to read (0 - 7)
*
* NOTES: Next input number needs to be sent out when this input is read.
*        Should be executed every 20 ms
*
* RETURN VALUE:
*    ADC value scaled to 0 - FFF
*
*****************************************************************************/
U16 read_SPI_ADC(U8 nextinput)              // read SPI ADC ~50 us at 300 kHz clock
{											// have to supply next input number
	U16 data;

	_LATD4 = 1;								// cs mux high to receive serial bits
	_LATD5 = 1;								// cs ADC high for safety
	_LATD5 = 0;								// cs ADC low for start convert
	_LATD5 = 0;								// wait a little to shift data
	_LATD5 = 0;
	_LATD5 = 0;
	_LATD5 = 0;
	data = SPI1BUF;							// clean up buffer for safety
	SPI1BUF = SPI1BUF = nextinput | 0x8;	// shift out next address
	while (!_SPIRBF)
		;									// wait for data back
	data = (SPI1BUF >> 2) & 0x0FFF;         // clean up read data bits
	_LATD5 = 1;								// cs ADC high
	_LATD4 = 0;								// cs mux low to latch bits
	return data;
}
/*****************************************************************************
* NAME:  read_RF_ADC()
*
* DESCRIPTION:  reads RF ADC.
*
* PARMETERS:
*   data[]         - array with room for 4 data points
*
* NOTES: Reads RF Voltage, RF Current, RF Power and RF DAC feedback.
*        Data is stored in array scaled as 13 bits + sign (C000 - 1FFF)
*        Zero scale is -27 mV and full scale is 10194 mV through 200 ohms.
*        Uses CPLD, should not be used in interrupt routine
*
* RETURN VALUE:
*    NONE
*
* This function is <IEC 62304 CLASS C>
*
*****************************************************************************/
void read_RF_ADC(S16 data[])              // read RF ADC, four values
{										  // ~18 us
	U8 tmp, i = 0;
	S16 adcdata;

	_LATC3 = 1;			// make sure no write
	TRISE = ~0x0000;	// turn off outputs
	LATA &= ~0x001F;    // clear address bits for low DAC
	_LATA3 = 1;			// adress A2D low

	do {
		_LATD3 = 1;			// ADC CONV = 1
		_LATD0 = (i > 1);	// ADC A0 = 0/1
		_LATD1 = 1;			// ADC CS = 1
		for (tmp = 0; tmp < 10; tmp++)
		_LATD2 = 1;			// ADC RD = 1 + 500 ns delay
		_LATD3 = 0;			// ADC CONV = 0 ; start convert
		_LATD3 = 0;			// ADC CONV = 0 ; start convert
		_LATD3 = 1;			// ADC CONV = 1
		_LATD3 = 1;			// ADC CONV = 1
		_LATD3 = 1;			// ADC CONV = 1
		_LATD3 = 1;			// ADC CONV = 1
		_LATD3 = 1;			// ADC CONV = 1
		_LATD3 = 1;			// ADC CONV = 1

		while (_RG14)
			;
		_LATD1 = 0;			// ADC CS = 0
		do {
			_LATD2 = 0;			// ADC RD = 0

			_LATA0 = 0;			// adress lo DAC
			_LATC4 = 0;			// PLD Read
			_LATC4 = 0;
			_LATC4 = 0;
			adcdata = PORTE & 0x00FF;
			_LATA0 = 1;			// adress hi DAC
			_LATA0 = 1;			// adress hi DAC
	 		adcdata |= (PORTE & 0x3F) << 8;
			_LATD2 = 1;			// ADC RD = 1
			if (adcdata & 0x2000) // fix sign
				adcdata |= 0xC000;
			data[i] = adcdata - RF_ADC_OFFSET; // subtract some offset
		} while (++i & 1);
		_LATD1 = 1;			// ADC CS = 1
	} while ( i < 4);

	_LATC4 = 1;
}
/*****************************************************************************
* NAME:  write_DAC()
*
* DESCRIPTION:  Writes RF DAC and RF control byte.
*
* PARMETERS:
*   data           - DAC data scaled 0 - FFF
*   control        - control byte for RF and relays
*
* NOTES: See HW documentation for control byte.
*        Uses CPLD, should not be used in interrupt routine
*
*
*
* RETURN VALUE:
*    NONE
*
* This function is <IEC 62304 CLASS C>
*
*****************************************************************************/
void write_DAC(U16 data, U8 control)  // write DAC and control byte
{
	_LATC4 = 1;			// make sure no read
	LATA &= ~0x001F;    // clear address bits for low DAC
	LATE = data;		// high byte is ignored
	TRISE = ~0x00FF;	// turn on outputs
	_LATC3 = 0;
	_LATC3 = 1;
	_LATA0 = 1;			// adress hi DAC
	LATE = data >> 8;		// low byte
	_LATC3 = 0;
	_LATC3 = 1;
	_LATA0 = 0;			// adress control byte
	_LATA2 = 1;			// adress control byte
	LATE = control;		// control byte
	_LATC3 = 0;
	_LATC3 = 1;

}
/*****************************************************************************
* NAME:  tone_gen()
*
* DESCRIPTION:  Sets beep frequency and output mode for loudspeaker.
*
* PARMETERS:
*   freq           - beep frequency in Hz
*   mode           - beep mode; 0 = mute, 1 = vol control, 2 = high
*
* NOTES: Frequency should be 200 - 4000 Hz; can NOT be 0.
*        Uses CPLD, should not be used in interrupt routine
*
* RETURN VALUE:
*    NONE
*
*****************************************************************************/
void tone_gen(U16 freq, U8 mode)          // set beep frequency and mode
{
	_LATA12 = 0;			// beep hi off
	_LATA13 = 0;			// beep lo off
	_LATC4 = 1;			// make sure no read
	LATA &= ~0x001F;    // clear address bits for low DAC
	_LATA1 = 1;			// sel 0x02; low beep period
	freq = (U16)(12000000L / (U32)freq);
	LATE = freq;		// high byte is ignored
	TRISE = ~0x00FF;	// turn on outputs
	_LATC3 = 0;
	_LATC3 = 1;
	_LATA0 = 1;			// adress hi DAC
	LATE = freq >> 8;		// low byte
	_LATC3 = 0;
	_LATC3 = 1;
	_LATA13 = ((mode & BEEP_VOLUMEC) != 0); 	// Volume controlled beep
	_LATA12 = ((mode & BEEP_HIGH) != 0);		// No volume hi fault beep
}
/*****************************************************************************
* Tone Generation System.
*
* DESCRIPTION:  Four "tunes" are defined by structures: tone1 - tone4.
*               Routine tone() is used to intiate and time the "tunes".
*
*****************************************************************************/
struct tonestruct {
	U16 freq;			// frequency
	U16 ontime;			// ontime
	U16 offtime;		// offtime
	U16 repeats;		// repeat count
	U16 mode;			// beep mode (1,2) or 0 for end
};

static const struct tonestruct tone1[] = {	{ 250, 100,   0, 1, BEEP_VOLUMEC},  	// POST tone
											{ 300, 100,   0, 1, BEEP_VOLUMEC},
											{ 400, 100,   0, 1, BEEP_VOLUMEC},
											{ 500, 100,   0, 1, BEEP_VOLUMEC},
											{ 530, 100,   0, 1, BEEP_VOLUMEC},
											{ 600, 100,   0, 1, BEEP_VOLUMEC},
											{ 750, 100,   0, 1, BEEP_VOLUMEC},
											{ 900, 100, 100, 1, BEEP_VOLUMEC},
											{1000, 100, 900, 5, BEEP_VOLUMEC},
											{1000, 500,   0, 1, BEEP_VOLUMEC},
											{   0,   0,   0, 0, 0}};
static const struct tonestruct tone2[] = {	{ 300, 200, 1800, ~0, BEEP_VOLUMEC},	// RF ON tone
											{   0,   0,   0, 0, 0}};

static const struct tonestruct tone3[] = {	{2100, 200, 100, 1, BEEP_HIGH},  		// FAULT tone
											{1400, 200, 300, ~0, BEEP_HIGH},
											{   0,   0,   0, 0, 0}};

static const struct tonestruct tone4[] = {	{ 750, 200, 100, 1, BEEP_VOLUMEC},  	// REPLACE tone
											{ 600, 200, 2800, ~0, BEEP_VOLUMEC},
											{   0,   0,   0, 0, 0}};

static const struct tonestruct tone5[] = {	{ 750, 200, 100, 1, BEEP_VOLUMEC},  	// REPLACE1 tone
											{   0,   0,   0, 0, 0}};

static const struct tonestruct tone6[] = {	{ 600,  40, 460, ~0, BEEP_VOLUMEC},  	// MOTOR tone
											{   0,   0,   0, 0, 0}};

static const struct tonestruct tone7[] = {	{ 300, 100,  100, 1, BEEP_VOLUMEC},		// MOTOR OFF tone
											{   0,   0,   0, 0, 0}};

static const struct tonestruct tone8[] = {	{ 750, 200, 100, 1, BEEP_VOLUMEC},  	// CHG_CARTR tone
											{ 600, 200,   0, 1, BEEP_VOLUMEC},
											{   0,   0,   0, 0, 0}};

static const struct tonestruct tone9[] = {	{ 600, 200,  1800, ~0, BEEP_VOLUMEC},	// TEMPERATURE WARNING tone
											{   0,   0,   0, 0, 0}};

static const struct tonestruct click[] = {	{1000,  40, 100, 1, BEEP_VOLUMEC},  	// CLICK tone
											{   0,   0,   0, 0, 0}};

static const struct tonestruct * const tonesp[] = {tone1, tone2, tone3, tone4, tone5, tone6, tone7, tone8, tone9, click};	// array of pointers to structures
/*****************************************************************************
* NAME:  tone()
*
* DESCRIPTION:  Handles "tune" generation for loudspeaker.
*
* PARMETERS:
*   mode           - "tune" number or stop ot check timing
*
* NOTES: "Tunes" and other modes are defined in include file.
*        Should be executed with parameter BEEP_CHECK every 20 ms
*        Uses CPLD, should not be used in interrupt routine
*
* RETURN VALUE:
*    1 if tone is active, 0 if tone is off
*
*****************************************************************************/
U16 tone(U16 mode)									// handle tone generation
{
	static U16 timer = 0, curmode = 0, repeat_cnt = 0, tone_on = 0;
	static const struct tonestruct *tsp = NULL;

	if ( mode == BEEP_INIT) {					// initialize everything
		tone_gen(1,0);
		timer = curmode = repeat_cnt = tone_on = 0;
		tsp = NULL;

	} else if (mode <= BEEP_CLICK) {			// start tone sequences
		tsp = tonesp[mode];						// start with first tone
		tone_gen(tsp->freq, tsp->mode);
		timer = tsp->ontime / (1000 / SPS);		// time is in 20 ms increment
		repeat_cnt = tsp->repeats;				// save repeat count
		tone_on = 1;							// tone is on at first

	} else if (mode == BEEP_CHECK && timer && --timer == 0) {	// time is in 20 ms increment
		if (tone_on && tsp->offtime) {
			tone_gen(1,0);								// stop
			timer = tsp->offtime / (1000 / SPS);		// time is in 20 ms increment
			tone_on = 0;								// tone off
		} else if (repeat_cnt && --repeat_cnt > 0) {	// repeat
			tone_gen(tsp->freq, tsp->mode);
			timer = tsp->ontime / (1000 / SPS);		// time is in 20 ms increment
			tone_on = 1;							// tone is on at first
		} else if ((++tsp)->mode) {					// next tone
			tone_gen(tsp->freq, tsp->mode);
			timer = tsp->ontime / (1000 / SPS);		// time is in 20 ms increment
			repeat_cnt = tsp->repeats;				// save repeat count
			tone_on = 1;							// tone is on at first
		} else
			tone_gen(1,0);							// done, stop
	}
	return (timer !=0);								// tell if tones are on or off
}
/*****************************************************************************
* NAME:  get_switches()
*
* DESCRIPTION:  reads front panel switches and handswitches.
*
* PARMETERS:       NONE
*
* NOTES: Front panel switches are debounced and has repeat function.
*        Uses CPLD, should not be used in interrupt routine
*
* RETURN VALUE:
*    Bit pattern defined in include file
*
* This function is <IEC 62304 CLASS C>
*
*****************************************************************************/
static U16 recorded_buttons = 0;

U16 get_switches(void)              // read switches and debounce
{
	static U8 olddata = 0, count = 0;
	static U16 oldhandswitches = 0;
	U16 handswitches, frontpanelswitches, newswitches;

	_LATC3 = 1;          // make sure no write
	TRISE = ~0x0000;	// turn off outputs
	LATA &= ~0x001F;    // clear address bits
	_LATA2 = 1;			// sel 0x06; switches
	_LATA1 = 1;
	_LATC4 = 0;			// PLD Read
	_LATC4 = 0;
	_LATC4 = 0;

   // ENTER_BUTTON, STOP_BUTTON, MODE_BUTTON value 0 - not available.
   // REMIX_BUTTON also known as RESET_BUTTON
   // use this code for debugging:
   // frontpanelswitches = ~PORTE;
   // frontpanelswitches &= (RESET_BUTTON | UP_BUTTON | DN_BUTTON);
   frontpanelswitches = ~PORTE & (ENTER_BUTTON | REMIX_BUTTON | STOP_BUTTON | MODE_BUTTON | UP_BUTTON | DN_BUTTON);

   _LATC4 = 1;
	newswitches = (~PORTF << 8);				// hand switches
	recorded_buttons |= (frontpanelswitches | ((newswitches & (RFON_BUTTON | MOTOR_BUTTON)) >> 4));
	newswitches &= RFON_BUTTON;					// ignore motor button
	if (newswitches & ~oldhandswitches & RFON_BUTTON) // get on edge of RF button
		handswitches = newswitches | RFON_BUTTONE;
	else if (~newswitches & oldhandswitches & RFON_BUTTON) // get off edge of RF button
		handswitches = newswitches | RFON_BUTTOFF;
	else
		handswitches = newswitches/* & ~oldhandswitches*/; // get regular RF button
	oldhandswitches = newswitches;
	if (frontpanelswitches & ENTER_BUTTON)		// but use enter button instead
		handswitches |= ENTERM_BUTTON;			// used to run motor
	if (frontpanelswitches != olddata) { 		// debounce
		olddata = frontpanelswitches;
		count = 0;
		return handswitches;
	}
	if ((frontpanelswitches & (ENTER_BUTTON | REMIX_BUTTON | STOP_BUTTON | MODE_BUTTON | UP_BUTTON | DN_BUTTON)) && count == 25) {
		count -= 5;
		return handswitches | frontpanelswitches;
	}
	if (count == 0xFF || ++count != 3)
		return handswitches;
	return handswitches | frontpanelswitches;  	// Max 7 switches
}
/*****************************************************************************
* NAME:  get_recorded_buttons()
*
* DESCRIPTION:  returns recorded buttons pressed since last call.
*
* PARMETERS:       NONE
*
* NOTES: Resets old value.
*        ENTER, REMIX and STOP buttons have masks of include file.
*        EBLUE and ORANGE buttons have masks of include file >> 4.
*
* RETURN VALUE:
*    Buttons pressed since last call
*
*****************************************************************************/
U16 get_recorded_buttons(void)
{
	U16 returnvalue = recorded_buttons;

	recorded_buttons = 0;
	return returnvalue;
}
/*****************************************************************************
* NAME:  get_raw_switches()
*
* DESCRIPTION:  reads front panel switches and handswitches.
*
* PARMETERS:       NONE
*
* NOTES: No debounce or repeat function.
*        Uses CPLD, should not be used in interrupt routine
*
* RETURN VALUE:
*    Bit pattern defined in include file
*
* This function is <IEC 62304 CLASS C>
*
*****************************************************************************/
U16 get_raw_switches(void)              // read switches, no debounce
{
	U16 handswitches, frontpanelswitches;

	_LATC3 = 1;           // make sure no write
	TRISE = ~0x0000;	// turn off outputs
	LATA &= ~0x001F;    // clear address bits
	_LATA2 = 1;			// sel 0x06; switches
	_LATA1 = 1;
	_LATC4 = 0;			// PLD Read
	_LATC4 = 0;
	_LATC4 = 0;
	frontpanelswitches = ~PORTE & 0x007F;
	handswitches = (~PORTF & 3) << 8;
	_LATC4 = 1;
	return handswitches | frontpanelswitches;  	// Max 7 switches
}
/*****************************************************************************
* NAME:  get_status()
*
* DESCRIPTION:  reads status bits from CPLD.
*
* PARMETERS:       NONE
*
* NOTES: Status bits are pump limits, syring present, motor relay and watch dog.
*        Uses CPLD, should not be used in interrupt routine
*
* RETURN VALUE:
*    Bit pattern defined in include file
*
* This function is <IEC 62304 CLASS C>
*
*****************************************************************************/
U8 get_status(void)              // read status bits from CPLD
{
	U8 data;

	_LATC3 = 1;          // make sure no write
	TRISE = ~0x0000;	// turn off outputs
	LATA &= ~0x001F;    // clear address bits
	_LATA2 = 1;			// sel 0x07; status
	_LATA1 = 1;
	_LATA0 = 1;
	_LATC4 = 0;			// PLD Read
	_LATC4 = 0;
	_LATC4 = 0;
	_LATC4 = 0;
	data = PORTE;		// Max 8 bits
	_LATC4 = 1;
	return data ^ 0x07;	// invert switches
}
/*****************************************************************************
* NAME:  write_LEDs()
*
* DESCRIPTION:  Writes to LED control register.
*
* PARMETERS:
*   bits           - bit pattern
*
* NOTES: Bits are defined in include file.
*        Uses CPLD, should not be used in interrupt routine
*
* RETURN VALUE:
*    NONE
*
*****************************************************************************/
void write_LEDs(U8 bits)		// write LEDs
{								// D0 = green; D1 = red; D2 = blue
	_LATC4 = 1;          // make sure no read
	LATA &= ~0x001F;    // clear address bits for low DAC
	_LATA2 = 1;			// sel 0x05; LEDs
	_LATA0 = 1;
	LATE = bits;		// high byte is ignored
	TRISE = ~0x00FF;	// turn on outputs
	_LATC3 = 0;			// write pulse
	_LATC3 = 1;
}
/*****************************************************************************
* NAME:  hw_init()
*
* DESCRIPTION:  Initializes CPU registers.
*
* PARMETERS:  NONE
*
* NOTES: Initializes PLL, I/O registers, timers, ADC, SPIs, I2C, UARTs, DMA.
*
* RETURN VALUE:
*    NONE
*
*****************************************************************************/
// oscillator configuration defines
/*
#define OSCCON_H		0x743		// address of high byte of OSCCON
#define OSCCON_L		0x742		// address of low byte of OSCCON
#define OSC_EXT_PLL		3			// external clock with PLL
#define OSC_UNLOCK_H1	0x78
#define OSC_UNLOCK_H2	0x9a
#define OSC_UNLOCK_L1	0x46
#define OSC_UNLOCK_L2	0x57
#define OSC_OSWEN		0			// OSCCON, bit 0
*/

void hw_init(void)				// intialize chip hardware
{
	U16 tmp;
	// re-configure the oscillator for 40 MHz
	// set the clock pre- and post-divisors to 2
	CLKDIV = 0;
	// set the PLL multiplier to 40  ((((8 MHz / 2) * 40) / 2) / 2)
	PLLFBD = 38;
	// now unlock OSCCON and switch to the external clock

/*	
#asm
	mov.b #OSC_EXT_PLL, w0
	mov #OSCCON_H, w1			; point to the high byte
	mov #OSC_UNLOCK_H1, w2		; first unlock code
	mov #OSC_UNLOCK_H2, w3		; second unlock code
	mov.b w2, [w1]				; unlock OSCCON high byte
	mov.b w3, [w1]
	mov.b w0, [w1]				; write the new clock configuration

	mov #OSCCON_L, w1			; point to the low byte
	mov #OSC_UNLOCK_L1, w2		; first unlock code
	mov #OSC_UNLOCK_L2, w3		; second unlock code
	mov.b w2, [w1]				; unlock OSCCON low byte
	mov.b w3, [w1]
	bset.b OSCCON_L, #OSC_OSWEN	; enable the clock switch
#endasm
*/

   //#define OSC_EXT_PLL		3			// external clock with PLL
	asm("mov.b #3, w0");
	
   //#define OSCCON_H		0x743		   // address of high byte of OSCCON
	asm("mov #0x743, w1");              //; point to the high byte
	
   //#define OSC_UNLOCK_H1	0x78
	asm("mov #0x78, w2");               //; first unlock code
	
   //#define OSC_UNLOCK_H2	0x9a
	asm("mov #0x9a, w3");               //; second unlock code
	
	asm("mov.b w2, [w1]");              //; unlock OSCCON high byte
	asm("mov.b w3, [w1]");
	asm("mov.b w0, [w1]");              //; write the new clock configuration

   //#define OSCCON_L		0x742		   // address of low byte of OSCCON
	asm("mov #0x742, w1");              //; point to the low byte
	
   //#define OSC_UNLOCK_L1	0x46
	asm("mov #0x46, w2");               //; first unlock code
	
   //#define OSC_UNLOCK_L2	0x57
	asm("mov #0x57, w3");               //; second unlock code
	
	asm("mov.b w2, [w1]");              //; unlock OSCCON low byte
	asm("mov.b w3, [w1]");
	
   //#define OSCCON_L		0x742		   // address of low byte of OSCCON
   //#define OSC_OSWEN		0			   // OSCCON, bit 0
	asm("bset.b 0x742, #0");            //; enable the clock switch

        // now wait for PLL lock
	while (!_LOCK)
		;

	// determine analog input, 1 = digital, 0 = analog
	AD1PCFGH = ~0x00C0; // 23,22 analog
	AD1PCFGL = AD2PCFGL = ~0x00DF; // 7,6,4,3,2,1,0 analog

	// port A
	LATA = 0x0000;   // Initialize all low
	ODCA = 0x0000;   // no OC
	TRISA = ~0x703F; // 14,13,12,5,4,3,2,1,0 outputs

	// port B
	LATB = 0x0000;   // Initialize all low
	TRISB = ~0xFF20; // 15,14,13,12,11,10,9,8,5 outputs

	// port C
	LATC = 0x0000;   // Initialize all low
	TRISC = ~0x001E; // 4,3,2,1 outputs

	// port D
	LATD = 0xFF3F;   // Initialize all high except 7,6
	ODCD = 0x000F;   // 3,2,1,0 OC
	TRISD = ~0xFFFF; // 15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 outputs

	// port E
	LATE = 0x0000;	 // Initalize all low
	TRISE = ~0x0000; // All inputs for now

	// port F
	LATF = 0x0000;   // Initialize all low
	ODCF = 0x0000;   // no OC
	TRISF = ~0x3020; // 13,12,5 outputs

	// port G
	LATG = 0x0201;   // Initialize all low, except 9,0
	ODCG = 0x0000;   // No OC
	TRISG = ~0xB201; // 15,13,12,9,0 output

	// set T1 for 20 ms sample rate
	T1CON = 0x0020;    // prescale / 64
	PR1 = (12500 - 1); // divide 40 MHz by 12500 * 64 = 50 Hz
	TMR1 = 0;
	_T1IF = 0;
	//T1ON = 1;
	//T1CONbits.TON = 1;
	_TON = 1;

	_INT4EP = 0;        // INT4 is used for display
	_INT4IP2 = 0;       // INT4 low priority
	_INT4IP1 = 0;
	_INT4IP0 = 1;

	// SPI 1
	SPI1CON1 = 0x0538; // 16-bit, pos edge out, master, 312 kHz
	SPI1CON2 = 0x0000; // no frame sync
	SPI1STAT = 0x8000; // Enable SPI1

	// SPI 2
	SPI2CON1 = 0x0020; // 8-bit, master, 75 kHz
					   // clock idle low, data changing on positive edge of clock
	SPI2CON2 = 0x0000; // no frame sync
	SPI2STAT = 0x8000; // Enable SPI2

	// I2C
	I2C1BRG = 0x018B; // 100 kHz
	I2C1CON = 0x8000; // enable I2C 1

	// ADC
	AD1CON1 = 0x04E0; // 12-bit auto-convert
	AD1CON2 = 0x6000; // Ext REF
	AD1CON3 = 0x0204; // Sample 3TAD, TAD = 5 * TCY = 125ns; TAD >= 117.6 ns; Tsamp >= 3 * TAD
	AD1CON4 = 0x0000; // For DMA only
	AD1CHS123 = 0x0000; // Not for 12-bit
	AD1CHS0 = 0x0000; // Start at AN0
	AD1CSSH = 0x0000; // Scan channels high
	AD1CSSL = 0x001F; // Scan channels low
	AD1CON1 = 0x84E0; // Start, 12-bit auto-convert

	// UART
	U1MODE = 0x8000;  // Turn on UART1, Lo speed BRG
	U1BRG = 259;      // 9600 baud, 0.16 % error
	U1STA = 0x0400;   // enable output
	tmp = U1RXREG;    // avoid garbage

   /*
    * U2 UART (and its DMA) need to be setup in gDFDisplyInit(), not here,
    * because the display outputs text when it powers up that gets in the way.
    * See comments in that function for more details.
    */

	// DMA for UARTs
	DMA0CON = 0x6001; // DMA off, byte, to peripheral, one shot
	DMA0REQ = 0x000C; // UART1TX
	DMA0PAD = 0x0224; // U1TXREG

	DMA1CON = 0x4000; // DMA off, byte, from peripheral, continous (circular buffer)
	DMA1REQ = 0x000B; // UART1RX
	DMA1PAD = 0x0226; // U1RXREG
	//DMA1_CHEN = 0;
	DMA1CONbits.CHEN = 0;
	DMA1STA = RX1DMABUF - DMARAM; // DMA RAM address offset 100
	DMA1CNT = RX1DMABUFSIZ - 1; // 16 chars max, circular buffer
	_DMA1IF = 0;		  // clear flag

	// DMA for SPI2
	DMA4CON = 0x6001; // DMA off, byte, to peripheral, one shot
	DMA4REQ = 0x0021; // SPI2
	DMA4PAD = 0x0268; // SPI2BUF
	DMA5CON = 0x4001; // DMA off, byte, from peripheral, one shot
	DMA5REQ = 0x0021; // SPI2
	DMA5PAD = 0x0268; // SPI2BUF
}

/*****************************************************************************
* NAME:  get_ADC()
*
* DESCRIPTION:  reads CPU ADC.
*
* PARMETERS:
*   ch             - CPU input number (0 - 31); 0,1,2,3,4,6,7,22,23 used
*
* NOTES:
*
* RETURN VALUE:
*    ADC value scaled to 0 - FFF
*
*****************************************************************************/
U16 get_ADC(U8 ch)			// get analog signal converted to 12 bits
{							// conversion time is ~2.5 us
	AD1CHS0 = ch;
	_SAMP = 1;
	while (_SAMP)		// wait for sample period
		;
	//while (!AD1CON_CONV)	// wait for conversion
	while (!_DONE)	// wait for conversion
		;
	return (ADC1BUF0);
}

/*****************************************************************************
* NAME:  read_eeprom()
*
* DESCRIPTION:  reads data from EEPROM - ATMEL AT24C1024B - 128Kbytes
*
* PARMETERS:
*  adr             - address in EEPROM (0 - 1FFFF)
*  bp              - buffer to store data in
*  cnt             - number of bytes to read
*
* NOTES:  Reads serial number, calibration data etc. from EEPROM
*         bp needs to have room for cnt bytes.
*
* RETURN VALUE:
*    0 if succesful, -1 if failure
*
*****************************************************************************/
S16 read_eeprom (U32 adr, U8 *bp, U8 cnt)	      // read bytes from EEPROM
{
   // clear interupt flag
   _MI2C1IF = 0;

   // initiate start event
   //I2C1_SEN = 1;
   _SEN = 1;
   // wait for done
   if (wait_for_i2c() == 0)
   {
      // err - not done within time period
      return -1;
   }

   /*
   * device address: upper nibble must be 0xAx
   * lower nibble
   * 0x80 - 1 --\
   * 0x40 - 0    \ upper nibble 0xAx
   * 0x20 - 1    /
   * 0x10 - 0 --/
   * 0x08 - A2 --\
   * 0x04 - A1 ---- device address/eeprom select (up to 4)
   * 0x02 - P0 -- 17th bit of word address
   * 0x01 - write (0) or read (1)
   */
   if ((adr & 0x10000) == 0)
   {
      I2C1TRN = 0xA0;
   }
   else
   {
      // Start seq (0xA0) + Device Address(0x00) + P0(0x02) + write(0x00)
      I2C1TRN = 0xA2;
   }
   // wait for done
   if (wait_for_i2c() == 0)
   {
      // err - not done within time period
      return -2;
   }
   // make sure ACK status is 0
   //if (I2C1_ACKSTAT)
   if (_ACKSTAT)
   {
      // no ACK - initiate stop event and return err
      //I2C1_PEN = 1;
      _PEN = 1;
      return -3;
	}

   // send upper byte Memory Address
   I2C1TRN = (U8) (adr >> 8);
   // wait for done
   if (wait_for_i2c() == 0)
   {
      // err - not done within time period
      return -4;
   }
   // make sure ACK status is 0
   //if (I2C1_ACKSTAT)
   if (_ACKSTAT)
   {
      // no ACK - initiate stop event and return err
      //I2C1_PEN = 1;
      _PEN = 1;
      return -5;
   }

   // send lower byte Memory Address
   I2C1TRN = (U8) adr;
   // wait for done
   if (wait_for_i2c() == 0)
   {
      // err - not done within time period
      return -6;
   }
   // make sure ACK status is 0
   //if (I2C1_ACKSTAT)
   if (_ACKSTAT)
   {
      // no ACK - initiate stop event and return err
      //I2C1_PEN = 1;
      _PEN = 1;
      return -7;
   }

   //I2C1_RSEN = 1;		// initiate repeat start
   _RSEN = 1;		// initiate repeat start
   // wait for done
   if (wait_for_i2c() == 0)
   {
      // err - not done within time period
      return -8;
   }

   // Set Start seq 0xA0/Device Address 0x0CH/P0 0x02H bit/Read 0x1H bit
   if ((adr & 0x00010000) == 0)
   {
      // Start seq (0xA0) + Device Address(0x00) + P0(0x00) + read(0x01)
      I2C1TRN = 0xA1;
   }
   else
   {
      // Start seq (0xA0) + Device Address(0x00) + P0(0x02) + read(0x01)
      I2C1TRN = 0xA3;		// send Device Address + read
   }
   // wait for done
   if (wait_for_i2c() == 0)
   {
      // err - not done within time period
      return -9;
   }
   // make sure ACK status is 0
   //if (I2C1_ACKSTAT)
   if (_ACKSTAT)
   {
      // no ACK - initiate stop event and return err
      //I2C1_PEN = 1;
      _PEN = 1;
      return -10;
   }

   // loop through and pick up all data
   while (cnt--)
   {
		//I2C1_RCEN = 1;		// enable receive
		_RCEN = 1;		// enable receive
      // wait for done
      if (wait_for_i2c() == 0)
      {
         // err - not done within time period
         return -11;
      }
      // pick up data
		*bp++ = I2C1RCV;
      // send NO ACK if last byte
		_ACKDT = (cnt == 0);
      // initiate ACK event
		_ACKEN = 1;
      // wait for done
      if (wait_for_i2c() == 0)
      {
         // err - not done within time period
         return -12;
      }
	}

   _PEN = 1;		// initiate stop event
   // wait for done
   if (wait_for_i2c() == 0)
   {
      // err - not done within time period
      return -13;
   }

   return 0;
}

#ifdef   DFTEST
/*****************************************************************************
* NAME:  write_eeprom()
*
* DESCRIPTION:  Writes one byte of data to EEPROM - ATMEL AT24C1024B - 128Kb
*
* PARMETERS:
*  adr             - address in EEPROM (0 - 1FFFF)
*  data            - data to write
*
* NOTES:  Routine does not wait for done. Needs delay between uses.
*         For use in test and maufacturing software only.
*         Function used by DFTEST in calibration routine and in eeprom test.
*
* RETURN VALUE:
*    data if succesful, -1 if failure
*
*****************************************************************************/
S16 write_eeprom (U32 adr, U8 data)       // write one byte to EEPROM
{
   // returns <0 or -1 if error

   // clear interupt flag
   MI2C1IF = 0;

   // initiate start event
	I2C1_SEN = 1;
   // wait for done
   if (wait_for_i2c() == 0)
   {
      // err - not done within time period
      return -1;
   }

   /*
   * device address: upper nibble must be 0xAx
   * lower nibble
   * 0x80 - 1 --\
   * 0x40 - 0    \ upper nibble 0xAx
   * 0x20 - 1    /
   * 0x10 - 0 --/
   * 0x08 - A2 --\
   * 0x04 - A1 ---- device address/eeprom select (up to 4)
   * 0x02 - P0 -- 17th bit of word address
   * 0x01 - write (0) or read (1)
   */
   if ((adr & 0x00010000) == 0)
   {
      // Start seq (0xA0) + Device Address(0x00) + P0(0x00) + write(0x00)
      I2C1TRN = 0xA0;
   }
   else
   {
      // Start seq (0xA0) + Device Address(0x00) + P0(0x02) + write(0x00)
      I2C1TRN = 0xA2;
   }
   // wait for done
   if (wait_for_i2c() == 0)
   {
      // err - not done within time period
      return -2;
   }
   // make sure ACK status is 0
   if (I2C1_ACKSTAT)
   {
      // no ACK - initiate stop event and return err
      I2C1_PEN = 1;
      return -3;
   }

   // send upper byte Memory Address
   I2C1TRN = (U8) (adr >> 8);
   // wait for done
   if (wait_for_i2c() == 0)
   {
      // err - not done within time period
      return -4;
   }
   // make sure ACK status is 0
   if (I2C1_ACKSTAT)
   {
      // no ACK - initiate stop event and return err
      I2C1_PEN = 1;
      return -5;
   }

   // send lower byte Memory Address
   I2C1TRN = (U8) adr;
   // wait for done
   if (wait_for_i2c() == 0)
   {
      // err - not done within time period
      return -6;
   }
   // make sure ACK status is 0
   if (I2C1_ACKSTAT)
   {
      // no ACK - initiate stop event and return err
      I2C1_PEN = 1;
      return -7;
   }

   // send Memory Data
   I2C1TRN = data;
   if (wait_for_i2c() == 0)
   {
      // err - not done within time period
      return -8;
   }
   // make sure ACK status is 0
   if (I2C1_ACKSTAT)
   {
      // no ACK - initiate stop event and return err
      I2C1_PEN = 1;
      return -9;
   }

   // initiate stop event
   I2C1_PEN = 1;
   if (wait_for_i2c() == 0)
   {
      // err - not done within time period
      return -10;
   }

   return data;
}
#endif /* #ifdef DFTEST */


/*****************************************************************************
* NAME:  wait_for_i2c()
*
* DESCRIPTION:  Waits for I2C but to be done.
*
* PARMETERS:  NONE
*
* NOTES:  Routine waits for I2C interrupt flag.
*         Clears flag if set.
*
* RETURN VALUE:
*    1 if succesful, 0 if failure
*
*****************************************************************************/
static U8 wait_for_i2c (void)// wait for I2C1 master interrupt flag
{
	U16 timer = 1000;		// max wait should be about 125 us

	while ( !_MI2C1IF)    // wait for done; 5 cycle loop 125 ns
   {
		if (--timer == 0)
         return 0;
   }
   _MI2C1IF = 0;			// clear interupt flag
	return 1;
}

/*****************************************************************************
* NAME:  wait_for_20ms()
*
* DESCRIPTION:  Waits for 20 ms time tic.
*
* PARMETERS:  NONE
*
* NOTES:  Routine waits for timer 1 interrupt flag.
*         Timer 1 is configured for 20 ms.
*         Clears interrupt flag.
*
* RETURN VALUE:
*    NONE
*
*****************************************************************************/
void wait_for_20ms(void)
{
	while (!_T1IF)
		;
	_T1IF = 0;
}
/****************************************************************************/
/*       TABLE OF T TYPE TC TEMPERATURES IN 0.1 DEG C UNITS					*/
/*       EVERY 32 MICROVOLTS FROM 0 TO 8128 MICROVOLTS.						*/
/*																			*/
/*     REF:   OMEGA: REVISED THERMOCOUPLE REFERENCE TABLES	    			*/
/*              Type T, Reference Tables N.I.S.T. Monograph 175				*/
/*              Revised to ITS-90.											*/
/*																			*/
/****************************************************************************/
static const U16 tcinterptable[] = {

 	   0,	/*	  0 v =    0 uV	(0)*/
	   8,	/*	  1 v =   32 uV	(8)*/
	  16,	/*	  2 v =   64 uV	(8)*/
	  25,	/*	  3 v =   96 uV	(9)*/
	  33,	/*	  4 v =  128 uV	(8)*/
	  41,	/*	  5 v =  160 uV	(8)*/
	  49,	/*	  6 v =  192 uV	(8)*/
	  57,	/*	  7 v =  224 uV	(8)*/
	  66,	/*	  8 v =  256 uV	(9)*/
	  74,	/*	  9 v =  288 uV	(8)*/
	  82,	/*	 10 v =  320 uV	(8)*/
	  90,	/*	 11 v =  352 uV	(8)*/
	  98,	/*	 12 v =  384 uV	(8)*/
	 106,	/*	 13 v =  416 uV	(8)*/
	 114,	/*	 14 v =  448 uV	(8)*/
	 123,	/*	 15 v =  480 uV	(9)*/
	 131,	/*	 16 v =  512 uV	(8)*/
	 139,	/*	 17 v =  544 uV	(8)*/
	 147,	/*	 18 v =  576 uV	(8)*/
	 155,	/*	 19 v =  608 uV	(8)*/
	 163,	/*	 20 v =  640 uV	(8)*/
	 171,	/*	 21 v =  672 uV	(8)*/
	 179,	/*	 22 v =  704 uV	(8)*/
	 187,	/*	 23 v =  736 uV	(8)*/
	 195,	/*	 24 v =  768 uV	(8)*/
	 203,	/*	 25 v =  800 uV	(8)*/
	 211,	/*	 26 v =  832 uV	(8)*/
	 219,	/*	 27 v =  864 uV	(8)*/
	 226,	/*	 28 v =  896 uV	(7)*/
	 234,	/*	 29 v =  928 uV	(8)*/
	 242,	/*	 30 v =  960 uV	(8)*/
	 250,	/*	 31 v =  992 uV	(8)*/
	 258,	/*	 32 v = 1024 uV	(8)*/
	 266,	/*	 33 v = 1056 uV	(8)*/
	 274,	/*	 34 v = 1088 uV	(8)*/
	 281,	/*	 35 v = 1120 uV	(7)*/
	 289,	/*	 36 v = 1152 uV	(8)*/
	 297,	/*	 37 v = 1184 uV	(8)*/
	 305,	/*	 38 v = 1216 uV	(8)*/
	 312,	/*	 39 v = 1248 uV	(7)*/
	 320,	/*	 40 v = 1280 uV	(8)*/
	 328,	/*	 41 v = 1312 uV	(8)*/
	 336,	/*	 42 v = 1344 uV	(8)*/
	 343,	/*	 43 v = 1376 uV	(7)*/
	 351,	/*	 44 v = 1408 uV	(8)*/
	 359,	/*	 45 v = 1440 uV	(8)*/
	 367,	/*	 46 v = 1472 uV	(8)*/
	 374,	/*	 47 v = 1504 uV	(7)*/
	 382,	/*	 48 v = 1536 uV	(8)*/
	 390,	/*	 49 v = 1568 uV	(8)*/
	 397,	/*	 50 v = 1600 uV	(7)*/
	 405,	/*	 51 v = 1632 uV	(8)*/
	 412,	/*	 52 v = 1664 uV	(7)*/
	 420,	/*	 53 v = 1696 uV	(8)*/
	 428,	/*	 54 v = 1728 uV	(8)*/
	 435,	/*	 55 v = 1760 uV	(7)*/
	 443,	/*	 56 v = 1792 uV	(8)*/
	 450,	/*	 57 v = 1824 uV	(7)*/
	 458,	/*	 58 v = 1856 uV	(8)*/
	 465,	/*	 59 v = 1888 uV	(7)*/
	 473,	/*	 60 v = 1920 uV	(8)*/
	 480,	/*	 61 v = 1952 uV	(7)*/
	 488,	/*	 62 v = 1984 uV	(8)*/
	 495,	/*	 63 v = 2016 uV	(7)*/
	 503,	/*	 64 v = 2048 uV	(8)*/
	 510,	/*	 65 v = 2080 uV	(7)*/
	 518,	/*	 66 v = 2112 uV	(8)*/
	 525,	/*	 67 v = 2144 uV	(7)*/
	 533,	/*	 68 v = 2176 uV	(8)*/
	 540,	/*	 69 v = 2208 uV	(7)*/
	 547,	/*	 70 v = 2240 uV	(7)*/
	 555,	/*	 71 v = 2272 uV	(8)*/
	 562,	/*	 72 v = 2304 uV	(7)*/
	 570,	/*	 73 v = 2336 uV	(8)*/
	 577,	/*	 74 v = 2368 uV	(7)*/
	 584,	/*	 75 v = 2400 uV	(7)*/
	 592,	/*	 76 v = 2432 uV	(8)*/
	 599,	/*	 77 v = 2464 uV	(7)*/
	 606,	/*	 78 v = 2496 uV	(7)*/
	 614,	/*	 79 v = 2528 uV	(8)*/
	 621,	/*	 80 v = 2560 uV	(7)*/
	 628,	/*	 81 v = 2592 uV	(7)*/
	 636,	/*	 82 v = 2624 uV	(8)*/
	 643,	/*	 83 v = 2656 uV	(7)*/
	 650,	/*	 84 v = 2688 uV	(7)*/
	 657,	/*	 85 v = 2720 uV	(7)*/
	 665,	/*	 86 v = 2752 uV	(8)*/
	 672,	/*	 87 v = 2784 uV	(7)*/
	 679,	/*	 88 v = 2816 uV	(7)*/
	 686,	/*	 89 v = 2848 uV	(7)*/
	 694,	/*	 90 v = 2880 uV	(8)*/
	 701,	/*	 91 v = 2912 uV	(7)*/
	 708,	/*	 92 v = 2944 uV	(7)*/
	 715,	/*	 93 v = 2976 uV	(7)*/
	 722,	/*	 94 v = 3008 uV	(7)*/
	 729,	/*	 95 v = 3040 uV	(7)*/
	 737,	/*	 96 v = 3072 uV	(8)*/
	 744,	/*	 97 v = 3104 uV	(7)*/
	 751,	/*	 98 v = 3136 uV	(7)*/
	 758,	/*	 99 v = 3168 uV	(7)*/
	 765,	/*	100 v = 3200 uV	(7)*/
	 772,	/*	101 v = 3232 uV	(7)*/
	 779,	/*	102 v = 3264 uV	(7)*/
	 786,	/*	103 v = 3296 uV	(7)*/
	 793,	/*	104 v = 3328 uV	(7)*/
	 800,	/*	105 v = 3360 uV	(7)*/
	 808,	/*	106 v = 3392 uV	(8)*/
	 815,	/*	107 v = 3424 uV	(7)*/
	 822,	/*	108 v = 3456 uV	(7)*/
	 829,	/*	109 v = 3488 uV	(7)*/
	 836,	/*	110 v = 3520 uV	(7)*/
	 843,	/*	111 v = 3552 uV	(7)*/
	 850,	/*	112 v = 3584 uV	(7)*/
	 857,	/*	113 v = 3616 uV	(7)*/
	 864,	/*	114 v = 3648 uV	(7)*/
	 871,	/*	115 v = 3680 uV	(7)*/
	 878,	/*	116 v = 3712 uV	(7)*/
	 885,	/*	117 v = 3744 uV	(7)*/
	 892,	/*	118 v = 3776 uV	(7)*/
	 899,	/*	119 v = 3808 uV	(7)*/
	 906,	/*	120 v = 3840 uV	(7)*/
	 913,	/*	121 v = 3872 uV	(7)*/
	 919,	/*	122 v = 3904 uV	(6)*/
	 926,	/*	123 v = 3936 uV	(7)*/
	 933,	/*	124 v = 3968 uV	(7)*/
	 940,	/*	125 v = 4000 uV	(7)*/
	 947,	/*	126 v = 4032 uV	(7)*/
	 954,	/*	127 v = 4064 uV	(7)*/
	 961,	/*	128 v = 4096 uV	(7)*/
	 968,	/*	129 v = 4128 uV	(7)*/
	 975,	/*	130 v = 4160 uV	(7)*/
	 981,	/*	131 v = 4192 uV	(6)*/
	 988,	/*	132 v = 4224 uV	(7)*/
	 995,	/*	133 v = 4256 uV	(7)*/
	1002,	/*	134 v = 4288 uV	(7)*/
	1009,	/*	135 v = 4320 uV	(7)*/
	1016,	/*	136 v = 4352 uV	(7)*/
	1023,	/*	137 v = 4384 uV	(7)*/
	1029,	/*	138 v = 4416 uV	(6)*/
	1036,	/*	139 v = 4448 uV	(7)*/
	1043,	/*	140 v = 4480 uV	(7)*/
	1050,	/*	141 v = 4512 uV	(7)*/
	1056,	/*	142 v = 4544 uV	(6)*/
	1063,	/*	143 v = 4576 uV	(7)*/
	1070,	/*	144 v = 4608 uV	(7)*/
	1077,	/*	145 v = 4640 uV	(7)*/
	1084,	/*	146 v = 4672 uV	(7)*/
	1090,	/*	147 v = 4704 uV	(6)*/
	1097,	/*	148 v = 4736 uV	(7)*/
	1104,	/*	149 v = 4768 uV	(7)*/
	1110,	/*	150 v = 4800 uV	(6)*/
	1117,	/*	151 v = 4832 uV	(7)*/
	1124,	/*	152 v = 4864 uV	(7)*/
	1131,	/*	153 v = 4896 uV	(7)*/
	1137,	/*	154 v = 4928 uV	(6)*/
	1144,	/*	155 v = 4960 uV	(7)*/
	1151,	/*	156 v = 4992 uV	(7)*/
	1158,	/*	157 v = 5024 uV	(7)*/
	1164,	/*	158 v = 5056 uV	(6)*/
	1171,	/*	159 v = 5088 uV	(7)*/
	1178,	/*	160 v = 5120 uV	(7)*/
	1184,	/*	161 v = 5152 uV	(6)*/
	1191,	/*	162 v = 5184 uV	(7)*/
	1198,	/*	163 v = 5216 uV	(7)*/
	1204,	/*	164 v = 5248 uV	(6)*/
	1211,	/*	165 v = 5280 uV	(7)*/
	1217,	/*	166 v = 5312 uV	(6)*/
	1224,	/*	167 v = 5344 uV	(7)*/
	1231,	/*	168 v = 5376 uV	(7)*/
	1237,	/*	169 v = 5408 uV	(6)*/
	1244,	/*	170 v = 5440 uV	(7)*/
	1250,	/*	171 v = 5472 uV	(6)*/
	1257,	/*	172 v = 5504 uV	(7)*/
	1264,	/*	173 v = 5536 uV	(7)*/
	1270,	/*	174 v = 5568 uV	(6)*/
	1277,	/*	175 v = 5600 uV	(7)*/
	1283,	/*	176 v = 5632 uV	(6)*/
	1290,	/*	177 v = 5664 uV	(7)*/
	1296,	/*	178 v = 5696 uV	(6)*/
	1303,	/*	179 v = 5728 uV	(7)*/
	1309,	/*	180 v = 5760 uV	(6)*/
	1316,	/*	181 v = 5792 uV	(7)*/
	1322,	/*	182 v = 5824 uV	(6)*/
	1329,	/*	183 v = 5856 uV	(7)*/
	1336,	/*	184 v = 5888 uV	(7)*/
	1342,	/*	185 v = 5920 uV	(6)*/
	1349,	/*	186 v = 5952 uV	(7)*/
	1355,	/*	187 v = 5984 uV	(6)*/
	1362,	/*	188 v = 6016 uV	(7)*/
	1368,	/*	189 v = 6048 uV	(6)*/
	1375,	/*	190 v = 6080 uV	(7)*/
	1381,	/*	191 v = 6112 uV	(6)*/
	1388,	/*	192 v = 6144 uV	(7)*/
	1394,	/*	193 v = 6176 uV	(6)*/
	1400,	/*	194 v = 6208 uV	(6)*/
	1407,	/*	195 v = 6240 uV	(7)*/
	1413,	/*	196 v = 6272 uV	(6)*/
	1420,	/*	197 v = 6304 uV	(7)*/
	1426,	/*	198 v = 6336 uV	(6)*/
	1433,	/*	199 v = 6368 uV	(7)*/
	1439,	/*	200 v = 6400 uV	(6)*/
	1446,	/*	201 v = 6432 uV	(7)*/
	1452,	/*	202 v = 6464 uV	(6)*/
	1458,	/*	203 v = 6496 uV	(6)*/
	1465,	/*	204 v = 6528 uV	(7)*/
	1471,	/*	205 v = 6560 uV	(6)*/
	1478,	/*	206 v = 6592 uV	(7)*/
	1484,	/*	207 v = 6624 uV	(6)*/
	1490,	/*	208 v = 6656 uV	(6)*/
	1497,	/*	209 v = 6688 uV	(7)*/
	1503,	/*	210 v = 6720 uV	(6)*/
	1510,	/*	211 v = 6752 uV	(7)*/
	1516,	/*	212 v = 6784 uV	(6)*/
	1522,	/*	213 v = 6816 uV	(6)*/
	1529,	/*	214 v = 6848 uV	(7)*/
	1535,	/*	215 v = 6880 uV	(6)*/
	1541,	/*	216 v = 6912 uV	(6)*/
	1548,	/*	217 v = 6944 uV	(7)*/
	1554,	/*	218 v = 6976 uV	(6)*/
	1560,	/*	219 v = 7008 uV	(6)*/
	1567,	/*	220 v = 7040 uV	(7)*/
	1573,	/*	221 v = 7072 uV	(6)*/
	1579,	/*	222 v = 7104 uV	(6)*/
	1586,	/*	223 v = 7136 uV	(7)*/
	1592,	/*	224 v = 7168 uV	(6)*/
	1598,	/*	225 v = 7200 uV	(6)*/
	1605,	/*	226 v = 7232 uV	(7)*/
	1611,	/*	227 v = 7264 uV	(6)*/
	1617,	/*	228 v = 7296 uV	(6)*/
	1624,	/*	229 v = 7328 uV	(7)*/
	1630,	/*	230 v = 7360 uV	(6)*/
	1636,	/*	231 v = 7392 uV	(6)*/
	1642,	/*	232 v = 7424 uV	(6)*/
	1649,	/*	233 v = 7456 uV	(7)*/
	1655,	/*	234 v = 7488 uV	(6)*/
	1661,	/*	235 v = 7520 uV	(6)*/
	1667,	/*	236 v = 7552 uV	(6)*/
	1674,	/*	237 v = 7584 uV	(7)*/
	1680,	/*	238 v = 7616 uV	(6)*/
	1686,	/*	239 v = 7648 uV	(6)*/
	1692,	/*	240 v = 7680 uV	(6)*/
	1698,	/*	241 v = 7712 uV	(6)*/
	1705,	/*	242 v = 7744 uV	(7)*/
	1711,	/*	243 v = 7776 uV	(6)*/
	1717,	/*	244 v = 7808 uV	(6)*/
	1723,	/*	245 v = 7840 uV	(6)*/
	1730,	/*	246 v = 7872 uV	(7)*/
	1736,	/*	247 v = 7904 uV	(6)*/
	1742,	/*	248 v = 7936 uV	(6)*/
	1748,	/*	249 v = 7968 uV	(6)*/
	1754,	/*	250 v = 8000 uV	(6)*/
	1761,	/*	251 v = 8032 uV	(7)*/
	1767,	/*	252 v = 8064 uV	(6)*/
	1773,	/*	253 v = 8096 uV	(6)*/
	1779,	/*	254 v = 8128 uV	(6)*/
	1785,	/*	255 v = 8160 uV	(6)*/
};
/*****************************************************************************
* NAME:  convert_to_degrees()
*
* DESCRIPTION:  Converts SPI ADC reading to degrees C * 10.
*
* PARMETERS:
*  adc_value       - ADC reading (0 - FFF)
*
* NOTES:  Routine uses an interpretation table: tcinterptable.
*
* RETURN VALUE:
*    degrees C * 10
*
* This function is <IEC 62304 CLASS C>
*
*****************************************************************************/
U16 convert_to_degrees(U16 adc_value) // converts ADC reading to degrees C * 10
{
	U16 microv4; 						// microvolts * 4 at input of op amp
	const U16 *tp;

	microv4 = (U16)(((U32)adc_value * 40492L) / 4095L); // 40492 = 4.5 * 2.94 / 12.94 / 101 * 4 * 1000000
	if (microv4 >= 255 * 32 * 4)
		return 1785;					// maximum temperature is 178.5 degrees C
	tp = tcinterptable + microv4 / 128;
	return tp[0] + ((tp[1] - tp[0]) * (microv4 & 0x7F) + 64) / 128;
}

/****************************************************************************/
/*       TABLE OF NTC RESISTOR TO TEMPERATURES IN 0.1 DEG C UNITS			*/
/*		From US Sensors NTC Resistance-Temperature Chart for PS303J2		*/
/*		Resistance 30000 - Curve "J"; Beta 0-50 C 3890          			*/
/****************************************************************************/
static const struct ntctablestr{
	U16 ADCcounts;				// ADC counts read
	U16 temp_10;				// temperature in 1/10 degreees C
	U16 TCcounts;				// thermocouple ADC counts to add for CJC
} ntctable[] = {
	{3950,100,158},
	{3920,102,161},
	{3890,104,165},
	{3860,106,168},
	{3830,108,171},
	{3800,110,174},
	{3772,112,178},
	{3743,114,181},
	{3714,116,184},
	{3685,118,187},
	{3656,120,190},
	{3628,122,193},
	{3601,124,197},
	{3573,126,200},
	{3545,128,203},
	{3517,130,206},
	{3490,132,209},
	{3463,134,213},
	{3437,136,216},
	{3410,138,219},
	{3383,140,222},
	{3357,142,225},
	{3331,144,229},
	{3305,146,232},
	{3279,148,235},
	{3253,150,238},
	{3229,152,242},
	{3204,154,245},
	{3179,156,248},
	{3154,158,251},
	{3129,160,254},
	{3105,162,258},
	{3081,164,261},
	{3057,166,264},
	{3033,168,267},
	{3009,170,271},
	{2986,172,274},
	{2963,174,277},
	{2940,176,280},
	{2917,178,284},
	{2894,180,287},
	{2872,182,290},
	{2850,184,293},
	{2827,186,297},
	{2805,188,300},
	{2783,190,303},
	{2762,192,306},
	{2740,194,310},
	{2719,196,313},
	{2697,198,316},
	{2676,200,320},
	{2656,202,323},
	{2635,204,326},
	{2614,206,329},
	{2594,208,333},
	{2573,210,336},
	{2553,212,339},
	{2534,214,342},
	{2514,216,345},
	{2494,218,349},
	{2474,220,352},
	{2455,222,355},
	{2437,224,359},
	{2418,226,362},
	{2399,228,365},
	{2379,230,369},
	{2361,232,372},
	{2343,234,375},
	{2325,236,378},
	{2307,238,381},
	{2288,240,385},
	{2271,242,388},
	{2253,244,391},
	{2236,246,395},
	{2218,248,398},
	{2201,250,401},
	{2184,252,405},
	{2167,254,408},
	{2150,256,411},
	{2133,258,415},
	{2116,260,418},
	{2100,262,421},
	{2084,264,425},
	{2068,266,428},
	{2052,268,431},
	{2036,270,434},
	{2020,272,438},
	{2005,274,441},
	{1989,276,444},
	{1973,278,447},
	{1958,280,451},
	{1943,282,454},
	{1928,284,457},
	{1913,286,461},
	{1898,288,464},
	{1883,290,467},
	{1869,292,471},
	{1855,294,474},
	{1840,296,477},
	{1826,298,480},
	{1812,300,484},
	{1798,302,487},
	{1784,304,491},
	{1771,306,494},
	{1757,308,497},
	{1743,310,501},
	{1730,312,504},
	{1717,314,507},
	{1703,316,511},
	{1690,318,514},
	{1677,320,517},
	{1664,322,521},
	{1652,324,524},
	{1639,326,527},
	{1626,328,531},
	{1613,330,534},
	{1601,332,537},
	{1589,334,541},
	{1577,336,544},
	{1565,338,548},
	{1553,340,551},
	{1541,342,554},
	{1529,344,558},
	{1518,346,561},
	{1506,348,564},
	{1494,350,568},
	{1483,352,571},
	{1472,354,574},
	{1461,356,578},
	{1449,358,581},
	{1438,360,585},
	{1427,362,588},
	{1417,364,591},
	{1406,366,594},
	{1395,368,598},
	{1384,370,601},
	{1374,372,605},
	{1364,374,608},
	{1353,376,611},
	{1343,378,615},
	{1333,380,618},
	{1323,382,622},
	{1313,384,625},
	{1303,386,628},
	{1293,388,632},
	{1283,390,635},
	{1274,392,639},
	{1264,394,642},
	{1255,396,645},
	{1245,398,649},
	{1236,400,652},
	{1226,402,655},
	{1217,404,659},
	{1208,406,662},
	{1199,408,666},
	{1190,410,669},
	{1181,412,672},
	{1172,414,676},
	{1164,416,679},
	{1155,418,683},
	{1146,420,686},
	{1138,422,689},
	{1129,424,693},
	{1121,426,696},
	{1112,428,700},
	{1104,430,703},
	{1096,432,706},
	{1088,434,710},
	{1080,436,713},
	{1072,438,717},
	{1064,440,720},
	{1056,442,724},
	{1048,444,727},
	{1040,446,730},
	{1032,448,734},
	{1025,450,737},
	{1017,452,741},
	{1010,454,744},
	{1002,456,748},
	{995,458,751},
	{987,460,754},
	{980,462,758},
	{973,464,761},
	{966,466,765},
	{959,468,768},
	{952,470,772},
	{945,472,775},
	{938,474,779},
	{931,476,782},
	{924,478,785},
	{917,480,789},
	{911,482,792},
	{904,484,796},
	{897,486,799},
	{891,488,803},
	{884,490,806},
	{878,492,810},
	{872,494,813},
	{865,496,817},
	{859,498,820},
	{853,500,824}
};
/*****************************************************************************
* NAME:  convert_ntc()
*
* DESCRIPTION:  Converts NTC ADC reading to degrees C * 10 and CJC value.
*
* PARMETERS:
*  adc_value       - ADC reading (0 - FFF)
*
* NOTES:  Routine uses an interpretation table: ntctable.
*
* RETURN VALUE:
*    CJC value
*    degrees C * 10
*
* This function is <IEC 62304 CLASS C>
*
*****************************************************************************/
#define NTCTABSIZ (sizeof(ntctable) / sizeof(ntctable[0]))
U16 convert_ntc(U16 adc_value, U16 *tempp) // converts ADC reading to degrees C * 10
{
	U16 temperature, cjcvalue, cntdiff, tabdiff;
	S16 i, j;

	if (adc_value > ntctable[0].ADCcounts) {
		temperature = 99;
		cjcvalue = ntctable[0].TCcounts;
	} else if (adc_value < ntctable[NTCTABSIZ - 1].ADCcounts) {
		temperature = 501;
		cjcvalue = ntctable[NTCTABSIZ - 1].TCcounts;
	} else {
		for (i = NTCTABSIZ / 2, j = NTCTABSIZ / 4; ; ) {
			if (adc_value > ntctable[i].ADCcounts) {
				if ((i -= j) < 0)
					i = 0;
			} else if (i < (S16)(NTCTABSIZ - 1) && adc_value < ntctable[i + 1].ADCcounts) {
				if ((i += j) > (S16)(NTCTABSIZ - 1))
					i = NTCTABSIZ - 1;
			} else if (i < (S16)(NTCTABSIZ - 1) && adc_value == ntctable[i + 1].ADCcounts) {
				i = i + 1;
				break;
			} else
				break;
			if (j <= 1)
				break;
			j = (j + 1) / 2;
		}
		temperature = ntctable[i].temp_10 + ((cntdiff = ntctable[i].ADCcounts - adc_value) * 2)
								 / (tabdiff = ntctable[i].ADCcounts - ntctable[i + 1].ADCcounts);
		cjcvalue = ntctable[i].TCcounts + (cntdiff * (ntctable[i + 1].TCcounts - ntctable[i].TCcounts)) / tabdiff;
	}
	if (tempp != NULL)
		*tempp = temperature;
	return cjcvalue;
}
/*****************************************************************************
* NAME:  ram_test()
*
* DESCRIPTION:  Test RAM above and below the stackpointer including DMA RAM.
*
* PARMETERS:  NONE
*
* NOTES:  Routine writes 00, FF, AA, 55 to area above and below stackpointer and checks.
*         Routine writes address of words of area and checks.
*         Needs more data space above stack pointer than below stack pointer.
*         No Interrupts or DMA transfers are allowed during test.
*
* RETURN VALUE:
*    0 if OK, code if error
*
*****************************************************************************/
static U16 ram_test1(U8 *top);     			// test memory area below the stack
U16 ram_test(void)     				     // test memory area above the stack
{										// NO Interrupts or DMA transfers allowed
	U8 *mp;											// byte pointer
	U16 *wp;										// word pointer
													// fill with zero and check
	for (mp = (U8 *)WREG15; mp < (U8 *)(DMARAM + DMARAMSIZE); mp++) // ~2.8 ms
		*mp = 0;
	for (mp = (U8 *)WREG15; mp < (U8 *)(DMARAM + DMARAMSIZE); mp++)
		if (*mp != 0)
			return ERROR_RAM_HI_SP_1ST_00;
	KICK_THE_DOG;									// fill with FF and check
	for (mp = (U8 *)WREG15; mp < (U8 *)(DMARAM + DMARAMSIZE); mp++) // ~2.8 ms
		*mp = 0xff;
	for (mp = (U8 *)WREG15; mp < (U8 *)(DMARAM + DMARAMSIZE); mp++) // ~4.3 ms
		if (*mp != 0xff)
			return ERROR_RAM_HI_SP_FF;
	KICK_THE_DOG;									// update watchdog
	for (mp = (U8 *)WREG15; mp < (U8 *)(DMARAM + DMARAMSIZE); mp++) // ~2.8 ms
		*mp = 0xaa;
	for (mp = (U8 *)WREG15; mp < (U8 *)(DMARAM + DMARAMSIZE); mp++)
		if (*mp != 0xaa)
			return ERROR_RAM_HI_SP_AA;
	KICK_THE_DOG;									// fill with 55 and check
	for (mp = (U8 *)WREG15; mp < (U8 *)(DMARAM + DMARAMSIZE); mp++) // ~2.8 ms
		*mp = 0x55;
	for (mp = (U8 *)WREG15; mp < (U8 *)(DMARAM + DMARAMSIZE); mp++)
		if (*mp != 0x55)
			return ERROR_RAM_HI_SP_55;
	KICK_THE_DOG;									// update watchdog
													// do check with 16-bit words
	for (wp = (U16 *)WREG15; wp < (U16 *)(DMARAM + DMARAMSIZE); wp++) // fill with address ^ 0xAAAA and check
		*wp = ((U16)wp  ^ 0xAAAA);
	for (wp = (U16 *)WREG15; wp < (U16 *)(DMARAM + DMARAMSIZE); wp++)
		if (*wp != ((U16)wp ^ 0xAAAA ))
			return ERROR_RAM_HI_SP_AAAA;
	KICK_THE_DOG;
	for (wp = (U16 *)WREG15; wp < (U16 *)(DMARAM + DMARAMSIZE); wp++) // fill with zeroes and check
		*wp = 0;
	for (wp = (U16 *)WREG15; wp < (U16 *)(DMARAM + DMARAMSIZE); wp++)
		if (*wp != 0)
			return ERROR_RAM_HI_SP_LAST_00;
	KICK_THE_DOG;									// update watchdog
	return ram_test1((U8 *)WREG15);					// test below stack pointer
}
/*****************************************************************************
* NAME:  ram_test1()
*
* DESCRIPTION:  Test RAM below the stackpointer.
*
* PARMETERS:  NONE
*   top		- old stack pointer from calling routine
*
* NOTES:  Routine writes 00, FF, AA, 55 to area below old stackpointer and checks.
*         Routine writes address of words of area and checks.
*         No Interrupts or DMA transfers are allowed during test.
*         Data below old stack pointer is moved to above new stack pointer first and returned at the end
*
* RETURN VALUE:
*    0 if OK, code if error
*
*****************************************************************************/
static U16 ram_test1(U8 *top)     			    // test memory area below the stack
{												// NO Interrupts or DMA transfers allowed
	U8 *mp;										// byte pointer
	U16 *wp, *dp;								// word pointers
	U16 errcode = 0;

	if (top - (U8 *)RAMSTART > (U8 *)(DMARAM + DMARAMSIZE) - (U8 *)WREG15)	// check for space
		return ERROR_RAM_SPACE;
	for (wp = (U16 *)RAMSTART, dp = (U16 *)WREG15; wp < (U16 *)top; dp++, wp++) // move data to above stack
		*dp = *wp;
	KICK_THE_DOG;									// update external watchdog
													// fill with zero and check
	for (mp = (U8 *)RAMSTART; mp < top; mp++) // ~2.8 ms
		*mp = 0;
	for (mp = (U8 *)RAMSTART; mp < top; mp++)
		if (*mp != 0) {
			errcode = ERROR_RAM_LO_SP_1ST_00;
			break;
		}
	KICK_THE_DOG;									// update external watchdog
	if (!errcode) {									// fill with FF and check
		for (mp = (U8 *)RAMSTART; mp < top; mp++) // ~2.8 ms
			*mp = 0xff;
		for (mp = (U8 *)RAMSTART; mp < top; mp++) // ~4.3 ms
			if (*mp != 0xff) {
				errcode = ERROR_RAM_LO_SP_FF;
				break;
			}
	}
	KICK_THE_DOG;									// update external watchdog
	if (!errcode) {									// fill with AA and check
		for (mp = (U8 *)RAMSTART; mp < top; mp++) // ~2.8 ms
			*mp = 0xaa;
		for (mp = (U8 *)RAMSTART; mp < top; mp++)
			if (*mp != 0xaa) {
				errcode = ERROR_RAM_LO_SP_AA;
				break;
			}
	}
	KICK_THE_DOG;									// update external watchdog
	if (!errcode) {									// fill with 55 and check
		for (mp = (U8 *)RAMSTART; mp < top; mp++) // ~2.8 ms
			*mp = 0x55;
		for (mp = (U8 *)RAMSTART; mp < top; mp++)
			if (*mp != 0x55) {
				errcode = ERROR_RAM_LO_SP_55;
				break;
			}
	}
	KICK_THE_DOG;									// update external watchdog
	if (!errcode) {									// do check with 16-bit words
		for (wp = (U16 *)RAMSTART; wp < (U16 *)(top); wp++) // fill with address ^ 0xAAAA and check
			*wp = ((U16)wp  ^ 0xAAAA);
		for (wp = (U16 *)RAMSTART; wp < (U16 *)(top); wp++)
			if (*wp != ((U16)wp ^ 0xAAAA )) {
				errcode = ERROR_RAM_LO_SP_AAAA;
				break;
			}
	}
	KICK_THE_DOG;									// update external watchdog
	if (!errcode) {
		for (wp = (U16 *)RAMSTART; wp < (U16 *)(top); wp++) // fill with zeroes and check
			*wp = 0;
		for (wp = (U16 *)RAMSTART; wp < (U16 *)(top); wp++)
			if (*wp != 0) {
				errcode = ERROR_RAM_LO_SP_LAST_00;
				break;
			}
	}
	KICK_THE_DOG;									// update external watchdog
	for (dp = (U16 *)RAMSTART, wp = (U16 *)WREG15; dp < (U16 *)top; dp++, wp++) // move data back below stack
		*dp = *wp;
	KICK_THE_DOG;									// update external watchdog
	return errcode;
}
/*****************************************************************************
* NAME:  config_check()
*
* DESCRIPTION:  Checks config registers in PIC24HJ256GP610
*
* PARMETERS:  NONE
*
* NOTES: Checks that the config regiters have the correct values.
*
* RETURN VALUE:
*    1 if good data, 0 if bad data
*
*****************************************************************************/
/*
U16 config_check(void)		// Checks config registers in PIC24HJ256GP610
{
	U16 i;

	for (i = 0; i < sizeof(config_data); i++) {
		if (flash_read_word(0xF80000L + i * 2) != config_data[i])
			return 0;
	}
	return 1;
}
*/
