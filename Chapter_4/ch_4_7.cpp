#include <iostream>

struct wwNotes
{
	std::string companyName;
	unsigned diametr;
	float weight;
};

int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;

	wwNotes newPizza;

	cout << "Enter the name of pizza company: ";
	getline(cin, newPizza.companyName);

	cout << "Enter diametr of pizza: ";
	cin >> newPizza.diametr;

	cout << "Enter weight of your pizza: ";
	cin >> newPizza.weight;

	cout << "Next specifications of pizza: " << endl 
	<< newPizza.companyName << " | diametr: " << newPizza.diametr 
	<< " | weight: " << newPizza.weight << endl;

	return 0;
}