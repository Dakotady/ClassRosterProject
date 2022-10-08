#pragma once
#include <string>
using std::string;
#include "degree.h"

// creates Student class.
class Student {

public:
	// assignes courseDaysArraySize Size.
	const static int courseDaysArraySize = 3;

	// Requirments for D1: created variables.
protected:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int courseDays[courseDaysArraySize];
	string program;

public:
	// Requirment for D1:
	Student();

	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int courseDays[], string program); //constructor with parameters

	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	int GetAge();
	int* GetCourseDays();
	string GetDegreeProgram();

	void SetID(string studentID);
	void SetFirstName(string firstName);
	void SetEmailAddress(string emailAddress);
	void SetAge(int age);
	void SetCourseDays(int courseDays[]);
	void SetDegreeProgram(string program);

	void print();
};
