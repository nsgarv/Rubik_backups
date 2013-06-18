/*******************************************************************************
* Copyright (C) 2011 Minnetronix Inc.  All rights reserved.                    *
*******************************************************************************/

/*******************************************************************************
*
*   $Source: DFDISPLY.H $
*   $Revision: 1.10 $
*   Project: Rubik
*   $Date: 2011/11/21 14:19:41CST $
*
*-------------------------------------------------------------------------------
*
* Description:
*
*    This header file contains definitions related to interfacing the Reach
*    Technology display.
*
*******************************************************************************/

#ifndef  DFDISPLY_H                        /* Prevents multiple inclusion */
#define  DFDISPLY_H

/*******************************************************************************
********************* Application Globals **************************************
*******************************************************************************/

/*
 * All of the predefined text items on the display have an ID.
 * (Some have more than one if they are displayed in multiple sizes or colors.)
 */

typedef enum
{
   SW_VERSION_DISPLAY_ITEM_ID,              /* Software version */
   RF_CYCLE_LABEL_DISPLAY_ITEM_ID,          /* Label for RF Cycle */
   CYCLES_LABEL_DISPLAY_ITEM_ID,            /* Label for Cycles */
   RF_TOTAL_LABEL_DISPLAY_ITEM_ID,          /* Label for RF Total */
   DISTAL_TC_LABEL_DISPLAY_ITEM_ID,         /* Label for Distal temperature */
   PROXIMAL_TC_LABEL_DISPLAY_ITEM_ID,       /* Label for Proximal temperature */
   POWER_LABEL_DISPLAY_ITEM_ID,             /* Label for Power */
   RESET_BTN_LABEL_DISPLAY_ITEM_ID,         /* Label for Reset button */
   CYCLE_BTN_LABEL_DISPLAY_ITEM_ID,         /* Label for Cycle button */
   TIMER_BTN_LABEL_DISPLAY_ITEM_ID,         /* Label for Timer button */
   POWER_BTN_LABEL_DISPLAY_ITEM_ID,         /* Label for Power button */
   CONNECT_DEVICE_DISPLAY_ITEM_ID,          /* Connect Device prompt */
   RF_CYCLE_VALUE_DISPLAY_ITEM_ID,          /* RF Cycle value (vs label) */
   CYCLES_VALUE_DISPLAY_ITEM_ID,            /* Cycles value (vs label) */
   RF_TOTAL_VALUE_DISPLAY_ITEM_ID,          /* RF Total value (vs label) */
   POWER_VALUE_DISPLAY_ITEM_ID,             /* Power value (vs label) */
   DISTAL_SMALL_VALUE_DISPLAY_ITEM_ID,      /* Distal temperature value (sm font) */
   DISTAL_LARGE_VALUE_DISPLAY_ITEM_ID,      /* Distal temp value (lg font) */
   PROXIMAL_SMALL_VALUE_DISPLAY_ITEM_ID,    /* Proximal temp value (sm font) */
   PROXIMAL_LARGE_VALUE_DISPLAY_ITEM_ID,    /* Proximal temp value (lg font) */
   WARNING_VALUE_ON_SPLASH_DISPLAY_ITEM_ID, /* Warning message on Splash */
   WARNING_VALUE_ON_THERAPY_DISPLAY_ITEM_ID,/* Warning message on Therapy */
   FAULT_VALUE_ON_SPLASH_DISPLAY_ITEM_ID,   /* Fault message on Splash */
   FAULT_VALUE_ON_THERAPY_DISPLAY_ITEM_ID,  /* Fault message on Therapy */
   NUM_DISPLAY_TEXT_ITEM_IDS
}  DISPLAY_TEXT_ITEM_IDS;

/*
 * All of the predefined graphic image (vs text) items on the display have an ID.
 */

