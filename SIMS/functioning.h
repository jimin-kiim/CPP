class Fuctioning
{
    int sorting_option = 1;

public:
    Fuctioning(){};
    void CreateData(Student);
    void SearchData(int,string);
    void setSortingOption(int option){sorting_option = option;};

    vector<Student> ReadData();
    void SortData();
};
