#include <iostream>
using namespace std;

class Complex
{
private:
    double re, im;

public:
    Complex(double r, double i) : re(r), im(i) {}
    Complex operator+(Complex &other);
    Complex operator-(Complex &other);
    Complex operator*(Complex &other);
    void Display()
    {
        if (im > 0)
            cout << re << "+" << im << "i" << endl;
        else if (im < 0)
            cout << re << im << "i" << endl;
        else if (im == 0)
            cout << re << endl;
    }
};

// Operator overloaded using a member function
Complex Complex::operator+(Complex &other)
{
    return Complex(re + other.re, im + other.im);
}

Complex Complex::operator-(Complex &other)
{
    return Complex(re - other.re, im - other.im);
}

Complex Complex::operator*(Complex &other)
{
    return Complex(re * other.re - im * other.im, re * other.im + im * other.re);
}
int main()
{
    Complex a = Complex(1.2, 3.4);
    Complex b = Complex(5.6, 7.8);
    Complex c = Complex(0.0, 0.0);

    a.Display();
    b.Display();
    cout << endl;

    c = a + b;
    c.Display();
    c = a - b;
    c.Display();
    c = a * b;
    c.Display();
    return 0;
}
