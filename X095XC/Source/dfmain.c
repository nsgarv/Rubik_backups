/*******************************************************************************
* Copyright (c) 2010 - 2011 Minnetronix, Inc.  All rights reserved.            *
*******************************************************************************/
/*******************************************************************************
*
*   $Source: DFMAIN.C $
*   $Revision: 1.25 $
*     Project: Balaton
*       $Date: 2012/02/02 10:03:24CST $
*
*-------------------------------------------------------------------------------
*
*  This file is <IEC 62304 CLASS C>
*
* Description:  This is the main file for the Balaton DFine ablation device.
*
*  Files and or functions marked with <IEC 62304 CLASS C> are considered
*     IEC 62304 Class 'C' and shall be treated accordingly. Changes to these
*     software components shall be tracked by issue. The altered code shall
*     be HUT (Heavy Unit Test) tested or data shall be provided of complete
*     testing during verification.
*
*******************************************************************************/

#define DFMAIN_C

#include <stdio.h>
// htc.h is a HI-TECH file and for this project calls "pic24hj256gp610.h" which was added below.
//#include <htc.h>
//#include <xc.h>
#include <string.h>
#include "dfine.h"
#include "dfdisply.h"
#include "pic24hj256gp610.h"

/*******************************************************************************
********************* Application Globals **************************************
*******************************************************************************/

/*
 * None.
 */

/*******************************************************************************
************************* File Globals *****************************************
*******************************************************************************/

/*
 * Define some flags to help the application to know when it's sent a
 * "Connect Device" message to the display or not. We only want to send the
 * message once for every change in dis/connect status.
 */

static U16 DeviceConnectReported = 0;
static U16 DeviceDisconnectReported = 0;

/*
 * Retain the current value of the RF Cycle time - in 20ms tick units.
 * The value will be converted first to seconds and then to MM:SS format before
 * it is displayed. It will count down as the RF is being delivered.
 * When 0, the RF ON button is ignored.
 * It's important that it is initialized to 0 so that a user must set it (and
 * think about the proper value to set it to) before RF can be turned on.
 */

static U16 RFCycleSPS = 0*SPS;

/*
 * The preset for the RF Cycle value. It is adjusted in Settings Mode.
 * It'll go away if power is turned off. The units for it are the same as the
 * units for RFCycleSPS.
 */

static U16 RFCycleSPSPreset = 0*SPS;

/*
 * Define two variables that have to do with whether or not the RF Cycle value
 * has been set or adjusted. The difference between "set" and "adjusted" is
 * degree. Adjusted means it has been manipulated with the up and down buttons.
 * Set means the adjusted value has been locked in by an exit from Settings Mode.
 */

static U16 RFCycleSet = 0;
static U16 RFCycleAdjusted = 0;
static U16 PostStartupRFCycleAdjusted = 1;

/*
 * Define a variable to assist in the flashing of the RF Cycle value. The
 * variable's value is used as an argument to a function that can either display
 * the RF Cycle value or erase it. The RFCycleEraseOnly value is alternately
 * set to 0 or 1 when flashing is desired.
 */

static U16 RFCycleEraseOnly = 0;

/*
 * Retain the current value of the Cycle counter.
 * A Cycle is defined as a run of RF Cycle seconds. It increments every time a
 * cycle starts. A cycle ends when the RF Cycle value counts down to 0 or a
 * new RF Cycle value is set.
 */

static U16 Cycles = 0;

/*
 * One button (Cycle button) and one handswitch (Cycle handswitch) alter the
 * RF Cycle value. The handswitch, which is in the sterile field, is simpler
 * and has less functionality than the button. The button can reset the RF Cycle
 * value to its preset - and so can the handswitch - but the handswitch has to
 * be held down longer than the button to do so. The button can also be used
 * to enter Settings Mode but the handswitch cannot (because the up and down
 * buttons, the buttons necessary for doing anything meaningful in the mode,
 * are outside the sterile field.
 *
 * The following variables help to know how long the button or handswitch
 * was held down.
 */

static U16 CycleButtonHeldAtExpirationCount = 0;
static U16 CycleSwitchHeldAtExpirationCount = 0;
static U16 CycleButtonHeldCount = 0;
static U16 CycleButtonReleased = 1;

/*
 * The following do similarly for the Up, Down and Reset buttons.
 */

static U16 UpButtonHeldCount = 0;
static U16 DownButtonHeldCount = 0;
static U16 ResetButtonHeldCount = 0;

/*
 * How long the Cycle button, in 20ms tick units, must be held to enter or exit
 * Settings Mode
 */

#define CYCLE_BUTTON_MODE_ENTRY_THRESHOLD (3*SPS)
#define CYCLE_BUTTON_MODE_EXIT_THRESHOLD (SPS/5)

/*
 * How long the Cycle button or handswitch, in 20ms tick units, must be held to
 * reset the RF Cycle value to its preset
 */

#define CYCLE_SWITCH_RELOAD_THRESHOLD (3*SPS)
#define CYCLE_BUTTON_RELOAD_THRESHOLD (SPS/5)

/*
 * The UP and DOWN buttons increment and decrement the RF Cycle preset in
 * Settings Mode. The following determine how much it can be incremented or
 * decremented. Units are 20ms ticks.
 */

#define MIN_RF_CYCLE_SPS_PRESET (0*60*SPS)  // 00:00
#define MAX_RF_CYCLE_SPS_PRESET (10*60*SPS) // 10:00

/*
 * The UP and DOWN buttons increment and decrement the RF Cycle preset by
 * different amounts the longer they are held. The hold time has been separated
 * into three segments: a LOW, MED and HIGH hold time. The variables that follow
 * help to define how long a button has to be held to be in a particular segment
 * and how much the RF Cycle preset is incremented or decremented every pass
 * through the button sample code while in that segment.
 *
 * The button sample code and the RF Cycle display code is not strictly
 * deterministic and some experimentation was necessary to arrive at values that
 * roughly adjust the displayed value in 1s, 15s and 1min increments.
 */

#define MED_BTN_HELD_THRESHOLD (5*SPS) // hold btn for 5s to get med time inc
#define HIGH_BTN_HELD_THRESHOLD (10*SPS) // hold btn for 10s to get hi time inc

#define LOW_RF_CYCLE_TIME_INCREMENT (7) // approx 1s per button push
#define MED_RF_CYCLE_TIME_INCREMENT (30) // approx 15s per display update
#define HIGH_RF_CYCLE_TIME_INCREMENT (120) // approx 1min per display update

/* How long the Reset button must be held, in 20ms tick units, to reset */

#define RESET_BTN_HELD_THRESHOLD (3*SPS) // hold btn for 3s to reset

// Maximum RF on power error allowed

#define POWER_ERROR_PCT_LIMIT (10)     // percentage > target that causes fault
#define POWER_LIMIT_TEST_HOLD_OFF (3)  // secs since RF on that limit is heldoff
#define POWER_FAULT_COUNT (3)       // consecutive secs power fault must be true

/*
 * Settings Mode is the mode that allows settings such as the RF Cycle value
 * to be set. Some operations, like turning the RF on, are prohibited in the
 * mode. The unit poowers up into the mode because the customer wants the user
 * to think about and select the RF Cycle value before they do anything else.
 */
static U16 SettingsMode = 1;

/*
 * The RF Cycle value flashes for a short while when a cycle is completed.
 * The following help to know when to stop and to make sure we don't stop on
 * a blank RF Cycle value.
 */
static U16 FlashRFCycleCount = 0;
static U16 PriorFlashRFCycleCount = 0;

/*
 * Keep track of which screen is being displayed. Currently, the only use is
 * to know which fault/warning image to display when a fault or warning occurs.
 * The two fault images are the same except that they are on different
 * backgrounds. The same is true for the two warning images.
 */
static DISPLAY_SCREENS Screen = SPLASH_DISPLAY_SCREEN;

static struct DFinestruct                          // Main data structure
{
   U16 impedance;       // activation element 1/10 ohm res.
   U16 rfontime;        // latest RF on time SPS res.
   U32 totalrfontime;   // total RF on time SPS res.
   U16 rfon;            // RF on flag
   U16 pressure;        // measured pressure PSI res.                // unused
   U16 lastpressure;    // last pressure at motor running, PSI res.  // unused
   U16 initial_imp;     // initial impedance
   U16 power_setp;      // RF power setpoint, 1/1000 W res.

   S16 power_setp_comp; // RF power, complete, 1 Sec Ave, 1/31.25 W res or 32 mW // x.093
   S16 power_setp_ave;  // RF power/32, accumulator, 1000/32 = 1/31.25 W res or 32 mW // x.093
                        // At 5 watts 0.64% error do to res., 41.9 W before overflow // x.093
                        // Track how well power follow set point. // x.093

   U16 RFpower;         // RF power, 1/1000 W res.

   S16 RFpower_comp;    // RF power, complete, 1 Sec Ave, 1/31.25 W res or 32 mW // x.093
   S16 RFpower_ave;     // RF power/32, accumulator, 1000/32 = 1/31.25 W res or 32 mW // x.093
                        // At 5 watts 0.64% error do to res., 41.9 W before overflow // x.093
   S16 pwr_track_err;   // Tracking error between set power and power in percent // x.093

