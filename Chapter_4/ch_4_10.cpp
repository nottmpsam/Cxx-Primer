#include <iostream>
#include <array>
const int Size = 3;
int main(void)
{
	std::array<int, Size> results;
	std::cout << "| Enter three results | " << std::endl;
	std::cout << "Enter your 1st result: "<< std::endl;
	std::cin >> results[0];

	std::cout << "Enter your 2nd result: "<< std::endl;
	std::cin >> results[1];

	std::cout << "Enter your 3rd result: "<< std::endl;
	std::cin >> results[2];
	
	std::cout << "Index: " << (results[1] + results[2] + results[0]) / 3 << std::endl; 

	return 0;
}