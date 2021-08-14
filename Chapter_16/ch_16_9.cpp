#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <algorithm>
/*
    Enter range: 10000000
    Vector is sorted? Answer: 0
    9.65667 sec.
    Vector is sorted? Answer: 1
    List is sorted? Answer: 0
    29.9545 sec.
    List is sorted? Answer: 1
    List is sorted? Answer: 0
    16.2515 sec.
    List is sorted? Answer: 1
*/
void show(int n);

void sortVi(std::vector<int> &v)
{
    auto t2 = std::chrono::high_resolution_clock::now();
    std::sort(v.begin(), v.end());
    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = t1 - t2;
    std::cout << elapsed.count() / 1000000  << " sec." << std::endl;
}

void sortLi(std::list<int> &l)
{
    auto t2 = std::chrono::high_resolution_clock::now();
    l.sort();
    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = t1 - t2;
    std::cout << elapsed.count() / 1000000  << " sec." << std::endl;
}
void sortLiwithVi(std::list<int> &l)
{
    std::vector<int> v(l.size());
    auto t2 = std::chrono::high_resolution_clock::now();
    std::copy(l.begin(), l.end(), v.begin());
    std::sort(v.begin(), v.end());
    l.clear();
    std::copy(v.begin(), v.end(), std::insert_iterator<std::list<int>> (l,l.begin()));
    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = t1 - t2;
    std::cout << elapsed.count() / 1000000  << " sec." << std::endl;
}
template <typename T>
void display(const T& t);
int main()
{
    int n;
    std::cout << "Enter range: ";
    std::cin >> n;
    std::vector<int> vi0(n);
    std::vector<int> vi(n);
    std::list<int> li;
    std::cout << li.size() << std::endl;
    int temp;
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        temp = 1 + rand() % 1000;
        vi0[i] = vi[i] = temp;
        li.push_back(temp);
    }
    std::cout << "Vector is sorted? Answer: " << std::is_sorted(vi.begin(), vi.end()) << std::endl;
    sortVi(vi);
    std::cout << "Vector is sorted? Answer: " << std::is_sorted(vi.begin(), vi.end()) << std::endl;

    std::cout << "List is sorted? Answer: " << std::is_sorted(li.begin(), li.end()) << std::endl;
    sortLi(li);
    std::cout << "List is sorted? Answer: " << std::is_sorted(li.begin(), li.end()) << std::endl;

    li.clear();
    std::copy(vi0.begin(), vi0.end(), std::insert_iterator<std::list<int>> (li,li.begin()));

    std::cout << "List is sorted? Answer: " << std::is_sorted(li.begin(), li.end()) << std::endl;
    sortLiwithVi(li);
    std::cout << "List is sorted? Answer: " << std::is_sorted(li.begin(), li.end()) << std::endl;

    return 0;
}
template <typename T>
void display(const T& t)
{
    for (auto&& i : t) std::cout << i << " ";
    std::cout << std::endl;
}
void show(int n)
{
    std::cout << n << " ";
}
