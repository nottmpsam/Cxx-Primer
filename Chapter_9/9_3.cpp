#include <iostream>
#include <cstring>
struct chaff
{
    char dross[20];
    int slag;
};
void showChaff(const chaff &_chaff)
{
    std::cout << "*************" << std::endl;
    std::cout << _chaff.dross << " | " << &_chaff.dross
        << std::endl
        << _chaff.slag << " | " << &_chaff.slag
        << std::endl;
    std::cout << "*************" << std::endl;
}
void setChaff(chaff &_chaff, const char* _dross, int _slag)
{
    strncpy(_chaff.dross, _dross, sizeof(_chaff.dross) - 1); //~19 in our case
    _chaff.dross[sizeof(_chaff.dross)-1] = '\0';
    _chaff.slag = _slag;
}
char BUF[240];
int main()
{
    int n;
    std::cout << "Enter number of struct (<= 10)" << std::endl;
L:
    while (!(std::cin >> n))
    {
        std::cin.clear();
        while (std::cin.get() != '\n') 
            continue;
    }
    if (n < 0 || n > 10) {
            goto L;
    }
    chaff* ptr = new (BUF) chaff[n];
    std::string str;
    int slag;
    for (int i = 0; i < n; ++i) {
        std::cin.get();
        std::cout << "Input dross #" << i + 1 << ": ";
        std::getline(std::cin, str);
        std::cout << "Enter slag: ";
        std::cin >> slag;
        setChaff(ptr[i], str.c_str(), slag);
    }
    for (int i = 0; i < n; ++i) {
        showChaff(ptr[i]);
    }
    chaff* ptr1 = new chaff[n];
    for (int i = 0; i < n; ++i) {
        std::cin.get();
        std::cout << "Input dross #" << i + 1 << ": ";
        std::getline(std::cin, str);
        std::cout << "Enter slag: ";
        std::cin >> slag;
        setChaff(ptr1[i], str.c_str(), slag);
    }
    for (int i = 0; i < n; ++i) {
        showChaff(ptr1[i]);
    }
    delete [] ptr1;
    return 0;
}
