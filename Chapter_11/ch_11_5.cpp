#include <iostream>
class Stonewt
{
public:
    enum Mode {STONE, POUND};
private:
    Mode mode;
    enum {Lbs_per_stn = 14};      // pounds per stone
    //1 stn = 14 lbs
    int stone;                    // whole stones
    double pds_left;              // fractional pounds
    double pounds;                // entire weight in pounds
public:
    Stonewt(double lbs, Mode = POUND);          // constructor for double pounds
    Stonewt(int stn, double lbs, Mode = STONE); // constructor for stone, lbs
    Stonewt();                    // default constructor
    ~Stonewt();
    void stoneMode() {mode = STONE;}
    void poundMode() {mode = POUND;}

    friend Stonewt operator*(const Stonewt &t0, const Stonewt &t1);

    Stonewt operator+(const Stonewt &t1) const;
 //   friend Stonewt operator+(double t2, const Stonewt &t1);

    friend Stonewt operator-(const Stonewt &t0, const Stonewt &t1);

    friend std::ostream& operator<<(std::ostream &os, Stonewt &t0);
};
Stonewt operator*(const Stonewt &t0, const Stonewt &t1)
{
    return Stonewt(t0.pounds * t1.pounds);
}
Stonewt operator+(double t2, const Stonewt &t1)
{
    return t1+t2;
}
Stonewt Stonewt::operator+(const Stonewt &t1) const
{
    return Stonewt(pounds + t1.pounds);
}
Stonewt operator-(const Stonewt &t0, const Stonewt &t1)
{
    return Stonewt(t0.pounds-t1.pounds);
}
std::ostream& operator<<(std::ostream &os, Stonewt &t0)
{
    if (Stonewt::STONE == t0.mode) {
        os << t0.stone << " stone, " << t0.pds_left << " pounds";
    } else if (Stonewt::POUND == t0.mode) {
        os <<  t0.pounds << " pounds";
    } else {
        os << "Mode is not valid. " << __PRETTY_FUNCTION__ 
            << std::endl;
    }
    return os;
}
// construct Stonewt object from double value
Stonewt::Stonewt(double lbs, Mode _mode)
{
    if (_mode != STONE && _mode != POUND) 
        _mode = STONE;
    mode = _mode;
    stone = int (lbs) / Lbs_per_stn;    // integer division
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs, Mode _mode)
{
    if (_mode != STONE && _mode != POUND) 
        _mode = STONE;
    mode = _mode;
    stone = stn;
    pds_left = lbs;
    pounds =  stn * Lbs_per_stn + lbs;
}

Stonewt::Stonewt()          // default constructor, wt = 0
{
    stone = pounds = pds_left = 0;
    mode = STONE;
}

Stonewt::~Stonewt()         // destructor
{
}

int main()
{
    Stonewt first = 259.3;
    std::cout << first << std::endl;
    Stonewt second(13,32.3);
    std::cout << second << std::endl;
    Stonewt plus = first + second;
    std::cout <<"+: " << plus << std::endl;
    plus = plus + 132.32;
    std::cout << "+: ...(132.32) = " << plus << std::endl;
    plus = 194.08 + plus;
    std::cout << "+: (194.08)... = " << plus << std::endl;
    plus = plus - 400.0;
    std::cout << "-: ...(400.0) = " << plus << std::endl;
    plus = 500.0 - plus;
    std::cout << "-: (500.0)... = " << plus << std::endl;
    plus = plus * 3.5;
    plus.stoneMode();
    std::cout << "Switched to Stone mode...\n*: ...(3.5) = "
        << plus << std::endl;
    std::cout << "Done!\n";
    // std::cin.get();
    return 0;
}


