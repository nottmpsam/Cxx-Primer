#include <iostream>
#include "9_4_header.h"

namespace SALES
{
    void setSales(Sales &s, const double ar[], int n) 
    {
        if (n <= 0) return;
        int currentRange = QUARTES;
        if (n < QUARTES) {
            currentRange = n;
        }
        int i = 0;
        s.max = ar[i];
        s.min = ar[i];
        s.average = 0.0;
        double temp{};
        while (i < currentRange) {
            temp = ar[i];
            s.sales[i] = temp;
            if (s.max < temp) s.max = temp;
            if (s.min > temp) s.min = temp;
            s.average += temp;
            ++i;
        }
        while (currentRange != QUARTES && i < QUARTES) {
            s.sales[i] = 0;
            ++i;
        }
        s.average /= currentRange;
    }
    void setSales(Sales &s)
    {
        double temp{};
        while (!(std::cin >> temp)) {
                std::cin.clear();
                while (std::cin.get() != '\n') continue;
        }
        s.sales[0] = temp;
        s.average = 0.0;
        s.max = s.min = temp;
        for (int i = 1; i < QUARTES; ++i) {
            while (!(std::cin >> temp)) {
                std::cin.clear();
                while (std::cin.get() != '\n') continue;
            }
            s.sales[i] = temp;
            if (s.max < temp) s.max = temp;
            if (s.min > temp) s.min = temp;
            s.average += temp;
        }
        s.average /= QUARTES;
        s.max = s.max;
        s.min = s.min;
    }
    void showSales(const Sales &s)
    {
        std::cout << "Sales: ";
        for (int i = 0; i < QUARTES; ++i) {
            std::cout << s.sales[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Average: " << s.average << std::endl
            << "Max: " << s.max  << " "
            << "Min: " << s.min << std::endl
            << "******************" << std::endl;
    }
}