typedef enum
{
   THERAPY_BKGND_DISPLAY_ITEM_ID,            /* Therapy screen background */
   RESET_BTN_DISPLAY_ITEM_ID,                /* Therapy screen: Reset button */
   CYCLE_BTN_DISPLAY_ITEM_ID,                /* Therapy screen: Cycle button */
   TIMER_UP_BTN_DISPLAY_ITEM_ID,             /* Therapy screen: Timer Up button */
   TIMER_DOWN_BTN_DISPLAY_ITEM_ID,           /* Therapy screen: Timer Dn button */
   OHMS_SYMBOL_DISPLAY_ITEM_ID,              /* Therapy screen: Ohms symbol */
   POWER_UP_BTN_DISPLAY_ITEM_ID,             /* Therapy screen: Power Up button */
   POWER_DOWN_BTN_DISPLAY_ITEM_ID,           /* Therapy screen: Power Dn button */
   RF_RADIATING_DISPLAY_ITEM_ID,             /* Therapy screen: RF animation */
   WARNING_SYMBOL_ON_THERAPY_DISPLAY_ITEM_ID,/* Therapy screen: Warning icon */
   FAULT_SYMBOL_ON_THERAPY_DISPLAY_ITEM_ID,  /* Therapy screen: Fault icon */
   WARNING_SYMBOL_ON_SPLASH_DISPLAY_ITEM_ID, /* Splash  screen: Warning icon */
   FAULT_SYMBOL_ON_SPLASH_DISPLAY_ITEM_ID,   /* Splash  screen: Fault icon */
   OHMS_BAR_DISPLAY_ITEM_ID,                 /* Therapy screen: Ohms histogram */
   NUM_DISPLAY_GRAPHIC_ITEM_IDS
}  DISPLAY_GRAPHIC_ITEM_IDS;

/*
 * Fonts acknowledged by Reach Technology display.
 * (Only a few defined here. Add others as necessary.)
 *
 * Update corresponding array in DFDISPLY.C whenever
 * this enumeration is changed.
 */

typedef enum
{
   TWELVE_PT_FONT,
   TWELVE_PT_BOLD_FONT,
   SIXTEEN_PT_FONT,
   TWENTY_PT_FONT,
   TWENTY_FOUR_PT_FONT,
   TWENTY_FOUR_PT_BOLD_FONT,
   THIRTY_TWO_PT_FONT,
   FORTY_EIGHT_PT_FONT,
   MONOSPACE_TWELVE_PT_FONT,
   MONOSPACE_TWELVE_PT_BOLD_FONT,
   MONOSPACE_SIXTEEN_PT_FONT,
   MONOSPACE_TWENTY_PT_FONT,
   MONOSPACE_TWENTY_FOUR_PT_FONT,
   MONOSPACE_TWENTY_FOUR_PT_BOLD_FONT,
   MONOSPACE_THIRTY_TWO_PT_FONT,
   MONOSPACE_FORTY_EIGHT_PT_FONT,
   NUM_REACH_TEXT_FONTS
}  REACH_TEXT_FONTS;

/*
 * Foreground on Background Colors acknowledged by
 * Reach Technology display. (Only a few defined here.
 * Add others as necessary.)
 *
 * Update corresponding array in DFDISPLY.C whenever
 * this enumeration is changed.
 */

typedef enum
{
   WHITE_ON_BLUE_COLOR,
   RED_ON_BLUE_COLOR,
   YELLOW_ON_BLUE_COLOR,
   BLUE_ON_BLUE_COLOR,     /* Useful for erases */
   BLACK_ON_WHITE_COLOR,
   WHITE_ON_WHITE_COLOR,   /* Useful for erases */
   WHITE_ON_BLACK_COLOR,
   RED_ON_BLACK_COLOR,
   YELLOW_ON_BLACK_COLOR,
   GOLD_ON_BLACK_COLOR,
   GREEN_ON_BLACK_COLOR,
   BLUE_ON_BLACK_COLOR,
   BLACK_ON_BLACK_COLOR,   /* Useful for erases */
   WHITE_ON_GREY_COLOR,
   GREY_ON_GREY_COLOR,     /* Useful for erases */
   NUM_REACH_TEXT_COLORS
}  REACH_TEXT_COLORS;

