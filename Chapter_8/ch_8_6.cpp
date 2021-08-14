#include <iostream>
#include <cstring>


template <typename T>
T maxn(T arr[], int range)
{
    T max = arr[0];
    for (int i = 1; i < range; ++i) 
        max = max < arr[i] ? arr[i] : max;
    return max;
}
template <>char* maxn<char*>(char *arr[], int range)
{
    int currentLength = strlen(arr[0]);
    char* ptr = arr[1];
    int temp = 0;
    for (int i = 0; i < range; ++i) {
        temp = strlen(arr[i]);
        if (temp > currentLength) {
            currentLength = temp;
            ptr = arr[i];
        }
    }
    return ptr;
}
template <typename T>
void show(const T arr[], int n)
{
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << std::endl;
    }
}
int main()
{
    const int range = 10;
    int q[range];
    for (int i = 0; i < range; ++i) {
        q[i] = rand () % 20;
    }
    show(q, range);
    std::cout << maxn(q, range) << std::endl;
    const int strrange = 5;
    char* strings[strrange];
    for (int i = 0; i < strrange; ++i) {
        strings[i] = new char[range];
        std::cin.getline(strings[i], range);
    }
    show(strings, strrange);
    char* maxStr = maxn(strings, strrange);
    std::cout << maxStr << std::endl;
    for (int i = 0; i < strrange; ++i) {
        delete [] strings[i];
    }
    return 0;
}
