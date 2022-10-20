#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string line;
    ifstream myfile ("example.txt");
    /* 
        since the mode is ios::in(default), 
        if there's no corresponding file, 
        an error occurs. so the if statement is needed
    */
    if (myfile.is_open()){ // if there exists a file called "example.txt"
        while (getline (myfile, line)){
            cout << line << '\n';
        }
        myfile.close();
    }else cout << "Unable to open file"; // if there's no file called "example.txt"

    return 0;
}