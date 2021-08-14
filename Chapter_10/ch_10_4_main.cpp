#include <iostream>

#include "ch_10_4_header.h"

int main()
{
    SALES::Sales ask[5];
    for (int i = 0; i < 5; ++i) 
    {
        std::cout << "~~~~~~~~~~~~~~~~" << std::endl;
        ask[i].showSales();
        std::cout << "~~~~~~~~~~~~~~~~" << std::endl;
    }
    return 0;
}
