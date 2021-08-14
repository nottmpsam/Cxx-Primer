#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
std::vector<int> Lotto(int, int);
int main()
{
    std::vector<int> winners;
    winners = Lotto(51, 6);
    for (auto&& i : winners) std:: cout << i << ' ';
    std::cout << std::endl;
    return 0;
}
std::vector<int> Lotto(int nCards, int nNumbers)
{
    std::vector<int> winners(nCards);
    std::iota(winners.begin(), winners.end(), 1);
    std::random_shuffle(winners.begin(), winners.end());
    //for (auto&& i : winners) std:: cout << i << ' ';
    //std::cout << std::endl;
    winners.resize(nNumbers);
    return winners;
}
