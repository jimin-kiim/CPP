#include <iostream>
#include <fstream>
using namespace std;

int main(){
    streampos size;
    char * memblock;
    ifstream file("example.bin", ios::in|ios::binary|ios::ate);
    if (file.is_open()){

        //get the size of the file
        size = file.tellg();

        // prepare a space whose size is the size of the file
        memblock = new char [size];

        // move the file pointer to the starting point of the file
        file.seekg (0, ios::beg);

        // start reading the file from the beginning and store it.
        // move the information from the file to the main memory
        file.read(memblock, size);

        // close the file
        file.close();

        cout << "the entire file content is in memory" ;
        delete[] memblock;
    } else cout << "Unable to open file";

    return 0;
}