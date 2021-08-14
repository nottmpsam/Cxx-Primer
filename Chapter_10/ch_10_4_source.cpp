#include <iostream>
#include "ch_10_4_header.h"

SALES::Sales::Sales(const double *ar, int n)
{
    if (n <= 0) 
        return;
    int currentRange = QUARTES;
    if (n < QUARTES) {
        currentRange = n;
    }
    int i = 0;
    max = ar[i];
    min = ar[i];
    average = 0.0;
    double temp = 0.0;
    while (i < currentRange) {
        temp = ar[i];
        sales[i] = temp;
        if (max < temp) max = temp;
        if (min > temp) min = temp;
        average += temp;
        ++i;
    }
    while (currentRange != QUARTES && i < QUARTES) {
        sales[i] = 0;
        ++i;
    }
    average /= currentRange;
}
SALES::Sales::Sales()
{
    //cuz conf of exer
    double temp{};
    while (!(std::cin >> temp)) {
        std::cin.clear();
        while (std::cin.get() != '\n') 
            continue;
    }
    sales[0] = temp;
    average = temp;
    max = min = temp;
    for (int i = 1; i < QUARTES; ++i) {
        while (!(std::cin >> temp)) {
            std::cin.clear();
            while (std::cin.get() != '\n')
                continue;
        }
        sales[i] = temp;
        if (max < temp) max = temp;
        if (min > temp) min = temp;
    }
    average /= QUARTES;
}
void SALES::Sales::showSales() const
{
    std::cout << "Sales: ";
    for (int i = 0; i < QUARTES; ++i)
        std::cout << sales[i] << " ";
    std::cout << std::endl;
    std::cout << "Average: " << average
        << std::endl
        << "Max: " << max << std::endl
        << "Min: " << min << std::endl
        << "*****************" << std::endl;
}
