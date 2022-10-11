#include <vector>
#include <iostream>
using namespace std;

class Greeter
{
public:
    Greeter(){};
    void displayInitialMessage(); // IIKH 소개 랜딩 화면을 출력한다. 
    void offerUserChoiceOfOptions(); // 메뉴를 출력하고 수행할 기능 옵션을 선택을 받아 다음 기능 수행으로 넘어간다.
};

class DatabaseManager
{
    static vector<Recipe> recipes; // 각각의 세부 정보가 담긴 Recipe 객체들을 지닌다. 
public:
    DatabaseManager(){};
    vector<Recipe> browseData(); // 저장된 레시피 데이터들을 읽어온다.
    void addNewData(); // 새로운 레시피 데이터를 추가 작성한다. 
    void editExistingData(); // 기존에 저장된 레시피 데이터를 수정한다.
};

class Recipe
{
    vector<string> ingredients; // 레시피 수행에 필요한 재료들의 리스트를 지닌다.
    vector<string> steps; // 레시피 수행 방법을 지닌다.
    string annotation; // 레시피 주석을 지닌다.

public:
    Recipe(){};
    void setIngredients(); // 재료 리스트를 저장한다.
    void setSteps(); // 레시피 수행 방법을 저장한다. 
    void setAnnotation(); // 레시피에 주석을 단다.
    void displayListOfRecipes(vector<Recipe>); // 기존에 저장된 레시피의 목록을 보여준다. (레시피 목록)
    void displaySpecificRecipe(vector<Recipe>); // 특정 레시피 정보를 보여준다. (레시피 디테일)
    void modifyRecipeInformation(); // 기존에 저장된 레시피 정보(재료, 요리방법)를 수정하거나 주석을 단다.
    void printRecipe(); // 특정 레시피 정보를 출력한다.
};

class PlanManager
{
    static vector<Date> plans; // 각각의 식사 계획이 담긴 Date 객체들을 지닌다.
public:
    PlanManager(){};
    void displayListOfPlans(); // 기존에 저장된 계획들을 보여준다. 
    void createNewPlan(); // 새로운 계획을 추가한다.
    void editExistingPlan(); // 기존에 작성된 계획 정보를 수정한다. 
};

class Date
{
    string date; // 날짜 정보를 지닌다.
    string annotation; //"Christmas Dinner"와 같은 이름, 별칭을 지닌다.
    vector<Meal> meals; // 해당 날짜의 식사 객체들의 리스트를 지닌다.
    string grocery_list; // 해당 날짜의 식사들을 준비하기 위한 장보기 목록을 지닌다.

public:
    Date(){};
    void displayMealsOfDay(); // 해당 날짜의 이름과 식사 리스트를 보여준다.
    void setDate(); // 날짜 정보를 저장한다.
    void setAnnotation(); // 해당 날짜에 이름을 붙일 수 있다. 
    void setMeals(); // 해당 날짜의 식사를 저장한다.
    void setGroceryList(); // 해당 날짜의 식사들을 준비하기 위한 장보기 목록을 저장한다.
    void editExistingMeal(); // 해당 날짜의 식사들을 수정할 수 있다.
    void printGroceryList(); // 해당 날짜 식사들을 준비하기 위한 장보기 목록을 출력한다. 
};

class Meal
{
    vector<Recipe> unit_recipes; // 한 식사동안 먹을 음식들의 기본 단위 레시피들을 지닌다.
    vector<Recipe> scaled_recipes; // 한 식사동안 먹을 음식들의 레시피들을 지닌다. 
    int the_number_of_people; // 한 식사동안 먹을 사람의 수를 지닌다.
    string grocery_list; // 한 식사에 속한 음식들을 준비하기 위한 장보기 목록을 지닌다.

public:
    Meal(){};
    void displayMealInformation(); // 식사 정보를 보여준다. 
    void setTheNumberOfPeople(); // 식사에 참여하는 인원수(멤버 변수 the_number_of_people)를 설정한다.
    void addRecipeToMeal(); // 식사에 새 레시피를 추가한다.
    void removeRecipeOfMeal(); // 식사의 레시피를 삭제한다. 
    void produceGroceryList(); // 해당 식사 준비를 위한 장보기 목록을 생성한다. 
};
