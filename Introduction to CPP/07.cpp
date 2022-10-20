#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream myfile ("example.txt");
    
    if (myfile.is_open()){
        /* 
            in fact, since the mode of ofstream is ios::out, 
            if there's no corresponding file, 
            a new file is created, no error is being occured
        */
        myfile << "This is a line.\n";
        myfile << "This is another line.\n";
        myfile.close();
    }else cout << "Unable to open file";

    return 0;
}