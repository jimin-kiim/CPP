// ofstream : stream class to write on files
// ifstream : stream class to read from files
// fstream : stream class to read and write from/to files
#include <iostream>
#include <fstream> 
using namespace std;

int main(){

    // class & object. create file stream object variable
    ofstream myfile;

    // open file
    myfile.open("example.txt"); 

    // write to the file
    myfile << "Writing to a file.\n";

    // close file 
    myfile.close();
    return 0;
}

// ASCII code : 1 byte. 1 character - 1 byte
// reading 129 as text - 3 bytes 
// reading 129 as binary: 129 = 10000001 - 1 byte

// in general, file is read and written in binary mode