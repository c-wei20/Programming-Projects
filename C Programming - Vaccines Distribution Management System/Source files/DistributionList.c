#include "main.h"
#include <string.h>
#include "sortDateCondition.h"
#define MAXFILE 1024

struct distribute
{
	char code[3], name[12], status[12];
	float quantity;
	struct {
		int day, month, year;
	}date;
	char state[16], city[20];
};

void distList()
{
	struct distribute dist[MAXFILE];
	struct distribute temp;
	FILE* fp;
	int i, r, line, check;
	char opt, title[23], sort[13];
	
	printf("\n\t *** Vaccine Received & Distributed Quantities List ***\n\n");

	fp = fopen("dist.txt", "r");
	if (fp == NULL)
		printf("Unable to open the file\n");
	else {
		i = 0;
		while (!feof(fp)) {
			fscanf(fp, "%s %s %s %f %d-%d-%d %s %s\n", dist[i].code, dist[i].name, dist[i].status, &dist[i].quantity, &dist[i].date.day, &dist[i].date.month, &dist[i].date.year, dist[i].state, dist[i].city);  /*read record from file */
			i++;
		}
	}
	fclose(fp);

	do {
		printf("Select an option to view:\n\t[1] View by quantity with descending\n\t[2] View by only received quantity with descending\n\t"); /*display the view option */
		printf("[3] View by only distributed quantity with descending\n\t[4] View by vaccine code with descending\n\t[5] View by date with descending\n\n");
		printf("Enter your selection: ");
		scanf(" %c", &opt); /*read the user view option*/
		while (opt != '1' && opt != '2' && opt != '3' && opt != '4' && opt != '5') {
			printf(">>> Invalid input!\nPlease enter your selection again: ");
			scanf(" %c", &opt); /*read the user view option*/
		}

		switch (opt) {
		case '1':
		case '2':
		case '3':
			strcpy(sort, "quantity");
			for (r = 0; r < i - 1; r++) {   /*sort the record with quantity by descending*/
				for (line = 0; line < i - 1 - r; line++) {
					if (dist[line].quantity < dist[line + 1].quantity) {
						temp = dist[line];
						dist[line] = dist[line + 1];
						dist[line + 1] = temp;
					}
				}
			}
			break;
		case '4':
			strcpy(sort, "vaccine code");
			for (r = 0; r < i - 1; r++) {  /*sort the revord with vaccine code by descending*/
				for (line = 0; line < i - 1 - r; line++) {
					if (strcmp(dist[line].code, dist[line + 1].code) < 0) {
						temp = dist[line];
						dist[line] = dist[line + 1];
						dist[line + 1] = temp;
					}
				}
			}
			break;
		default:
			strcpy(sort, "date");
			for (r = 0; r < i - 1; r++) { /*sort the record with date by descending*/
				for (line = 0; line < i - 1 - r; line++) {   /*call sortDateCondition to check is the i date is smaller than i+1 date*/
					check = sortDateCondition(&dist[line].date.day, &dist[line].date.month, &dist[line].date.year, &dist[line + 1].date.day, &dist[line + 1].date.month, &dist[line + 1].date.year); 
					if (check == 1){  /*if condition true*/
						temp = dist[line];
						dist[line] = dist[line + 1];
						dist[line + 1] = temp;
					}
				}
			}
			break;
		}

		switch (opt) {
		case'2':
			strcpy(title, "received"); /*give string according to option*/
			break;
		case'3':
			strcpy(title, "distributed");
			break;
		default:
			strcpy(title, "received & distributed");
			break;
		}

		printf("\nVaccine %s quantity list sort by %s with descending:\n\n", title, sort);
		printf("   ---------------------------------------------------------------------------------------------------------------------------\n");
		printf("    Vaccine Code\tName\t\tStatus\t\tQuantity (million)\tDate\t\tState\t\tCity\n");
		printf("   ---------------------------------------------------------------------------------------------------------------------------\n");
		if (opt == '2') {
			for (line = 0; line < i; line++)
				if (strstr(dist[line].status, "Received") != NULL)  /*to check and print only the received record*/
					printf("      %s\t\t%-12s\t%-12s\t%f\t\t%d-%d-%d\t%-16s %s\n", dist[line].code, dist[line].name, dist[line].status, dist[line].quantity, dist[line].date.day, dist[line].date.month, dist[line].date.year, dist[line].state, dist[line].city);
		}
		else if (opt == '3') {
			for (line = 0; line < i; line++)
				if (strstr(dist[line].status, "Distributed") != NULL)  /*to check and print only the distributed record*/
					printf("      %s\t\t%-12s\t%-12s\t%f\t\t%d-%d-%d\t%-16s %s\n", dist[line].code, dist[line].name, dist[line].status, dist[line].quantity, dist[line].date.day, dist[line].date.month, dist[line].date.year, dist[line].state, dist[line].city);
		}
		else {
			for (line = 0; line < i; line++)   /*to print all record*/
				printf("      %s\t\t%-12s\t%-12s\t%f\t\t%d-%d-%d\t%-16s %s\n", dist[line].code, dist[line].name, dist[line].status, dist[line].quantity, dist[line].date.day, dist[line].date.month, dist[line].date.year, dist[line].state, dist[line].city);
		}

		printf("\nContinue to view vaccine received & distribution list with other option? 'Y' to continue, 'N' back to main menu: ");
		scanf(" %c", &opt);
		while (opt != 'Y' && opt != 'y' && opt != 'N' && opt != 'n') {
			printf(">>> Invalid input!\nPlease enter again: ");
			scanf(" %c", &opt);
		}
		printf("\n");
	}while (opt != 'N' && opt != 'n');
}
