#include <iostream>

int main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;

	cout << "Enter your distance: ";
	int yr;
	int mtr;
	cin >> yr;
	mtr = yr * 201169;
	yr = yr * 220;

	cout << mtr << " metres, " << yr << " yards.";

	return 0;
}