#include <iostream>
using namespace std;
#include "user_interaction.h"
void UserInteraction::ShowMainMenu()
{
    cout << "1. Insertion\n 2. Search\n 3. Sorting Option\n 4. Exit ";
}
int main()
{
    int user_input;
    UserInteraction ui;
    ui.ShowMainMenu();
    cin >> user_input;

        return 0;
}