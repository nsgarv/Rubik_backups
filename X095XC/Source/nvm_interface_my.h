#ifndef _NVM_INTERFACE_H
#define _NVM_INTERFACE_H

#ifndef _HTC_H_
/* <htc.h> must not be included after us, as older versions (<=9.60)
   will try to stomp on our macros, but _we_ need to stomp on _them_
   so we include it before their definitions.
   If it has already been included, its include-guard will
   stop this block being processed.
*/
//#include <htc.h>
#endif

#if defined(__DSPICC__) && \
	(_HTC_VER_MAJOR_ == 9 && _HTC_VER_MINOR_ <= 60) && \
	(!defined(_HTC_EDITION_) || _HTC_EDITION_ == 1)

#if _HTC_VER_MAJOR_ == 9 && _HTC_VER_MINOR_ <= 60
/* undo the 9.60 macros */
#undef __EEPROM_ROW
#undef __EEADJ
#undef eeprom_read_word
#undef eeprom_read_block
#undef eeprom_write_word
#undef eeprom_write_block
#undef eeprom_read_row
#undef eeprom_write_row
#undef eeprom_erase_word_only
#undef eeprom_write_word_only
#undef eeprom_erase_block_only
#undef eeprom_write_block_only
#undef eeprom_erase_row_only
#undef eeprom_write_row_only

#undef __FLASH_ROW
#undef flash_read_word
#undef flash_read_block
#undef flash_write_block
#undef flash_read_row
#undef flash_write_row
#undef flash_erase_row_only
#undef flash_write_row_only

#undef __CONFIG_OSC
#undef __CONFIG_WDT
#undef __CONFIG_BORPOR
#undef __CONFIG_GS
#undef config_read
#undef config_write

#undef device_id_read
#undef __DEVID_MASK
#undef __DEVID_SHIFT
#undef __DEVID_VARIANT_MASK
#undef __DEVID_VARIANT_SHIFT
#undef __DEVID
#undef __DEVID_VARIANT

#undef device_rev_read
#undef __DEVID_PROC_MASK
#undef __DEVID_PROC_SHIFT
#undef __DEVID_REV_MASK
#undef __DEVID_REV_SHIFT
#undef __DEVID_DOT_MASK
#undef __DEVID_DOT_SHIFT
#undef __DEVID_PROC
#undef __DEVID_REV
#undef __DEVID_DOT

#undef __UNITID_MAX
#undef unit_id_read

#undef __UNITID_BASE
#undef unit_id_read

#endif


#if defined __EEPROM_SIZE__ && !defined _EEPROMSIZE
  #if __EEPROM_SIZE__ % 1024 != 0
//#warning EEPROM size not on 1k boundary - tweaked
    #define _EEPROMSIZE (((__EEPROM_SIZE__+1023)/1024)*1024)
  #else
    #define _EEPROMSIZE __EEPROM_SIZE__
  #endif
#endif

#if defined(__dsPIC30F__)

 #define _EEPROM_ROW	16 /* 16-bit words */

 #define _FLASH_ROW	32 /* 24-bit words */
 #define _FLASH_WRITE_SIZE	96
 #define _FLASH_ERASE_SIZE	96
 #define _FLASH_PANEL	128 /* rows */

 #if defined(__dsPIC30F2011__) || \
     defined(__dsPIC30F2012__) || \
     defined(__dsPIC30F2013__) || \
     defined(__dsPIC30F3013__)
  #define _ERRATA_EEPROM_ODDWORD_HIBIT_CORRUPT
 #endif

#elif defined(__dsPIC33F__) || \
      defined(__PIC24FJ__) || defined(__PIC24HJ__)

 #define _FLASH_ROW	64 /* 24-bit words */
 #define _FLASH_PAGE	8 /* rows */
 #define _FLASH_WRITE_WORD
 #define _FLASH_WRITE_SIZE	192
 #define _FLASH_ERASE_SIZE	1536

#else
 #warning Unknown chip sub-family
#endif


/* For the curious:
   These functions have names beginning with __ to keep them out
   of the User's namespace, and in the Implementor's namespace
   so that the User is free to define functions with these names
   provided this header is not #included; once this header comes
   into play, the macros bounce calls through to these non-standard
   functions.  The macros are defined parameterless so that the
   addresses of the functions can also be taken if needed.

   The formal parameters are likewise kept in the Implementor's
   namespace so that the User can have any pathological macro
   definitions at all (provided _our_ namespace isn't infringed)
   and the parameters won't cause problems.
 */


