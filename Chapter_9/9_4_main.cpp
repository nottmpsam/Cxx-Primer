#include <iostream>
#include "9_4_header.h"

int main()
{
    SALES::Sales q;
    SALES::setSales(q);
    SALES::showSales(q);

    using namespace SALES;
    srand(time(0));
    int n = 1 + rand() % 10;
    double* a = new double[n];
    for (int i = 0; i < n; ++i) {
        a[i] = 1 + rand() % 20 + 0.1;
    }

    Sales t; 
    setSales(t, a, n);
    showSales(t);
    delete [] a;

    return 0;
}
