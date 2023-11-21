#include <stdio.h>
#include <string.h>
#include "oprand.h"
#define OP_XBIT 0x800000

int cal_nm_dmpr(char* oprnd) { //operand of "DMPR" mnemonic
    // ex) cal_nm_dmpr("x")
    int opr;
    if (!strcmp(oprnd, "PC")) opr = 0x000000;
    else if (!strcmp(oprnd, "U")) opr = 0x000001;
    else if (!strcmp(oprnd, "X")) opr = 0x000002;
    else if (!strcmp(oprnd, "A")) opr = 0x000003;
    else fprintf(stderr, "%s --> Operand is not valid...\n", LBUF), exit(10);
    return(opr);
}

int cal_nm_oprnd(char* oprnd) //operand of mnemonic code
{                                                         // ex) cal_nm_oprnd("BUF")
    char buf[128], * xp;      // ex) cal_nm_oprnd("VAR3+4")
    int opr;                  // ex) cal_nm_oprnd("BUF[X]")
    strcpy(buf, oprnd);               // keep unchanged original operand string
    if (xp = strchr(buf, '[')) { // '[X]' ?
        if (strcmp(xp, "[X]"))
            fprintf(stderr, "%s ->> Operand is not valid ...\n", LBUF), exit(10);
        *xp = 0;
    }
    opr = cal_one_expr(buf); // CON +/-const, SYM+/-const
    opr &= 0x007fffff;               // for minus value
    if (xp) opr |= OP_XBIT;
    return(opr);
}