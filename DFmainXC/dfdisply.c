/*******************************************************************************
* Copyright (C) 2011 Minnetronix Inc.  All rights reserved.                    *
*******************************************************************************/

/*******************************************************************************
*
*   $Workfile: DFDSPLY.C $
*   $Revision: 1.21 $
*     Project: Rubik
*       $Date: 2011/11/21 15:01:45CST $
*
*-------------------------------------------------------------------------------
*
* Description:
*
*    This file contains definitions and logic for interfacing the display.
*
*******************************************************************************/

/*******************************************************************************
************************ Included Files ****************************************
*******************************************************************************/

#include "dfine.h"
#include <stdio.h>
// htc.h is a HI-TECH file and for this project calls "pic24hj256gp610.h" which was added below.
//#include <htc.h>
//#include "pic24hj256gp610.h"
#include <xc.h>
#include <string.h>
#include "dfdisply.h"

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
 * Define how many times we will try to initialize communications with the
 * Reach Technology display. Datasheet suggests a total of 4.
 *
 * Additionally, define how many of those tries should use the null command
 * before the abort command is used instead.
 */

#define MAX_DISPLAY_INIT_RETRIES (4)
#define MAX_DISPLAY_NULL_CMD_RETRIES (3)

/*
 * We queue the display requests because each request has an associated response
 * and we want to inspect the response but we don't want to hold everybody up
 * while we're waiting for it - and we might want to "queue up" several requests
 * in a row (such as the Set Font, Set Color, Set Text triplet).
 *
 * A queue entry will be an individual request and we'll limit it to
 * LIMITED_DISPLAY_CMD_LEN characters to keep the queue from taking up too much
 * space. LIMITED_DISPLAY_CMD_LEN should be <= DISPLAY_CMD_MAX_LEN.
 *
 * We also limit how many entries can be in the queue to MAX_POSSIBLE_QUEUE_ENTRIES.
 * Because of the algorithm that is used to keep track of the enqueue and dequeue
 * indices, the MAX_POSSIBLE_QUEUE_ENTRIES value must be a power of two.
 *
 * The queue itself is named Queue.
 *
 * As entries are added or subtracted from the queue, QueueEntryCount is updated.
 *
 * Requests are placed into the queue at the QueueEnqueueIndex and removed from
 * the queue at the QueueDequeueIndex.
 */

#ifndef DFTEST
#define LIMITED_DISPLAY_CMD_LEN (40)
#define MAX_POSSIBLE_QUEUE_ENTRIES (32)               /* must be power of 2 */
#else
#define LIMITED_DISPLAY_CMD_LEN (64)
#define MAX_POSSIBLE_QUEUE_ENTRIES (32)               /* must be power of 2 */
#endif

#define QUEUE_ENTRY_SIZE (LIMITED_DISPLAY_CMD_LEN)


static char Queue[MAX_POSSIBLE_QUEUE_ENTRIES][LIMITED_DISPLAY_CMD_LEN];
static int  QueueEntryCount = 0;
static int  QueueEnqueueIndex = 0;
static int  QueueDequeueIndex = 0;

/*
 * Serial communications are known for requiring that retries be attempted
 * when communications fail - because they sometimes do - and retrying often
 * corrects the problem.
 *
 * Requests are dequeued from the queue if the queue has something in it and
 * a request isn't already in progress. A request remains "in progress" until
 * a response has been received for it. The request is held in "Request" in case
 * it needs to be resent.
 *
 * The application will poll for a response approximately every 20ms. Every time
 * it looks for a response it increments RequestWaitingCount.
 *
 * If the count ever reaches MAX_DISPLAY_RESPONSE_WAIT_CNT the software will
 * perform a retry (will resend the contents of Request). The value for the
 * maximum count assumes the count is being incremented as often as noted above.
 *
 * The number of retries attempted is kept track of in RequestRetries. If the
 * value ever exceeds MAX_REQUEST_RETRIES a communications error will be declared.
 */

static int RequestInProgress = 0;
static char Request[LIMITED_DISPLAY_CMD_LEN];

static int RequestWaitingCount = 0;
#define MAX_DISPLAY_RESPONSE_WAIT_CNT (50)

static int RequestRetries = 0;
#define MAX_REQUEST_RETRIES (3)

/*
 * Remember when the Connect Device string is placed on the screen so that we
 * don't try to clear it if it isn't there. Be careful if you change screens
 * (be careful to clear the variable).
 */

static int ConnectDeviceOnScreen = 0;

/* Text Fonts. See enum REACH_TEXT_FONTS in DFine.h */

static char *Fonts[NUM_REACH_TEXT_FONTS] =
{
   "f 12\r",    // TWELVE_PT_FONT
   "f 12B\r",   // TWELVE_PT_BOLD_FONT
   "f 16\r",    // SIXTEEN_PT_FONT
   "f 20\r",    // TWENTY_PT_FONT
   "f 24\r",    // TWENTY_FOUR_PT_FONT
   "f 24B\r",   // TWENTY_FOUR_PT_BOLD_FONT
   "f 32\r",    // THIRTY_TWO_PT_FONT
   "f 48\r",    // FORTY_EIGHT_PT_FONT
   "f m12\r",   // MONOSPACE_TWELVE_PT_FONT
   "f m12B\r",  // MONOSPACE_TWELVE_PT_BOLD_FONT
   "f m16\r",   // MONOSPACE_SIXTEEN_PT_FONT
   "f m20\r",   // MONOSPACE_TWENTY_PT_FONT
   "f m24\r",   // MONOSPACE_TWENTY_FOUR_PT_FONT
   "f m24B\r",  // MONOSPACE_TWENTY_FOUR_PT_BOLD_FONT
   "f m32\r",   // MONOSPACE_THIRTY_TWO_PT_FONT
   "f m48\r",   // MONOSPACE_FORTY_EIGHT_PT_FONT
};

/* Text Colors. See enum REACH_TEXT_COLORS in DFine.h */

static char *Colors[NUM_REACH_TEXT_COLORS] =
{
   "S FFFFFF 004681\r", /* WHITE_ON_BLUE_COLOR */
   "S FF0000 004681\r", /* RED_ON_BLUE_COLOR */
   "S FFF805 004681\r", /* YELLOW_ON_BLUE_COLOR */
   "S 004681 004681\r", /* BLUE_ON_BLUE_COLOR */
   "S 000000 FFFFFF\r", /* BLACK_ON_WHITE_COLOR */
   "S FFFFFF FFFFFF\r", /* WHITE_ON_WHITE_COLOR */
   "S FFFFFF 000000\r", /* WHITE_ON_BLACK_COLOR */
   "S FF0000 000000\r", /* RED_ON_BLACK_COLOR */
   "S FFF805 000000\r", /* YELLOW_ON_BLACK_COLOR */
   "S F8DC3E 000000\r", /* GOLD_ON_BLACK_COLOR */
   "S 69D960 000000\r", /* GREEN_ON_BLACK_COLOR */
   "S 5BB3C9 000000\r", /* BLUE_ON_BLACK_COLOR */
   "S 000000 000000\r", /* BLACK_ON_BLACK_COLOR */
   "S FFFFFF 6C6F70\r", /* WHITE_ON_GREY_COLOR */
   "S 6C6F70 6C6F70\r", /* GREY_ON_GREY_COLOR */
};

/* Max length (including null) of set-font command "f m10B\r\0" */

#define MAX_FONT_TEXT (8)

/* Max length (including null) of set-color command "S FFFFFF BBBBBB\r\0" */

#define MAX_COLOR_TEXT (17)

/*
 * Max length (including null) of the screen location field that is present in
 * various display commands. Since screen is 800x480, field need be no longer
 * than "XXX YYY\0".
 */

#define MAX_LOCATION_TEXT (8)

/* Longest label that is ever written to the screen ("Connect Device\0") */

#define MAX_LABEL_TEXT (15)

/* Longest value that is ever written to the screen ("00:00\0") */

#define MAX_VALUE_TEXT (6)

/* The longest text (of any kind) written to the screen */

#define MAX_SCREEN_TEXT (MAX_LABEL_TEXT)

/*
 * A display text command has the format: t "text" location \r
 * The following define the:
 * START, everything before the "text" component
 * MIDDLE, the part after the "text" component up to the location component
 * END, the terminating carriage return.
 */

#define DISPLAY_TEXT_COMMAND_START    ("t \"")
#define DISPLAY_TEXT_COMMAND_MIDDLE   ("\" ")
#define DISPLAY_TEXT_COMMAND_END      ("\r")

/*
 * Define the start of a flashing text command (for the temperatures).
 * The argument following the "tf" is an index that can range fron 0 to 9.
 * The index must be unique across all flashing texts and all animations.                                                                      .
 * The assigned indices are:                                                                                                                                            .
 *                                                                                                                                                                      .
 * 0 - the startup animation that is in the macros.txt file                                                                                                                                                                     .
 * 1 - the radiating rf animation that is in the same file.                                                                                                                                                                                                                             .
 * 2 - for either a flashing distal temperature or a flashing proximal temp.                                                                                                                                                                                                                                                                                     .
 * 3 - the "connect device" text                                                                                                                                                                                                                                                                                                                                                            .
 * 4 - unassigned                                                                                                                                                                                                                                                                                                                                                                     .
 * 5 - unassigned                                                                                                                                                                                                                                                                                                                                                                                   .
 * 6 - unassigned                                                                                                                                                                                                                                                                                                                                                                                                 .
 * 7 - unassigned                                                                                                                                                                                                                                                                                                                                                                                                               .
 * 8 - unassigned                                                                                                                                                                                                                                                                                                                                                                                                                             .
 * 9 - DFTEST flashing text                                                                                                                                                                                                                                                                                                                                                                                                                                           .
 */

#define DISPLAY_FLASHING_TEMP_TEXT_COMMAND_START ("tf 2 \"")

/* To stop the flashing temperature text, disable it and then delete it */

#define DISABLE_FLASHING_TEMP_TEXT_COMMAND ("tfd 2 1\r")
#define DELETE_FLASHING_TEMP_TEXT_COMMAND  ("tfx 2\r")

/* Define the start of a flashing text command (for the "connect" string) */

#define DISPLAY_FLASHING_CONNECT_TEXT_COMMAND_START ("tf 3 \"")

/* To stop the flashing "connect" text, disable it and then delete it */

#define DISABLE_FLASHING_CONNECT_TEXT_COMMAND ("tfd 3 1\r")
#define DELETE_FLASHING_CONNECT_TEXT_COMMAND  ("tfx 3\r")

#ifdef   DFTEST

