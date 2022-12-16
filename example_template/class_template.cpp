#include <iostream>
#include <string>
using namespace std;

template <typename T>
class thing
{
public:
    thing(T data);
    ~thing() { delete x; }
    T get_data() { return *x; }
    T set_data(T data);

private:
    T *x;
};

template <typename T>
thing<T>::thing(T data)
{
    x = new T;
    *x = data;
}

template <typename T>
T thing<T>::set_data(T data)
{
    *x = data;
    return *x;
}

int main()
{
    thing<int> i_thing(5);
    thing<string> s_thing("COMP151");

    cout << i_thing.get_data() << endl;
    cout << s_thing.get_data() << endl;

    i_thing.set_data(10);
    s_thing.set_data("CPEG");
    cout << i_thing.get_data() << endl;
    cout << s_thing.get_data() << endl;

    return 0;
}
