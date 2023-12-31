#include <string.h>
#include <stdio.h>
#include "optab.h"
#include "oprand.h"


int asm_mnemonic(Optab* op) {
    char* obp = OBJC;
    unsigned int obc; //4byte
    obc = (op->opcode << 24);
    if (op->n_operand) {
        if (!OPerand) fprintf(stderr, "%s --> Operand is not defined ...\n", LBUF), 
            (10);
        if (!strcmp(op->mnemonic, "DMPR")) obc |= cal_nm_dmpr(OPerand);
        else obc |= cal_nm_oprnd(OPerand);
    }

    OBJC[0] = 4;
    OBJC[1] = obc >> 24;
    OBJC[2] = obc >> 16;
    OBJC[3] = obc >> 8;
    OBJC[4] = obc >> 0;
    return(OBJC[0]);
}