/*
 * The list of screens that are written to the display
 */

typedef enum
{
   SPLASH_DISPLAY_SCREEN,
   THERAPY_DISPLAY_SCREEN,
   NUM_DISPLAY_SCREENS
}  DISPLAY_SCREENS;

/*******************************************************************************
****************** Global Function Prototypes **********************************
*******************************************************************************/

/*============================================================================*/
/*
 * Global:        gDFDisplyClearScreen
 *
 * Description:   This function erases the entire display using the passed
 *                background color.
 *
 *
 * Parameters:    color  - the foreground/background color (foreground unused)
 *
 * Returns:       None
 *
 * Side-effects:  The fault routine will be called (effectively stopping the
 *                program) if an enqueuing error occurs.
 */

void gDFDisplyClearScreen (REACH_TEXT_COLORS color);


/*============================================================================*/
/*
 * Global:        gDFDisplyDisableRFGraphicItem
 *
 * Description:   This function turns off the Radiating RF icon animation.
 *
 *                The fault_routine function calls this function versus the
 *                gDFDisplyPrintRFGraphicItem function because it does not want
 *                to get into a recursion situation.
 *                (The gDFDisplyPrintRFGraphicItem function can call the
 *                fault_routine function.)
 *
 * Parameters:    None
 *
 * Returns:       None
 *
 * Side-effects:  None
 */

void gDFDisplyDisableRFGraphicItem(void);


/*============================================================================*/
/*
 * Global:        gDFDisplyDoesGraphicDisplayHaveWorkToDo
 *
 * Description:   This function returns a 1 if the display has work to
 *                do or a 0 if it doesn't.
 *
 *                It has work if either there is something in its queue that
 *                could be sent or a response from the graphic controller yet to
 *                process.
 *
 *                It's useful when the program hasn't yet entered the
 *                ablate_loop and some caller wants to push display commands
 *                through the queue. In such a situation ablate_loop isn't
 *                pushing items through the queue and a caller that wanted to
 *                could:
 *
 *                1. call whatever display function (like PrintTextItem) they
 *                wanted
 *
 *                2. call wait_for_20ms
 *
 *                3) call ProcessDisplayRequests (like ablate_loop would to move
 *                things through the queue
 *
 *                4) call this function to see if all of the requests related to
 *                #1 had been sent to the display.
 *
 *                5) repeat steps 2-4 if not empty
 *
 * Parameters:    None
 *
 * Returns:       See description
 *
 * Side-effects:  None
 */

int gDFDisplyDoesGraphicDisplayHaveWorkToDo(void);


/*============================================================================*/
/*
 * Global:        gDFDisplyInit
 *
 * Description:   This function initializes the Reach Technology display and
 *                the communication vehicles that talk to it.
 *
 * Parameters:    None
 *
 * Returns:       0 if success or 1 otherwise
 *
 *
 * Side-effects:  The display functions use DMA to transfer data to and from the
 *                display. Debugging and DMA don't play nice with each other in
 *                that the debugger never quite stops it at a breakpoint and
 *                stops that happen to occur while a DMA is in progress will
 *                cause funny things to appear on the screen, things like text
 *                in the wrong place, of the wrong color, of the wrong size, etc
 */

int gDFDisplyInit(void);


/*============================================================================*/
/*
 * Global:        gDFDisplyPrintCyclesValueTextItem
 *
 * Description:   This function prints the numeric cycles value to
 *                the display.
 *
 * Parameters:    cycles - the current cycles value to display
 *
 * Returns:       None
 *
 * Side-effects:  The fault routine will be called (effectively stopping the
 *                program) if an enqueuing error occurs.
 */

