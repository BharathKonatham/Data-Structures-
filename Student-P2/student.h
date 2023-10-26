#pragma once
#include <string>

using namespace std;

// The GradeListNode class allows us to build a
// linked list of grades for each student
class GradeListNode {
public:
    string course;
    string grade;
    GradeListNode* next;

    GradeListNode(string, string);
};

// Class student holds all of the information about
// a WSU student
class Student {
private:
    string lastName;
    string firstName;
    unsigned int uid;
    GradeListNode* head;

public:
    // Default constructor
    Student();

    // Parameterized constructor
    Student(string, string, unsigned int);

    // Pretty print
    void print(ostream&);

    // Setter for lastName
    void setlastName(string);

    // Add a grade to the linked list
    void addGrade(string, string);


};