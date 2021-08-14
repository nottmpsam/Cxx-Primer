#include <iostream>

double const Foot = 0.0833333;

int main(void)
{
	std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	
	unsigned growth;
	std::cout << "Enter your height in inch: ___\b\b\b";
	std::cin >> growth;
	std::cout << "In foot: ";
	std::cout <<  growth * Foot << std::endl;

	return 0;
}