#include <string.h>
#include <stdio.h>
#include "symtab.h"
#include "oprand.h"
#define MAX_FNAME 8
#define MAX_FTAB 4

typedef struct ftab {
	char fname[MAX_FNAME + 1];
	int port;
	char in_out;
} Ftab;

void ins_FATB(), see_FTAB(), put_obj_ftab();
int FCNT;
Ftab FTAB[MAX_FTAB];

void ins_FTAB() {
	char* pn, *io, *fn;
	int port;

	if (!(pn = strtok(OPerand, ",")) || !(io = strtok(NULL, ",")) || !(fn = strtok(NULL, " \t\n\r")))
		fprintf(stderr, "\n%s --> FILE operand is not valid ...\n", LBUF), exit(31);

	see_FTAP(fn);

	if ((port = str2int(pn)) == INV_VAL || port < 0)
		fprintf(stderr, "\n%s --> FILE operand is not valid ...\n", LBUF), exit(31);

	if (strcmp(io, "I") && strcmp(io, "0"))
		fprintf(stderr, "\n%s --> Port type('I' or '0') is not defined ...\n", LBUF), exit(31);

	strcpy(FTAB[FCNT].fname, fn);
	FTAB[FCNT].port = port;
	FTAB[FCNT++].in_out = *io;
}

void see_FTAB(char *fname) {
	int i;
	for (i = 0; i < FCNT; i++)
		if (!strcmp(FTAB[i].fname, fname))
			fprintf(stderr, "File nmae '%s' is duplicated...\n", fname);
}

void put_obj_ftab() {
	int i;
	for (i = 0; i < FCNT; i++)
		fprintf(Ofp, "F:%s:%c:%.6X\n", FTAB[i].fname, FTAB[i].in_out, FTAB[i].port);
}