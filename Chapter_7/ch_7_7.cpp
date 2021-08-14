// arrfun3.cpp -- array functions and const
#include <iostream>
const int Max = 5;

// function prototypes
int fill_array(double ar[], int limit);
void show_array(const double ar[], int n);  // don't change data
void revalue(double r, double ar[], int n);
const double * fill_array_1(double*, const double*);
void show_array_1(const double*, const double*);
void revalue_1(double*, const double*, double);
int main()
{
    using namespace std;
    double properties[Max];

	const double* end = fill_array_1(properties, properties+Max);
	show_array_1(properties, end);
	if (end != &properties[0]) {
		std::cout << "Enter revaluation factor: ";
		double factor;
		while (!(std::cin >> factor)) {
			std::cin.clear();
			while (std::cin.get() != '\n') {
				continue;
			}
			cout << "Bad input; Please enter a number: ";
		}
		revalue_1(properties, end, factor);
		show_array_1(properties, end);
	}
	/*
    int size = fill_array(properties, Max);
    show_array(properties, size);
    if (size > 0)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor))    // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
           cout << "Bad input; Please enter a number: ";
        }
        revalue(factor, properties, size);
        show_array(properties, size);
    }
	*/
    // cin.get();
    // cin.get();
	cout << "Done.\n";
    return 0;
}

const double* fill_array_1(double *ar, const double * end)
{
	double temp;
	double *pt = nullptr;
	for (pt = ar; pt != end; ++pt) {
		std::cout << "Enter value: "; 
		if (!(std::cin >> temp)) {
			std::cin.clear();
			while (std::cin.get() != '\n')
				continue;
			std::cout << "Bad input..." << std::endl;
			break;
		} else if  (temp < 0) { 
			break;
		}
		*(pt) = temp;
	}
	return pt;
}
int fill_array(double ar[], int limit)
{
    using namespace std;
    double temp;
    int i;
    for (i = 0; i < limit; i++)
    {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if (!cin)    // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
           cout << "Bad input; input process terminated.\n";
           break;
        }
        else if (temp < 0)     // signal to terminate
            break;
        ar[i] = temp;
    }
    return i;
}
void show_array_1(const double *ar, const double * end) {
	for (const double *begin = ar; end != begin; ++begin) 
	{
		std::cout << *begin << std::endl;
	}
}
// the following function can use, but not alter,
// the array whose address is ar
void show_array(const double ar[], int n)
{
    using namespace std;
    for (int i = 0; i < n; i++)
    {
        cout << "Property #" << (i + 1) << ": $";
        cout << ar[i] << endl;
    }
}

// multiplies each element of ar[] by r
void revalue_1(double*ar, const double* end, double r)
{
	for (double* begin = ar; end != begin; ++begin) {
		*(begin) *= r;
	}
}
void revalue(double r, double ar[], int n)
{
    for (int i = 0; i < n; i++)
        ar[i] *= r;
}