   S16 RFvoltage;       // RF voltage, 1/100 V res.
   S16 RFcurrent;       // RF current, 1/1000 A res.
   U16 ntc_temp;        // NTC temperature, 1/10 degC res.
   U16 temperature1;    // TC1 temperature, 1/10 degC res.
   U16 temperature2;    // CJC temperature, 1/10 degC res.
   U16 set_room_temp;   // set room temperature, 1 degF res.
   U32 acc_power;       // accumulated power, mW per sample.
   U32 cement_time;     // cement timer, samples.                    // unused
   U32 timecount2;      // second timer, samples.
   U16 pramp;           // CJC temperature, 1/10 degC res.
   U16 impcomp;         // CJC temperature, 1/10 degC res.
   U32 imp_avg;
   U16 imp_comp;
   U16 looptime;

   U16 loopCount;       // x0.93
   U16 faultCount;      // x0.93

   U32 t1_avg;
   U16 t1_comp;
   U32 t2_avg;
   U16 t2_comp;
   U16 prxtemp;
   U16 setting;
   U16 display_temp;    // CJC temperature, 1/10 degC res.

} ds = {0, 0,0,0, 0,0, 0, RF_MIN_POWER,0,0,0, 0,0,0,0, 0L, 0L,0L,0,0,0,0,0,0,0,0,0,500,1,500};

static struct EEPROMstruct es =
{"DCC-001", "0", "00000", "000", PRESSURE_OFFSET, PRESSURE_SCALE, RF_POWER_SCALE, RF_VOLTAGE_SCALE, RF_CURRENT_SCALE, 0};

/*******************************************************************************
****************** Static Function Prototypes **********************************
*******************************************************************************/

static U16  ablate_bad(struct DFinestruct *dfp);         // check temperature etc of activation element
static U16  ablate_loop(void);                           // loop where the software spends the time in ablate mode
static void ablate_power(struct DFinestruct *dfp, U16 setting);   // measure impedance when RF is on
static U16  calc_median(U16 *in_array);
static void display_time(U32 total_rf_seconds, U16 rf_cycle_seconds); // display times
static void EnterSettingsMode();
static void ExitSettingsMode();

static void get_temperature(struct DFinestruct *dfp);    // update ambient temperature
static void imp_pulse_measure(struct DFinestruct *dfp);  // measure impedance when RF is off
static U16  isDeviceConnected();                         // returns non-zero if ablate probe is connected, return zero if unrealistic temperature readings
static U16  isImpedanceTooLow(U16 impedance);
static void SetPowerSetting(U16 new_pwr_setting);

static U16  start_sequence(U16 RFKflg);                  // after POST etc.
static void tonechk(U32 timecount, U32 s_reg);           // generate appropriate sound

/*******************************************************************************
********************* Function Definitions *************************************
*******************************************************************************/

/*****************************************************************************
* NAME:  main()
*
* DESCRIPTION:  Program starts here.
*
* PARMETERS:   NONE
*
* NOTES: Initializes hardware.
*        Turns on and off display.
*        Plays start "tune".
*        Checks for stuck buttons.
*        Calls start_sequence() and main_loop().
*
* RETURN VALUE:
*    Does not return.
*
* This function is <IEC 62304 CLASS C>
*
*****************************************************************************/
int main()
{
   U16 i, code;

   hw_init();
   KICK_THE_DOG;

   /* Turn all of the LEDs on */

   write_LEDs(LED_ON | LED_FAULT | LED_RF | LED_WARNING);
   tone(BEEP_INIT);

   /* Turn off RF relay and motor relay */

   write_DAC(0, RFDAC_CTRL_RF_MOTOR_AND_RELAY_ALL_OFF);

   /* Initialize the display */

   if (!gDFDisplyInit())
      fault_routine(WARNING_SEVERITY, ERROR_DISPLAY_INIT, "Display Init");

   /* Check CPU Configuration Registers */

   /*
   if (!config_check())
      fault_routine(FAULT_SEVERITY, ERROR_CPU_CONFIG, "CPU Config Register");
   */

   /* Check CPU FLASH Memory */

   #if (CHECK_CRC)
   if (!crc_flash())
      fault_routine(FAULT_SEVERITY, ERROR_FLASH_CRC, "FLASH CRC");
   #endif

   /* Check RAM */

   if (code = ram_test())
      fault_routine(WARNING_SEVERITY, code, "RAM");

   /*
    * Sound power-up melody.
    * Call tone at 20ms intervals for length of melody.
    * (If you wait for other tone calls to do it the melody won't be as
    * deterministic as it is implied to be in the tonestruct structure.)
    *
    * Waiting here, of course, slows bootup time.
    * A shorter melody or changing the reqt to be looser on the timing of the
    * tones in the melody would allow a person to remove most of the for loop.
    */

   tone(BEEP_TONE1);
   for (i = 0; i < (5*SPS); i++)
   {
      wait_for_20ms();
      tone(BEEP_CHECK);
      KICK_THE_DOG;
   }

   /* Turn on the ON LED */

   write_LEDs(LED_ON);

   /* Read configuration bytes from EEPROM and check integrity of bytes */

   if (read_eeprom(0, (U8 *)(&es), sizeof(es)) < 0
       || crcchk((U8 *)(&es), sizeof(es)) == 0)
      fault_routine(FAULT_SEVERITY, ERROR_EEPROM, "EEPROM");

   /* Is watchdog happy? */

   if ((get_status() & WATCH_DOG) == 0)
      fault_routine(FAULT_SEVERITY, ERROR_WATCHDOG, "Watchdog");

   /* Test supply voltages and on-board temperature */

   if ((code = post_supply_volts()) != 0)
      if (code == ERROR_TEMP)
      {
         fault_routine(WARNING_SEVERITY, code, "On-board temp");
      }
      else
      {
         fault_routine(FAULT_SEVERITY, code, "Supply Voltage");
      }

   /* Check for stuck front panel buttons or stuck handswitches */

   if (get_raw_switches() != 0)
      fault_routine(WARNING_SEVERITY, ERROR_STUCK_BTN, "Stuck Button");

   /* Test RF Circuitry */

   if ((code = post_rf(&es)) != 0)
   {
      #define  RF_CIRCUITRY
      #ifdef RF_CIRCUITRY
      if (code == ERROR_IMPEDANCE)
      {
         fault_routine(WARNING_SEVERITY, code, "RF Circuitry");
      }
      else
      {
         fault_routine(FAULT_SEVERITY, code, "RF Circuitry");
      }
      #else
      ;
      #endif
   }

   /* Test SPI Circuitry */

   if ((code = post_spi()) != 0)
      fault_routine(FAULT_SEVERITY, code, "SPI Circuitry");

   KICK_THE_DOG;

   for (code = 0; ;)
   {
      start_sequence(code); // startup and ablate loop.
   }
}


/*****************************************************************************
* NAME:  ablate_loop()
*
* DESCRIPTION:  Ablate loop.
*
* PARMETERS:   NONE
*
* NOTES: Handles all buttons.
*        Checks impedance for fault.
*        Checks temperature for RF on.
*        Handles display etc.
*        Exits on MODE button.
*
* RETURN VALUE:
*    Button code that caused exit
*
* This function is <IEC 62304 CLASS C>
*
*****************************************************************************/

#ifdef DEBUG_LEVEL_CHECK           // x.093
static char cDebugLevelText1[30];  // x.093
static U16 uCount = 0;             // x.093
static U16 uCount2 = 0;            // x.093
static S16 sPerrPrcntMax = 0;      // x.093
#endif // #ifdef DEBUG_LEVEL_CHECK // x.093

#define ABLATE_BAD_TC1  0x01 // bad activation element flags
#define ABLATE_BAD_TC2  0x02
#define ABLATE_BAD_IMP  0x04
#define ABLATE_BAD_AMB  0x08

