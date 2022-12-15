#include <iostream>
using namespace std;

class B
{
private:
	int x;

public:
	B() : x(10) {} // B(){x=10};
	void displayB() { cout << "x = " << x << endl; }
};
class D : public B
{
private:
	int y;

public:
	D() : y(20){}; // Default Constructor used for B D() {y=20};
	void displayD() { cout << "y = " << y << endl; }
};

int main()
{
	D derived;
	derived.displayB();
	derived.displayD();
	return 0;
}
