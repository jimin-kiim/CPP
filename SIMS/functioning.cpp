#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "user_interaction.h"
#include "student.h"
#include "functioning.h"

using namespace std;
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
    // for (int i = 0; i < students.size(); i++)
    //     {
    //         ui.ShowSearchResultView(students[i]);
    //     }

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

// void Functioning::SortData(vector<Student> students)
// {
//     switch (sorting_option)
//     {
//     case 1:
//         sort(students.begin()->getName(), students.end()->getName(), compare);
//         break;
//     case 2:
//         sort(students.begin()->getStudentId(), students.end()->getStudentId(), compare);
//         break;
//     case 3:
//         sort(students.begin()->getStudentId().substr(0, 4), students.end()->getStudentId().substr(0, 4), compare);
//         break;
//     case 4:
//         sort(students.begin()->getDepartment(), students.end()->getDepartment(), compare);
//         break;
//     default:
//         cout << "Wrong Input";
//         break;
//     }
// }

bool compareName(Student a, Student b)
{
    return (a.getName() > b.getName());
}

bool compareStudentId(Student a, Student b)
{
    return (stoi(a.getStudentId()) > stoi(b.getStudentId()));
}

bool compareAdmissionYear(Student a, Student b)
{
    return (stoi(a.getStudentId().substr(0, 4)) > stoi(b.getStudentId().substr(0, 4)));
}

bool compareDepartmentName(Student a, Student b)
{
    return (a.getDepartment() > b.getDepartment());
}

void Functioning::SortData(vector<Student> &students)
{
    UserInteraction ui;
    int sorting_option = getSortingOption();
    cout << "sorting_option" << sorting_option << "\n";
    switch (sorting_option)
    {
    case 1:
        sort(students.begin(), students.end(), compareName);
        // for (int i = 0; i < students.size(); i++)
        // {
        //     ui.ShowSearchResultView(students[i]);
        // }
        break;
    case 2:
        sort(students.begin(), students.end(), compareStudentId);
        // for (int i = 0; i < students.size(); i++)
        // {
        //     ui.ShowSearchResultView(students[i]);
        // }
        break;
    case 3:
        sort(students.begin(), students.end(), compareAdmissionYear);
        // for (int i = 0; i < students.size(); i++)
        // {
        //     ui.ShowSearchResultView(students[i]);
        // }
        break;
    case 4:
        sort(students.begin(), students.end(), compareDepartmentName);
        break;
    default:
    sort(students.begin(), students.end(), compareName);
        // cout << "Wrong Input";
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
