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
    D() {}
    void displayD() { cout << "y = " << y << endl; }
};

int main()
{
    D derived;
    derived.displayB();
    derived.displayD();
    return 0;
}

// error: constructor for 'D' must explicitly initialize the base class 'B' which does not have a default constructor
