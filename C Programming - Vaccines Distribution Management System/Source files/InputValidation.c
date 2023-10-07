#include "main.h"
#include "string.h"

void charValidation(char* name, int* check)
{
	int i;

	if (*check == 1) {
		*check = 0;
	}

	for (i = 0; i < strlen(name); i++) {
		if (name[i] == ' ') {  /* check user input exist space */
			printf(">>> Please avoid the space\n");
			printf(">>> You can replace the space with _\n");
			*check = 1;
			break;
		}
	}
}

void intValidation(int* valid, int* num)
{
	while (*valid != 1 || *num < 0) {  /*check user input is integer or not*/
		getchar();
		printf(">>> Invalid input!\n");
		printf("Please enter the number again: ");
		*valid = scanf("%d", &*num);
	}
}

void floatValidation(int *valid, float *num)
{
	while (*valid != 1 || *num < 0) {  /*check user input is float or not*/
		getchar();
		printf(">>> Invalid input!\n");
		printf("Please enter the number again: ");
		*valid = scanf("%f", &*num);
	}
}

void dateValidation(int* day, int* month, int* year, int* check)
{
	if (*check == 1) {
		*check = 0;
	}

	if (*day < 1 || *day > 31 || *month < 1 || *month > 12 || *year < 1 || *year > 9999) { /* check the date input is valid */
		printf(">>> Invalid Date!\n");
		*check = 1;
	}
		
}