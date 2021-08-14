#include <iostream>

int main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;
	//cout.setf(std::ios_base::fixed, std::ios_base::floatfield);

	long long comein;
	cout << "Enter the number of seconds: ";
	cin >> comein;

	const unsigned H = 24;
	const unsigned M = 60;
	const unsigned S = 60;
	unsigned const Total = H*M*S;

	unsigned days = comein/(Total);
	unsigned long for_hours = comein - days*Total;
	unsigned hours = for_hours / (M * S);
	unsigned for_minutes = for_hours - hours * (M * S);
	unsigned minutes = for_minutes / M;
	unsigned seconds = for_minutes - minutes * S;

	cout << comein << " seconds = " 
	<< days << " days, " << hours << " hours, "
	<< minutes << " minutes, " << seconds 
	<< " seconds " << endl;

	return 0;	
}