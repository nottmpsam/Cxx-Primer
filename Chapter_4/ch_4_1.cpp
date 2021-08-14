#include <iostream>

const int Size{50};
	
int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;

	char name[Size];
	char last_name[Size];
	short age;
	char grade;
	
	cout << "What is your first name? ";
	cin.getline(name, Size);
	cout << "What is your last name? ";
	cin.getline(last_name, Size);
	cout << "What letter grade do you deserve? ";
	cin >> grade;
	grade++;
	cout << "What is your age? ";
	cin >> age;

	cout << "Name: " << last_name << ", " << name << endl;
	cout << "Grade: "<< grade << endl;
	cout << "Age: " << age << endl;

	return 0;
};