/* Flash Program Memory */
/* each function takes a byte-address within the entire Flash space;
   the least-significant bit is always ignored.
   if an unimplemented address is specified, an Address Trap exception will be triggered.
 */
#define flash_read_word		__flash_read_word
#define flash_read_block	__flash_read_block
#define flash_read_low_word	__flash_read_low_word
#define flash_read_low_block	__flash_read_low_block

/* return the contents of the (24 bit) word at __adr. */
unsigned long
flash_read_word(unsigned long __adr);

/* store into __block[] the __n words starting from __adr. */
void
flash_read_block(unsigned long __adr,
                 unsigned long __block[], unsigned __n);

/* return the contents of the (16 bit) word at __adr. */
unsigned
flash_read_low_word(unsigned long __adr);

/* store into __block[] the __n words starting from __adr. */
void
flash_read_low_block(unsigned long __adr,
                     unsigned __block[], unsigned __n);


#if _FLASH_WRITE_SIZE != 0
#if _FLASH_PAGE == 0
/* erase _FLASH_ROW words starting at __adr rounded down to nearest _FLASH_ROW. */
#define flash_erase_row_only	__flash_erase_row_only
#define flash_write_row_only	__flash_write_row_only_30
void
flash_erase_row_only(unsigned long __adr);

#else /* _FLASH_PAGE != 0 */
/* erase _FLASH_PAGE words starting at __adr rounded down to nearest _FLASH_PAGE. */
#define flash_erase_page_only	__flash_erase_page_only
#define flash_write_row_only	__flash_write_row_only_33
void
flash_erase_page_only(unsigned long __adr);

#endif /* _FLASH_PAGE == 0 */


#if defined(_FLASH_WRITE_WORD)
/* write __val to Flash at __adr,
   assuming that that Flash word has already been erased. */
#define flash_write_word_only	__flash_write_word_only
void
flash_write_word_only(unsigned long __adr, unsigned long __val);

#endif

/* specific routine already selected based on the writing mechanism */

/* write _FLASH_ROW words from __row to Flash starting at
   __adr rounded down to nearest _FLASH_ROW,
   assuming that that Flash row has already been erased. */
void
flash_write_row_only(unsigned long __adr,
                     unsigned long __row[/*_FLASH_ROW*/]);


#if _FLASH_PAGE == 0
/* erase _FLASH_ROW words starting at __adr rounded down to nearest _FLASH_ROW
   and then write _FLASH_ROW words from __row. */
#define flash_write_row	__flash_write_row
void
(flash_write_row)(unsigned long __adr,
                  unsigned long __row[/*_FLASH_ROW*/]);
#define __flash_write_row(address,row) do{\
	unsigned long __a=(address);\
	flash_erase_row_only(__a);\
	flash_write_row_only(__a,(row));\
}while(0)

#else /* _FLASH_PAGE != 0 */
/* erase _FLASH_ROW * _FLASH_PAGE words starting at __adr rounded down to nearest _FLASH_ROW * _FLASH_PAGE
   and then write _FLASH_ROW * _FLASH_PAGE words from __page. */
#define flash_write_page	__flash_write_page
void
(flash_write_page)(unsigned long __adr,
                   unsigned long __page[/*_FLASH_ROW * _FLASH_PAGE*/]);

#define __flash_write_page(address,page) do{\
	unsigned long __a=(address);\
	unsigned long* __p=(page);\
	unsigned __i;\
	flash_erase_page_only(__a);\
	for (__i = 0; __i < _FLASH_PAGE; __i++) {\
		flash_write_row_only(__a, __p);\
		__p += _FLASH_ROW;\
		__a += _FLASH_ROW*2;\
	}\
}while(0)

#endif /* _FLASH_PAGE == 0 */
#endif /* _FLASH_WRITE_SIZE != 0 */


/* Data EEPROM */
/* each function takes a byte-address within the EEPROM space;
   the least-significant bit is always ignored.
   if an unimplemented address is specified, an Address Trap exception will be triggered.
 */

