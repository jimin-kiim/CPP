#include <iostream>
using namespace std;

// class : data structure type that can contain member data and member functions
class Rectangle {
    int width, height; // member data(variables)
    public: // member functions
        void set_values(int,int); // may leave only the prototype of the function
        int area() {return width*height;};// can insert the function body(implementation)
};

// can insert the function body outside the class
void Rectangle::set_values(int x, int y){
    width = x;
    height = y;
}

int main(){

    // class(type) objects(variables)
    Rectangle rect, rectb;
    rect.set_values(3,4);
    rectb.set_values(5,6);
    cout << "rect area: " << rect.area() << endl;
    cout << "rectb area: " << rectb.area() << endl;
    return 0;
}