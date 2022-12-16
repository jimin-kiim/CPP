#include <iostream>
#include <vector> // "vector” class from STL 
using namespace std;

template <class IteratorT, class T> 
IteratorT Find( IteratorT begin, IteratorT end, const T& value ) ;

int main() 
{ 
    const int SIZE = 100; 
    vector<int> x(SIZE); int num; 

    for (int i = 0; i < SIZE; ++i) {
        x[i] = 2 * i; 
    }

    while (true) { 
        cout<< "Enter number to locate: "; cin >> num; 
        vector<int>::iterator position = Find(x.begin(), x.end(), num); 
        if (position != x.end()) { 
            ++position; 
            if (position != x.end()) cout << "Found before " << *position << endl; 
            else cout << "Found as last element." << endl; 
        } else {
            cout<< "Not found" << endl; 
        }
    } 
}

template <class IteratorT, class T> 
IteratorT Find( IteratorT begin, IteratorT end, const T& value ) 
{ 
    for ( ; begin != end ; begin++) 
        if (*begin == value) break;
    return begin; 
} 