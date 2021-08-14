#include <iostream>

int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;

	int range_1, range_2;
	cout << "Enter your first int: ";
	cin >> range_1;
	cout << "Enter your second int: ";
	cin >> range_2;

	int total{};
	for (int i = range_1; i <= range_2; ++i) {
		total += i;
	}

	cout << "Sum between " << range_1 << " and " << range_2 << " = " 
	<< total;


	return 0;
}
