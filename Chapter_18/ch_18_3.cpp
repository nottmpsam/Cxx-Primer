#include <iostream>
long double sum_values()
{
    return 0.0;
}
template <typename T, typename... Args>
long double sum_values(const T& value, const Args&... args)
{
    long double sum_value = 0;
    sum_value = value + sum_values(args...);
    return sum_value;
}

int main()
{
    std::cout << sum_values(12.5, 8, 10, -5, -5, 10) << std::endl;
    return 0;
}
