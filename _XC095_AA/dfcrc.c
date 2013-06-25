/*
 *	DFcrc.c
 *
 * CRC routines for DFine Compact Controller.
 *
 *
 * Author: Robin Bek
 *
 * Revision History:
 **********************************************************************************
 * 11/21/07  Version 1.00 Initial Release. Nils Johansson                         *
 * 12/10/07  Version 1.10 Rev B PCB, New pump, Changed function. Nils Johansson   *
 * 01/08/08  Version 1.12 Changed function. Minor bug fixes. Nils Johansson       *
 * 01/21/08  Version 1.13 Changed function. Minor bug fixes. Nils Johansson       *
 * 02/22/08  Version 1.14 Changed function. Orange button changed. Nils Johansson *
 * 03/18/08  Version 1.15 Changed function. NTC support added. Nils Johansson     *
 * 03/24/08  Version 1.16 Fixed Hall Sensor Bug. Nils Johansson                   *
 * 04/25/08  Version 1.17 Temperature setp adjusts with pressure. Nils Johansson  *
 * 05/13/08  Version 1.18 Many changes, see FRS. Nils Johansson                   *
 * 05/28/08  Version 1.19 Minor changes, see FRS. Nils Johansson                  *
 * 06/13/08  Version 1.20 Reorganized display and sound. Nils Johansson           *
 * 08/26/08  Version 1.21 Removed temperature control and check. Nils Johansson   *
 * 10/07/08  Version 1.22 Simplified menus. Nils Johansson                        *
 * 10/31/08  Version 2.00 Different cement algorithm. Rocker switch. Nils Johansson*
 * 11/11/08  Version 2.01 Manual temperature setting. Nils Johansson			  *
 * 12/02/08  Version 2.02 Misc minor changes in algorithm. See FRS. Nils Johansson*
 * 12/19/08  Version 2.03 Removed rocker. Added second timer. Nils Johansson      *
 * 04/07/09  Version 3.00 Added ablation. Nils Johansson                          *
 * 04/28/09  Version 3.01 Ablation power moderated by impedance. Nils Johansson   *
 * 10/01/10  Version x.08 Added new Menu and new icons Robin Bek                  *
 **********************************************************************************
 */

#include <stdarg.h>
// htc.h is a HI-TECH file and for this project calls "pic24hj256gp610.h" which was added below.
//#include <htc.h>
//#include "pic24hj256gp610.h"
//#include "dspic_my.h"
//#include "nvm_interface_my.h"
//#include "htc_my.h"
#include <xc.h>
#include "dfine.h"
#include <string.h>
#include <stdio.h>
#include "dfdisply.h"

const U16 pre_calculated_crc = ROM_CRC_VALUE;	/* update ROM_CRC_VALUE (the pre-calculated/expected CRC) */
                                                /*  in DFINE.H                                            */

