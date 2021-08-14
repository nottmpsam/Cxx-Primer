#include <iostream>

int Month(int Age);
int main(void)
{
	int age;
	std::cout << "Enter your age: ";
	std::cin >> age;
	std::cout << "Your age in month is " << Month(age)
	<< std::endl;

	return 0;
}
int Month(int Age)
{
	return Age * 12;
}
