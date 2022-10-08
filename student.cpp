#pragma once
#include <string>
#include "student.h"
#include <iostream>
using std::cout;
using std::endl;


// Requirments for D1: Empty constructor.
Student::Student() {

	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < courseDaysArraySize; i++) {
		this->courseDays[i] = 0;
	}
	this->program = "";

}

// Requirments for D2: uses all input provided by table.
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int courseDays[], string program) {

	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < courseDaysArraySize; i++) {
		this->courseDays[i] = courseDays[i];
	}
	this->program = program;
}


// Requirments for D2: getters.

string Student::GetStudentID() {
	 return studentID;
}

string Student::GetFirstName() {
	 return firstName;
}

string Student::GetLastName() {
	 return lastName;
}

string Student::GetEmailAddress() {
	 return emailAddress;
}

int Student::GetAge() {
	 return age;
}

int * Student::GetCourseDays() {
	 return courseDays;
}

string Student::GetDegreeProgram() {
	return program;
}

// Requirments for D2: setters.

void Student::SetID(string studentID) {
	 this->studentID = studentID;
}

void Student::SetFirstName(string firstName) {
	 this->firstName = firstName;
}

void Student::SetEmailAddress(string emailAddress) {
	 this->emailAddress = emailAddress;
}

void Student::SetAge(int age) {
	 this->age = age;
}

void Student::SetCourseDays(int courseDays[]) {
	 for (int i = 0; i < courseDaysArraySize; i++) {
		  this->courseDays[i] = courseDays[i];
	}
}

void Student::SetDegreeProgram(string program) {
	this->program = program;
}

//Requirment for D2: displays all fields
void Student::print() {
	cout << "\t" << "First Name: " << firstName;
	cout << "\t" << "Last Name: " << lastName;
	cout << "\t" << "Age: " << age;
	cout << "\t" << "daysInCourse: {" << courseDays[0] << ", " << courseDays[1] << ", " << courseDays[2] << "} ";
	cout << "Degree Program: " << program << endl;
}