#include <iostream>
#include "ch_10_header.h"

int main()
{
    golf ask;
    ask.showgolf();
    golf answer("Sam", 32);
    answer.setHandicap(4);
    answer.showgolf();
    return 0;
}
