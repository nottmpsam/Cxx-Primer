#include <iostream>
int const Size = 15;

int main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;
	char name[Size];
	char address[Size];
	cout << "Enter your name." << endl;
	cin >> name;

	cout << "And now enter your address." << endl;
	cin >> address;

	cout << "You're welcome!" << endl;
	cout << name << ", " << address;

	return 0;
}