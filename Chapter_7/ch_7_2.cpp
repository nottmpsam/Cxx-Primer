#include <iostream>

const int N = 10;
int enter(int*);
void show(int*, int);
double average(int*, int);

int main()
{
	int arr[N];
	int range = enter(arr);
	show (arr, range);
	return 0;
}
double average(int* arr, int n) 
{
	int avr = 0;
	for (int i = 0; i < n; ++i) {
		avr += arr[i];
	}
	return (avr/n);
}
void show(int* arr, int n)
{
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\nAverage:" << average(arr, n) << std::endl;
}
int enter(int* arr)
{
	int temp;
	int i;
	for (i = 0; i < N; ++i) {
		if (!(std::cin >> temp)) {
			std::cin.clear();
			while (std::cin.get() != '\n') {
				continue;
			}
			break;
		}
		arr[i] = temp;
	}
	return i;
}
