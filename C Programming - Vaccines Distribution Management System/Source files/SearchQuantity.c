#include "main.h"
#include <string.h>

struct Vaccine {
	char name[12], code[3], country[7];
	int dos;
	float cover, quantity;
} VC;

void searchQuantity() {
	int flag;
	char code[3], opt;
	FILE* fp;

	printf("\n\t*** Search Vaccine Quantity ****\n\n");
	
	do {
		printf("Select a vaccine code to search:\n\t[1] PF\n\t[2] SV\n\t[3] AZ\n\t[4] SP\n\t[5] CS\n");
		printf("Enter you option: ");
		scanf(" %c", &opt);
		while (opt != '1' && opt != '2' && opt != '3' && opt != '4' && opt != '5') {
			printf(">>> Invalid input!\nPlease enter the number again: ");
			scanf(" %c", &opt); /*read user selected number of code*/
		}
		
		switch (opt)
		{
		case ('1'):
			strcpy(code, "PF"); /*give the code by number reletively*/
			break;
		case ('2'):
			strcpy(code, "SV");
			break;
		case ('3'):
			strcpy(code, "AZ");
			break;
		case ('4'):
			strcpy(code, "SP");
			break;
		default:
			strcpy(code, "CS");
			break;
		}

		flag = 0;
		fp = fopen("vaccine.txt", "r");
		if (fp == NULL)
			printf("Unable to open the file");
		while (!feof(fp)) 
		{
			fscanf(fp, "%s %s %s %d %f %f\n", VC.name, VC.code, VC.country, &VC.dos, &VC.cover, &VC.quantity);  /*read record from file */
			if (strstr(VC.code, code) != NULL) {  /*find the record with some code*/
				printf("\n   ------------------------------------------------------------------\n");
				printf("     Vaccine Code\tName\t\tAvailable Quantity (million)\n");
				printf("   ------------------------------------------------------------------\n");
				printf("\t%s\t\t%-12s\t%f\n\n", VC.code,VC.name, VC.quantity); /*display the available quantity*/
				flag = 1;
			}
		}
		fclose(fp);

		if (flag != 1)
			printf("\n>>> Vaccine code not found\n\n"); /*can not finf the same code*/
		printf("Continue to search another vaccine available quantity? 'Y' to continue, 'N' back to main menu: ");
		scanf(" %c", &opt);
		while (opt != 'Y' && opt != 'y' && opt != 'N' && opt != 'n') {
			printf(">>> Invalid input!\nPlease enter again: ");
			scanf(" %c", &opt);
		}
	} while (opt != 'N' && opt != 'n');

}

