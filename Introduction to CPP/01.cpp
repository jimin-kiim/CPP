#include <iostream> // standard input and output
using namespace std; // "we are gonna use functions and objects that are in std"

int main(){
    cout << "Hello World!\n"; // cout : standard output (screen stream object)
    cout << "I'm a C++ program\n";

    int i;
    cout << "Please enter an integer value >> ";
    cin >> i; //cin : standard input (keyboard stream object)
    // value is stored when the enter key is pressed

     // in the case of the one not surrouded by quotation marks, it means the value of the variable
    cout << "The value you entered is " << i ; // prints the value of i on screen
    cout << "\nand its double is " << i*2 << ".\n";
    return 0;

}

// Compilation : C++ compiler generates executable file(machine code) from C++ source code
// > g++ -o TestProg TestProg.cpp
// > ./TestProg

