#include <iostream>
#include <cstdlib>
#include <fstream>
const double MIN = 1e4;
const int Size = 24;
int display(const char *);
struct people
{
	std::string human_name;
	long human_donate;
};

int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;
	char filename[Size];

    cout << "Enter your file name: ";
    cin >> filename;
    display(filename);
	

	return 0;
}
int display(const char * filename)
{
	using std::cin;
	using std::cout;
	using std::endl;

	std::ifstream inFile;
	cout << "Name of your entered file is: " << filename << endl;
	inFile.open(filename);

	if(!(inFile.is_open()))
	{
		cout << "Can't open your file";
		return 0;
	}
	int range{};
	inFile >> range;
	cout << "Range is " << range << endl;	

	int count_for_donate{};
	people* pt = new people[range];
	for (int i = 0; i < range; i++)
	{
		inFile >> pt -> human_name;
		cout << pt-> human_name << endl;
		inFile >> pt -> human_donate;
		cout << pt-> human_donate << endl;
		pt++;
	}
	pt -= range;
	cout << "**__Grand Patrons__**" << endl;
	for (int i = 0; i < range; i++)
	{
		if (pt-> human_donate >= MIN) { // MIN = 1e4
			cout << pt->human_name  <<  "  $" << pt->human_donate << endl;
			++count_for_donate;
		}
		pt++;
	}
	pt -= range;
	//cout << pt->human_name  <<  " " << pt-> human_donate;
	if (count_for_donate == 0) cout << "None\n";
	else if (count_for_donate == range) cout << "Patrons\n" 
									    <<	"None\n";
	else
	{
		cout << "Patrons\n";
		for (int i = 0; i < range; i++)
		{
			if (pt-> human_donate < MIN) 
			{
				cout << pt-> human_name  <<  "  $" << pt-> human_donate << endl;
			}
			pt++;
		}	
	}
	pt -= range;
	for  (int i = 0; i < range; ++i)
	{
		delete pt;
		pt++;
	}
	inFile.close();
	return 1;

}
