#include <string.h>
#include "symtab.h"

#define RND_OPR 0x7fffff

int SYMCNT = 1;
Symtab SYMTAB[MAX_SYM] = { "RND", RND_OPR, }; //symbol for random number

int ins_SYMTAB(int value, char* sym) // 1 : success,  0 : failure
{                                                                        // ex) ins_SUMTAB(0x1308, "VAR3")
    if (see_SYMTAB(sym) != INV_VAL)
        return 0;
    strcpy(SYMTAB[SYMCNT].symbol, sym);
    SYMTAB[SYMCNT].value = value;
    SYMCNT++;
    return 1;
}

int see_SYMTAB(char* sym)
{
    int i;
    for (i = 0; i < SYMCNT; i++) {
        if (!strcmp(SYMTAB[i].symbol, sym))
            return(SYMTAB[i].value);
    }
    return INV_VAL;
}