#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "student.h"
#include "functioning.h"

using namespace std;

void Fuctioning::CreateData(Student student)
{
    ofstream myfile;
    myfile.open("file1.txt", ios::app);
    myfile << student.getName() << "," << student.getStudentId() << "," << student.getBirthYear() << "," << student.getDepartment() << "," << student.getTel() << "\n";
    myfile.close();
}

void Fuctioning::SearchData(int criteria, string keyword)
{
    //데이터 읽어와서 저장하고

    // search

    // search 결과 반환
}

void Fuctioning::ReadData()
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
            Student student(tokens[0],tokens[1],tokens[2],tokens[3],tokens[4]);
            students.push_back(student);
            
        }
        cout << "REad data" << students[0].getName() << students[0].getStudentId() << students[0].getDepartment() << students[0].getBirthYear() << students[0].getTel() ;
        myfile.close();
    }
    else
        cout << "Unable to open file";
}

void Fuctioning::SortData()
{

    // sort
    // sort 결과 반환
}
