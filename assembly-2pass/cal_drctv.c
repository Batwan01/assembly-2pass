#include <stdio.h>
#include <string.h>
#include "oprand.h"

int cal_dc_oprnd(char* oprnd, int unit, unsigned char obj[])
{                                                                                       // ex_dc_oprnd("100, VAR1, BUF-4", 2, OBJC)
    char buf[128], * exp;
    char* op = (char*)(obj + 1);
    short* sp = (short*)(obj + 1);
    int* ip = (int*)(obj + 1);
    int n = 0, v, len = 0;

    strcpy(buf, oprnd);
    exp = strtok(buf, ",");
    do {
        if (++n > MAX_DNUM)
            fprintf(stderr, "%s ->> OPerand '%s' is not valid...\n", LBUF, oprnd), exit(11);

        v = cal_one_expr(exp);
        (exp);
        switch (unit)
        {
        case 4: *op = v >> 24; op++, len++;
            *op = v >> 16; op++, len++;
        case 2: *op = v >> 8; op++; len++;
        case 1: *op = v; op++, len++;
        }
    } while (exp = strtok(NULL, ","));
    obj[0] = len;
    return (len);
}

int cal_dc_oprnd_string(char* oprnd, unsigned char obj[])
{                                                                                       // ex) cal_dc_oprnd_string("EOT", OBJC)
    int i;

    for (i = 1; oprnd[i] != '\'' && i <= MAX_DNUM; i++)
        obj[i] = oprnd[i];
    if (oprnd[i] != '\'' || !oprnd[i] || oprnd[i + 1])
        fprintf(stderr, "%s --> Operand '%s' is not valid...\n", LBUF, oprnd), exit(11);

    obj[i] = '\0'; obj[0] = i;
    return(i);
}