/* no point in prototyping functions that won't be implemented */
#if _EEPROMSIZE != 0
#define eeprom_read_word	__eeprom_read_word
#define eeprom_read_block	__eeprom_read_block
#define eeprom_read_word_nowait	__eeprom_read_word_nowait
#define eeprom_read_block_nowait	__eeprom_read_block_nowait

#define eeprom_erase_word_only	__eeprom_erase_word_only
#define eeprom_erase_row_only	__eeprom_erase_row_only
#define eeprom_erase_block_only	__eeprom_erase_block_only
#define eeprom_write_word_only	__eeprom_write_word_only
#define eeprom_write_row_only	__eeprom_write_row_only
#define eeprom_write_block_only	__eeprom_write_block_only
#define eeprom_erase_word_only_nowait	__eeprom_erase_word_only_nowait
#define eeprom_erase_row_only_nowait	__eeprom_erase_row_only_nowait
#define eeprom_write_word_only_nowait	__eeprom_write_word_only_nowait
#define eeprom_write_row_only_nowait	__eeprom_write_row_only_nowait

#define eeprom_write_word	__eeprom_write_word
#define eeprom_write_row	__eeprom_write_row
#define eeprom_write_block	__eeprom_write_block

/* select the specific routine based on the size of the EEPROM */
#if _EEPROMSIZE == 1024
#define __eeprom_read_word	__eeprom_read_word_1k
#define __eeprom_read_block	__eeprom_read_block_1k
#define __eeprom_read_word_nowait	__eeprom_read_word_nowait_1k
#define __eeprom_read_block_nowait	__eeprom_read_block_nowait_1k

#define __eeprom_erase_word_only	__eeprom_erase_word_only_1k
#define __eeprom_erase_row_only		__eeprom_erase_row_only_1k
#define __eeprom_erase_block_only	__eeprom_erase_block_only_1k
#define __eeprom_write_word_only	__eeprom_write_word_only_1k
#define __eeprom_write_row_only		__eeprom_write_row_only_1k
#define __eeprom_write_block_only	__eeprom_write_block_only_1k
#define __eeprom_erase_word_only_nowait	__eeprom_erase_word_only_nowait_1k
#define __eeprom_erase_row_only_nowait	__eeprom_erase_row_only_nowait_1k
#define __eeprom_write_word_only_nowait	__eeprom_write_word_only_nowait_1k
#define __eeprom_write_row_only_nowait	__eeprom_write_row_only_nowait_1k

#define __eeprom_write_word	__eeprom_write_word_1k
#define __eeprom_write_word_1k(address,value) do{\
	unsigned __a=(address);\
	eeprom_erase_word_only(__a);\
	eeprom_write_word_only(__a,(value));\
}while(0)
#define __eeprom_write_row	__eeprom_write_row_1k
#define __eeprom_write_row_1k(address,row) do{\
	unsigned __a=(address);\
	eeprom_erase_row_only(__a);\
	eeprom_write_row_only(__a,(row));\
}while(0)
#define __eeprom_write_block	__eeprom_write_block_1k
#define __eeprom_write_block_1k(address,block,n) do{\
	unsigned __a=(address),__n=(n);\
	eeprom_erase_block_only(__a,__n);\
	eeprom_write_block_only(__a,(block),__n);\
}while(0)

#elif _EEPROMSIZE == 2048
#define __eeprom_read_word	__eeprom_read_word_2k
#define __eeprom_read_block	__eeprom_read_block_2k
#define __eeprom_read_word_nowait	__eeprom_read_word_nowait_2k
#define __eeprom_read_block_nowait	__eeprom_read_block_nowait_2k

#define __eeprom_erase_word_only	__eeprom_erase_word_only_2k
#define __eeprom_erase_row_only		__eeprom_erase_row_only_2k
#define __eeprom_erase_block_only	__eeprom_erase_block_only_2k
#define __eeprom_write_word_only	__eeprom_write_word_only_2k
#define __eeprom_write_row_only		__eeprom_write_row_only_2k
#define __eeprom_write_block_only	__eeprom_write_block_only_2k
#define __eeprom_erase_word_only_nowait	__eeprom_erase_word_only_nowait_2k
#define __eeprom_erase_row_only_nowait	__eeprom_erase_row_only_nowait_2k
#define __eeprom_write_word_only_nowait	__eeprom_write_word_only_nowait_2k
#define __eeprom_write_row_only_nowait	__eeprom_write_row_only_nowait_2k