/* CRC table */
static const unsigned int crc_table[] = {
0x0000, 0x1189, 0x2312, 0x329b, 0x4624, 0x57ad, 0x6536, 0x74bf,
0x8c48, 0x9dc1, 0xaf5a, 0xbed3, 0xca6c, 0xdbe5, 0xe97e, 0xf8f7,
0x1081, 0x0108, 0x3393, 0x221a, 0x56a5, 0x472c, 0x75b7, 0x643e,
0x9cc9, 0x8d40, 0xbfdb, 0xae52, 0xdaed, 0xcb64, 0xf9ff, 0xe876,
0x2102, 0x308b, 0x0210, 0x1399, 0x6726, 0x76af, 0x4434, 0x55bd,
0xad4a, 0xbcc3, 0x8e58, 0x9fd1, 0xeb6e, 0xfae7, 0xc87c, 0xd9f5,
0x3183, 0x200a, 0x1291, 0x0318, 0x77a7, 0x662e, 0x54b5, 0x453c,
0xbdcb, 0xac42, 0x9ed9, 0x8f50, 0xfbef, 0xea66, 0xd8fd, 0xc974,
0x4204, 0x538d, 0x6116, 0x709f, 0x0420, 0x15a9, 0x2732, 0x36bb,
0xce4c, 0xdfc5, 0xed5e, 0xfcd7, 0x8868, 0x99e1, 0xab7a, 0xbaf3,
0x5285, 0x430c, 0x7197, 0x601e, 0x14a1, 0x0528, 0x37b3, 0x263a,
0xdecd, 0xcf44, 0xfddf, 0xec56, 0x98e9, 0x8960, 0xbbfb, 0xaa72,
0x6306, 0x728f, 0x4014, 0x519d, 0x2522, 0x34ab, 0x0630, 0x17b9,
0xef4e, 0xfec7, 0xcc5c, 0xddd5, 0xa96a, 0xb8e3, 0x8a78, 0x9bf1,
0x7387, 0x620e, 0x5095, 0x411c, 0x35a3, 0x242a, 0x16b1, 0x0738,
0xffcf, 0xee46, 0xdcdd, 0xcd54, 0xb9eb, 0xa862, 0x9af9, 0x8b70,
0x8408, 0x9581, 0xa71a, 0xb693, 0xc22c, 0xd3a5, 0xe13e, 0xf0b7,
0x0840, 0x19c9, 0x2b52, 0x3adb, 0x4e64, 0x5fed, 0x6d76, 0x7cff,
0x9489, 0x8500, 0xb79b, 0xa612, 0xd2ad, 0xc324, 0xf1bf, 0xe036,
0x18c1, 0x0948, 0x3bd3, 0x2a5a, 0x5ee5, 0x4f6c, 0x7df7, 0x6c7e,
0xa50a, 0xb483, 0x8618, 0x9791, 0xe32e, 0xf2a7, 0xc03c, 0xd1b5,
0x2942, 0x38cb, 0x0a50, 0x1bd9, 0x6f66, 0x7eef, 0x4c74, 0x5dfd,
0xb58b, 0xa402, 0x9699, 0x8710, 0xf3af, 0xe226, 0xd0bd, 0xc134,
0x39c3, 0x284a, 0x1ad1, 0x0b58, 0x7fe7, 0x6e6e, 0x5cf5, 0x4d7c,
0xc60c, 0xd785, 0xe51e, 0xf497, 0x8028, 0x91a1, 0xa33a, 0xb2b3,
0x4a44, 0x5bcd, 0x6956, 0x78df, 0x0c60, 0x1de9, 0x2f72, 0x3efb,
0xd68d, 0xc704, 0xf59f, 0xe416, 0x90a9, 0x8120, 0xb3bb, 0xa232,
0x5ac5, 0x4b4c, 0x79d7, 0x685e, 0x1ce1, 0x0d68, 0x3ff3, 0x2e7a,
0xe70e, 0xf687, 0xc41c, 0xd595, 0xa12a, 0xb0a3, 0x8238, 0x93b1,
0x6b46, 0x7acf, 0x4854, 0x59dd, 0x2d62, 0x3ceb, 0x0e70, 0x1ff9,
0xf78f, 0xe606, 0xd49d, 0xc514, 0xb1ab, 0xa022, 0x92b9, 0x8330,
0x7bc7, 0x6a4e, 0x58d5, 0x495c, 0x3de3, 0x2c6a, 0x1ef1, 0x0f78
};

#define CRC_INIT		0xffff /* this is an arbitrary seed value for the CRC */
#define CRC_END			0xf0b8

/*
* The value 0x8000 is used in the macro below to reverse map data space back to
* program space and thus the FLASH address.  See the PIC24HJXXXGPX06/X08/X10
* data sheet DS70175F Table 3-33, page 49 (Bit 15 is always set to 1 when mapped
* from FLASH space to data space).  PSVPAG register must be unchanged from its
* reset value of 0.
*
*/
#define CODE_ADDRESS_TO_FLASH_INDEX(code_address) (((U32)(code_address))-0x08000)

/*****************************************************************************
* NAME:  crcgen()
*
* DESCRIPTION:  Generates CRC at the end of a buffer in memory.
*
* PARMETERS:
*   bp             - pointer to buffer
*   bytes          - number of bytes in buffer
*
* NOTES: 1 Calculates the CRC for the whole buffer and writes after buffer.
*          Buffer needs to have room for two more bytes.
*        2 This function not used.
*
* RETURN VALUE:
*    NONE
*
*****************************************************************************/
/*
void crcgen(__far unsigned char *bp, unsigned bytes)
{
	unsigned crc = CRC_INIT;

	while(bytes--)
		crc = (crc >> 8) ^ crc_table[(crc ^ *bp++) & 0xff];

	*bp++ = ~crc;
	*bp++ = ~(crc >> 8);
}
*/
/*****************************************************************************
* NAME:  crcchk()
*
* DESCRIPTION:  Checks CRC of a buffer in memory.
*
* PARMETERS:
*   bp             - pointer to buffer
*   bytes          - number of bytes in buffer
*
* NOTES: Calculates the CRC for the whole buffer.
*
* RETURN VALUE:
*    1 if good data CRC, 0 if bad CRC
*
*****************************************************************************/
#if (CHECK_CRC)
int crcchk(__far unsigned char *bp, unsigned bytes)
{
	unsigned crc = CRC_INIT;

	while(bytes--)
		crc = (crc >> 8) ^ crc_table[(crc ^ *bp++) & 0xff];

	return (crc == CRC_END);
}
#endif

