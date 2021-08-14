#include <iostream>
#include <string>
class bankAccount 
{
    std::string name;
    std::string card;
    double balance;
public:
    bankAccount(std::string _name = "", std::string _card = "",  double _balance = 0.0);
    void addAccount();
    void showInfo() const;
    void addBalance(double value);
    void minBalance(double value);
};
void bankAccount::addAccount()
{
    std::cout << "Enter full name: ";
    std::getline(std::cin, name);
    std::cout << "Enter number of card: ";
    std::getline(std::cin, card);
    std::cout << "Enter balance: ";
    while (!(std::cin >> balance)) {
        std::cin.clear();
        while (std::cin.get() != '\n')
            continue;
    }
    while (std::cin.get() != '\n') 
        continue;
}
bankAccount::bankAccount(std::string _name, std::string _card, double _balance)
{
    name = _name;
    card = _card;
    balance = _balance;
}
void bankAccount::showInfo() const
{
    std::cout << "Full name: " << name << std::endl
        <<  "Card: " << card << std::endl
        << "Balance: " << balance << std::endl
        << "****************" << std::endl;
}
void bankAccount::addBalance(double value)
{
    balance += value;
}
void  bankAccount::minBalance(double value)
{
    balance -= value;
}
int main()
{
    bankAccount Person0("Shabdan", "99920202", 30113.3);
    Person0.showInfo();
    bankAccount Person1;
    Person1 = bankAccount("Dmitrii", "20201021", 21.31);
    Person1.showInfo();
    const int n = 5;
    bankAccount persons[n];
    for (int i = 0; i < n; ++i) {
        persons[i].addAccount();
    }
    for (int i = 0; i < n; ++i) {
        persons[i].showInfo();
    }
    return 0;
}
