#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student
{

public:
    Student(int id, char *name)
    {
        stu_id = id;
        stu_name = name;
    }
    ~Student() {}

    friend bool operator<(const Student &s1, const Student &s2);

    bool operator==(const int sid)
    {
        return (stu_id == sid);
    }

    char *getName() { return stu_name; }
    int getID() { return stu_id; }

private:
    int stu_id;
    char *stu_name;
};

bool operator<(const Student &s1, const Student &s2)
{
    return (s1.stu_id < s2.stu_id);
}

void Display(vector<Student>::iterator start, vector<Student>::iterator end)
{
    for (vector<Student>::iterator p = start; p != end; ++p)
        cout << p->getID() << " : " << p->getName() << endl;
}

int main()
{
    vector<Student> stu_vec;
    vector<Student>::iterator stu_it;

    stu_vec.push_back(Student(4, "Nancy"));
    stu_vec.push_back(Student(1, "Tom"));
    stu_vec.push_back(Student(3, "Mike"));
    stu_vec.push_back(Student(2, "Lisa"));

    Display(stu_vec.begin(), stu_vec.end());
    cout << endl;

    stu_it = find(stu_vec.begin(), stu_vec.end(), 3);
    cout << "the name of stu_id=3 is : " << stu_it->getName() << endl
         << endl;

    sort(stu_vec.begin(), stu_vec.end());
    cout << "sorting completed!\n";

    Display(stu_vec.begin(), stu_vec.end());

    return 0;
}