#include <iostream>
const int Seasons = 4;
void fill(int*, const char *[Seasons]);
void show(const int *, const char *[Seasons]);
int main()
{
	int expenses[Seasons];
	const char *snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"}; 
	fill(expenses, snames);
	show(expenses, snames);
	return 0;
}
void fill (int* expenses, const char *snames[Seasons]) {
	for (int i = 0; i < Seasons; ++i) {
		std::cout<<"Enter " << snames[i] << " expenses: ";
		std::cin >> *expenses;
		++expenses;
	}
}
void show(const int* arr, const char *snames[Seasons]) {
	double total{};
	std::cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; ++i) {
		std::cout << snames[i] << ": $" << (*arr) << std::endl;
		total += (*arr);
		++arr;
	}
	std::cout << "Total: $" << total << std::endl;
}