#define __eeprom_write_word	__eeprom_write_word_2k
#define __eeprom_write_word_2k(address,value) do{\
	unsigned __a=(address);\
	eeprom_erase_word_only(__a);\
	eeprom_write_word_only(__a,(value));\
}while(0)
#define __eeprom_write_row	__eeprom_write_row_2k
#define __eeprom_write_row_2k(address,row) do{\
	unsigned __a=(address);\
	eeprom_erase_row_only(__a);\
	eeprom_write_row_only(__a,(row));\
}while(0)
#define __eeprom_write_block	__eeprom_write_block_2k
#define __eeprom_write_block_2k(address,block,n) do{\
	unsigned __a=(address),__n=(n);\
	eeprom_erase_block_only(__a,__n);\
	eeprom_write_block_only(__a,(block),__n);\
}while(0)

#elif _EEPROMSIZE == 4096
#define __eeprom_read_word	__eeprom_read_word_4k
#define __eeprom_read_block	__eeprom_read_block_4k
#define __eeprom_read_word_nowait	__eeprom_read_word_nowait_4k
#define __eeprom_read_block_nowait	__eeprom_read_block_nowait_4k

#define __eeprom_erase_word_only	__eeprom_erase_word_only_4k
#define __eeprom_erase_row_only		__eeprom_erase_row_only_4k
#define __eeprom_erase_block_only	__eeprom_erase_block_only_4k
#define __eeprom_write_word_only	__eeprom_write_word_only_4k
#define __eeprom_write_row_only		__eeprom_write_row_only_4k
#define __eeprom_write_block_only	__eeprom_write_block_only_4k
#define __eeprom_erase_word_only_nowait	__eeprom_erase_word_only_nowait_4k
#define __eeprom_erase_row_only_nowait	__eeprom_erase_row_only_nowait_4k
#define __eeprom_write_word_only_nowait	__eeprom_write_word_only_nowait_4k
#define __eeprom_write_row_only_nowait	__eeprom_write_row_only_nowait_4k

#define __eeprom_write_word	__eeprom_write_word_4k
#define __eeprom_write_word_4k(address,value) do{\
	unsigned __a=(address);\
	eeprom_erase_word_only(__a);\
	eeprom_write_word_only(__a,(value));\
}while(0)
#define __eeprom_write_row	__eeprom_write_row_4k
#define __eeprom_write_row_4k(address,row) do{\
	unsigned __a=(address);\
	eeprom_erase_row_only(__a);\
	eeprom_write_row_only(__a,(row));\
}while(0)
#define __eeprom_write_block	__eeprom_write_block_4k
#define __eeprom_write_block_4k(address,block,n) do{\
	unsigned __a=(address),__n=(n);\
	eeprom_erase_block_only(__a,__n);\
	eeprom_write_block_only(__a,(block),__n);\
}while(0)

#else
//#error Unsupported EEPROM size
#endif


/* wait for any pending write to complete, then
   return the contents of the (16 bit) word at __adr. */
unsigned
eeprom_read_word(unsigned __adr);
/* don't wait, but if a write is pending, EEPROM will be corrupted
   caller must verify WR==0 before call */
unsigned
eeprom_read_word_nowait(unsigned __adr);

/* wait for any pending write to complete, then
   store into __block[] the __n words starting from __adr. */
void
eeprom_read_block(unsigned __adr,
                  unsigned __block[], unsigned __n);
/* don't wait, but if a write is pending, EEPROM will be corrupted
   caller must verify WR==0 before call */
void
eeprom_read_block_nowait(unsigned __adr,
                         unsigned __block[], unsigned __n);


/* wait for any pending write to complete, then
   erase __adr. */
void
eeprom_erase_word_only(unsigned __adr);
/* don't wait, but if a write is pending, EEPROM will be corrupted
   caller must verify WR==0 before call */
void
eeprom_erase_word_only_nowait(unsigned __adr);

/* wait for any pending write to complete, then
   erase _EEPROM_ROW words starting at __adr rounded down to nearest _EEPROM_ROW. */
void
eeprom_erase_row_only(unsigned __adr);
/* don't wait, but if a write is pending, EEPROM will be corrupted
   caller must verify WR==0 before call */
void
eeprom_erase_row_only_nowait(unsigned __adr);

/* wait for any pending write to complete, then
   erase __n words starting at __adr. */
