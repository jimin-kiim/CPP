
#ifndef __STUDENT_H__ 
#define __STUDENT_H__ 

#include <iostream>
using namespace std;
class Student
{
    string name;
    string studentId;
    string birthYear;
    string department;
    string tel;

public:
    Student(){};
    Student(string, string, string, string, string);

    string getName(){return name;};
    string getStudentId(){return studentId;};
    string getBirthYear(){return birthYear;};
    string getDepartment(){return department;};
    string getTel(){return tel;};
};

#endif