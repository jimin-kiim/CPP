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