static U16 ablate_loop(void)    // loop where the software spends the time in ablate mode
{
   U32 timecount;               // Start at 0:00

   U16 switches, status, displaytimer;
   U16 ablate_bad_flags, ablate_bad_tc1_cnt = 0, ablate_bad_tc2_cnt = 0, ablate_bad_imp_cnt = 0;
   U32 s_reg = 0L;
   U16 pwr_setting = ABLATE_POWER_SETTING_LEVEL1;
   U16 time_increment;
   static S32 slTemp; // x.093
   long temp_rf_cycle_sps_preset;
   char *power_value_text;

   /* move power setting to master copy */

   SetPowerSetting(pwr_setting);

   for ( ; ; timecount++)
   {
      wait_for_20ms(); // wait for next 20 ms time tic

      ablate_bad_flags = ablate_bad(&ds);    // check activation element
      if (ablate_bad_flags & ABLATE_BAD_TC1) // timers for blinking
      {
         if (ds.rfon)
            ablate_bad_tc1_cnt = 5 * SPS;    // blink 5 seconds extra if RF on
         else if (ablate_bad_tc1_cnt < SPS)
            ablate_bad_tc1_cnt = SPS;        // 1 sec if RF off
      }
      else if (ablate_bad_tc1_cnt)
         --ablate_bad_tc1_cnt;
      if (ablate_bad_flags & ABLATE_BAD_TC2)
      {
         if (ds.rfon)
            ablate_bad_tc2_cnt = 5 * SPS;    // blink 5 seconds extra if RF on
         else if (ablate_bad_tc2_cnt < SPS)
            ablate_bad_tc2_cnt = SPS;        // 1 sec if RF off
      }
      else if (ablate_bad_tc2_cnt)
         --ablate_bad_tc2_cnt;
      if (ablate_bad_flags & ABLATE_BAD_IMP)
      {
         if (ds.rfon)
            ablate_bad_imp_cnt = 5 * SPS;    // blink 5 seconds extra if RF on
         else if (ablate_bad_imp_cnt < SPS)
            ablate_bad_imp_cnt = SPS;        // 1 sec if RF off
      }
      else if (ablate_bad_imp_cnt)
         --ablate_bad_imp_cnt;

      ////////////////////////// Check Switches ///////////////////////////////

      switches = get_switches();

      /*
       * If RF button press does not match current RF state AND
       * If there are no ablate_bad flags set AND
       * If the RF "on" time is less than cutoff
       * ...
       *
       * NOTE: RFON_LED is on when its value is 1.
       */

      if (((switches & RFON_BUTTONE) && RFON_LED == 0 || !(switches & RFON_BUTTONE) && RFON_LED == 1) &&
          !ablate_bad_flags &&
          RFCycleSPS > 0)
      {
         if ((!ds.rfon) && (SettingsMode == 0))
         {
            // turn on RF if not on

            ds.rfon = 1;
            ds.loopCount = 0;          // Used to not test RF power error when
                                       // RF is first turned on // x.093
            #ifdef DEBUG_LEVEL_CHECK   // x.093
            sPerrPrcntMax = 0;         // x.093
            #endif                     // x.093
            ds.faultCount = 0;         // x.093

            tone(BEEP_CLICK);

            write_LEDs(LED_ON | LED_RF); // turn on blue LED
            if (!ds.initial_imp)
               ds.initial_imp = ds.impedance;

            // lite handswitch RFON LED, if it exists

            RFON_LED = 1;

            // set flag is stat reg for display
            s_reg = s_reg & ~(S_MOTOR | S_HI_PRESS | S_RESTART_EXP) | S_RF;

            /* Turn on the Radiating RF graphic */

            gDFDisplyPrintRFGraphicItem(1);

            /* Increment the Cycles value */

            if (RFCycleSPS == RFCycleSPSPreset)
            {
               Cycles++;
               gDFDisplyPrintCyclesValueTextItem(Cycles);
            }
         }
      }
      else
      {
         if (ds.rfon)
         {
            // turn off RF, if on
            imp_pulse_measure(NULL);         // updates DAC and LEDs
            ds.rfon = ds.rfontime = 0;
            ds.RFpower = 0;
            ds.RFvoltage = ds.RFcurrent = 0;

            /* Turn off the Radiating RF graphic */

            gDFDisplyPrintRFGraphicItem(0);

            tone(BEEP_CLICK);

            /*
             * Flash RF Cycle for n seconds to prompt user to set it if
             * they want to run again.
             */

            if (RFCycleSPS == 0)
            {
               FlashRFCycleCount = 5 * SPS;
            }
         }

         RFON_LED = 0;                  // RF latched LED off
         MOTOR_LED = 0;                 // motor latched LED off
         s_reg &= ~(S_RF | S_MOTOR);    // clear flag is stat reg for display
      }

      /* Power can be increased with up button and decreased with down button */

      if (SettingsMode == 0)
      {
         if ((switches & UP_BUTTON) && pwr_setting < ABLATE_POWER_SETTING_MAXNDX)
         {
            /* if up pressed and not yet at maximum RF power setting */

            tone(BEEP_CLICK);                 // click tone
            ++pwr_setting;                    // increment copy of power setting
            SetPowerSetting(pwr_setting);     // move to master copy
         }
         else if ((switches & DN_BUTTON) && pwr_setting > ABLATE_POWER_SETTING_MINNDX)
         {
            /* else if down pressed and not yet at minimum RF power setting */

            tone(BEEP_CLICK);                 // click tone
            --pwr_setting;                    // decrement copy of power setting
            SetPowerSetting(pwr_setting);     // move to master copy
         }
      }
      else
      {
         /* See if user is trying to adjust RF Cycle time preset */

         if (get_raw_switches() & UP_BUTTON)
         {
            /* Turn off RF Cycle flashing that was turned on at startup */

            RFCycleAdjusted = 1;
            PostStartupRFCycleAdjusted = 1;

            /* Keep track of how long the up btn was held */

            UpButtonHeldCount++;

            /* Increment the time value by varying amts based on time held */

            if (UpButtonHeldCount > HIGH_BTN_HELD_THRESHOLD)
            {
               time_increment = HIGH_RF_CYCLE_TIME_INCREMENT;
            }
            else if (UpButtonHeldCount > MED_BTN_HELD_THRESHOLD)
            {
               time_increment = MED_RF_CYCLE_TIME_INCREMENT;
            }
            else
            {
               time_increment = LOW_RF_CYCLE_TIME_INCREMENT;
            }

            if ((RFCycleSPSPreset+time_increment) <= MAX_RF_CYCLE_SPS_PRESET)
            {
               RFCycleSPSPreset += time_increment;
            }
            else
            {
               RFCycleSPSPreset = MAX_RF_CYCLE_SPS_PRESET;
            }

            /* Rely on normal periodic display updates to display new value */

            RFCycleSPS = RFCycleSPSPreset;
         }
         else
         {
            UpButtonHeldCount = 0;
         }

         /* Examine down arrow button in same way as up arrow button */

         if (get_raw_switches() & DN_BUTTON)
         {
            RFCycleAdjusted = 1;
            PostStartupRFCycleAdjusted = 1;

            DownButtonHeldCount++;
            if (DownButtonHeldCount > HIGH_BTN_HELD_THRESHOLD)
            {
               time_increment = HIGH_RF_CYCLE_TIME_INCREMENT;
            }
            else if (DownButtonHeldCount > MED_BTN_HELD_THRESHOLD)
            {
               time_increment = MED_RF_CYCLE_TIME_INCREMENT;
            }
            else
            {
               time_increment = LOW_RF_CYCLE_TIME_INCREMENT;
            }

            temp_rf_cycle_sps_preset = RFCycleSPSPreset;
            if ((temp_rf_cycle_sps_preset - time_increment) >=
                MIN_RF_CYCLE_SPS_PRESET)
            {
               RFCycleSPSPreset -= time_increment;
            }
            else
            {
               RFCycleSPSPreset = MIN_RF_CYCLE_SPS_PRESET;
            }

            RFCycleSPS = RFCycleSPSPreset;
         }
         else
         {
            DownButtonHeldCount = 0;
         }
      }

      if ((get_raw_switches() & RESET_BUTTON) && (SettingsMode == 0))
      {

         ResetButtonHeldCount++;
         if (ResetButtonHeldCount == RESET_BTN_HELD_THRESHOLD)
         {
            /* reset button -> start over */

            tone(BEEP_CLICK);
            ds.totalrfontime=0;
            RFCycleSPS = RFCycleSPSPreset;
            Cycles = 0;
            FlashRFCycleCount = 0;

            gDFDisplyPrintRFToTalValueTextItem(0);
            gDFDisplyPrintRFCycleValueTextItem(RFCycleSPSPreset/SPS, 0, 0);
            gDFDisplyPrintCyclesValueTextItem(Cycles);
         }

      }
      else
      {
         ResetButtonHeldCount = 0;
      }

      /*
       * Allow the RF Cycle time to be reloaded to its preset if:
       * 1) We're not in Settings Mode AND
       * 2) RF is off AND
       * 3) either the Orange "Cycle" button on the handpiece has been pressed
       *    for 3 seconds or the Cycle button on the front panel has been
       *    pressed. (If the user continues to hold the Cycle button on the
       *    front panel s/he will enter a mode that lets the preset be changed.)
       */

      if ((SettingsMode == 0) && (ds.rfon == 0))
      {
         if (get_raw_switches() & CYCLE_SWITCH)
         {
            CycleSwitchHeldAtExpirationCount++;
            if (CycleSwitchHeldAtExpirationCount ==
                CYCLE_SWITCH_RELOAD_THRESHOLD)
            {
               tone(BEEP_CLICK);
               RFCycleSPS = RFCycleSPSPreset;
               FlashRFCycleCount = 0;
            }
         }
         else
         {
            CycleSwitchHeldAtExpirationCount = 0;
         }

         if (get_raw_switches() & CYCLE_BUTTON)
         {
            CycleButtonHeldAtExpirationCount++;
            if (CycleButtonHeldAtExpirationCount ==
                CYCLE_BUTTON_RELOAD_THRESHOLD)
            {
               tone(BEEP_CLICK);
               RFCycleSPS = RFCycleSPSPreset;
               FlashRFCycleCount = 0;
            }
         }
         else
         {
            CycleButtonHeldAtExpirationCount = 0;
         }
      }

      /*
       * Also check if the user is signalling that they want to enter or exit
       * "Settings Mode". They can only do so when the RF is off. They hold
       * the front panel Cycle button to enter the mode but simply press it
       * to exit it.
       */

      if (ds.rfon == 0)
      {
        if (get_raw_switches() & CYCLE_BUTTON)
         {
            CycleButtonHeldCount++;
            if (SettingsMode == 0)
            {
               if ((CycleButtonHeldCount == CYCLE_BUTTON_MODE_ENTRY_THRESHOLD) &&
                   (CycleButtonReleased  == 1))
               {
                  tone(BEEP_CLICK);
                  EnterSettingsMode();
                  CycleButtonReleased = 0;
               }
            }
            else
            {
               /*
                * Settings Mode is forced at startup. User must change the
                * default by at least one up or down button push to exit the
                * mode.
                */

               if ((RFCycleAdjusted == 1) &&
                   (CycleButtonHeldCount == CYCLE_BUTTON_MODE_EXIT_THRESHOLD))
               {
                  /*
                   * Above test works if Exit threshold is lower than Entry
                   * threshold. When that's true, it should never be possible for
                   * user to have been NOT in the mode and enter it and immediately
                   * exit it by never letting up on the button - because the above
                   * is an "equals" test, and to get to the else that contains us,
                   * the count would already have passed over the exit threshold.
                   * We should only get here if they've let up on the button after
                   * entering the mode and then subsequently held it for our exit
                   * threshold.
                   */

                  tone(BEEP_CLICK);
                  ExitSettingsMode();
                  CycleButtonReleased = 0;
               }
            }
         }
         else
         {
            CycleButtonHeldCount = 0;
            CycleButtonReleased = 1;
         }
      }

      ///////////////////////// Misc. Stuff ////////////////////////////////////

      if (ds.rfon)
      {

         SetPowerSetting(pwr_setting);     // move to master copy
         ablate_power(&ds, pwr_setting);   // do power control

         // Quickly reset the the fault counter if power returns to normal limits

         slTemp = (S16)ds.RFpower - (S16)ds.power_setp; // x.093
         slTemp = (slTemp * 100) / ds.power_setp; // change to precent // x.093

         // Difference between target and actual power < POWER_ERROR_PCT_LIMIT ?
         // Yes, reset the fault (strike) counter.

         if (slTemp < POWER_ERROR_PCT_LIMIT) // x.093 // x.094
         {
            ds.faultCount = 0;
         }


         #ifdef DEBUG_LEVEL_CHECK   // x.093
         uCount++;
         #endif                     // x.093

         ds.rfontime++;
         ds.totalrfontime++;
         if (RFCycleSPS > 0)
         {
            RFCycleSPS--;
         }
      }
      else
         imp_pulse_measure(&ds);           // RF OFF, measure impedance only

      // read temperature avery 160 ms

      get_temperature(&ds);

      /////////////////////////// Update Display //////////////////////////////

      if (s_reg & S_RF)
         // RF on, no no RF
         s_reg &=
         ~(S_9_5CC_NORF | S_MED_PRESS_NORF | S_HI_PRESS_NORF | S_HY_LIMIT_NORF);
      else
      {
         // RF off, set bits
         s_reg =
            s_reg & ~(S_9_5CC_NORF | S_MED_PRESS_NORF | S_HI_PRESS_NORF | S_HY_LIMIT_NORF)
            | ((s_reg & (S_9_5CC | S_MED_PRESS | S_HI_PRESS | S_HY_LIMIT)) << 1);
      }

      #ifdef DEBUG_LEVEL_CHECK // x.093

      // x.093, Debug code for level testing per IEC60601-2-2 Clause 51.5
      if ((displaytimer = timecount % SPS) == 0 || displaytimer == (SPS / 2))
      {
         sprintf(cDebugLevelText1, "Err 1S=%6d%% Cnt=%5u", ds.pwr_track_err, ds.loopCount);
         //sprintf(cDebugLevelText1, "Pset =%5u P=%5u", ds.power_setp, ds.RFpower);ds.faultCount
         gDFDisplyPrintText(cDebugLevelText1, MONOSPACE_TWELVE_PT_FONT, WHITE_ON_BLUE_COLOR, 10, 460);
      }
      else if (displaytimer == 4 || displaytimer == (SPS / 2) + 4)
      {
         sprintf(cDebugLevelText1, "Pset 1S=%5u P 1S=%5u", ds.power_setp_comp, ds.RFpower_comp);
         gDFDisplyPrintText(cDebugLevelText1, MONOSPACE_TWELVE_PT_FONT, WHITE_ON_BLUE_COLOR, 260, 460);

      }
      else if (displaytimer == 8 || displaytimer == (SPS / 2) + 8)
      {
         sprintf(cDebugLevelText1, "EMx=%5u%% Imp=%5u", sPerrPrcntMax, ds.imp_comp);
         gDFDisplyPrintText(cDebugLevelText1, MONOSPACE_TWELVE_PT_FONT, WHITE_ON_BLUE_COLOR, 505, 460);
      }

      #endif // #ifdef DEBUG_LEVEL_CHECK // x.093

      if ((displaytimer = timecount % SPS) == 0 || displaytimer == (SPS / 2))
      {
         display_time(ds.totalrfontime, RFCycleSPS);
      }
      else if (displaytimer == 4 || displaytimer == (SPS / 2) + 4)
      {
         /* refresh the RF power setting on display */
         gDFDisplyPrintPowerValueTextItem(pwr_setting);

      }
      else if (displaytimer == 6 || displaytimer == (SPS / 2) + 6 && !(ablate_bad_imp_cnt))
      {
         gDFDisplyPrintImpedanceGraphicItem(ds.impedance, isDeviceConnected(),
                                            ablate_bad_imp_cnt, 0);
      }
      else if (displaytimer == (SPS / 2) + 6 && ablate_bad_imp_cnt)
      {
         gDFDisplyPrintImpedanceGraphicItem(ds.impedance, isDeviceConnected(),
                                            ablate_bad_imp_cnt, 0);
      }
      else if (displaytimer == 18)
      {
         /*
          * Don't check for disconnected device until RF Cycle has been
          * adjusted by an up/down button push and set by exiting Settings mode
          */

         if ((RFCycleAdjusted == 0) || (PostStartupRFCycleAdjusted == 0))
         {
            /* Instead, blink RF Cycle */

            if (RFCycleEraseOnly == 0)
            {
               RFCycleEraseOnly = 1;
            }
            else
            {
               RFCycleEraseOnly = 0;
            }
            gDFDisplyPrintRFCycleValueTextItem(RFCycleSPS/SPS, 1, RFCycleEraseOnly);
         }
         else
         {
            if (RFCycleSet == 1)
            {
               /*
                * Before we get to the Device Connected logic, since we are also
                * supposed to flash RF Cycle for n seconds after an auto-shutoff,
                * we might as well check for it and do it here (close to the
                * other code that flashes it).
                */

               if (FlashRFCycleCount > 0)
               {
                  PriorFlashRFCycleCount = FlashRFCycleCount;
                  FlashRFCycleCount -= SPS;
                  if (RFCycleEraseOnly == 0)
                  {
                     RFCycleEraseOnly = 1;
                  }
                  else
                  {
                     RFCycleEraseOnly = 0;
                  }
                  gDFDisplyPrintRFCycleValueTextItem(RFCycleSPS/SPS, 1, RFCycleEraseOnly);
               }
               else
               {
                  if (PriorFlashRFCycleCount > 0)
                  {
                     /* We don't want to end up with blank RF Cycle displayed */

                     PriorFlashRFCycleCount = 0;
                     gDFDisplyPrintRFCycleValueTextItem(RFCycleSPS/SPS, 1, 0);
                  }
               }

               /* Now we'll do the Connect Device display logic */

               if (SettingsMode == 0)
               {
                  if (isDeviceConnected())
                  {
                     /* Device is connected, remove "Connect Device" prompt */

                     DeviceDisconnectReported = 0;
                     if (DeviceConnectReported == 0)
                     {
                        DeviceConnectReported = 1;
                        gDFDisplyPrintTextItem(CONNECT_DEVICE_DISPLAY_ITEM_ID,
                           "null", 0);

                        /*
                         * Display temperatures - one should be large font, other
                         * should be small font.
                         *
                         * Whichever the larger one is, blink it if either
                         * ablate_bad_tc1_cnt or ablate_bad_tc2_cnt is greater
                         * than 0 (if a temp is/was bad - but not so bad as to look
                         * like the handpiece is disconnected).
                         */

                        gDFDisplyPrintTemperatureValues(ds.setting,
                           ds.temperature2/10,
                           ds.temperature1/10,
                           ablate_bad_tc1_cnt || ablate_bad_tc2_cnt, 1, 0);
                     }

                     /* Update the temperatures */

                     gDFDisplyPrintTemperatureValues(ds.setting,
                        ds.temperature2/10,
                        ds.temperature1/10,
                        ablate_bad_tc1_cnt || ablate_bad_tc2_cnt, 0, 0);
                  }
                  else
                  {
                     /* Remove temperatures. Display "Connect Device" prompt */

                     DeviceConnectReported = 0;
                     if (DeviceDisconnectReported == 0)
                     {
                        DeviceDisconnectReported = 1;

                        gDFDisplyPrintTemperatureValues(ds.setting,
                           ds.temperature2/10,
                           ds.temperature1/10, 0, 1, 1);

                        gDFDisplyPrintTextItem(CONNECT_DEVICE_DISPLAY_ITEM_ID,
                           "null", 1);
                     }
                  }
               }
            }
         }

         /* (Indirectly) Sound tone if Proximal temperature is > 45 and RF is on */

         switch (ds.setting) /* what power level is currently selected */
         {
            case ABLATE_POWER_SETTING_LEVEL1: /* intentional fall-through */
            case ABLATE_POWER_SETTING_LEVEL2:

               if (ds.temperature2 < 450 && ds.rfon == 1)
               {
                  s_reg = 0;
                  s_reg = s_reg & ~(S_MOTOR | S_HI_PRESS | S_RESTART_EXP) | S_RF;
               }
               else if (ds.temperature2 >= 450 && ds.rfon == 1)
               {
                  s_reg = s_reg & ~(S_MOTOR | S_HI_PRESS | S_RESTART_EXP) | S_MED_PRESS;
               }

               break;

            default: /* should never happen */
               break;

         } /* end of switch (ds.setting) */

      } // end of else if (displaytimer == 18)

      tonechk(timecount, s_reg); // handle sounds

      if (gDFDisplyProcessDisplayRequests() == 0)
      {
         fault_routine(WARNING_SEVERITY, ERROR_DISPLAY_PROCESSING, "Display Processing");
      }

      if (((status = get_status()) & WATCH_DOG) == 0)
         fault_routine(FAULT_SEVERITY, ERROR_WATCHDOG, "Watchdog");

      KICK_THE_DOG; // update watchdog

   } // end of for (; ; timecount++)

   return switches;
}

