#include <iostream>

unsigned int Fill_array(double [], unsigned int);
void Show_array(double [], unsigned int);
void Reverse_array(double [], unsigned int);

int main()
{
	unsigned int n;
	std::cout << "Enter range: "<< std::endl;
	std::cin >> n;
	double * arr = new double[n];
	n = Fill_array(arr, n);
	int q;
	std::cin >> q;
	std::cout << q << std::endl;
	return 0;
	Show_array(arr, n);
	Reverse_array(arr,n);
	Show_array(arr, n);
	delete [] arr;
	return 0;
}
void Reverse_array(double arr[], unsigned int n) 
{
	int temp;
	for (int i = 0, j = n - 1; j != i; ++i, --j) {
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
void Show_array(double arr[], unsigned int n)
{
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
unsigned int Fill_array(double arr[], unsigned int n)
{
	int i = 0;
	int temp;
	while (i < n) { 
		if (!(std::cin >> temp)){
			std::cin.clear();
			while (std::cin.get() != '\n') {
				continue;
			}
			break;
		}
		arr[i] = temp;
		++i;
	}
	return i;
}
