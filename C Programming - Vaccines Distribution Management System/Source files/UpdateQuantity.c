#include "main.h"
#include "updateFunction.h"
#include "inputValidation.h"
#include <string.h>

struct distribute {
	char code[3], name[12], status[12];
	float quantity;
	struct {
		int day, month, year;
	}date;
	char state[16], city[20];
}DIST;

void updateQuantity()
{
	int check, valid, charcheck = 0;
	char code, status, save, opt;
	FILE *fp;

	printf("\n\t*** Update Quantity ****\n\n");

	do {
		printf("Select the vaccine code: \n\t[1] PF\n\t[2] SV\n\t[3] AZ\n\t[4] SP\n\t[5] CS\n");
		printf("Enter the number: ");
		scanf(" %c", &code);  /*read user vaccine code option*/
		while (code != '1' && code != '2' && code != '3' && code != '4' && code != '5') {
			printf(">>> Invalid input!\nPlease enter the number again: ");
			scanf(" %c", &code);

		}
		printf("Select the status: \n\t[1] Received\n\t[2] Distributed\n");
		printf("Enter the number: ");
		scanf(" %c", &status); /*read receied or distributed*/
		while (status != '1' && status != '2') {
			printf(">>> Invalid input!\nPlease enter the number again: ");
			scanf(" %c", &status);
		}
		updateOpt(&code, &status, DIST.code, DIST.name, DIST.status);

		printf("Insert quantity (integer): ");
		valid = scanf("%f", &DIST.quantity); /*resd quantity*/
		floatValidation(&valid, &DIST.quantity); /*check inut in float*/
		DIST.quantity = DIST.quantity / 1000000; /*devide quantity to million form*/
		getchar();

		check = checkQuantity(DIST.code, &status, &DIST.quantity); /*check quantity enough? */

		if (check == 0) {
			do {
				printf("Date (DD-MM-YYYY): ");
				scanf("%d-%d-%d", &DIST.date.day, &DIST.date.month, &DIST.date.year); /*read date with int*/
				dateValidation(&DIST.date.day, &DIST.date.month, &DIST.date.year, &charcheck); /*check date input valid*/
			} while (charcheck == 1);
			getchar();
			if (status == '2') {
				do {
					printf("State: ");
					gets(DIST.state);  /*read state*/
					charValidation(DIST.state, &charcheck); /*chaeck user input exist space*/
				} while (charcheck == 1);
				do {
					printf("City: ");
					gets(DIST.city); /*read city*/
					charValidation(DIST.city, &charcheck); 
				} while (charcheck == 1);
			}
			else {
				strcpy(DIST.state, "-");  /*no need location if received*/
				strcpy(DIST.city, "-");
			}

			printf("\nConfirm the following information:\n");  /* confirm info */
			printf("Code\t: %s\nName\t: %s\nStatus\t: %s\nQuantity: %f million\nDate\t: %d-%d-%d\nState\t: %s\nCity\t: %s\n", DIST.code, DIST.name, DIST.status, DIST.quantity, DIST.date.day, DIST.date.month, DIST.date.year, DIST.state, DIST.city);
			printf("Confirm to save the record? 'Y' for yes, 'N' for no: ");
			scanf(" %c", &save);
			while (save != 'Y' && save != 'y' && save != 'N' && save != 'n') {
				printf(">>> Invalid input!\nPlease enter again: ");
				scanf(" %c", &save);
			}
			if (save == 'Y' || save == 'y') {
				fp = fopen("dist.txt", "a");
				if (fp == NULL)
					printf("Unable to open the file.");
				else {
					fprintf(fp, "%s %s %s %f %d-%d-%d %s %s\n", DIST.code, DIST.name, DIST.status, DIST.quantity, DIST.date.day, DIST.date.month, DIST.date.year, DIST.state, DIST.city); /*sace in to file*/
					fclose(fp);
					updateVaccine(DIST.code, DIST.status, &DIST.quantity);  /*access to update vaccine function to update vaccine quantity*/
					printf(">>> Record save sucessful\n");
				}
			}
			else
				printf(">>> Record cancel to save\n");
		}
		else
			printf(">>> Not enough available quantity to distribute!\n\n"); /*if no enough quantity available to distributed*/

		printf("Continue to update vaccine quantity? 'Y' for yes, 'N' for no: ");
		scanf(" %c", &opt);
		while (opt != 'Y' && opt != 'y' && opt != 'N' && opt != 'n') {
			printf(">>> Invalid input!\nPlease enter again: ");
			scanf(" %c", &opt);
		}
		printf("\n");
	} while (opt != 'N' && opt != 'n');
}