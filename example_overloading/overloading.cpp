#include <iostream> 
using namespace std;

void Func( int one, int two=2, int three=3);
void Func( float fv );

int main () 
{ 
	Func(10, 20, 30); 
	Func(10, 20); // Let the last parm default 
	Func(10); // Just provide the required parm.
	Func(1.5f); 
    return 0;
} 

void Func( int one, int two, int three) 
{ 
	cout << "One = " << one << endl; 
	cout << "Two = " << two << endl; 
	cout << "Three = " << three << endl << endl; 
}

void Func ( float fv)
{
	cout << fv << endl;
}
