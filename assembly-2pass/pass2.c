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


void Pass_2(char* sfile) {
	FILE* fp;
	Optab* op;
	Dctab* dp;
	int len;

	fp = fopen(sfile, "r");
	put_list_head();
	read_line(fp);
	if (!LABEL) LABEL = "ASMBLY";
	LOC = LDaddr;
	put_list();
	while (read_line(fp) > 0) {
		if (!strcmp(OPcode, "END"))
			break;
		if (!strcmp(OPcode, "FILE"))
			continue;
		if (op = see_OPTAB(OPcode))
			len = asm_mnemonic(op);
		else {
			dp = see_DCTAB(OPcode);
			len = asm_space(dp);
		}
		if (!OPerand)
			OPerand = null_OPR;
		if (!LNO)
			LNO = null_LNO;
		if (!LABEL)
			LABEL = null_LBL;
		put_list();
		LOC += len;
	}

	if (!OPerand)
		OPerand = null_OPR;
	LABEL = null_LBL;
	put_list();
	fclose(fp);
}