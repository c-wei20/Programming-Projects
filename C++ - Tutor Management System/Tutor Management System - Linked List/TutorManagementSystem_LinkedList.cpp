//G3_TP062572_TP062011_TP061980

#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include "LinkedListStructure.h"	//the linked list structure
#define  _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std;

//global variable to save number of record of each structure
int AdminSize = 0;
int TutorSize = 0;
int StudentSize = 0;
int TuitionSize = 0;
int SubjectSize = 0;

//global variable to save login user data
Admin* loginAdmin = NULL;	//to store login admin data
Student* loginStudent = NULL;	//to store login student data

//function - Create new node of each structure
Admin* CreateNewAdmin(string username, string password, string position, string location) {
	Admin* newAdmin = new Admin;
	newAdmin->username = username;
	newAdmin->password = password;
	newAdmin->position = position;
	newAdmin->location = location;
	newAdmin->nextAddress = NULL;
	newAdmin->previousAddress = NULL;

	return newAdmin;
}

Student* CreateNewStudent(string StudentID, string Password, string Name, string DoB, int Age, char Gender,
	string Phone, string Address, string Tuition_Center_Code, string Tuition_Center_Name, string subject[10])
{
	Student* newStudent = new Student;
	newStudent->StudentID = StudentID;
	newStudent->Password = Password;
	newStudent->Name = Name;
	newStudent->DoB = DoB;
	newStudent->Age = Age;
	newStudent->Gender = Gender;
	newStudent->Phone = Phone;
	newStudent->Address = Address;
	newStudent->Tuition_Center_Code = Tuition_Center_Code;
	newStudent->Tuition_Center_Name = Tuition_Center_Name;
	//assign each of the student subject to the new node one by one
	for (int i = 0; i < 10; i++){
		if (subject[i] != "\0") {
			newStudent->subject[i] = subject[i];
		}
		else {
			break;
		}
	}
	newStudent->nextAddress = NULL;
	newStudent->previousAddress = NULL;

	return newStudent;
}

Tutor* CreateNewTutor(string TutorID, string Name, string DoB, int Age, char Gender, string Date_Joined, 
	string Date_Terminated, double Hourly_Pay_Rate, string Phone, string Address, string Education, 
	string Tuition_Center_Code, string Tuition_Center_Name, string Subject_Code, string Subject_Name, double Rating[2]) {
	Tutor* newTutor = new Tutor;
	newTutor->TutorID = TutorID;
	newTutor->Name = Name;
	newTutor->DoB = DoB;
	newTutor->Age = Age;
	newTutor->Gender = Gender;
	newTutor->Date_Joined = Date_Joined;
	newTutor->Date_Terminated = Date_Terminated;
	newTutor->Hourly_Pay_Rate = Hourly_Pay_Rate;
	newTutor->Phone = Phone;
	newTutor->Address = Address;
	newTutor->Education = Education;
	newTutor->Tuition_Center_Code = Tuition_Center_Code;
	newTutor->Tuition_Center_Name = Tuition_Center_Name;
	newTutor->Subject_Code = Subject_Code;
	newTutor->Subject_Name = Subject_Name;
	//assign the total rating and number of rate to the new node rating list one by one
	for (int i = 0; i < 2; i++) {
		newTutor->Rating[i] = Rating[i];
	}
	newTutor->NextAddress = NULL;
	newTutor->PrevAddress = NULL;

	return newTutor;
}

Tuition* CreateNewTuition(string code, string name){
	Tuition* newTuition = new Tuition;
	newTuition->code = code;
	newTuition->name = name;
	newTuition->nextAddress = NULL;
	newTuition->PreviousAddress = NULL;

	return newTuition;
}

Subject* CreateNewSubject(string code, string name) {
	Subject* newSubject = new Subject;
	newSubject->code = code;
	newSubject->name = name;
	newSubject->nextAddress = NULL;
	newSubject->PreviousAddress = NULL;

	return newSubject;
}


// Insert new record function
void insertIntoSortedAdmin(Admin* newnode) {
	//scenario 1: list is empty
	if (Ahead == NULL) {
		Ahead = Atail = newnode;
	}
	//scenario 2: list is not empty, and always newnode 
	//character of the username smaller than Admin head username
	else if (newnode->username < Ahead->username) {
		newnode->nextAddress = Ahead;
		Ahead->previousAddress = newnode;
		Ahead = newnode;
	}
	//scenario 3: list not empty, always attach the end of the list
	else if (newnode->username > Atail->username) {
		newnode->previousAddress = Atail;
		Atail->nextAddress = newnode;
		Atail = newnode;
	}
	//scenario 4: middle of the list
	else {
		Admin* current = Ahead->nextAddress;
		while (current != NULL) {
			if (newnode->username < current->username) {	//find teh location
				newnode->previousAddress = current->previousAddress;
				newnode->nextAddress = current;
				current->previousAddress->nextAddress = newnode;
				current->previousAddress = newnode;
				break;
			}
			current = current->nextAddress;	//not found
		}
	}
	AdminSize++;
}

void insertIntoSortedStudent(Student* newnode) {
	//scenario 1: list is empty
	if (Shead == NULL) {
		Shead = Stail = newnode;
	}
	//scenario 2: list is not empty, and always newnode student name character smaller than head name
	else if (newnode->Name < Shead->Name) {
		newnode->nextAddress = Shead;
		Shead->previousAddress = newnode;
		Shead = newnode;
	}
	//scenario 3: list not empty, always attach the end of the list
	else if (newnode->Name > Stail->Name) {
		newnode->previousAddress = Stail;
		Stail->nextAddress = newnode;
		Stail = newnode;
	}
	//scenario 4: middle of the list
	else {
		Student* current = Shead->nextAddress;
		while (current != NULL) {
			if (newnode->Name < current->Name) {	//find teh location
				newnode->previousAddress = current->previousAddress;
				newnode->nextAddress = current;
				current->previousAddress->nextAddress = newnode;
				current->previousAddress = newnode;
				break;
			}
			current = current->nextAddress;	//not found
		}
	}
	StudentSize++;
}

void insertIntoEndofTutorList(Tutor* newnode) {
	//scenario 1: list is still empty, means tutor head is still empty
	if (Thead == NULL)
	{
		Thead = Ttail = newnode;
	}
	//scenario 2: if list not empty, means add item to the last location 
	else
	{
		Ttail->NextAddress = newnode;
		newnode->PrevAddress = Ttail;
		Ttail = newnode;
	}
	TutorSize++;
}

void insertIntoSortedTuition(Tuition* newnode) {
	//scenario 1: list is empty
	if (TThead == NULL) {
		TThead = TTtail = newnode;
	}
	//scenario 2: list is not empty, and always newnode tuition code character 
	//smaller than head tuition code
	else if (newnode->code < TThead->code) {
		newnode->nextAddress = TThead;
		TThead->PreviousAddress = newnode;
		TThead = newnode;
	}
	//scenario 3: list not empty, always attach the end of the list
	else if (newnode->code > TTtail->code) {
		newnode->PreviousAddress = TTtail;
		TTtail->nextAddress = newnode;
		TTtail = newnode;
	}
	//scenario 4: middle of the list
	else {
		Tuition* current = TThead->nextAddress;
		while (current != NULL) {
			if (newnode->code < current->code) {	//find teh location
				newnode->PreviousAddress = current->PreviousAddress;
				newnode->nextAddress = current;
				current->PreviousAddress->nextAddress = newnode;
				current->PreviousAddress = newnode;
				break;
			}
			current = current->nextAddress;	//not found
		}
	}
	TuitionSize++;
}

void insertIntoSortedSubject(Subject* newnode) {
	//scenario 1: list is empty
	if (SJhead == NULL) {
		SJhead = SJtail = newnode;
	}
	//scenario 2: list is not empty, and always newnode subject code character 
	//smaller than head subject code
	else if (newnode->code < SJhead->code) {
		newnode->nextAddress = SJhead;
		SJhead->PreviousAddress = newnode;
		SJhead = newnode;
	}
	//scenario 3: list not empty, always attach the end of the list
	else if (newnode->code > SJtail->code) {
		newnode->PreviousAddress = SJtail;
		SJtail->nextAddress = newnode;
		SJtail = newnode;
	}
	//scenario 4: middle of the list
	else {
		Subject* current = SJhead->nextAddress;
		while (current != NULL) {
			if (newnode->code < current->code) {	//find teh location
				newnode->PreviousAddress = current->PreviousAddress;
				newnode->nextAddress = current;
				current->PreviousAddress->nextAddress = newnode;
				current->PreviousAddress = newnode;
				break;
			}
			current = current->nextAddress;	//not found
		}
	}
	SubjectSize++;
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
	//create the student subject list
	string subject[10] = { "AMT", "PS", "EN" };
	newStudent = CreateNewStudent("S00001", "123456", "James", "12/12/2005", 17, 'M', "011-2233453", 
		"17-B Jln Batai Laut 7 Kawasan 16 Tmn Intan", "BJ-H", "Bukit Jalil", subject);
	insertIntoSortedStudent(newStudent);
	string subject1[10] = { "EC", "BK"};
	newStudent = CreateNewStudent("S00002", "123321", "Peter", "12/1/2004", 18, 'M', "012-2344345", 
		"13/F Plaza Mont Kiara Blok E Jalan 1/70C", "BJ-H", "Bukit Jalil", subject1);
	insertIntoSortedStudent(newStudent);
	string subject2[10] = { "MA", "EN", "SC" };
	newStudent = CreateNewStudent("S00003", "234567", "Swati", "11/19/2005", 17, 'F', "018-8290648", 
		"Kg. Banggol Saman Kok Lanas, Ketereh", "PJ", "Petaling Jaya", subject2);
	insertIntoSortedStudent(newStudent);
	string subject3[10] = { "MT" };
	newStudent = CreateNewStudent("S00004", "abcde", "Brian", "11/8/2004", 18, 'M', "014-2966491", 
		"476 Jln Pasir Puteh Pasir Puteh", "PJ", "Petaling Jaya", subject3);
	insertIntoSortedStudent(newStudent);
	string subject4[10] = { "AMT", "PS" };
	newStudent = CreateNewStudent("S00005", "abc1234", "Sally", "10/27/2004", 18, 'F', "018-0936226", 
		"10Th Mile, Jalan Kuching-serian", "CR", "Cheras", subject4);
	insertIntoSortedStudent(newStudent);
	string subject5[10] = { "MT", "EN" };
	newStudent = CreateNewStudent("S00006", "aaa666", "Kevin", "10/16/2006", 16, 'M', "019-2072971", 
		"9A JLN LAPANGAN TERBANG LAMA", "CR", "Cheras", subject5);
	insertIntoSortedStudent(newStudent);
}

