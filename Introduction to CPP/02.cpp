#include <iostream>
using namespace std;

int add(int a, int b){
    int r;
    r = a+b;
    return r;
}

int main(){
    int z;
    z=add(5,3);
    cout << "The result is " << z;
}

// dynamic : done during run time, execution time. (mallloc & free in C, new & delete in C++)
// static : done during compile time. - array 

/*
int x[10]; // array. memory allocation is already determined and allocated during the compile time.
// static memory allocation
x[0] = 5;
x[2] = 7;
*/

/*
# C

int *x;
x = (int*)malloc(10*sizeof(int));
tree;
*/

/*
# C++

int *x; // 4 bytes pointer variable
x = new int[10];

delete[] x;
*/