#include <iostream>
using namespace std;

// class : data structure type that can contain member data and member functions
class Rectangle {
    int width, height; // member data(variables)
    public: // member functions

        // class constructor - automatically called when the object is created
        Rectangle (int,int); // may leave only the prototype of the function
        int area() {return width*height;};// can insert the function body(implementation)
};

// can insert the function body outside the class
Rectangle::Rectangle(int x, int y){
    width = x;
    height = y;
}

int main(){

    // class(type) objects(variables)
    Rectangle rect(3,4), rectb(5,6);
    cout << "rect area: " << rect.area() << endl;
    cout << "rectb area: " << rectb.area() << endl;
    return 0;
}