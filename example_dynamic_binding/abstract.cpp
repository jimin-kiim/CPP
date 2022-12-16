#include <iostream>
using namespace std;
class Vehicle
{
public:
    virtual double accelerate(double) = 0;
    virtual double speed() = 0;
};

class Car : public Vehicle
{
public:
    virtual double accelerate(double);
    virtual double speed();
};

class Bicycle : public Vehicle
{
public:
    virtual double accelerate(double);
    virtual double speed();
};

void full_stop(Vehicle &v)
{
    v.accelerate(-v.speed());
}

int main()
{
    Vehicle v; // compile error! It is an abstract class
    Car c;
    full_stop(c);
    return 0;
}