void gDFDisplyPrintCyclesValueTextItem(int cycles);


/*============================================================================*/
/*
 * Global:        gDFDisplyPrintErrorItem
 *
 * Description:   This function prints a graphic error symbol and error text to
 *                the display.
 *
 * Parameters:    severity - the severity of the error (affects the symbol that
 *                           is used and the color of the text that is written)
 *
 *                error    - the error value
 *
 *                message  - optional text string message that relates to the
 *                           error value (ignored at this time)
 *
 *                screen   - indicates which screen is up on the display
 *
 * Returns:       None
 *
 * Side-effects:  None
 */

void gDFDisplyPrintErrorItem(ERROR_SEVERITY severity, U16 error,
                             const char *message, DISPLAY_SCREENS screen);


/*============================================================================*/
/*
 * Global:        gDFDisplyPrintGraphicItem
 *
 * Description:   This function prints a graphic item (versus a text item) to
 *                the display.
 *
 * Parameters:    id - the id of item to display
 *
 * Returns:       None
 *
 * Side-effects:  The fault routine will be called (effectively stopping the
 *                program) if an enqueuing error occurs.
 */

void gDFDisplyPrintGraphicItem(DISPLAY_GRAPHIC_ITEM_IDS id);


/*============================================================================*/
/*
 * Global:        gDFDisplyPrintImpedanceGraphicItem
 *
 * Description:   This function prints the impedance bar graph to
 *                the display. Flashing of the bar will occur if the
 *                value is out of range or if an impedance fault (determined
 *                by the caller) is in effect.
 *
 * Parameters:    value         - the current impedance value. In-range values
 *                                light the corresponding number of bar
 *                                segments. Out-of-range values will result in
 *                                the bar graph flashing (if the ok_to_flash
 *                                value is 1).
 *
 *                ok_to_flash   - tells this function whether flashing the bar
 *                                is currently allowed.
 *
 *                imp_fault_cnt - tells this function whether an impedance fault
 *                                is active or not. (Any non-zero value
 *                                indicates an active fault.) When true, will
 *                                flash the bar (if the ok_to_flash value is 1).
 *
 *                erase_only    - set this variable to true if you just want this
 *                                function to erase the bar (and then not
 *                                subsequently draw any number of segments).
 *                                Its principal use is to cooperate with the
 *                                caller to flash the bar.
 *
 * Returns:       None
 *
 * Side-effects:  The fault routine will be called (effectively stopping the
 *                program) if an enqueuing error occurs.
 */

void gDFDisplyPrintImpedanceGraphicItem(int value, int ok_to_flash,
                                        int imp_fault_cnt, int erase_only);


/*============================================================================*/
/*
 * Global:        gDFDisplyPrintPowerValueTextItem
 *
 * Description:   This function prints the Power value to the display.
 *
 * Parameters:    power_value - the power value to print
 *
 * Returns:       None
 *
 * Side-effects:  The fault routine will be called (effectively stopping the
 *                program) if an enqueuing error occurs.
 */

void gDFDisplyPrintPowerValueTextItem(TE_ABLATE_POWER_SETTING_INDEX power_value);


/*============================================================================*/
/*
 * Global:        gDFDisplyPrintRFCycleValueTextItem
 *
 * Description:   This function prints the RF Cycle value to the display, in
 *                MM:SS format.
 *
 * Parameters:    seconds     - the RF Cycle value, in seconds
 *
 *                force_write - forces this function to write the value when it
 *                              wouldn't have otherwise. (This function normally
 *                              doesn't write the value if it's the same as it
 *                              was last time.)
 *
 *                erase_only  - set this variable to true if you just want this
 *                              function to erase the value (and then not
 *                              subsequently write it).
 *
 * Returns:       None
 *
 * Side-effects:  The fault routine will be called (effectively stopping the
 *                program) if an enqueuing error occurs.
 */

void gDFDisplyPrintRFCycleValueTextItem(int seconds, int force_write, int erase_only);


