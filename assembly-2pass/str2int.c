#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "symtab.h"
#include "util.h"
#include "oprand.h"

int str2int(char* sp)                           // ex) str2int("4")
{                                                                       // ex) str2int("10h")
    int l = strlen(sp);
    if (sp[l - 1] != 'h')
        return(dec2int(sp));
    else
        return(hex2int(sp));
}

int dec2int(char* sp_dec)                       // ex) str2int("4")
{
    int d, n = 0;
    for (n = 0; *sp_dec; sp_dec++) {
        if (isdigit(*sp_dec))
            d = *sp_dec - '0';
        else
            return INV_VAL;
        n = n * 10 + d;
    }
    return(n);
}

int hex2int(char* sp_hex)                       // ex) str2int("10h")
{
    int x, n;
    for (n = 0; *(sp_hex + 1); sp_hex++) { // last one is 'h'
        if (isdigit(*sp_hex))
            x = *sp_hex - '0';
        else if ('A' <= *sp_hex && *sp_hex <= 'F')
            x = *sp_hex - 'A' + 10;
        else return INV_VAL;
        n = (n << 4) + x;
    }
    return(n);
}