#include <iostream>
void show(const char* str, int count = 1);
int main()
{
    const char* str = "Biscuit is delicious";
    int count {};
    while (std::cin >> count)
        show(str, count);
    return 0;
}
void show(const char*str, int count) 
{
    if (!count) { 
        std::cout << str << std::endl;
        return;
    }
    count = (count < 0 ? -count : count);
    for (int i = 0; i < count; ++i){
        std::cout << str <<  std::endl;
    }
}
