#include <iostream>
using namespace std; // lots of functions and objects are designed in std

int main(){
    cout << "Hello World!\n"; // cout : standard output (screen output)
    cout << "I'm a C++ program\n";

    int i;
    cout << "Please enter an integer value >> ";
    cin >> i; //cin : standard input (keyboard)

     // in the case of the one not surrouded by quotation marks, it means the value of the variable
    cout << "The value you entered is " << i ;
    cout << "\nand its double is " << i*2 << ".\n";
    return 0;

}