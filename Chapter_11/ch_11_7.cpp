#include <iostream>
#include <cmath>
#include <ostream>
class Complex 
{
    double re;
    double im;
public:
    Complex(double _re = 0.0, double _im = 0.0);
    Complex operator+(const Complex &t1) const;
    Complex operator-(const Complex &t1) const;
    //another way:
    //explicit Complex(double _re = 0.0, double _im = 0.0);
   //Complex operator*(const Complex &t1) const;
   //Complex operator*(double x) const;
    //friend Complex operator*(double x, const Complex &t0);
    friend Complex operator*(const Complex &t0, const Complex &t1);
    Complex operator~() const;
    //inline
    double magVal() const { return std::sqrt(re * re + im * im); }
    double angVal() const { return std::atan2(im, re); }
    //
    friend std::ostream & operator<<(std::ostream &os, const Complex &t0);
    friend std::istream & operator>>(std::istream &is, Complex &t1);
};
std::istream & operator>>(std::istream &is, Complex &t1)
{
    std::cout << "real: ";
    is >> t1.re;
    std::cout << "imaginary: ";
    is >> t1.im;
    return is;
}
std::ostream & operator<<(std::ostream &os, const Complex &t0)
{
    os << "(" << t0.re << "," << t0.im << "i)";
    return os;
}
Complex Complex::operator~() const
{
    return Complex(re, -im);
}
Complex operator*(const Complex &t0, const Complex &t1)
{
    return Complex(t0.re * t1.re - t0.im * t1.im, t0.re * t1.im + t0.im * t1.re);
}
/*
Complex operator*(double x, const Complex &t0)
{
    return t0 * x;
    //return t0.operator*(x);
}
Complex Complex::operator*(double x) const
{
    return Complex(x * re, x * im);
}
Complex Complex::operator*(const Complex &t1) const
{
    return Complex(re * t1.re - im * t1.im, re * t1.im + im * t1.re); 
}
*/
Complex Complex::operator-(const Complex &t1) const
{
    return Complex(re - t1.re, im - t1.im);
}
Complex Complex::operator+(const Complex &t1) const
{
    return Complex(re + t1.re, im + t1.im);
}

Complex::Complex(double _re, double _im)
{
    re = _re;
    im = _im;
}
int main()
{
    Complex a(3.0, 4.0);
    Complex c;
    std::cout << "Enter a complex number (q to quit):\n";
    while (std::cin >> c)
    {
        std::cout << "c is " << c << std::endl;
        std::cout << "Complex conjugate is " << ~c << std::endl;
        std::cout << "a is " << a << std::endl
            << "a + c is " << a + c << std::endl
            << "a - c is " << a - c << std::endl
            << "a * c is " << a * c << std::endl
            << "2 * c is " << 2 * c << std::endl;
        std::cout << "Enter a complex number (q to quit): \n";
    }
    std::cout << "Done!\n";
    return 0;
}
