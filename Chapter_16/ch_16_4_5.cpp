#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
template <typename T>
void display(T a[], int n)
{
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void shaker_sort(T a[], int size)
{
	int Lt = 0;
	int R = 0;
	int L  = size - 1;
	int Rt = size - 1;
	T b, c;

	while ((R != Rt) && (L != Lt))
	{
		R = Rt;
		for(int i = Lt; i < R; i++)
		{
			if(a[i] > a[i + 1])
			{
                b = a[i];
				a[i] = a[i + 1];
				a[i + 1] = b;
				Rt = i;
			}
		}
        if (R != Rt)
        {
            L = Lt;
            for(int i = Rt; i > L ; i--) 
            {
                if(a[i] < a[i - 1])
                {	
                    c = a[i];
                    a[i] = a[i - 1];
                    a[i - 1] = c;
                    Lt = i;
                }
            }
        }
	}
}
template <typename T>
int reduce(T a[], int &n)
{
    shaker_sort(a, n);
    int j, q;
    int temp = n;
    for (int i = 0; i < n - 1; ++i)
    {
        j = 0;
        q = i;
        while (a[q] == a[q + 1] && (q + 1 < n)) {
            ++j;
            ++q;
        }
        if (j != 0) {
            for (int c = i + 1; c < n - j; ++c) 
                a[c] = a[c + j];
            n -= j;
        }
    }
    return temp - n;
}
template<typename T>
void show(T x)
{
    std::cout << x << " ";
}
template<typename T>
int with_stl(T b[], int n) 
{
    std::set<T> x;
    std::copy(b, b + n, std::insert_iterator<std::set<T>>(x, x.begin()));
    //std::for_each(x.begin(), x.end(), show);
    int i = 0;
    for (auto it = x.begin(); it != x.end(); ++it, ++i) {
        b[i] = *it;
    }
    return n - i;
}
int main()
{
    srand(time(0));
    {
        int n = rand() % 20 + 5;
        long* a = new long[n];
        long* b = new long[n];
        const int range = n;
        for (int i = 0; i < n; ++i) {
            int temp = rand() % 20 + 1;
            a[i] = b[i] = temp;
        }
        std::cout << "Our array:\n";
        display(a, n);
        std::cout << "After deleting...\n";
        std::cout << "Differ: " << reduce(a, n) << std::endl;
        display(a, n);
        int temp = with_stl(b, range);
        std::cout << "Differ: " << temp << std::endl;
        display(b, range - temp);
        delete [] b;
        delete [] a;
    }
    {
        int n = 5;
        const int range = n;
        std::string* a = new std::string[n];
        std::string* b = new std::string[n];
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            b[i] = a[i];
        }

        std::cout << "Our array:\n";
        display(a, n);
        std::cout << "After deleting...\n";
        std::cout << "Differ: " << reduce(a, n) << std::endl;
        display(a, n);
        int temp = with_stl(b, range);
        std::cout << "Differ: " << temp << std::endl;
        display(b, range - temp);
        delete [] b;
        delete [] a;
    }
    return 0;
}
