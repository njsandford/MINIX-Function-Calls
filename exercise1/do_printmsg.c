#include <stdio.h>
#include "pm.h"         // provides global variables such as m_in

int do_printmsg() {
    int i = m_in.m1_i1; /* m_in is a global variable set to PM's
                         * incoming message, 
                         * So m_in.m1_i1 is the integer parameter set in our
                         * test program above.
                         */
    
    printf("System call do_printmsg called with value %d\n", i);
    return 0;
}