#include <iostream>
#include <valarray>
typedef std::valarray<int> a;
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
   /* Pair& operator=(const Pair<std::valarray<int>, std::valarray<int>> &);*/
};
/*
template<>
Pair<a,a>& Pair<a,a>::operator=(const Pair<std::valarray<int>, std::valarray<int>> &t0) 
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    int size = t0.first().size();
    first().resize(size);
    second().resize(size);
    int i, j;
    for (i = j = 0; i < first().size() && j < second().size(); ++i, ++j) {
        first()[i] = t0.first()[i];
        second()[j] = t0.second()[j];
    }
    for ( ; i < first().size(); ++i) { 
        first()[i] = t0.first()[i];
    }
    for ( ; j < second().size(); ++j) {
        second()[j] = t0.second()[j];
    }
    return *this;
}*/
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

class Wine: private Pair<a, a>, /*private*/ std::string
{
public:
    //по умолчанию для двух конструкторов
    Wine();
    virtual ~Wine();
    Wine(const char* _label, int nYears, const int years[] = nullptr, const int bottles[] = nullptr);
    std::string& getLabel();
    const std::string& getLabel() const;
    int sum() const;
    void show() const;
    friend std::ostream& operator<<(std::ostream &os, const Wine &t0);
    void getBottles();
    Wine& operator=(const Wine&);
};
Wine& Wine::operator=(const Wine& t0)
{
    (std::string&)*this = (std::string&)t0;
    (Wine::Pair&)*this = (Wine::Pair&)t0;
    return *this;
}

Wine::Wine() 
{}
Wine::~Wine()
{}
void Wine::show() const
{ std::cout << *this; }

std::ostream& operator<<(std::ostream& os, const Wine &t0)
{
    os << (const std::string&) t0 << std::endl;
    os << (const Wine::Pair&) t0;
    return os;
}
int Wine::sum() const
{
    return second().sum();
}
const std::string& Wine::getLabel() const
{
    return (const std::string&) *this;
}
std::string& Wine::getLabel()
{
    return (std::string&) *this;
}
Wine::Wine(const char* _label, int nYears, const int years[], const int bottles[])
    : std::string(_label) 
{
    first().resize(nYears);
    second().resize(nYears);
    if (years && bottles) {
        for (int i = 0; i < nYears; ++i) {
            first()[i] = years[i];
            second()[i] = bottles[i];
        }
    }
}
void Wine::getBottles()
{
    //int size = ((const Wine::Pair&) *this).first().size();
    int size = first().size();
    std::cout << "Enter " << (const std::string &) *this <<
        " data for " <<  size
        << " years(s): " << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter year: ";
        while (!(std::cin >> first()[i])) {
            std::cin.clear();
            while (std::cin.get() != '\n') {
                continue;
            }
        }
        while (std::cin.get() != '\n') {
            continue;
        }
        std::cout << "Enter bottles for that year: ";
        while (!(std::cin >> second()[i])) {
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
int main()
{
    std::cout << "enter name of wine: ";
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
    std::cout << "And now.." << std::endl;
    holding = more;
    holding.show();
    return 0;
}
