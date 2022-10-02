#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "user_interaction.h"
#include "student.h"
#include "functioning.h"

using namespace std;

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
    UserInteraction ui;
    ui.ShowSearchResultHeaderView();

    switch (criteria)
    {
    case 1:
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].getName() == keyword)
            {
                ui.ShowSearchResultView(students[i]);
            }
        }
        break;
    case 2:
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].getStudentId() == keyword)
            {
                ui.ShowSearchResultView(students[i]);
            }
        }
        break;
    case 3:
        for (int i = 0; i < students.size(); i++)
        {
            string admission_year = students[i].getStudentId().substr(0, 4);
            if (admission_year == keyword)
            {
                ui.ShowSearchResultView(students[i]);
            }
        }
        break;
    case 4:
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].getDepartment() == keyword)
            {
                ui.ShowSearchResultView(students[i]);
            }
        }
        break;
    case 5:
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
}

void Functioning::SortData()
{

    // sort
    // sort 결과 반환
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