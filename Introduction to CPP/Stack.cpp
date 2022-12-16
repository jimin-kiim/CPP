#include <iostream>
using namespace std;

template<typename T> 
class Stack { 
public: 
    Stack(int s = 100)
    {
        size = s;
        top = 0;
        stackPtr = new T[s];
    };
    ~Stack();
    bool push(const T&);
    bool pop(T&);
    bool isEmpty() const;
    bool isFull() const;    

private: 
    int size; 
    int top; 
    T *stackPtr;
};

template<typename T> 
bool Stack<T>::push(const T& x){
    if(top<size){ // if (isFull()) return false; 
// top += 1 ;
//     stackPtr[top] = x;

    stackPtr[top++] = x;
    return true;
    }
    return false;
    
}

int main()
{
    int x, y;

    Stack<int> intStack(5);
    intStack.push(5);
    intStack.push(8);
    // intStack.pop(x);
    // intStack.pop(y);

    cout << x << endl;
    cout << y << endl;

    return 0;
}

