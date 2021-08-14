#include <iostream>
#include <cctype>

void menu_display(void);

const int Size = 25;
struct bop 
{
	char fullname[Size];
	char title[Size];
	char bopname[Size];
	int preference;
};

int main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;
	const int N = 5;
	bop front_1[N]
	{
		{"Arthur Sheriov", "Full-stack developer", "Ant", 2},
		{"Samuel Smith", "Game-developer", "Samusya", 0},
		{"Brench Tree", "C++ engineer", "Bred", 1 },
		{"Matt Laiter", "Junior Java developer", "Onion", 2},
		{"Alex Morthi", "DevOps engineer", "RedHead", 0}
	};
	//for (int i = 0;  i < 5; ++i)
	//	cout << front_1[i].fullname << " " << front_1[i].title << " " << front_1[i].bopname <<
	//   " " << front_1[i].preference << endl;
	menu_display();
	char ch;
	while (cin.get(ch) && ch != 'q')
	{
		if (isspace(ch)) continue;
		if (ch == 'a' || ch == 'A') 
			for (int i = 0; i < N ; ++i)
				cout << front_1[i].fullname << endl;
		else if (ch == 'b' || ch == 'B')
			for (int i = 0; i < N; ++i)
				cout << front_1[i].title << endl;
		else if (ch == 'c' || ch == 'C')
			for (int i = 0; i < N; ++i)
				cout << front_1[i].bopname << endl;
		else if (ch == 'd' || ch == 'D')
		{
			for (int i = 0; i < N; ++i)
			{
				switch(front_1[i].preference)
				{
					case 0 : cout << front_1[i].fullname << endl; break;
					case 1 : cout << front_1[i].title << endl; break;
					case 2 : cout << front_1[i].bopname << endl; break;
				}
			} 
		} 
		else 
		{
			cout << "Reenter:\n";
			continue;
		}
		cout <<  "Next choice: ";
	}
	cout << "** Bye! **\n";

	return 0;
}
void menu_display(void)
{
	std::cout <<  "Benevolent Order of Programmers Report \n"
	<< "a. display by name" << "\tb. display by title\n"
	<< "c. display by bopname" << "\td. display by prefernce\n"
	<< "q. quit\n"
	<< "Enter a choice: ";
}