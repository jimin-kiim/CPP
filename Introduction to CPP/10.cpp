#include <iostream>
#include <fstream>
using namespace std;

int main(){
    streampos size;
    char * memblock;
    ifstream file("example.bin", ios::in|ios::binary|ios::ate); // move the file position to the end of the file
    if (file.is_open()){

        // get the size of the file (since the position was moved to the end of the file)
        // since the mode is reading mode, tellg is used instead of tellp
        size = file.tellg();

        // prepare a space whose size is the size of the file, in dynamic memory allocation method
        // and the memblock points to the space(array)
        memblock = new char [size]; 

        // move the file pointer(current file position) to the beginning of the file
        // since the mode is reading mode, seekg is used instead of seekp
        file.seekg (0, ios::beg);

        /* 
            moving the information from the file to the main memory
            read the file as much as the 'size'bytes and store it to where the memblock points.
            it's read from the beginning,
            since the position of file pointer was set at the beginning of the file by above code.
        */
        file.read(memblock, size);

        // close the file
        file.close();

        cout << "the entire file content is in memory" ;
        delete[] memblock;
    } else cout << "Unable to open file";

    return 0;
}