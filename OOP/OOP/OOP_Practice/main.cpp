#include<iostream>
#include "student.cpp"
using namespace std;

int main(){
    Student* StudentPtr;
    Student student1("konatham","bharath",1029016);
   // student1.print(cout);

    StudentPtr = new Student("konatham","bharath",1029016);
    StudentPtr->addGrade("CS3100","A");
    StudentPtr->addGrade("CEG4350","A+");
    StudentPtr->print(cout);
    delete StudentPtr;
}