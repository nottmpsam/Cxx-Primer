#include <iostream>
#include <cstring>
#include <ostream>
class Cow
{
    static int countCow;
    enum {Range = 20};
    char name[Range];
    char *hobby;
    double weight;
public:
    Cow();
    Cow(const char *_name, const char *_hobby, double _wt);
    Cow(const Cow &t1);
    ~Cow();
    Cow& operator=(const Cow &t1);
    void ShowCow() const;
};
void Cow::ShowCow() const
{
    std::cout << "Name: " << name
        << std::endl
        << "Hobby: " << hobby 
        << std::endl
        << "Weight: " << weight
        << std::endl;
}

Cow& Cow::operator=(const Cow &t1)
{
    std::cout << __PRETTY_FUNCTION__ << " countCow : " <<  countCow << std::endl;
    if (this == &t1) {
        delete [] hobby;
        hobby = new char[strlen(t1.hobby) + 1];
        weight = t1.weight;
        strncpy(name, t1.name, Range);
        strncpy(hobby, t1.hobby, Range);
    }

    return *this;
}

Cow::Cow(const Cow &t1)
{
    ++countCow;
    std::cout << __PRETTY_FUNCTION__ << " countCow : " <<  countCow << std::endl;
    strncpy(name, t1.name, Range);
    hobby = new char[strlen(t1.hobby) + 1];
    strncpy(hobby, t1.hobby, Range);
    weight = t1.weight;
}

Cow::~Cow()
{
    --countCow;
    std::cout << __PRETTY_FUNCTION__ << " countCow : " <<  countCow << std::endl;
    delete [] hobby;
}

Cow::Cow(const char* _name, const char*_hobby, double _weight)
{
    ++countCow;
    std::cout << __PRETTY_FUNCTION__ << " countCow : " <<  countCow << std::endl;
    strncpy(name, _name, Range);
    hobby = new char[strlen(_hobby) + 1];
    strncpy(hobby, _hobby, Range);
    weight = _weight;
}
Cow::Cow()
{
    ++countCow;
    std::cout << __PRETTY_FUNCTION__ << " countCow : " <<  countCow << std::endl;
    name[0] = '\0';
    hobby = nullptr;
    weight =  0.0;
}
int Cow::countCow = 0;
int main()
{
    {
        Cow first("CowFirst", "Reading", 21.2);
        Cow second = first;
        std::cout << "***" << std::endl;
        first.ShowCow();
        std::cout << "***" <<  std::endl;
        second.ShowCow();
        first = second;
        std::cout << "***" << std::endl;
        Cow third;
        third = Cow("CowThird", "Watching-Tv", 32.3); //temporary object
    }
    return 0;
}
