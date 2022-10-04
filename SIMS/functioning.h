class Functioning
{
    static int sorting_option;

public:
    Functioning(){};
    void CreateData(Student);
    void SearchData(int,string);
    void setSortingOption(int option){sorting_option = option; cout << "sorting_option" << sorting_option << "\n";};
    int getSortingOption(){return sorting_option;};

    vector<Student> ReadData();
    void SortData(vector<Student>&);
    int VerifyStudentId(string);
};
