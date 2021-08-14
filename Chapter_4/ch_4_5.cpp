#include <iostream>
const int Size = 50;

struct CandyBar
{
	char name[Size];
	float weight;
	int callory;
};

int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;

	CandyBar snack = {"Mocha Munch", 2.3, 350};
	cout << "Name of sweat: " << snack.name << " | weight: " << snack.weight
	<< " | callory: " << snack.callory << endl;

	return 0;
}