/* Define the start of DFTEST flashing text command */

#define DISPLAY_FLASHING_DFTEST_TEXT_COMMAND_START ("tf 9 \"")

/* Define the delete of DFTEST flashing text */

#define DELETE_FLASHING_DFTEST_TEXT_COMMAND        ("tfx 9\r")

#endif // DFTEST

/*
 * Define a structure that contains all of the items that are usually necessary
 * when writing text to the screen:
 * font,     the size and style of the text
 * color,    the color of the text
 * text,     the text
 * location, the location (x and y coordinates) of the start of the text
 */

typedef struct
{
   REACH_TEXT_FONTS font;
   REACH_TEXT_COLORS color;
   REACH_TEXT_COLORS erase_color;
   char text[MAX_SCREEN_TEXT];
   char location[MAX_LOCATION_TEXT];
}  DISPLAY_TEXT_STRUCT;

/*
 * Fill an array with all of the text strings that will probably be written.
 */

static DISPLAY_TEXT_STRUCT TextItems[NUM_DISPLAY_TEXT_ITEM_IDS] =
{
   {
   MONOSPACE_TWENTY_FOUR_PT_BOLD_FONT,  /* SW_VERSION_DISPLAY_ITEM_ID */
   WHITE_ON_BLUE_COLOR,
   BLUE_ON_BLUE_COLOR,
   " ",
   "290 260"
   },
   {
   MONOSPACE_SIXTEEN_PT_FONT,           /* RF_CYCLE_LABEL_DISPLAY_ITEM_ID */
   WHITE_ON_BLACK_COLOR,
   BLACK_ON_BLACK_COLOR,
   "RF Cycle",
   "60 34"
   },
   {
   MONOSPACE_SIXTEEN_PT_FONT,           /* CYCLES_LABEL_DISPLAY_ITEM_ID */
   WHITE_ON_BLACK_COLOR,
   BLACK_ON_BLACK_COLOR,
   "Cycles",
   "320 34"
   },
   {
   MONOSPACE_SIXTEEN_PT_FONT,           /* RF_TOTAL_LABEL_DISPLAY_ITEM_ID */
   WHITE_ON_BLACK_COLOR,
   BLACK_ON_BLACK_COLOR,
   "RF Total",
   "550 34"
   },
   {
   MONOSPACE_SIXTEEN_PT_FONT,           /* DISTAL_TC_LABEL_DISPLAY_ITEM_ID */
   WHITE_ON_BLACK_COLOR,
   BLACK_ON_BLACK_COLOR,
   "Distal TC",
   "310 186"
   },
   {
   MONOSPACE_SIXTEEN_PT_FONT,           /* PROXIMAL_TC_LABEL_DISPLAY_ITEM_ID */
   WHITE_ON_BLACK_COLOR,
   BLACK_ON_BLACK_COLOR,
   "Proximal TC",
   "535 186"
   },
   {
   MONOSPACE_TWENTY_FOUR_PT_FONT,       /* POWER_LABEL_DISPLAY_ITEM_ID */
   WHITE_ON_BLACK_COLOR,
   BLACK_ON_BLACK_COLOR,
   "Power",
   "550 359"
   },
   {
   MONOSPACE_TWELVE_PT_FONT,            /* RESET_BTN_LABEL_DISPLAY_ITEM_ID */
   WHITE_ON_GREY_COLOR,
   GREY_ON_GREY_COLOR,
   "Reset",
   "729 62"
   },
   {
   MONOSPACE_TWELVE_PT_FONT,            /* CYCLE_BTN_LABEL_DISPLAY_ITEM_ID */
   WHITE_ON_GREY_COLOR,
   GREY_ON_GREY_COLOR,
   "Cycle",
   "730 169"
   },
   {
   MONOSPACE_TWELVE_PT_FONT,            /* TIMER_BTN_LABEL_DISPLAY_ITEM_ID */
   WHITE_ON_GREY_COLOR,
   GREY_ON_GREY_COLOR,
   "Timer",
   "729 277"
   },
   {
   MONOSPACE_TWELVE_PT_FONT,            /* POWER_BTN_LABEL_DISPLAY_ITEM_ID */
   WHITE_ON_GREY_COLOR,
   GREY_ON_GREY_COLOR,
   "Power",
   "729 275"
   },
   {
   MONOSPACE_THIRTY_TWO_PT_FONT,        /* CONNECT_DEVICE_DISPLAY_ITEM_ID */
   WHITE_ON_BLACK_COLOR,
   BLACK_ON_BLACK_COLOR,
   "Connect Device",
   "325 245"
   },
   {
   MONOSPACE_FORTY_EIGHT_PT_FONT,       /* RF_CYCLE_VALUE_DISPLAY_ITEM_ID */
   GREEN_ON_BLACK_COLOR,
   BLACK_ON_BLACK_COLOR,
   " ",
   "30 60"
   },
   {
   MONOSPACE_FORTY_EIGHT_PT_FONT,       /* CYCLES_VALUE_DISPLAY_ITEM_ID */
   GREEN_ON_BLACK_COLOR,
   BLACK_ON_BLACK_COLOR,
   " ",
   "314 60"
   },
   {
   MONOSPACE_FORTY_EIGHT_PT_FONT,       /* RF_TOTAL_VALUE_DISPLAY_ITEM_ID */
   GREEN_ON_BLACK_COLOR,
   BLACK_ON_BLACK_COLOR,
   " ",
   "470 60"
   },
   {
   MONOSPACE_THIRTY_TWO_PT_FONT,        /* POWER_VALUE_DISPLAY_ITEM_ID */
   BLUE_ON_BLACK_COLOR,
   BLACK_ON_BLACK_COLOR,
   " ",
   "505 395"
   },
   {
   MONOSPACE_THIRTY_TWO_PT_FONT,        /* DISTAL_SMALL_VALUE_DISPLAY_ITEM_ID */
   GOLD_ON_BLACK_COLOR,
   BLACK_ON_BLACK_COLOR,
   " ",
   "307 234"
   },
   {
   MONOSPACE_FORTY_EIGHT_PT_FONT,       /* DISTAL_LARGE_VALUE_DISPLAY_ITEM_ID */
   GOLD_ON_BLACK_COLOR,
   BLACK_ON_BLACK_COLOR,
   " ",
   "285 208"
   },
   {
   MONOSPACE_THIRTY_TWO_PT_FONT,        /* PROXIMAL_SMALL_VALUE_DISPLAY_ITEM_ID */
   GOLD_ON_BLACK_COLOR,
   BLACK_ON_BLACK_COLOR,
   " ",
   "545 234"
   },
   {
   MONOSPACE_FORTY_EIGHT_PT_FONT,       /* PROXIMAL_LARGE_VALUE_DISPLAY_ITEM_ID */
   GOLD_ON_BLACK_COLOR,
   BLACK_ON_BLACK_COLOR,
   " ",
   "500 208"
   },
   {
   MONOSPACE_TWENTY_PT_FONT,            /* WARNING_VALUE_ON_SPLASH_DISPLAY_ITEM_ID */
   YELLOW_ON_BLUE_COLOR,
   BLUE_ON_BLUE_COLOR,
   "Warning ",
   "80 445"
   },
   {
   MONOSPACE_TWENTY_PT_FONT,            /* WARNING_VALUE_ON_THERAPY_DISPLAY_ITEM_ID */
   YELLOW_ON_BLACK_COLOR,
   BLACK_ON_BLACK_COLOR,
   "Warning ",
   "80 445"
   },
   {
   MONOSPACE_TWENTY_PT_FONT,            /* FAULT_VALUE_ON_SPLASH_DISPLAY_ITEM_ID */
   RED_ON_BLUE_COLOR,
   BLUE_ON_BLUE_COLOR,
   "Fault ",
   "80 445"
   },
   {
   MONOSPACE_TWENTY_PT_FONT,            /* FAULT_VALUE_ON_THERAPY_DISPLAY_ITEM_ID */
   RED_ON_BLACK_COLOR,
   BLACK_ON_BLACK_COLOR,
   "Fault ",
   "80 445"
   },
};

/*
 * A display bitmap image command has the format: xi index location \r
 * The following define the:
 * START, everything before the index component
 * MIDDLE, the part after the index component up to the location component
 * END, the terminating carriage return.
 */

#define DISPLAY_BITMAP_COMMAND_START    ("xi ")
#define DISPLAY_BITMAP_COMMAND_MIDDLE   (" ")
#define DISPLAY_BITMAP_COMMAND_END      ("\r")

/* Max length (including null) of image index ("nnn\0") */

#define MAX_IMAGE_INDEX (4)

/*
 * Define a structure that contains all of the items that are usually necessary
 * when writing a graphic to the screen:
 * image_index, represents its index in the list of images that were supplied
 *              to the BMPload program. Convention is for a numerical prefix in
 *              the filename of the image to match the order as well.
 * location,    the location (x and y coordinates) of the start of the graphic
 */

typedef struct
{
   char image_index[MAX_IMAGE_INDEX];
   char location[MAX_LOCATION_TEXT];
}  DISPLAY_GRAPHIC_STRUCT;

/*
 * Fill an array with all of the graphics that will probably be written.
 */

static DISPLAY_GRAPHIC_STRUCT GraphicItems[NUM_DISPLAY_GRAPHIC_ITEM_IDS] =
{
   {"28", "0 0"},    /* THERAPY_BKGND_DISPLAY_ITEM_ID */
   {"29", "724 86"}, /* RESET_BTN_DISPLAY_ITEM_ID */
   {"30", "724 192"},/* CYCLE_BTN_DISPLAY_ITEM_ID */
   {"33", "724 297"},/* TIMER_UP_BTN_DISPLAY_ITEM_ID */
   {"34", "724 402"},/* TIMER_DOWN_BTN_DISPLAY_ITEM_ID */
   {"35", "88 255"}, /* OHMS_SYMBOL_DISPLAY_ITEM_ID */
   {"31", "724 297"},/* POWER_UP_BTN_DISPLAY_ITEM_ID */
   {"32", "724 402"},/* POWER_DOWN_BTN_DISPLAY_ITEM_ID */
   {"36", "314 368"},/* RF_RADIATING_DISPLAY_ITEM_ID (but macros.txt wins) */
   {"42", "32 438"}, /* WARNING_SYMBOL_ON_THERAPY_DISPLAY_ITEM_ID */
   {"43", "32 438"}, /* FAULT_SYMBOL_ON_THERAPY_DISPLAY_ITEM_ID */
   {"44", "32 438"}, /* WARNING_SYMBOL_ON_SPLASH_DISPLAY_ITEM_ID */
   {"45", "32 438"}, /* FAULT_SYMBOL_ON_SPLASH_DISPLAY_ITEM_ID */
   {" 0", "0 0"},    /* OHMS_BAR_DISPLAY_ITEM_ID (draw rectangle used instead)*/
};

