/*******************************************************************************
* Copyright (c) 2010 - 2011 Minnetronix, Inc.  All rights reserved.            *
*******************************************************************************/
/*******************************************************************************
*
*   $Source: dfine.h $
*   $Revision: 1.30 $
*     Project: Rubik
*       $Date: 2012/02/02 10:44:20CST $
*
*-------------------------------------------------------------------------------
*
*  This file is <IEC 62304 CLASS C>
*
* Description:  This is the principal header file for the Rubik DFine ablation
*               device.
*
*  Files and or functions marked with <IEC 62304 CLASS C> are considered
*     IEC 62304 Class 'C' and shall be treated accordingly. Changes to these
*     software components shall be tracked by issue. The altered code shall
*     be HUT (Heavy Unit Test) tested or data shall be provided of complete
*     testing during verification.
*
*******************************************************************************/

#ifndef  __DFINE_H__                        /* Prevents multiple inclusion */
#define  __DFINE_H__

/*******************************************************************************
********************* Application Globals **************************************
*******************************************************************************/

#define SWVER  "S/V x.095.AB" // Software version

// production settings

// comment out for production
// comment in/enable for DFTEST application
#define DFTEST

// comment out for production
// comment in for Debug code for level testing per IEC60601-2-2 Clause 51.5
#define DEBUG_LEVEL_CHECK

#define CHECK_CRC 1    // 0 = Inhibits CRC during development & debugging,
                       // 1 = ENABLE WHEN CHECKED IN (always CRC checked in code)

#define ROM_CRC_VALUE 0xDC68 // <------ insert pre-calculated/expected CRC here
                             // See SDD (in MKS) for procedure for updating CRC

// types

#define U8        unsigned char
#define U16       unsigned int
#define U32       unsigned long
#define S8        signed char
#define S16       signed int
#define S32       signed long
#define BOOLEAN   bit

// 256 kbyte FLASH, 16 kbyte of regular ram in the PIC24H, DMARAM is above it

#define FLASHSIZE    0x2AC00L                    // 0x40000 * 2 / 3, 256 kbytes
#define RAMSTART ((__far unsigned char *)0x0800) // start of RAM

//    used for hc/adaq/display
#define DMARAM ((__far unsigned char *)0x4000)   // MUST be declared __far
#define DMARAMSIZE      0x800                    // Size of DMA RAM
#define RX1DMABUFSIZ 16                          // UART1 receive DMA buffer size
//    used for hc comm
#define TX1DMABUF (DMARAM+0x00)                  // 8 bytes for transmit
#define RX1DMABUF (TX1DMABUF+8)                  // 16 bytes for receive
//    used for ADAQ comm
#define TX2DMABUF (RX1DMABUF+RX1DMABUFSIZ)       // 0x100 for transmit ADAQ
#define RX2DMABUF (TX2DMABUF+0x100)              // 0x100 for receive
#define SPI2DMABUF (RX2DMABUF+0x100)             // dummy for SPI2 receive

// Reach Technology display serial commands are  no longer than 127 characters
// including the carriage return terminator. It's not clear what the longest
// command response would be. There are several commands that return lists
// that can be fairly long. Since we aren't using these list commands, we'll
// just assume the response is no longer than the max command length.

#define DISPLAY_CMD_MAX_LEN (127)

// SPI RX buffer precedes our buffer in DMA RAM.
// Since it was at the end (prior to Mntx adding the Reach Technology display),
// other developers didn't bother to dimension it.
// Looks like - see check_usb() - it's only used for RX.Existing code TXs out
// of TX2DMABUF. Size of SPI RX buffer could have been limited to the 10 used
// in check_usb() but there's plenty of DMA RAM so we'll give it the 0x100
// that they gave to most of the other buffers. We add one to DISPLAY_CMD_MAX_LEN
// to make it an even number. It's good practice (and some processors care)
// to start blocks on even boundaries.

#define DISPLAY_TX2_DMA_BUF (SPI2DMABUF+0x100)
#define DISPLAY_RX2_DMA_BUF (DISPLAY_TX2_DMA_BUF+DISPLAY_CMD_MAX_LEN+1)

