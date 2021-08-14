#include <iostream>
long double factorial (unsigned int);
int main()
{
	int n;
	while (std::cin >> n) {
		std::cout << "Factorial of " << n  << 
			" is " << factorial(n) << std::endl;
	}
	std::cin.clear();
	while (std::cin.get() != '\n') {
		continue;
	}
	return 0;
}
long double factorial(unsigned int n)
{
	if (n == 0) return 1;
	return n*factorial(n-1);
}
