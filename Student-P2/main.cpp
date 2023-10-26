#include <iostream>
#include <string>
#include "student.h"

using namespace std;


int main() {

    Student* studentPtr;
    
    // Create a student object and add a few grades
    Student student1("Raymer", "Mike", 123);
    student1.addGrade("CS 1180", "B");
    student1.addGrade("CS 1181", "C");

    student1.print(cout);
    
    // Use a setter to change the last name
    student1.setlastName("Smith");
    student1.print(cout);

    // This student object lives on the heap, and
    // is pointed to by studentPtr!
    studentPtr = new Student("Raymer", "Delia", 456);
    (*studentPtr).print(cout);
    studentPtr->print(cout);

    // Since we did new(), we should delete when we
    // don't need the object anymore
    delete studentPtr;
}