/* Define strings for each of the power levels */

#define MAX_POWER_VALUE_TEXT (8) /* "Level n\0" */

static char Level2PowerText[MAX_POWER_VALUE_TEXT] = "Level 2";
static char Level1PowerText[MAX_POWER_VALUE_TEXT] = "Level 1";

/* Remember the last power value we wrote to the screen (for erases) */

static char OldPowerValueText[MAX_POWER_VALUE_TEXT];

static TE_ABLATE_POWER_SETTING_INDEX OldPowerValue = ABLATE_POWER_SETTING_LEVEL1;

/* Remember the last RF Total value we wrote to the screen (for erases) */

static char OldRFTotalValueText[MAX_VALUE_TEXT];

static int OldRFTotalSeconds = -1; /* Assures first value (0) is different than last */

/* Remember the last RF Cycle value we wrote to the screen (for erases) */

static char OldRFCycleValueText[MAX_VALUE_TEXT];

static int OldRFCycleSeconds = -1; /* Assures first value (0) is different than last */

/* Remember the last Cycles value we wrote to the screen (for erases) */

static char OldCyclesValueText[MAX_VALUE_TEXT];

static int OldCycles = -1; /* Assures first value (0) is different than last */

/* Remember the last temperature values we wrote to the screen (for erases) */

#define MAX_TEMPERATURE_VALUE_TEXT (9) /* "150\xB0C\0" */

static char OldMajorTempValueText[MAX_TEMPERATURE_VALUE_TEXT] = " "; /* any non-null */
static char OldMinorTempValueText[MAX_TEMPERATURE_VALUE_TEXT] = " "; /* any non-null */

static int OldDistalValue   = -1; /* Assures first value (0) is different than last */
static int OldProximalValue = -1; /* Assures first value (0) is different than last */

static int OldTempFaultCnt = 0;   /* For ablate_bad_tcx_cnts */

TE_ABLATE_POWER_SETTING_INDEX OldTempPowerValue; /* Pwr when temp was written */

/* Impedance rectangle command, dimensions, color and locations */
/* Command format is "r <x0> <y0> <x1> <y1> \r" */

#define IMPEDANCE_RECT_COMMAND_START      ("r 79 ")
#define IMPEDANCE_RECT_Y0_LOCATION        ("295")
#define IMPEDANCE_RECT_COMMAND_MIDDLE     (" ")
#define IMPEDANCE_RECT_REST_OF_LOCATION   ("119 435")
#define IMPEDANCE_RECT_COMMAND_END        ("\r")

/* Command to draw the entire impedance rectangle's border */

#define IMPEDANCE_RECT_BORDER_COMMAND ("r 79 295 119 435\r")

/* Command to draw the impedance rectangle's border and fill it in */

#define IMPEDANCE_RECT_BORDER_AND_FILL_COMMAND ("r 79 295 119 435 3 EBEBEB\r")

/*
 * Impedance bar graph is 435-295=140 pixels tall. To get 10 segments ...
 * The value is used instead of IMPEDANCE_RECT_Y0_LOCATION when drawing
 * the bars.
 */

#define IMPEDANCE_RECT_ONE_BAR_Y0_LOCATION    ("421")
#define IMPEDANCE_RECT_TWO_BARS_Y0_LOCATION   ("407")
#define IMPEDANCE_RECT_THREE_BARS_Y0_LOCATION ("393")
#define IMPEDANCE_RECT_FOUR_BARS_Y0_LOCATION  ("379")
#define IMPEDANCE_RECT_FIVE_BARS_Y0_LOCATION  ("365")
#define IMPEDANCE_RECT_SIX_BARS_Y0_LOCATION   ("351")
#define IMPEDANCE_RECT_SEVEN_BARS_Y0_LOCATION ("337")
#define IMPEDANCE_RECT_EIGHT_BARS_Y0_LOCATION ("323")
#define IMPEDANCE_RECT_NINE_BARS_Y0_LOCATION  ("309")
#define IMPEDANCE_RECT_TEN_BARS_Y0_LOCATION   ("295")

/*
 * Specify the color of the impedance bar graph fill when fill is desired.
 * Following assumes when you want to draw (vs erase) the filled rectangle
 * that you wish it to be off-white, Pure white was too hard to look at.
 */

#define IMPEDANCE_RECT_DRAW_FILLED_STYLE  ("3 EBEBEB") /* foreground (off-white) */
#define IMPEDANCE_RECT_ERASE_FILLED_STYLE ("3 000000") /* background (black) */

/* Command to erase the entire impedance rectangle */

#define IMPEDANCE_RECT_ERASE_COMMAND ("r 79 295 119 435 3 000000\r")

/* Impedance bar graph border color command (white on black */

#define IMPEDANCE_RECT_BORDER_COLOR_COMMAND ("S FFFFFF 000000\r")

/* Number of bars in the impedance bar graph */

typedef enum
{
   ZERO_BARS,
   ONE_BAR,
   TWO_BARS,
   THREE_BARS,
   FOUR_BARS,
   FIVE_BARS,
   SIX_BARS,
   SEVEN_BARS,
   EIGHT_BARS,
   NINE_BARS,
   TEN_BARS,
   NUM_BARS
}  IMPEDANCE_BARS;

/* The (upper) boundary for each impedance bar (in ohms*10) */

#define ZERO_BARS_IMPEDANCE   (200)
#define ONE_BARS_IMPEDANCE    (300)
#define TWO_BARS_IMPEDANCE    (430)
#define THREE_BARS_IMPEDANCE  (690)
#define FOUR_BARS_IMPEDANCE   (950)
#define FIVE_BARS_IMPEDANCE   (1500)
#define SIX_BARS_IMPEDANCE    (2050)
#define SEVEN_BARS_IMPEDANCE  (3300)
#define EIGHT_BARS_IMPEDANCE  (4550)
#define NINE_BARS_IMPEDANCE   (7300)
#define TEN_BARS_IMPEDANCE    (10000)

/* Remember the last impedance value we wrote to the screen (for erases) */

static int OldImpedanceBars = -1;
static int OldOkToFlashImpedance = -1;
static int OldImpedanceEraseOnly = -1;
static int OldImpedanceFlashState = 0;

/*
 * Command to enable the Radiating RF graphic.
 * The animation is defined in the Macros.txt file that is programmed into the
 * display by the BMPload program.
 *
 * See the description of DISPLAY_FLASHING_TEMP_TEXT_COMMAND_START regarding
 * the first argument of the command.
 */

#define RF_GRAPHIC_ENABLE_COMMAND ("anie 1\r")

/*
 * Command to disable the Radiating RF graphic.
 * The second argument to the anid call, the argument after the one that
 * specifies which animation to stop, names the slide to stop at, a slide
 * which effectively is an "erase" slide (a background-only slide).
 * Also see RF_GRAPHIC_ENABLE_COMMAND description.
 */

#define RF_GRAPHIC_DISABLE_COMMAND ("anid 1 5\r")

/* Command to erase the area that the Radiating RF covers */

#define RF_GRAPHIC_ERASE_COMMAND ("r 314 368 401 435 3 000000\r")

/* Remember the last up/down buttons label we wrote to the screen (for erases) */

#define MAX_UP_DOWN_BTNS_LABEL_TEXT (6) // "Power" or "Timer" and null

static char OldUpDownBtnsLabelText[MAX_UP_DOWN_BTNS_LABEL_TEXT] = "Timer";

/* Number of seconds in a minute */

#define SECONDS_TO_MINUTES (60)

/*******************************************************************************
****************** Static Function Prototypes **********************************
*******************************************************************************/

static int  DequeueGraphicRequest(char *request);
static void EnqueueFontColorAndText(DISPLAY_TEXT_ITEM_IDS id,
                                    REACH_TEXT_FONTS font,
                                    REACH_TEXT_COLORS color,
                                    char *text);
static int  EnqueueGraphicRequest(char *request);
static void EraseTextItem(DISPLAY_TEXT_ITEM_IDS id, char *string);
static void EraseTextItemUsingFont(DISPLAY_TEXT_ITEM_IDS id, char *string,
                                   REACH_TEXT_FONTS font);
static void SendRequest();

/*******************************************************************************
********************* Function Definitions *************************************
*******************************************************************************/

/*============================================================================*/
/*
 * Global:        gDFDisplyInit
 *
 */

