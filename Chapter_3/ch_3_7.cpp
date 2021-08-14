#include <iostream>

int main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;
	//cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	
	float km, lt;
	cout << "Distance and used petrol(EU): ";
	cin >> km >> lt;

	double per_km = lt / km;
	const float gl_cn = 4.54609;
	const float ml_cn = 0.6214;
	double total = per_km * 100;
	double ml,gl;
	gl = lt / gl_cn;
	ml = km * ml_cn;
	cout << "Distance and used petrol(EU): " << km << " km " << lt << " litres" << endl;
	cout << "Distance and used petrol(US): " << ml << " miles " << gl << " gallons" << endl;
	
	cout << "Specifications of car(EU): "<< total << " litres/100 km"  << endl;
	cout << "Specifications of car(US): " <<"62.14 miles/ " << total / gl_cn << " gallons"  << endl;
		
	return 0;
} 
