#include <iostream>
#include <vector>
#include <algorithm>
// #include 'init.cpp'
using namespace std;

// File “init.cpp”
int f(int x) { return -x*x + 40*x + 22; } 
// 22 61 98 133 166 197 226 253 278 301 322 341 358 373 386 397 
// 406 413 418 421 422 421 418 413 406 397 386 373 358 341 322 301 

template<typename T> 
void my_initialization(T& x) 
{
    const int N = 39; 
    for (int j = 0; j < N; ++j) {
        x.push_back( f(j) ); 
    }
}

int main()
{
    const int search_value = 341;
    vector<int> x;
    my_initialization(x);

    vector<int>::iterator p;
    p = find(x.begin(), x.end(), search_value);

    if (p != x.end())
    {                                         // Value found!
        p = find(++p, x.end(), search_value); // Find again
        if (p != x.end())
        { // Value found again!
            cout << "Found after : " << *--p << endl;
        }
    }

    return 0;
}


