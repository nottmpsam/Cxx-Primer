#include <iostream>
int countSymbols(const char* str)
{
    int i = 0;
    while (str[i]) {
        if (str[i] == '$') {
            break;
        }
        ++i;
    }
    if (str[i])
        return i;
    return -1;
}
int main()
{
    std::string str;
    getline(std::cin, str);
    std::cout << countSymbols(str.c_str()) << std::endl;
    return 0;
}
