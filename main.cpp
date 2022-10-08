#pragma once
#include <string>
#include "roster.h"
using std::cout;
using std::endl;


// creates main.
int main() {

// assigns numStudents to 5.
int numStudents = 5;

// assigns student data.
const string studentData[5] = {
	 "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	 "A5,Dakota,Dyche,ddyche2@wgu.edu,26, 30, 45, 50 ,SOFTWARE" };

// Prints requirments for F1: course title, programming language, WGU student ID, and Name.
cout << "Scripting and Programming - Applications C867" << endl;
cout << "Programming language: C++" << endl;
cout << "Student ID: 001503564" << endl;
cout << "Student Name: Dakota Dyche" << endl << "------------------------------------------------------------------------------------------------------------------------" << endl << endl;

// requirments for F2: Create an instance of the Roster class called classRoster.
Roster* classRoster = new Roster(numStudents);

// requirments for F3: builds and creates student data.
for (int i = 0; i < numStudents; i++) {
	classRoster->parseThenAdd(studentData[i]);
}

// requirments for F4: prints classRosterArray.
cout << "Printing ClassRosterArray-->" << endl << endl;
classRoster->printAll();

// requirments for F4: prints invalid emails.
cout << endl << "------------------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
cout << "Checking for invalid emails-->" << endl << endl;
classRoster->printInvalidEmails();

// requirments for F4: prints average days in course.
cout << endl << "------------------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
cout << "Printing average number of days in course-->" << endl << endl;
for (int i = 0; i < numStudents; i++) {
	classRoster->printAverageDaysInCourse(classRoster->getStudentIndex(i)->GetStudentID());
}

// requirments for F4: prints student info by degree.
cout << endl << "------------------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
cout << "Printing student information by a degree program specified by an enumerated type-->" << endl << endl;
classRoster->printByDegreeProgram(SOFTWARE);

// requirments for F4: removes student.
cout << endl << "------------------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
cout << "Remvoving student with ID A3-->" << endl << endl;
classRoster->remove("A3");

if (classRoster->checkNumStudents(numStudents) == false) {
	numStudents--;
}

// requirments for F4: print classRosterArray
cout << endl << "------------------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
cout << "Printing ClassRosterArray-->" << endl << endl;
classRoster->printAll();

// requirments for F4: checks to see if student is still in data set.
cout << endl << "------------------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
cout << "Remvoving student with ID A3-->" << endl << endl;
classRoster->remove("A3");

if (classRoster->checkNumStudents(numStudents) == false) {
	numStudents--;
}

// requirments for F4: calls destructor.
cout << endl << "------------------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
cout << "Calling the roster destructor-->" << endl << endl;
classRoster->~Roster();
cout << "Roster Memory released.";
cout << endl << "------------------------------------------------------------------------------------------------------------------------" << endl;

// ends main.
return 0;

}