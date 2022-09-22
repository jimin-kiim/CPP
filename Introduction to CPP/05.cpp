// array - static memory allocation : memory is allocated at complie time
//          - light-weight, fast to create and delete from the memory
//          - the exact memory size must be specified when declaring the array
//       - dynamic memory allocaton : memory is allocated at run time
//          - no need to specify the exact memory size
//          - heavy-weight, slow

int x[10];
x[0] = 3;
x[2] = 7;

// C
int* x;
x = (int*)malloc(sizeof(x)*10); // allocating
x[0] = 3;
x[2] = 7;

free(x); // deallocating


// C++
int* y;
int n = 10;
y = new int[n]; // allocating
y[0] = 3;
y[2] = 7;

delete[] y; // deallocating
