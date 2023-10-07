//G3_TP062572_TP062011_TP061980

#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std;

//Admin array structure
struct Admin
{
	string username;
	string password;
	string position;
	string location;
};

//Student array structure
struct Student
{
	string studentID;
	string password;
	string name;
	string dob;
	int age;
	char gender;
	string phone;
	string address;
	string tuitionCenterCode;
	string tuitionCenterName;
	string subject[10];
};

//Tutor array structure
struct Tutor
{
	string tutorID;
	string name;
	string dob;
	int age;
	char gender;
	string dateJoined;
	string dateTerminated;
	double hourlyPayRate;
	string phone;
	string address;
	string education;
	string tuitionCenterCode;
	string tuitionCenterName;
	string subjectCode;
	string subjectName;
	double rating[2];
};

//Tuition array structure
struct Tuition
{
	string code;
	string name;
};

//Subject array structure
struct Subject
{
	string code;
	string name;
};

//global variable to save number of record
int AdminSize = 0;
int StudentSize = 0;
int TutorSize = 0;
int TuitionSize = 0;
int SubjectSize = 0;
Admin* adminlist[10];
Student* studentlist[20];
Tutor* tutorlist[50];
Tuition* tuitionlist[15];
Subject* subjectlist[10];

//global variable to save login user data
Admin* loginAdmin = NULL; //admin login data
Student* loginStudent = NULL; //student login data

//function - add new node
Admin* CreateNewAdmin(string username, string password, string position, string location)
{
	Admin* newAdmin = new Admin;
	newAdmin->username = username;
	newAdmin->password = password;
	newAdmin->position = position;
	newAdmin->location = location;

	return newAdmin;
}

Student* CreateNewStudent(string studentID, string password, string name, string dob, int age, char gender,
	string phone, string address, string tuitionCenterCode, string tuitionCenterName, string subject[10])
{
	Student* newStudent = new Student;
	newStudent->studentID = studentID;
	newStudent->password = password;
	newStudent->name = name;
	newStudent->dob = dob;
	newStudent->age = age;
	newStudent->gender = gender;
	newStudent->phone = phone;
	newStudent->address = address;
	newStudent->tuitionCenterCode = tuitionCenterCode;
	newStudent->tuitionCenterName = tuitionCenterName;
	for (int i = 0; i < 10; i++) {
		if (subject[i] != "\0") {
			newStudent->subject[i] = subject[i];
		}
		else {
			break;
		}
	}
	return newStudent;
}

Tutor* CreateNewTutor(string tutorID, string name, string dob, int age, char gender, string dateJoined,
	string dateTerminated, double hourlyPayRate, string phone, string address, string education,
	string tuitionCenterCode, string tuitionCenterName, string subjectCode, string subjectName, double rating[2]) 
{
	Tutor* newTutor = new Tutor;
	newTutor->tutorID = tutorID;
	newTutor->name = name;
	newTutor->dob = dob;
	newTutor->age = age;
	newTutor->gender = gender;
	newTutor->dateJoined = dateJoined;
	newTutor->dateTerminated = dateTerminated;
	newTutor->hourlyPayRate = hourlyPayRate;
	newTutor->phone = phone;
	newTutor->address = address;
	newTutor->education = education;
	newTutor->tuitionCenterCode = tuitionCenterCode;
	newTutor->tuitionCenterName = tuitionCenterName;
	newTutor->subjectCode = subjectCode;
	newTutor->subjectName = subjectName;
	for (int i = 0; i < 2; i++) {
		newTutor->rating[i] = rating[i];
	}
	return newTutor;
}

Tuition* CreateNewTuition(string code, string name)
{
	Tuition* newTuition = new Tuition;
	newTuition->code = code;
	newTuition->name = name;

	return newTuition;
}

Subject* CreateNewSubject(string code, string name) 
{
	Subject* newSubject = new Subject;
	newSubject->code = code;
	newSubject->name = name;

	return newSubject;
}

//insert new record function
void insertIntoSortedAdmin(Admin* newarray)
{
	if (AdminSize == 0) //when no data in admin array
	{
		adminlist[0] = newarray;
		AdminSize++;
	}
	else if (AdminSize == size(adminlist)) //when array is full
	{
		cout << "Array Overflow, cannot add new record!";
	}
	else
	{
		int i;
		for (i = AdminSize - 1; (i >= 0 && adminlist[i]->username > newarray->username); i--)
		{
			adminlist[i + 1] = adminlist[i];
		}
		adminlist[i + 1] = newarray;
		AdminSize++;
	}
}

void insertIntoSortedStudent(Student* newarray)
{
	if (StudentSize == 0) //when no data in array
	{
		studentlist[0] = newarray;
		StudentSize++;
	}
	else if (StudentSize == size(studentlist)) //when array is full
	{
		cout << "Array Overflow, cannot add new record!";
	}
	else
	{
		int i;
		for (i = StudentSize - 1; (i >= 0 && studentlist[i]->name > newarray->name); i--)
		{
			studentlist[i + 1] = studentlist[i];
		}
		studentlist[i + 1] = newarray;
		StudentSize++;
	}
}

//
void insertIntoEndofTutorList(Tutor* newarray)
{
	if (TutorSize == 0) //when no data in array
	{
		tutorlist[0] = newarray;
		TutorSize++;
	}
	else if(TutorSize == size(tutorlist)) //when array is full
	{
		cout << "Array Overflow, cannot add new record!";
	}
	else
	{
		tutorlist[TutorSize] = newarray; //add array to the back
		TutorSize++;
	}
}

void insertIntoSortedTuition(Tuition* newarray)
{
	if (TuitionSize == 0) //when no data in array
	{
		tuitionlist[0] = newarray;
		TuitionSize++;
	}
	else if (TuitionSize == size(tuitionlist)) //when array is full
	{
		cout << "Array Overflow, cannot add new record!";
	}
	else
	{
		int i;
		for (i = TuitionSize - 1; (i >= 0 && tuitionlist[i]->code > newarray->code); i--)
		{
			tuitionlist[i + 1] = tuitionlist[i];
		}
		tuitionlist[i + 1] = newarray;
		TuitionSize++;
	}
}

void insertIntoSortedSubject(Subject* newarray)
{
	if (SubjectSize == 0) //when no data in array
	{
		subjectlist[0] = newarray;
		SubjectSize++;
	}
	else if (SubjectSize == size(subjectlist)) //when array is full
	{
		cout << "Array Overflow, cannot add new record!";
	}
	else
	{
		int i;
		for (i = SubjectSize - 1; (i >= 0 && subjectlist[i]->code > newarray->code); i--)
		{
			subjectlist[i + 1] = subjectlist[i];
		}
		subjectlist[i + 1] = newarray;
		SubjectSize++;
	}
}

// Predefined record function
void PredefinedAdmin() {
	Admin* newAdmin = CreateNewAdmin("Kirsten", "12345678", "Manager", "Bukit Jalil");
	insertIntoSortedAdmin(newAdmin);
	newAdmin = CreateNewAdmin("Miguel", "11223344", "Admin", "Bukit Jalil");
	insertIntoSortedAdmin(newAdmin);
	newAdmin = CreateNewAdmin("Angela", "87654321", "Admin", "Petaling Jaya");
	insertIntoSortedAdmin(newAdmin);
	newAdmin = CreateNewAdmin("Fiona", "12345678", "Admin", "Cheras");
	insertIntoSortedAdmin(newAdmin);
}

void PredefinedStudent() {
	Student* newStudent = new Student;
	string subject[10] = { "AMT", "PS", "EN" };
	newStudent = CreateNewStudent("S00001", "123456", "James", "12/12/2005", 17, 'M', "011-2233453", "17-B Jln Batai Laut 7 Kawasan 16 Tmn Intan", "BJ-H", "Bukit Jalil", subject);
	insertIntoSortedStudent(newStudent);
	string subject1[10] = { "EC", "BK" };
	newStudent = CreateNewStudent("S00002", "123321", "Peter", "12/1/2004", 18, 'M', "012-2344345", "13/F Plaza Mont Kiara Blok E Jalan 1/70C", "BJ-H", "Bukit Jalil", subject1);
	insertIntoSortedStudent(newStudent);
	string subject2[10] = { "MA", "EN", "SC" };
	newStudent = CreateNewStudent("S00003", "234567", "Swati", "11/19/2005", 17, 'F', "018-8290648", "Kg. Banggol Saman Kok Lanas, Ketereh", "PJ", "Petaling Jaya", subject2);
	insertIntoSortedStudent(newStudent);
	string subject3[10] = { "MT" };
	newStudent = CreateNewStudent("S00004", "abcde", "Brian", "11/8/2004", 18, 'M', "014-2966491", "476 Jln Pasir Puteh Pasir Puteh", "PJ", "Petaling Jaya", subject3);
	insertIntoSortedStudent(newStudent);
	string subject4[10] = { "AMT", "PS" };
	newStudent = CreateNewStudent("S00005", "abc1234", "Sally", "10/27/2004", 18, 'F', "018-0936226", "10Th Mile, Jalan Kuching-serian", "CR", "Cheras", subject4);
	insertIntoSortedStudent(newStudent);
	string subject5[10] = { "MT", "EN" };
	newStudent = CreateNewStudent("S00006", "aaa666", "Kevin", "10/16/2006", 16, 'M', "019-2072971", "9A JLN LAPANGAN TERBANG LAMA", "CR", "Cheras", subject5);
	insertIntoSortedStudent(newStudent);
}

