#include <iostream>
#include <fstream>
using namespace std;

int main() {
    streampos begin, end; // can be considered as integer
    ifstream myfile("example.bin",ios::binary);
    begin = myfile.tellg(); // 0
    myfile.seekg(0,ios::end); // move the position to ios::end
    end = myfile.tellg(); // end of the doc
    myfile.close(); 
    cout << "size is : " << (end-begin) << " bytes.\n";

    return 0; 
}