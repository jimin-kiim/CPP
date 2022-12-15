#include <iostream>
using namespace std;

class B
{
private:
	int x;

public:
	B(int x_val) : x(x_val) {}
	void displayB() { cout << "x = " << x << endl; }
};

class D : public B
{
private:
	int y;

public:
	D(int x_val, int y_val) : B(x_val), y(y_val) {}
	void displayD() { cout << "y = " << y << endl; }
};

int main()
{
	D derived(10, 20);
	derived.displayB();
	derived.displayD();
	return 0;
}