void PredefinedTutor() {
	Tutor* newTutor = new Tutor;
	// Bukit Jalil Tutor
	double Rating[2] = { 14, 3 };
	newTutor = CreateNewTutor("T0001", "Elaine", "12/1/1987", 35, 'F', "1/1/2019", "-", 40, "011-2233453",
		"Amcorp Trade Centre, 18 Persiaran Barat", "Mathematics", "BJ-H", "Bukit Jalil", "MT", "Mathematics", Rating);
	insertIntoEndofTutorList(newTutor);
	double Rating1[2] = { 9, 2 };
	newTutor = CreateNewTutor("T0002", "Jamie", "12/3/1992", 30, 'F', "1/1/2019", "-", 70, "012-2344345",
		"8 Jln Perhentian", "Mathematics", "BJ-H", "Bukit Jalil", "AMT", "Additional Mathematics", Rating1);
	insertIntoEndofTutorList(newTutor);
	double Rating2[2] = { 4, 1 };
	newTutor = CreateNewTutor("T0003", "Anthony", "6/9/1988", 34, 'M', "1/1/2019", "-", 60, "018-8290648",
		"10th Floor Mui Plaza Jalan P Ramlee", "Engineering", "BJ-H", "Bukit Jalil", "PS", "Physics", Rating2);
	insertIntoEndofTutorList(newTutor);
	double Rating3[2] = { 4, 1 };
	newTutor = CreateNewTutor("T0004", "David", "6/10/1988", 34, 'M', "1/1/2019", "-", 50, "014-2966491",
		"4 Jalan Barrack", "Chemistry", "BJ-H", "Bukit Jalil", "CM", "Chemistry", Rating3);
	insertIntoEndofTutorList(newTutor);
	double Rating4[2] = { 10, 2 };
	newTutor = CreateNewTutor("T0005", "Nicola", "6/11/1988", 34, 'M', "1/1/2019", "-", 60, "018-0936226",
		"Kompleks Pejabat Kerajaan, Jalan Duta", "Malay Linguistic", "BJ-H", "Bukit Jalil", "MA", "Malay", Rating4);
	insertIntoEndofTutorList(newTutor);
	double Rating5[2] = { 10, 2 };
	newTutor = CreateNewTutor("T0006", "Christopher", "12/2/1987", 35, 'M', "1/1/2019", "-", 62, "019-2072971",
		"19 1 Jln 3/27D Seksyen 6 Wangsa Maju", "English Linguistic", "BJ-H", "Bukit Jalil", "EN", "English", Rating5);
	insertIntoEndofTutorList(newTutor);
	double Rating6[2] = { 0, 1 };
	newTutor = CreateNewTutor("T0007", "Pauline", "12/3/1987", 35, 'F', "1/1/2019", "-", 64, "011-6873958",
		"No. 12, Jalan Yap Kwan Seng", "Economics", "BJ-H", "Bukit Jalil", "EC", "Economics", Rating6);
	insertIntoEndofTutorList(newTutor);
	double Rating7[2] = { 5, 1 };
	newTutor = CreateNewTutor("T0008", "Amy", "12/4/1987", 35, 'F', "1/1/2019", "-", 66, "017-0312624",
		" 52 Lebuh India", "Accounting", "BJ-H", "Bukit Jalil", "BK", "Book Keeping", Rating7);
	insertIntoEndofTutorList(newTutor);
	// Petaling Jaya Tutor
	double Rating8[2] = { 9, 2 };
	newTutor = CreateNewTutor("T0009", "Katherine", "12/5/1987", 35, 'F', "1/1/2019", "-", 68, "017-6538168",
		"Jalan Petaling, Larkin Industri Area", "Mathematics", "PJ", "Petaling Jaya", "MT", "Mathematics", Rating8);
	insertIntoEndofTutorList(newTutor);
	double Rating9[2] = { 14, 3 };
	newTutor = CreateNewTutor("T0010", "Brett ", "25/6/1990", 32, 'M', "1/1/2019", "12/11/2021", 70, "013-7894309",
		"Jalan Majlis, S. Alam", "Mathematics", "PJ", "Petaling Jaya", "AMT", "Additional Mathematics", Rating9);
	insertIntoEndofTutorList(newTutor);
	double Rating10[2] = { 5, 1 };
	newTutor = CreateNewTutor("T0011", "Nicholas", "25/6/1991", 31, 'M', "1/1/2019", "-", 45, "013-7894310",
		"772 Jln 32 Kampung Baru Salak Selatan", "Engineering", "PJ", "Petaling Jaya", "PS", "Physics", Rating10);
	insertIntoEndofTutorList(newTutor);
	double Rating11[2] = { 5, 1 };
	newTutor = CreateNewTutor("T0012", "Rebecca", "25/6/1992", 30, 'F', "1/1/2019", "-", 74, "011-2233453",
		"3738 Jalan Siram", "Chemistry", "PJ", "Petaling Jaya", "CM", "Chemistry", Rating11);
	insertIntoEndofTutorList(newTutor);
	double Rating12[2] = { 10, 2 };
	newTutor = CreateNewTutor("T0013", "Rachael", "25/6/1993", 29, 'F', "1/1/2019", "-", 76, "012-2344345",
		"4Th Floor Kompleks Pertama", "Malay Linguistic", "PJ", "Petaling Jaya", "MA", "Malay", Rating12);
	insertIntoEndofTutorList(newTutor);
	double Rating13[2] = { 9, 2 };
	newTutor = CreateNewTutor("T0014", "Philip", "12/5/1991", 31, 'M', "1/1/2019", "-", 78, "018-8290648",
		"497-501 Jalan Pasir Puteh", "English Linguistic", "PJ", "Petaling Jaya", "EN", "English", Rating13);
	insertIntoEndofTutorList(newTutor);
	double Rating14[2] = { 14, 3 };
	newTutor = CreateNewTutor("T0015", "Paul", "12/6/1991", 31, 'M', "1/1/2019", "-", 80, "014-2966491",
		"17-B Jln Batai Laut 7 Kawasan 16 Tmn Intan", "Economics", "PJ", "Petaling Jaya", "EC", "Economics", Rating14);
	insertIntoEndofTutorList(newTutor);
	double Rating15[2] = { 5, 1 };
	newTutor = CreateNewTutor("T0016", "Martin", "12/7/1991", 31, 'M', "1/1/2019", "-", 65, "018-0936226",
		"13/F Plaza Mont Kiara Blok E Jalan 1/70C", "Accounting", "PJ", "Petaling Jaya", "BK", "Book Keeping", Rating15);
	insertIntoEndofTutorList(newTutor);
	double Rating16[2] = { 10, 2 };
	newTutor = CreateNewTutor("T0017", "Thomas", "25/6/1994", 28, 'M', "1/1/2019", "-", 55, "019-2072971",
		"Kg. Banggol Saman Kok Lanas, Ketereh", "Applied Science", "PJ", "Petaling Jaya", "SC", "Science", Rating16);
	insertIntoEndofTutorList(newTutor);
	double Rating17[2] = { 0, 1 };
	newTutor = CreateNewTutor("T0018", "Angel", "25/6/1995", 27, 'F', "1/1/2019", "-", 48, "019-2072972",
		"476 Jln Pasir Puteh Pasir Puteh", "Chinese Linguitic", "PJ", "Petaling Jaya", "CH", "Chinese", Rating17);
	insertIntoEndofTutorList(newTutor);
	// Cheras Tutor
	double Rating18[2] = { 10, 2 };
	newTutor = CreateNewTutor("T0019", "Stephen", "25/6/1996", 26, 'M', "1/1/2020", "-", 40, "019-2072973",
		"10Th Mile, Jalan Kuching-serian", "Mathematics", "CR", "Cheras", "MT", "Mathematics", Rating18);
	insertIntoEndofTutorList(newTutor);
	double Rating19[2] = { 10, 2 };
	newTutor = CreateNewTutor("T0020", "Sandra ", "12/8/1991", 31, 'F', "1/1/2020", "12/11/2021", 70, "019-2072974",
		"9A JLN LAPANGAN TERBANG LAMA", "Mathematics", "CR", "Cheras", "AMT", "Additional Mathematics", Rating19);
	insertIntoEndofTutorList(newTutor);
	double Rating20[2] = { 10, 2 };
	newTutor = CreateNewTutor("T0021", "Carolyn", "11/11/1992", 30, 'F', "1/1/2020", "-", 60, "018-0936226",
		"8 Jln Perhentian", "Engineering", "CR", "Cheras", "PS", "Physics", Rating20);
	insertIntoEndofTutorList(newTutor);
	double Rating21[2] = { 9, 2 };
	newTutor = CreateNewTutor("T0022", "Kerry", "12/1/1992", 30, 'F', "1/1/2020", "-", 50, "019-2072971",
		"10th Floor Mui Plaza Jalan P Ramlee", "Chemistry", "CR", "Cheras", "CM", "Chemistry", Rating21);
	insertIntoEndofTutorList(newTutor);
	double Rating22[2] = { 14, 3 };
	newTutor = CreateNewTutor("T0023", "Gillian", "12/2/1992", 30, 'F', "1/1/2020", "-", 60, "011-6873958",
		"4 Jalan Barrack", "Malay Linguistic", "CR", "Cheras", "MA", "Malay", Rating22);
	insertIntoEndofTutorList(newTutor);
	double Rating23[2] = { 0, 1 };
	newTutor = CreateNewTutor("T0024", "Darren", "12/3/1992", 30, 'M', "1/1/2020", "20/12/2021", 63, "017-0312624",
		"Kompleks Pejabat Kerajaan, Jalan Duta", "English Linguistic", "CR", "Cheras", "EN", "English", Rating23);
	insertIntoEndofTutorList(newTutor);
}

void PredefinedTuition() {
	Tuition* newTuition = new Tuition;
	newTuition = CreateNewTuition("BJ-H", "Bukit Jalil");
	insertIntoSortedTuition(newTuition);
	newTuition = CreateNewTuition("PJ", "Petaling Jaya");
	insertIntoSortedTuition(newTuition);
	newTuition = CreateNewTuition("CR", "Cheras");
	insertIntoSortedTuition(newTuition);
}

void PredefinedSubject() {
	Subject* newSubject = new Subject;
	newSubject = CreateNewSubject("MT", "Mathematics");
	insertIntoSortedSubject(newSubject);
	newSubject = CreateNewSubject("AMT", "Additional Mathematics");
	insertIntoSortedSubject(newSubject);
	newSubject = CreateNewSubject("PS", "Physics");
	insertIntoSortedSubject(newSubject);
	newSubject = CreateNewSubject("CM", "Chemistry");
	insertIntoSortedSubject(newSubject);
	newSubject = CreateNewSubject("MA", "Malay");
	insertIntoSortedSubject(newSubject);
	newSubject = CreateNewSubject("EN", "English");
	insertIntoSortedSubject(newSubject);
	newSubject = CreateNewSubject("EC", "Economics");
	insertIntoSortedSubject(newSubject);
	newSubject = CreateNewSubject("BK", "Book Keeping");
	insertIntoSortedSubject(newSubject);
	newSubject = CreateNewSubject("SC", "Science");
	insertIntoSortedSubject(newSubject);
	newSubject = CreateNewSubject("CH", "Chinese");
	insertIntoSortedSubject(newSubject);
}

//sort and display tutor record function
// sort by name
void sortTutorName()
{
	if (TutorSize == 0)
	{
		cout << "List is empty, no thing to sort";
		return;
	}
	bool sort = true;
	while (sort)
	{
		sort = false;
		for (int i = 0; i < TutorSize - 1 ; i++)
		{
			for (int j = 0; j < TutorSize - 1; j++)
			{
				if (tutorlist[j]->name > tutorlist[j + 1]->name)
				{
					swap(tutorlist[j], tutorlist[j + 1]);
				}
			}
		}
	}
}

void sortTutorID()
{
	if (TutorSize == 0)
	{
		cout << "List is empty, no thing to sort";
		return;
	}
	bool sort = true;
	while (sort)
	{
		sort = false;
		for (int i = 0; i < TutorSize - 1; i++)
		{
			for (int j = 0; j < TutorSize - 1; j++)
			{
				if (tutorlist[j]->tutorID > tutorlist[j + 1]->tutorID)
				{
					swap(tutorlist[j], tutorlist[j + 1]);
				}
			}
		}

	}
}

void sortTutorHourPay()
{
	if (TutorSize == 0)
	{
		cout << "List is empty, no thing to sort";
		return;
	}
	bool sort = true;
	while (sort)
		{
		sort = false;
		for (int i = 0; i < TutorSize - 1; i++)
		{
			for (int j = 0; j < TutorSize - 1; j++)
			{
				if (tutorlist[j]->hourlyPayRate > tutorlist[j + 1]->hourlyPayRate)
				{
					swap(tutorlist[j], tutorlist[j + 1]);
				}
			}
		}
	}
}

void sortTutorRating()
{
	if (TutorSize == 0)
	{
		cout << "List is empty, no thing to sort";
		return;
	}
	bool sort = true;
	while (sort)
	{
		sort = false;
		for (int i = 0; i < TutorSize - 1; i++)
		{
			for (int j = 0; j < TutorSize - 1; j++)
			{
				if (tutorlist[j]->rating > tutorlist[j + 1]->rating)
				{
					swap(tutorlist[j], tutorlist[j + 1]);
				}
			}
		}
	}
}