/************************************************************************************************
* NAME:  gui[]
*
* DESCRIPTION:  Initialized array of stuctures that define the sound.
*
*************************************************************************************************/
static const struct guistr
{
   U16 sound;
}  gui[] = {
   {BEEP_INIT    }, // 0  Idle
   {BEEP_RF      }, // 1  RF + Motor
   {BEEP_WARNING }, // 2  9.5 cc, RF
   {BEEP_INIT    }, // 3  9.5 cc
   {BEEP_WARNING }, // 4  med press 500, RF
   {BEEP_INIT    }, // 5  med press 500
   {BEEP_WARNING }, // 6  hi press 700, RF
   {BEEP_INIT    }, // 7  hi press 700
   {BEEP_REPLACE1}, // 8  auto restart exp
   {BEEP_MOTOR   }, // 9  Motor only
   {BEEP_INIT    }, // 10 AE Checked
   {BEEP_REPLACE1}, // 11 AE Bad
   {BEEP_INIT    }, // 12 HY Checked
   {BEEP_REPLACE }, // 13 HY Bad
   {BEEP_REPLACE }, // 14 STOP pressed
   {BEEP_REPLACE }, // 15 syringe limit, RF
   {BEEP_INIT    }  // 16 syringe limit
};

#define GUISIZE (sizeof(gui)/sizeof(gui[0]))


