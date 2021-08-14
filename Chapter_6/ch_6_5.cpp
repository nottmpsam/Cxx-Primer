#include <iostream>

int main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;
	const double percent_1 = 0.10;
	const double percent_2 = 0.15;
	const double percent_3 = 0.20;
	int stage1 = 5e3;
	int stage2 = 1e4;
	int stage3 = 2e4;
	int stage4 = 35e3;
	int coins;
	while (cin >> coins && coins >= 0)
	{
		if (coins <= stage1)
			cout << '0' << endl;
		else if (stage1 < coins && coins <= 15e3 )
			cout << stage2 * percent_1 << endl;
		else if (15e3 < coins && stage4 >= coins)
			cout << stage2 * percent_1 + stage3 * percent_2 << endl;
		else
		{
			coins -= stage4;
			cout <<  stage2 * percent_1 + stage3 * percent_2 + coins * percent_3 << endl;
		}

	}
	return 0;
}