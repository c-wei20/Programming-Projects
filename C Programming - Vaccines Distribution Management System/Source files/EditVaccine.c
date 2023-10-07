#include "main.h"
#include "inputValidation.h"
#include <string.h>

struct Vaccine {
	char name[12], code[3], country[7];
	int dos;
	float cover, quantity;
} VC[4];

void editVaccine()
{
	int i, j, edit, valid, charcheck = 0;
	char opt, MIN, MAX;
	FILE* fp;

	do {
		printf("\n\t*** Edit Vaccine Inventory Record ***\n\n");

		fp = fopen("vaccine.txt", "r");
		i = 0;
		if (fp == NULL)
			printf("Unable to open the file");
		while (!feof(fp)) {
			fscanf(fp, "%s %s %s %d %f %f\n", VC[i].name, VC[i].code, VC[i].country, &VC[i].dos, &VC[i].cover, &VC[i].quantity); /* read the vaccine detail from file */
			i++;
		}
		fclose(fp);

		printf(">>> Current vaccine record: \n");
		printf("\t-----------------------------------------------------------------------------------------------------------------------------------\n");
		printf("\t  Vacine Name\t\tVacine Code\tProducting Country\tDosage Required\t\tPopulation Coverd\tQuantity (million)\n");
		printf("\t-----------------------------------------------------------------------------------------------------------------------------------\n");
		for (j = 0; j < i; j++) {
			printf("  [%d]\t  %-12s\t\t%s\t\t%-7s\t\t\t%d\t\t\t%.1f\t\t\t%f\n", j + 1, VC[j].name, VC[j].code, VC[j].country, VC[j].dos, VC[j].cover, VC[j].quantity); /*display all vaccine record in file with option*/
		}
		printf("  [0]\t  Cancel edit\n");

		MIN = '0'; /*option min number*/
		MAX = i + '0'; /*option max number*/
		printf("\nEnter the number of record to edit: "); 
		scanf(" %c", &opt); /*read edit option*/
		while ((int)opt < (int)MIN || (int)opt >(int)MAX) {
			printf(">>> Invalid input!\nPlease emter again: ");
			scanf(" %c", &opt);
		}

		if (opt != '0') {
			edit = opt - '1';
			printf("\nSelect the edit section:\n\t[1] Vaccine Name\n\t[2] Vaccine Code\n\t[3] Producting Country\n\t[4] Dosage Required\n\t[5] Population Coverd\n\t[6] Quantity\n"); 
			printf("Enter the number: ");
			scanf(" %c", &opt); /*read edit detial option*/
			MIN = '1'; /*option min number*/
			MAX = '6' ;/*option max number*/
			while ((int)opt < (int)MIN || (int)opt >(int)MAX) {
				printf(">>> Invalid input!\nPlease emter again: ");
				scanf(" %c", &opt);
			}

			getchar();
			printf("\n");
			switch (opt) {
			case '1':
				printf("Current name: %s\n", VC[edit].name);
				do {
					printf("Enter new name: ");  /*print current detial*/
					gets(VC[edit].name); /*read new detail*/
					charValidation(VC[edit].name, &charcheck);  /*check input exist space? */
				} while (charcheck == 1);
				break;
			case '2':
				do {
					printf("Current code: %s\n", VC[edit].code);
					printf("Enter new code: ");
					gets(VC[edit].code);
					charValidation(VC[edit].code, &charcheck);
				} while (charcheck == 1);
				break;
			case '3':
				do{
					printf("Current country: %s\n", VC[edit].country);
					printf("Enter new country: ");
					gets(VC[edit].country);
					charValidation(VC[edit].country, &charcheck);
				} while (charcheck == 1);
				break;
			case '4':
				printf("Current dosage: %d\n", VC[edit].dos);
				printf("Enter new dosage: ");
				valid = scanf("%d", &VC[edit].dos);
				intValidation(&valid, &VC[edit].dos); /* check input data type */
				break;
			case '5':
				printf("Current population covered: %.1f\n", VC[edit].cover);
				printf("Enter new population covered: ");
				valid = scanf("%f", &VC[edit].cover);
				floatValidation(&valid, &VC[edit].cover);
				break;
			default:
				printf(">>>\a WARNING\a\n>>> \aPlease check before edit\a\n");
				printf("Current quantity: %f\n", VC[edit].quantity);
				printf("Enter new quantity (integer): ");
				valid = scanf("%f", &VC[edit].quantity);
				floatValidation(&valid, &VC[edit].quantity);
				VC[edit].quantity = VC[edit].quantity / 1000000; /* devide quantity to million form */
				break;
			}

			printf("\n--- Confirm the following edited record ---\n\n"); /*confirm info*/
			printf("Vacine Name\t\t: %s\nVacine Code\t\t: %s\nProducting Country\t: %s\n", VC[edit].name, VC[edit].code, VC[edit].country);
			printf("Dosage Required\t\t: %d\nPopulation Coverd\t: %.1f %%\nInitial Quantity\t: %.2f million\n", VC[edit].dos, VC[edit].cover, VC[edit].quantity);
			printf("\nConfirm to save the edited record? 'Y' for YES, 'N' for NO: ");
			scanf(" %c", &opt);
			while (opt != 'Y' && opt != 'y' && opt != 'N' && opt != 'n') {
				printf(">>> Invalid input!\n");
				printf("Confirm to save the edited record? 'Y' for YES, 'N' for NO: ");
				scanf(" %c", &opt);
			}

			if (opt == 'Y' || opt == 'y') {
				fp = fopen("vaccine.txt", "w");
				if (fp == NULL)
					printf("Unable to open the fie");
				else {
					printf(">>> Update vaccine record successful\n");
					for (j = 0; j < i; j++) {
						fprintf(fp, "%s %s %s %d %f %f\n", VC[j].name, VC[j].code, VC[j].country, VC[j].dos, VC[j].cover, VC[j].quantity); /*save in file*/
					}
				}
				fclose(fp);
			}
			else
				printf(">>> Record cancel to save\n");
		}
		else
			printf(">>> Cancel to edit record\n");

		printf("Continue to edit vaccine inventory record? 'Y' to continue, 'N' to terminate: ");
		scanf(" %c", &opt);
		while (opt != 'Y' && opt != 'y' && opt != 'N' && opt != 'n') {
			printf(">>> Invalid input!\n");
			printf("Continue to edit vaccine inventory record? 'Y' to continue, 'N' to terminate: ");
			scanf(" %c", &opt);
		}
		system("CLS");
	}while (opt != 'N' && opt != 'n');

}