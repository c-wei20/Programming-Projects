#include "main.h"
#include <string.h>

struct Vaccine {
	char name[12], code[3], country[7];
	int dos;
	float cover, quantity;
} VC;

int checkQuantity(char* code, char* status, float *quantity)
{
	int check = 0;
	FILE* fp;
	if (*status == '2') {
		fp = fopen("vaccine.txt", "r");
		if (fp == NULL)
			printf("Unable to open the file");
		while (!feof(fp))
		{
			fscanf(fp, "%s %s %s %d %f %f\n", VC.name, VC.code, VC.country, &VC.dos, &VC.cover, &VC.quantity); /*read record from file*/
			if (strstr(VC.code, code) != NULL) { /*find the record same with the selected code*/
				if (*quantity > VC.quantity) /*check distributed quantity available or not */
					check = 1;
			}
		}
		fclose(fp);
	}

	return check;
}