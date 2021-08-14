#include <iostream>

int main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;
	//cout.setf(std::ios_base::fixed, std::ios_base::floatfield);

	const double Population =  7858772994;
	cout << "Enter the wordl's population: " << Population << endl;
	double population_2;
	cout << "Enter the population of the another country: ";
	cin >> population_2;
	const double Percent =  Population / 100;
	cout <<"Population of entered country is " << population_2 / Percent << "% of the world population" << endl;

	return 0;
}