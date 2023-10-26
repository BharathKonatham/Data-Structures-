#pragma once
#include<iostream>
using namespace std;
#include<string>
class Student;


class GradeListNode{
    public:
        string course;
        string grade;
        GradeListNode* next;
        GradeListNode(string, string);
        
};


class Student{
    private:
        string lastName;
        string firstName;
        unsigned int uid;
        GradeListNode* head;

       

    public:
        //default constructor
        Student();

        //parameterzied constructor
        Student(string, string, unsigned int);

        //print function
        void  print(ostream&);

        //Add grade 
        void addGrade(string, string);
};