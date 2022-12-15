#include <iostream>
using namespace std;

class lifeform 
{
public:
	virtual void die()=0;
};

class plant : public lifeform
{
public:
	void die() { cout << "plant die!\n" ; }
};

class person : public lifeform
{
public:
	void die() { cout << "person die!\n" ; }
};

void kill(lifeform& f) {
	f.die();
}

int main()
{
	plant x;
	person y;
	lifeform *p1, *p2;

	kill(x);
	kill(y);
	
	p1 = new plant;
	p1->die();
	p2 = new person;
	p2->die();


	return 0;
}