//Display record in detail page ////
//Student Page
void displayStudentPage(string tuition, int select)
{
	int i;
	int position = 0;
	for (i = 0; i < StudentSize; i++)
	{
		if (studentlist[i]->tuitionCenterName == tuition)
		{
			position++;
		}
		if (position == select)
		{
			break;
		}
	}
	do {
		cout << "Details Record of Student ID: " << studentlist[i]->studentID << endl << endl;
		cout << left << setw(20) << "-Student ID" << ": " << studentlist[i]->studentID << endl;
		cout << setw(20) << "-Name" << ": " << studentlist[i]->name << endl;
		cout << setw(20) << "-Date of Birth" << ": " << studentlist[i]->dob << endl;
		cout << setw(20) << "-Age" << ": " << studentlist[i]->age << endl;
		cout << setw(20) << "-Gender" << ": " << studentlist[i]->gender << endl;
		cout << setw(20) << "-Phone" << ": " << studentlist[i]->phone << endl;
		cout << setw(20) << "-Address" << ": " << studentlist[i]->address << endl;
		cout << setw(20) << "-Tuition Center" << ": " << studentlist[i]->tuitionCenterName << endl;
		cout << setw(20) << "-Subject" << ": ";
		for (int k = 0; k < 10; k++)
		{
			if (studentlist[i]->subject[k] != "\0")
			{
				for ( int j = 0; j < SubjectSize; j++)
				{
					if (subjectlist[j]->code == studentlist[i]->subject[k])
					{
						cout << subjectlist[j]->name << "  ";
						break;
					}
				}
			}
			else
			{
				break;
			}
		}

		bool find = false;
		while (!find && select != -1) {
			cout << endl << endl << "Enter 0 to Page UP, 1 to page DOWN, -1 exit to main menu: ";
			cin >> select;
			while (cin.fail() || select < -2 || select > 1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Enter 0 to Page UP, 1 to page DOWN, -1 exit to main menu: ";
				cin >> select;
			}
			//go to previous page
			if (select == 0) {
				cout << "Page Up" << endl;
				//check whether have previous record
				while (i != 0)
				{
					i--;
					if (studentlist[i]->tuitionCenterName == tuition)
					{
						find = true;
						break;
					}
				}
			}
			//go to next page
			else if (select == 1) {
				cout << "Page Down" << endl;
				//check whether have next record
				while (i != StudentSize - 1)
				{
					i++;
					if (studentlist[i]->tuitionCenterName == tuition)
					{
						find = true;
						break;
					}
				}
			}
			//no previous or next record
			if (!find) {
				cout << "No more record found, please select other option!" << endl;
			}
		}
		system("CLS");
	} while (select != -1);
}

//Tutor page
void displayTutorPage(string tuition, int select)
{
	int i;
	int position = 0;
	for (i = 0; i < StudentSize; i++)
	{
		if (tuition == "") {
			position++;
		}
		else {
			if (tutorlist[i]->tuitionCenterName == tuition) {
				position++;
			}
		}
		if (position == select) {
			break;
		}
	}
	do {
		cout << "Details Record of Tutor ID: " << tutorlist[i]->tutorID << endl << endl;
		cout << left << setw(20) << "-Tutor ID" << ": " << tutorlist[i]->tutorID << endl;
		cout << setw(20) << "-Name" << ": " << tutorlist[i]->name << endl;
		cout << setw(20) << "-Date of Birth" << ": " << tutorlist[i]->dob << endl;
		cout << setw(20) << "-Age" << ": " << tutorlist[i]->age << endl;
		cout << setw(20) << "-Gender" << ": " << tutorlist[i]->gender << endl;
		cout << setw(20) << "-Date Joined" << ": " << tutorlist[i]->dateJoined << endl;
		cout << setw(20) << "-Date Terminated" << ": " << tutorlist[i]->dateTerminated << endl;
		cout << setw(20) << "-Hourly Pay Rate" << ": RM " << setprecision(2) << tutorlist[i]->hourlyPayRate << endl;
		cout << setw(20) << "-Phone" << ": " << tutorlist[i]->phone << endl;
		cout << setw(20) << "-Address" << ": " << tutorlist[i]->address << endl;
		cout << setw(20) << "-Specialized Field" << ": " << tutorlist[i]->education << endl;
		cout << setw(20) << "-Tuition Center Code" << ": " << tutorlist[i]->tuitionCenterCode << endl;
		cout << setw(20) << "-Tuition Center Name" << ": " << tutorlist[i]->tuitionCenterName << endl;
		cout << setw(20) << "-Subject Code" << ": " << tutorlist[i]->subjectCode << endl;
		cout << setw(20) << "-Subject Name" << ": " << tutorlist[i]->subjectName << endl;
		cout << setw(20) << "-Rating" << ": " << setprecision(1) << tutorlist[i]->rating[0] / tutorlist[i]->rating[1] << endl;

		bool find = false;
		while (!find && select != -1) {
			cout << endl << "Enter 0 to Page UP, 1 to page DOWN, -1 exit to main menu: ";
			cin >> select;
			while (cin.fail() || select < -2 || select > 1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Enter 0 to Page UP, 1 to page DOWN, -1 exit to main menu: ";
				cin >> select;
			}
			//go to previous page
			if (select == 0) {
				cout << "Page Up" << endl;
				while (i != 0)
				{
					i--;
					if (tuition == "")
					{
						find = true;
						break;
					}
					else
					{
						if (tutorlist[i]->tuitionCenterName == tuition)
						{
							find = true;
							break;
						}
					}
				}
			}
			else if (select == 1) {
				cout << "Page Down" << endl;
				while (i != TutorSize - 1)
				{
					i++;
					if (tuition == "")
					{
						find = true;
						break;
					}
					else
					{
						if (tutorlist[i]->tuitionCenterName == tuition)
						{
							find = true;
							break;
						}
					}
				}
			}
			if (!find) {
				cout << "No more record found, please select other option!" << endl;
			}
		}
		system("CLS");
	} while (select != -1);
}


//Display record in table list function
// Admin
void displayAdmin()
{
	int j = 1;
	cout << string(65, '-') << endl;
	cout << left << setw(5) << "No." << setw(20) << "Name" << setw(20) << "Position" << "Tuition Location" << endl;
	cout << string(65, '-') << endl;
	for (int i = 0; i < AdminSize; i++)
	{
		cout << left << setw(5) << j << setw(20) << adminlist[i]->username << setw(20) << adminlist[i]->position << adminlist[i]->location << endl;
		j++;
	}
	cout << endl;
}
//Student
void displayStudent()
{
	int select;
	string tname;
	do {
		if (loginAdmin->location == "Bukit Jalil") {
			int num = 0;
			string tuitionList[10] = {};
			for (int i = 0; i < TuitionSize; i++)
			{
				tuitionList[num] = tuitionlist[i]->name;
				num++;
			}
			cout << "Select the student record to display: " << endl;
			for (int i = 0; i < num; i++) {
				cout << "\t[" << i + 1 << "] " << tuitionList[i] << endl;
			}
			cout << "Enter the number of student: ";
			cin >> select;
			while (cin.fail() || select < 0 || select > num) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Enter the number of tuition: ";
				cin >> select;
			}
			tname = tuitionList[select - 1];
		}
		else {
			tname = loginAdmin->location;
		}
		int no = 0;
		cout << string(100, '-') << endl;
		cout << left << setw(5) << "No." << setw(15) << "Student ID" << setw(20) << "Name" << setw(10) << "Age"
			<< setw(25) << "Tuition" << setw(25) << "Subject" << endl;
		cout << string(100, '-') << endl;
		for (int i = 0; i < StudentSize; i++)
		{
			if (studentlist[i]->tuitionCenterName == tname)
			{
				no++;
				cout << left << setw(5) << no << setw(15) << studentlist[i]->studentID << setw(20) << studentlist[i]->name << setw(10)
					<< studentlist[i]->age << setw(25) << studentlist[i]->tuitionCenterName;
				for (int j = 0; j < sizeof(studentlist[i]->subject) / sizeof(studentlist[i]->subject[0]); j++) {
					if (studentlist[i]->subject[j] != "\0") {
						cout << studentlist[i]->subject[j] << ", ";
					}
				}
				cout << endl;
			}
		}
		cout << endl << "Select the number of student to view detials (0 exit to main menu): ";
		cin >> select;
		while (cin.fail() || select < -1 || select > no) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Select the number of student to view detials (0 exit to main menu): ";
			cin >> select;
		}
		if (select != 0) {
			system("CLS");
			displayStudentPage(tname, select);
			select = 0;
		}
	} while (select != 0);
}
//Tutor
void displayTutor()
{
	int select;
	string tname;
	do {
		if (loginAdmin->location == "Bukit Jalil") {
			int num = 0;
			string tuitionList[10] = {};

			for (int i = 0; i < TuitionSize; i++)
			{
				tuitionList[num] = tuitionlist[i]->name;
				num++;
			}
			cout << "Select the tuition's tutor record to display: " << endl;
			for (int i = 0; i < num; i++) {
				cout << "\t[" << i + 1 << "] " << tuitionList[i] << endl;
			}
			cout << "Enter the number of tuition: ";
			cin >> select;
			while (cin.fail() || select < 0 || select > num) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Enter the number of tuition: ";
				cin >> select;
			}
			tname = tuitionList[select - 1];
		}
		else {
			tname = loginAdmin->location;
		}
		//display the top row of the table
		int No = 0;
		cout << string(120, '-') << endl;
		cout << left << setw(5) << "No." << setw(15) << "Tutor ID" << setw(20) << "Name" << setw(20) << "Tuition"
			<< setw(25) << "Subject" << setw(25) << "Hourly Pay Rate(RM)" << setw(20) << "Rating" << endl;
		cout << string(120, '-') << endl;
		//display the tutor record list of the specific tuition
		for (int i = 0; i < TutorSize; i++)
		{
			if (tutorlist[i]->tuitionCenterName == tname)
			{
				No++;
				cout << left << setw(5) << No << setw(15) << tutorlist[i]->tutorID << setw(20) << tutorlist[i]->name << setw(20)
					<< tutorlist[i]->tuitionCenterName << setw(25) << tutorlist[i]->subjectName << setw(25) << fixed << setprecision(2)
					<< tutorlist[i]->hourlyPayRate << setw(20) << setprecision(1) << tutorlist[i]->rating[0] / tutorlist[i]->rating[1] << endl;
			}
		}
		//select the tutor record that want to view in detial
		cout << endl << "Select the number of tutor to view detials (0 exit to main menu): ";
		cin >> select;
		while (cin.fail() || select < -1 || select > No) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Select the number of tutor to view detials (0 exit to main menu): ";
			cin >> select;
		}
		if (select != 0) {
			system("CLS");
			displayTutorPage(tname, select);
			select = 0;
		}
	} while (select != 0);
}
//Tutor List
void displayTutorListOnly()
{
	if (loginAdmin->location == "Bukit Jalil") {
		int no = 1;
		cout << string(120, '-') << endl;
		cout << left << setw(5) << "No." << setw(15) << "Tutor ID" << setw(20) << "Name" << setw(20) << "Tuition"
			<< setw(25) << "Subject" << setw(25) << "Hourly Pay Rate(RM)" << setw(20) << "Rating" << endl;
		cout << string(120, '-') << endl;
		for (int i = 0; TutorSize; i++)
		{
			cout << left << setw(5) << no << setw(15) << tutorlist[i]->tutorID << setw(20) << tutorlist[i]->name << setw(20)
				<< tutorlist[i]->tuitionCenterName << setw(25) << tutorlist[i]->subjectName << setw(25) << fixed << setprecision(2)
				<< tutorlist[i]->hourlyPayRate << setw(20) << setprecision(1) << tutorlist[i]->rating[0] / tutorlist[i]->rating[1] << endl;
			no++;
		}
	}
	else {
		string tname = loginAdmin->location;
		int No = 1;
		cout << string(120, '-') << endl;
		cout << left << setw(5) << "No." << setw(15) << "Tutor ID" << setw(20) << "Name" << setw(20) << "Tuition"
			<< setw(25) << "Subject" << setw(25) << "Hourly Pay Rate(RM)" << setw(20) << "Rating" << endl;
		cout << string(120, '-') << endl;
		for (int i = 0; TutorSize; i++)
		{
			if (tutorlist[i]->tuitionCenterName == tname)
			{
				cout << left << setw(5) << No << setw(15) << tutorlist[i]->tutorID << setw(20) << tutorlist[i]->name << setw(20)
					<< tutorlist[i]->tuitionCenterName << setw(25) << tutorlist[i]->subjectName << setw(25) << fixed << setprecision(2)
					<< tutorlist[i]->hourlyPayRate << setw(20) << setprecision(1) << tutorlist[i]->rating[0] / tutorlist[i]->rating[1] << endl;
				No++;
			}
		}
	}
}
//Tuition
void displayTuition()
{
	int j = 1;
	cout << "Tuition Reocrd" << endl << endl;
	cout << string(50, '-') << endl;
	cout << left << setw(5) << "No." << setw(20) << "Tuition Code" << "Tuition Name" << endl;
	cout << string(50, '-') << endl;
	for (int i = 0; i < TuitionSize; i++)
	{
		cout << left << setw(5) << j << setw(20) << tuitionlist[i]->code << tuitionlist[i]->name << endl;
		j++;
	}
	cout << endl;
}
//Subject
void displaySubject()
{
	int j = 1;
	cout << "Student Record" << endl << endl;
	cout << string(50, '-') << endl;
	cout << left << setw(5) << "No." << setw(20) << "Subject Code" << "Subject Name" << endl;
	cout << string(50, '-') << endl;
	for (int i = 0; i < SubjectSize; i++)
	{
		cout << left << setw(5) << j << setw(20) << subjectlist[i]->code << subjectlist[i]->name << endl;
		j++;
	}
}


