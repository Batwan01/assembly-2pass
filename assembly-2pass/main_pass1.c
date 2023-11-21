#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "optab.h"
#include "dctab.h"
#include "symtab.h"
#include "asm.h"
#include "util.h"
#include "oprand.h"

int LOC = 0, LDaddr, GOaddr;
char LBUF[128], * LNO, * LABEL, * OPcode, * OPerand;
unsigned char OBJC[MAX_DNUM * 4 + 1];
char* null_LNO = "  ";
char* null_LBL = "      ";
char* null_OPR = "      ";

void TwoPassAssemble(char* sfile) {
    Pass_1(sfile);
    Pass_2(sfile);
}

void Pass_1(char* sfile) {
    FILE* fp;
    Optab* op;
    Dctab* dp;
    int len;

    if (!(fp = fopen(sfile, "r")))
        fprintf(stderr, "File '%s' not found....\n", sfile), exit(1);
    read_line(fp);


    if (!OPcode || strcmp(OPcode, "START"))
        fprintf(stderr, "\n%se --> Opcode is not 'START'...\n", LBUF), exit(2);
    if (OPerand && (LOC = str2int(OPerand)) < 0)
        fprintf(stderr, "\n%s --> Start address is invalid...\n", LBUF), exit(3);

    if (!LABEL) LABEL = "ASMBLY";
    ins_SYMTAB(LOC, LABEL); //program name


    LDaddr = GOaddr = LOC;

    while (read_line(fp) > 0) {
        if (!strcmp(OPcode, "END")) break;

        if (!strcmp(OPcode, "FILE")) continue;

        if (LABEL) {
            if (strlen(LABEL) > MAX_SYM)
                fprintf(stderr, "\n%s --> Symbol '%s' is duplicated", LBUF, LABEL), exit(4);

            if (!ins_SYMTAB(LOC, LABEL))
                fprintf(stderr, "\n%s --> Symbol '%s' is duplicated...\n", LBUF, LABEL), exit(4);
        }
        if (op = see_OPTAB(OPcode))
            len = len_mnemonic(op);
        else if (dp = see_DCTAB(OPcode))
            len = len_space(dp);
        else fprintf(stderr, "\n%s --> Opcode '%s' is not valid...\n", LBUF, OPcode), exit(4);

        LOC += len;
    }
    if (!OPcode)
        fprintf(stderr, " --> 'END' opcode is not defined...\n"), exit(5);
    if (OPerand) GOaddr = cal_nm_oprnd(OPerand);
    fclose(fp);
}

/*int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <assembly_file>\n", argv[0]);
        return 1;
    }

    char* source_file = argv[1];
    OnePassAssemble(argv[1]);

    return 0;
}*/

int main() {
    char* n = "s_102.txt";
    TwoPassAssemble(n);

    return 0;
}