//G3_TP062572_TP062011_TP061980
//This header file is all about the structure of the linked list
using namespace std;

//Admin linked list structure
struct Admin
{
	string username;
	string password;
	string position;
	string location;
	Admin* nextAddress;
	Admin* previousAddress;
} *Ahead, * Atail;

//Student linked list structure
struct Student
{
	string StudentID;
	string Password;
	string Name;
	string DoB;
	int Age;
	char Gender;
	string Phone;
	string Address;
	string Tuition_Center_Code;
	string Tuition_Center_Name;
	string subject[10];
	Student* nextAddress;
	Student* previousAddress;
} *Shead, * Stail;

//Tutor linked list structure
struct Tutor
{
	string TutorID;
	string Name;
	string DoB;
	int Age;
	char Gender;
	string Date_Joined;
	string Date_Terminated;
	double Hourly_Pay_Rate;
	string Phone;
	string Address;
	string Education;
	string Tuition_Center_Code;
	string Tuition_Center_Name;
	string Subject_Code;
	string Subject_Name;
	double Rating[2];	//Rating { total rating, number of rate}
	Tutor* NextAddress;
	Tutor* PrevAddress;
} *Thead, * Ttail;

//Tuition linked list structure
struct Tuition
{
	string code;
	string name;
	Tuition* nextAddress;
	Tuition* PreviousAddress;
}*TThead, * TTtail;

//Subject linked list structure
struct Subject
{
	string code;
	string name;
	Subject* nextAddress;
	Subject* PreviousAddress;
}*SJhead, * SJtail;