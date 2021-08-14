#include <iostream>
#include <cstring>
const int Size{250};

int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;
	char name[Size];
	char last_name[Size];
	char mx[Size] = "Here's the information in a single string: ";
	const char lx[] = ", ";
	cout << "Enter your first name: ";
	cin.getline(name, Size);
	cout << "Enter your last name: ";
	cin.getline(last_name, Size);
	strcat(mx, last_name);	
	strcat(mx, lx);
	strcat(mx, name);
	cout << mx << endl;

	return 0;
}

