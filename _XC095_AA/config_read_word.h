#include "nvm_internal.h"

/* actual function renamed (into Implementor's namespace) by macro */
unsigned
config_read_word(unsigned reg)
{
/* FIXME: (compiler feature desired)
   need to be able to say to the compiler
   "give me a register, and then use it in this asm()".
   Meanwhile, know that W1:W0 is first arg,
   and return value goes in W1:W0. */

    /*WREG0 = (reg*2) | CONFIG_OFFSET_BASE; */
    asm("SL W0, W0");
#if CONFIG_OFFSET_BASE > 1023
    asm("MOV #0" ___mkstr(CONFIG_OFFSET_BASE_) ", W1");
    asm("IOR W1, W0, W0");
#elif CONFIG_OFFSET_BASE > 0
    asm("IOR #0" ___mkstr(CONFIG_OFFSET_BASE_) ", W0");
#endif

    WAIT();
    TBLPAG = CONFIG_PAGE;

    asm("TBLRDL [W0],W0");
    /*return WREG0; */
#warning: Expect "implicit return at end of non-void function"
}
