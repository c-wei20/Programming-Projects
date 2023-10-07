int sortDateCondition(int* day1, int* month1, int* year1, int* day2, int* month2, int* year2)
{
	int check;  /*indicate condition*/
	if (*day1 < *day2 && *month1 < *month2 && *year1 < *year2) /*check the date1 is small than date2*/
		check = 1; /*condition true*/
	else if (*day1 < *day2 && *month1 < *month2 && *year1 == *year2)
		check = 1;
	else if (*day1 < *day2 && *month1 == *month2 && *year1 == *year2)
		check = 1;
	else if (*day1 == *day2 && *month1 == *month2 && *year1 < *year2)
		check = 1;
	else if (*day1 == *day2 && *month1 < *month2 && *year1 < *year2)
		check = 1;
	else if (*day1 == *day2 && *month1 < *month2 && *year1 == *year2)
		check = 1;
	else if (*day1 > *day2 && *month1 < *month2 && *year1 == *year2)
		check = 1;
	else if (*day1 > *day2 && *month1 < *month2 && *year1 < *year2)
		check = 1;
	else
		check = 0; /*condition false*/

	return check; /*return the condition true or false*/
}