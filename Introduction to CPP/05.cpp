/* static memory allocation - memory is allocated at compile time*/
int x[10]; // typical way to use an array 
x[0] = 3;
x[2] = 7;

/* dynamic memory allocation - memory is allocated at run time (execution time) */
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