void
eeprom_erase_block_only(unsigned __adr, unsigned __n);


/* wait for any pending write to complete, then
   write __val to EEPROM at __adr,
   assuming that that EEPROM word has already been erased. */
void
eeprom_write_word_only(unsigned __adr, unsigned __val);
/* don't wait, but if a write is pending, EEPROM will be corrupted
   caller must verify WR==0 before call */
void
eeprom_write_word_only_nowait(unsigned __adr, unsigned __val);

/* wait for any pending write to complete, then
   write _EEPROM_ROW words from __row to EEPROM starting at
   __adr rounded down to nearest _EEPROM_ROW,
   assuming that that EEPROM row has already been erased. */
void
eeprom_write_row_only(unsigned __adr,
                      unsigned __row[/*_EEPROM_ROW*/]);
/* don't wait, but if a write is pending, EEPROM will be corrupted
   caller must verify WR==0 before call */
void
eeprom_write_row_only_nowait(unsigned __adr,
                             unsigned __row[/*_EEPROM_ROW*/]);

/* wait for any pending write to complete, then
   write __n words from __block to EEPROM starting at __adr,
   assuming that that EEPROM block has already been erased. */
void
eeprom_write_block_only(unsigned __adr,
                        unsigned __block[], unsigned __n);


/* erase __adr and then write __val to __adr. */
void
(eeprom_write_word)(unsigned __adr, unsigned __val);

/* erase _EEPROM_ROW words starting at __adr rounded down to nearest _EEPROM_ROW
   and then write _EEPROM_ROW words from __row. */
void
(eeprom_write_row)(unsigned __adr,
                   unsigned __row[/*_EEPROM_ROW*/]);

/* erase __n words starting at __adr
   and then write __n words from __block. */
void
(eeprom_write_block)(unsigned __adr,
                     unsigned __block[], unsigned __n);

#endif /* _EEPROMSIZE != 0 */


#define config_read_word	__config_read_word
#define config_read_block	__config_read_block

/* Device Configuration registers */
/* each function takes a register number.
   if an unimplemented register is specified, an Address Trap exception will be triggered.
 */
#define _CONFIG_OSC	0	/* Oscillator Configuration */
#define _CONFIG_WDT	1	/* Watchdog Timer Configuration */
#define _CONFIG_BORPOR	2	/* BOR and POR Configuration */
#define _CONFIG_GS	5	/* General Code Segment Configuration */
/* dsPIC33 chips have an extra 3 16-bit config registers */

/* return the contents of the (16 bit) word at __reg. */
unsigned
config_read_word(unsigned __reg);

/* store into __block[] the __n words starting from __reg. */
void
config_read_block(unsigned __reg,
                  unsigned __block[], unsigned __n);


#define devid_read	__devid_read

/* Device ID set at manufacture */
struct devid_s {
#if defined(__DSPICC__) && \
	(_HTC_VER_MAJOR_ == 9 && _HTC_VER_MINOR_ <= 60)
	/* compiler is dsPICC 9.60 or older */
	unsigned device:10;
	unsigned variant:6;
	unsigned process:4;
	unsigned revision:6;
	unsigned subrev:6;
#else
//#error Newer compiler version - Check validity of bitfield ordering
#endif
}
devid_read(void);


/* Datasheets refer to factory-programmable "unit ID" locations
   but the .DEV files call them "user ID", and the chips allow
   run-time programming */
/* User ID locations */
/* each function takes a register number which should be from 0 to 31 */
/* only on dsPIC30 & 33 so far */
#if defined(__dsPIC30F__) ||  defined(__dsPIC33F__)

#define unitid_read_word	__unitid_read_word
#define unitid_read_block	__unitid_read_block

/* return the contents of the (24 bit) word at __adr. */
unsigned long
unitid_read_word(unsigned __reg);

/* store into __block[] the __n words starting from __reg. */
void
unitid_read_block(unsigned long __reg,
                  unsigned long __block[], unsigned __n);
#endif

#if 0
void config_write(unsigned char reg_no, unsigned dataword);

/* user ID regs ... same as Unit ID? */
void idloc_write(unsigned char reg_no,unsigned char data);
#endif


#else
//#error Newer compiler version - Check validity of argument-passing assumptions
#endif

#endif /* _NVM_INTERFACE_H */
