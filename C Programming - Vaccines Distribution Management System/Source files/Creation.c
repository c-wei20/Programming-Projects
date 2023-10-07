#include "main.h"
#include "inputValidation.h"

struct Vaccine {
	char name[12], code[3], country[7];
	int dos;
	float cover, quantity;
} VC;

void creation() {

	int check, valid, charcheck = 0;
	char opt, str[100];
	FILE *fp;

	printf("\n\t*** Inventory Creation ***\n\n");

	do {
		getchar();
		do {
			printf("Enter vaccine name: "); 
			gets(VC.name);  /*read vaccine name*/
			charValidation(VC.name, &charcheck);  /* check user input exist space? */
		} while (charcheck == 1);
		do {
			printf("Enter vaccine code: ");
			gets(VC.code);  /*read vaccine code*/
			charValidation(VC.code, &charcheck);
		} while (charcheck == 1);
		do {
			printf("Enter the producing country: ");
			gets(VC.country);  /*read producing country*/
			charValidation(VC.code, &charcheck);
		} while (charcheck == 1);
		printf("Enter the number of dosage required: ");
		valid = scanf("%d", &VC.dos);  /*read dosage requiredy*/
		intValidation(&valid, &VC.dos);  /* check user input data type */
		printf("Enter population covered percentage: ");
		valid = scanf("%f", &VC.cover);  /*read covered percentage*/
		floatValidation(&valid, &VC.cover);
		printf("Enter initial quantity of vaccine (integer): ");
		valid = scanf("%f", &VC.quantity);  /*read initial quantity*/
		floatValidation(&valid, &VC.quantity);
		VC.quantity = VC.quantity / 1000000; /*concert the quantity to million form*/

		printf("\n--- Confirm the following record ---\n\n");  /*condirm info with user*/
		printf("Vacine Name\t\t: %s\nVacine Code\t\t: %s\nProducting Country\t: %s\n", VC.name, VC.code, VC.country);
		printf("Dosage Required\t\t: %d\nPopulation Coverd\t: %.1f %%\nInitial Quantity\t: %.2f million\n", VC.dos, VC.cover, VC.quantity);
		printf("\nConfirm to save the record? 'Y' for YES, 'N' for NO: ");
		scanf(" %c", &opt);
		while (opt != 'Y' && opt != 'y' && opt != 'N' && opt != 'n') {  /*check if user enter irrelevent option*/
			printf(">>> Invalid input!\n");
			printf("Confirm to save the record? 'Y' for YES, 'N' for NO: ");
			scanf(" %c", &opt);
		}

		if (opt == 'Y' || opt == 'y') {
			fp = fopen("vaccine.txt", "a+");
			if (fp == NULL)
				printf("Unable to open the file.");
			else {
				check = 0;
				while(fgets(str, 100, fp) != NULL) {  /*check exist same record*/
					if (strstr(str, VC.code) != NULL || strstr(str, VC.name) != NULL)
					{
						printf(">>> Record exist, unable to save the record\n");
						check = 1;
					}
				}
				if (check != 1) {
					fprintf(fp, "%s %s %s %d %f %f\n", VC.name, VC.code, VC.country, VC.dos, VC.cover, VC.quantity);  /*write info to file*/
					printf(">>> Record successfully save!\n");
				}				
			}
			fclose(fp);
		}
		else
			printf(">>> Record cancel to save\n");
		
		printf("Continue to create new vaccine inventory record? 'Y' to continue, 'N' to terminate: ");
		scanf(" %c", &opt);
		while (opt != 'Y' && opt != 'y' && opt != 'N' && opt != 'n') {
			printf(">>> Invalid input!\n");
			printf("Continue to create new vaccine inventory record? 'Y' to continue, 'N' to terminate: ");
			scanf(" %c", &opt);
		}
		printf("\n");
	} while (opt != 'N' && opt != 'n');
	
}