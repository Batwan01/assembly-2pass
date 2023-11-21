all: Makefile
Makefile: asc2int.o asm_mnmo.o asm_space.o cal_drctv.o cal_expr.o cal_mnmo.o cal_term.o dctab.o main.o optab.o put_list.o rdline.o str2int.o symtab.o
                gcc -o $@ asc2int.o asm_mnmo.o asm_space.o cal_drctv.o cal_expr.o cal_mnmo.o cal_term.o dctab.o main.o optab.o put_list.o rdline.o str2int.o symtab.o

asc2int.o: symtab.h oprand.h asc2int.c
                gcc -c asc2int.c

asm_mnmo.o: optab.h oprand.h asm_mnmo.c
                gcc -c asm_mnmo.c

asm_space.o: dctab.h oprand.h symtab.h asm_space.c
                gcc -c asm_space.c

cal_drctv.o: oprand.h cal_drctv.c
                gcc -c cal_drctv.c

cal_expr.o: oprand.h cal_expr.c
                gcc -c cal_expr.c

cal_mnmo.o: oprand.h cal_mnmo.c
                gcc -c cal_mnmo.c

cal_term.o: symtab.h oprand.h cal_term.c
                gcc -c cal_term.c

dctab.o: dctab.h dctab.c
                gcc -c dctab.c

main.o: optab.h dctab.h asm.h util.h oprand.h main.c
                gcc -c main.c

optab.o: optab.h optab.c
                gcc -c optab.c

put_list.o: oprand.h util.h put_list.c
                gcc -c put_list.c

rdline.o: optab.h oprand.h dctab.h rdline.c
                gcc -c rdline.c

str2int.o: symtab.h util.h oprand.h str2int.c
                gcc -c str2int.c

symtab.o: symtab.h symtab.c
                gcc -c symtab.c

clean:
                rm -rf Makefile *.o