//Search tutor by tutor id
void searchByTutorID()
{
	double searchRate;
	do {
		sortTutorName();
		cout << "Enter a Tutor Performance Rating (-1 exit to main menu): ";
		cin >> searchRate;
		while (cin.fail() || searchRate < -1 || searchRate > 5) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Enter a Tutor Performance Rating (-1 exit to main menu): ";
			cin >> searchRate;
		}
		bool find = false;
		if (searchRate != -1) {
			system("CLS");
			int no = 1;
			cout << endl << string(120, '-') << endl;
			cout << left << setw(5) << "No." << setw(15) << "Tutor ID" << setw(20) << "Name" << setw(20) << "Tuition"
				<< setw(25) << "Subject" << setw(25) << "Hourly Pay Rate(RM)" << setw(20) << "Rating" << endl;
			cout << string(120, '-') << endl;
			for (int i = 0; i < TutorSize; i++)
			{
				searchRate = round(searchRate * 10.0) / 10.0;
				double Rating = round((tutorlist[i]->rating[0] / tutorlist[i]->rating[1]) * 10.0) / 10.0;
				if (loginAdmin->location == "Bukit Jalil") {
					if (Rating == searchRate) {
						find = true;
						cout << left << setw(5) << no << setw(15) << tutorlist[i]->tutorID << setw(20) << tutorlist[i]->name << setw(20)
							<< tutorlist[i]->tuitionCenterName << setw(25) << tutorlist[i]->subjectName << setw(25) << fixed << setprecision(2)
							<< tutorlist[i]->hourlyPayRate << setw(20) << setprecision(1) << tutorlist[i]->rating[0] / tutorlist[i]->rating[1] << endl;
						no++;
					}
				}
				else {
					if (Rating == searchRate && tutorlist[i]->tuitionCenterName == loginAdmin->location) {
						find = true;
						cout << left << setw(5) << no << setw(15) << tutorlist[i]->tutorID << setw(20) << tutorlist[i]->name << setw(20)
							<< tutorlist[i]->tuitionCenterName << setw(25) << tutorlist[i]->subjectName << setw(25) << fixed << setprecision(2)
							<< tutorlist[i]->hourlyPayRate << setw(20) << setprecision(1) << tutorlist[i]->rating[0] / tutorlist[i]->rating[1] << endl;
						no++;
					}
				}
			}
			cout << endl;
			if (!find) {
				cout << "No record match! " << endl << endl;
			}
		}
	} while (searchRate != -1);
	system("CLS");
}

//Search tutors by overall performance rating
void searchByRating()
{
	double searchRate;
	do {
		sortTutorName();
		cout << "Enter a Tutor Performance Rating (-1 exit to main menu): ";
		cin >> searchRate;
		while (cin.fail() || searchRate < -1 || searchRate > 5) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Enter a Tutor Performance Rating (-1 exit to main menu): ";
			cin >> searchRate;
		}
		bool find = false;
		if (searchRate != -1) {
			system("CLS");
			int no = 1;
			cout << endl << string(120, '-') << endl;
			cout << left << setw(5) << "No." << setw(15) << "Tutor ID" << setw(20) << "Name" << setw(20) << "Tuition"
				<< setw(25) << "Subject" << setw(25) << "Hourly Pay Rate(RM)" << setw(20) << "Rating" << endl;
			cout << string(120, '-') << endl;
			for (int i = 0; i < TutorSize; i++)
			{
				searchRate = round(searchRate * 10.0) / 10.0;
				double Rating = round((tutorlist[i]->rating[0] / tutorlist[i]->rating[1]) * 10.0) / 10.0;
				if (loginAdmin->location == "Bukit Jalil") {
					if (Rating == searchRate) {
						find = true;
						cout << left << setw(5) << no << setw(15) << tutorlist[i]->tutorID << setw(20) << tutorlist[i]->name << setw(20)
							<< tutorlist[i]->tuitionCenterName << setw(25) << tutorlist[i]->subjectName << setw(25) << fixed << setprecision(2)
							<< tutorlist[i]->hourlyPayRate << setw(20) << setprecision(1) << tutorlist[i]->rating[0] / tutorlist[i]->rating[1] << endl;
						no++;
					}
				}
				else {
					if (Rating == searchRate && tutorlist[i]->tuitionCenterName == loginAdmin->location) {
						find = true;
						cout << left << setw(5) << no << setw(15) << tutorlist[i]->tutorID << setw(20) << tutorlist[i]->name << setw(20)
							<< tutorlist[i]->tuitionCenterName << setw(25) << tutorlist[i]->subjectName << setw(25) << fixed << setprecision(2)
							<< tutorlist[i]->hourlyPayRate << setw(20) << setprecision(1) << tutorlist[i]->rating[0] / tutorlist[i]->rating[1] << endl;
						no++;
					}
				}
			}
			cout << endl;
			if (!find) {
				cout << "No record match! " << endl << endl;
			}
		}
	} while (searchRate != -1);
	system("CLS");
}


