#include "student.h"
class UserInteraction
{

public:
    UserInteraction(){};
    void ShowMainMenu();
    Student ShowInsertionView();
    void ShowSearchView();
    void ShowSearchResultHeaderView();
    void ShowSearchResultView(Student);
    void ShowSortingOptionView();
};