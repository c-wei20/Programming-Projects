/* Name: Clarence Lee Chee Wei */
/* TP Number: TP062572 */

#include "main.h"
#include "function.h"

int main()
{
	char opt;

	do {
		printf("\n\t-------------------------------------------\n");
		printf("\t*** VACCINE INVENTORY MANAGEMENT SYSTEM ***\n");
		printf("\t-------------------------------------------\n");

		printf("\nPlease select a function:\n\t[1] Inventory Creation\n\t[2] Edit Vaccine Inventory Record\n\t[3] Update Quantities\n"); /* Print the option number to user */
		printf("\t[4] Search Vaccine Available Quantity\n\t[5] Vaccine Received & Distributed Quantities List\n\t[0] Exit\n");
		printf("\nEnter your selection: ");
		scanf(" %c", &opt); /*read the user option*/

		while (opt != '1' && opt != '2' && opt != '3' && opt != '4' && opt != '5' && opt != '0') { /*check if user enter irrelevent option*/
			printf(">>> Invalid input!\n");
			printf("Please enter your selection again: "); /*ask for input again*/
			scanf(" %c", &opt);
		}
	
		switch (opt) {
		case '1':
			system("CLS");
			creation(); /*access to inventory creation function*/
			system("CLS");
			break;
		case '2':
			system("CLS");
			editVaccine(); /*access to edit vaccine detail function*/
			break;
		case '3':
			system("CLS");
			updateQuantity(); /*access to updated quantity function*/
			system("CLS");
			break;
		case '4':
			system("CLS");
			searchQuantity(); /*access to search available quantity function*/
			system("CLS");
			break;
		case '5':
			system("CLS");
			distList(); /*access to received & distribution list function*/
			system("CLS");
			break;
		default:
			printf("Are you sure want to exit? 'Y' for YES, 'N' for NO: ");  /*confirm exist with the user*/
			scanf(" %c", &opt);
			while (opt != 'Y' && opt != 'y' && opt != 'N' && opt != 'n') {  /*check if user enter irrelevent option*/
				printf(">>> Invalid input!\nAre you sure want to exit? 'Y' for YES, 'N' for NO: "); 
				scanf(" %c", &opt);
			}
			if (opt == 'Y' || opt == 'y') {  /*confirm t0 exist*/
				printf("\nBye-bye!!!\n");
			}
			break;
		}
	} while (opt != 'Y' && opt != 'y');
	return 0;
}