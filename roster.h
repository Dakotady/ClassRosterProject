#pragma once
#include <string>
#include <iostream>
#include "student.h"

// Creates the Roster Class that stores a collection of students.
class Roster {
private:

	// this captures the index of last student in roster.
	int lastIndex;

	// logs the max the Roster can be.
	int capacity; 

	// this points the classRosterArray to the students class.
	Student** classRosterArray; 

public:
	// creates empty constructor for roster and assigns default values.
	Roster();

	// assigns max size for roster.
	Roster(int capacity);

	// gets student index.
	Student* getStudentIndex(int index);

	// checks the number of students returns bool value.
	bool checkNumStudents(int numStudents);

	// parses data and creates student objects.
	void parseThenAdd(string row);

	// populate variables from parsed data.
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1,
		int daysInCourse2, int daysInCourse3, string program);

	// removes student from roster or identifies student does not exist
	void remove(string studentID);

	//  loops through classRosterArray function for each student.
	void printAll();

	// returns each students average number of days in the courses.
	void printAverageDaysInCourse(string studentID);

	// verifies email is formated correctly, and contains '@' and '.' with no spaces. this will also return all invalid emails.
	void printInvalidEmails(); 

	// prints each students information by the enumerated degree.
	void printByDegreeProgram(Degree degreeProgram);

	// Creates destructor.
	~Roster();
};
