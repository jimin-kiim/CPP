#include <iostream>
#include "student.h"
using namespace std;

Student::Student(string name, string studentId, int birthYear, string department, string tel)
{
    this->name = name;
    this->studentId = studentId;
    this->birthYear = birthYear;
    this->department = department;
    this->tel = tel;
}
// void Student::setName(string name)
// {
// }
// void Student::setStudentId(int studentId)
// {
// }
// void Student::setBirthYear(int birthYear)
// {
// }
// void Student::setDepartment(string department)
// {
// }
// void Student::setTel(int tel)
// {
// }