/*============================================================================*/
/*
 * Global:        gDFDisplyPrintRFGraphicItem
 *
 * Description:   This function turns the Radiating RF icon animation on or off.
 *
 *
 * Parameters:    write - set this to 1 to turn the animation on (or 0 for off)
 *
 * Returns:       None
 *
 * Side-effects:  The fault routine will be called (effectively stopping the
 *                program) if an enqueuing error occurs.
 */

void gDFDisplyPrintRFGraphicItem(int write);


/*============================================================================*/
/*
 * Global:        gDFDisplyPrintRFToTalValueTextItem
 *
 * Description:   This function converts the RF Total value (which is the length
 *                of time the RF has been on - in seconds) to "MM:SS" format
 *                and prints it to the display.
 *
 * Parameters:    seconds - the RF Total value to print
 *
 * Returns:       None
 *
 * Side-effects:  The fault routine will be called (effectively stopping the
 *                program) if an enqueuing error occurs.
 */

void gDFDisplyPrintRFToTalValueTextItem(int seconds);


/*============================================================================*/
/*
 * Global:        gDFDisplyPrintTemperatureValues
 *
 * Description:   This function prints the Distal and Proximal temperatures to
 *                the display.
 *
 *                One of the temperatures is displayed more prominently (larger)
 *                than the other - depending on the current power setting.
 *
 *                The prominent temperature may flash if a temp is out-of-range.
 *
 * Parameters:    power_value   - the current power setting, determines which
 *                                temperature is displayed more prominently than
 *                                the other.
 *
 *                proximal_temp - the current proximal temperature
 *
 *                distal_temp   - the current distal temperature
 *
 *                temp_fault_cnt- tells this function whether a temperature fault
 *                                is active or not. (Any non-zero value
 *                                indicates an active fault.) When true, will
 *                                flash the prominent temperature.
 *
 *                force_write   - forces this function to write the value when
 *                                it wouldn't have otherwise. (This function
 *                                normally doesn't write the value if it's the
 *                                same as it was last time.)
 *
 *                erase_only    - set this variable to true if you just want
 *                                this function to erase the value (and then not
 *                                subsequently write it).
 *
 * Returns:       None
 *
 * Side-effects:  The fault routine will be called (effectively stopping the
 *                program) if an enqueuing error occurs.
 */

void gDFDisplyPrintTemperatureValues(TE_ABLATE_POWER_SETTING_INDEX power_value,
   int proximal_temp, int distal_temp, int temp_fault_cnt, int force_write,
   int erase_only);


/*============================================================================*/
/*
 * Global:        gDFDisplyPrintText
 *
 * Description:   This function prints the passed-in text to the display. It's
 *                intended for those cases when a developer wants to print
 *                free-format debugging or test messages to the display. Other
 *                values that are written to the display, values written by the
 *                other PrintXXXX functions, have to be in certain places,
 *                be a certain size, a certain color, etc.
 *
 *                NOTE:
 *                The (x,y) value of (10,460) is a good place to write debug
 *                text because there is usually nothing else written there.
 *                Typical code to write a value there is:
 *
 *                char debug_text[10];
 *                sprintf(debug_text, "%d", some_value);
 *                gDFDisplyPrintText(debug_text, TWELVE_PT_FONT,
 *                                   WHITE_ON_BLACK_COLOR, 10, 460);
 *
 * Parameters:    string - the text string to print
 *                font   - the font the string should be written in
 *                color  - the color the string should be written in
 *                x      - the x coordinate where the text should start
 *                y      - the y coordinate
 *
 * Returns:       None
 *
 * Side-effects:  The fault routine will be called (effectively stopping the
 *                program) if an enqueuing error occurs.
 */

void gDFDisplyPrintText(char *string, REACH_TEXT_FONTS font,
                        REACH_TEXT_COLORS color, int x, int y);

