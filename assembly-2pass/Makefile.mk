all: Makefile
Makefile: asm_drctv.o pass2.o len_drvtv_num.o len_drvtv_str.o len_mnmo.o asc2int.o asm_mnmo.o cal_drctv.o cal_expr.o cal_mnmo.o cal_term.o dctab.o main_pass1.o optab.o put_list.o rdline.o str2int.o symtab.o len_drctv.o
                gcc -o $@ asm_drctv.o pass2.o len_drvtv_num.o len_drvtv_str.o len_mnmo.o asc2int.o asm_mnmo.o cal_drctv.o cal_expr.o cal_mnmo.o cal_term.o dctab.o main_pass1.o optab.o put_list.o rdline.o str2int.o symtab.o len_drctv.o

len_drctv.o: dctab.h oprand.h symtab.h asm.h len_drctv.c
                gcc -c len_drctv.c

len_mnmo.o: optab.h len_mnmo.c
                gcc -c len_mnmo.c

len_drvtv_str.o: oprand.h len_drvtv_str.c
                gcc -c len_drvtv_str.c

len_drvtv_num.o: oprand.h len_drvtv_num.c
                gcc -c len_drvtv_num.c

pass2.o: optab.h dctab.h asm.h util.h oprand.h symtab.h pass2.c
                gcc -c pass2.c

asm_drctv.o: dctab.h oprand.h asm_drctv.c
                gcc -c asm_drctv.c

asc2int.o: symtab.h oprand.h asc2int.c
                gcc -c asc2int.c

asm_mnmo.o: optab.h oprand.h asm_mnmo.c
                gcc -c asm_mnmo.c

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

main_pass1.o: optab.h dctab.h asm.h util.h oprand.h symtab.h main_pass1.c
                gcc -c main_pass1.c

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