int gDFDisplyInit(void)
{
   int i;
   int j;
   int display_init_succeeded = 0;
   static __far unsigned char *bp = DISPLAY_RX2_DMA_BUF;
   U16 temp;

   /* Initiate communications with the Reach Technology display */

   /*
    * The process is to:
    * 1) Send a null command (single return character)
    * 2) Wait at least 10ms for a response
    * 3) Look for a received success prompt (a ">")
    * 4) Send "*abt<return>" and look for a received success prompt if
    *    three null commands haven't yielded success.
    */

   /*
    * ... but first we'll delay as long as we know the startup animation is
    * (minus a guess for how long it took us to get to here in the program)
    */

   for (j = 0; j < 250; j++)
   {
      wait_for_20ms();
      KICK_THE_DOG;
   }

   /*
    * Initialize the hardware that interfaces the Reach Technology display.
    * The hardware consists of a UART and a DMA channel.                             .
    * The initialization is done here versus in hw_init() in DFHW.C because                                                                    .
    * the display outputs text when it powers up that has to be dealt with                                                                                                                                         .
    * (thrown away) or it will not even let the first read of the display's                                                                                                                                                                                                             .
    * response to our poll succeed. The display sends out text like:                                                                                                                                                                                                                                                                                  .
    *                                                                                                                                                                                                                                                                                                                                                              .
    * SLCD5 PLUS Bootloader V2.29 (C) Copyright 2010 ...                                                                                                                                                                                                                                                                                                                                                             .
    *                                                                                                                                                                                                                                                                                                                                                                                                                .
    * If the UART port is opened in hw_init() before/while the text is being                                                                                                                                                                                                                                                                                                                                                                                                               .
    * output it freezes the read functionality in the UART.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     .
    */

   U2MODE    = 0x8000;  // Turn on UART2, Lo speed BRG,8,N,1
   U2BRG     = 21;      // 115200 baud, 1.36% error
   U2STA     = 0x0400;  // enable output
   temp      = U2RXREG; // read rx register now and throw away

   DMA6CON   = 0x6001;  // DMA off, byte, to peripheral, one shot
   DMA6REQ   = 0x001F;  // UART2TX
   DMA6PAD   = 0x0234;  // U2TXREG
   DMA7CON   = 0x4001;  // DMA off, byte, from peripheral, one shot
   DMA7REQ   = 0x001E;  // UART2RX
   DMA7PAD   = 0x0236;  // U2RXREG

   for (i = 0; i < MAX_DISPLAY_INIT_RETRIES; i++)
   {
      if (i < MAX_DISPLAY_NULL_CMD_RETRIES)
      {
         /*
          * 1. Disable the DMA TX channel before we fill/configure it.
          * 2. Move the null command to the DMA TX buffer.
          * 3. Tell the DMA where the buffer starts. (We have to do this for
          *    every write because it auto-increments as it moves data out of it.)
          * 4. Tell the DMA how many characters to output (subtract 1 from actual)
          * 5. Enable the DMA TX channel and force the transfer to begin.
          */

         //DMA6_CHEN = 0;
         DMA6CONbits.CHEN = 0;
         DMA7CONbits.CHEN = 0;
         *bp = 0;

         memmove((void*) DISPLAY_TX2_DMA_BUF, (const void*) "\r", (size_t) 1);
         DMA6STA = DISPLAY_TX2_DMA_BUF - DMARAM;
         DMA6CNT = 0;
         DMA6CONbits.CHEN = 1;
         //DMA6_FORCE = 1;
         DMA6REQbits.FORCE = 1;

         /*
          * Set up this other DMA channel to RX the display's response.
          * We're expecting a two character response, a ">" or a "!" or the
          * other possible prompts and a carriage return.
          * Datasheet says to wait at least 10ms for a response.
          * The ">" character means it understood us and we've succeeded.
          */

         DMA7STA = DISPLAY_RX2_DMA_BUF - DMARAM;
         DMA7CNT = 1;
         DMA7CONbits.CHEN = 1;
         wait_for_20ms();
         if (*bp == '>')
         {
            DMA7CONbits.CHEN = 0;

            display_init_succeeded = 1;

            /*
             * Display has a habit of not responding to the first one or two
             * carriage returns and then sending multiple responses (approx 10ms
             * apart) to the carriage return that it does like. We need to get
             * those extra responses out of the buffer.
             */

            for (j = 0; j < i; j++)
            {
               DMA7CONbits.CHEN = 0;
               *bp = 0;
               DMA7STA = DISPLAY_RX2_DMA_BUF - DMARAM;
               DMA7CNT = 1;
               DMA7CONbits.CHEN = 1;
               wait_for_20ms();
               DMA7CONbits.CHEN = 0;
            }
            break;
         }
         else
         {
            DMA7CONbits.CHEN = 0;
         }
      }
      else
      {
         DMA6CONbits.CHEN = 0;
         DMA7CONbits.CHEN = 0;
         *bp = 0;

         memmove((void*) DISPLAY_TX2_DMA_BUF, (const void*) "*abt\r", (size_t) 5);
         DMA6STA = DISPLAY_TX2_DMA_BUF - DMARAM;
         DMA6CNT = 4;
         DMA6CONbits.CHEN = 1;
         DMA6REQbits.FORCE = 1;

         DMA7STA = DISPLAY_RX2_DMA_BUF - DMARAM;
         DMA7CNT = 1;
         DMA7CONbits.CHEN = 1;
         wait_for_20ms();
         if (*bp == '>')
         {
            DMA7CONbits.CHEN = 0;

            display_init_succeeded = 1;
            for (j = 0; j < MAX_DISPLAY_NULL_CMD_RETRIES; j++)
            {
               DMA7CONbits.CHEN = 0;
               *bp = 0;
               DMA7STA = DISPLAY_RX2_DMA_BUF - DMARAM;
               DMA7CNT = 1;
               DMA7CONbits.CHEN = 1;
               wait_for_20ms();
               DMA7CONbits.CHEN = 0;
            }
         }
         else
         {
            DMA7CONbits.CHEN = 0;
         }
      }
      KICK_THE_DOG;
   }

   return(display_init_succeeded);
}

/*============================================================================*/
/*
 * Static:        DequeueGraphicRequest
 *
 * Description:   Dequeue the request (a command string) from a circular queue.
 *
 * Parameters:    request - pointer to location where dequeued command string
 *                will be placed. Location must be large enough to store
 *                LIMITED_DISPLAY_CMD_LEN bytes.
 *
 * Returns:       1 if the function was successful, 0 otherwise.
 *
 * Side-effects: None
 */

static int DequeueGraphicRequest(char *request)
{
   /* default to queue underflow error */

   int success = 0;

   /* check if queue is empty */

   if (QueueEntryCount != 0)
   {
      /* There is at least one entry to dequeue */

      /* call library function to load contents of queue entry pointed to by
       * source pointer into memory pointed to by dest pointer. source pointer
       * is set to entry to dequeue. dequeue index multiplied by entry size
       * provides us with the index to the start of the queue entry to dequeue
       */

      memcpy((void *) request,
             (void *)((char *)Queue + (QueueDequeueIndex * QUEUE_ENTRY_SIZE)),
             QUEUE_ENTRY_SIZE);

      /* update dequeue index to next entry to dequeue. The queue is a circular
       * buffer. If we just dequeued an entry from the end of the queue, the
       * index is set to the top of the queue.
       */

      QueueDequeueIndex = (QueueDequeueIndex+1) & (MAX_POSSIBLE_QUEUE_ENTRIES-1);

      /* decrement entry count */

      QueueEntryCount--;

      success = 1;
   }

   return(success);
}

/*============================================================================*/
/*
 * Static:        EnqueueFontColorAndText
 *
 * Description:   This function enqueues the font/color/text "triplet" of
 *                information unto the graphic request queue.
 *
 * Parameters:    id    - the display item id that is related to the text
 *                        (used to prevent recursion when the id relates to
 *                        the warning or fault ids)
 *                font  - the font to enqueue
 *                color - the color to enqueue
 *                text  - the text to enqueue
 *
 * Returns:       None
 *
 * Side-effects:  The fault routine will be called (effectively stopping the
 *                program) if an enqueuing error occurs.
 */

static void EnqueueFontColorAndText(DISPLAY_TEXT_ITEM_IDS id,
                                    REACH_TEXT_FONTS font,
                                    REACH_TEXT_COLORS color,
                                    char *text)
{
   int success;

   success = EnqueueGraphicRequest(Fonts[font]);

   if (success == 1)
   {
      success = EnqueueGraphicRequest(Colors[color]);
   }

   if (success == 1)
   {
      success = EnqueueGraphicRequest(text);
   }

   if ((success == 0) &&
       (id != WARNING_VALUE_ON_SPLASH_DISPLAY_ITEM_ID) &&
       (id != WARNING_VALUE_ON_THERAPY_DISPLAY_ITEM_ID) &&
       (id != FAULT_VALUE_ON_SPLASH_DISPLAY_ITEM_ID) &&
       (id != FAULT_VALUE_ON_THERAPY_DISPLAY_ITEM_ID))
   {
      fault_routine(WARNING_SEVERITY, ERROR_DFDISPLY_FCAT,
                   "EnqueueFontColorAndText()");
   }
}

/*============================================================================*/
/*
 * Static:        EnqueueGraphicRequest
 *
 * Description:   Enqueue the request (a command string) onto a circular queue.
 *
 * Parameters:    request - pointer to command string. String
 *                (including terminating null) must be less than or equal to
 *                LIMITED_DISPLAY_CMD_LEN.
 *
 * Returns:       1 if the function was successful, 0 otherwise.
 *
 * Side-effects: None
 */

static int EnqueueGraphicRequest(char *request)
{
   /* default to queue overflow error */

   int success = 0;

   int cmd_len = strlen(request);

   /* check if queue is already full */

   if ((QueueEntryCount < MAX_POSSIBLE_QUEUE_ENTRIES) &&
       (cmd_len < LIMITED_DISPLAY_CMD_LEN))
   {
      /* Queue has space for at least one more entry */

      /* call library function to load memory contents pointed to by source
       * pointer into memory pointed to by dest pointer. dest pointer is set to
       * queue entry to enqueue. enqueue index multiplied by entry size
       * provides us with the index to the start of the queue entry to enqueue.
       */

      memcpy((void *)((char *)Queue + (QueueEnqueueIndex * QUEUE_ENTRY_SIZE)),
             request, cmd_len+1);

      /* update enqueue index to next entry in queue. The queue is a circular
       * buffer. If we just enqueued an entry into end of the queue, the index
       * is set to the top of the queue.
       */

      QueueEnqueueIndex = (QueueEnqueueIndex+1) & (MAX_POSSIBLE_QUEUE_ENTRIES-1);

      /* increment entry count */

      QueueEntryCount++;

      /* no queue overflow, return no error  */

      success = 1;
   }

   return success;
}

/*============================================================================*/
/*
 * Static:        EraseTextItem
 *
 * Description:   Erase a text item by rewriting the value it is currently
 *                displaying - in the background color.
 *
 *                If, instead, you merely tried to write a different set of
 *                characters on top of it, even a set that had the same number
 *                of characters, artifacts might be left on the screen because
 *                characters like a "W" are wider than a "D". Affects the right
 *                end of strings if the string is left-justfied - and probably
 *                other justifications.
 *
 * Parameters:    id     - the display id of the value you want to erase
 *                string - the text value that the id is currently showing
 *                font   - the font that the value was written in
 *
 * Returns:       None
 *
 * Side-effects:  The fault routine will be called (effectively stopping the
 *                program) if an enqueuing error occurs.
 */

static void EraseTextItem(DISPLAY_TEXT_ITEM_IDS id, char *string)
{
   EraseTextItemUsingFont(id, string, TextItems[id].font);
}

/*============================================================================*/
/*
 * Static:        EraseTextItemUsingFont
 *
 * Description:   Erase a text item by rewriting the value it is currently
 *                displaying - in the background color - using the passed-in
 *                font.
 *
 *                The font argument is useful when a value is sometimes written
 *                in one font and then another. If the font never changes, use
 *                the simpler function named EraseTextItem instead.
 *
 *                If, instead, you merely tried to write a different set of
 *                characters on top of it, even a set that had the same number
 *                of characters, artifacts might be left on the screen because
 *                characters like a "W" are wider than a "D". Affects the right
 *                end of strings if the string is left-justfied - and probably
 *                other justifications.
 *
 * Parameters:    id     - the display id of the value you want to erase
 *                string - the text value that the id is currently showing
 *                font   - the font that the current value was written in
 *
 * Returns:       None
 *
 * Side-effects:  The fault routine will be called (effectively stopping the
 *                program) if an enqueuing error occurs.
 */

