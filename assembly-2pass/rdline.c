#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "optab.h"
#include "oprand.h"
#include "dctab.h"

int read_line(FILE* fp) {
    static char buf[128];
    char* cp;
    LNO = NULL, LABEL = NULL, OPcode = NULL, OPerand = NULL;
    do {
        if (!fgets(buf, sizeof(buf), fp)) return -1;
        strcpy(LBUF, buf); LBUF[strlen(LBUF) - 1] = 0;
        if (cp = strstr(buf, "//")) *cp = 0;
    } while (!(cp = strtok(buf, " \t\n\r")));

    if (isdigit(*cp)) {
        LNO = cp;
        cp = strtok(NULL, " \t\n\r");
    }

    if (strcmp(cp, "END") && strcmp(cp, "START") && !see_OPTAB(cp) && !see_DCTAB(cp)) {
        LABEL = cp;
        cp = strtok(NULL, " \t\n\r");
    }
    OPcode = cp;
    OPerand = strtok(NULL, " \t\n\r");
    return 1;
}