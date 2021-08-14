#include <iostream>

int main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;
	//cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	
	float km, l;
	cout << "Enter your traveled distance: ";
	cin >> km;
	cout << "How much petrol it used? Enter: ";
	cin >> l;
	double per_km = l / km;
	cout << "For 1 km used " << per_km << " litres" << endl;
	
	cout << "For 100 km will be used " << per_km * 100 << " litres" << endl; 
	return 0;
}