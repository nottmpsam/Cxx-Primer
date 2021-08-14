#include <iostream>
#include <cstdlib>

const double MIN = 100;
const int Size = 24;
struct people
{
	std::string human_name;
	double human_donate;
};

int main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;
	int human_range {};

	cout << "How many people? ";
	while(!(cin >> human_range))
	{
		cin.clear();
		while(cin.get() != '\n')
			continue;
		cout << "Enter a number! \n";
	}

	people* pt = new people[human_range];
	cout << "Enter a name & donate: " << endl;

	for (int i = 0; i < human_range; i++)
	{
		cout << "#" << i + 1 <<   "\nName: ";
		cin >> pt -> human_name;
		cout << "Donate: ";
		cin >> pt -> human_donate; 
		pt++;
	}
	pt -= human_range;
	
	int count {};
	cout << "**__Grand Patrons__**" << endl;
	for (int i = 0; i < human_range; i++)
	{
		if (pt->human_donate >= MIN)
		{
			cout << pt -> human_name << "  |  $" 
			<< pt -> human_donate << endl;
			++count;
		}
		pt++;
	}
	pt -= human_range;
	if (count == human_range) {
		cout << "Patrons\nNone\n";
	}
	else if (count == 0)
	{
		cout << "None\n";
		cout << "Patrons\n";
		for (int i = 0; i < human_range; i++)
		{
			cout << pt -> human_name << "  " << pt -> human_donate << endl; 
			pt++;
		}
		pt -= human_range;
	}
	else 
	{
		cout << "Patrons\n";
		for (int i = 0; i < human_range; i++)
		{
			if ((pt -> human_donate) < MIN)
				cout << pt -> human_name << "  " << pt -> human_donate << endl;
			pt++;
		}
		pt -= human_range;
	}
	for  (int i = 0; i < human_range; ++i)
	{
		delete pt;
		pt++;
	}
	return 0;
}
