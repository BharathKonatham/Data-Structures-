#include <iostream> 

#include <string> 

#include "student.h" 

using namespace std; 

void messWithJake(Student); 

int main() { 



 // Create a student object and add a few grades 

 Student student1("Raymer", "Jake", 123); 

student1.addGrade("CS 1180", "B"); 

student1.addGrade("CS 1181", "C"); 

cout << "Jake in main()" << endl; 

 student1.print(cout); 

  

 // Here we go Jake 

 messWithJake(student1); 

 cout << "Jake, back in main() again" << endl; 

 student1.print(cout); 

 

 // Let's look for memory leaks 

 Student* studentPtr; 

 cout << "Before memory leak test" << endl; 

 system("pause"); 

 for (int i = 0; i < 10000; i++){ 

  studentPtr = new Student("Student", "Test", 12345); 

  for (int j=0; j < 1000; j++){ 

   studentPtr->addGrade("CS 1000", "A"); 

  } 

  delete studentPtr; 

 } 

 cout << "After memory leak test" << endl; 

 system("pause"); 

  

} 

void messWithJake(Student jake){ 

 jake.uid = 999; 

 jake.head->grade = "F"; 

 jake.lastName.append("son"); 

 cout << "Changed Jake!" << endl; 

 jake.print(cout); 

} 