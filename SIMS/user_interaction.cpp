#include <iostream>
#include "user_interaction.h"
#include "student.h"
#include "functioning.h"
using namespace std;

enum option {NAME = 1, STUDENT_ID, ADMISSION_YEAR, DEPARTMENT, ALL};
void UserInteraction::ShowMainMenu()
{
    cout << "\n";
    cout << " 1. Insertion\n 2. Search\n 3. Sorting Option\n 4. Exit\n > ";
}

Student UserInteraction::ShowInsertionView()
{
    Functioning func;

    string name = " ";
    string studentId = " ";
    string birthYear;
    string department;
    string tel;

    int ok = 0;

    cin.ignore();
    while (1)
    {
        cout << "Name ? ";
        getline(cin, name);
        if (name[0] == ' ' || name[0] == '\0' || name[0] == '\n')
        {
            cout << "Name cannot be blank and cannot start with blank.\n";
        }
        else if (name.length() > 15)
        {
            cout << "Name has up to 15 (English) charaters.\n";
        }
        else
        {
            break;
        }
    }

    while (1)
    {
        cout << "Student ID (10 digits) ? ";
        getline(cin, studentId);
        if (studentId[0] == ' ' || studentId[0] == '\0' || studentId[0] == '\n')
        {
            cout << "Student ID cannot be blank and cannot start with blank.\n";
        }
        else if (studentId.length() != 10)
        {
            cout << "Student ID should be 10 digits\n";
        }
        else
        {
            ok = func.VerifyStudentId(studentId);
            if (ok != -1)
            {
                break;
            }
        }
    }

    while (1)
    {
        cout << "Birth Year (4 digits) ? ";
        cin >> birthYear;
        if (birthYear.length() != 4)
        {
            cout << "Birth Year should be 4 digits\n";
        }
        else
        {
            break;
        }
    }

    cout << "Department ? ";
    cin.ignore();
    getline(cin, department);

    while (1)
    {
        cout << "Tel ? ";
        cin >> tel;
        if (tel.length() > 12)
        {
            cout << "Tel has up to 12 digits.\n";
        }
        else
        {
            break;
        }
    }

    Student student(name, studentId, birthYear, department, tel);
    return student;
}

void UserInteraction::ShowSearchView()
{
    int user_input;
    Functioning func;
    cout << "\n";
    cout << " - Search -\n ";
    cout << "1. Search by name \n ";
    cout << "2. Search by student ID(10 numbers)\n ";
    cout << "3. Search by admission year(4 numbers)\n ";
    cout << "4. Search by department name\n ";
    cout << "5. List All\n";
    cout << "\n > ";
    cin >> user_input;

    string keyword = "";
    switch (user_input)
    {
    case NAME:
        cout << " Name keyword ? ";
        cin.ignore();
        getline(cin, keyword);

        func.SearchData(1, keyword);
        break;

    case STUDENT_ID:
        cout << " Student ID keyword ? ";
        cin.ignore();
        getline(cin, keyword);

        func.SearchData(2, keyword);
        break;

    case ADMISSION_YEAR:
        cout << " Admission year keyword ? ";
        cin.ignore();
        getline(cin, keyword);

        func.SearchData(3, keyword);
        break;

    case DEPARTMENT:
        cout << " Department name keyword ? ";
        cin.ignore();
        getline(cin, keyword);

        func.SearchData(4, keyword);
        break;

    case ALL:
        func.SearchData(5, keyword);
        break;

    default:
        cout << "Wrong Input";
        break;
    }
}

void UserInteraction::ShowSearchResultHeaderView()
{
    cout << "\n";
    cout.width(15);
    cout << left << "Name";
    cout.width(11);
    cout << left << "StudentID";
    cout.width(17);
    cout << left << "Dept";
    cout << " Birth Year";
    cout << left << " Tel\n";
}

void UserInteraction::ShowSearchResultView(Student student)
{
    cout.width(15);
    cout << left << student.getName();
    cout.width(11);
    cout << student.getStudentId();
    cout.width(17);
    cout << student.getDepartment();
    cout.width(11);
    cout << right << student.getBirthYear();
    cout << " " << student.getTel() << "\n";
}

void UserInteraction::ShowSortingOptionView()
{
    int user_input;
    Functioning func;
    cout << "\n";
    cout << " - Sorting Option -\n ";
    cout << "1. Sort by Name \n ";
    cout << "2. Sort by Student ID(10 numbers)\n ";
    cout << "3. Sort by Admission Year(4 numbers)\n ";
    cout << "4. Sort by Department name\n ";
    cout << "> ";
    cin >> user_input;
    func.setSortingOption(user_input);
}