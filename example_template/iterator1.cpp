#include <iostream>
using namespace std;

typedef int* Int_Iterator; 

template <class IteratorT, class T> 
IteratorT Find( IteratorT begin, IteratorT end, const T& value ) ;

int main()
{ 
    const int SIZE = 100; 
    int x[SIZE]; 
    int num; 

    Int_Iterator begin = x; Int_Iterator end = &x[SIZE]; 

    for (int i = 0; i < SIZE; ++i) {
        x[i] = 2 * i; 
    }

    while (true) { 
        cout<< "Enter number: "; cin>> num; 
        Int_Iterator position = Find(begin, end, num); 
        if (position != end) { 
            ++position; 
            if (position != end) cout << "Found before " << *position << endl; 
            else cout<< "Found as last element" << endl; 
        } else cout<< "Not found" << endl; 
    } 
}

template <class IteratorT, class T> 
IteratorT Find( IteratorT begin, IteratorT end, const T& value ) 
{ 
    for ( ; begin != end ; begin++) 
        if (*begin == value) break;
    return begin; 
} 