/*****************************************************************************
* NAME:  tonechk()
*
* DESCRIPTION:  Handles tone generation based on status and time.
*
* PARMETERS:
*   timecount      - display time counter, 20 ms increment from first ENTER.
*   s_reg          - system status register.
*
* NOTES: Uses status and time to generate the appropriate sound.
*        Should be executed every 20 ms
*
* RETURN VALUE:
*    NONE
*
*****************************************************************************/
static void tonechk(U32 timecount, U32 s_reg)
{
   static S16 old_i = 0;
   S16 i;
   U16 sound;

   for (i = 0; s_reg != 0L; i++)          // find highest priority
      s_reg >>= 1;

   if (i == old_i || gui[i].sound == BEEP_RF && gui[old_i].sound == BEEP_RF)   // if no change
   {
      if (tone(BEEP_CHECK) == 0           // check tone timing
          && ((sound = gui[i].sound) == BEEP_MOTOR || sound == BEEP_RF
              || sound == BEEP_REPLACE || sound == BEEP_WARNING))
         tone(sound);                  // generate old tone, if off
      old_i = i;                       // remember what is going on
      return;
   }
   sound = gui[old_i].sound;
   old_i = i;                          // remember what is going on
   if (i == 0 && sound == BEEP_MOTOR)        // if the motor sound was on
      tone(BEEP_MOTOR_OFF);               // sound off
   else
      tone(gui[i].sound);                 // generate the sound
}

/*****************************************************************************
* NAME:         start_sequence()
*
* DESCRIPTION:  Handles display etc before timer start
*
* PARMETERS:
*
* RETURN VALUE: 1 if OK (always true)
*
*****************************************************************************/

static U16 start_sequence(U16 RFKflg) // returns OK = 1, NOK = 0
{
   U16 timecount = 0;
   S16 temperature = 0;
   U16 switches, rawswitches, status;
   int display_id;

   // initalize stuff
   imp_pulse_measure(NULL);                        // updates DAC and LEDs
   ds.rfon = ds.rfontime = 0;
   ds.totalrfontime = 0;
   ds.lastpressure = 0;                            // unused
   ds.initial_imp = 0;
   ds.RFpower = 0;

   ds.RFpower_comp = ds.RFpower_ave = 0;           // x.093
   ds.power_setp_comp = ds.power_setp_ave = 0;     // x.093
   ds.pwr_track_err = 0;                           // x.093

   ds.RFvoltage = ds.RFcurrent = 0;
   ds.acc_power = 0L;
   ds.power_setp = RF_MIN_POWER;                   // 0.5 W

   ds.looptime = ds.loopCount = 0;                 // x.093
   ds.faultCount = 0;                              // x.093

   RFON_LED = MOTOR_LED = 0;                       // all latched LEDs off

   get_temperature(&ds);                           // read temperature

   gDFDisplyPrintTextItem(SW_VERSION_DISPLAY_ITEM_ID, SWVER, 1);

   while (gDFDisplyDoesGraphicDisplayHaveWorkToDo() == 1)
   {
      wait_for_20ms();
      if (gDFDisplyProcessDisplayRequests() == 0)
      {
         fault_routine(WARNING_SEVERITY, ERROR_SW_VERSION, "Version");
      }
      KICK_THE_DOG;
   }

   imp_pulse_measure(NULL); // start to measure impedance
   for (timecount = 0; timecount < DISPLAY_WAIT * SPS; timecount++) // wait 2 seconds
   {
      wait_for_20ms();
      imp_pulse_measure(&ds);
      get_temperature(&ds);
      tone(BEEP_CHECK);
      KICK_THE_DOG;
   }
   timecount %= SPS;

   RFKflg = 1; /* always force ablate mode in this ablate only device. */

   if (RFKflg == 1)
   {
      /* Write all of the graphics to the screen */

      for (display_id = THERAPY_BKGND_DISPLAY_ITEM_ID;
           display_id <= OHMS_SYMBOL_DISPLAY_ITEM_ID;
           display_id++)
      {
         gDFDisplyPrintGraphicItem(display_id);

         while (gDFDisplyDoesGraphicDisplayHaveWorkToDo() == 1)
         {
            wait_for_20ms();
            if (gDFDisplyProcessDisplayRequests() == 0)
            {
               fault_routine(WARNING_SEVERITY, ERROR_GRAPHICS, "Initial Graphics");
            }
            KICK_THE_DOG;
         }
      }

      /* Note that the Therapy screen (with it's black bkgnd) is now up */

      Screen = THERAPY_DISPLAY_SCREEN;

      /* Write the Impedance bar graph (just the border) to the screen */

      gDFDisplyPrintImpedanceGraphicItem(0, 0, 0, 0);

      while (gDFDisplyDoesGraphicDisplayHaveWorkToDo() == 1)
      {
         wait_for_20ms();
         if (gDFDisplyProcessDisplayRequests() == 0)
         {
            fault_routine(WARNING_SEVERITY, ERROR_IMPEDANCE, "Initial Impedance bar");
         }
         KICK_THE_DOG;
      }

      /* Write all of the labels to the screen */

      for (display_id = RF_CYCLE_LABEL_DISPLAY_ITEM_ID;
           display_id <= TIMER_BTN_LABEL_DISPLAY_ITEM_ID;
           display_id++)
      {
         gDFDisplyPrintTextItem(display_id, " ", 0);

         while (gDFDisplyDoesGraphicDisplayHaveWorkToDo() == 1)
         {
            wait_for_20ms();
            if (gDFDisplyProcessDisplayRequests() == 0)
            {
               fault_routine(WARNING_SEVERITY, ERROR_LABELS, "Initial Labels");
            }
            KICK_THE_DOG;
         }
      }

      /* Write the initial Cycles value (0) to the screen */

      gDFDisplyPrintCyclesValueTextItem(Cycles);

      while (gDFDisplyDoesGraphicDisplayHaveWorkToDo() == 1)
      {
         wait_for_20ms();
         if (gDFDisplyProcessDisplayRequests() == 0)
         {
            fault_routine(WARNING_SEVERITY, ERROR_CYCLES, "Initial Cycles");
         }
         KICK_THE_DOG;
      }

      wait_for_20ms();

      ablate_loop();
   }

   wait_for_20ms();
   return 1;
}