static void EraseTextItemUsingFont(DISPLAY_TEXT_ITEM_IDS id, char *string,
                                   REACH_TEXT_FONTS font)
{
   char text[LIMITED_DISPLAY_CMD_LEN];

   strcpy (text, DISPLAY_TEXT_COMMAND_START);
   strcat (text, string);
   strcat (text, DISPLAY_TEXT_COMMAND_MIDDLE);
   strcat (text, TextItems[id].location);
   strcat (text, DISPLAY_TEXT_COMMAND_END);

   EnqueueFontColorAndText(id, font, TextItems[id].erase_color, text);
}

/*============================================================================*/
/*
 * Global:        gDFDisplyClearScreen
 */

void gDFDisplyClearScreen (REACH_TEXT_COLORS color)
{
   int success;

   success = EnqueueGraphicRequest(Colors[color]);

   if (success == 1)
   {
      success = EnqueueGraphicRequest("z \r");
   }

   #ifdef   DFTEST
   if (success == 1)
   {
      /* wait until buffers are processed/output */
      while (gDFDisplyDoesGraphicDisplayHaveWorkToDo() == 1)
      {
         wait_for_20ms();
         if (gDFDisplyProcessDisplayRequests() == 0)
         {
            break;
         }
         KICK_THE_DOG;
      }
   }
   #endif   // #ifdef   DFTEST
}

/*============================================================================*/
/*
 * Global:        gDFDisplyDisableRFGraphicItem
 */

void gDFDisplyDisableRFGraphicItem()
{
   char text[LIMITED_DISPLAY_CMD_LEN];

   strcpy (text, RF_GRAPHIC_DISABLE_COMMAND);
   EnqueueGraphicRequest(text);
}

/*============================================================================*/
/*
 * Global:        gDFDisplyDoesGraphicDisplayHaveWorkToDo
 *
 */

int gDFDisplyDoesGraphicDisplayHaveWorkToDo()
{
   if ((QueueEntryCount > 0) || (RequestInProgress == 1))
   {
      return(1);
   }
   else
   {
      return(0);
   }
}

/*============================================================================*/
/*
 * Global:        gDFDisplyPrintCyclesValueTextItem
 */

void gDFDisplyPrintCyclesValueTextItem(int cycles)
{
   char text[LIMITED_DISPLAY_CMD_LEN];

   if (cycles != OldCycles)
   {
      OldCycles = cycles;

      sprintf(OldCyclesValueText, "%02d", cycles);

      strcpy (text, DISPLAY_TEXT_COMMAND_START);
      strcat (text, OldCyclesValueText);
      strcat (text, DISPLAY_TEXT_COMMAND_MIDDLE);
      strcat (text, TextItems[CYCLES_VALUE_DISPLAY_ITEM_ID].location);
      strcat (text, DISPLAY_TEXT_COMMAND_END);

      EnqueueFontColorAndText(CYCLES_VALUE_DISPLAY_ITEM_ID,
                              TextItems[CYCLES_VALUE_DISPLAY_ITEM_ID].font,
                              TextItems[CYCLES_VALUE_DISPLAY_ITEM_ID].color,
                              text);
   }
}

/*============================================================================*/
/*
 * Global:        gDFDisplyPrintErrorItem
 */

void gDFDisplyPrintErrorItem(ERROR_SEVERITY severity, U16 error,
                             const char *message, DISPLAY_SCREENS screen)
{
   DISPLAY_GRAPHIC_ITEM_IDS graphic_id;
   DISPLAY_TEXT_ITEM_IDS text_id;
   char error_value[MAX_VALUE_TEXT];
   char text[LIMITED_DISPLAY_CMD_LEN];

   if (severity == WARNING_SEVERITY)
   {
      if (screen == SPLASH_DISPLAY_SCREEN)
      {
         graphic_id = WARNING_SYMBOL_ON_SPLASH_DISPLAY_ITEM_ID;
         text_id    = WARNING_VALUE_ON_SPLASH_DISPLAY_ITEM_ID;
      }
      else
      {
         graphic_id = WARNING_SYMBOL_ON_THERAPY_DISPLAY_ITEM_ID;
         text_id    = WARNING_VALUE_ON_THERAPY_DISPLAY_ITEM_ID;
      }
   }
   else
   {
      if (screen == SPLASH_DISPLAY_SCREEN)
      {
         graphic_id = FAULT_SYMBOL_ON_SPLASH_DISPLAY_ITEM_ID;
         text_id    = FAULT_VALUE_ON_SPLASH_DISPLAY_ITEM_ID;
      }
      else
      {
         graphic_id = FAULT_SYMBOL_ON_THERAPY_DISPLAY_ITEM_ID;
         text_id    = FAULT_VALUE_ON_THERAPY_DISPLAY_ITEM_ID;
      }
   }

   /* First print the icon and then the code and/or message */

   #ifndef  DFTEST
   if (error != ERROR_DFDISPLY_GRAPHIC)
   {
      gDFDisplyPrintGraphicItem(graphic_id);
   }
   #endif

   strcpy (text, DISPLAY_TEXT_COMMAND_START);
   strcat (text, TextItems[text_id].text);

   sprintf(error_value, "%02d", error);

   strcat (text, error_value);
   strcat (text, DISPLAY_TEXT_COMMAND_MIDDLE);
   strcat (text, TextItems[text_id].location);
   strcat (text, DISPLAY_TEXT_COMMAND_END);

   if (error != ERROR_DFDISPLY_FCAT)
   {
      EnqueueFontColorAndText(text_id,
                              TextItems[text_id].font, TextItems[text_id].color,
                              text);
   }

}

/*============================================================================*/
/*
 * Global:        gDFDisplyPrintGraphicItem
 */

void gDFDisplyPrintGraphicItem(DISPLAY_GRAPHIC_ITEM_IDS id)
{
   int success = 1;

   char text[LIMITED_DISPLAY_CMD_LEN];

   switch (id)
   {
      case THERAPY_BKGND_DISPLAY_ITEM_ID:    /* intentional fall-through */
      case RESET_BTN_DISPLAY_ITEM_ID:        /* intentional fall-through */
      case CYCLE_BTN_DISPLAY_ITEM_ID:        /* intentional fall-through */
      case POWER_UP_BTN_DISPLAY_ITEM_ID:     /* intentional fall-through */
      case POWER_DOWN_BTN_DISPLAY_ITEM_ID:   /* intentional fall-through */
      case TIMER_UP_BTN_DISPLAY_ITEM_ID:     /* intentional fall-through */
      case TIMER_DOWN_BTN_DISPLAY_ITEM_ID:   /* intentional fall-through */
      case OHMS_SYMBOL_DISPLAY_ITEM_ID:      /* intentional fall-through */
      case FAULT_SYMBOL_ON_SPLASH_DISPLAY_ITEM_ID:   /* intentional fall-through */
      case WARNING_SYMBOL_ON_SPLASH_DISPLAY_ITEM_ID: /* intentional fall-through */
      case FAULT_SYMBOL_ON_THERAPY_DISPLAY_ITEM_ID:  /* intentional fall-through */
      case WARNING_SYMBOL_ON_THERAPY_DISPLAY_ITEM_ID:/* intentional fall-through */

         strcpy (text, DISPLAY_BITMAP_COMMAND_START);
         strcat (text, GraphicItems[id].image_index);
         strcat (text, DISPLAY_BITMAP_COMMAND_MIDDLE);
         strcat (text, GraphicItems[id].location);
         strcat (text, DISPLAY_BITMAP_COMMAND_END);
         break;

      default:
         success = 0;
         break;
   }

   if (success == 1)
   {
      success = EnqueueGraphicRequest(text);
   }

   /* Complain of any fault (except the reporting of a fault - recursion) */

   if ((success == 0) &&
       (id != FAULT_SYMBOL_ON_SPLASH_DISPLAY_ITEM_ID) &&
       (id != WARNING_SYMBOL_ON_SPLASH_DISPLAY_ITEM_ID) &&
       (id != FAULT_SYMBOL_ON_THERAPY_DISPLAY_ITEM_ID) &&
       (id != WARNING_SYMBOL_ON_THERAPY_DISPLAY_ITEM_ID))
   {
      fault_routine(WARNING_SEVERITY, ERROR_DFDISPLY_GRAPHIC, "PrintGraphic()");
   }
}

/*============================================================================*/
/*
 * Global:        gDFDisplyPrintImpedanceGraphicItem
 */