//add record function
// tutor
void addTutor()
{
	int select;
	string tname, tcode;
	int num = 0;
	string tuitionCode[10] = {};
	string tuitionName[10] = {};
	for (int i = 0; i < TuitionSize; i++)
	{
		tuitionCode[num] = tuitionlist[i]->code;
		tuitionName[num] = tuitionlist[i]->name;
		num++;
	}
	int SJnum = 0;
	string SJCode[20] = {};
	string SJName[20] = {};
	for (int i = 0; i < SubjectSize; i++)
	{
		SJCode[SJnum] = subjectlist[i]->code;
		SJName[SJnum] = subjectlist[i]->name;
		SJnum++;
	}
	do {
		if (loginAdmin->location == "Bukit Jalil") {
			cout << "Select the tutor's tuition to add: " << endl;
			for (int i = 0; i < num; i++) {
				cout << "\t[" << i + 1 << "] " << tuitionName[i] << endl;
			}
			cout << "Enter the number of tuition: ";
			cin >> select;
			while (cin.fail() || select < 0 || select > num) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Enter the number of tuition: ";
				cin >> select;
			}
			tcode = tuitionCode[select - 1];
			tname = tuitionName[select - 1];
		}
		else {
			tname = loginAdmin->location;
			for (int i = 0; i < sizeof(tuitionName) / sizeof(tuitionName[0]); i++) {
				if (tuitionName[i] == tname) {
					tcode = tuitionCode[i];
					break;
				}
			}
		}
		int tutorNum = 0;
		for (int i = 0; i < TutorSize; i++)
		{
			if (tutorlist[i]->tuitionCenterCode == tcode && tutorlist[i]->dateTerminated != "-")
			{
				tutorNum++;
			}
		}
		if (tutorNum == 10) {
			cout << "The existing tutor in " << tname << " have reach a maximum of 10! No able to add tutor record!" << endl;
			break;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("CLS");
		string TutorID, id, Name, DoB, Date_Joined, Date_Terminated, Phone, Address, Specialize, Subject_Code, Subject_Name;
		char Gender;
		int Age = 0;
		double Hourly_Pay_Rate, Rating[2] = { 0, 1 };
		sortTutorID();
		cout << "Please enter the following tutor information: " << endl << endl;
		for (int i = 1; i < 5; i++) {
			if (tutorlist[TutorSize]->tutorID[i] != 0) {
				id = to_string(stoi(tutorlist[TutorSize]->tutorID.substr(i)) + 1);
				TutorID = "T" + string((4 - id.length()), '0') + id;
				break;
			}
		}
		cout << left << setw(28) << "-Name" << ": ";
		getline(cin, Name);
		cout << setw(28) << "-Date of Birth (DD/MM/YYYY)" << ": ";
		getline(cin, DoB);
		if (DoB != "") {
			bool digit = true;
			for (int i = DoB.size() - 4; i < DoB.size(); i++) {
				if (isdigit(DoB[i]) == false) {
					digit = false;
					break;
				}
			}
			if (digit) {
				time_t now = time(NULL);
				tm* ltm = localtime(&now);
				Age = 1900 + ltm->tm_year - stoi((DoB.substr(DoB.length() - 4)));
			}
		}
		cout << setw(28) << "-Gender (M/F)" << ": ";
		cin >> Gender;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << setw(28) << "-Date Joined (DD/MM/YYYY)" << ": ";
		getline(cin, Date_Joined);
		Date_Terminated = "-";
		cout << setw(28) << "-Hourly Pay Rate (40 - 80)" << ": RM ";
		cin >> Hourly_Pay_Rate;
		while (cin.fail() || Hourly_Pay_Rate < 40 || Hourly_Pay_Rate > 80) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "-Hourly Pay Rate (40 - 80)" << ": RM ";
			cin >> Hourly_Pay_Rate;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << setw(28) << "-Phone" << ": ";
		getline(cin, Phone);
		cout << setw(28) << "-Address" << ": ";
		getline(cin, Address);
		cout << setw(28) << "-Specialized Field" << ": ";
		getline(cin, Specialize);
		cout << setw(28) << "-Subject" << ": " << "[1]" << SJName[0] << endl;
		for (int i = 1; SJName[i] != "\0"; i++) {
			cout << string(30, ' ') << "[" << i + 1 << "] " << SJName[i] << endl;
		}
		cout << "Enter the tutor subject code number: ";
		cin >> select;
		while (cin.fail() || select < 0 || select > SJnum) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Enter the tutor subject code number: ";
			cin >> select;
		}
		Subject_Code = SJCode[select - 1];
		Subject_Name = SJName[select - 1];
		cout << endl << "Comfirm to add the record? 1 for YES, 0 for NO: ";
		cin >> select;
		while (cin.fail() || select < 0 || select > 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Comfirm to add the record? 1 for YES, 0 for NO: ";
			cin >> select;
		}
		if (select == 1) {
			Tutor* newTutor = CreateNewTutor(TutorID, Name, DoB, Age, Gender, Date_Joined, Date_Terminated, Hourly_Pay_Rate,
				Phone, Address, Specialize, tcode, tname, Subject_Code, Subject_Name, Rating);
			insertIntoEndofTutorList(newTutor);
			cout << "Record add secussful!" << endl;
		}
		else {
			cout << "Record cancel to add" << endl;
		}
		cout << endl << "Do you want to continue to add? 1 for YES, 0 exit to main menu: ";
		cin >> select;
		while (cin.fail() || select < 0 || select > 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Do you want to continue to add? 1 for YES, 0 exit to main menu: ";
			cin >> select;
		}
	} while (select != 0);
	system("CLS");
}
//student
void addStudent()
{
	int select;
	string tname, tcode;
	int num = 0;
	string tuitionCode[10] = {};
	string tuitionName[10] = {};
	for (int i = 0; i < TuitionSize; i++)
	{
		tuitionCode[num] = tuitionlist[i]->code;
		tuitionName[num] = tuitionlist[i]->name;
		num++;
	}
	int SJnum = 0;
	string SJCode[20] = {};
	string SJName[20] = {};
	for (int i = 0; i < SubjectSize; i++)
	{
		SJCode[SJnum] = subjectlist[i]->code;
		SJName[SJnum] = subjectlist[i]->name;
		SJnum++;
	}
	do {
		if (loginAdmin->location == "Bukit Jalil") {
			cout << "Select the tutor's tuition to add: " << endl;
			for (int i = 0; i < num; i++) {
				cout << "\t[" << i + 1 << "] " << tuitionName[i] << endl;
			}
			cout << "Enter the number of tuition: ";
			cin >> select;
			while (cin.fail() || select < 0 || select > num) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Enter the number of tuition: ";
				cin >> select;
			}
			tcode = tuitionCode[select - 1];
			tname = tuitionName[select - 1];
		}
		else {
			tname = loginAdmin->location;
			for (int i = 0; i < sizeof(tuitionName) / sizeof(tuitionName[0]); i++) {
				if (tuitionName[i] == tname) {
					tcode = tuitionCode[i];
					break;
				}
			}
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("CLS");
		string StudentID, id, Password, Name, DoB, Phone, Address, Subject[10];
		char Gender;
		int Age = 0;
		cout << "Please enter the following student information: " << endl << endl;
		string lastID = "0";
		for (int i = 0; i < StudentSize; i++)
		{
			if (studentlist[i]->studentID > lastID)
			{
				lastID = studentlist[i]->studentID;
			}
		}
		for (int i = 1; i < 6; i++) {
			if (lastID[i] != 0) {
				id = to_string(stoi(lastID.substr(i)) + 1);
				StudentID = "S" + string((5 - id.length()), '0') + id;
				break;
			}
		}
		cout << left << setw(28) << "-Name" << ": ";
		getline(cin, Name);
		cout << left << setw(28) << "-Password" << ": ";
		getline(cin, Password);
		cout << setw(28) << "-Date of Birth (DD/MM/YYYY)" << ": ";
		getline(cin, DoB);
		if (DoB != "") {
			bool digit = true;
			for (int i = DoB.size() - 4; i < DoB.size(); i++) {
				if (isdigit(DoB[i]) == false) {
					digit = false;
					break;
				}
			}
			if (digit) {
				time_t now = time(NULL);
				tm* ltm = localtime(&now);
				Age = 1900 + ltm->tm_year - stoi((DoB.substr(DoB.length() - 4)));
			}
		}
		cout << setw(28) << "-Gender (M/F)" << ": ";
		cin >> Gender;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << setw(28) << "-Phone" << ": ";
		getline(cin, Phone);
		cout << setw(28) << "-Address" << ": ";
		getline(cin, Address);
		cout << setw(28) << "-Subject" << ": " << "[1]" << SJName[0] << endl;
		for (int i = 1; SJName[i] != "\0"; i++) {
			cout << string(30, ' ') << "[" << i + 1 << "] " << SJName[i] << endl;
		}
		cout << "Enter the number of subject to add (max 10): ";
		cin >> select;
		while (cin.fail() || select < 1 || select > 10) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Enter the number of subject to add (max 10): ";
			cin >> select;
		}
		int subjectNum = select;
		for (int i = 0; i < subjectNum; i++) {
			cout << "Subject " << i + 1 << ": ";
			cin >> select;
			while (cin.fail() || select < 1 || select > SJnum) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Subject " << i + 1 << ": ";
				cin >> select;
			}
			Subject[i] = SJCode[select - 1];
		}
		cout << endl << "Comfirm to add the record? 1 for YES, 0 for NO: ";
		cin >> select;
		while (cin.fail() || select < 0 || select > 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Comfirm to add the record? 1 for YES, 0 for NO: ";
			cin >> select;
		}
		if (select == 1) {
			Student* newStudent = CreateNewStudent(StudentID, Password, Name, DoB, Age, Gender,
				Phone, Address, tcode, tname, Subject);
			insertIntoSortedStudent(newStudent);
			cout << "Record add secussful!" << endl;
		}
		else {
			cout << "Record cancel to add" << endl;
		}
		cout << endl << "Do you want to continue to add? 1 for YES, 0 exit to main menu: ";
		cin >> select;
		while (cin.fail() || select < 0 || select > 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Do you want to continue to add? 1 for YES, 0 exit to main menu: ";
			cin >> select;
		}
	} while (select != 0);
	system("CLS");
}
//admin
void addAdmin()
{
	int select;
	do {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("CLS");
		string username, Password, position, location;
		cout << "Please enter the following admin information: " << endl << endl;
		cout << left << setw(20) << "-User Name" << ": ";
		getline(cin, username);
		cout << left << setw(20) << "-Password" << ": ";
		getline(cin, Password);
		cout << setw(20) << "-Position" << ": ";
		getline(cin, position);
		cout << setw(20) << "-Location" << ": ";
		getline(cin, location);
		cout << endl << "Comfirm to add the record? 1 for YES, 0 for NO: ";
		cin >> select;
		while (cin.fail() || select < 0 || select > 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Comfirm to add the record? 1 for YES, 0 for NO: ";
			cin >> select;
		}
		if (select == 1) {
			Admin* newAdmin = CreateNewAdmin(username, Password, position, location);
			insertIntoSortedAdmin(newAdmin);
			cout << "Record add secussful!" << endl;
		}
		else {
			cout << "Record cancel to add" << endl;
		}
		cout << endl << "Do you want to continue to add? 1 for YES, 0 exit to main menu: ";
		cin >> select;
		while (cin.fail() || select < 0 || select > 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Do you want to continue to add? 1 for YES, 0 exit to main menu: ";
			cin >> select;
		}
	} while (select != 0);
	system("CLS");
}
//tuition
void addTuition()
{
	int select;
	int num = 0;
	string tuitionCode[10] = {};
	string tuitionName[10] = {};
	for (int i = 0; i < TutorSize; i++)
	{
		tuitionCode[num] = tuitionlist[i]->code;
		tuitionName[num] = tuitionlist[i]->name;
		num++;
	}
	do {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("CLS");
		string code, name;
		cout << "Please enter the following admin information: " << endl << endl;
		cout << left << setw(20) << "-Tuition Code" << ": ";
		getline(cin, code);
		while (true) {
			bool find = false;
			for (int i = 0; i < num; i++) {
				if (tuitionCode[i] == code) {
					find = true;
					break;
				}
			}
			if (!find) {
				break;
			}
			cout << "Code exist! Enter new code" << endl;
			cout << left << setw(20) << "-Tuition Code" << ": ";
			getline(cin, code);
		}
		cout << left << setw(20) << "-Tuition Name" << ": ";
		getline(cin, name);
		while (true) {
			bool find = false;
			for (int i = 0; i < num; i++) {
				if (tuitionName[i] == name) {
					find = true;
					break;
				}
			}
			if (!find) {
				break;
			}
			cout << "Name exist! Enter new name" << endl;
			cout << left << setw(20) << "-Tuition Name" << ": ";
			getline(cin, name);
		}
		cout << endl << "Comfirm to add the record? 1 for YES, 0 for NO: ";
		cin >> select;
		while (cin.fail() || select < 0 || select > 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Comfirm to add the record? 1 for YES, 0 for NO: ";
			cin >> select;
		}
		if (select == 1) {
			Tuition* newTuition = CreateNewTuition(code, name);
			insertIntoSortedTuition(newTuition);
			cout << "Record add secussful!" << endl;
		}
		else {
			cout << "Record cancel to add" << endl;
		}
		cout << endl << "Do you want to continue to add? 1 for YES, 0 exit to main menu: ";
		cin >> select;
		while (cin.fail() || select < 0 || select > 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Do you want to continue to add? 1 for YES, 0 exit to main menu: ";
			cin >> select;
		}
	} while (select != 0);
	system("CLS");
}
//subject
void addSubject()
{
	int select;
	int SJnum = 0;
	string SJCode[20] = {};
	string SJName[20] = {};
	for (int i = 0; i < SubjectSize; i++)
	{
		SJCode[SJnum] = subjectlist[i]->code;
		SJName[SJnum] = subjectlist[i]->name;
		SJnum++;
	}
	do {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("CLS");
		string code, name;
		cout << "Please enter the following subject information: " << endl << endl;
		cout << left << setw(20) << "-Subject Code" << ": ";
		getline(cin, code);
		while (true) {
			bool find = false;
			for (int i = 0; i < SJnum; i++) {
				if (SJCode[i] == code) {
					find = true;
					break;
				}
			}
			if (!find) {
				break;
			}
			cout << "Code exist! Enter new code" << endl;
			cout << left << setw(20) << "-Subject Code" << ": ";
			getline(cin, code);
		}
		cout << left << setw(20) << "-Subject Name" << ": ";
		getline(cin, name);
		while (true) {
			bool find = false;
			for (int i = 0; i < SJnum; i++) {
				if (SJName[i] == name) {
					find = true;
					break;
				}
			}
			if (!find) {
				break;
			}
			cout << "Subject exist! Enter new subject" << endl;
			cout << left << setw(20) << "-Subject Name" << ": ";
			getline(cin, name);
		}
		cout << endl << "Comfirm to add the record? 1 for YES, 0 for NO: ";
		cin >> select;
		while (cin.fail() || select < 0 || select > 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Comfirm to add the record? 1 for YES, 0 for NO: ";
			cin >> select;
		}
		if (select == 1) {
			Subject* newSubject = CreateNewSubject(code, name);
			insertIntoSortedSubject(newSubject);
			cout << "Record add secussful!" << endl;
		}
		else {
			cout << "Record cancel to add" << endl;
		}
		cout << endl << "Do you want to continue to add? 1 for YES, 0 exit to main menu: ";
		cin >> select;
		while (cin.fail() || select < 0 || select > 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Do you want to continue to add? 1 for YES, 0 exit to main menu: ";
			cin >> select;
		}
	} while (select != 0);
	system("CLS");
}


