
#ifndef __STUDENT_H__ 
#define __STUDENT_H__ 

#include <iostream>
using namespace std;
class Student
{
    string name;
    int studentId;
    int birthYear;
    string department;
    int tel;

public:
    Student(){};
    // Student(Student &);
    Student(string, int, int, string, int);
    // void setName();
    // void setStudentId();
    // void setBirthYear();
    // void setDepartment();
    // void setTel();

    string getName(){return name;};
    int getStudentId(){return studentId;};
    int getBirthYear(){return birthYear;};
    string getDepartment(){return department;};
    int getTel(){return tel;};
};

#endif