#define MAX_DNUM 8 // ex) cal_dc_oprnd("4h,'AB',VAR-1-VAR2",4,OBJC)

extern int LOC, LDaddr, GOaddr;                 //main.c
extern char LBUF[], * LNO, * LABEL, * OPcode, * OPerand;
extern unsigned char OBJC[];
extern char* null_LNO;
extern char* null_LBL;
extern char* null_OPR;

extern int cal_nm_dmpr(char* oprnd); //cal_mnmo.c
extern int cal_nm_oprnd(char* oprnd);

extern int cal_dc_oprnd(char* oprnd, int unit, unsigned char obj[]); //cal_drctv.c
extern int cal_dc_oprnd_string(char* oprnd, unsigned char obj[]);

extern int str2int(char* sp); //str2int.c
extern int dec2int(char* sp_dec);
extern int hex2int(char* sp_hex);

extern int asc2int(char* ap); //asc2int.c

extern int cnv_one_term(char* term); //cal_term.c

extern int cal_one_expr(char* expr); //cal_expr.c

extern void Pass_1(char* sfile);
extern void Pass_2(char* sfile); //2pass

