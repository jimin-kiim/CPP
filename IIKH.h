#include <vector>

class Greeter
{
public:
    Greeter(){};
    void displayInitialMessage(); // IIKH 소개 랜딩 화면을 출력한다. 
    void offerUserChoiceOfOptions(); // 메뉴를 출력하고 수행할 기능 옵션을 선택을 받아 다음 기능 수행으로 넘어간다.
};

class DatabaseManager
{
public:
    DatabaseManager(){};
    void browseData(); // 저장된 데이터들을 읽어온다. 
    void addNewData(); // 새로운 데이터를 추가 작성한다. 
    void editExistingData(); // 기존에 저장된 데이터를 수정한다.
};

class Recipe
{
    vector<String> ingredients; // 레시피 수행에 필요한 재료들의 리스트를 갖는다.
    vector<String> steps; // 레시피 수행 방법을 갖는다.

public:
    Recipe(){};
    void displayListOfRecipes(); // 기존에 저장된 레시피의 목록을 보여준다. (레시피 목록)
    void displaySpecificRecipe(); // 특정 레시피 정보를 보여준다. (레시피 디테일)
    void modifyRecipeInformation(); // 기존에 저장된 레시피 정보(재료, 요리방법)를 수정하거나 주석을 단다.
    void printRecipe(); // 특정 레시피 정보를 출력한다.
};

class PlanManager
{
public:
    PlanManager(){};
    void displayListOfPlans(); // 기존에 저장된 계획들을 보여준다. 
    void createNewPlan(); // 새로운 계획을 추가한다.
    void editExistingData(); // 기존에 작성된 계획 정보를 수정한다. 
};

class Date
{
    string date; // 날짜 정보를 갖는다.
    string annotation; //"Christmas Dinner"와 같은 이름을 갖는다.
    vector<Meal> meals; // 해당 날짜에 해당하는 식사 객체의 리스트를 갖는다.

public:
    Date(){};
    void displayMealsOfDay(); // 해당 날짜의 이름과 식사 리스트를 보여준다.
    void setAnnotation(); // 해당 날짜에 이름을 붙일 수 있다. 
    void editExistingData(); // 해당 날짜의 식사를 수정할 수 있다.
    void printGroceryList(); // 해당 날짜 식사들을 준비하기 위한 장보기 목록을 출력한다. 
};

class Meal
{
    Recipe unit_recipe;
    int the_number_of_people;
    vector<String> ingredients;
    vector<String> steps;


public:
    Meal(){};
    void setTheNumberOfPeople(); // 식사에 참여하는 인원수(멤버 변수 the_number_of_people)를 설정한다.
    void addRecipeToMeal(); 
    void addNewData();
    void produceGroceryList(); // 해당 식사 준비를 위한 장보기 목록을 생서한다. 
};
