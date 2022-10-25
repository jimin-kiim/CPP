#include <iostream>
#include <fstream> // to use file stream class, fstream header file should be included
using namespace std;

int main(){

    // TODO-1: creating file stream object variable
    // class(type) & object. 
    ofstream myfile; // stream that supports writing on files 

    // TODO-2: opening a file
    myfile.open("example.txt"); 
    /* 
        since its mode is ios::out, 
        if there's no file corresponding file, a new file is created. 
        but in the case of file stream object 'ifstream', 
        if there's no corresponding file, the error occurs
    */

    // member function 'open' : open(filename, mode)
    // as the file stream object type is ofstream, the default mode of opening the file is ios::out(write only)

    // TODO-3: writing data(string) to the file
    myfile << "Writing to a file.\n";

    // TODO-4: closing the file after any file processing
    myfile.close();
    return 0;
}