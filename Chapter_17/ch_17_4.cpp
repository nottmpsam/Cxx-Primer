#include <iostream>
#include <fstream>
#include <sstream>
int main()
{
    std::cout << "Enter 1st input file: ";
    std::string str;
    getline(std::cin, str);
    std::ifstream fi0(str);
    if (!fi0.is_open()) {
        std::cerr << "Didn't open: " << str << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "Enter 2nd input file: ";
    getline(std::cin, str);
    std::ifstream fi1(str);
    if (!fi1.is_open()) {
        std::cerr << "Didn't open: " << str << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "Enter output file: ";
    getline(std::cin, str);
    std::ofstream fo(str);
    std::string ss;
    while (true) {
        if (getline(fi0, ss))
            fo << ss << ' ';
        if (getline(fi1, ss))
            fo << ss << std::endl;
        if (fi0.fail() && fi1.fail()) {
            break;
        }
    }
    /*
    char ch;
    while (true) {
        while (fi0.get(ch)) {
            if (ch == '\n') {
                fo << ' ';
                break;
            }
            fo << ch;
        }
        while (fi1.get(ch)) {
            if (ch == '\n') {
                fo << ch;
                break;
            }
            fo << ch;
        }
        if (fi0.fail() && fi1.fail()) {
            break;
        }
    }*/
    return 0;
}