//modify record 
//tutor
void modifyTutor()
{
	sortTutorName();
	int select;
	do {
		system("CLS");
		cout << "Modify tutor record" << endl << endl;
		int no = 0;
		cout << string(140, '-') << endl;
		cout << left << setw(5) << "No." << setw(15) << "Tutor ID" << setw(20) << "Name" << setw(20) << "Tuition"
			<< setw(20) << "Date Terminated" << setw(25) << "Phone" << "Address" << endl;
		cout << string(140, '-') << endl;
		for (int i = 0; i < TutorSize; i++)
		{
			no++;
			cout << left << setw(5) << no << setw(15) << tutorlist[i]->tutorID << setw(20) << tutorlist[i]->name << setw(20) << tutorlist[i]->tuitionCenterName
				<< setw(20) << tutorlist[i]->dateTerminated << setw(25) << tutorlist[i]->phone << tutorlist[i]->address << endl;
		}
		cout << endl << "Select the number of tutor to modify (0 exit to main menu): ";
		cin >> select;
		while (cin.fail() || select < -1 || select > no) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Select the number of tutor to modify (0 exit to main menu): ";
			cin >> select;
		}
		if (select != 0) {
			int i;
			int position = 0;
			for ( i = 0; i < TutorSize; i++)
			{
				position++;
				if (position == select)
				{
					break;
				}
			}
			cout << endl << "Select the record to modify: " << endl << "\t[1] Phone" << endl << "\t[2] Address"
				<< endl << "\t[3] Date Terminated" << endl;
			cout << "Enter your selection: ";
			cin >> select;
			while (cin.fail() || select < 1 || select > 3) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Enter your selection: ";
				cin >> select;
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			string newData;
			if (select == 1) {
				cout << endl << endl << "Enter new phone no. : ";
				getline(cin, newData);
				tutorlist[i]->phone = newData;
			}
			else if (select == 2) {
				cout << endl << endl << "Enter new address : ";
				getline(cin, newData);
				tutorlist[i]->address = newData;
			}
			else {
				cout << endl << endl << "Enter Teminated Date (DD/MM/YYYY): ";
				getline(cin, newData);
				tutorlist[i]->dateTerminated = newData;
			}
			cout << "Modify done!" << endl;
			cout << endl << "Do you want to continue modify other? 1 for YES, 0 exit to main menu: ";
			cin >> select;
			while (cin.fail() || select < 0 || select > 1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Do you want to continue to modify other? 1 for YES, 0 exit to main menu: ";
				cin >> select;
			}
		}
	} while (select != 0);
	system("CLS");
}
//student
void modifyStudent()
{
	int select;
	string tname = "";
	do {
		system("CLS");
		if (loginAdmin->location != "Bukit Jalil") {
			tname = loginAdmin->location;
		}
		int no = 0;
		cout << string(100, '-') << endl;
		cout << left << setw(5) << "No." << setw(15) << "Student ID" << setw(20) << "Name" << setw(20) << "Phone"
			<< setw(25) << "Tuition" << setw(25) << "Subject" << endl;
		cout << string(100, '-') << endl;
		if (tname == "") {
			for (int i = 0; i < StudentSize; i++)
			{
				no++;
				cout << left << setw(5) << no << setw(15) << studentlist[i]->studentID << setw(20) << studentlist[i]->name << setw(20)
					<< studentlist[i]->phone << setw(25) << studentlist[i]->tuitionCenterName;
				for (int j = 0; j < sizeof(studentlist[i]->subject) / sizeof(studentlist[i]->subject[0]); i++)
				{
					if (studentlist[i]->subject[j] != "\0")
					{
						cout << studentlist[i] << ", ";
					}
				}
				cout << endl;
			}
		}
		else {
			for (int i = 0; i < StudentSize; i++)
			{
				if (studentlist[i]->tuitionCenterName == tname)
				{
					no++;
					cout << left << setw(5) << no << setw(15) << studentlist[i]->studentID << setw(20) << studentlist[i]->name << setw(20)
						<< studentlist[i]->phone << setw(25) << studentlist[i]->tuitionCenterName;
					for (int j = 0; j < sizeof(studentlist[i]->subject) / sizeof(studentlist[i]->subject[0]); i++)
					{
						if (studentlist[i]->subject[j] != "\0")
						{
							cout << studentlist[i]->subject[j] << ", ";
						}
					}
				}
			}
		}
		cout << endl << "Select the number of student to modify (0 exit to main menu): ";
		cin >> select;
		while (cin.fail() || select < -1 || select > no) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Select the number of tutor to modify (0 exit to main menu): ";
			cin >> select;
		}
		if (select != 0) {
			int i;
			int position = 0;
			if (tname == "") {
				for (i = 0; i < StudentSize; i++)
				{
					position++;
					if (position == select)
					{
						break;
					}
				}
			}
			else {
				for (int i = 0; i < StudentSize; i++)
				{
					if (studentlist[i]->tuitionCenterName == tname)
					{
						position++;
						if (position == select)
						{
							break;
						}
					}
				}
			}
			cout << endl << "Select the record to modify: " << endl << "\t[1] Phone" << endl << "\t[2] Address"
				<< endl << "\t[3] Tuition Center" << endl << "\t[4] New Subject List" << endl;
			cout << "Enter your selection: ";
			cin >> select;
			while (cin.fail() || select < 1 || select > 4) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Enter your selection: ";
				cin >> select;
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			string newData;
			if (select == 1) {
				cout << endl << endl << "Enter new phone no. : ";
				getline(cin, newData);
				studentlist[i]->phone = newData;
			}
			else if (select == 2) {
				cout << endl << endl << "Enter new address : ";
				getline(cin, newData);
				studentlist[i]->address = newData;
			}
			else if (select == 3) {
				cout << endl << endl << "Tuition: " << endl;;
				int no = 1;
				for (int j = 0; j < TuitionSize; j++)
				{
					cout << "\t[" << no << "] " << tuitionlist[j]->name << endl;
					no++;
				}
				cout << "Enter new tuition number: ";
				cin >> select;
				while (cin.fail() || select < 1 || select > TuitionSize) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid Input!" << endl;
					cout << "Enter new tuition number: ";
					cin >> select;
				}
				studentlist[i]->tuitionCenterCode = tuitionlist[select-1]->code;
				studentlist[i]->tuitionCenterName = tuitionlist[select-1]->name;
			}
			else {
				int SJnum = 0;
				string SJCode[20] = {};
				string SJName[20] = {};
				for (int k = 0; k < SubjectSize; k++)
				{
					SJCode[SJnum] = subjectlist[k]->code;
					SJName[SJnum] = subjectlist[k]->name;
					SJnum++;
				}
				cout << "Subject" << ": " << "[1]" << SJName[0] << endl;
				for (int i = 1; SJName[i] != "\0"; i++) {
					cout << string(10, ' ') << "[" << i + 1 << "] " << SJName[i] << endl;
				}
				cout << endl << "Enter the number of subject (max 10): ";
				cin >> select;
				while (cin.fail() || select < 1 || select > 10) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid Input!" << endl;
					cout << "Enter the number of subject to add (max 10): ";
					cin >> select;
				}
				int subjectNum = select;
				string newlist[10];
				for (int i = 0; i < subjectNum; i++) {
					cout << "Subject " << i + 1 << ": ";
					cin >> select;
					while (cin.fail() || select < 1 || select > SJnum) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid Input!" << endl;
						cout << "Subject " << i + 1 << ": ";
						cin >> select;
					}
					newlist[i] = SJCode[select - 1];
				}
				for (int k = 0; k < 10; k++) {
					studentlist[i]->subject[k] = newlist[k];
				}
			}
			cout << "Modify done!" << endl;
			cout << endl << "Do you want to continue modify other? 1 for YES, 0 exit to main menu: ";
			cin >> select;
			while (cin.fail() || select < 0 || select > 1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Do you want to continue to modify other? 1 for YES, 0 exit to main menu: ";
				cin >> select;
			}
		}
	} while (select != 0);
	system("CLS");
}
//admin
void modifyAdmin()
{
	sortTutorName();
	int select;
	do {
		system("CLS");
		cout << "Modify Admin record" << endl << endl;
		displayAdmin();
		cout << endl << "Select the number of admin to modify location (0 exit to main menu): ";
		cin >> select;
		while (cin.fail() || select < -1 || select > AdminSize) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Select the number of admin to modify location (0 exit to main menu): ";
			cin >> select;
		}
		if (select != 0) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			string newData;
			int i;
			int position = 0;
			for (i = 0; i < AdminSize; i++)
			{
				position++;
				if (position == select)
				{
					break;
				}
			}
			if (adminlist[i]->position != "Manager")
			{
				cout << endl << endl << "Enter new location : ";
				getline(cin, newData);
				adminlist[i]->location = newData;
				cout << "Modify done!" << endl;
			}
			else {
				cout << endl << "Manager record no allow to modify!" << endl;
			}
			cout << endl << "Do you want to continue modify other? 1 for YES, 0 exit to main menu: ";
			cin >> select;
			while (cin.fail() || select < 0 || select > 1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Do you want to continue to modify other? 1 for YES, 0 exit to main menu: ";
				cin >> select;
			}
		}
	} while (select != 0);
	system("CLS");
}


//to calculate the days between two dates
int calculateDays(Tutor* tutor)
{
	int first = tutor->dateTerminated.find("/");
	int second = tutor->dateTerminated.find("/", first + 1);

	int day = stoi(tutor->dateTerminated.substr(0, first));
	int month = stoi(tutor->dateTerminated.substr(first + 1, second - first - 1));
	int year = stoi(tutor->dateTerminated.substr(tutor->dateTerminated.length() - 4));

	int days = 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + day - 306;

	time_t theTime = time(NULL);
	struct tm* aTime = localtime(&theTime);

	int Cday = aTime->tm_mday;
	int Cmonth = aTime->tm_mon + 1;
	int Cyear = aTime->tm_year + 1900;

	int Cdays = 365 * Cyear + Cyear / 4 - Cyear / 100 + Cyear / 400 + (153 * Cmonth - 457) / 5 + Cday - 306;

	return (Cdays - days);
}

