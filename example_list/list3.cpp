#include <list>
#include <iostream>
using namespace std;

void display(list<int>::iterator first, list<int>::iterator end)
{
    list<int>::iterator p;
    for (p = first; p != end; ++p)
    {
        cout << *p << " ";
    }
}

int main()
{
    list<int> my_list, small, large;
    list<int>::iterator ip;

    for (int i = 1; i < 13; ++i)
    { // initialize values in the list
        my_list.push_back(i * i % 13);
    }
    for (ip = my_list.begin(); ip != my_list.end(); ++ip)
    {
        if (*ip < 7)
        {
            small.push_back(*ip);
        }
        else
        {
            large.push_back(*ip);
        }
    }
    cout << "my_list: ";
    display(my_list.begin(), my_list.end());
    cout << endl;
    cout << "small: ";
    display(small.begin(), small.end());
    cout << endl;
    cout << "large: ";
    display(large.begin(), large.end());
    cout << endl;

    return 0;
}
