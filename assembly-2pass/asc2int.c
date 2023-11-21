#include <string.h>
#include "symtab.h"
#include "oprand.h"

int asc2int(char* ap)                   // ex) str2int("AB")
{
    int l = strlen(ap), v;
    if (ap[l - 1] != '\"')
        return(INV_VAL);
    for (v = 0; *(ap + 1) != '\"'; ap++)
        v = (v << 8) | *(ap + 1);
    return(v);
}