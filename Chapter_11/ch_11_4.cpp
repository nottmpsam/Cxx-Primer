#include <iostream>
class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    friend std::ostream & operator<<(std::ostream & os, const Time & t);
    friend Time operator+(const Time &t0, const Time &t1);
    friend Time operator-(const Time &t0,const Time &t1);
    friend Time operator*(const Time &t0, double m);
    friend Time operator*(double m, const Time &t0) { return t0 * m; }
};

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m )
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time operator+(const Time &t0, const Time &t1)
{
    return Time (t0.hours + t1.hours + (t0.minutes + t0.minutes) / 60,
            (t1.minutes + t0.minutes)%60);
}

Time operator-(const Time &t0, const Time &t1)
{
    int time1 = t1.minutes + 60 * t1.hours;
    int time0 = t0.minutes + 60 * t0.hours;
    time1 = time0-time1;
    return Time(time1/60, time1%60);
}

Time operator*(const Time &t0, double mult)
{
    long totalminutes = t0.hours * mult * 60 + t0.minutes * mult;
    return Time(totalminutes / 60, totalminutes % 60);
}

std::ostream & operator<<(std::ostream & os, const Time & t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}

int main()
{
    using std::cout;
    using std::endl;
    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;

    cout << "Aida and Tosca:\n";
    cout << aida<<"; " << tosca << endl;
    temp = aida + tosca;     // operator+()
    cout << "Aida + Tosca: " << temp << endl;
    temp = aida* 1.17;  // member operator*()
    cout << "Aida * 1.17: " << temp << endl;
    cout << "10.0 * Tosca: " << 10.0 * tosca << endl;
	// std::cin.get();
    return 0; 
}

