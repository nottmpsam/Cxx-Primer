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
    bool operator==(const Stonewt &t1) const;
    bool operator!=(const Stonewt &t1) const;
    bool operator<(const Stonewt &t1) const;
    bool operator>(const Stonewt &t1) const;
    bool operator<=(const Stonewt &t1) const;
    bool operator>=(const Stonewt &t1) const;
};
bool Stonewt::operator==(const Stonewt &t1) const
{
    return (pounds == t1.pounds);
}
bool Stonewt::operator!=(const Stonewt &t1) const
{
    return (pounds != t1.pounds);
}
bool Stonewt::operator<(const Stonewt &t1) const
{
    return (pounds < t1.pounds);
}
bool Stonewt::operator>(const Stonewt &t1) const
{
    return (pounds > t1.pounds);
}
bool Stonewt::operator<=(const Stonewt &t1) const
{
    return (pounds < t1.pounds || pounds == t1.pounds);
}
bool Stonewt::operator>=(const Stonewt &t1) const
{
    return (pounds > t1.pounds || pounds == t1.pounds);
}
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
    const int n = 6;
    Stonewt a[n] = { {13, 2.4}, {23.2}, {8, 4.5} };
    for (int i = 3; i < n; ++i) {
        double temp;
        std::cin >> temp;
        a[i] = Stonewt(temp);
    }
    a[0].poundMode();
    a[2].poundMode();
    std::cout << "***"<<std::endl;
    for (int i = 0; i < n; ++i) 
        std::cout << a[i] << std::endl;
    std::cout << "***"<<std::endl;
    Stonewt minPound(a[0]);
    Stonewt maxPound(a[0]);
    for (int i = 1; i < n; ++i) {
        if (maxPound < a[i]) {
            maxPound = a[i];
        }
        if (minPound > a[i]) {
            minPound = a[i];
        }
    }
    std::cout << "Min: " << minPound << std::endl
        << "Max: " << maxPound << std::endl;
    std::cout << "~~~" << std::endl;
    for (int i = 0; i < n; ++i) {
        a[i].stoneMode();
        std::cout << a[i] << std::endl;
    }
    std::cout << "~~~" << std::endl;
    minPound.stoneMode();
    maxPound.stoneMode();
    std::cout << "Min: " << minPound << std::endl
    << "Max: " << maxPound << std::endl;
return 0;
}



