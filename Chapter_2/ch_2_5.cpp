#include <iostream>
int Fahrenheit(int Celcius);

int main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;

	int celcius;
	cout << "Please enter a Celcius value: ";
	cin >> celcius;
	cout << celcius << " degrees Celcius "
	<< "is "  << Fahrenheit(celcius) << " degrees Fahrenheit" << endl;
 
	return 0;
}

int Fahrenheit(int Celcius)
{
	return int(1.8 * Celcius) + 32; 
}
