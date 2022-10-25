#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    streampos begin, end; // can be considered as integer
    ifstream myfile("example.bin", ios::binary);

    if (myfile.is_open())
    {
        // since the mode is reading a file, tellg is used instead of tellp
        begin = myfile.tellg();    // current position of get pointer. 0 (starting point)
        myfile.seekg(0, ios::end); // move the position to ios::end and the amount of distancing from the end is 0.
        end = myfile.tellg();      // position would be the end of the doc
        myfile.close();
        cout << "size is : " << (end - begin) << " bytes.\n";
    }
    else
        cout << "Unable to open file";

    return 0;
}