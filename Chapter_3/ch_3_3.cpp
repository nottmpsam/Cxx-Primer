#include <iostream>

int main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;
	//cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	
	int deg, min, sec;
		cout << "Enter a latitude in degrees, minutes, and seconds: \n"
	<< "First, enter the degrees: ";
	cin >> deg;
	cout << "Next, enter the minutes of arc: ";
	cin >> min;
	cout << "Finally, enter the seconds of arc: ";
	cin >> sec;

	const double Per = 60.0;
	const double Per_2 = 3600.0;
	double total_degrees = deg + min / Per + sec/ Per_2 ;

	cout << deg<< " degrees, " << min << " minutes, ";
    cout << sec << " seconds = " << total_degrees << " degrees." << endl;

	return 0;
}