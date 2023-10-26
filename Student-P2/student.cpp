#include "student.h"
#include <iostream>

// Parameterized constructor for a GradeListNode
GradeListNode::GradeListNode(string newCourse, string newGrade){
    course = newCourse;
    grade = newGrade;
    next = NULL;
}

// Default constructor for a student
Student::Student() {
    lastName = "";
    firstName = "";
    uid = 0;
    head = NULL;
}

// Parameterized constructor for a student
Student::Student(string newLastName, string newFirstName,
                    unsigned int newUID){
    lastName = newLastName;
    firstName = newFirstName;
    uid = newUID;
    head = NULL;
}

// Pretty print a student object
void Student::print(ostream& os){
    os << lastName << ", " << firstName << " [U" << uid << "]" << endl;
    GradeListNode* current = head;
    while (current != NULL){
        os << "  " << current->course << ": " << current->grade << endl;
        current = current->next;
    }
}

// Setter for lastName
void Student::setlastName(string newlastName){
    lastName = newlastName;
}

// Add a grade to the linked list for a student
void Student::addGrade(string newCourse, string newGrade){

    // Edge case: no grades in the list - point 'head'
    //   at the new grade
    if (head == NULL){
        head = new GradeListNode(newCourse, newGrade);
    }

    // General case:  Find the last node, and point its
    //  'next' pointer at the new grade
    else {
        GradeListNode* current = head;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = new GradeListNode(newCourse, newGrade);
    }
}