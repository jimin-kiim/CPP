
#ifndef __STUDENT_H__ 
#define __STUDENT_H__ 

#include <iostream>
using namespace std;
class Student
{
    string name;
    string studentId;
    int birthYear;
    string department;
    string tel;

public:
    Student(){};
    // Student(Student &);
    Student(string, string, int, string, string);
    // void setName();
    // void setStudentId();
    // void setBirthYear();
    // void setDepartment();
    // void setTel();

    string getName(){return name;};
    string getStudentId(){return studentId;};
    int getBirthYear(){return birthYear;};
    string getDepartment(){return department;};
    string getTel(){return tel;};
};

#endif