struct EEPROMstruct {            // stuff stored in EEPROM
   U8 serialnumber[8];           // serial number text
   U8 type[2];                   // hardware revision text
   U8 testdate[6];               // test date text
   U8 tester[4];                 // test technician initials
   U16 pressureoffset;           // pressure sensor offset, ADC count // unused
   U16 pressuregain;             // pressure sensor FS, PSI res.      // unused
   U16 RFpowerscale;             // RF power full scale, 1/1000 W res.
   U16 RFvoltagescale;           // RF voltage full scale, 1/100 V res.
   U16 RFcurrentscale;           // RF current full scale, 1/1000 A res.
   U16 crc;
};

#ifdef   DFTEST
struct postRFstruct              // values generated in POST rf function
{
   S16 data[4];
   U16 prim_volt;
   U16 prim_curr;
   S16 voltage;
   S16 current;
   S16 power;
   U32 impedance_scale;
   S16 impedance;
   S32 power_delta;

   U16 wd_expired_time;
   S16 wd_expired_power;
   S16 wd_power;
   U8  wd_stat1;
   U8  wd_stat2;
};
#endif

#define HC_SPEED1          5     // default HC speed1 is 0.5 cc/min
#define HC_SPEED2          13    // default HC speed2 is 1.3 cc/min
#define HC_HIGH_SPEED      30    // high HC speed is 3.0 cc/min
#define HC_PULLBACK        102   // HC pullback speed is 10.2 cc/min for a 16.10 mm syringe, 2.54 mm pitch
#define HC_MAX_VOL         125   // HC maximum volume, 12.5 cc
#define HC_PULLB_TIME      120   // HC pullback time 120 seconds
#define HC_CHG_CARTR       95    // change Cement Cartridge at 9.5 cc
#define RETRACT_TIME       7     // STOP button retract time 7 seconds
#define REMIX_BUTTON_TIME  5     // REMIX button time 5 seconds
#define RF_POWER1          3400  // RF max power is 3.4 W at 65 F
#define RF_POWER2          2300  // RF hi power is 2.3  W at 65 F
#define RF_LO_POWER        1900  // RF lo power is 1.9 W at 65 F
#define RF_NEG_SLOPE_POWER 2500  // RF lo power is 2.5 W at 65 F
#define RF_MIN_POWER       100   // RF minimum power is 0.5 W
#define RF_PRESS_LO        0     // low pressure for low speed at RF on 0 PSI
#define RF_PRESS_INC       0     // increase of last RF pressure for low speed at RF on 0 PSI
#define RF_ON_DELAY        7     // RF after min 7 seconds

#define IMPEDANCE_MIN   (201)       // min impedance in deci-ohms; 20.1 ohms is inbounds/OK, 20.0 ohms is too low
#define IMPEDANCE_MAX1  (130 * 10)  // max impedance is initially 130 ohms
#define IMPEDANCE_MAX2  (200 * 10)  // max impedance is after RF 200 ohms
#define IMP_MAX_INC     (140 * 10)  // max impedance increase 140 ohms
#define PRESSURE_MAX    700         // max pressure is 700 PSI
#define PRESSURE_MAX1   680         // max pressure is 680 PSI for restart

#define DISPLAY_WAIT       2     // display stuff for 2 seconds

#define HC_IDLE            0     // HC status, stopped
#define HC_HOME            1     // stopped at home position
#define HC_PUSH            2     // going out
#define HC_PULL            3     // pulling back
#define HC_BUSY            4     // busy; POST
#define HC_INIT            5     // HC initialized, waiting for communicaation
#define HC_LIMIT           6     // at max limit
                                 // also see ERROR_HC_XXXX

typedef enum
{
   WARNING_SEVERITY,
   FAULT_SEVERITY,
   NUM_ERROR_SEVERITIES
}  ERROR_SEVERITY;
                                     // Error codes

                                     // ... from Hydraulic Controller
#define ERROR_HC_MAXCURRENT       10 // max current detected
#define ERROR_HC_MINCURRENT       11 // low current detected
#define ERROR_HC_PULSERRHI        12 // too many pulses
#define ERROR_HC_PULSERRLO        13 // too little pulses
#define ERROR_HC_COMERR           14 // communication error
#define ERROR_HC_POST_MAXCURR     20 // max current during POST
#define ERROR_HC_POST_MINCURR     21 // min current during POST
#define ERROR_HC_POST_MINPULSES   22 // min pulses during POST
#define ERROR_HC_POST_MAXPULSES   23 // max pulses during POST
#define ERROR_HC_ROMERR           25 // FLASH CRC error during POST
#define ERROR_HC_RAMERR           26 // ram test error during POST
#define ERROR_HC_CONFIGERR        27 // configuration test error during POST

                                     // ... from original named constants
