#include <iostream>

double Astr(double);

int main(void)
{
	double years;
	std::cout << "Enter the number of light years:  ";
	std::cin >> years;
	std::cout << years << " light years = " << Astr(years) << 
	" astronomical units" << std::endl;

	return 0;
}

double Astr(double years) { return years * 63240; }