#ifdef   DFTEST
/*============================================================================*/
/*
 * Global:        gDFDisplyPrintTextFlash
 *
 * Description:   This function is same is gDFDisplyPrintText except that
 *                it sets the "string" into flashing mode.
 *                NOTE: only one string may be flashed at any one time.
 *                String flashing is deleted with gDFDisplyPrintTextFlashDelete
 *                function call.
 *
 * Parameters:    Same as gDFDisplyPrintText.
 *
 * Returns:       None
 *
 * Side-effects:  The fault routine will be called (effectively stopping the
 *                program) if an enqueuing error occurs.
 */
void gDFDisplyPrintTextFlash (char *string, REACH_TEXT_FONTS font,
                              REACH_TEXT_COLORS color, int x, int y);

/*============================================================================*/
/*
 * Global:        gDFDisplyPrintTextFlashDelete
 *
 * Description:   This function stops flashing text created by calling
 *                gDFDisplyPrintTextFlash.
 *
 * Parameters:    None
 *
 * Returns:       None
 *
 * Side-effects:  The fault routine will be called (effectively stopping the
 *                program) if an enqueuing error occurs.
 */
void gDFDisplyPrintTextFlashDelete (void);
#endif   // DFTEST

/*============================================================================*/
/*
 * Global:        gDFDisplyPrintTextItem
 *
 * Description:   This function prints known text items to the display,
 *                displaying them at their predefined location and in their
 *                predefined font and color.
 *
 * Parameters:    id     - the id of the item to display
 *                string - the text to print
 *                set    - indicates whether the text is being set or cleared.
 *                         Currently, this parameter is only used for the ids
 *                         listed below. For all other ids, the passed-in value
 *                         is ignored.
 *
 *                         CONNECT_DEVICE
 *                         set = 0 will cause the associated text to appear and
 *                                 flash
 *                         set = 1 will erase the associated text
 *
 * Returns:       None
 *
 * Side-effects:  The fault routine will be called (effectively stopping the
 *                program) if an enqueuing error occurs or if an invalid id
 *                is specified.
 */

void gDFDisplyPrintTextItem(DISPLAY_TEXT_ITEM_IDS id, char *string, U16 set);


/*============================================================================*/
/*
 * Global:        gDFDisplyProcessDisplayRequests
 *
 * Description:   This function does two things:
 *                1) Sends any display request it finds in the display queue AND
 *                2) Inspects any response that there may be for a previous request.
 *
 *                This function will not send a new request until it has
 *                received a response from the previous request.
 *
 *                Responses are typically just the ">" character and a carriage
 *                return. Other characters besides the ">" character usually
 *                indicate failure. See "Prompt Summary" in the SLCDx Input Buffer
 *                Processing section of the Reach Technology SLCD+/6/43 Reference
 *                Manual for more details.
 *
 * Parameters:    None
 *
 * Returns:       1 if the function was successful or 0 if:
 *                a) it didn't receive the response to a command soon enough or
 *                b) it had trouble dequeuing a request
 *
 * Side-effects: None
 */

int gDFDisplyProcessDisplayRequests(void);


/*============================================================================*/
/*
 * Global:        gDFDisplySetProgrammableButtons
 *
 * Description:   This function sets the lower two softkeys, the Up and Down
 *                softkeys, to the "Set Power" or "Set Timer" look.
 *
 * Parameters:    id - the id of the label for the group of softkeys. The only
 *                     recognized ids are POWER_BTN_LABEL_DISPLAY_ITEM_ID and
 *                     TIMER_BTN_LABEL_DISPLAY_ITEM_ID.
 *
 * Returns:       None
 *
 * Side-effects:  The fault routine will be called (effectively stopping the
 *                program) if an enqueuing error occurs.
 */

void gDFDisplySetProgrammableButtons(DISPLAY_TEXT_ITEM_IDS btn_label_id);


#endif /* #ifndef DFDISPLY_H */



