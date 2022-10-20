#include <iostream>
using namespace std;

// OOP : a set of interating objects
// class : data structure type that can contain member data and member functions
class Rectangle {
    int width, height; // member data, variables, attributes, state
    public: // member functions, procedures, methods, behaviors

        // class constructor - automatically called when the object is created
        // constructor doesn't have any return type
        Rectangle (int,int); // may leave only the prototype of the function
        int area() {return width*height;};// can insert the function body(implementation) inside the class
};

// can insert the function body outside the class
Rectangle::Rectangle(int x, int y){
    width = x;// member variable width. 
    height = y;
}

int main(){

    // class(type) objects(variables)
    Rectangle rect(3,4), rectb(5,6); // different memory space and address are assigned to each objects
    // when object is created the constructor is automatically called
    cout << "rect area: " << rect.area() << endl; // message reciever.message
    cout << "rectb area: " << rectb.area() << endl;
    return 0;
}