#define ERROR_IMPEDANCE           30 // Impedance fault
#define ERROR_POWER               31 // POST power fault
#define ERROR_24V                 32 // POST 24V supply fault
#define ERROR_12V                 33 // POST 12V supply fault
#define ERROR_12VNEG              34 // POST -12V supply fault
#define ERROR_5V                  35 // POST 5V supply fault
#define ERROR_TEMP                36 // POST on board temperature fault
#define ERROR_SPI                 37 // POST SPI fault
#define ERROR_CJC                 38 // POST CJC out of range
#define ERROR_WATCHDOG            39 // Watchdog expired

                                     // ... from original literal constants
                                     // (used to be numbered 1-19, with skips)
#define ERROR_RAM_HI_SP_1ST_00    41 // POST RAM above SP failed 1st 0x00
#define ERROR_RAM_HI_SP_FF        42 // POST RAM above SP failed 0xFF
#define ERROR_RAM_HI_SP_AA        43 // POST RAM above SP failed 0xAA
#define ERROR_RAM_HI_SP_55        44 // POST RAM above SP failed 0x55
#define ERROR_RAM_HI_SP_AAAA      45 // POST RAM above SP failed 0xAAAA
#define ERROR_RAM_HI_SP_LAST_00   46 // POST RAM above SP failed last 0x00
#define ERROR_RAM_LO_SP_1ST_00    47 // POST RAM below SP failed 1st 0x00
#define ERROR_RAM_LO_SP_FF        48 // POST RAM below SP failed 0xFF
#define ERROR_RAM_LO_SP_AA        49 // POST RAM below SP failed 0xAA
#define ERROR_RAM_LO_SP_55        50 // POST RAM below SP failed 0x55
#define ERROR_RAM_LO_SP_AAAA      51 // POST RAM below SP failed 0xAAAA
#define ERROR_RAM_LO_SP_LAST_00   52 // POST RAM below SP failed last 0x00
#define ERROR_RAM_SPACE           53 // POST RAM not enough space

                                     // ... new display-related
#define ERROR_DFDISPLY_FCAT       60 // Display function: enqueue font/color/text
#define ERROR_DFDISPLY_GRAPHIC    61 // Display function: print graphic item
#define ERROR_DFDISPLY_IMPEDANCE  62 // Display function: print impedance
#define ERROR_DFDISPLY_RF_GRAPHIC 63 // Display function: print rf graphic
#define ERROR_DFDISPLY_TEMP       64 // Display function: print temperature
#define ERROR_DFDISPLY_TEXT_ITEM  65 // Display function: print text item
#define ERROR_DFDISPLY_BTNS       66 // Display function: programmable btns

                                     // ... from original unnumbered / unnamed
                                     // (just existed as hard-coded text strings)
#define ERROR_EEPROM              70 // POST EEPROM corrupted
#define ERROR_DAC_ADC             71 // POST DAC to ADC fault
#define ERROR_DISPLAY_INIT        72 // POST Display initialization
#define ERROR_CPU_CONFIG          73 // POST CPU Config Register
#define ERROR_FLASH_CRC           74 // POST FLASH CRC
#define ERROR_STUCK_BTN           75 // POST Stuck button

                                     // ... a mixture of old and new
#define ERROR_DISPLAY_PROCESSING  80 // Display Processing
#define ERROR_USB                 81 // USB Interface
#define ERROR_SW_VERSION          82 // Display error: Software version
#define ERROR_GRAPHICS            83 // Display error: Initial graphics
#define ERROR_LABELS              84 // Display error: Initial labels
#define ERROR_CYCLES              85 // Display error: Initial Cycles value

#define ERROR_HC_COMM_4           90 // Hydraulics Controller Comm 4
#define ERROR_HC_SHAFT_SPEED      91 // Hydraulics Controller Shaft Speed

#define SPS                50       // 50 samples per second; 20 ms sample rate
                                    // Scale factors
#define RF_VOLTAGE_SCALE   17575L   // RF voltage 175.75 V FS; 56.9mV/V (17583)
                                    // RF current was 543L: 0.543 A FS; 18.43mV/mA
