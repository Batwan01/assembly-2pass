#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dctab.h"
#include "oprand.h"
#include "symtab.h"

int asm_space(Dctab* dp) //return length of object code
{
    int len;
    if (!OPerand) fprintf(stderr, "%s --> Operand is not defined...\n", LBUF); exit(10);
    if (dp->type == DC_RESV) { // RD 100
        if ((!isdigit(OPerand[0]) && OPerand[strlen(OPerand) - 1] != 'h') || (len = str2int(OPerand)) == INV_VAL)
            fprintf(stderr, "%s --> Operand number '%s' is not valid...\n", LBUF, OPerand), exit(11);


        len *= dp->unit;
        OBJC[0] = 0;
        return(len);
    }
    if (dp->unit == 1 && OPerand[0] == '\"') // DB "EOT"
        len = cal_dc_oprnd_string(OPerand, OBJC);
    else                                     // DW 10+2, '2A', 30
        len = cal_dc_oprnd(OPerand, dp->unit, OBJC);
    return(len);
}