/*****************************************************************************
* NAME:         ablate_bad()
*
* DESCRIPTION:  Checks if activation element is bad for ablate.
*
* PARMETERS:    dfp - Pointer to DFinestruct structure.
*
* NOTES:        Checks temperature of activation element NTC and TC.
*
* RETURN VALUE:
*    appropriate code(s) if activation element is bad, otherwise zero
*
* This function is <IEC 62304 CLASS C>
*
*****************************************************************************/

static int ntc_avg = 0;
static int ntc_comp = 0;

static U16 ablate_bad(struct DFinestruct *dfp)
{
   U16 code = 0;
   static S32 slTemp2;

   /* Add new values to sums for various variables (prior to averaging) */

   dfp->looptime       = dfp->looptime      + 1;
   dfp->imp_avg        = dfp->imp_avg       + dfp->impedance;
   dfp->t1_avg         = dfp->t1_avg        + dfp->temperature1;
   dfp->t2_avg         = dfp->t2_avg        + dfp->temperature2;
   ntc_avg             = ntc_avg            + dfp->ntc_temp;

   // divide power by 32 so accumulator doesn't overflow at 25 watts

   dfp->RFpower_ave    = dfp->RFpower_ave   + (dfp->RFpower/32);     // x.093
   dfp->power_setp_ave = dfp->power_setp_ave+ (dfp->power_setp/32);  // x.093

   /* Is it time to average (has it been 1s) ? */

   if (dfp->looptime==50)
   {
      #ifdef DEBUG_LEVEL_CHECK   // x.093
      uCount2++;
      #endif                     // x.093

      /* Average */

      dfp->imp_comp=dfp->imp_avg/50;
      dfp->imp_avg=0;

      dfp->t1_comp=dfp->t1_avg/50;
      dfp->t1_avg=0;

      dfp->t2_comp=dfp->t2_avg/50;
      dfp->t2_avg=0;

      ntc_comp=ntc_avg/50;
      ntc_avg=0;

      dfp->RFpower_comp    =(dfp->RFpower_ave/50) *32;                 // x.093
      dfp->power_setp_comp =(dfp->power_setp_ave/50) *32;              // x.093
      slTemp2              = dfp->RFpower_comp - dfp->power_setp_comp; // x.093

      // Don't take absolute value of pwr_track_err.                   // x.093
      // Only the upper power limit (percentage) needs to be checked.  // x.093

      dfp->pwr_track_err   = (slTemp2 * 100) / dfp->power_setp_comp;   // x.093
      dfp->RFpower_ave=0;                                              // x.093
      dfp->power_setp_ave=0;                                           // x.093

      dfp->looptime=0;

      // Start of x.093 change block ------------------------------------------

      // Check RF on power limit

      if(dfp->rfon)
      {
         dfp->loopCount++;

         // Has RF power been on long enough to check limit?

         if(dfp->loopCount >= POWER_LIMIT_TEST_HOLD_OFF)
         {
            #ifdef DEBUG_LEVEL_CHECK
            if(dfp->pwr_track_err  > sPerrPrcntMax)
            {
               sPerrPrcntMax =  ds.pwr_track_err;
            }
            #endif

            // Is the RF power too high?

            if(ds.pwr_track_err > POWER_ERROR_PCT_LIMIT)
            {
               // The power must be over the limit POWER_FAULT_COUNT consecutive
               // times. Also, there is a condition caused by shorting the
               // output where the power drops to zero - don't set the error
               // fault when the power drops to zero.

               if(++(dfp->faultCount) >= POWER_FAULT_COUNT && dfp->RFpower_comp > 100)
               {
                  fault_routine(FAULT_SEVERITY, ERROR_POWER, "RF Circuitry");
               }
            }
            else
            {
               dfp->faultCount = 0;
            }
         }
      }

      // End of x.093 change block --------------------------------------------

      /* Now check the averages against various thresholds */

      switch (dfp->setting)
      {
         case ABLATE_POWER_SETTING_LEVEL1: // intentional fall-through
         case ABLATE_POWER_SETTING_LEVEL2:

            // check TC1 is within temperature range.

            #ifdef DEBUG_LEVEL_CHECK // x.094
            if ((dfp->t1_comp < 150) || (dfp->t1_comp > 1500))  // Lower the start temp to 15 for testing // x.093
            #else
            if ((dfp->t1_comp < 300) || (dfp->t1_comp > 1500))
            #endif
            {
               code |= ABLATE_BAD_TC1;
            }

            // check TC2 is within temperature range.

            #ifdef DEBUG_LEVEL_CHECK // x.094
            if ((dfp->t2_comp < 150) || (dfp->t2_comp > 1500))  // Lower the start temp to 15 for testing // x.093
            #else
            if ((dfp->t2_comp < 300) || (dfp->t2_comp > 1500))
            #endif
            {
               code |= ABLATE_BAD_TC2;
            }
            if (dfp->t2_comp > 500)
            {
               code |= ABLATE_BAD_TC2;
            }
            if ((ntc_comp < 120) || (ntc_comp > 500))
            {
               code |= ABLATE_BAD_AMB;
            }

            break;

         default: // should never happen
            break;
      }

      if ((isImpedanceTooLow(dfp->imp_comp)) || (dfp->imp_comp >= 9999))
      {
         code |= ABLATE_BAD_IMP;
      }
   }

   return code;
}


/*****************************************************************************
* NAME:         display_time()
*
* DESCRIPTION:  Display RF Cycle and RF Total time.
*
* PARMETERS:
*               total_rf_counts  - total accumulated rf counts
*               rf_cycle_counts  - current rf cycle counts
*
* NOTES:        Display RF Total max is 99:00
*
* RETURN VALUE: NONE
*
*****************************************************************************/

static void display_time(U32 total_rf_counts, U16 rf_cycle_counts)
{
   if ((total_rf_counts/SPS) > (99 * 60))
   {
      /* Need to cast SPS here or calculation is way off */

      total_rf_counts = ((U32) SPS) * 99 * 60;
   }

   /*
    * The RF Total time counts up. The RF Cycle time counts down.
    * Users will naturally try to crosscheck the RF Cycle time against the
    * RF Total time as in: if RF Cycle says 00:08 and the auto-shutoff time was
    * 30, they'll want to see the RF Total time be 00:22.
    *
    * As natural as this seems for the user, the reality is that behind the
    * scenes the numbers are more like RF Cycle = 7.5 and RF Total = 22.5.
    * The fraction comes from the fact that both counters increment at a 50 Hz
    * rate (or approximately every 20ms) - they increment at fraction of a
    * second intervals.
    *
    * To get from counts to seconds we have to divide by SPS.
    *
    * If we simply let implicit integer truncation (count / SPS) occur, the
    * two values often don't "add up".
    *
    * If we add a half of SPS to both counters ((count+(SPS/2)) the values
    * "add up" practically all of the time but can still end up with:
    * RF Cycle = 00:08 while RF Total == 00:23
    * when the RF Cycle count is 375 and the RF Total count is 1125
    * because (375+SPS/2)/SPS = 8 and (1125+SPS/2)/SPS = 23.
    *
    * The below checks to see if the rounding of both counters would add a 00:01
    * to both, and if it does, to instead just add it to RF Total. We had to
    * choose which one to favor, RF Cycle or RF Total, and it seemed more
    * correct to favor the one that is counting up / accumulating.
    * It's only a temporary favor, the counters aren't actually changed, just
    * the displayed value - so when the count moves on over time, the displayed
    * values will self-correct.
    */

   gDFDisplyPrintRFToTalValueTextItem((total_rf_counts+(SPS/2))/SPS);

   if ((((total_rf_counts % SPS)+(SPS/2))/SPS)+
       (((rf_cycle_counts % SPS)+(SPS/2))/SPS) > 1)
   {
      gDFDisplyPrintRFCycleValueTextItem(rf_cycle_counts/SPS, 0, 0);
   }
   else
   {
      gDFDisplyPrintRFCycleValueTextItem((rf_cycle_counts+(SPS/2))/SPS, 0, 0);
   }
}


/*****************************************************************************
* NAME:  TempControl()
*
* DESCRIPTION:  performs PI control of temperature.
*
* PARMETERS:
*   OldPower       - Old power setpoint scaled to 1 mW per bit
*   TempSet        - Temperature setpoint scaled to 0.1C per bit
*   Temperature    - actual temperature scaled to 0.1C per bit
*
* NOTES: Should be executed once with actual temperature as initialization, since last data is used in routine.
*        Should be executed every 20 ms
*
* RETURN VALUE:
*    New power setpoint scaled to 1 mW per bit
*
* This function is <IEC 62304 CLASS C>
*
*****************************************************************************/
U16 TempControl(U16 OldPower, S16 TempSet, S16 Temperature)
{
   static S16 OldTemp;
   S32 NewPower;
   U16 MAXPower;

   NewPower = (S32)OldPower
              + (S32)(TempSet - Temperature) * 20L    //   Ki
              + (S32)(OldTemp - Temperature) * 160L; // 120 Kp
   OldTemp = Temperature;
   if (NewPower < 0L)
      return 0;
   if (NewPower > 25000L)
      return 25000;
   return(U16)NewPower;
}