/*****************************************************************************
* NAME:  crc_partial_flash()
*
* DESCRIPTION:  Checks CRC for part of the FLASH memory in PIC24HJ256GP610
*
* PARMETERS:  NONE
*
* NOTES: Calculates the CRC for three bytes of every program address.
*
* RETURN VALUE:
*    calculated CRC
*
*****************************************************************************/
#if (CHECK_CRC)
U16 crc_partial_flash(U16 crc, U32 next_address, U32 last_address_p2) // calculate CRC for part of the FLASH memory
{
	union {
		U32 word;
		U8 bytes[4];
	} flash;

	while (next_address < last_address_p2) {
		flash.word = flash_read_word(next_address);
		crc = (crc >> 8) ^ crc_table[(crc ^ flash.bytes[0]) & 0xff]; // LS byte first
		crc = (crc >> 8) ^ crc_table[(crc ^ flash.bytes[1]) & 0xff];
		crc = (crc >> 8) ^ crc_table[(crc ^ flash.bytes[2]) & 0xff];
   		KICK_THE_DOG;

        next_address += 2;
	}

	return (crc); // return calculated crc
}
#endif

/*****************************************************************************
* NAME:  crc_flash()
*
* DESCRIPTION:  Checks CRC for the whole FLASH memory in PIC24HJ256GP610
*               (less embedded CRC value)
*
*               144 ms for PIC24HJ256GP610 - this timing is stale.
*
* PARMETERS:  NONE
*
* NOTES: Calculates the CRC for three bytes of every program address.
*
* RETURN VALUE:
*    1 if good data CRC, 0 if bad CRC
*
*****************************************************************************/
#if (CHECK_CRC)
U16 crc_flash(void)
{
   U16 crc_match = 0;      /* assume bad CRC until its tested and found good */
	U16 crc = CRC_INIT;     /* the intermediate crc is initialized to a known */
                           /* constant.                                      */
   U16 expected_crc_value; /* the CRC embedded at compile time is read into  */
                           /*  this expected_crc_value variable.             */
   U32 crc_start;          /* crc_partial_flash() calculates a partial crc   */
                           /*  from the flash index pointed to by crc_start  */
   U32 crc_end_p2;			/*  all the way to the WORD before crc_end_p2     */

   char text[11];          /* "CRC = XXXX\0" */

   /* read pre-calculated CRC from flash code space */

   expected_crc_value =
      flash_read_word(CODE_ADDRESS_TO_FLASH_INDEX(&pre_calculated_crc));

   KICK_THE_DOG;

   /* Calculate CRC on all words up to where linker placed CRC */

   crc_start  = 0;
   crc_end_p2 = CODE_ADDRESS_TO_FLASH_INDEX(&pre_calculated_crc) & 0xFFFFFFFEL;
   crc = crc_partial_flash( crc, crc_start, crc_end_p2 );

   /*
    * Continue calculating CRC on all words after CRC to size of program.
    * So crc_start is ROUNDED up the the next WORD offset by add 1 and MOD-ing
    * by 2.  MOD is actually carried out by masking with 0xFFFFFFFEL.
    */

   crc_start  = (CODE_ADDRESS_TO_FLASH_INDEX(&pre_calculated_crc) + 1 +
                 sizeof(pre_calculated_crc)) & 0xFFFFFFFEL;

   /*
	 * the last 0xC00 of the flashsize determined by previous SW engineer is
    * not accessable through the flash space reading routine, thus we must
    * stop flash calculation 0xC00 bytes before end of the estimated flash
    * space.  All flash offsets are post incremented by sizeof(WORD).  Thus,
    * the loop end tests are the final WORD offset plus 2.
    */

   crc_end_p2 = FLASHSIZE - 0xc00 + 2;

   crc = crc_partial_flash( crc, crc_start, crc_end_p2 );

   KICK_THE_DOG;

   if (crc == expected_crc_value)
   {
 	   // flag CRC as GOOD

      crc_match = 1;
   }
   else
   {
      // display the calculated bad CRC at bottom right corner of the display

      sprintf(text, "CRC = %04X", (U16) crc);
      gDFDisplyPrintText(text, TWENTY_PT_FONT, WHITE_ON_BLUE_COLOR, 620, 445);
   }

   return (crc_match);
}
#endif

