#pragma once
#include <string>
#include "roster.h"
using std::cout;
using std::endl;

// Requirments for E1: empty constructor.
Roster::Roster() {
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

// Requirments for E1: constructor that sets max capacity for roster.
Roster::Roster(int capacity) {
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [capacity];
}

// Requirments for F5: Roster Destuctor.
Roster::~Roster() {//destroys all the students (Descructor)
	for (int i = 0; i <= lastIndex; i++) {
		delete this->classRosterArray[i]; //deletes each student first
	}
	delete classRosterArray; //deletes the dynamically allocated array of pointers to students

}

// Requirments for E2: Parses and adds data.
void Roster::parseThenAdd(string row) {



	// gets student ID.
	int rightHandSide = row.find(",");
	string studentIDTemp = row.substr(0, rightHandSide);

	// gets firstName.
	int leftHandSide = rightHandSide + 1;
	rightHandSide = row.find(",", leftHandSide);
	string firstNameTemp = row.substr(leftHandSide, rightHandSide - leftHandSide);

	// gets lastName.
	leftHandSide = rightHandSide + 1;
	rightHandSide = row.find(",", leftHandSide);
	string lastNameTemp = row.substr(leftHandSide, rightHandSide - leftHandSide);

	// gets emailAddress.
	leftHandSide = rightHandSide + 1;
	rightHandSide = row.find(",", leftHandSide);
	string emailAddressTemp = row.substr(leftHandSide, rightHandSide - leftHandSide);

	// gets age.
	leftHandSide = rightHandSide + 1;
	rightHandSide = row.find(",", leftHandSide);
	int ageTemp = std::stoi(row.substr(leftHandSide, rightHandSide - leftHandSide));

	// gets course days 1 value.
	leftHandSide = rightHandSide + 1;
	rightHandSide = row.find(",", leftHandSide);
	int courseDays1Temp = std::stoi(row.substr(leftHandSide, rightHandSide - leftHandSide));

	// gets course days 2 value.
	leftHandSide = rightHandSide + 1;
	rightHandSide = row.find(",", leftHandSide);
	int courseDays2Temp = std::stoi(row.substr(leftHandSide, rightHandSide - leftHandSide));

	// gets course days 3 value.
	leftHandSide = rightHandSide + 1;
	rightHandSide = row.find(",", leftHandSide);
	int courseDays3Temp = std::stoi(row.substr(leftHandSide, rightHandSide - leftHandSide));

	// gets degree program.
	leftHandSide = rightHandSide + 1;
	rightHandSide = row.find(",", leftHandSide);
	string degreeProgramTemp = row.substr(leftHandSide, rightHandSide - leftHandSide);

	//adds the students to the roster.
	add(studentIDTemp, firstNameTemp, lastNameTemp, emailAddressTemp, ageTemp, courseDays1Temp, courseDays2Temp, courseDays3Temp, degreeProgramTemp);
}

// Requirment for E3: sets the instance variables from part D1 and updates the roster.
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string program) {

	lastIndex++;

	int courseDaysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, courseDaysArray, program);
};

// Requirment for E3: prints all students in classRosterArray.
void Roster::printAll() {

	for (int i = 0; i <= this->lastIndex; i++) {
		(this->classRosterArray)[i]->print();
	}
}

// Requirment for E3: prints average days in course.
void Roster::printAverageDaysInCourse(string studentID) {
	bool found = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->GetStudentID() == studentID) {
			found = true;
			int* days = classRosterArray[i]->GetCourseDays();
			cout << "Average number of course days " << studentID << " is " << (days[0] + days[1] + days[2]) / 3 << endl;
		}

	}
}

// Requirment for E3:  that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
void Roster::remove(string Id) {
	bool found = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->GetStudentID() == Id) {
			found = true;
			delete this->classRosterArray[i];			
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
	}
	if (found == true) {
		cout << "STUDENT " << Id << " REMOVED." << endl;
	}
	else {
		cout << "STUDENT " << Id << " NOT FOUND." << endl;
	}
}

// checks student count.
bool Roster::checkNumStudents(int numStudents) {
	if (numStudents != lastIndex - 1) {
		return false;
	}
	else {
		return true;
	}

}

// gets student index.
Student* Roster::getStudentIndex(int index) {
	return classRosterArray[index];
}

// requirment for E3: prints out student information for a degree program specified by an enumerated type.
void Roster::printByDegreeProgram(Degree degreeProgram) {

	string program = "";

	if (degreeProgram == 0)
	{
		program = "SECURITY";
	}
	else if (degreeProgram == 1)
	{
		program = "NETWORK";
	}
	else if (degreeProgram == 2)
	{
		program = "SOFTWARE";
	}

	 for (int i = 0; i <= lastIndex; i++) {
		  if (this->classRosterArray[i]->GetDegreeProgram() == program) this->classRosterArray[i]->print();
	 }
}


// validates email per student.
bool is_email_valid(const std::string& email) {

	if (email.find(" ") != string::npos or email.find("@") == string::npos or email.find(".") == string::npos)
	{
		return false;
	}
	else
	{
		return true;
	}	
};

// Requirment for E3: erifies student email addresses and displays all invalid email addresses to the user.
void Roster::printInvalidEmails() {

	for (int i = 0; i <= this->lastIndex; i++) {
		string testEmail = (this->classRosterArray)[i]->GetEmailAddress();
		bool isValidEmail = is_email_valid(testEmail);
		if (!isValidEmail) {
			cout << testEmail << " is not a valid email." << endl;
		}
	}

}