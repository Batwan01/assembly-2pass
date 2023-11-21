#include "dctab.h"
#include "oprand.h"

int asm_space(Dctab* dp) {
	int len;
	if (dp->type == DC_RESV) {
		len = str2int(OPerand) * dp->unit;
		OBJC[0] = 0;
		return(len);
	}
	if (dp->unit == 1 && OPerand[0] == '\"')
		len = cal_dc_oprnd_string(OPerand, OBJC);
	else
		len = cal_dc_oprnd(OPerand, dp->unit, OBJC);
	
	return(len);
}