/*****************************************************************************
* NAME:  ablate_power()
*
* DESCRIPTION:  Performs ablate power control and measures impedance.
*
* PARMETERS:
*   dfp            - Pointer to DFinestruct structure.
*   setting        - power setting 1,2, or 3.
*
* NOTES: Performs PI control of RF VA power.
*        Calculates VA setpoint from setting.
*        Measures impedance, voltage and current.
*        Should be executed every 20 ms
*
* RETURN VALUE:
*    NONE
*
* This function is <IEC 62304 CLASS C>
*
*****************************************************************************/

/* Power setting setpoints (in milliwatts) */

#define RF_MILLIWATT_PWR_LEVEL1    5000L /*  5000 milliwatts =  5 watts */
#define RF_MILLIWATT_PWR_LEVEL2   10000L /* 10000 milliwatts = 10 watts */

/* power setting index to value tables */

static const U16 ablate_powers[NUM_ABLATE_POWER_SETTING_INDICES] =
{RF_MILLIWATT_PWR_LEVEL1, RF_MILLIWATT_PWR_LEVEL2};

static const U16 ablate_temps [NUM_ABLATE_POWER_SETTING_INDICES] = {1600,  1600}; // 5W, 10W
static const U16 ablate_ramps [NUM_ABLATE_POWER_SETTING_INDICES] = {  20,    30}; // 5W, 10W


static void ablate_power(struct DFinestruct *dfp, U16 setting) // measure impedance when RF is on
{
   static U16 zmin, zinit, DACvalue = 0;
   U16 max_power,power_ramp;
   U32 impedance_scale;
   S16 data[4];                  // RF ADC values

   read_RF_ADC(data);               // read RF ADC values
   if ((data[2] = (S16)(((S32)data[2] * es.RFpowerscale) / 8191L)) < 0) //~26.67W FS
      data[2] = 0;
   dfp->RFpower = data[2];                            // measured power
   dfp->RFvoltage = (S16)(((S32)data[0] * es.RFvoltagescale) / 8191L);           //175.75 V FS
   dfp->RFcurrent = (S16)(((S32)data[1] * es.RFcurrentscale) / 8191L);           //0.543 A FS

   if (dfp->rfontime == 0)
   {
      DACvalue = 0;
      dfp->power_setp = RF_MIN_POWER;
      dfp->pramp = 100;
      powercontrol(0, 0, dfp->RFpower);
      TempControl(0, 0, dfp->temperature1);
   }
   else
   {
      max_power = ablate_powers[setting - ABLATE_POWER_SETTING_MINNDX];

      dfp->pramp=dfp->pramp+ablate_ramps[setting - ABLATE_POWER_SETTING_MINNDX];
      if (dfp->pramp>=max_power) dfp->pramp = max_power;
      max_power = dfp->pramp;


      if (dfp->rfontime > 15)  // wait a little to update impedance
      {
         // original calculation not rendered correctly
         // impedance_scale = ((U32)(es.RFvoltagescale) * 10000L) / (U32)(es.RFcurrentscale);
         impedance_scale = ((U32)(es.RFvoltagescale) * 10000L);
         impedance_scale /= (U32)(es.RFcurrentscale);
         if (data[0] <= 0)
            dfp->impedance = 0;
         else
            dfp->impedance = data[1] > 0 ? (((U32)data[0] * impedance_scale) / (U32)data[1]) / 100L : 9999;
      }
      dfp->power_setp = TempControl(dfp->power_setp, ablate_temps[setting - ABLATE_POWER_SETTING_MINNDX], dfp->temperature1); // setpoint 80,85,or 90C
      if (dfp->power_setp < RF_MIN_POWER)
         dfp->power_setp = RF_MIN_POWER;
      else if (dfp->power_setp > max_power)
         dfp->power_setp = max_power;

      /* Calculate next DACvalue, based on previous DACvalue, power  */
      /*  setpoint and power measured                                */
      DACvalue = powercontrol(DACvalue, dfp->power_setp, dfp->RFpower);
   }


   write_DAC(DACvalue >> 4, RFDAC_CTRL_RF_ON_AND_ABLATING);

   return;
}
/*****************************************************************************
* NAME:         fault_routine()
*
* DESCRIPTION:  Displays fault on screen until power is cycled.
*
* PARMETERS:
*               severity - Warning or Fault
*               number   - Error number.
*               message  - Optional error message (currently not used).
*
* NOTES:        Blinks fault or warning LED.
*               Plays fault "tune".
*               Turns off RF (and it's animating icon).
*               Displays fault or warning icon.
*               Displays error number.
*
* RETURN VALUE: NONE
*
* This function is <IEC 62304 CLASS C>
*
*****************************************************************************/

void fault_routine(ERROR_SEVERITY severity, U16 number, const char *message)
{
   U8 led;
   U16 timecount = 0;

   /* Turn on LEDs (Power and error severity) */

   if (severity == WARNING_SEVERITY)
   {
      led = LED_WARNING;
   }
   else
   {
      led = LED_FAULT;
   }
   write_LEDs(LED_ON | led);

   /* Start error tone */

   tone(BEEP_FAULT);

   /* Turn off RF */

   imp_pulse_measure(NULL);
   write_DAC(0, RFDAC_CTRL_RF_MOTOR_AND_RELAY_ALL_OFF);

   /* Turn on LEDs again */

   write_LEDs(LED_ON | led);

   /* Output message to screen */

   gDFDisplyPrintErrorItem(severity, number, message, Screen);

   /*
    * Turn off the radiating rf icon - but only if we made it at least as far
    * as the Therapy screen (otherwise it leaves a black rectangle on the blue
    * Splash screen)
    */

   if (Screen == THERAPY_DISPLAY_SCREEN)
   {
      gDFDisplyDisableRFGraphicItem();
   }

   /* ablate_loop() isn't processing display events any more - so we have to */

   while (gDFDisplyDoesGraphicDisplayHaveWorkToDo() == 1)
   {
      wait_for_20ms();
      if (gDFDisplyProcessDisplayRequests() == 0)
      {
         break;
      }
      KICK_THE_DOG;
   }

   /* Blink LED */

   while (1)
   {
      wait_for_20ms();
      if (++timecount == SPS)
      {
         timecount = 0;
         write_LEDs(LED_ON | led);
      }
      else if (timecount == SPS / 2)
         write_LEDs(LED_ON);

      tone(BEEP_CHECK);
   }
}
/*****************************************************************************
* NAME:  get_temperature()
*
* DESCRIPTION:  Gets temperature from CJC device.
*
* PARMETERS:
*   dfp            - Pointer to DFinestruct structure.
*
* NOTES: Cycles all SPI ADC inputs.
*        Updates ambient temperature every 160 ms.
*        Should be executed every 20 ms
*
* RETURN VALUE:
*    NONE
*
* This function is <IEC 62304 CLASS C>
*
*****************************************************************************/

#define NUM_MEDIAN_SAMPLES (3)

static void get_temperature(struct DFinestruct *dfp)     // update ambient temperature
{
   // Only scan channels 0-2,
   // perform 3 sample median filtering on all temperatures.

   // SPI_TEMPERATURE1 = 0
   // SPI_TEMPERATURE2 = 1
   // SPI_NTC = 2

   static U8  next_index = SPI_TEMPERATURE1;
   static U16 tccnt      = 0;

   // median filter with window size of NUM_MEDIAN_SAMPLES

   static U16 tc1_median_input[NUM_MEDIAN_SAMPLES] = {0,0,0};
   static U16 tc2_median_input[NUM_MEDIAN_SAMPLES] = {0,0,0};
   static U16 ntc_median_input[NUM_MEDIAN_SAMPLES] = {0,0,0};

   static U8  tc1_median_index =  0;
   static U8  tc2_median_index =  0;
   static U8  ntc_median_index =  0;

   U8  index;
   U16 data;

   index = next_index;

   if(++next_index > SPI_NTC)
   {
      next_index = SPI_TEMPERATURE1;
   }

   data = read_SPI_ADC(next_index);    // read SPI and start new convert

   if (index == SPI_TEMPERATURE1)
   {
      /// update rolling window with new data

      if (++tc1_median_index >= NUM_MEDIAN_SAMPLES)
      {
         tc1_median_index = 0;
      }
      tc1_median_input[tc1_median_index] = data;

      dfp->temperature1 =
         convert_to_degrees(calc_median(tc1_median_input) + tccnt);
   }
   else if (index == SPI_TEMPERATURE2)
   {
      if (++tc2_median_index >= NUM_MEDIAN_SAMPLES)
      {
         tc2_median_index = 0;
      }
      tc2_median_input[tc2_median_index] = data;

      dfp->temperature2 =
         convert_to_degrees(calc_median(tc2_median_input) + tccnt);
   }
   else if (index == SPI_NTC)
   {
      if (++ntc_median_index >= NUM_MEDIAN_SAMPLES)
      {
         ntc_median_index = 0;
      }
      ntc_median_input[ntc_median_index] = data;

      tccnt = convert_ntc(calc_median(ntc_median_input), &(dfp->ntc_temp));
   }
}

