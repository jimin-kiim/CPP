#include <iostream>
using namespace std;

// class : data structure type that can contain member data and member functions
class Rectangle {
    int width, height; // member data(variables)
    public: // member functions

        // two class constructors - automatically called when the object is created
        // constructors have no return type/ value
        Rectangle() {width = 1; height = 1; } 
        Rectangle(int x, int y) : width(x), height(y) {}
        int area() {return width*height;};// can insert the function body(implementation)
};

int main(){
    Rectangle obj(3,4);
    Rectangle *foo, *bar, *baz;

    // giving a another name(alias, nickname) to the object
    foo = &obj; // & : 'address of', * : 'value at the address of'

    // naming the object
    bar = new Rectangle(5,6); // dynamic allocation
    baz = new Rectangle[2]; // array of two Rectangle type elements
    // constructor without parameters is called

    // class(type) objects(variables)
    cout << "obj's area: " << obj.area() << "\n";
    cout << "*foo's area: " << foo->area() << "\n"; // (*foo).area() // obj.area()
    cout << "*bar's area: " << bar->area() << "\n";
    cout << "baz[0]'s area: " << baz[0].area() << "\n";
    cout << "baz[1]'s area: " << baz[1].area() << "\n";
    delete bar;
    delete[] baz;
    
    return 0;
}