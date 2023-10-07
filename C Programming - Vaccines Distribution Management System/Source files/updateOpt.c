#define _CRT_SECURE_NO_WARNINGS
#include <string.h>

void updateOpt(char* code, char* status, char* Vcode, char* Vname, char* Vstatus) {

	switch (*code)
	{
	case ('1'):
		strcpy(Vcode, "PF"); /*give the code and vaccine name with the correspoding option*/
		strcpy(Vname, "Pfizer");
		break;
	case ('2'):
		strcpy(Vcode, "SV");
		strcpy(Vname, "Sinovac");
		break;
	case ('3'):
		strcpy(Vcode, "AZ");
		strcpy(Vname, "AstraZeneca");
		break;
	case ('4'):
		strcpy(Vcode, "SP");
		strcpy(Vname, "Sputnik_V");
		break;
	default:
		strcpy(Vcode, "CS");
		strcpy(Vname, "CanSinoBio");
		break;
	}

	switch (*status)
	{
	case('1'):
		strcpy(Vstatus, "Received");  /*give the status in string with the correspoding option*/
		break;
	default:
		strcpy(Vstatus, "Distributed");
		break;
	}
}
