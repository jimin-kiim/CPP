#include <iostream>
#include <fstream> 
#include "student.h"
#include "functioning.h"

using namespace std;

void Fuctioning::InsertNewData(Student student)
{
    // cout<<"InsertNewData";
    ofstream myfile;
    myfile.open("file1.txt"); 
    myfile << student.getName() << ","<< student.getStudentId()<<","<< student.getBirthYear()<<","<<student.getDepartment() << ","<<student.getTel();
    myfile.close();
}

void Fuctioning::SearchData()
{
    //데이터 읽어와서 저장하고 
    string line;
    ifstream myfile ("file1.txt");
    if (myfile.is_open()){
        while (getline (myfile, line)){
            cout << line << '\n';
        }
        myfile.close();
    }else cout << "Unable to open file";
    //search
    //search 결과 반환
}

void Fuctioning::SortData()
{
    //데이터 읽어와서 저장하고 
    string line;
    ifstream myfile ("file1.txt");
    if (myfile.is_open()){
        while (getline (myfile, line)){
            cout << line << '\n';
        }
        myfile.close();
    }else cout << "Unable to open file";
    //sort
    //sort 결과 반환
}