#define RF_CURRENT_SCALE   880L     // RF current: previous X 1.62
                                    // RF power was 26700L: 26.67 W FS; 0.375V/W
#define RF_POWER_SCALE     43271L   // RF power: previous X 1.62

#define RF_POWER_MAX_THRESH ((S16)((11*(U32)RF_POWER_SCALE)/10)) /* RF power FS + 10% */

#define RF_IMPEDANCE_SCALE 323665L  // RF impdance multiplier = VFS / IFS * 1000
#define RF_PRIM_V_SCALE    2538L    // RF primary voltage 25.38 V FS
#define RF_PRIM_I_SCALE    5872L    // RF primary current 5.872 A FS
#define RF_DAC_1W          246      // RF DAC value for approx 1W into 100 ohms (R16 = 5K); was 920
#define RF_ADC_OFFSET      22       // RF ADC offset at zero volts
#define PRESSURE_OFFSET    250      // Default Pressure Offset
#define PRESSURE_SCALE     2100L    // default Pressure Scale
#define SPI_TEMPERATURE1   0        // index of TC1 temperature in SPI
#define SPI_TEMPERATURE2   1        // index of TC2 temperature in SPI
#define SPI_NTC            2        // index of NTC resistor in SPI
#define SPI_CJC_TEMP       4        // index of CJC temperature in SPI
#define SPI_TEMPERATURE3   5        // index of ext temperature sensor in SPI

#define TEST_IMPEDANCE     100      // POST test impedance
#define TEST_IMP_DELTA     (100 / 10) // POST test impedance +/- 10%
#define TEST_POWER_DIFF    300      // POST test power difference .300 W
#define TEST_SUPPLY_TOL    10       // POST power supply tolerance 10%
#define TEST_LO_TEMP       15       // POST low on board temperature 15C
#define TEST_HI_TEMP       50       // POST high on board temperature 50C

#define BEEP_INIT       0x10        // beep codes
#define BEEP_CHECK      0x11
#define BEEP_TONE1      0x00
#define BEEP_RF         0x01
#define BEEP_FAULT      0x02
#define BEEP_REPLACE    0x03
#define BEEP_REPLACE1   0x04
#define BEEP_MOTOR      0x05
#define BEEP_MOTOR_OFF  0x06
#define BEEP_CHG_CARTR  0x07
#define BEEP_WARNING    0x08
#define BEEP_CLICK      0x09
#define BEEP_VOLUMEC    0x01
#define BEEP_HIGH       0x02

#define LED_ON          0x01        // LED ON mask in LED control
#define LED_RF          0x02        // LED RF mask in LED control
#define LED_WARNING     0x04        // LED WARNING mask in LED control
#define LED_FAULT       0x08        // LED FAULT mask in LED control

#define REMIX_BUTTON    0x01        // REMIX button mask
#define RESET_BUTTON    0x01        // RESET button is renamed REMIX button mask
#define CYCLE_BUTTON    0x02        // Front panel Cycle button
#define UP_BUTTON       0x04        // UP button mask
#define DN_BUTTON       0x08        // DOWN button mask
                                    //
#define RFON_BUTTON     0x100       // RF, blue, button mask
#define CYCLE_SWITCH    0x200       // Orange Cycle Reset Switch
#define RFON_BUTTONE    0x800       // RF, blue, button mask on edge
#define RFON_BUTTOFF    0x1000      // RF, blue, button mask off edge
                                    //
#define MOTOR_BUTTON    0           // Cement, orange, button (n/a in this device)
#define ENTER_BUTTON    0 // was 0x02: ENTER button (not available in this device)
#define ENTERM_BUTTON   0           // ENTER MOTOR run button (n/a in this device)
#define STOP_BUTTON     0 // was 0x01: STOP button (not available in this device)
#define MODE_BUTTON     0 // was 0x40: MODE button (not available in this device)

#define WATCH_DOG       0x10        // watchdog expired mask in status byte
#define HALL_SWITCH     0x20        // hall effect sensor mask in status byte

#define S_RF            0x00001L    // status bits for display and sound
#define S_9_5CC         0x00002L
#define S_9_5CC_NORF    0x00004L
#define S_MED_PRESS     0x00008L
#define S_MED_PRESS_NORF 0x00010L
#define S_HI_PRESS      0x00020L
#define S_HI_PRESS_NORF 0x00040L
#define S_RESTART_EXP   0x00080L
#define S_MOTOR         0x00100L
#define S_HY_LIMIT      0x04000L
#define S_HY_LIMIT_NORF 0x08000L    // 16 bits + no bits

