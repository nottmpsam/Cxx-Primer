#include <iostream>

const int N = 5;
template <typename T>
T max5(T arr[])
{
    T max = arr[0];
    for (int i = 1; i < N; ++i) 
        max = max < arr[i] ? arr[i] : max;
    return max;
}
template <typename T>
void show(const T arr[])
{
    for (int i = 0;i < N; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
int main()
{
    double arr0[N];
    int arr1[N];
    srand(time(0));
    for (int i = 0; i < N; ++i) {
        arr0[i] = rand()%100 + 1.2;
        arr1[i] = rand()%100 + 20;
    }
    show(arr0);
    show(arr1);
    std::cout << max5(arr0) << std::endl << max5(arr1);
    return 0;
}
