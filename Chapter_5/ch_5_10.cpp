#include <iostream>

void version_1(const int &);
void version_2(const int &);
const int Size = 100;
const char s = '*';
const char p = '.';
	
int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;

	int range_count{};
	cout << "Enter an integer as a range for my beatiful painting! ";
	cin >> range_count;

	version_1(range_count);
	version_2(range_count);
	
	return 0;
}
void version_1(const int &range_count)
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "1st version: " << endl;

	char square[Size][Size];	
	int count_p = 1;
	for (int i = 0; i < range_count; ++i)
	{
		for (int j = 0; j < range_count - count_p; ++j)
		{
			square[i][j] = p;
		}
		++count_p;
	}

	int count_s = 0;
	for (int i = range_count - 1; i >= 0; --i) //[4][4] - [3][3]
	{
		for (int j = range_count - 1; j >= count_s; --j) 
		{
			square[i][j] = s;
		}
		++count_s; 
	}

	for (int i = 0; i <= range_count; ++i)
	{
		for (int j = 0; j <= range_count; ++j)
		{
			cout << square[i][j];
		}
		cout << endl;
	}
}

void version_2(const int &range_count)
{
	using std::cin;
	using std::cout;
	using std::endl;
	
	cout << "2nd version: " << endl;

	char square[Size][Size];
	int count_s = 1;
	for (int i = 0; i < range_count; ++i)
	{
		for (int j = 0; j < range_count - count_s; ++j)
		{
			square[i][j] = p;
			cout << square[i][j];
		}
		for (int n = count_s; n > 0; --n)
		{
			square[i][n] = s;
			cout << square[i][n];
		}
		++count_s;
		cout << endl;
	}
}