#define RFON_LED        LATD6
#define MOTOR_LED       LATD7

/* This define is <IEC 62304 CLASS C> */

#define KICK_THE_DOG (LATG15 = !(LATG15 = 0)) // watchdog kick, toggle RG15, 500 ns

/*
 * The TE_ABLATE_POWER_SETTING_INDEX enum type is used in the user interface to
 * allow selecting between the ablation power levels.  The values of each type
 * are specifically set, since this type is both used to increment & decrement
 * the ablate power setting and used as an index into ablate power tables (arrays).
 */

typedef enum /* these indices correlate to array indices */
{
   ABLATE_POWER_SETTING_MINNDX = 1, /* for index lower bound testing and zero-relative array conversion */
   ABLATE_POWER_SETTING_LEVEL1 = 1, /* index for the lowest power setting */
   ABLATE_POWER_SETTING_LEVEL2 = 2, /* indice for the highest power setting */
   ABLATE_POWER_SETTING_MAXNDX = 2, /* for index upper bound testing */
   NUM_ABLATE_POWER_SETTING_INDICES = 3
}  TE_ABLATE_POWER_SETTING_INDEX;

typedef enum /* these indices correlate to array indices */
{
   RFDAC_CTRL_RF_MOTOR_AND_RELAY_ALL_OFF = 0b0000, /* 0x0 */
   RFDAC_CTRL_RF_OFF_MTRRLY_OFF_RFRLY_ON = 0b1100, /* 0xC */
   RFDAC_CTRL_RF_OFF_MTRRLY_ON_RFRLY_OFF = 0b1000, /* 0x8 */
   RFDAC_CTRL_RF_ON_MTRRLY_OFF_RFRLY_OFF = 0b0011, /* 0x3 */
   RFDAC_CTRL_RF_ON_AND_ABLATING         = 0b1111  /* 0xF - RF on and ablating */
}  TE_RFDAC_CTRL_BITS;


#define DEGREE    248  // special display characters
#define OHM       234

/*******************************************************************************
****************** Global Function Prototypes **********************************
*******************************************************************************/

U16  config_check(void);                     // Checks config registers in PIC24HJ256GP610
U16  convert_ntc(U16 adc_value, U16 *tempp); // converts NTC ADC reading to degrees C * 10
U16  convert_to_degrees(U16 adc_value);      // converts TC ADC reading to degrees C * 10

int  crcchk(__far unsigned char *bp, unsigned bytes);
void crcgen(__far unsigned char *bp, unsigned bytes);

U16  crc_flash(void);                        // 144 ms

void fault_routine(ERROR_SEVERITY severity, U16 number, const char *message);
U16  get_ADC(U8 ch);
U16  get_raw_switches(void);                 // read switches, no debounce
U16  get_recorded_buttons(void);             // get buttons pressed since last call
U8   get_status(void);                       // read status bits from CPLD
U16  get_switches(void);

void hw_init(void);

U16  post_rf(struct EEPROMstruct *eep);      // do POST test of RF circuitry

#ifdef   DFTEST
U16 post_rf_test_mode(struct EEPROMstruct *eep, struct postRFstruct *postRF);
#endif

U16  post_spi(void);                         // do POST check on SPI system
U16  post_supply_volts(void);                // do POST check of supply voltages

U16  powercontrol(U16 DACvalue, U16 setpoint, S16 data); // PI control for DACValue out

U16  ram_test(void);                         // test memory area above the stack
void read_RF_ADC(S16 data[4]);
U16  read_SPI_ADC(U8 nextinput);

U16  tone(U16 mode);
void tone_gen(U16 freq, U8 mode);
void wait_for_20ms(void);
void write_LEDs(U8 bits);
void write_DAC(U16 data, U8 control);

/* eeprom is the ATMEL AT24C1024B - 128Kbytes */
S16  read_eeprom  (U32 adr, U8 *bp, U8 cnt);       // read bytes from EEPROM

#ifdef   DFTEST
S16  write_eeprom (U32 adr, U8 data);              // write one byte to EEPROM
#endif

#endif /* #ifndef __DFINE_H__ */

