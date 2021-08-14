#include <iostream>
#include <array>
const int Size = 10;
int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;
	std::array<double, Size> arr;
	
	cout << "Any non integer symbol to quit. Size = 10..." << endl;
	int i{};
	double total{};
	while(i < Size && cin >> arr[i])
	{
		total += arr[i];
		++i;
	}
	double index = total / i;
	cout << "Index: " << index  << endl;
	
	cout << "[ ";
	for(int j = 0; j < i; ++j)
	{
		if (arr[j] > index) {
			cout << arr[j] << " ";
		}
	}
	cout << "]" << endl;

	return 0;
}