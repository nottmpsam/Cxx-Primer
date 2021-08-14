#include <iostream>
#include <cstring>
#include "ch_10_header.h"

golf::golf(const char * _fullname, int _handicap)
{
   strncpy(fullname, _fullname, Len - 1);
   fullname[Len - 1] = '\0';
   handicap = _handicap;
}

golf::golf()
{
    //cuz ex
    int _handicap;
    char _fullname[Len];
    std::cout << "Enter fullname: " << std::endl;
    std::cin.get(_fullname, Len);
    if (std::cin.get() != '\n')
    {
        std::cerr << __PRETTY_FUNCTION__ << " Overflow: std::cin.get(...)"
            << std::endl;
        while (std::cin.get() != '\n') {
            continue;
        }
    }
    while (!(std::cin >> _handicap)) 
    {
        std::cin.clear();
        while (std::cin.get() != '\n') {
            continue;
        }
    }
    while (std::cin.get() != '\n') {
        continue;
    }
    //cuz ex
    *this = golf(_fullname, _handicap);//временный объект
}
void golf::setHandicap(int _handicap)
{
    handicap = _handicap;
}
void golf::showgolf() const 
{
    std::cout << "Name: " << fullname << " , " 
        << "Handicap: " << handicap  << std::endl;
}

