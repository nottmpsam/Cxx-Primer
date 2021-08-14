#include <iostream>

void clock(int, int);

int main(void)
{
	int hours, minutes;

	std::cout << "Enter the number of hours:";
	std::cin>> hours;

	std::cout << "Enter the number of minutes:";
	std::cin >> minutes;
	clock(hours, minutes);

	return 0;
}
void clock(int h, int m )
{
	std::cout << "Time " << h << ':' << m << std::endl;
}