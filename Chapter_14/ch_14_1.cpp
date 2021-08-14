#include <iostream>
#include <valarray>
template <typename T1, typename T2>
class Pair
{
    T1 a;
    T2 b;
public:
    Pair();
    ~Pair();
    Pair(const T1&_a, const T2&_b) : a(_a), b(_b) {}
    T1& first();
    T2& second();
    const T1& first() const;
    const T2& second() const;
    template <typename U, typename Q>
    friend std::ostream & operator<<(std::ostream &os, const Pair<U, Q> &t0);
    friend std::ostream & operator<<(std::ostream &os, const Pair<std::valarray<int>, std::valarray<int>> &t0);
    //?
};

template <typename T1, typename T2>
Pair<T1, T2>::Pair() {}

template <typename T1, typename T2>
Pair<T1, T2>::~Pair() {}
template <typename U, typename Q>
std::ostream & operator<<(std::ostream &os, const Pair<U, Q> &t0)
{
    os << "[ " << t0.a << ", " << t0.b << " ] ";
    return os;
}
std::ostream & operator<<(std::ostream &os, const Pair<std::valarray<int>, std::valarray<int>> &t0)
{
    if (t0.first().size() == t0.second().size()) {
        for (int i = 0; i < t0.first().size(); ++i) {
            std::cout << t0.first()[i] << ", " << t0.second()[i] << std::endl;
        }
    } else {
        int i, j;
        for (i = 0, j = 0; i < t0.first().size() && j < t0.second().size(); ++i, ++j) {
            std::cout << t0.first()[i] << ", " << t0.second()[j] << std::endl;
        }
        while (i < t0.first().size()) {
            std::cout << t0.first()[i] << std::endl;
        }
        while (j < t0.second().size()) {
            std::cout << t0.second()[j] << std::endl;
        }
    }
    return os;
}
template <typename T1, typename T2>
T1& Pair<T1, T2>::first()
{
    return a;
}

template <typename T1, typename T2>
T2& Pair<T1, T2>::second()
{
    return b;
}

template <typename T1, typename T2>
const T1& Pair<T1, T2>::first() const 
{
    return a;
}

template <typename T1, typename T2>
const T2& Pair<T1, T2>::second() const 
{
    return b;
}

class Wine
{
    std::string label;
    typedef std::valarray<int> arrayInt;
    Pair<arrayInt, arrayInt> pairArray;
public:
    Wine();
    virtual ~Wine();
    Wine(const char* _label, int nYears, const int years[] = nullptr, const int bottles[] = nullptr);
    void getBottles();
    int sum() const;
    std::string& getLabel();
    const std::string& getLabel() const;
    void show() const;
    friend std::ostream & operator<<(std::ostream &os, const Wine &t0);
};
void Wine::getBottles()
{
    std::cout << "Enter " << label << 
        " data for " << pairArray.first().size() 
        << " years(s): " << std::endl;
    for (int i = 0; i < pairArray.first().size(); ++i) {
        std::cout << "Enter year: ";
        while (!(std::cin >> pairArray.first()[i])) {
            std::cin.clear();
            while (std::cin.get() != '\n') {
                continue;
            }
        }
        while (std::cin.get() != '\n') {
            continue;
        }
        std::cout << "Enter bottles for that year: ";
        while (!(std::cin >> pairArray.second()[i])) {
            std::cin.clear();
            while (std::cin.get() != '\n') {
                continue;
            }
        }
        while (std::cin.get() != '\n') {
            continue;
        }
    }
}
const std::string& Wine::getLabel() const
{
    return label;
}
std::string& Wine::getLabel()
{
    return label;
}
int Wine::sum() const
{
    return pairArray.second().sum();
}
void Wine::show() const
{
    std::cout << *this;
}
std::ostream & operator<<(std::ostream &os, const Wine &t0)
{
    /*
    std::cout << "* " << t0.label << " *" << std::endl;
    for (int i = 0; i <  t0.pairArray.first().size(); ++i) {
        std::cout << t0.pairArray.first()[i]  << ", " << t0.pairArray.second()[i] 
            << std::endl;
    }*/
    std::cout << "* " << t0.label << " *" << std::endl << t0.pairArray;
    return os;
}

Wine::Wine(const char* _label, int nYears, const int years[], const int bottles[])
{
    label = _label;
    pairArray.first().resize(nYears);
    pairArray.second().resize(nYears);
    if (years && bottles)
        for (int i = 0; i < nYears; ++i) {
            pairArray.first()[i] = years[i];
            pairArray.second()[i] = bottles[i];
        }
}

Wine::~Wine() { }
Wine::Wine() : label(""), pairArray() { }
//в этом конструкторе pairArray можно было также oпустить

int main()
{
    std::cout << "Enter name of wine: ";
    char lab[50];
    std::cin.getline(lab, 50);
    std::cout << "Enter number of years: ";
    int yrs;
    std::cin >> yrs;
    Wine holding(lab, yrs);
    holding.getBottles();
    holding.show();
    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = {48, 60, 72};
    Wine more("Gushing Grape Red", YRS, y, b);
    more.show();
    return 0;
}
