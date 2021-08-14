#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
std::multiset<std::string> enterFriends()
{
    std::multiset<std::string> _cont;
    std::string str;
    std::cout << "Enter names of your friends(q - to quit):\n";
    getline(std::cin, str);
    while (str != "q"){
       _cont.insert(str);
       getline(std::cin, str);
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
    std::cout << std::endl;
    return 0;
}

