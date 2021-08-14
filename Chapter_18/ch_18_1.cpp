#include <iostream>
#include <initializer_list>
#include <algorithm>
template <typename T>
T average_list(const std::initializer_list<T> &list)
{
    T count = 0;
    std::for_each(list.begin(), list.end(), 
            [&count](T x) { count += x; });
    return count / list.size();
}
int main()
{
    using namespace std;
    auto q = average_list({15.4, 10.7, 9.0});
    cout << q << endl;
    cout << average_list({20, 30, 19, 17, 45, 38}) << endl;
    auto ad = average_list<double>({'a', 70, 65.33});
    cout << ad << endl;
}
