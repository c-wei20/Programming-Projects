#include "main.h"
#include <string.h>

struct Vaccine {
	char name[12], code[3], country[7];
	int dos;
	float cover, quantity;
} VC[4];

void updateVaccine(char* code, char *status, float* quantity) 
{
	int i,j;
	FILE *fp;

	fp = fopen("vaccine.txt", "r");
	if (fp == NULL)
		printf("Unable to open the file");
	else {
		i = 0;
		while (!feof(fp))
		{
			fscanf(fp, "%s %s %s %d %f %f\n", VC[i].name, VC[i].code, VC[i].country, &VC[i].dos, &VC[i].cover, &VC[i].quantity); /*read record from file*/
			if (strstr(VC[i].code, code) != NULL){  /*find the record same with the chosen code */
				if (strstr(status, "Received") != NULL) {
					VC[i].quantity = VC[i].quantity + *quantity;  /*add quantity if received */
				}
				else {
					VC[i].quantity = VC[i].quantity - *quantity; /*subtract quantity if destributed*/
				}
			}
			i++;
		}
	}
	fclose(fp);

	fp = fopen("vaccine.txt", "w");
	if (fp == NULL)
		printf("Unable to open the fie");
	else {
		printf(">>> Update vaccine record\n");
		for (j = 0; j < 5 ; j++) {
			fprintf(fp, "%s %s %s %d %f %f\n", VC[j].name, VC[j].code, VC[j].country, VC[j].dos, VC[j].cover, VC[j].quantity); /*updated the quantity and save in file*/
		}
	}
	fclose(fp);
}