void PredefinedTutor() {
	Tutor* newTutor = new Tutor;
	// Bukit Jalil Tutor ----------------------------------
	//create tutor rating list { total rating, number of rate }
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
	// Petaling Jaya Tutor ----------------------------------
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
	// Cheras Tutor ----------------------------------
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


//bubble sort and display tutor record function
//sort by tutor name - bubble sort
void sortTutorName() {
	//the tutor list is empty
	if (Thead == NULL) {
		cout << "List is empty, no thing to sort";
		return;
	}
	//tutor list is not empty
	bool sort = true;
	while (sort) {
		Tutor* current = Thead;
		sort = false;
		//ensure the list has more than one node
		//ensure the current node and next node is not null, able to swap the node 
		while (current != NULL && current->NextAddress != NULL) {
			// the current node name character is larger then next node
			if (current->Name > current->NextAddress->Name) {
				//scenario 1: the current node is head
				if (current == Thead) {
					//scenario 1.1: the next node is tail
					if (current->NextAddress == Ttail) {
						Tutor* temp = current;
						current = current->NextAddress;
						temp->NextAddress = current->NextAddress;
						current->PrevAddress = temp->PrevAddress;
						current->NextAddress = temp;
						temp->PrevAddress = current;
						Thead = current;
						Ttail = temp;
					}
					//scenario 1.2: the next node is not tail
					else {
						Tutor* temp = current;
						current = current->NextAddress;
						current->NextAddress->PrevAddress = temp;
						temp->NextAddress = current->NextAddress;
						current->PrevAddress = temp->PrevAddress;
						current->NextAddress = temp;
						temp->PrevAddress = current;
						Thead = current;
					}
				}
				//scenario 2: the next node is tail
				else if (current->NextAddress == Ttail) {
					Tutor* temp = current;
					current = current->NextAddress;
					temp->NextAddress = current->NextAddress;
					current->PrevAddress = temp->PrevAddress;
					temp->PrevAddress->NextAddress = current;
					current->NextAddress = temp;
					temp->PrevAddress = current;
					Ttail = temp;
				}
				//scenario 3: the two nodes to swap is at the middle of the list
				else {
					Tutor* temp = current;
					current = current->NextAddress;
					current->NextAddress->PrevAddress = temp;
					temp->NextAddress = current->NextAddress;
					current->PrevAddress = temp->PrevAddress;
					temp->PrevAddress->NextAddress = current;
					current->NextAddress = temp;
					temp->PrevAddress = current;
				}
				sort = true;
			}
			//current node to next node
			current = current->NextAddress;
		}
	}
}
//sort and display by TutorID
void sortTutorID() {
	//tutor list is empty
	if (Thead == NULL) {
		cout << "List is empty, no thing to sort";
		return;
	}
	//tutor list is not empty
	bool sort = true;
	while (sort) {
		Tutor* current = Thead;
		sort = false;
		//ensure the list has more than one node
		//ensure the current node and next node is not null, able to swap the node 
		while (current != NULL && current->NextAddress != NULL) {
			// the current node tutor ID is larger then next node
			if (current->TutorID > current->NextAddress->TutorID) {
				if (current == Thead) {
					//scenario 1.1: the next node is tail
					if (current->NextAddress == Ttail) {
						Tutor* temp = current;
						current = current->NextAddress;
						temp->NextAddress = current->NextAddress;
						current->PrevAddress = temp->PrevAddress;
						current->NextAddress = temp;
						temp->PrevAddress = current;
						Thead = current;
						Ttail = temp;
					}
					//scenario 1.2: the next node is not tail
					else {
						Tutor* temp = current;
						current = current->NextAddress;
						current->NextAddress->PrevAddress = temp;
						temp->NextAddress = current->NextAddress;
						current->PrevAddress = temp->PrevAddress;
						current->NextAddress = temp;
						temp->PrevAddress = current;
						Thead = current;
					}
				}
				//scenario 2: the next node is tail
				else if (current->NextAddress == Ttail) {
					Tutor* temp = current;
					current = current->NextAddress;
					temp->NextAddress = current->NextAddress;
					current->PrevAddress = temp->PrevAddress;
					temp->PrevAddress->NextAddress = current;
					current->NextAddress = temp;
					temp->PrevAddress = current;
					Ttail = temp;
				}
				//scenario 3: the two nodes to swap is at the middle of the list
				else {
					Tutor* temp = current;
					current = current->NextAddress;
					current->NextAddress->PrevAddress = temp;
					temp->NextAddress = current->NextAddress;
					current->PrevAddress = temp->PrevAddress;
					temp->PrevAddress->NextAddress = current;
					current->NextAddress = temp;
					temp->PrevAddress = current;
				}
				sort = true;
			}
			//current node to next node
			current = current->NextAddress;
		}
	}
}
///sort and display by Hourly Pay
void sortTutorHourPay() {
	//tutor list is empty
	if (Thead == NULL) {
		cout << "List is empty, no thing to sort";
		return;
	}
	//tutor list is not empty
	bool sort = true;
	while(sort){
		Tutor* current = Thead;
		sort = false;
		//ensure the list has more than one node
		//ensure the current node and next node is not null, able to swap the node 
		while (current != NULL && current->NextAddress != NULL) {
			// the current node pay rate is larger then next node
			if (current->Hourly_Pay_Rate > current->NextAddress->Hourly_Pay_Rate) {
				if (current == Thead) {
					//scenario 1.1: the next node is tail
					if (current->NextAddress == Ttail) {
						Tutor* temp = current;
						current = current->NextAddress;
						temp->NextAddress = current->NextAddress;
						current->PrevAddress = temp->PrevAddress;
						current->NextAddress = temp;
						temp->PrevAddress = current;
						Thead = current;
						Ttail = temp;
					}
					//scenario 1.2: the next node is not tail
					else {
						Tutor* temp = current;
						current = current->NextAddress;
						current->NextAddress->PrevAddress = temp;
						temp->NextAddress = current->NextAddress;
						current->PrevAddress = temp->PrevAddress;
						current->NextAddress = temp;
						temp->PrevAddress = current;
						Thead = current;
					}
				}
				//scenario 2: the next node is tail
				else if (current->NextAddress == Ttail) {
					Tutor* temp = current;
					current = current->NextAddress;
					temp->NextAddress = current->NextAddress;
					current->PrevAddress = temp->PrevAddress;
					temp->PrevAddress->NextAddress = current;
					current->NextAddress = temp;
					temp->PrevAddress = current;
					Ttail = temp;
				}
				//scenario 3: the two nodes to swap is at the middle of the list
				else {
					Tutor* temp = current;
					current = current->NextAddress;
					current->NextAddress->PrevAddress = temp;
					temp->NextAddress = current->NextAddress;
					current->PrevAddress = temp->PrevAddress;
					temp->PrevAddress->NextAddress = current;
					current->NextAddress = temp;
					temp->PrevAddress = current;
				}
				sort = true;
			}
			//current node to next node
			current = current->NextAddress;
		}
	}
}
///sort and display by Overall Performance (Rating)
void sortTutorRate() {
	//tutor list is empty
	if (Thead == NULL) {
		cout << "List is empty, no thing to sort";
		return;
	}
	//tutor list is not empty
	bool sort = true;
	while (sort) {
		Tutor* current = Thead;
		sort = false;
		//ensure the list has more than one node
		//ensure the current node and next node is not null, able to swap the node 
		while (current != NULL && current->NextAddress != NULL) {
			// the current node rating is larger then next node
			if (current->Rating[0] / current->Rating[1] > 
				current->NextAddress->Rating[0] / current->NextAddress->Rating[1]) {
				if (current == Thead) {
					//scenario 1.1: the next node is tail
					if (current->NextAddress == Ttail) {
						Tutor* temp = current;
						current = current->NextAddress;
						temp->NextAddress = current->NextAddress;
						current->PrevAddress = temp->PrevAddress;
						current->NextAddress = temp;
						temp->PrevAddress = current;
						Thead = current;
						Ttail = temp;
					}
					//scenario 1.2: the next node is not tail
					else {
						Tutor* temp = current;
						current = current->NextAddress;
						current->NextAddress->PrevAddress = temp;
						temp->NextAddress = current->NextAddress;
						current->PrevAddress = temp->PrevAddress;
						current->NextAddress = temp;
						temp->PrevAddress = current;
						Thead = current;
					}
				}
				//scenario 2: the next node is tail
				else if (current->NextAddress == Ttail) {
					Tutor* temp = current;
					current = current->NextAddress;
					temp->NextAddress = current->NextAddress;
					current->PrevAddress = temp->PrevAddress;
					temp->PrevAddress->NextAddress = current;
					current->NextAddress = temp;
					temp->PrevAddress = current;
					Ttail = temp;
				}
				//scenario 3: the two nodes to swap is at the middle of the list
				else {
					Tutor* temp = current;
					current = current->NextAddress;
					current->NextAddress->PrevAddress = temp;
					temp->NextAddress = current->NextAddress;
					current->PrevAddress = temp->PrevAddress;
					temp->PrevAddress->NextAddress = current;
					current->NextAddress = temp;
					temp->PrevAddress = current;
				}
				sort = true;
			}
			//current node to next node
			current = current->NextAddress;
		}
	}
}


//display record in detailed page
void displayStudentPage(string tuition, int select) {
	Student* student = Shead;
	int position = 0;
	//get the record of selected student in the specific tuition
	while (student != NULL) {
		if (student->Tuition_Center_Name == tuition) {
			position++;
		}
		if (position == select) {
			break;
		}
		student = student->nextAddress;
	}
	do {
		//print the detail of the student record 
		cout << "Details Record of Student ID: " << student->StudentID << endl << endl;
		cout << left << setw(20) << "-Student ID" << ": " << student->StudentID << endl;
		cout << setw(20) << "-Name" << ": " << student->Name << endl;
		cout << setw(20) << "-Date of Birth" << ": " << student->DoB << endl;
		cout << setw(20) << "-Age" << ": " << student->Age << endl;
		cout << setw(20) << "-Gender" << ": " << student->Gender << endl;
		cout << setw(20) << "-Phone" << ": " << student->Phone << endl;
		cout << setw(20) << "-Address" << ": " << student->Address << endl;
		cout << setw(20) << "-Tuition Center" << ": " << student->Tuition_Center_Name << endl;
		cout << setw(20) << "-Subject" << ": ";
		//print the student subject record
		for (int i = 0; i < 10; i++) {
			if (student->subject[i] != "\0") {
				Subject* current = SJhead;
				while (current != NULL) {
					if (current->code == student->subject[i]) {
						cout << current->name << "   ";
						break;
					}
					current = current->nextAddress;
				}
			}
			else {
				break;
			}
		}

		//prompt user select to show previous record or next record
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
			Student* checkRecord = student;
			//go to previous page
			if (select == 0) {
				cout << "Page Up" << endl;
				//check whether have previous record
				checkRecord = checkRecord->previousAddress;
				while (checkRecord != NULL) {
					if (checkRecord->Tuition_Center_Name == tuition) {
						student = checkRecord;
						//record find
						find = true;
						break;
					}
					checkRecord = checkRecord->previousAddress;
				}
			}
			//go to next page
			else if (select == 1) {
				cout << "Page Down" << endl;
				//check whether have next record
				checkRecord = checkRecord->nextAddress;
				while (checkRecord != NULL) {
					if (checkRecord->Tuition_Center_Name == tuition) {
						student = checkRecord;
						//record find
						find = true;
						break;
					}
					checkRecord = checkRecord->nextAddress;
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

void displayTutorPage(string tuition, int select) {
	Tutor* tutor = Thead;
	int position = 0;
	//get the record of selected tutor in the specific tuition
	while (tutor != NULL) {
		//the selected record is no based on specific tutiion
		if (tuition == "") {
			position++;
		}
		//the selected record is based on specific tutiion
		else {
			if (tutor->Tuition_Center_Name == tuition) {
				position++;
			}
		}
		if (position == select) {
			break;
		}
		tutor = tutor->NextAddress;
	}
	do {
		//print the detail of the tutor record 
		cout << "Details Record of Tutor ID: " << tutor->TutorID << endl << endl;
		cout << left << setw(20) << "-Tutor ID" << ": " << tutor->TutorID << endl;
		cout << setw(20) << "-Name" << ": " << tutor->Name << endl;
		cout << setw(20) << "-Date of Birth" << ": " << tutor->DoB << endl;
		cout << setw(20) << "-Age" << ": " << tutor->Age << endl;
		cout << setw(20) << "-Gender" << ": " << tutor->Gender << endl;
		cout << setw(20) << "-Date Joined" << ": " << tutor->Date_Joined << endl;
		cout << setw(20) << "-Date Terminated" << ": " << tutor->Date_Terminated << endl;
		cout << setw(20) << "-Hourly Pay Rate" << ": RM " << setprecision(2) << tutor->Hourly_Pay_Rate << endl;
		cout << setw(20) << "-Phone" << ": " << tutor->Phone << endl;
		cout << setw(20) << "-Address" << ": " << tutor->Address << endl;
		cout << setw(20) << "-Specialized Field" << ": " << tutor->Education << endl;
		cout << setw(20) << "-Tuition Center Code" << ": " << tutor->Tuition_Center_Code << endl;
		cout << setw(20) << "-Tuition Center Name" << ": " << tutor->Tuition_Center_Name << endl;
		cout << setw(20) << "-Subject Code" << ": " << tutor->Subject_Code << endl;
		cout << setw(20) << "-Subject Name" << ": " << tutor->Subject_Name << endl;
		cout << setw(20) << "-Rating" << ": " << setprecision(1) << tutor->Rating[0]/tutor->Rating[1] << endl;

		bool find = false;
		//prompt user select to show previous record or next record
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
			Tutor* checkRecord = tutor;
			//go to previous page
			if (select == 0) {
				cout << "Page Up" << endl;
				//check whether have previous record
				checkRecord = checkRecord->PrevAddress;
				while (checkRecord != NULL) {
					//record is not based on specific tuition
					if (tuition == "") {
						tutor = checkRecord;
						find = true;
						break;
					}
					//record is based on specific tuition
					else {
						if (checkRecord->Tuition_Center_Name == tuition) {
							tutor = checkRecord;
							find = true;
							break;
						}
					}
					checkRecord = checkRecord->PrevAddress;
				}
			}
			//go to next page
			else if (select == 1) {
				cout << "Page Down" << endl;
				//check whether have next record
				checkRecord = checkRecord->NextAddress;
				while (checkRecord != NULL) {
					//record is not based on specific tuition
					if (tuition == "") {
						tutor = checkRecord;
						find = true;
						break;
					}
					//record is based on specific tuition
					else {
						if (checkRecord->Tuition_Center_Name == tuition) {
							tutor = checkRecord;
							find = true;
							break;
						}
					}
					checkRecord = checkRecord->NextAddress;
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


// Display record in Table List function
void displayAdmin() {
	Admin* current = Ahead;
	int i = 1;
	//display the top row of the table
	cout << string(65, '-') << endl;
	cout << left << setw(5) << "No." << setw(20) << "Name" << setw(20) << "Position" << "Tuition Location" << endl;
	cout << string(65, '-') << endl;
	//display the list of record
	while (current != NULL){
		cout << left << setw(5) << i << setw(20) << current->username << setw(20) << current->position << current->location << endl;
		current = current->nextAddress;
		i++;
	}
	cout << endl;
}

void displayStudent() {
	int select;
	string tname;
	do {
		//check the admin access this function is from headquater(Bukit Jalil) or not
		if (loginAdmin->location == "Bukit Jalil") {
			int num = 0;
			string tuitionList[10] = {};
			Tuition* tuition = TThead;
			//get the tuition name into a list
			while (tuition != NULL) {
				tuitionList[num] = tuition->name;
				num++;
				tuition = tuition->nextAddress;
			}
			//prompt the admin to display the student in which tuition
			cout << "Select the tuition's student record to display: " << endl;
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
			//get the selected tuition name
			tname = tuitionList[select - 1];
		}
		//the admin access this function is not from headquater(Bukit Jalil)
		else {
			//get the tuition name of the admin
			tname = loginAdmin->location;
		}
		int No = 0;
		//display the first row of the table
		cout << string(100, '-') << endl;
		cout << left << setw(5) << "No." << setw(15) << "Student ID" << setw(20) << "Name" << setw(10) << "Age"
			<< setw(25) << "Tuition" << setw(25) << "Subject" << endl;
		cout << string(100, '-') << endl;
		Student* current = Shead;
		//display the student record list of the specific tuition
		while (current != NULL) {
			if (current->Tuition_Center_Name == tname) {
				No++;
				cout << left << setw(5) << No << setw(15) << current->StudentID << setw(20) << current->Name << setw(10)
					<< current->Age << setw(25) << current->Tuition_Center_Name;
				for (int i = 0; i < sizeof(current->subject) / sizeof(current->subject[0]); i++) {
					if (current->subject[i] != "\0") {
						cout << current->subject[i] << ", ";
					}
				}
				cout << endl;
			}
			current = current->nextAddress;
		}
		//select the student record that want to view in detial
		cout << endl << "Select the number of student to view detials (0 exit to main menu): ";
		cin >> select;
		while (cin.fail() || select < -1 || select > No) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Select the number of student to view detials (0 exit to main menu): ";
			cin >> select;
		}
		if (select != 0) {
			system("CLS");
			//call the function for print the student record detial
			displayStudentPage(tname, select);
			select = 0;
		}
	} while (select != 0);
}

void displayTutor() {
	int select;
	string tname;
	do {
		//check the admin access this function is from headquater(Bukit Jalil) or not
		if (loginAdmin->location == "Bukit Jalil") {
			int num = 0;
			string tuitionList[10] = {};
			Tuition* tuition = TThead;
			//get the tuition name into a list
			while (tuition != NULL) {
				tuitionList[num] = tuition->name;
				num++;
				tuition = tuition->nextAddress;
			}
			//prompt the admin to display the tutor in which tuition
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
			//get the selected tuition name
			tname = tuitionList[select - 1];
		}
		//the admin access this function is not from headquater(Bukit Jalil)
		else {
			//get the tuition name of the admin
			tname = loginAdmin->location;
		}
		int No = 0;
		//display the top row of the table
		cout << string(120, '-') << endl;
		cout << left << setw(5) << "No." << setw(15) << "Tutor ID" << setw(20) << "Name" << setw(20) << "Tuition"
			<< setw(25) << "Subject" << setw(25) << "Hourly Pay Rate(RM)" << setw(20) << "Rating" << endl;
		cout << string(120, '-') << endl;
		Tutor* current = Thead;
		//display the tutor record list of the specific tuition
		while (current != NULL) {
			if (current->Tuition_Center_Name == tname) {
				No++;
				cout << left << setw(5) << No << setw(15) << current->TutorID << setw(20) << current->Name << setw(20)
					<< current->Tuition_Center_Name << setw(25) << current->Subject_Name << setw(25) << fixed << setprecision(2)
					<< current->Hourly_Pay_Rate << setw(20) << setprecision(1) << current->Rating[0]/current->Rating[1] << endl;
			}
			current = current->NextAddress;
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
			//call the function for print the tutor record detial
			displayTutorPage(tname, select);
			select = 0;
		}
	} while (select != 0);
}
//function to display the tutor record in table list only, without the function of view detail record
void displayTutorListOnly() {
	//check the login admin is from headquater or not
	if (loginAdmin->location == "Bukit Jalil") {
		int No = 1;
		//display first row if the table
		cout << string(120, '-') << endl;
		cout << left << setw(5) << "No." << setw(15) << "Tutor ID" << setw(20) << "Name" << setw(20) << "Tuition"
			<< setw(25) << "Subject" << setw(25) << "Hourly Pay Rate(RM)" << setw(20) << "Rating" << endl;
		cout << string(120, '-') << endl;
		Tutor* current = Thead;
		//display all tutor record with some attribute in table list
		while (current != NULL) {
			cout << left << setw(5) << No << setw(15) << current->TutorID << setw(20) << current->Name << setw(20)
				<< current->Tuition_Center_Name << setw(25) << current->Subject_Name << setw(25) << fixed << setprecision(2)
				<< current->Hourly_Pay_Rate << setw(20) << setprecision(1) << current->Rating[0] / current->Rating[1] << endl;
			No++;
			current = current->NextAddress;
		}
	}
	//the admin is no from headquater
	else {
		//get the admin tuition name
		string tname = loginAdmin->location;
		int No = 1;
		cout << string(120, '-') << endl;
		cout << left << setw(5) << "No." << setw(15) << "Tutor ID" << setw(20) << "Name" << setw(20) << "Tuition"
			<< setw(25) << "Subject" << setw(25) << "Hourly Pay Rate(RM)" << setw(20) << "Rating" << endl;
		cout << string(120, '-') << endl;
		Tutor* current = Thead;
		//display the tutor record of the tuition with some attribute in table list
		while (current != NULL) {
			if (current->Tuition_Center_Name == tname) {
				cout << left << setw(5) << No << setw(15) << current->TutorID << setw(20) << current->Name << setw(20)
					<< current->Tuition_Center_Name << setw(25) << current->Subject_Name << setw(25) << fixed << setprecision(2)
					<< current->Hourly_Pay_Rate << setw(20) << setprecision(1) << current->Rating[0] / current->Rating[1] << endl;
				No++;
			}
			current = current->NextAddress;
		}
	}
}

void displayTuition() {
	Tuition* current = TThead;
	int i = 1;
	//display table top row
	cout << "Tuition Reocrd" << endl << endl;
	cout << string(50, '-') << endl;
	cout << left << setw(5) << "No." << setw(20) << "Tuition Code" << "Tuition Name" << endl;
	cout << string(50, '-') << endl;
	//display all the tuition record
	while (current != NULL) {
		cout << left << setw(5) << i << setw(20) << current->code << current->name << endl;
		current = current->nextAddress;
		i++;
	}
	cout << endl;
}

void displaySubject() {
	Subject* current = SJhead;
	int i = 1;
	//display table top row
	cout << "Subject Record" << endl << endl;
	cout << string(50, '-') << endl;
	cout << left << setw(5) << "No." << setw(20) << "Subject Code" << "Subject Name" << endl;
	cout << string(50, '-') << endl;
	//display all the tuition record
	while (current != NULL) {
		cout << left << setw(5) << i << setw(20) << current->code << current->name << endl;
		current = current->nextAddress;
		i++;
	}
	cout << endl;
}


//Search a Tutor by Tutor ID function - linear search
void searchByTutorID() {
	//sort the tutor record with name
	sortTutorName;
	bool find = false;
	string searchID;
	do {
		//promt admin to enter a tutor id
		cout << "Enter a Tutor ID (0 exit to main menu): ";
		cin >> searchID;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		Tutor* tutor = Thead;
		int position = 0;
		if (searchID != "0") {
			while (tutor != NULL) {
				//for the admin in headquater can search all the tutor ID
				if (loginAdmin->location == "Bukit Jalil") {
					position++;
					if (tutor->TutorID == searchID) {
						find = true;
						break;
					}
				}
				//for the admin not in headquarter can only search the tutor ID in his tuition
				else {
					if (tutor->Tuition_Center_Name == loginAdmin->location) {
						position++;
						if (tutor->TutorID == searchID && 
							tutor->Tuition_Center_Name == loginAdmin->location) {
							find = true;
							break;
						}
					}
				}
				tutor = tutor->NextAddress;
			}
		}
		//exit the function
		if (searchID == "0") {
			system("CLS");
			break;
		}
		//no tutor id record find
		else if (!find) {
			cout << "No record found, please try other Tutor ID." << endl;
		}
		//tutor id record find and the admin is from headquater
		else if (find && loginAdmin->location == "Bukit Jalil") {
			//to showw the tuition is not specific
			string tuition = "";
			system("CLS");
			//call the function to diaplay tutor record in detial page
			displayTutorPage(tuition, position);
		}
		//for the admin not in headquater
		else{
			//specific the tuition
			string tuition = loginAdmin->location;
			system("CLS");
			//call the function to diaplay tutor record in detial page
			displayTutorPage(tuition, position);
		}
	} while (!find);
}


//Search Tutors by overall performance (Rating) - linear search
void searchByRate() {
	double searchRate;
	do {
		//sort tutor record by name
		sortTutorName();
		//promt admin to enter a rating
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
			int No = 1;
			//display table top row
			cout << endl << string(120, '-') << endl;
			cout << left << setw(5) << "No." << setw(15) << "Tutor ID" << setw(20) << "Name" << setw(20) << "Tuition"
				<< setw(25) << "Subject" << setw(25) << "Hourly Pay Rate(RM)" << setw(20) << "Rating" << endl;
			cout << string(120, '-') << endl;
			Tutor* current = Thead;
			//search tutor rating and display the tutor list
			while (current != NULL) {
				//make sure the search rating is with one decial point
				searchRate = round(searchRate * 10.0) / 10.0;
				double Rating = round((current->Rating[0] / current->Rating[1]) * 10.0) / 10.0;
				//for the admin in headquater
				if (loginAdmin->location == "Bukit Jalil") {
					//diaplay the tutor list that match the rating
					if (Rating == searchRate) {
						find = true;
						cout << left << setw(5) << No << setw(15) << current->TutorID << setw(20) << current->Name << setw(20)
							<< current->Tuition_Center_Name << setw(25) << current->Subject_Name << setw(25) << fixed << setprecision(2)
							<< current->Hourly_Pay_Rate << setw(20) << setprecision(1) << current->Rating[0] / current->Rating[1] << endl;
						No++;
					}
				}
				//for admin not in headquater
				else {
					//diaplay the specific tuition tutor list that match the rating
					if (Rating == searchRate && current->Tuition_Center_Name == loginAdmin->location) {
						find = true;
						cout << left << setw(5) << No << setw(15) << current->TutorID << setw(20) << current->Name << setw(20)
							<< current->Tuition_Center_Name << setw(25) << current->Subject_Name << setw(25) << fixed << setprecision(2)
							<< current->Hourly_Pay_Rate << setw(20) << setprecision(1) << current->Rating[0]/current->Rating[1] << endl;
						No++;
					}
				}
				current = current->NextAddress;
			}
			cout << endl;
			//no any record match the rating
			if (!find) {
				cout << "No record match! " << endl << endl;
			}
		}
	} while (searchRate != -1);
	system("CLS");
}


//add record function
//tutor - add to the end of list
void addTutor() {
	int select;
	string tname, tcode;
	int num = 0;
	string tuitionCode[10] = {};
	string tuitionName[10] = {};
	Tuition* tuition = TThead;
	//store all the tuition name and code into the list for easy retrieved
	while (tuition != NULL) {
		tuitionCode[num] = tuition->code;
		tuitionName[num] = tuition->name;
		num++;
		tuition = tuition->nextAddress;
	}
	int SJnum = 0;
	string SJCode[20] = {};
	string SJName[20] = {};
	Subject* subject = SJhead;
	//store all the subject name and code into the list for easy retrieved
	while (subject != NULL) {
		SJCode[SJnum] = subject->code;
		SJName[SJnum] = subject->name;
		SJnum++;
		subject = subject->nextAddress;
	}
	do {
		//check the admin is from headquater
		if (loginAdmin->location == "Bukit Jalil") {
			//prompt admin to select the tutor tuition that want to add
			cout << "Select the tuition of tutor to add: " << endl;
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
			//assigned the seleced tuition code and name
			tcode = tuitionCode[select - 1];
			tname = tuitionName[select - 1];
		}
		//for the admin not in headquater
		else {
			//specify the admin tuition code and name
			tname = loginAdmin->location;
			for (int i = 0; i < sizeof(tuitionName) / sizeof(tuitionName[0]); i++) {
				if (tuitionName[i] == tname) {
					tcode = tuitionCode[i];
					break;
				}
			}
		}
		int tutorNum = 0;
		Tutor* tutor = Thead;
		//to check is the existing tutor in that tuition reach a maximum of 10
		while (tutor != NULL) {
			if (tutor->Tuition_Center_Code == tcode && tutor->Date_Terminated != "-") {
				tutorNum++;
			}
			tutor = tutor->NextAddress;
		}
		//number of tutor in that tuition reach maximum of 10
		if (tutorNum == 10) {
			cout << "The existing tutor in " << tname << 
				" have reach a maximum of 10! No able to add tutor record!" << endl;
			system("pause");
			break;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("CLS");
		string TutorID, id, Name, DoB, Date_Joined, Date_Terminated, 
			Phone, Address, Specialize, Subject_Code, Subject_Name;
		char Gender;
		int Age = 0;	//assign default age - 0
		double Hourly_Pay_Rate, Rating[2] = { 0, 1 };	//assign the default rating - 0
		sortTutorID();
		//prompt admin to enter tutor detials
		cout << "Please enter the following tutor information: " << endl << endl;
		//auto assign new tutor ID with the last ID
		for (int i = 1; i < 5; i++) {
			if (Ttail->TutorID[i] != 0) {
				id = to_string(stoi(Ttail->TutorID.substr(i)) + 1);
				TutorID = "T" + string((4 - id.length()), '0') + id;
				break;
			}
		}
		cout <<left << setw(28) << "-Name" << ": ";
		getline(cin, Name);
		cout << setw(28) << "-Date of Birth (DD/MM/YYYY)" << ": ";
		getline(cin, DoB);
		//calculate the tutor age
		if (DoB != "" && DoB.size() >= 4) {
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
		//show the subject in list form to select
		for (int i = 1; SJName[i] != "\0"; i++) {
			cout << string(30,' ') << "[" << i + 1 << "] " << SJName[i] << endl;
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
		//assign subject code and name
		Subject_Code = SJCode[select - 1];
		Subject_Name = SJName[select - 1];
		cout << endl << "Confirm to add the record? 1 for YES, 0 for NO: ";
		cin >> select;
		while (cin.fail() || select < 0 || select > 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Confirm to add the record? 1 for YES, 0 for NO: ";
			cin >> select;
		}
		//confirm to save the record
		if (select == 1) {
			//create new tutor node and insert to the end of the tutor list
			Tutor* newTutor = CreateNewTutor(TutorID, Name, DoB, Age, Gender, Date_Joined, 
				Date_Terminated, Hourly_Pay_Rate, Phone, Address, Specialize, tcode, 
				tname, Subject_Code, Subject_Name, Rating);
			insertIntoEndofTutorList(newTutor);
			cout << "Record add secussful!" << endl;
		}
		//cancel to save new record
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
void addStudent() {
	int select;
	string tname, tcode;
	int num = 0;
	string tuitionCode[10] = {};
	string tuitionName[10] = {};
	Tuition* tuition = TThead;
	//store all the tuition name and code into the list for easy retrieved
	while (tuition != NULL) {
		tuitionCode[num] = tuition->code;
		tuitionName[num] = tuition->name;
		num++;
		tuition = tuition->nextAddress;
	}
	int SJnum = 0;
	string SJCode[20] = {};
	string SJName[20] = {};
	Subject* subject = SJhead;
	//store all the subject name and code into the list for easy retrieved
	while (subject != NULL) {
		SJCode[SJnum] = subject->code;
		SJName[SJnum] = subject->name;
		SJnum++;
		subject = subject->nextAddress;
	}
	do {
		//check the admin is from headquater
		if (loginAdmin->location == "Bukit Jalil") {
			//prompt admin to select the student tuition that want to add
			cout << "Select the tuition of student to add: " << endl;
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
			//assigned the seleced tuition code and name
			tcode = tuitionCode[select - 1];
			tname = tuitionName[select - 1];
		}
		//for the admin not in headquater
		else {
			//specify the admin tuition code and name
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
		//prompt admin to enter student detials
		cout << "Please enter the following student information: " << endl << endl;
		Student* student = Shead;
		//find the student last id
		string lastID = "0";
		while (student != NULL) {
			if (student->StudentID > lastID) {
				lastID = student->StudentID;
			}
			student = student->nextAddress;
		}
		//auto assign student id
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
		//calculate the student age
		if (DoB != "" && DoB.size() >= 4) {
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
		//show the suject list to select
		cout << setw(28) << "-Subject" << ": " << "[1]" << SJName[0] << endl;
		for (int i = 1; SJName[i] != "\0"; i++) {
			cout << string(30, ' ') << "[" << i + 1 << "] " << SJName[i] << endl;
		}
		//select the total number of subject the student joined 
		cout << "Enter the number of subject to add (max 10): ";
		cin >> select;
		while (cin.fail() || select < 1 || select > 10) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Enter the number of subject to add (max 10): ";
			cin >> select;
		}
		//save each of the student joined subject code
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
		cout << endl << "Confirm to add the record? 1 for YES, 0 for NO: ";
		cin >> select;
		while (cin.fail() || select < 0 || select > 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Confirm to add the record? 1 for YES, 0 for NO: ";
			cin >> select;
		}
		//confirm to add record
		if (select == 1) {
			//create new student node and insert to the sorted student list
			Student* newStudent = CreateNewStudent(StudentID, Password, Name, DoB, Age, Gender,
				Phone, Address, tcode, tname, Subject);
			insertIntoSortedStudent(newStudent);
			cout << "Record add secussful!" << endl;
		}
		//cancel to save record
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
void addAdmin() {
	int select;
	do {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("CLS");
		string username, Password, position, location;
		//prompt manager to enter admin detials
		cout << "Please enter the following admin information: " << endl << endl;
		cout << left << setw(20) << "-User Name" << ": ";
		getline(cin, username);
		cout << left << setw(20) << "-Password" << ": ";
		getline(cin, Password);
		cout << setw(20) << "-Position" << ": ";
		getline(cin, position);
		cout << setw(20) << "-Location" << ": ";
		getline(cin, location);
		cout << endl << "Confirm to add the record? 1 for YES, 0 for NO: ";
		cin >> select;
		while (cin.fail() || select < 0 || select > 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Confirm to add the record? 1 for YES, 0 for NO: ";
			cin >> select;
		}
		//confirm to save record
		//create new admin node and insert to the sort admin list
		if (select == 1) {
			Admin* newAdmin = CreateNewAdmin(username, Password, position, location);
			insertIntoSortedAdmin(newAdmin);
			cout << "Record add secussful!" << endl;
		}
		//cancel to save record
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
void addTuition() {
	int select;
	int num = 0;
	string tuitionCode[10] = {};
	string tuitionName[10] = {};
	Tuition* tuition = TThead;
	//save the tuition code and name in list for easy retrieved
	while (tuition != NULL) {
		tuitionCode[num] = tuition->code;
		tuitionName[num] = tuition->name;
		num++;
		tuition = tuition->nextAddress;
	}
	do {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("CLS");
		string code, name;
		//prompt manager to enter tuition detials
		cout << "Please enter the following tuition information: " << endl << endl;
		cout << left << setw(20) << "-Tuition Code" << ": ";
		getline(cin, code);
		//to check is the new tuition code existed - linear search
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
		//to check the new tuition name existed - linear search
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
		cout << endl << "Confirm to add the record? 1 for YES, 0 for NO: ";
		cin >> select;
		while (cin.fail() || select < 0 || select > 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Confirm to add the record? 1 for YES, 0 for NO: ";
			cin >> select;
		}
		//confirm to save record
		if (select == 1) {
			//create new tuition node and insert to the sorted tuition list
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
void addSubject() {
	int select;
	int SJnum = 0;
	string SJCode[20] = {};
	string SJName[20] = {};
	Subject* subject = SJhead;
	//save all the subject code and name in list for easy retrieved
	while (subject != NULL) {
		SJCode[SJnum] = subject->code;
		SJName[SJnum] = subject->name;
		SJnum++;
		subject = subject->nextAddress;
	}
	do {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("CLS");
		string code, name;
		//prompt to enter subject detials
		cout << "Please enter the following subject information: " << endl << endl;
		cout << left << setw(20) << "-Subject Code" << ": ";
		getline(cin, code);
		//check the new subject code existed
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
		//check the new subject name existed
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
		cout << endl << "Confirm to add the record? 1 for YES, 0 for NO: ";
		cin >> select;
		while (cin.fail() || select < 0 || select > 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Confirm to add the record? 1 for YES, 0 for NO: ";
			cin >> select;
		}
		//confirm to save record
		if (select == 1) {
			//create new subject node and insert to the sort subject list
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


//modify record from specific location function
//tutor
void modifyTutor() {
	//sort the tutor by name
	sortTutorName();
	int select;
	do {
		system("CLS");
		cout << "Modify tutor record" << endl << endl;
		int No = 0;
		//display the top row of table
		cout << string(140, '-') << endl;
		cout << left << setw(5) << "No." << setw(15) << "Tutor ID" << setw(20) << "Name" << setw(20) << "Tuition"
			<< setw(20) << "Date Terminated" << setw(25) << "Phone" << "Address" << endl;
		cout << string(140, '-') << endl;
		Tutor* tutor = Thead;
		//diaplay all the tutor list with the modifiable attribute
		while (tutor != NULL) {
			No++;
			cout << left << setw(5) << No << setw(15) << tutor->TutorID << setw(20) << tutor->Name << setw(20) << tutor->Tuition_Center_Name 
				<< setw(20)	<< tutor->Date_Terminated << setw(25) << tutor->Phone << tutor->Address << endl;
			tutor = tutor->NextAddress;
		}
		//select the tutor record to modify
		cout << endl << "Select the number of tutor to modify (0 exit to main menu): ";
		cin >> select;
		while (cin.fail() || select < -1 || select > No) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Select the number of tutor to modify (0 exit to main menu): ";
			cin >> select;
		}
		if (select != 0) {
			tutor = Thead;
			int position = 0;
			//get the selected tutor record
			while (tutor != NULL) {
				position++;
				if (position == select) {
					break;
				}
				tutor = tutor->NextAddress;
			}
			//select the modify option
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
			//modify phone
			if (select == 1) {
				cout << endl << endl << "Enter new phone no. : ";
				getline(cin, newData);
				tutor->Phone = newData;
			}
			//modify address
			else if (select == 2) {
				cout << endl << endl << "Enter new address : ";
				getline(cin, newData);
				tutor->Address = newData;
			}
			//modify terminated date
			else {
				cout << endl << endl << "Enter Teminated Date (DD/MM/YYYY): ";
				getline(cin, newData);
				tutor->Date_Terminated = newData;
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
void modifyStudent() {
	int select;
	string tname = "";	//no specify the tiotion name
	do {
		system("CLS");
		//the admin to access is not from the headquater
		if (loginAdmin->location != "Bukit Jalil") {
			//assign the specific tuition name
			tname = loginAdmin->location;
		}
		int No = 0;
		//display top row of the table
		cout << string(100, '-') << endl;
		cout << left << setw(5) << "No." << setw(15) << "Student ID" << setw(20) << "Name" << setw(20) << "Phone"
			<< setw(25) << "Tuition" << setw(25) << "Subject" << endl;
		cout << string(100, '-') << endl;
		Student* student = Shead;
		//the tuition name is no specify
		//display all the student record in table list with modifiable attribute
		if (tname == "") {
			while (student != NULL) {
				No++;
				cout << left << setw(5) << No << setw(15) << student->StudentID << setw(20) << student->Name << setw(20)
					<< student->Phone << setw(25) << student->Tuition_Center_Name;
				for (int i = 0; i < sizeof(student->subject) / sizeof(student->subject[0]); i++) {
					if (student->subject[i] != "\0") {
						cout << student->subject[i] << ", ";
					}
				}
				cout << endl;
				student = student->nextAddress;
			}
		}
		//has a specific tuition name
		//display all the specific tuition student record in table list with modifiable attribute
		else {
			while (student != NULL) {
				if (student->Tuition_Center_Name == tname) {
					No++;
					cout << left << setw(5) << No << setw(15) << student->StudentID << setw(20) << student->Name << setw(20)
						<< student->Phone << setw(25) << student->Tuition_Center_Name;
					for (int i = 0; i < sizeof(student->subject) / sizeof(student->subject[0]); i++) {
						if (student->subject[i] != "\0") {
							cout << student->subject[i] << ", ";
						}
					}
					cout << endl;
				}
				student = student->nextAddress;
			}
		}
		//prompt to select student to modify
		cout << endl << "Select the number of student to modify (0 exit to main menu): ";
		cin >> select;
		while (cin.fail() || select < -1 || select > No) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Select the number of tutor to modify (0 exit to main menu): ";
			cin >> select;
		}
		if (select != 0) {
			student = Shead;
			int position = 0;
			//to get the selected student record with no specific tutition name
			if (tname == "") {
				while (student != NULL) {
					position++;
					if (position == select) {
						break;
					}
					student = student->nextAddress;
				}
			}
			//to get the selected student record with specific tutition name
			else {
				while (student != NULL) {
					if (student->Tuition_Center_Name == tname) {
						position++;
						if (position == select) {
							break;
						}
					}
					student = student->nextAddress;
				}
			}
			//prompt to select the modify option
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
			//modify phone
			if (select == 1) {
				cout << endl << endl << "Enter new phone no. : ";
				getline(cin, newData);
				student->Phone = newData;
			}
			//modify address
			else if (select == 2) {
				cout << endl << endl << "Enter new address : ";
				getline(cin, newData);
				student->Address = newData;
			}
			//modify tuition record
			else if(select == 3){
				cout << endl << endl << "Tuition: " << endl;;
				Tuition* tuition = TThead;
				int no = 1;
				// list all the tuition to select
				while (tuition != NULL) {
					cout << "\t[" << no << "] " << tuition->name << endl;
					no++;
					tuition = tuition->nextAddress;
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
				tuition = TThead;
				//to get and assign the new tuition code and name
				for (int i = 1; i < select; i++) {
					tuition = tuition->nextAddress;
				}
				student->Tuition_Center_Code = tuition->code;
				student->Tuition_Center_Name = tuition->name;
			}
			//modify subject list
			else {
				int SJnum = 0;
				string SJCode[20] = {};
				string SJName[20] = {};
				Subject* subject = SJhead;
				//save all the subject name and code in list for easy retrieved
				while (subject != NULL) {
					SJCode[SJnum] = subject->code;
					SJName[SJnum] = subject->name;
					SJnum++;
					subject = subject->nextAddress;
				}
				//list all the subject to select
				cout << "Subject" << ": " << "[1]" << SJName[0] << endl;
				for (int i = 1; SJName[i] != "\0"; i++) {
					cout << string(10, ' ') << "[" << i + 1 << "] " << SJName[i] << endl;
				}
				//get the total number of subject the student joined
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
				//save the subject to the subject list
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
				//save the new subject list
				for (int i = 0; i < 10; i++) {
					student->subject[i] = newlist[i];
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
void modifyAdmin() {
	int select;
	do {
		system("CLS");
		cout << "Modify Admin record" << endl << endl;
		//display all admin record
		displayAdmin();
		//prompt to select the admin record to modify location
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
			Admin* admin = Ahead;
			int position = 0;
			//get the select admin record
			while (admin != NULL) {
				position++;
				if (position == select) {
					break;
				}
				admin = admin->nextAddress;
			}
			//ensure the modify record is not manager record
			if (admin->position != "Manager") {
				//enter and save new location
				cout << endl << endl << "Enter new location : ";
				getline(cin, newData);
				admin->location = newData;
				cout << "Modify done!" << endl;
			}
			//the modify record is manager record
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


// to calculate the days between two date
int calculate_days(Tutor* tutor) {
	//to identified the position of "/" symbol
	int first = tutor->Date_Terminated.find("/");
	int second = tutor->Date_Terminated.find("/", first+1);

	//to get the day, month, year from the string date
	int day = stoi(tutor->Date_Terminated.substr(0, first));
	int month = stoi(tutor->Date_Terminated.substr(first + 1, second - first - 1));
	int year = stoi(tutor->Date_Terminated.substr(tutor->Date_Terminated.length() - 4));
	
	//calcualte the day of the date
	int days = 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + day - 306;
	
	//get the current system time
	time_t theTime = time(NULL);
	struct tm* aTime = localtime(&theTime);

	//to get the current system day, month, year
	int Cday = aTime->tm_mday;
	int Cmonth = aTime->tm_mon + 1;
	int Cyear = aTime->tm_year + 1900;

	//calcualte the day of the current date
	int Cdays = 365 * Cyear + Cyear / 4 - Cyear / 100 + Cyear / 400 + (153 * Cmonth - 457) / 5 + Cday - 306;

	//return the the days between two date
	return (Cdays - days);
}


//delete record from specific location function
//tutor
void deleteTutor() {
	//sort tutor record by tutor name
	sortTutorName;
	int select;
	do {
		system("CLS");
		int No = 0;
		cout << string(80, '-') << endl;
		cout << left << setw(5) << "No." << setw(15) << "Tutor ID" << setw(20) << "Name" << setw(20) << "Date Terminated"
			<< setw(25) << "Tuition Center" << endl;
		cout << string(80, '-') << endl;
		Tutor* tutor = Thead;
		//display tutor record with terminated date more than 6 month
		while (tutor != NULL) {
			//to get the terminated totur record
			if(tutor->Date_Terminated!="-"){
				//calculate the duration of terminated date
				int days = calculate_days(tutor);
				//check the terminated tutor record is more than 6 month (182.5 day) 
				if (days > 182.5) {
					//display the deletable tutor record
					No++;
					cout << left << setw(5) << No << setw(15) << tutor->TutorID << setw(20) << tutor->Name << setw(20)
						<< tutor->Date_Terminated << setw(25) << tutor->Tuition_Center_Name << endl;
				}
			}
			tutor = tutor->NextAddress;
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

				tutor = Thead;
				int position = 0;
				int showListPosition = 0;
				//get the actually position of the selected record in the tutor record
				while (tutor != NULL) {
					position++;
					if (tutor->Date_Terminated != "-") {
						int days = calculate_days(tutor);
						if (days > 182.5) {
							showListPosition++;
							if (showListPosition == select) {
								select = position;
								break;
							}
						}
					}
					tutor = tutor->NextAddress;
				}

				//delete the specific position tutor record
				Tutor* current = NULL;
				//scenario 1: list is empty?
				if (Thead == NULL) {
					cout << "Empty List! No deletion needed! " << endl;
				}
				//scenario 2: list is position 1
				else if (select == 1) {
					current = Thead;
					Thead = Thead->NextAddress;
					if (Thead != NULL) { //head is still not empty
						Thead->PrevAddress = NULL;
					}
					else {   //head = NULL
						Ttail = NULL;
					}
					cout << "The tutor ID of " << current->TutorID << " is deleted now!" << endl;
					delete current;
					TutorSize--;
				}
				//scenario 3: position = last position (size of linked list)
				else if (select == TutorSize) {
					current = Ttail;
					Ttail = Ttail->PrevAddress;
					if (Ttail != NULL) { //tail is still not empty
						Ttail->NextAddress = NULL;
					}
					else {  //tail = NULL
						Thead = NULL;
					}
					cout << "The tutor ID of " << current->TutorID<< " is deleted now!" << endl;
					delete current;
					TutorSize--;
				}
				//scenario 4: position not the first and not the last - middle position
				else {
					current = Thead->NextAddress;
					int current_positon = 2;
					while (current != NULL) {
						if (current_positon == select) {
							current->PrevAddress->NextAddress = current->NextAddress;
							current->NextAddress->PrevAddress = current->PrevAddress;
							cout << "The tutor ID of " << current->TutorID << " is deleted now!" << endl;
							delete current;
							TutorSize--;
							break;
						}
						current = current->NextAddress;
						current_positon++;
					}
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
	}while(select != 0);
}
//student
void deleteStudent() {
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
		Student* student = Shead;
		//the tuition name is no specific
		//display all the student record
		if (tname == "") {
			while (student != NULL) {
				No++;
				cout << left << setw(5) << No << setw(15) << student->StudentID << setw(20) << student->Name << setw(20)
					<< student->Phone << setw(25) << student->Tuition_Center_Name;
				for (int i = 0; i < sizeof(student->subject) / sizeof(student->subject[0]); i++) {
					if (student->subject[i] != "\0") {
						cout << student->subject[i] << ", ";
					}
				}
				cout << endl;
				student = student->nextAddress;
			}
		}
		//display the specific tuition student record
		else {
			while (student != NULL) {
				if (student->Tuition_Center_Name == tname) {
					No++;
					cout << left << setw(5) << No << setw(15) << student->StudentID << setw(20) << student->Name << setw(20)
						<< student->Phone << setw(25) << student->Tuition_Center_Name;
					for (int i = 0; i < sizeof(student->subject) / sizeof(student->subject[0]); i++) {
						if (student->subject[i] != "\0") {
							cout << student->subject[i] << ", ";
						}
					}
					cout << endl;
				}
				student = student->nextAddress;
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
			student = Shead;
			int position = 0;
			int no = 0;
			//get the actual position of the selected student in the specific tuition
			if (tname != "") {
				while (student != NULL) {
					position++;
					if (student->Tuition_Center_Name == tname) {
						no++;
						if (no == select) {
							select = position;
							break;
						}
					}
					student = student->nextAddress;
				}
			}
			Student* current = NULL;
			//delete student record from a specific position
			//scenario 1: list is empty?
			if (Shead == NULL) {
				cout << "Empty List! No deletion needed! " << endl;
			}
			//scenario 2: list is position 1
			else if (select == 1) {
				current = Shead;
				Shead = Shead->nextAddress;
				if (Shead != NULL) { //head is still not empty
					Shead->previousAddress = NULL;
				}
				else {   //head = NULL
					Stail = NULL;
				}
				cout << "The student of " << current->StudentID << " is deleted now!" << endl;
				delete current;
				StudentSize--;
			}
			//scenario 3: position = last position (size of linked list)
			else if (select == StudentSize) {
				current = Stail;
				Stail = Stail->previousAddress;
				if (Stail != NULL) { //tail is still not empty
					Stail->nextAddress = NULL;
				}
				else {  //tail = NULL
					Shead = NULL;
				}
				cout << "The student of " << current->StudentID << " is deleted now!" << endl;
				delete current;
				StudentSize--;
			}
			//scenario 4: position not the first and not the last - middle position
			else {
				current = Shead->nextAddress;
				int current_positon = 2;
				while (current != NULL) {
					if (current_positon == select) {
						current->previousAddress->nextAddress = current->nextAddress;
						current->nextAddress->previousAddress = current->previousAddress;
						cout << "The student of " << current->StudentID << " is deleted now!" << endl;
						delete current;
						StudentSize--;
						break;
					}
					current = current->nextAddress;
					current_positon++;
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
		}
	} while (select != 0);
	system("CLS");
}
//admin
void deleteAdmin() {
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
			Admin* admin = Ahead;
			//check the selected record is manager record
			while (admin != NULL) {
				position++;
				if (position = select) {
					if (admin->position == "Manager") {
						cout << "Manager Record cannot delete!" << endl;
						manager = true;
						break;
					}
					break;
				}
			}
			//the select record is not manager record
			if (!manager) {
				Admin* current = NULL;
				//delete admin record from a specific position
				//scenario 1: list is empty?
				if (Ahead == NULL) {
					cout << "Empty List! No deletion needed! " << endl;
				}
				//scenario 2: list is position 1
				else if (select == 1) {
					current = Ahead;
					Ahead = Ahead->nextAddress;
					if (Ahead != NULL) { //head is still not empty
						Ahead->previousAddress = NULL;
					}
					else {   //head = NULL
						Atail = NULL;
					}
					cout << "The admin of " << current->username << " is deleted now!" << endl;
					delete current;
					AdminSize--;
				}
				//scenario 3: position = last position (equal size of linked list)
				else if (select == AdminSize) {
					current = Atail;
					Atail = Atail->previousAddress;
					if (Atail != NULL) { //tail is still not empty
						Atail->nextAddress = NULL;
					}
					else {  //tail = NULL
						Ahead = NULL;
					}
					cout << "The admin of " << current->username << " is deleted now!" << endl;
					delete current;
					AdminSize--;
				}
				//scenario 4: position not the first and not the last - middle position
				else {
					current = Ahead->nextAddress;
					int current_positon = 2;
					while (current != NULL) {
						if (current_positon == select) {
							current->previousAddress->nextAddress = current->nextAddress;
							current->nextAddress->previousAddress = current->previousAddress;
							cout << "The admin of " << current->username << " is deleted now!" << endl;
							delete current;
							AdminSize--;
							break;
						}
						current = current->nextAddress;
						current_positon++;
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
			}
		}
		system("CLS");
	} while (select != 0);
}
//tuition
void deleteTuition() {
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
			Tuition* current = NULL;
			//delete tuition record from specific position
			//scenario 1: list is empty?
			if (TThead == NULL) {
				cout << "Empty List! No deletion needed! " << endl;
			}
			//scenario 2: list is position 1
			else if (select == 1) {
				current = TThead;
				TThead = TThead->nextAddress;
				if (TThead != NULL) { //head is still not empty
					TThead->PreviousAddress = NULL;
				}
				else {   //head = NULL
					TTtail = NULL;
				}
				cout << "The tuition of " << current->code << " is deleted now!" << endl;
				delete current;
				TuitionSize--;
			}
			//scenario 3: position = last position (equal size of linked list)
			else if (select == TuitionSize) {
				current = TTtail;
				TTtail = TTtail->PreviousAddress;
				if (TTtail != NULL) { //tail is still not empty
					TTtail->nextAddress = NULL;
				}
				else {  //tail = NULL
					TThead = NULL;
				}
				cout << "The tuition of " << current->code << " is deleted now!" << endl;
				delete current;
				TuitionSize--;
			}
			//scenario 4: position not the first and not the last - middle position
			else {
				current = TThead->nextAddress;
				int current_positon = 2;
				while (current != NULL) {
					if (current_positon == select) {
						current->PreviousAddress->nextAddress = current->nextAddress;
						current->nextAddress->PreviousAddress = current->PreviousAddress;
						cout << "The tuition of " << current->code << " is deleted now!" << endl;
						delete current;
						TuitionSize--;
						break;
					}
					current = current->nextAddress;
					current_positon++;
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
		}
		system("CLS");
	} while (select != 0);
}
//subject
void deleteSubject() {
	system("CLS");
	int select;
	do {
		//display all subject record
		displaySubject();
		//select the subject to  delete
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
			Subject* current = NULL;
			//delete subject from specific position
			//scenario 1: list is empty?
			if (SJhead == NULL) {
				cout << "Empty List! No deletion needed! " << endl;
			}
			//scenario 2: list is position 1
			else if (select == 1) {
				current = SJhead;
				SJhead = SJhead->nextAddress;
				if (SJhead != NULL) { //head is still not empty
					SJhead->PreviousAddress = NULL;
				}
				else {   //head = NULL
					SJtail = NULL;
				}
				cout << "The subject of " << current->code << " is deleted now!" << endl;
				delete current;
				SubjectSize--;
			}
			//scenario 3: position = last position (size of linked list)
			else if (select == SubjectSize) {
				current = SJtail;
				SJtail = SJtail->PreviousAddress;
				if (SJtail != NULL) { //tail is still not empty
					SJtail->nextAddress = NULL;
				}
				else {  //tail = NULL
					SJhead = NULL;
				}
				cout << "The subject of " << current->code << " is deleted now!" << endl;
				delete current;
				SubjectSize--;
			}
			//scenario 4: position not the first and not the last - middle position
			else {
				current = SJhead->nextAddress;
				int current_positon = 2;
				while (current != NULL) {
					if (current_positon == select) {
						current->PreviousAddress->nextAddress = current->nextAddress;
						current->nextAddress->PreviousAddress = current->PreviousAddress;
						cout << "The subject of " << current->code << " is deleted now!" << endl;
						delete current;
						SubjectSize--;
						break;
					}
					current = current->nextAddress;
					current_positon++;
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
		}
		system("CLS");
	} while (select != 0);
}


//generate report function
void report() {
	// current date/time based on current system
	time_t now = time(0);
	// convert now to string form
	char* date = ctime(&now);

	cout << left << setw(80) << "Title - eXcel Tuition Centre Report" << "Date: " << date << endl << endl;
	sortTutorName();
	cout << string(110, '-') << endl << setw(5) << "NO." << setw(10) << "Tutor ID" << setw(28) << "Name" << setw(10) << "Gender"
		<< setw(10) << "Rating" << setw(20) << "Date Terminated" << "Tuition Center" << endl << string(110, '-') << endl;
	//display all tutor record based on the tuition center
	Tuition* tuition = TThead;
	while (tuition != NULL) {
		int No = 0;
		int count = 0;
		Tutor* tutor = Thead;
		while (tutor != NULL) {
			if (tutor->Tuition_Center_Code == tuition->code) {
				if (tutor->Date_Terminated == "-") {
					count++;
				}
				No++;
				cout << setw(5) << No << setw(10) << tutor->TutorID << setw(28) << tutor->Name << setw(10) << tutor->Gender 
					<< setw(10) << fixed << setprecision(1) << tutor->Rating[0]/ tutor->Rating[1] << setw(20) 
					<< tutor->Date_Terminated << tutor->Tuition_Center_Name << endl;
			}
			tutor = tutor->NextAddress;
		}
		//calculate and display the available vacancy of each tuition center (each tuition maximum 10 tutor)
		cout << endl << "Tuition Name: " << setw(20) << tuition->name << "Available Vaccancy: " << 10 - count << endl << endl;
		cout << string(110, '-') << endl;
		tuition = tuition->nextAddress;
	}
	system("pause");
	system("CLS");
}


//user main menu funtion
void managerMenu() {
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
		//select function to access
		cout << "Enter the number of the function to access: ";
		cin >> select;
		while (cin.fail() || select < -1 || select > 10) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Enter the number of the function to access: ";
			cin >> select;
		}
		//add record
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
		//display record
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
				//sort tutor record by tutor name
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
			else if(select == 4){
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
		//search by tutor id
		else if (select == 3) {
			searchByTutorID();
		}
		//search by rating
		else if (select == 4) {
			searchByRate();
		}
		//sort and diaplay by id
		else if (select == 5) {
			system("CLS");
			cout << "Sort and display by Tutors ID in ascending order: " << endl << endl;
			sortTutorID();
			displayTutorListOnly();
			cout << endl;
			system("pause");
			system("CLS");
		}
		//sort and diaplay by pay rate
		else if (select == 6) {
			system("CLS");
			cout << "Sort and display by Tutors Hourly Pay Rate in ascending order: " << endl << endl;
			sortTutorHourPay();
			displayTutorListOnly();
			cout << endl;
			system("pause");
			system("CLS");
		}
		//sort and diaplay by rating
		else if (select == 7) {
			system("CLS");
			cout << "Sort and display by Tutors Overall Performance in ascending order: " << endl << endl;
			sortTutorRate();
			displayTutorListOnly();
			cout << endl;
			system("pause");
			system("CLS");
		}
		//modify record
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
			else{
				modifyAdmin();
			}
		}
		//delete record
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
			//exit
			if (select == 1) {
				exit(0);
			}
			//no exit
			else {
				select = -1;
				system("CLS");
			}
		}
	}while (select != 0);

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void adminMenu() {
	int select;
	do {
		cout << "=== Admin Main Menu ===" << endl << endl;
		cout << "Please select a function:" << endl;
		cout << "\t[1] Add Record" << endl << "\t[2] Display Record" << endl 
			<< "\t[3] Search a Tutor by Tutor ID" << endl
			<< "\t[4] Search Tutors by overall performance (Rating)" << endl 
			<< "\t[5] Sort and display by Tutors ID in ascending order" << endl
			<< "\t[6] Sort and display by Tutors Hourly Pay Rate in ascending order" << endl
			<< "\t[7] Sort and display by Tutors Overall Performance in ascending order" << endl
			<< "\t[8] Modify Student Record" << endl << "\t[9] Delete Student Record" 
			<< endl << "\t[0] Logout" << endl << "\t[-1] Exit" << endl << endl;
		cout << "Enter the number of the function to access: ";
		cin >> select;
		while (cin.fail() || select < -1 || select > 9) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Enter the number of the function to access: ";
			cin >> select;
		}
		//add record
		if (select == 1) {
			cout << endl << "Select a record to add: " << endl << "\t[1] Tutor" << endl 
				<< "\t[2] Student" << endl << endl;
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
		//display record
		else if (select == 2) {
			cout << endl << "Select a record to display: " << endl << "\t[1] Tutor" 
				<< endl << "\t[2] Student" << endl <<
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
		//search by tutor ID
		else if (select == 3) {
			searchByTutorID();
		}
		//search by rate
		else if (select == 4) {
			searchByRate();
		}
		//sort and display by ID
		else if (select == 5) {
			system("CLS");
			cout << "Sort and display by Tutors ID in ascending order: " << endl << endl;
			sortTutorID();
			displayTutorListOnly();
			cout << endl;
			system("pause");
			system("CLS");
		}
		//sort and display by pay rate
		else if (select == 6) {
			system("CLS");
			cout << "Sort and display by Tutors Hourly Pay Rate in ascending order: " << endl << endl;
			sortTutorHourPay();
			displayTutorListOnly();
			cout << endl;
			system("pause");
			system("CLS");
		}
		//sort and display by rating
		else if (select == 7) {
			system("CLS");
			cout << "Sort and display by Tutors Overall Performance in ascending order: " << endl << endl;
			sortTutorRate();
			displayTutorListOnly();
			cout << endl;
			system("pause");
			system("CLS");
		}
		//modify student record
		else if (select == 8) {
			modifyStudent();
		}
		//delete student record
		else if (select == 9) {
			deleteStudent();
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
		//exit
		if (select == 1) {
			exit(0);
		}
		//no exit
		else {
			select = -1;
			system("CLS");
		}
		}
	} while (select != 0);

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void StudentMenu() {
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
			cout << left << setw(20) << "-Student ID" << ": " << loginStudent->StudentID << endl;
			cout << setw(20) << "-Name" << ": " << loginStudent->Name << endl;
			cout << setw(20) << "-Date of Birth" << ": " << loginStudent->DoB << endl;
			cout << setw(20) << "-Age" << ": " << loginStudent->Age << endl;
			cout << setw(20) << "-Gender" << ": " << loginStudent->Gender << endl;
			cout << setw(20) << "-Phone" << ": " << loginStudent->Phone << endl;
			cout << setw(20) << "-Address" << ": " << loginStudent->Address << endl;
			cout << setw(20) << "-Tuition Center" << ": " << loginStudent->Tuition_Center_Name << endl;
			cout << setw(20) << "-Subject" << ": ";
			//display the student joined subject one by one
			for (int i = 0; i < 10; i++) {
				if (loginStudent->subject[i] == "\0") {
					break;
				}
				else {
					Subject* current = SJhead;
					while (current != NULL) {
						if (current->code == loginStudent->subject[i]) {
							cout << current->name << "   ";
							break;
						}
						current = current->nextAddress;
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
			//display the list of tutor that have teach the student
			for (int i = 0; i < 10; i++) {
				if (loginStudent->subject[i] == "\0") {
					break;
				}
				else {
					Tutor* current = Thead;
					while (current != NULL) {
						//the teacher with the same subject code and tuition code
						if (current->Tuition_Center_Code == loginStudent->Tuition_Center_Code && 
							current->Subject_Code==loginStudent->subject[i]) {
							tutor[num] = current->TutorID;
							num++;
							cout << "[" << num << "] " << current->Name << endl;
							break;
						}
						current = current->NextAddress;
					}
				}
			}
			//no tutor record find
			if (num == 0) {
				cout << "No tutor to rate" << endl;
				system("pause");
				system("CLS");
			}
			else {
				//select the tutor to rate
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
				Tutor* TutorRate = Thead;
				//display the detials of selected tutor
				cout << " -----Tutor Detials-----" << endl;
				while (TutorRate != NULL) {
					if (TutorRate->TutorID == tutor[select-1]) {
						cout << "Tutor Name: " << TutorRate->Name << endl;
						cout << "Subject: " << TutorRate->Subject_Name << endl;
						cout << "Tuition: " << TutorRate->Tuition_Center_Name << endl;
						cout << "Rating: " << fixed << setprecision(1) << TutorRate->Rating[0]/ TutorRate->Rating[1] << endl;
						break;
					}
					TutorRate = TutorRate->NextAddress;
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
				//update the rating of tutor with default rating value
				if (TutorRate->Rating[0] == 0) {
					TutorRate->Rating[0] = TutorRate->Rating[0] + rate;
				}
				//update tutor rating
				else {
					TutorRate->Rating[0] = TutorRate->Rating[0] + rate;
					TutorRate->Rating[1] = TutorRate->Rating[1] + 1;
				}
				cout << "Rating Successful" << endl;
				system("pause");
				system("CLS");
			}
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
			}
		}
	} while (select != 0);

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//system login validation function
void login() {
	do {
		//System Title
		cout << string(80, '=') << endl << string(30, ' ') << "eXcel Tuition Centre" << endl;
		cout << string(29, ' ') << "Tutor Managment System" << endl;
		cout << string(80, '=') << endl << endl;

		bool login = false;
		do {
			//get username and password;
			string username, password;
			cout << "- Enter Username: ";
			getline(cin, username);
			cout << "- Enter Password: ";
			getline(cin, password);

			//user validation
			//Admin & Manager
			Admin* AdminCheck = Ahead;
			while (AdminCheck != NULL) {
				if (username == AdminCheck->username && password == AdminCheck->password) {
					loginAdmin = AdminCheck;
					login = true;
					break;
				}
				AdminCheck = AdminCheck->nextAddress;
			}
			//if user not an admin, check student
			if (!login) {
				Student* StudentCheck = Shead;
				while (StudentCheck != NULL) {
					if (username == StudentCheck->StudentID && password == StudentCheck->Password) {
						loginStudent = StudentCheck;
						login = true;
						break;
					}
					StudentCheck = StudentCheck->nextAddress;
				}
			}

			//check which menu should access by the user
			if (loginAdmin != NULL) {
				//login user is manager
				if (loginAdmin->position == "Manager") {
					system("CLS");
					managerMenu();
					system("CLS");
					//logout from the menu
					loginAdmin = NULL;
				}
				//login user is admin
				else {
					system("CLS");
					adminMenu();
					system("CLS");
					//logout from the menu
					loginAdmin = NULL;
				}
			}
			//login user is student
			else if (loginStudent != NULL) {
				system("CLS");
				StudentMenu();
				system("CLS");
				//logout from the menu
				loginStudent = NULL;
			}
			//username and password incorrect
			else {
				cout << endl << "Invalid username or password!" << endl;
				cout << "Please enter again." << endl << endl;
			}
		} while (!login);

	} while (true);
}

int main() {
	//Initialise head & tial of each structure
	Ahead = Atail = NULL;
	Shead = Stail = NULL;
	Thead = Ttail = NULL;
	TThead = TTtail = NULL;
	SJhead = SJtail = NULL;

	// Create predefined record
	PredefinedAdmin();
	PredefinedStudent();
	PredefinedTutor();
	PredefinedTuition();
	PredefinedSubject();

	//call system login function to access the system
	login();

	return 0;
}