void gDFDisplyPrintImpedanceGraphicItem(int value, int ok_to_flash,
                                        int imp_fault_cnt, int erase_only)
{
   int success;
   int flash = 0;
   char text[LIMITED_DISPLAY_CMD_LEN];
   int impedance_bars;

   /*
    * See if the number of impedance bars would be different than last time.
    * (If we just used the passed-in impedance we would be refreshing the screen
    * practically at every call - because the passed-in value changes on every
    * call - but usually not enough to change the number of displayed bars.)
    */

   if (value < ZERO_BARS_IMPEDANCE)
   {
      impedance_bars = ZERO_BARS;
   }
   else if ((value >= ZERO_BARS_IMPEDANCE) && (value <= ONE_BARS_IMPEDANCE))
   {
      impedance_bars = ONE_BAR;
   }
   else if ((value > ONE_BARS_IMPEDANCE) && (value <= TWO_BARS_IMPEDANCE))
   {
      impedance_bars = TWO_BARS;
   }
   else if ((value > TWO_BARS_IMPEDANCE) && (value <= THREE_BARS_IMPEDANCE))
   {
      impedance_bars = THREE_BARS;
   }
   else if ((value >  THREE_BARS_IMPEDANCE) && (value <= FOUR_BARS_IMPEDANCE))
   {
      impedance_bars = FOUR_BARS;
   }
   else if ((value >  FOUR_BARS_IMPEDANCE) && (value <= FIVE_BARS_IMPEDANCE))
   {
      impedance_bars = FIVE_BARS;
   }
   else if ((value >  FIVE_BARS_IMPEDANCE) && (value <= SIX_BARS_IMPEDANCE))
   {
      impedance_bars = SIX_BARS;
   }
   else if ((value >  SIX_BARS_IMPEDANCE) && (value <= SEVEN_BARS_IMPEDANCE))
   {
      impedance_bars = SEVEN_BARS;
   }
   else if ((value >  SEVEN_BARS_IMPEDANCE) && (value <= EIGHT_BARS_IMPEDANCE))
   {
      impedance_bars = EIGHT_BARS;
   }
   else if ((value >  EIGHT_BARS_IMPEDANCE) && (value <= NINE_BARS_IMPEDANCE))
   {
      impedance_bars = NINE_BARS;
   }
   else if ((value >  NINE_BARS_IMPEDANCE) && (value <= TEN_BARS_IMPEDANCE))
   {
      impedance_bars = TEN_BARS;
   }
   else
   {
      impedance_bars = NUM_BARS;
   }

   /*
    * Don't do anything if all of the inputs are the same as last time
    * (unless the impedance fault count variable is non-zero and it's ok to flash).
    */

   if((impedance_bars     != OldImpedanceBars)      ||
      (ok_to_flash        != OldOkToFlashImpedance) ||
      (erase_only         != OldImpedanceEraseOnly) ||
     ((imp_fault_cnt > 0) && (ok_to_flash == 1)))
   {
      OldImpedanceBars      = impedance_bars;
      OldOkToFlashImpedance = ok_to_flash;
      OldImpedanceEraseOnly = erase_only;

      /* Erase current value (including border) */

      strcpy (text, IMPEDANCE_RECT_ERASE_COMMAND);
      success = EnqueueGraphicRequest(text);

      if ((success == 1) && (erase_only == 0))
      {
         /* Set the foreground color (for the border) */

         strcpy (text, IMPEDANCE_RECT_BORDER_COLOR_COMMAND);
         success = EnqueueGraphicRequest(text);

         if (success == 1)
         {
            /* Is the impedance out of range? */

            if ((impedance_bars == ZERO_BARS) || (impedance_bars == NUM_BARS))
            {
               /* Flash the impedance if caller says it's an ok time to do so */

               if (ok_to_flash == 1)
               {
                  if (OldImpedanceFlashState == 0)
                  {
                     OldImpedanceFlashState = 1;

                     /*
                      * Flash just the border if we're under the limit.
                      * Flash the interior and the border if we're over.
                      */

                     if (impedance_bars == ZERO_BARS)
                     {
                        /* Just write the border */

                        strcpy (text, IMPEDANCE_RECT_BORDER_COMMAND);
                     }
                     else
                     {
                        /* Write the border and fill the interior */

                        strcpy (text, IMPEDANCE_RECT_BORDER_AND_FILL_COMMAND);
                     }

                     success = EnqueueGraphicRequest(text);
                  }
                  else
                  {
                     OldImpedanceFlashState = 0;

                     /* No need to do anything. Rectangle was already erased */
                  }
               }
               else
               {
                  /* Don't flash, Just write the rectangle border */

                  strcpy (text, IMPEDANCE_RECT_BORDER_COMMAND);

                  success = EnqueueGraphicRequest(text);
               }
            }
            else
            {
               /* Write rectangle border prior to filling it in below */

               strcpy (text, IMPEDANCE_RECT_BORDER_COMMAND);
               success = EnqueueGraphicRequest(text);

               if (success == 1)
               {
                  /* Now write bars */

                  strcpy (text, IMPEDANCE_RECT_COMMAND_START);

                  switch (impedance_bars)
                  {
                     case ONE_BAR:
                        strcat (text, IMPEDANCE_RECT_ONE_BAR_Y0_LOCATION);
                        break;
                     case TWO_BARS:
                        strcat (text, IMPEDANCE_RECT_TWO_BARS_Y0_LOCATION);
                        break;
                     case THREE_BARS:
                        strcat (text, IMPEDANCE_RECT_THREE_BARS_Y0_LOCATION);
                        break;
                     case FOUR_BARS:
                        strcat (text, IMPEDANCE_RECT_FOUR_BARS_Y0_LOCATION);
                        break;
                     case FIVE_BARS:
                        strcat (text, IMPEDANCE_RECT_FIVE_BARS_Y0_LOCATION);
                        break;
                     case SIX_BARS:
                        strcat (text, IMPEDANCE_RECT_SIX_BARS_Y0_LOCATION);
                        break;
                     case SEVEN_BARS:
                        strcat (text, IMPEDANCE_RECT_SEVEN_BARS_Y0_LOCATION);
                        break;
                     case EIGHT_BARS:
                        strcat (text, IMPEDANCE_RECT_EIGHT_BARS_Y0_LOCATION);
                        break;
                     case NINE_BARS:
                        strcat (text, IMPEDANCE_RECT_NINE_BARS_Y0_LOCATION);
                        break;
                     case TEN_BARS:
                        strcat (text, IMPEDANCE_RECT_TEN_BARS_Y0_LOCATION);
                        break;
                     default: /* Can't happen */
                        break;
                  }

                  strcat (text, IMPEDANCE_RECT_COMMAND_MIDDLE);
                  strcat (text, IMPEDANCE_RECT_REST_OF_LOCATION);
                  strcat (text, IMPEDANCE_RECT_COMMAND_MIDDLE);
                  strcat (text, IMPEDANCE_RECT_DRAW_FILLED_STYLE);
                  strcat (text, IMPEDANCE_RECT_COMMAND_END);

                  success = EnqueueGraphicRequest(text);
               }
            }
         }
      }

      if (success == 0)
      {
         fault_routine(WARNING_SEVERITY, ERROR_DFDISPLY_IMPEDANCE,
                      "PrintImpedance()");
      }
   }
}

/*============================================================================*/
/*
 * Global:        gDFDisplyPrintPowerValueTextItem
 */

void gDFDisplyPrintPowerValueTextItem(TE_ABLATE_POWER_SETTING_INDEX power_value)
{
   char text[LIMITED_DISPLAY_CMD_LEN];

   /*
    * This code is different than others you will see in this file in that it
    * writes the power value even though it may not have changed since the last
    * time we were called. It's important (to safety) that the power represented
    * on the screen is always in sync with the power that is being delivered.
    * This is one way to make sure it is always current on the display.
    * (The string is also short and therefore won't flicker much as it is
    * being updated.)
    */

   switch (power_value)
   {
      case ABLATE_POWER_SETTING_LEVEL2:
         strcpy (OldPowerValueText, Level2PowerText);
         break;
      case ABLATE_POWER_SETTING_LEVEL1:
         strcpy (OldPowerValueText, Level1PowerText);
         break;
      default: /* cases cover all possibilities for type */
         break;
   }

   OldPowerValue = power_value;

   strcpy (text, DISPLAY_TEXT_COMMAND_START);
   strcat (text, OldPowerValueText);
   strcat (text, DISPLAY_TEXT_COMMAND_MIDDLE);
   strcat (text, TextItems[POWER_VALUE_DISPLAY_ITEM_ID].location);
   strcat (text, DISPLAY_TEXT_COMMAND_END);

   EnqueueFontColorAndText(POWER_VALUE_DISPLAY_ITEM_ID,
                           TextItems[POWER_VALUE_DISPLAY_ITEM_ID].font,
                           TextItems[POWER_VALUE_DISPLAY_ITEM_ID].color, text);
}

/*============================================================================*/
/*
 * Global:        gDFDisplyPrintRFCycleValueTextItem
 */

void gDFDisplyPrintRFCycleValueTextItem(int seconds, int force_write,
                                        int erase_only)
{
   int minutes;
   char text[LIMITED_DISPLAY_CMD_LEN];

   if ((seconds != OldRFCycleSeconds) || (force_write == 1))
   {
      /* Clear out old value - new value may be shorter and leave artifact */

      if (force_write == 1)
      {
         EraseTextItem(RF_CYCLE_VALUE_DISPLAY_ITEM_ID, OldRFCycleValueText);
      }

      if (erase_only == 0)
      {
         OldRFCycleSeconds = seconds;

         minutes = seconds / SECONDS_TO_MINUTES;
         seconds = seconds % SECONDS_TO_MINUTES;

         sprintf(OldRFCycleValueText, "%02d:%02d", minutes, seconds);

         strcpy (text, DISPLAY_TEXT_COMMAND_START);
         strcat (text, OldRFCycleValueText);
         strcat (text, DISPLAY_TEXT_COMMAND_MIDDLE);
         strcat (text, TextItems[RF_CYCLE_VALUE_DISPLAY_ITEM_ID].location);
         strcat (text, DISPLAY_TEXT_COMMAND_END);

         EnqueueFontColorAndText(RF_CYCLE_VALUE_DISPLAY_ITEM_ID,
                                 TextItems[RF_CYCLE_VALUE_DISPLAY_ITEM_ID].font,
                                 TextItems[RF_CYCLE_VALUE_DISPLAY_ITEM_ID].color,
                                 text);
      }
   }
}

/*============================================================================*/
/*
 * Global:        gDFDisplyPrintRFGraphicItem
 */

void gDFDisplyPrintRFGraphicItem(int write)
{
   int success;
   char text[LIMITED_DISPLAY_CMD_LEN];

   if (write == 1)
   {
      /* Turn on animation */

      strcpy (text, RF_GRAPHIC_ENABLE_COMMAND);
      success = EnqueueGraphicRequest(text);
   }
   else
   {
      /* Turn off animation */

      strcpy (text, RF_GRAPHIC_DISABLE_COMMAND);
      success = EnqueueGraphicRequest(text);
   }

   if (success == 0)
   {
      fault_routine(WARNING_SEVERITY, ERROR_DFDISPLY_RF_GRAPHIC,
                   "PrintRFGraphic()");
   }
}

/*============================================================================*/
/*
 * Global:        gDFDisplyPrintRFToTalValueTextItem
 */

void gDFDisplyPrintRFToTalValueTextItem(int seconds)
{
   int minutes;
   char text[LIMITED_DISPLAY_CMD_LEN];

   if (seconds != OldRFTotalSeconds)
   {
      OldRFTotalSeconds = seconds;

      minutes = seconds / SECONDS_TO_MINUTES;
      seconds = seconds % SECONDS_TO_MINUTES;

      sprintf(OldRFTotalValueText, "%02d:%02d", minutes, seconds);

      strcpy (text, DISPLAY_TEXT_COMMAND_START);
      strcat (text, OldRFTotalValueText);
      strcat (text, DISPLAY_TEXT_COMMAND_MIDDLE);
      strcat (text, TextItems[RF_TOTAL_VALUE_DISPLAY_ITEM_ID].location);
      strcat (text, DISPLAY_TEXT_COMMAND_END);

      EnqueueFontColorAndText(RF_TOTAL_VALUE_DISPLAY_ITEM_ID,
                              TextItems[RF_TOTAL_VALUE_DISPLAY_ITEM_ID].font,
                              TextItems[RF_TOTAL_VALUE_DISPLAY_ITEM_ID].color,
                              text);
   }
}