/*****************************************************************************
* NAME:  imp_pulse_measure()
*
* DESCRIPTION:  Measures impedance when RF is off.
*
* PARMETERS:
*   dfp            - Pointer to DFinestruct structure.
*
* NOTES: Generates short RF pulse evey 2 seconds and measures impedance.
*        RF LED is blinked every RF pulse.
*        Should be executed every 20 ms
*
* RETURN VALUE:
*    NONE
*
* This function is <IEC 62304 CLASS C>
*
*****************************************************************************/
static void imp_pulse_measure(struct DFinestruct *dfp)      // measure impedance when RF is off
{
   static U16 pulseintcnt = 0;
   U32 impedance_scale;
   S16 data[4];            // RF ADC values



   if (dfp == NULL)                        // initialize if pointer is NULL
   {
      write_DAC(0, RFDAC_CTRL_RF_OFF_MTRRLY_OFF_RFRLY_ON);
      write_LEDs(LED_ON);
      pulseintcnt = 0;
      return;
   }

   if (++pulseintcnt >= SPS * 2)              // two second cycle
   {
      pulseintcnt = 0;
      write_LEDs(LED_ON);
   }
   else if (pulseintcnt == SPS * 2 - 10)    // turn on LED and DAC
   {
      write_LEDs(LED_ON | LED_RF);
      write_DAC(RF_DAC_1W, RFDAC_CTRL_RF_ON_AND_ABLATING);
   }
   else if (pulseintcnt == SPS * 2 - 8)     // measure and turn off DAC
   {
      read_RF_ADC(data);
      // original calculation not rendered correctly
      // impedance_scale = ((U32)(es.RFvoltagescale) * 10000L) / (U32)(es.RFcurrentscale);
      impedance_scale = ((U32)(es.RFvoltagescale) * 10000L);
      impedance_scale /= (U32)(es.RFcurrentscale);
      if (data[0] <= 0)
         dfp->impedance = 0;
      else
         dfp->impedance = data[1] > 0 ? (((U32)data[0] * impedance_scale) / (U32)data[1]) / 100L : 9999;
      write_DAC(0, RFDAC_CTRL_RF_OFF_MTRRLY_OFF_RFRLY_ON);
   }
}

/*****************************************************************************
* NAME:  isDeviceConnected()
*
* DESCRIPTION:  Checks the thermal-couples in probe to be higher than expected.
*               This indicates open circuit on thermal-couple (device not
*               connected or broke electrically "open")
*
* PARMETERS:
*
* NOTES: Checks if device is connected by looking at ADC readings device thermo
* couple lines.  They go high temp (above 1500 C) if not connected.
*
* RETURN VALUE:
*    None Zero if Connected, 0 if Not apparently connected
*
*****************************************************************************/
static U16 isDeviceConnected()
{
   U16 is_device_connected;

   if (ds.temperature1 <= 1500 && ds.temperature2 <= 1500)
   {
      is_device_connected = 1;
   }
   else
   {
      is_device_connected = 0;
   }

   return(is_device_connected);
}


/*****************************************************************************
* NAME:  isImpedanceTooLow()
*
* DESCRIPTION:  Checks if impedance of probe (tip-to-ring) is too low.
*
* PARMETERS:
*   status         -
*
*
* NOTES: Checks if device is connected by looking at ADC readings of voltage
*        and current going through probe.
*
* RETURN VALUE:
*    Non-zero if impedance too low (short circuit)), 0 if impedance OK with
*    respect to being too low end. (too high is not check by this function)
*
*****************************************************************************/
static U16 isImpedanceTooLow(U16 impedance)
{
   U16 is_impedance_too_low;

   if (impedance < IMPEDANCE_MIN)   // less than IMPEDANCE_MIN-1 deci-ohms is considered a short circuit
   // use IMPEDANCE_MIN deci-ohms is considered inbounds/OK value
   {
      is_impedance_too_low = 1;
   }
   else
   {
      is_impedance_too_low = 0;
   }

   return(is_impedance_too_low);
}


/*****************************************************************************
* NAME:         SetPowerSetting()
*
* DESCRIPTION:  Syncronizes the user setting the power level
*               with the associated max DAC value.
*
* PARAMETERS:
*               new_pwr_setting - operator selected power setting.
*                                 1 is lowest, 2 is highest.
*
* RETURN VALUE: None.
*
*****************************************************************************/
static void SetPowerSetting(U16 new_pwr_setting)
{
   ds.setting = new_pwr_setting;
}

/*============================================================================*/
/*
 * Static:        EnterSettingsMode
 *
 * Description:   This function performs the actions required to enter "Settings
 *                Mode", the mode where settings may be changed, settings such
 *                as the RF Cycle Preset value.
 *
 * Parameters:    None
 *
 * Returns:       None
 *
 * Side-effects:  None
 */

static void EnterSettingsMode()
{
   /* Set flag that prevents most operations while in the mode */

   SettingsMode = 1;

   /* Init the RF Cycle value to the preset */

   RFCycleSPS = RFCycleSPSPreset;

   /* Turn off any flashing of the RF Cycle value that may be in effect */

   FlashRFCycleCount = 0;

   /* Arm the logic that flashes RF Cycle until an adjustment is made */

   PostStartupRFCycleAdjusted = 0;

   /* Change the labels on and the colors of the up and down buttons */

   gDFDisplySetProgrammableButtons(TIMER_BTN_LABEL_DISPLAY_ITEM_ID);

   /* Turn off any flashing of Connect Device that may be going on */

   gDFDisplyPrintTextItem(CONNECT_DEVICE_DISPLAY_ITEM_ID, "null", 0);

   /* Erase any temperatures that may be displayed */

   gDFDisplyPrintTemperatureValues(ds.setting, ds.temperature2/10,
                                   ds.temperature1/10, 0, 1, 1);
}

/*============================================================================*/
/*
 * Static:        ExitSettingsMode
 *
 * Description:   Exit "Settings Mode". See EnterSettingsMode() for more info.
 *
 * Parameters:    None
 *
 * Returns:       None
 *
 * Side-effects:  None
 */

static void ExitSettingsMode()
{
   /* Clear flag that prevents most operations while in mode */

   SettingsMode = 0;

   /* Get rid of the fraction (of a sec) that may be in the preset */

   /*
    * We could just round or truncate but see note in display_time() regarding
    * interplay between Total RF and RF Cycle.
    */

   if ((((ds.totalrfontime % SPS)+(SPS/2))/SPS)+
       (((RFCycleSPSPreset % SPS)+(SPS/2))/SPS) > 1)
   {
      RFCycleSPSPreset = RFCycleSPSPreset / SPS * SPS;
   }
   else
   {
      RFCycleSPSPreset = ((RFCycleSPSPreset + (SPS/2)) / SPS) * SPS;
   }

   /* Set RF Cycle to the normalized preset */

   RFCycleSPS = RFCycleSPSPreset;

   /*
    * Set the flag that indicates that the RF Cycle value has been set.
    * (The flag is initialized to 0 at power on and is set to 1 the first time
    * the RF Cycle value is set. It's used to prevent the user from doing
    * anything else until they set the RF Cycle value and to inhibit any
    * "Connect Device" message that might be pending until they do so.)
    *
    * It's also set anytime they exit Settings Mode therafter but the application
    * doesn't care after the first time.
    */

   RFCycleSet = 1;

   /* Disarm the logic that flashes RF Cycle until an adjustment is made */
   /* (In case they entered Settings Mode manually but didn't make any adjustment) */

   PostStartupRFCycleAdjusted = 1;

   /* Change the labels on and the colors of the up and down buttons */

   gDFDisplySetProgrammableButtons(POWER_BTN_LABEL_DISPLAY_ITEM_ID);

   /*
    * Reset the variables that track whether a Connect Device has been
    * reported or not - so that they start out as if neither was reported
    * (so that it'll report either again as we come out of Settings mode).
    */

   DeviceConnectReported    = 0;
   DeviceDisconnectReported = 0;
}

/*============================================================================*/
/*
 * Static:        calc_median
 *
 * Description:   Find the median (middle) value in an array of three values.
 *
 * Parameters:    array - the array
 *
 * Returns:       median
 *
 * Side-effects:  None
 */

static U16 calc_median(U16 *in_array)
{
   U16 tmp_a = in_array[0];
   U16 tmp_b = in_array[1];
   U16 tmp_c = in_array[2];

   if (tmp_a > tmp_b)
   {
      if (tmp_a > tmp_c)
      {
         if (tmp_b > tmp_c)
         {
            tmp_a = tmp_b;
         }
         else
         {
            tmp_a = tmp_c;
         }
      }
   }
   else
   {
      if (tmp_a < tmp_c)
      {
         if (tmp_b > tmp_c)
         {
            tmp_a = tmp_c;
         }
         else
         {
            tmp_a = tmp_b;
         }
      }
   }

   return (tmp_a);
}

