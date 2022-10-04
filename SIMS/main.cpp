#include <iostream>
using namespace std;
#include "user_interaction.h"
#include "student.h"
#include "functioning.h"

int Functioning::sorting_option = 1;
int main()
{
    int user_input;
    UserInteraction ui;
    Student student;
    Functioning func;
    while (1)
    {
        ui.ShowMainMenu();
        cin >> user_input;
        switch (user_input)
        {
        case 1:
            student = ui.ShowInsertionView();
            func.CreateData(student);
            break;
        case 2:
            ui.ShowSearchView();
            break;
        case 3:
            ui.ShowSortingOptionView();
            break;
        case 4:
            cout << "Program ended";
            return 0;
        default:
            cout << "Wrong Input";
            return 0;
        }
    }

    return 0;
}