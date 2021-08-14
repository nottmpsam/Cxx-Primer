#include <iostream>
#include <stdexcept>
#include <cmath>

class error_bad_hmean: public std::logic_error 
{
public:
    explicit error_bad_hmean(const std::string &str = "error_bad_hmean") : logic_error(str) { }
};
class error_bad_gmean: public std::logic_error 
{
public:
    explicit error_bad_gmean(const std::string &str = "error_bad_gmean") : logic_error(str) { }
};

double hmean(double a, double b)
{
    if (a == -b) { 
        std::string str = "***********************\n";
        str += __PRETTY_FUNCTION__;
        str += "\ninvalid arguments: a = -b\n";
        str += "***********************\n";
        throw error_bad_hmean(str);
    }
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0) {
        std::string str = "***********************\n";
        str += __PRETTY_FUNCTION__;
        str += "\ngmean() arguments should be >= 0\n";
        str += "***********************\n";
        throw error_bad_gmean(str);
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
        catch (error_bad_hmean & e)    // start of catch block
        {
            std::cout << e.what();
            cout << "Try again.\n";
            continue;
        }                  
        catch (error_bad_gmean & e) 
        {
            std::cout << std::endl;
            std::cout << e.what();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        } // end of catch block
    }
    cout << "Bye!\n";
    // cin.get();
    // cin.get();
    return 0;
}


