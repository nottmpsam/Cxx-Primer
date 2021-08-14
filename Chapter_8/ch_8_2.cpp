#include <iostream>


struct CandyBar 
{
    std::string name;
    double weight;
    int calorie;
};
void SetCandy(CandyBar &currentCandy, std::string currentName = "Millennium Munch", double currentWeight = 2.85, int currentCalorie 
        = 350) 
{
    currentCandy.name = currentName;
    currentCandy.weight = currentWeight;
    currentCandy.calorie = currentCalorie;
}
void showCandy(const CandyBar& currentCandy)
{
    std::cout << "************************"  
    << "\nCandy's name: " << currentCandy.name
    << "\nWeight: " << currentCandy.weight
    << "\nCalorie: " << currentCandy.calorie
    << std::endl;
    std::cout << "************************\n";
}
int main()
{
    std::string name;
    double weight; int calorie;
    std::cout << "Name of candy: ";
    std::getline(std::cin, name);
    std::cout << "Weight: ";
    std::cin >> weight;
    std::cout << "Calorie: ";
    std::cin >> calorie;
    CandyBar Munhen;
    SetCandy(Munhen, name, weight, calorie);
    showCandy(Munhen);
    return 0;
}
