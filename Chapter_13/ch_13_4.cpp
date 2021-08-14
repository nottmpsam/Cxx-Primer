#include <iostream>
#include <cstring>

class Port
{
private:
    enum {LEN  = 20 };
    char* brand; 
    char style[LEN];
    int bottles;
public:
    Port(const char* br = "none", const char* st = "none", int b = 0);
    Port(const Port& p);
    virtual ~Port();
    Port& operator=(const Port& p);
    Port& operator+=(int b);
    Port& operator-=(int b);
    int bottleCount() const { return bottles; }
    virtual void Show() const;
    friend std::ostream& operator<<(std::ostream& os, const Port& p);
};

Port& Port::operator-=(int b)
{
    if (bottles - b >= 0) {
        bottles -= b;
    }
    return *this;
}

Port& Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

Port& Port::operator=(const Port& p)
{
    if (this != &p) {
        bottles = p.bottles;

        strncpy(style, p.style, LEN - 1);
        style[LEN - 1] = '\0';

        delete [] brand;
        brand = new char[strlen(p.brand) + 1];
        strcpy(brand, p.brand);
    }
    return *this;
}

Port::~Port()
{
    delete [] brand;
}

Port::Port(const Port& p)
{
    bottles = p.bottles;

    strncpy(style, p.style, LEN - 1);
    style[LEN - 1] = '\0';

    delete [] brand;
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
}

Port::Port(const char* br, const char* st, int b)
{
    bottles = 0;

    strncpy(style, st, LEN - 1);
    style[LEN - 1] = '\0';

    brand = new char[strlen(br) + 1];
    strcpy(brand, br);
}

std::ostream& operator<<(std::ostream& os, const Port& p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}

void Port::Show() const 
{
    std::cout << "Brand: " << brand << std::endl
        << "Kind: " << style << std::endl
        << "Bottles: " << bottles << std::endl;
}

class VintagePort : public Port
{
private:
    char* nickname;
    int year;
public:
    VintagePort();
    VintagePort(const char* br, int b, const char* nn, int y);
    VintagePort(const VintagePort& vp);
    ~VintagePort();
    VintagePort& operator=(const VintagePort& vp);
    void show() const;
    friend std::ostream& operator<<(std::ostream& os, const VintagePort& vp);
};

VintagePort& VintagePort::operator=(const VintagePort& vp)
{
    if (this != &vp)
    {
        delete [] nickname;
        nickname = new char[strlen(vp.nickname) + 1];
        strcpy(nickname, vp.nickname);
        Port::operator=(vp);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const VintagePort& vp)
{
    os << (Port&) vp << ", " << vp.nickname << ", " << vp.year;
    return os;
}

void VintagePort::show() const
{
    Port::Show();
    std::cout << "Nickname: " << nickname
        << "Year: " << year << std::endl;
}

VintagePort::~VintagePort()
{
    delete [] nickname;
}

VintagePort::VintagePort(const char* br, int b, const char* nn, int y) : Port(br,"none", b)
{
    nickname = new char[strlen(nn) + 1];
    strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort() : Port()
                             //можно опустить
{
    nickname = nullptr;
    year = 0;
}

int main()
{

    return 0;
}
