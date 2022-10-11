#include <iostream>
using namespace std;
#include "user_interaction.h"
#include "student.h"
#include "functioning.h"

enum option {INSERTION = 1, SEARCHING, SORTING, EXIT };
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
        case INSERTION:
            student = ui.ShowInsertionView();
            func.CreateData(student);
            break;
        case SEARCHING:
            ui.ShowSearchView();
            break;
        case SORTING:
            ui.ShowSortingOptionView();
            break;
        case EXIT:
            cout << "Program ended";
            return 0;
        default:
            cout << "Wrong Input";
            return 0;
        }
    }

    return 0;
}