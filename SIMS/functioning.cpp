#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "user_interaction.h"
#include "student.h"
#include "functioning.h"

using namespace std;

enum option {NAME = 1, STUDENT_ID, ADMISSION_YEAR, DEPARTMENT, ALL};
bool compare(string a, string b)
{
    return (a > b);
}

void Functioning::CreateData(Student student)
{
    ofstream myfile;
    myfile.open("file1.txt", ios::app);
    myfile << student.getName() << "," << student.getStudentId() << "," << student.getBirthYear() << "," << student.getDepartment() << "," << student.getTel() << "\n";
    myfile.close();
}

void Functioning::SearchData(int criteria, string keyword)
{
    vector<Student> students = ReadData();
    SortData(students);
    UserInteraction ui;
    ui.ShowSearchResultHeaderView();

    switch (criteria)
    {
    case NAME:
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].getName() == keyword)
            {
                ui.ShowSearchResultView(students[i]);
            }
        }
        break;
    case STUDENT_ID:
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].getStudentId() == keyword)
            {
                ui.ShowSearchResultView(students[i]);
            }
        }
        break;
    case ADMISSION_YEAR:
        for (int i = 0; i < students.size(); i++)
        {
            string admission_year = students[i].getStudentId().substr(0, 4);
            if (admission_year == keyword)
            {
                ui.ShowSearchResultView(students[i]);
            }
        }
        break;
    case DEPARTMENT:
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].getDepartment() == keyword)
            {
                ui.ShowSearchResultView(students[i]);
            }
        }
        break;
    case ALL:
        for (int i = 0; i < students.size(); i++)
        {
            ui.ShowSearchResultView(students[i]);
        }
        break;
    default:
        cout << "Wrong Input";
        break;
    }
}

vector<Student> Functioning::ReadData()
{
    string line;
    ifstream myfile("file1.txt");
    vector<Student> students;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            stringstream sstream(line);
            vector<string> tokens;
            string token;
            int i = 0;
            while (getline(sstream, token, ','))
            {
                tokens.push_back(token);
            }
            Student student(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4]);
            students.push_back(student);
        }
        myfile.close();
        return students;
    }
    else
        cout << "Unable to open file";
        return students;
}

bool compareName(Student a, Student b)
{
    return (a.getName() < b.getName());
}

bool compareStudentId(Student a, Student b)
{
    return (stoi(a.getStudentId()) < stoi(b.getStudentId()));
}

bool compareAdmissionYear(Student a, Student b)
{
    return (stoi(a.getStudentId().substr(0, 4)) < stoi(b.getStudentId().substr(0, 4)));
}

bool compareDepartmentName(Student a, Student b)
{
    return (a.getDepartment() < b.getDepartment());
}

void Functioning::SortData(vector<Student> &students)
{
    UserInteraction ui;
    int sorting_option = getSortingOption();
    switch (sorting_option)
    {
    case NAME:
        sort(students.begin(), students.end(), compareName);
        break;
    case STUDENT_ID:
        sort(students.begin(), students.end(), compareStudentId);
        break;
    case ADMISSION_YEAR:
        sort(students.begin(), students.end(), compareAdmissionYear);
        break;
    case DEPARTMENT:
        sort(students.begin(), students.end(), compareDepartmentName);
        break;
    default:
        cout<<"Error: sorting option is not specified \n";
        break;
    }
}

int Functioning::VerifyStudentId(string id)
{
    vector<Student> students = ReadData();
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getStudentId() == id)
        {
            cout << "Error : Already inserted\n";
            return -1;
        }
    }
    return 0;
}
