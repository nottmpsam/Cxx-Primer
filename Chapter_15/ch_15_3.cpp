#include <iostream>
#include <sstream>
#include <typeinfo>
#include <stdexcept>
#include <cmath>
#include <cstring>

template <typename T>
std::string to_string_with_precision(const T value, int n = 6)
{
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << value;
    return out.str();
}

class bad_gmean: public std::logic_error
{
    double x, y;
    char* ch;
    public:
    explicit bad_gmean(double _x = 0.0, double _y = 0.0, const std::string &str = "error: bad_gmean");
    const char* what() const noexcept override { return ch; }
    virtual ~bad_gmean() throw() { delete [] ch; }
};
bad_gmean::bad_gmean(double _x, double _y, const std::string &str)
        : logic_error(str), x(_x), y(_y) 
{
    std::string _str = "Values: " + to_string_with_precision(x, 3) + " " + to_string_with_precision(y, 3)  + '\n';
    _str += str;
    _str += '\n';
    ch = new char[_str.length() + 1];
    std::strcpy(ch, _str.c_str());
}
class bad_hmean: public bad_gmean
{
public:
    explicit bad_hmean(double _x = 0.0, double _y = 0.0, const std::string &str = "error: bad_hmean") 
        : bad_gmean(_x, _y, str){ }
};
double hmean(double a, double b)
{
    if (a == -b) { 
        throw bad_hmean(a, b, __PRETTY_FUNCTION__);
    }
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0) {
        throw bad_gmean(a, b, __PRETTY_FUNCTION__);
    }
    return std::sqrt(a * b); 
}

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    
    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try {                  // start of try block
            z = hmean(x,y);
            cout << "Harmonic mean of " << x << " and " << y
                << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y
                << " is " << gmean(x,y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }// end of try block
        catch (std::logic_error & e)    // start of catch block
        {
            if (typeid(e) == typeid(bad_gmean &)) {
                e = dynamic_cast<bad_gmean &>(e);
                std::cout << e.what();
                std::cout << "You're bad guy: All values are negative!!!\n";
            }
            if (typeid(e) == typeid(bad_hmean &)) {
                e = dynamic_cast<bad_hmean &>(e);
                std::cout << e.what();
                std::cout << "You're not good boy: One value is negative!\n";
            } // end of catch block
            break;
        }
    }
    std::cout <<x << std::endl;
    cout << "Bye!\n";
    // cin.get();
    // cin.get();
    return 0;
}


