#include<iostream>
using namespace std;
#include "student.h"

Student::Student(){
    lastName = "";
    firstName = "";
    uid = 0;
    head = NULL;
}

Student :: Student(string newLastName, string newFirstName, unsigned int newUid){
    lastName = newLastName;
    firstName = newFirstName;
    uid = newUid;
    head = NULL;
    
}

void Student :: print(ostream& out){
    // out << lastName << ", " << firstName << " [U" << uid << "]" << endl;
    // cout<<head->course; 

    GradeListNode* current = head; 

    while (current != NULL){

    out << " " << current->course << ": " << current->grade << endl; 

    current = current->next; 

    } 
}

void Student :: addGrade(string newGrade, string newCourse){
   
    if (head == NULL){ 

        head = new GradeListNode(newCourse, newGrade); 

    } 

    else { 

        GradeListNode* current = head; 

        while (current->next != NULL){ 

        current = current->next; 

        } 

        current->next = new GradeListNode(newCourse, newGrade); 
    }
 
}

GradeListNode :: GradeListNode(string newCourse, string newGrade){
    grade = newGrade;
    course = newCourse;
    next = NULL;
}