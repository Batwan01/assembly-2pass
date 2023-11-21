#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "symtab.h"
#include "oprand.h"

int cnv_one_term(char* term)    // ex) cal_one_term("BUF")
{                                                               // ex) cal_one_term("10h")
    int val;                                        // ex) cal_one_term("AB")
    if (isdigit(term[0]) || (term[strlen(term)] - 1) == 'h') { //const
        if ((val = str2int(term)) == INV_VAL)
            fprintf(stderr, "%s ->> Operand number '%s' is not valid...\n", LBUF, term), exit(11);
    }
    else if (term[0] == '\'') {
        if ((val = asc2int(term)) == INV_VAL)
            fprintf(stderr, "%s --> Operand number '%s' is not valid...\n", LBUF, term), exit(11);
    }
    else if (isdigit(term[0])) {
        val = atoi(term);
    }
    else {
        if ((val = see_SYMTAB(term)) == INV_VAL)
            fprintf(stderr, "%s --> Operand symbol '%s' is not defined...\n", LBUF, term), exit(12);
    }
    return(val);
}