//delete record
//tutor
void deleteTutor()
{
	//sort tutor record by tutor name
	sortTutorName();
	int select;
	do {
		system("CLS");
		int No = 0;
		cout << string(80, '-') << endl;
		cout << left << setw(5) << "No." << setw(15) << "Tutor ID" << setw(20) << "Name" << setw(20) << "Date Terminated"
			<< setw(25) << "Tuition Center" << endl;
		cout << string(80, '-') << endl;
		//display tutor record with terminated date more than 6 month
		for (int i = 0; i < TutorSize; i++)
		{
			//to get the terminated totur record
			if (tutorlist[i]->dateTerminated != "-") {
				//calculate the duration of terminated date
				int days = calculateDays(tutorlist[i]);
				//check the terminated tutor record is more than 6 month (182.5 day) 
				if (days > 182.5) {
					//display the deletable tutor record
					No++;
					cout << left << setw(5) << No << setw(15) << tutorlist[i]->tutorID << setw(20) << tutorlist[i]->name << setw(20)
						<< tutorlist[i]->dateTerminated << setw(25) << tutorlist[i]->tuitionCenterName << endl;
				}
			}
		}
		//no deletable record found
		if (No == 0) {
			cout << "No record of terminated tutor more than 6 month to delete!" << endl;
		}
		//has deletable record
		else {
			//prompt to select the tutor record to delete
			cout << endl << "Select the number of tutor to delete (0 exit to main menu): ";
			cin >> select;
			while (cin.fail() || select < -1 || select > No) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Select the number of tutor to delete (0 exit to main menu): ";
				cin >> select;
			}
			if (select != 0) {
				int position = 0;
				int showListPosition = 0;
				//get the actually position of the selected record in the tutor record
				for (int i = 0; i < TutorSize; i++)
				{
					position++;
					if (tutorlist[i]->dateTerminated != "-") {
						int days = calculateDays(tutorlist[i]);
						if (days > 182.5) {
							showListPosition++;
							if (showListPosition == select) {
								select = position;
								break;
							}
						}
					}
				}

				//delete the specific position tutor record
				Tutor* current = NULL;
				//scenario 1: list is empty?
				if (TutorSize == 0) {
					cout << "Empty List! No deletion needed! " << endl;
				}
				//scenario 2: list is position 1
				else {
					cout << "The tutor of " << tutorlist[select - 1]->tutorID << " is deleted now!" << endl;
					delete tutorlist[select - 1];
					for (int i = select - 1; i < TutorSize - 1; i++)
					{
						tutorlist[i] = tutorlist[i + 1];
					}
					delete tutorlist[TutorSize];
					TutorSize--;
				}
			}
		}
		cout << endl << "Do you want to continue delete other? 1 for YES, 0 exit to main menu: ";
		cin >> select;
		while (cin.fail() || select < 0 || select > 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Do you want to continue to delete other? 1 for YES, 0 exit to main menu: ";
			cin >> select;
		}
		system("CLS");
	} while (select != 0);
}
//student
void deleteStudent()
{
	int select;
	string tname = "";	//no specific tuition name
	do {
		system("CLS");
		//the admin is not from the headquater
		if (loginAdmin->location != "Bukit Jalil") {
			//specify the tuition name with the admin location
			tname = loginAdmin->location;
		}
		int No = 0;
		cout << string(100, '-') << endl;
		cout << left << setw(5) << "No." << setw(15) << "Student ID" << setw(20) << "Name" << setw(20) << "Phone"
			<< setw(25) << "Tuition" << setw(25) << "Subject" << endl;
		cout << string(100, '-') << endl;
		//the tuition name is no specific
		//display all the student record
		if (tname == "") {
			for (int i = 0; i < StudentSize; i++)
			{
				No++;
				cout << left << setw(5) << No << setw(15) << studentlist[i]->studentID << setw(20) << studentlist[i]->name << setw(20)
					<< studentlist[i]->phone << setw(25) << studentlist[i]->tuitionCenterName;
				for (int j = 0; j < sizeof(studentlist[i]->subject) / sizeof(studentlist[i]->subject[0]); j++) {
					if (studentlist[i]->subject[j] != "\0") {
						cout << studentlist[i]->subject[j] << ", ";
					}
				}
				cout << endl;
			}
		}
		//display the specific tuition student record
		else {
			for (int i = 0; i < StudentSize; i++)
			{
				if (studentlist[i]->tuitionCenterName == tname)
				{
					No++;
					cout << left << setw(5) << No << setw(15) << studentlist[i]->studentID << setw(20) << studentlist[i]->name << setw(20)
						<< studentlist[i]->phone << setw(25) << studentlist[i]->tuitionCenterName;
					for (int j = 0; j < sizeof(studentlist[i]->subject) / sizeof(studentlist[i]->subject[0]); j++) {
						if (studentlist[i]->subject[i] != "\0") {
							cout << studentlist[i]->subject[j] << ", ";
						}
					}
					cout << endl;
				}
			}
		}
		//select the student record to delete
		cout << endl << "Select the number of student to delete (0 exit to main menu): ";
		cin >> select;
		while (cin.fail() || select < -1 || select > No) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Select the number of student to delete (0 exit to main menu): ";
			cin >> select;
		}
		if (select != 0) {
			int i;
			int position = 0;
			int no = 0;
			//get the actual position of the selected student in the specific tuition
			if (tname != "") {
				for (i = 0; i < StudentSize; i++)
				{
					position++;
					if (studentlist[i]->tuitionCenterName == tname) {
						no++;
						if (no == select) {
							select = position;
							break;
						}
					}
				}
			}
			//delete student record from a specific position
			//scenario 1: list is empty?
			if (StudentSize == 0) {
				cout << "Empty List! No deletion needed! " << endl;
			}
			//scenario 2: list is position 1
			else {
				cout << "The student of " << studentlist[select - 1]->studentID << " is deleted now!" << endl;
				delete studentlist[select - 1];
				for (int i = select - 1; i < StudentSize - 1; i++)
				{
					studentlist[i] = studentlist[i + 1];
				}
				delete studentlist[StudentSize];
				StudentSize--;
			}
			cout << endl << "Do you want to continue delete other? 1 for YES, 0 exit to main menu: ";
			cin >> select;
			while (cin.fail() || select < 0 || select > 1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Do you want to continue to delete other? 1 for YES, 0 exit to main menu: ";
				cin >> select;
			}
		}
	} while (select != 0);
	system("CLS");
}
//admin
void deleteAdmin()
{
	system("CLS");
	int select;
	do {
		//display all admin record
		displayAdmin();
		//select the number of admin to delete
		cout << endl << "Select the number of admin to delete (0 exit to main menu): ";
		cin >> select;
		while (cin.fail() || select < -1 || select > AdminSize) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Select the number of tuition to delete (0 exit to main menu): ";
			cin >> select;
		}
		bool manager = false;
		if (select != 0) {
			int position = 0;
			//check the selected record is manager record
			for (int i = 0; i < AdminSize; i++)
			{
				position++;
				if (position = select)
				{
					if (adminlist[i]->position == "Manager")
					{
						cout << "Manager Record cannot delete!" << endl;
						manager = true;
						break;
					}
					break;
				}
			}
			//the select record is not manager record
			if (!manager) {
				//delete admin record from a specific position
				if (AdminSize == 0) {
					cout << "Empty List! No deletion needed! " << endl;
				}
				//scenario 2: list is position 1
				else {
					cout << "The admin of " << adminlist[select - 1]->username << " is deleted now!" << endl;
					delete adminlist[select - 1];
					for (int i = select - 1; i < AdminSize - 1; i++)
					{
						adminlist[i] = adminlist[i + 1];
					}
					delete adminlist[AdminSize];
					AdminSize--;
				}
				cout << endl << "Do you want to continue delete other? 1 for YES, 0 exit to main menu: ";
				cin >> select;
				while (cin.fail() || select < 0 || select > 1) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid Input!" << endl;
					cout << "Do you want to continue to delete other? 1 for YES, 0 exit to main menu: ";
					cin >> select;
				}
			}
		}
		system("CLS");
	} while (select != 0);
}
//tuition
void deleteTuition()
{
	system("CLS");
	int select;
	do {
		//display all tuition record
		displayTuition();
		//prompt to select the tuition to delete
		cout << endl << "Select the number of tuition to delete (0 exit to main menu): ";
		cin >> select;
		while (cin.fail() || select < -1 || select > TuitionSize) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Select the number of tuition to delete (0 exit to main menu): ";
			cin >> select;
		}
		if (select != 0) {
			//delete tuition record from specific position
			//scenario 1: list is empty?
			if (TuitionSize == 0) {
				cout << "Empty List! No deletion needed! " << endl;
			}
			//scenario 2: list is position 1
			else {
				cout << "The tuition of " << tuitionlist[select - 1]->code << " is deleted now!" << endl;
				delete tuitionlist[select - 1];
				for (int i = select - 1; i < SubjectSize - 1; i++)
				{
					tuitionlist[i] = tuitionlist[i + 1];
				}
				delete tuitionlist[TuitionSize];
				TuitionSize--;
			}
			cout << endl << "Do you want to continue delete other? 1 for YES, 0 exit to main menu: ";
			cin >> select;
			while (cin.fail() || select < 0 || select > 1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Do you want to continue to delete other? 1 for YES, 0 exit to main menu: ";
				cin >> select;
			}
		}
		system("CLS");
	} while (select != 0);
}
//subject
void deleteSubject()
{
	system("CLS");
	int select;
	do {
		displaySubject();
		cout << endl << "Select the number of subject to delete (0 exit to main menu): ";
		cin >> select;
		while (cin.fail() || select < -1 || select > SubjectSize) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Select the number of subject to delete (0 exit to main menu): ";
			cin >> select;
		}
		if (select != 0) {
			//scenario 1: list is empty?
			if (SubjectSize == 0) {
				cout << "Empty List! No deletion needed! " << endl;
			}
			//scenario 2: list is position 1
			else {
				cout << "The subject of " << subjectlist[select-1]->code << " is deleted now!" << endl;
				delete subjectlist[select-1];
				for (int i = select-1; i < SubjectSize-1; i++)
				{
					subjectlist[i] = subjectlist[i+1];
				}
				delete subjectlist[SubjectSize];
				SubjectSize--;
			}
			cout << endl << "Do you want to continue delete other? 1 for YES, 0 exit to main menu: ";
			cin >> select;
			while (cin.fail() || select < 0 || select > 1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Do you want to continue to delete other? 1 for YES, 0 exit to main menu: ";
				cin >> select;
			}
		}
		system("CLS");
	} while (select != 0);
}


//generate report function
void report()
{
	// current date/time based on current system
	time_t now = time(0);
	// convert now to string form
	char* date = ctime(&now);

	cout << left << setw(80) << "Title - eXcel Tuition Centre Report" << "Date: " << date << endl << endl;
	sortTutorName();
	cout << string(110, '-') << endl << setw(5) << "NO." << setw(10) << "Tutor ID" << setw(28) << "Name" << setw(10) << "Gender"
		<< setw(10) << "Rating" << setw(20) << "Date Terminated" << "Tuition Center" << endl << string(110, '-') << endl;
	int i;
	for (i = 0; i < TuitionSize; i++)
	{
		int no = 0;
		int count = 0;
		for (int j = 0; j < TutorSize; j++)
		{
			if (tutorlist[j]->tuitionCenterCode == tuitionlist[i]->code)
			{
				if (tutorlist[j]->dateTerminated == "-")
				{
					count++;
				}
				no++;
				cout << setw(5) << no << setw(10) << tutorlist[j]->tutorID << setw(28) << tutorlist[j]->name << setw(10) << tutorlist[j]->gender
					<< setw(10) << fixed << setprecision(1) << tutorlist[j]->rating[0] / tutorlist[j]->rating[1] << setw(20) << tutorlist[j]->dateTerminated << tutorlist[j]->tuitionCenterName << endl;
			}
		}
		//calculate and display the available vacancy of each tuition center (each tuition maximum 10 tutor)
		cout << endl << "Tuition Name: " << setw(20) << tuitionlist[i]->name << "Available Vaccancy: " << 10 - count << endl << endl;
		cout << string(110, '-') << endl;
	}
	system("pause");
	system("CLS");
}


