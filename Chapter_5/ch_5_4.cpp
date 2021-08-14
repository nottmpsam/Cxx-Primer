#include <iostream>


int main(void)
{
	const float percent_D = 0.10;
	const float percent_C = 0.05;
	const int started_D = 100;

	double coins_C = 100;
	int coins_D = 100;
	short year = 1;
	
	do
	{
		coins_D = coins_D + started_D * percent_D;
		coins_C = coins_C + coins_C * percent_C;

		std::cout << "Year " << year <<std::endl;
		std::cout <<"C. has " << coins_C << "$ coins."<<std::endl;
		std::cout << "D. has " << coins_D << "$ coins."<< std::endl;
		std::cout << std::endl;

		++year;
	} while(coins_C <= coins_D);

	std::cout << std::endl << "In this year: " << year << " C has much moneys than D! "  <<std::endl;
	return 0;
}