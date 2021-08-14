#include <iostream>
#include <cstring>
#include "9_1_header.h"

void setgolf(golf &g, const char* name, int hc)
{
    int length = sizeof (char) * Len - 1; //~ Len - 1 (just for fun)
    strncpy(g.fullname, name, length); // < length
    g.fullname[length] = '\0';
    g.handicap = hc;
}

int setgolf(golf &g)
{
    std::cout << "At first enter player's handicap: ";
    int temp;
    while (!(std::cin >> temp)) {
        std::cin.clear();
        while (std::cin.get() != '\n') {
            continue;
        }
        std::cout << "Enter handicap again: ";
    }
    while (std::cin.get() != '\n') continue;
    g.handicap = temp;
    std::cout << "Now enter player's full name: ";
    std::cin.getline(g.fullname, Len); //if std::cin.get(...) - another way;
    if (g.fullname[0] == '\0')
        return 0;
    if (!std::cin) {
        std::cerr <<__PRETTY_FUNCTION__
            <<" (Overflow)... was written: " << g.fullname << std::endl;
        char temp1;
        std::cin.clear();
        std::cin.get(temp1); //clear
        while (temp1 != '\n') {
            std::cin.get(temp1);
        }
    }
    return 1;
}

void handicap(golf &g, int hc)
{
    g.handicap = hc;
}
void showgolf(const golf &g)
{
    std::cout << "Full name: " << g.fullname << std::endl
        << "Handicap: " << g.handicap << std::endl;
}
