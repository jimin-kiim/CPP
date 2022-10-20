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

/* 
sometimes the static memory allocation is more suitable
and 
sometimes the dynamic memmory allocation is more suitable.
understanding the pros and cons of each of them and using them in pertinent situation is necessary.

# static 
- advantage : 
    light-weight.
    faster to be created and deleted than dynamic allocating method
    higher speed of the program in the execution time 
    ( since the memory allocation is already performed at the compile time. )
- disadvantage : 
    the exact size of the array must be specified when declaring the array

# dynamic
- advantage : 
    no need to specify the exact memory size
    ( even in the case when I cannot expect the size of array in advance, I can declare the array)
- disadvantage : 
    heavy-wight
    slower speed of the program when executed
    ( since the prodedure of allocating the memory is performed during the run time)


When I have to make a fast program then it's better to use the static memory allocating method
When I cannot expect the size of the array in advance of executing the program, it's better to use the dynamic memory allocating method
*/