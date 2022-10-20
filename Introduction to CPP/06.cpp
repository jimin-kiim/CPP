/* 
File Stream Class
- ofstream(output file stream) : stream class to write on files
- ifstream(input file stream) : stream class to read from files
- fstream(file stream) : stream class to read and write from/to files
*/
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

/*
File Processing
1. opening a file
    - text file? or binary file?
    - in the case of writing, is it appending mode? or truncating? 
    - is file position automatic? or user-control?
2. processing(reading/writing) file
3. closing the file
*/

/*
Text mode and Binary mode
- generally, bianry file processing method is used. 
- text mode is a kind of exceptional case 
129 in text mode : stored as 3 character, 3 bytes of memory (3 ASCII code; ASCII code 1 character : 1 byte)
129 in binary mode(image, video, sound) : stored as 10000001, 1 byte of memory
*/

/*
Specifying modes for member function 'open'
# either using only one mode or combination of several modes( with 'or operator' | ) are available

- ios::in
    opening the file as 'read-only' mode (considering the file as an input)
- ios::out
    opening the file as 'write-only' mode (considering the file as a destination for output)
- ios::binary
    opening the file in binay mode
- ios::ate
    setting the initial position as the end of the file.
    unless this flag is set, the initial position is the beginning of the file.
- ios::app
    performing output operation at the end of the file.
    appending the content to the current content of the file. 
- ios:: trunc 
    if the file is opened for output operations and it already existed, 
    then its previous content is deleted and replaced by the new one. 


Default mode
ofstream : ios::out
ifstream : ios::in
fstream : ios::in|ios::out
*/