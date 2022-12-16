#include <iostream>
using namespace std;

class Complex
{
private:
    double re, im;

public:
    Complex(double r, double i) : re(r), im(i) {}
    friend Complex operator+(Complex &, Complex &);
    friend Complex operator-(Complex &, Complex &);
    friend Complex operator*(Complex &, Complex &);
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

// Operator overloaded using a non-member function
Complex operator+(Complex &i, Complex &other)
{
    return Complex(i.re + other.re, i.im + other.im);
}

Complex operator-(Complex &i, Complex &other)
{
    return Complex(i.re - other.re, i.im - other.im);
}

Complex operator*(Complex &i, Complex &other)
{
    return Complex(i.re * other.re - i.im * other.im, i.re * other.im + i.im * other.re);
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