/*============================================================================*/
/*
 * Global:        gDFDisplyPrintTemperatureValues
 */

void gDFDisplyPrintTemperatureValues(TE_ABLATE_POWER_SETTING_INDEX power_value,
   int proximal_temp, int distal_temp, int temp_fault_cnt, int force_write,
   int erase_only)
{
   int stopped_flashing = 0;
   int success = 1;

   DISPLAY_TEXT_ITEM_IDS major_id;
   DISPLAY_TEXT_ITEM_IDS minor_id;

   char text[LIMITED_DISPLAY_CMD_LEN];

   /*
    * Don't print anything if everything's the same as last time
    * (unless caller is forcing a write)
    */

   if ((power_value    != OldTempPowerValue) ||
       (proximal_temp  != OldProximalValue)  ||
       (distal_temp    != OldDistalValue)    ||
       (temp_fault_cnt != OldTempFaultCnt)   ||
       (force_write    == 1))
   {
      major_id = PROXIMAL_LARGE_VALUE_DISPLAY_ITEM_ID;
      minor_id = DISTAL_LARGE_VALUE_DISPLAY_ITEM_ID;

      /* Clear out old values */

      /* Complicating factor is whether a temp was out-of-range and flashing */

      if (OldTempFaultCnt == 1)
      {
         /* was flashing */

         /* is there a reason to stop flashing the one that was */
         /* (did the power setting change - which means the prominence should)*/
         /* (are the temps no longer faulting) */
         /* (do we need to change the - prominent - value that is flashing) */
         /* (did they specify an erase-only - because they're entering settings mode) */

         /* The number of power levels and which temperature is prominent for
          * that level is expected to change in the next version of the product -
          * so the condition you see below is a little more pedantic
          * than if the power level to prominence characteristics were more
          * stable.
          */

         if ((power_value != OldTempPowerValue) ||
             (temp_fault_cnt == 0) ||
             ((OldTempPowerValue == ABLATE_POWER_SETTING_LEVEL1) && (proximal_temp != OldProximalValue))  ||
             ((OldTempPowerValue == ABLATE_POWER_SETTING_LEVEL2) && (proximal_temp != OldProximalValue))  ||
             (erase_only == 1))
         {
            /* yes, stop flashing whichever was the prominent temperature */

            stopped_flashing = 1;

            success = EnqueueGraphicRequest(DISABLE_FLASHING_TEMP_TEXT_COMMAND);
            if (success == 1)
            {
               success = EnqueueGraphicRequest(DELETE_FLASHING_TEMP_TEXT_COMMAND);
            }

            if (success == 1)
            {
               /*
                * The above doesn't always erase the temperature.
                * It does always stop the flashing.                                                         .
                * Probably has something to do with the display wanting to                                                                                          .
                * have time to get to the state mentioned in the tfd command                                                                                                                                                  .
                * before it sees a tfx command even though their document                                                                                                                                                                                                            .
                * says nothing to that affect.                                                                                                                                                                                                                                                                   .
                *                                                                                                                                                                                                                                                                                                .
                * We'll ensure it's erased the old-fashioned way.
                */

               EraseTextItem(major_id, OldMajorTempValueText);
            }
         }

         /* Erase the one that wasn't flashing */

         if ((success == 1) && (force_write == 1))
         {
            EraseTextItem(minor_id, OldMinorTempValueText);
         }
      }
      else
      {
         /* nothing was flashing, simply erase both old temp values */

         if (force_write == 1)
         {
            EraseTextItem(major_id, OldMajorTempValueText);
            EraseTextItem(minor_id, OldMinorTempValueText);
         }
      }

      /*
       * Stop here, don't write new values, if caller just wanted to erase old.
       */

      if ((success == 1) && (erase_only == 0))
      {
         /* Start writing new values ... */

         /* convert them to ASCII (and add degree symbol and 'C') */

         sprintf(OldMajorTempValueText, "%02d\\xB0C", proximal_temp);
         sprintf(OldMinorTempValueText, "%02d\\xB0C", distal_temp);

         /* Is a temperature faulting? */

         if (temp_fault_cnt == 1)
         {
            /* Were we faulting before? */

            if (OldTempFaultCnt == 1)
            {
               /*
                * Is there a reason to change that flashing?
                * (Did we stop the flashing in the above?)
                */

               if (stopped_flashing == 1)
               {
                  /* Yes, start flashing w/at least 1 new parameter */

                  strcpy (text, DISPLAY_FLASHING_TEMP_TEXT_COMMAND_START);
                  strcat (text, OldMajorTempValueText);
                  strcat (text, DISPLAY_TEXT_COMMAND_MIDDLE);
                  strcat (text, TextItems[major_id].location);
                  strcat (text, DISPLAY_TEXT_COMMAND_END);

                  EnqueueFontColorAndText(major_id,
                                          TextItems[major_id].font,
                                          TextItems[major_id].color, text);
               }
            }
            else
            {
               /* We weren't faulting before, flash prominent temp */

               strcpy (text, DISPLAY_FLASHING_TEMP_TEXT_COMMAND_START);
               strcat (text, OldMajorTempValueText);
               strcat (text, DISPLAY_TEXT_COMMAND_MIDDLE);
               strcat (text, TextItems[major_id].location);
               strcat (text, DISPLAY_TEXT_COMMAND_END);

               EnqueueFontColorAndText(major_id,
                                       TextItems[major_id].font,
                                       TextItems[major_id].color, text);
            }

            /* Print the non-prominent (minor) temp */

            strcpy (text, DISPLAY_TEXT_COMMAND_START);
            strcat (text, OldMinorTempValueText);
            strcat (text, DISPLAY_TEXT_COMMAND_MIDDLE);
            strcat (text, TextItems[minor_id].location);
            strcat (text, DISPLAY_TEXT_COMMAND_END);

            EnqueueFontColorAndText(minor_id,
                                    TextItems[minor_id].font,
                                    TextItems[minor_id].color, text);

         }
         else
         {
            /* No temperature fault, display both temps w/o flashing */

            strcpy (text, DISPLAY_TEXT_COMMAND_START);
            strcat (text, OldMajorTempValueText);
            strcat (text, DISPLAY_TEXT_COMMAND_MIDDLE);
            strcat (text, TextItems[major_id].location);
            strcat (text, DISPLAY_TEXT_COMMAND_END);

            EnqueueFontColorAndText(major_id,
                                    TextItems[major_id].font,
                                    TextItems[major_id].color, text);

            strcpy (text, DISPLAY_TEXT_COMMAND_START);
            strcat (text, OldMinorTempValueText);
            strcat (text, DISPLAY_TEXT_COMMAND_MIDDLE);
            strcat (text, TextItems[minor_id].location);
            strcat (text, DISPLAY_TEXT_COMMAND_END);

            EnqueueFontColorAndText(minor_id,
                                    TextItems[minor_id].font,
                                    TextItems[minor_id].color, text);
         }
      }

      OldTempPowerValue = power_value;
      OldProximalValue  = proximal_temp;
      OldDistalValue    = distal_temp;
      OldTempFaultCnt   = temp_fault_cnt;

      if (success == 0)
      {
         fault_routine(WARNING_SEVERITY, ERROR_DFDISPLY_TEMP, "PrintTemperature()");
      }
   }
}

/*============================================================================*/
/*
 * Global:        gDFDisplyPrintText
 */

void gDFDisplyPrintText(char *string, REACH_TEXT_FONTS font,
                        REACH_TEXT_COLORS color, int x, int y)
{
   char text[LIMITED_DISPLAY_CMD_LEN];
   char coordinates[MAX_LOCATION_TEXT];

   strcpy (text, DISPLAY_TEXT_COMMAND_START);
   strcat (text, string);
   strcat (text, DISPLAY_TEXT_COMMAND_MIDDLE);

   sprintf(coordinates, "%d %d", x, y);

   strcat (text, coordinates);
   strcat (text, DISPLAY_TEXT_COMMAND_END);

   EnqueueFontColorAndText(NUM_DISPLAY_TEXT_ITEM_IDS, font, color, text);

   #ifdef   DFTEST
   /* wait until buffers are processed/output */
   while (gDFDisplyDoesGraphicDisplayHaveWorkToDo() == 1)
   {
      wait_for_20ms();
      if (gDFDisplyProcessDisplayRequests() == 0)
      {
         break;
      }
      KICK_THE_DOG;
   }
   #endif   // #ifdef   DFTEST
}

#ifdef   DFTEST
/*============================================================================*/
/*
 * Global:        gDFDisplyPrintTextFlash
 */

void gDFDisplyPrintTextFlash (char *string, REACH_TEXT_FONTS font,
                              REACH_TEXT_COLORS color, int x, int y)
{
   char text[LIMITED_DISPLAY_CMD_LEN];
   char coordinates[MAX_LOCATION_TEXT];

   strcpy (text, DISPLAY_FLASHING_DFTEST_TEXT_COMMAND_START);
   strcat (text, string);
   strcat (text, DISPLAY_TEXT_COMMAND_MIDDLE);

   sprintf(coordinates, "%d %d", x, y);

   strcat (text, coordinates);
   strcat (text, DISPLAY_TEXT_COMMAND_END);

   EnqueueFontColorAndText(NUM_DISPLAY_TEXT_ITEM_IDS, font, color, text);

   /* wait until buffers are processed/output */
   while (gDFDisplyDoesGraphicDisplayHaveWorkToDo() == 1)
   {
      wait_for_20ms();
      if (gDFDisplyProcessDisplayRequests() == 0)
      {
         break;
      }
      KICK_THE_DOG;
   }
}

/*============================================================================*/
/*
 * Global:        gDFDisplyPrintTextFlashDelete
 */

void gDFDisplyPrintTextFlashDelete (void)
{
   int success;

   success = EnqueueGraphicRequest(DELETE_FLASHING_DFTEST_TEXT_COMMAND);

   if (success == 1)
   {
      /* wait until buffers are processed/output */
      while (gDFDisplyDoesGraphicDisplayHaveWorkToDo() == 1)
      {
         wait_for_20ms();
         if (gDFDisplyProcessDisplayRequests() == 0)
         {
            break;
         }
         KICK_THE_DOG;
      }
   }
}
#endif   // DFTEST


/*============================================================================*/
/*
 * Global:        gDFDisplyPrintTextItem
 */

