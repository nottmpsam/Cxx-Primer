#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
#include <fstream>

std::multiset<std::string> enterFriends()
{
    std::multiset<std::string> _cont;
    std::string str;
    std::cout << "Enter the file with names of friends(q - to quit):\n";
    getline(std::cin, str);
    std::ifstream fi(str);
    if (!fi.is_open()) {
        std::cerr << "File didn't opened: " << str 
            << std::endl;
        std::exit(EXIT_FAILURE);
    }
    while (getline(fi, str)) {
        _cont.insert(str);
    }
    return _cont;
}

int main()
{
    std::multiset<std::string> MattFriends = enterFriends();
    auto PattFriends = enterFriends();
    std::cout << "Here are MattFriends:\n";
    for (auto&& i: MattFriends) std::cout << i << "  ";

    std::cout << "\nHere are PattFriends:\n";
    std::ostream_iterator<std::string, char> out(std::cout, "  ");
    std::copy(PattFriends.begin(), PattFriends.end(), out);

    std::set<std::string> withoutDublicats;
    std::set_union(MattFriends.begin(), MattFriends.end(), PattFriends.begin(),
            PattFriends.end(), std::insert_iterator<std::set<std::string>> (withoutDublicats, withoutDublicats.begin()));
    std::cout << "\nAnd now: " << std::endl;
    std::copy(withoutDublicats.begin(), withoutDublicats.end(), out);

    std::cout << "\nEnter output File:\n";
    std::string str;
    getline(std::cin, str);
    std::ofstream outputFile(str);
    for (auto i: withoutDublicats) outputFile << i << std::endl;
    return 0;
}


