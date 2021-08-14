#include <iostream>

struct car
{ 
	std::string car_name;
	int car_year;
};

int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;
	int cars_count{};

	cout << "Enter how many cars you want to add: ";
	cin >> cars_count;
	car* car_pointer = new car[cars_count];

	for (int i = 0; i < cars_count; ++i) 
	{
		cout << "Car #" << (i + 1)<< ':';
		cin >> (car_pointer + i) -> car_name;
		cout << "Made in: ";
		cin >> (car_pointer + i) -> car_year;   
	}
	
	cout << endl << "Your collection is here: " << endl;
	for (int i = 0; i < cars_count; ++i)
	{
		cout <<  (car_pointer + i) -> car_year
		<< " " << (car_pointer + i) -> car_name << endl;
	}

	delete [] car_pointer;
	return 0;
}