void gDFDisplyPrintTextItem(DISPLAY_TEXT_ITEM_IDS id, char *string, U16 set)
{
   int success = 1;
   int enqueue_text = 1;

   char text[LIMITED_DISPLAY_CMD_LEN];

   switch (id)
   {
      case SW_VERSION_DISPLAY_ITEM_ID:

         strcpy (text, DISPLAY_TEXT_COMMAND_START);
         strcat (text, string);
         strcat (text, DISPLAY_TEXT_COMMAND_MIDDLE);
         strcat (text, TextItems[id].location);
         strcat (text, DISPLAY_TEXT_COMMAND_END);
         break;

      case RF_CYCLE_LABEL_DISPLAY_ITEM_ID:   /* intentional fall-through */
      case CYCLES_LABEL_DISPLAY_ITEM_ID:     /* intentional fall-through */
      case RF_TOTAL_LABEL_DISPLAY_ITEM_ID:   /* intentional fall-through */
      case DISTAL_TC_LABEL_DISPLAY_ITEM_ID:  /* intentional fall-through */
      case PROXIMAL_TC_LABEL_DISPLAY_ITEM_ID:/* intentional fall-through */
      case POWER_LABEL_DISPLAY_ITEM_ID:      /* intentional fall-through */
      case RESET_BTN_LABEL_DISPLAY_ITEM_ID:  /* intentional fall-through */
      case CYCLE_BTN_LABEL_DISPLAY_ITEM_ID:  /* intentional fall-through */
      case POWER_BTN_LABEL_DISPLAY_ITEM_ID:  /* intentional fall-through */
      case TIMER_BTN_LABEL_DISPLAY_ITEM_ID:  /* intentional fall-through */

         strcpy (text, DISPLAY_TEXT_COMMAND_START);
         strcat (text, TextItems[id].text);
         strcat (text, DISPLAY_TEXT_COMMAND_MIDDLE);
         strcat (text, TextItems[id].location);
         strcat (text, DISPLAY_TEXT_COMMAND_END);
         break;

      case CONNECT_DEVICE_DISPLAY_ITEM_ID:

         /* Are they asking for it to be written (set) or cleared ? */

         if (set == 1)
         {
            /* Flash text */

            strcpy (text, DISPLAY_FLASHING_CONNECT_TEXT_COMMAND_START);
            strcat (text, TextItems[id].text);
            strcat (text, DISPLAY_TEXT_COMMAND_MIDDLE);
            strcat (text, TextItems[id].location);
            strcat (text, DISPLAY_TEXT_COMMAND_END);

            /* Remember that we put it on the screen (for below) */

            ConnectDeviceOnScreen = 1;
         }
         else
         {
            /* If it's on the screen, kill the flashing */

            if (ConnectDeviceOnScreen == 1)
            {
               ConnectDeviceOnScreen = 0;
               enqueue_text = 0;

               success =
               EnqueueGraphicRequest(DISABLE_FLASHING_CONNECT_TEXT_COMMAND);

               if (success == 1)
               {
                  success =
                  EnqueueGraphicRequest(DELETE_FLASHING_CONNECT_TEXT_COMMAND);
               }
               if (success == 1)
               {
                  /*
                   * The above doesn't always erase the Connect Device message.
                   * It does always stop the flashing.                                                         .
                   * Probably has something to do with the display wanting to                                                                                          .
                   * have time to get to the state mentioned in the tfd command                                                                                                                                                  .
                   * before it sees a tfx command even though their document                                                                                                                                                                                                            .
                   * says nothing to that affect.                                                                                                                                                                                                                                                                   .
                   *                                                                                                                                                                                                                                                                                                .
                   * We'll ensure it's erased the old-fashioned way.
                   */

                  strcpy (text, DISPLAY_TEXT_COMMAND_START);
                  strcat (text, TextItems[id].text);
                  strcat (text, DISPLAY_TEXT_COMMAND_MIDDLE);
                  strcat (text, TextItems[id].location);
                  strcat (text, DISPLAY_TEXT_COMMAND_END);

                  EnqueueFontColorAndText(id, TextItems[id].font,
                                          BLACK_ON_BLACK_COLOR, text);
               }
            }
            else
            {
               enqueue_text = 0;
            }
         }
         break;

      default:
         success = 0;
         break;
   }

   if (success == 1)
   {
      if (enqueue_text == 1)
      {
         EnqueueFontColorAndText(id, TextItems[id].font, TextItems[id].color,
                                 text);
      }
   }
   else
   {
      fault_routine(WARNING_SEVERITY, ERROR_DFDISPLY_TEXT_ITEM, "PrintTextItem()");
   }
}

/*============================================================================*/
/*
 * Global:        gDFDisplyProcessDisplayRequests
 */

int gDFDisplyProcessDisplayRequests()
{
   int success = 1;

   if (RequestInProgress == 1)
   {
      if (((__far char *)DISPLAY_RX2_DMA_BUF)[0] == '>')
      {
         /* Previous request was accepted by the display controller */

         RequestInProgress = 0;
         DMA7CONbits.CHEN = 0;
      }
      else if (((__far char *)DISPLAY_RX2_DMA_BUF)[0] == '!')
      {
         /* Previous request denied by the display controller */

         success = 0;
         RequestInProgress = 0;
         DMA7CONbits.CHEN = 0;

         return(success);
      }
      else
      {
         /* Display controller hasn't responded yet, Limit how long we wait */

         RequestWaitingCount++;
         if (RequestWaitingCount > MAX_DISPLAY_RESPONSE_WAIT_CNT)
         {
            RequestRetries++;
            if (RequestRetries <= MAX_REQUEST_RETRIES)
            {
                SendRequest();
            }
            else
            {
               success = 0;
               RequestInProgress = 0;
               return(success);
            }
         }
      }
   }

   if (RequestInProgress == 0)
   {
      if (QueueEntryCount > 0)
      {
         /* Dequeue request */

         success = DequeueGraphicRequest(Request);

         /* Send request to Display */

         if (success == 1)
         {
            RequestRetries = 0;
            SendRequest();
         }
      }
   }

   return(success);
}

/*============================================================================*/
/*
 * Global:        gDFDisplySetProgrammableButtons
 */

void gDFDisplySetProgrammableButtons(DISPLAY_TEXT_ITEM_IDS btn_label_id)
{
   int success = 1;
   char text[LIMITED_DISPLAY_CMD_LEN];
   DISPLAY_GRAPHIC_ITEM_IDS up_btn_id;
   DISPLAY_GRAPHIC_ITEM_IDS down_btn_id;

   switch (btn_label_id)
   {
      case POWER_BTN_LABEL_DISPLAY_ITEM_ID:
         up_btn_id   = POWER_UP_BTN_DISPLAY_ITEM_ID;
         down_btn_id = POWER_DOWN_BTN_DISPLAY_ITEM_ID;
         break;
      case TIMER_BTN_LABEL_DISPLAY_ITEM_ID:
         up_btn_id   = TIMER_UP_BTN_DISPLAY_ITEM_ID;
         down_btn_id = TIMER_DOWN_BTN_DISPLAY_ITEM_ID;
         break;
      default:
         success = 0;
         break;
   }

   /* Erase old label and write new one */

   if (success == 1)
   {
      EraseTextItem(btn_label_id, OldUpDownBtnsLabelText);

      strcpy (OldUpDownBtnsLabelText, TextItems[btn_label_id].text);

      strcpy (text, DISPLAY_TEXT_COMMAND_START);
      strcat (text, OldUpDownBtnsLabelText);
      strcat (text, DISPLAY_TEXT_COMMAND_MIDDLE);
      strcat (text, TextItems[btn_label_id].location);
      strcat (text, DISPLAY_TEXT_COMMAND_END);

      EnqueueFontColorAndText(btn_label_id,
                              TextItems[btn_label_id].font,
                              TextItems[btn_label_id].color,
                              text);
   }

   /* Draw the UP button */

   if (success == 1)
   {
      strcpy (text, DISPLAY_BITMAP_COMMAND_START);
      strcat (text, GraphicItems[up_btn_id].image_index);
      strcat (text, DISPLAY_BITMAP_COMMAND_MIDDLE);
      strcat (text, GraphicItems[up_btn_id].location);
      strcat (text, DISPLAY_BITMAP_COMMAND_END);

      success = EnqueueGraphicRequest(text);
   }

   /* Draw the DOWN button */

   if (success == 1)
   {
      strcpy (text, DISPLAY_BITMAP_COMMAND_START);
      strcat (text, GraphicItems[down_btn_id].image_index);
      strcat (text, DISPLAY_BITMAP_COMMAND_MIDDLE);
      strcat (text, GraphicItems[down_btn_id].location);
      strcat (text, DISPLAY_BITMAP_COMMAND_END);

      success = EnqueueGraphicRequest(text);
   }

   if (success == 0)
   {
      fault_routine(WARNING_SEVERITY, ERROR_DFDISPLY_BTNS, "ProgrammableBtns()");
   }
}

/*============================================================================*/
/*
 * Static:        SendRequest
 *
 * Description:   Output the graphic display request and setup for receiving
 *                a response.
 *
 * Parameters:    None
 *
 * Returns:       None
 *
 * Side-effects:  None
 */

static void SendRequest()
{
   int request_len;

   request_len = strlen(Request);

   /* Turn off the TX DMA channel while we're configuring */

   DMA6CONbits.CHEN = 0;

   /* Turn off the RX DMA channel while we're configuring */

   DMA7CONbits.CHEN = 0;

   /*
    * Zero the first byte in the RX response area - just so we know we really
    * got a response (versus the previous contents).
    */

   ((__far char *)DISPLAY_RX2_DMA_BUF)[0] = 0;

   /* Move the request to the TX DMA buffer */

   memmove((void*) DISPLAY_TX2_DMA_BUF, (const void*) Request,
           (size_t) request_len);

   /* Tell the TX DMA channel where the TX buffer starts (auto-increments) */

   DMA6STA = DISPLAY_TX2_DMA_BUF - DMARAM;

   /* Tell it how much to send (Tell it one less than actual byte count) */

   DMA6CNT = request_len - 1;

   /* Enable the TX DMA channel now */

   DMA6CONbits.CHEN = 1;
   DMA6REQbits.FORCE = 1;

   /* Setup to wait for a response */

   RequestInProgress = 1;
   RequestWaitingCount = 0;

   /* Tell the RX DMA channel where the RX buffer starts (auto-increments) */

   DMA7STA = DISPLAY_RX2_DMA_BUF - DMARAM;

   /*
    * We're expecting a single character response and a carriage return
    * (but remember the count always need to be one less)
    */

   DMA7CNT = 1;
   DMA7CONbits.CHEN = 1;
}

