#include <iostream>
#include <string>

int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;

	string name;
	string last_name;
	string mx= "Here's the information in a single string: ";
	string lx = ", ";
	cout << "Enter your first name: ";
	getline(cin, name);
	cout << "Enter your last name: ";
	getline(cin, last_name);
	
	string total = mx + last_name + lx + name; 	
	cout << total << endl;

	return 0;
}

