#include <list> 
#include <vector> 
#include <string> 
#include <iostream> 
using namespace std;

template<class IteratorT> 
void display(IteratorT start, IteratorT end) 
// now display() becomes our own generic algorithm!
{
    for( IteratorT p = start; p != end; ++p ) {
        cout<< *p << " " ;
    }
} 

int main() 
{
    list<int> li; 
    vector<string> vs; 
    for (int i = 1; i < 13; ++i) {
        li.push_back(i*i % 13); 
    }
    vs.push_back("Now"); vs.push_back("Is"); vs.push_back("The"); 
    vs.push_back("Time"); vs.push_back("For"); vs.push_back("All"); 
    cout<< "li: "; display(li.begin(), li.end()); cout<< endl; 
    cout<< "vs: "; display(vs.begin(), vs.end()); cout<< endl; 

    return 0;
} 
