#include <iostream>
#include <cctype>

void string_toUpper(std::string &str)
{
    for (int i = 0; i < str.length(); ++i) 
       str[i] = toupper(str[i]);
}

int main()
{
    std::string str;
    std::cout << "Enter a string (q to quit): ";
    while (std::getline(std::cin, str) && str != "q") {
        string_toUpper(str);
        std::cout << str << std::endl;
        std::cout << "Enter a string (q to quit): ";
    }
    return 0;
}
