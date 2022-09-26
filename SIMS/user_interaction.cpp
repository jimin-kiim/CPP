#include <iostream>
#include "user_interaction.h"
#include "student_data.h"
using namespace std;

void UserInteraction::ShowMainMenu()
{
    cout << "1. Insertion\n 2. Search\n 3. Sorting Option\n 4. Exit\n >";
}

void UserInteraction::ShowInsertionView()
{
    Student student;

    cout << "Name ? ";
    cin.ignore(256,'\n');
    getline(cin, student.name);
    cout << "Student ID ? (10 digits)";
    cin >> student.studentId;
    cout << "Birth Year ? (4 digits)";
    cin >> student.birthYear;
    cout << "Department ? ";
    cin.ignore(256,'\n');
    getline(cin, student.department);
    cout << "Tel ? ";
    cin >> student.department;
}

void UserInteraction::ShowSearchView()
{
    int user_input;
    cout << "- Search -\n";
    cout << "1. Search by name \n ";
    cout << "2. Search by student ID(10 numbers)\n ";
    cout << "3. Search by admission year(4 numbers)\n ";
    cout << "4. Search by department name ";
    cout << "5. List All\n";
    cout << "\n >";
    cin >> user_input;
}

void UserInteraction::ShowSearchResultView()
{

    cout.width(15);
    cout << "Name";
    cout.width(10);
    cout << "StudentID";
    cout.width(15);
    cout << "Dept";
    cout << "Birth Year";
    cout << "Tel";
}

void UserInteraction::ShowSortingOptionView()
{
    int user_input;
    cout << "- Sorting Option -\n";
    cout << "1. Sort by Name \n ";
    cout << "2. Sort by Student ID(10 numbers)\n ";
    cout << "3. Sort by Admission Year(4 numbers)\n ";
    cout << "4. Sort by Department name ";
    cout << "\n >";
    cin >> user_input;
}