#include <iostream>
#include "9_1_header.h"

int main()
{
    int n;
    std::cout << "How many lovers of golf do you know? Enter: ";
    std::cin >> n;
    golf* glovers = new golf[n];
    int i;
    for (i = 0; i < n && setgolf(glovers[i]); ++i);
    for (int j = 0; j < i; ++j) showgolf(glovers[j]);
    delete [] glovers;
    return 0;
}
