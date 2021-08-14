#include <iostream>
#include <cstring>
#include <ostream>


class baseDMA
{
private:
    char* label;
    double rating;
public:
    baseDMA(const baseDMA& t1);
    baseDMA& operator=(const baseDMA& t1);
    baseDMA(const char* _label = "blank", int _rating = 0.0);
    virtual void viewDMA() const;
    friend std::ostream& operator<<(std::ostream& os, const baseDMA& t0);
    virtual void setValues() = 0;
    ~baseDMA();
};

void baseDMA::viewDMA() const
{
    std::cout << "Label: " << label << std::endl
        << "Rating: " << rating << std::endl;
}
std::ostream& operator<<(std::ostream& os, const baseDMA& t0)
{
    os << "Label: " << t0.label << std::endl
        << "Rating: " << t0.rating << std::endl;
    return os;
}
void baseDMA::setValues()
{
    delete [] label;
    std::cout << "Enter label: ";
    std::string str;
    std::getline(std::cin, str);
    label = new char[str.length() + 1];
    strcpy(label, str.c_str());

    std::cout << "Enter rating: ";
    while (!(std::cin >> rating)) {
        std::cin.clear();
        while (std::cin.get() != '\n') {
            continue;
        }
    }
    while (std::cin.get() != '\n')
        continue;
}
baseDMA& baseDMA::operator=(const baseDMA& t1)
{
    if (this != &t1) {
        delete [] label;
        label = new char[strlen(t1.label) + 1];
        strcpy(label, t1.label);
        rating = t1.rating;
    }
    return *this;
}
baseDMA::baseDMA(const baseDMA& t1)
{
    label = new char[strlen(t1.label) + 1];
    strcpy(label, t1.label);
    rating = t1.rating;
}
baseDMA::baseDMA(const char* _label, int _rating)
{
    label = new char[strlen(_label) + 1];
    strcpy(label, _label);
    rating = _rating;
}
baseDMA::~baseDMA()
{
    delete [] label;
}
class lacksDMA : public baseDMA
{
private:
    char* color;
public:
    lacksDMA(const char* _label = "blank", int _rating = 0.0, const char* _color = "null");
    ~lacksDMA();
    virtual void setValues() override;
    virtual void viewDMA() const override;
    lacksDMA(const lacksDMA& t0);
    lacksDMA& operator=(const lacksDMA& t0);
    friend std::ostream& operator<<(std::ostream& os, const lacksDMA& t0);
};
void lacksDMA::viewDMA() const
{
    baseDMA::viewDMA();
    std::cout << "Color: " << color << std::endl;
}
std::ostream& operator<<(std::ostream& os, const lacksDMA& t0)
{
    os << (baseDMA&) t0;
    os << "Color: " << t0.color;
    return os;
}
lacksDMA& lacksDMA::operator=(const lacksDMA& t0)
{
    if (this != &t0) {
        delete [] color;
        baseDMA::operator=(t0);
        color = new char[strlen(t0.color) + 1];
        strcpy(color, t0.color);
    }
    return *this;
}
lacksDMA::lacksDMA(const lacksDMA& t0) : baseDMA(t0)
{
    delete [] color;
    color = new char[strlen(t0.color) + 1];
    strcpy(color, t0.color);
}
void lacksDMA::setValues()
{
    baseDMA::setValues();
    std::string str;
    std::cout << "Enter color: ";
    std::getline(std::cin, str);
    color = new char[str.length() + 1];
    strcpy(color, str.c_str());
}
lacksDMA::lacksDMA(const char* _label, int _rating, const char* _color) : baseDMA(_label, _rating)
{
    color = new char[strlen(_color) + 1];
    strcpy(color, _color);
}
lacksDMA::~lacksDMA()
{
    delete [] color;   
}

class statDMA : public baseDMA
{
private:
    enum { STYLE_LEN = 30 };
    char style[STYLE_LEN];
public:
    statDMA(const char* _label = "bland", int _rating = 0.0, const char* _style = "null");
    friend std::ostream& operator<<(std::ostream& os, const statDMA& t0);
    virtual void setValues() override;
    virtual void viewDMA() const override;
    ~statDMA();
};
statDMA::statDMA(const char* _label, int _rating, const char* _style) : baseDMA(_label, _rating)
{
    strncpy(style, _style, STYLE_LEN);
}
std::ostream& operator<<(std::ostream& os, const statDMA& t0)
{
    os << (baseDMA&) t0;
    os << "Style: " << t0.style << std::endl;
    return os;
}
void statDMA::setValues()
{
    baseDMA::setValues();
    std::string str;
    std::cout << "Enter style: ";
    std::getline(std::cin, str);
    strncpy(style, str.c_str(), STYLE_LEN);
}
void statDMA::viewDMA() const
{
    baseDMA::viewDMA();
    std::cout << "Style: " << style << std::endl;
}
int main()
{
    const int n = 2;
    baseDMA* p[n];
    char kind;
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter either 1 or 2: ";
        while (std::cin >> kind && (kind != '1' && kind != '2')) {
            std::cout << "Enter either 1 or 2: ";
        }
        std::cin.get();
        if (kind == '1') { 
            p[i] = new lacksDMA;
            p[i]->setValues();
        } else {
            std::string label;
            std::cout << "Enter label: ";
            std::getline(std::cin, label);
            std::cout << "Enter rating: ";
            int rating;
            while (!(std::cin >> rating)) {
                std::cin.clear();
                while (std::cin.get() != '\n')
                    continue;
                std::cout << "Enter rating again: ";
            }
            std::cout <<"Enter style: ";
            std::cin.get();
            std::string style;
            std::getline(std::cin, style);
            p[i] = new statDMA(label.c_str(), rating, style.c_str());
        }
    }
    for (int i = 0; i < n; ++i) {
        p[i]->viewDMA();
    }
    lacksDMA qwerty;
    qwerty.setValues();
    std::cout << qwerty << std::endl;
    lacksDMA q;
    q = qwerty;
    std::cout << q << std::endl;
}
