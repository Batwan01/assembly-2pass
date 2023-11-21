#include <stdio.h>
#include <string.h>
#include "oprand.h"

int cal_dc_oprnd(char* oprnd, int unit, unsigned char obj[])
{                                                                                       // ex_dc_oprnd("100, VAR1, BUF-4", 2, OBJC)
    char buf[128], * exp;
    char* op = (char*)(obj + 1);
    short* sp = (short*)(obj + 1);
    int* ip = (int*)(obj + 1);
    int v, len = 0;

    strcpy(buf, oprnd);
    exp = strtok(buf, ",");
    do {
        v = cal_one_expr(exp);
        
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

    for (i = 1; oprnd[i] != '\"'; i++)
        obj[i] = oprnd[i];

    obj[i] = '\0', obj[0] = i;
    return(i);
}