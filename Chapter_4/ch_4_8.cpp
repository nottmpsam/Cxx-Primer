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

	wwNotes* pointer = new wwNotes;

	cout << "Enter diametr of pizza: ";
	cin >> pointer->diametr;
	
	cout <<  "Enter the name of pizza company: ";
	cin >> pointer->companyName;

	cout << "Enter weight of your pizza: ";
	cin >> pointer->weight;

	cout << "Next specifications of pizza: " << endl 
	<< pointer->companyName << " | diametr: " << pointer->diametr 
	<< " | weight: " << pointer->weight << endl;

	delete pointer;
	return 0;
}