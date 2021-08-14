#include <iostream>
double res(int, int);
int main()
{
	int x, y;
	while (std::cin >> x >> y)
	{
		if (x == 0 || y == 0) 
			break;
		std::cout << res(x,y) << std::endl;
	}
	std::cin.clear();
	while (std::cin.get() != '\n') {
		continue;
	}
	return 0;
}
double res(int x, int y)
{
	return (2.0 * x * y / (x + y));
}
