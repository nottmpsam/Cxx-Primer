#include <iostream>
#include <cmath>
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype
using namespace std;
namespace VECTOR
{
    class Vector
    {
    public:
        enum Mode {RECT, POL};
    // RECT for rectangular, POL for Polar modes
    private:
        double x;          // horizontal value
        double y;          // vertical value
        Mode mode;         // RECT or POL
    // private methods for setting values
        void set_x(double mag, double ang);
        void set_y(double mag, double ang);
        void set_x();
        void set_y();
    public:
       Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double xval() const {return x;}       // report x value
        double yval() const {return y;}       // report y value
        double magval() const;   // report magnitude
        double angval() const;   // report angle
        void polar_mode();                    // set mode to POL
        void rect_mode();                     // set mode to RECT
    // operator overloading
        Vector operator+(const Vector & b) const;
        Vector operator-(const Vector & b) const;
        Vector operator-() const;
        Vector operator*(double n) const;
    // friends
        friend Vector operator*(double n, const Vector & a);
        friend std::ostream & operator<<(std::ostream & os, const Vector & v);
    };

}   // end namespace VECTOR
// vect.cpp -- methods for the Vector class

namespace VECTOR
{
    using std::sqrt;
    using std::sin;
    using std::cos;
    using std::atan;
    using std::atan2;
    // compute degrees in one radian
    const double Rad_to_deg = 45.0 / atan(1.0);
    // should be about 57.2957795130823

    // private methods
    // calculates magnitude from x and y
    double Vector::magval() const {
        return  sqrt(x * x + y * y);
    }
    double Vector::angval() const {
        if (x == 0.0 && y== 0.0) {
            return 0.0;
        }
        return atan2(y, x);
    }
    // set x from polar coordinate
    void Vector::set_x()
    {
        x = magval() * cos(angval());
    }

    // set y from polar coordinate
    void Vector::set_y()
    {
        y = magval() * sin(angval());
    }
    void Vector::set_x(double t1, double t2)
    {
        x = t1 * cos(t2);
    }
    void Vector::set_y(double t1, double t2)
    {
        y =  t1 * sin(t2);
    }
    // public methods
    Vector::Vector()             // default constructor
    {
        x = y = 0.0;
        mode = RECT;
    }

    // construct vector from rectangular coordinates if form is r
    // (the default) or else from polar coordinates if form is p
    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if (mode == RECT) {
            x = n1;
            y = n2;
            return;
        }
        if (mode == POL) {
            n2 /= Rad_to_deg;
            set_x(n1, n2);
            set_y(n1, n2);
            return;
        }
        cout << "Incorrect 3rd argument to Vector() -- ";
        cout << "vector set to 0\n";
        x = y = 0.0;
        mode = RECT;
    }

    // reset vector from rectangular coordinates if form is
    // RECT (the default) or else from polar coordinates if
    // form is POL
    void Vector:: reset(double n1, double n2, Mode form)
    {
        mode = form;
        if (mode == RECT) {
            x = n1;
            y = n2;
            return;
        }
        if (mode == POL) {
            n2 /= Rad_to_deg;
            set_x(n1, n2);
            set_y(n1, n2);
            return;
        }
        cout << "Incorrect 3rd argument to Vector() -- ";
        cout << "vector set to 0\n";
        x = y = 0.0;
        mode = RECT;
    }

    Vector::~Vector()    // destructor
    {
    }

    void Vector::polar_mode()    // set to polar mode
    {
        mode = POL;
    }

    void Vector::rect_mode()     // set to rectangular mode
    {
        mode = RECT;
    }

    // operator overloading
    // add two Vectors
    Vector Vector::operator+(const Vector & b) const
    {
        return Vector(x + b.x, y + b.y);
    }

    // subtract Vector b from a
    Vector Vector::operator-(const Vector & b) const
    {
        return Vector(x - b.x, y - b.y);
    }

    // reverse sign of Vector
    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }

    // multiply vector by n
    Vector Vector::operator*(double n) const
    {
        return Vector(n * x, n * y);
    }

    // friend methods
    // multiply n by Vector a
    Vector operator*(double n, const Vector & a)
    {
        return a * n;
    }

    // display rectangular coordinates if mode is RECT,
    // else display polar coordinates if mode is POL
    std::ostream & operator<<(std::ostream & os, const Vector & v)
    {
        if (v.mode == Vector::RECT)
             os << "(x,y) = (" << v.x << ", " << v.y << ")";
        else if (v.mode == Vector::POL)
        {
             os << "(m,a) = (" << v.magval() << ", "
                 << v.angval() * Rad_to_deg << ")";
        }
        else
             os << "Vector object mode is invalid";
        return os;
    }

}

// end namespace VECTOR
int main()
{
    using VECTOR::Vector;
    srand(time(0));     // seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;

        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        cout << "After " << steps << " steps, the subject "
            "has the following location:\n";
        cout << result << endl;
        result.polar_mode();
        cout << " or\n" << result << endl;
        cout << "Average outward distance per step = "
            << result.magval()/steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    return 0;
}