//user main menu function
//manager
void managerMenu()
{
	int select;
	do {
		cout << "=== Manager Main Menu ===" << endl << endl;
		cout << "Please select a function:" << endl;
		cout << "\t[1] Add Record" << endl << "\t[2] Display Record" << endl << "\t[3] Search a Tutor by Tutor ID" << endl
			<< "\t[4] Search Tutors by overall performance (Rating)" << endl << "\t[5] Sort and display by Tutors ID in ascending order" << endl
			<< "\t[6] Sort and display by Tutors Hourly Pay Rate in ascending order" << endl
			<< "\t[7] Sort and display by Tutors Overall Performance in ascending order" << endl
			<< "\t[8] Modify Record" << endl << "\t[9] Delete Record" << endl << "\t[10] Generate Report" << endl
			<< "\t[0] Logout" << endl << "\t[-1] Exit" << endl << endl;
		cout << "Enter the number of the function to access: ";
		cin >> select;
		while (cin.fail() || select < -1 || select > 10) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Enter the number of the function to access: ";
			cin >> select;
		}
		if (select == 1) {
			cout << endl << "Select a record to add: " << endl << "\t[1] Tutor" << endl << "\t[2] Student" << endl <<
				"\t[3] Admin" << endl << "\t[4] Tuition" << endl << "\t[5] Subject" << endl << endl;
			cout << "Select the number of record to add: ";
			cin >> select;
			while (cin.fail() || select < 1 || select > 5) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Select the number of record to add: ";
				cin >> select;
			}
			if (select == 1) {
				addTutor();
			}
			else if (select == 2) {
				addStudent();
			}
			else if (select == 3) {
				addAdmin();
			}
			else if (select == 4) {
				addTuition();
			}
			else {
				addSubject();
			}
		}
		else if (select == 2) {
			cout << endl << "Select a record to display: " << endl << "\t[1] Tutor" << endl << "\t[2] Student" << endl <<
				"\t[3] Tuition" << endl << "\t[4] Subject" << endl << "\t[5] Admin" << endl << endl;
			cout << "Select the number of record to display: ";
			cin >> select;
			while (cin.fail() || select < 1 || select > 5) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Select the number of record to display: ";
				cin >> select;
			}
			if (select == 1) {
				system("CLS");
				sortTutorName();
				displayTutor();
				system("CLS");
			}
			else if (select == 2) {
				system("CLS");
				displayStudent();
				system("CLS");
			}
			else if (select == 3) {
				system("CLS");
				displayTuition();
				system("pause");
				system("CLS");
			}
			else if (select == 4) {
				system("CLS");
				displaySubject();
				system("pause");
				system("CLS");
			}
			else {
				system("CLS");
				displayAdmin();
				system("pause");
				system("CLS");
			}
		}
		else if (select == 3) {
			searchByTutorID();
		}
		else if (select == 4) {
			searchByRating();
		}
		else if (select == 5) {
			system("CLS");
			cout << "Sort and display by Tutors ID in ascending order: " << endl << endl;
			sortTutorID();
			displayTutorListOnly();
			cout << endl;
			system("pause");
			system("CLS");
		}
		else if (select == 6) {
			system("CLS");
			cout << "Sort and display by Tutors Hourly Pay Rate in ascending order: " << endl << endl;
			sortTutorHourPay();
			displayTutorListOnly();
			cout << endl;
			system("pause");
			system("CLS");
		}
		else if (select == 7) {
			system("CLS");
			cout << "Sort and display by Tutors Overall Performance in ascending order: " << endl << endl;
			sortTutorRating();
			displayTutorListOnly();
			cout << endl;
			system("pause");
			system("CLS");
		}
		else if (select == 8) {
			cout << endl << "Select a record to modify: " << endl << "\t[1] Tutor" << endl << "\t[2] Student" << endl <<
				"\t[3] Admin" << endl << endl;
			cout << "Select the number of record to modify: ";
			cin >> select;
			while (cin.fail() || select < 1 || select > 3) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Select the number of record to modify: ";
				cin >> select;
			}
			if (select == 1) {
				modifyTutor();
			}
			else if (select == 2) {
				modifyStudent();
			}
			else {
				modifyAdmin();
			}
		}
		else if (select == 9) {
			cout << endl << "Select a record to delete: " << endl << "\t[1] Tutor" << endl << "\t[2] Student" << endl <<
				"\t[3] Admin" << endl << "\t[4] Tuition" << endl << "\t[5] Subject" << endl << endl;
			cout << "Select the number of record to delete: ";
			cin >> select;
			while (cin.fail() || select < 1 || select > 5) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Select the number of record to delete: ";
				cin >> select;
			}
			if (select == 1) {
				deleteTutor();
			}
			else if (select == 2) {
				deleteStudent();
			}
			else if (select == 3) {
				deleteAdmin();
			}
			else if (select == 4) {
				deleteTuition();
			}
			else {
				deleteSubject();
			}
		}
		//generate report
		else if (select == 10) {
			system("CLS");
			report();
		}
		//exit system
		else if (select == -1) {
			cout << "Are you sure want to exit entire system? ( 0 for 'NO', 1 for 'YES' ): ";
			cin >> select;
			while (cin.fail() || select < -1 || select > 2) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Are you sure want to exit entire system? ( 0 for 'NO', 1 for 'YES' ): ";
				cin >> select;
			}
			if (select == 1) {
				exit(0);
			}
			else {
				select = -1;
				system("CLS");
			}
		}
	} while (select != 0);

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
//admin
void adminMenu()
{
	int select;
	do {
		cout << "=== Admin Main Menu ===" << endl << endl;
		cout << "Please select a function:" << endl;
		cout << "\t[1] Add Record" << endl << "\t[2] Display Record" << endl << "\t[3] Search a Tutor by Tutor ID" << endl
			<< "\t[4] Search Tutors by overall performance (Rating)" << endl << "\t[5] Sort and display by Tutors ID in ascending order" << endl
			<< "\t[6] Sort and display by Tutors Hourly Pay Rate in ascending order" << endl
			<< "\t[7] Sort and display by Tutors Overall Performance in ascending order" << endl
			<< "\t[8] Modify Student Record" << endl << "\t[9] Delete Student Record" << endl << "\t[0] Logout" << endl << "\t[-1] Exit" << endl << endl;
		cout << "Enter the number of the function to access: ";
		cin >> select;
		while (cin.fail() || select < -1 || select > 9) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Enter the number of the function to access: ";
			cin >> select;
		}
		if (select == 1) {
			cout << endl << "Select a record to add: " << endl << "\t[1] Tutor" << endl << "\t[2] Student" << endl << endl;
			cout << "Select the number of record to add: ";
			cin >> select;
			while (cin.fail() || select < 1 || select > 2) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Select the number of record to add: ";
				cin >> select;
			}
			if (select == 1) {
				addTutor();
			}
			else if (select == 2) {
				addStudent();
			}
		}
		else if (select == 2) {
			cout << endl << "Select a record to display: " << endl << "\t[1] Tutor" << endl << "\t[2] Student" << endl <<
				"\t[3] Tuition" << endl << "\t[4] Subject" << endl << endl;
			cout << "Select the number of record to display: ";
			cin >> select;
			while (cin.fail() || select < 1 || select > 4) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Select the number of record to display: ";
				cin >> select;
			}
			if (select == 1) {
				system("CLS");
				sortTutorName();
				displayTutor();
				system("CLS");
			}
			else if (select == 2) {
				system("CLS");
				displayStudent();
				system("CLS");
			}
			else if (select == 3) {
				system("CLS");
				displayTuition();
				system("pause");
				system("CLS");
			}
			else {
				system("CLS");
				displaySubject();
				system("pause");
				system("CLS");
			}
		}
		else if (select == 3) {
			searchByTutorID();
		}
		else if (select == 4) {
			searchByRating();
		}
		else if (select == 5) {
			system("CLS");
			cout << "Sort and display by Tutors ID in ascending order: " << endl << endl;
			sortTutorID();
			displayTutorListOnly();
			cout << endl;
			system("pause");
			system("CLS");
		}
		else if (select == 6) {
			system("CLS");
			cout << "Sort and display by Tutors Hourly Pay Rate in ascending order: " << endl << endl;
			sortTutorHourPay();
			displayTutorListOnly();
			cout << endl;
			system("pause");
			system("CLS");
		}
		else if (select == 7) {
			system("CLS");
			cout << "Sort and display by Tutors Overall Performance in ascending order: " << endl << endl;
			sortTutorRating();
			displayTutorListOnly();
			cout << endl;
			system("pause");
			system("CLS");
		}
		else if (select == 8) {
			//modifyStudent();
		}
		else if (select == 9) {
			deleteStudent();
		}
		else if (select == -1) {
			cout << "Are you sure want to exit entire system? ( 0 for 'NO', 1 for 'YES' ): ";
			cin >> select;
			while (cin.fail() || select < -1 || select > 2) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Are you sure want to exit entire system? ( 0 for 'NO', 1 for 'YES' ): ";
				cin >> select;
			}
			if (select == 1) {
				exit(0);
			}
			else {
				select = -1;
				system("CLS");
			}
		}
	} while (select != 0);

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
//student
void studentMenu()
{
	int select;
	do {
		cout << "=== Student Main Menu ===" << endl << endl;
		cout << "Please select a function:" << endl;
		cout << "\t[1] View Profile" << endl << "\t[2] Rating" << endl << "\t[0] Logout" << endl << "\t[-1] Exit" << endl << endl;
		cout << "Enter the number of the function to access: ";
		cin >> select;
		while (cin.fail() || select < -1 || select > 2) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Enter the number of the function to access: ";
			cin >> select;
		}

		//check selection to access function
		//view profile
		if (select == 1) {
			cout << endl << "Below is your profile info: " << endl;
			cout << left << setw(20) << "-Student ID" << ": " << loginStudent->studentID << endl;
			cout << setw(20) << "-Name" << ": " << loginStudent->name << endl;
			cout << setw(20) << "-Date of Birth" << ": " << loginStudent->dob << endl;
			cout << setw(20) << "-Age" << ": " << loginStudent->age << endl;
			cout << setw(20) << "-Gender" << ": " << loginStudent->gender << endl;
			cout << setw(20) << "-Phone" << ": " << loginStudent->phone << endl;
			cout << setw(20) << "-Address" << ": " << loginStudent->address << endl;
			cout << setw(20) << "-Tuition Center" << ": " << loginStudent->tuitionCenterName << endl;
			cout << setw(20) << "-Subject" << ": ";
			for (int i = 0; i < 10; i++) {
				if (loginStudent->subject[i] == "\0") {
					break;
				}
				else {
					for (int i = 0; i < StudentSize; i++)
					{
						if (subjectlist[i]->code == loginStudent->subject[i])
						{
							cout << subjectlist[i]->name << "   ";
							break;
						}
					}
				}
			}
			cout << endl << endl;
			system("pause");
			system("CLS");
		}
		//give tutor rating
		else if (select == 2) {
			cout << "Please select the tutor to give rating: " << endl;
			int num = 0;
			string tutor[10] = {};
			for (int i = 0; i < 10; i++) {
				if (loginStudent->subject[i] == "\0") {
					break;
				}
				else 
				{
					for (int j = 0; j < TutorSize; j++)
					{
						if (tutorlist[j]->tuitionCenterCode == loginStudent->tuitionCenterCode &&
							tutorlist[j]->subjectCode == loginStudent->subject[i])
						{
							tutor[num] = tutorlist[j]->tutorID;
							num++;
							cout << "[" << num << "]" << tutorlist[j]->name << endl;
							break;
						}
					}
				}
			}
			if (num == 0) {
				cout << "No tutor to rate" << endl;
				system("pause");
				system("CLS");
			}
			else {
				cout << "Enter number of tutor to rate: ";
				cin >> select;
				while (cin.fail() || select < 1 || select > num) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid Input!" << endl;
					cout << "Enter number of tutor to rate: ";
					cin >> select;
				}
				cout << endl;
				for (int i = 0; i < TutorSize; i++)
				{
					if (tutorlist[i]->tutorID == tutor[select - 1])
					{
						cout << "Tutor Name: " << tutorlist[i]->name << endl;
						cout << "Subject: " << tutorlist[i]->subjectName << endl;
						cout << "Tuition: " << tutorlist[i]->tuitionCenterName << endl;
						cout << "Rating: " << fixed << setprecision(1) << tutorlist[i]->rating[0] / tutorlist[i]->rating[1] << endl;
						break;
					}
				}
				int rate;
				cout << endl << "Enter your rating (1-5): ";
				cin >> rate;
				while (cin.fail() || rate < 1 || rate > 5) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid rating!" << endl;
					cout << "Enter your rating (1-5): ";
					cin >> rate;
				}
				for (int i = 0; i < TutorSize; i++)
				{
					if (tutorlist[i]->tutorID == tutor[select - 1])
					{
						if (tutorlist[i]->rating[0] == 0) {
							tutorlist[i]->rating[0] = tutorlist[i]->rating[0] + rate;
						}
						else {
							tutorlist[i]->rating[0] = tutorlist[i]->rating[0] + rate;
							tutorlist[i]->rating[1] = tutorlist[i]->rating[1] + 1;
						}
					}
				}
				cout << "Rating Successful" << endl;
				system("pause");
				system("CLS");
			}
		}
		else if (select == -1) {
			cout << "Are you sure want to exit entire system? ( 0 for 'NO', 1 for 'YES' ): ";
			cin >> select;
			while (cin.fail() || select < -1 || select > 2) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Are you sure want to exit entire system? ( 0 for 'NO', 1 for 'YES' ): ";
				cin >> select;
			}
			if (select == 1) {
				exit(0);
			}
			else {
				select = -1;
			}
		}
	} while (select != 0);

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


// login
void login()
{
	do {
		//System title
		cout << string(80, '=') << endl << string(30, ' ') << "eXcel Tuition Centre" << endl;
		cout << string(29, ' ') << "Tutor Managment System" << endl;
		cout << string(80, '=') << endl << endl;

		bool login = false;
		do {
			//get username and password;
			string username, password;
			cout << "Enter User ID: ";
			cin >> username;
			cout << "Enter password: ";
			cin >> password;

			//user validation
			//Admin
			for (int i = 0; i < AdminSize; i++)
			{
				if (username == adminlist[i]->username && password == adminlist[i]->password)
				{
					loginAdmin = adminlist[i];
					login = true;
					break;
				}
			}
			//Check for student if user not admin
			if (!login)
			{
				for (int i = 0; i < StudentSize; i++)
				{
					if (username == studentlist[i]->studentID && password == studentlist[i]->password)
					{
						loginStudent = studentlist[i];
						login = true;
						break;
					}
				}
			}

			//check the menu to be accessed by the user
			if (loginAdmin != NULL) {
				if (loginAdmin->position == "Manager") {
					system("CLS");
					managerMenu();
					system("CLS");
					loginAdmin = NULL;
				}
				else {
					system("CLS");
					adminMenu();
					system("CLS");
					loginAdmin = NULL;
				}
			}
			else if (loginStudent != NULL) {
				system("CLS");
				studentMenu();
				system("CLS");
				loginStudent = NULL;
			}
			else
			{
				cout << endl << "Invalid username or password!" << endl;
				cout << "Please enter again." << endl << endl;
			}
		} while (!login);

	} while (true);
}


int main()
{
	// Create predefined record
	PredefinedAdmin();
	PredefinedStudent();
	PredefinedSubject();
	PredefinedTuition();
	PredefinedTutor();
	
	//start system by login
	login();

	return 0;
}