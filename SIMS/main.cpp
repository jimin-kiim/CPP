#include <iostream>
using namespace std;
#include "user_interaction.h"

int main()
{
    int user_input;
    UserInteraction ui;
    ui.ShowMainMenu();
    cin >> user_input;

    switch (user_input)
    {
    case 1:
        ui.ShowInsertionView();
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
        break;
    }
    return 0;
}