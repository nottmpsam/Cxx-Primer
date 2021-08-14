#include <iostream>

int main(void)
{
	int total{};
	int input{};

	std::cout << "Enter integer: ";
	std::cin >> input;
	while(input != 0)
	{
		total += input;
		std::cout << "Sum = "  << total << std::endl;
		std::cout << "Enter integer again: ";
		std::cin >> input;
	}
	std::cout << "Done!\n" << std::endl;
	return 0;
}