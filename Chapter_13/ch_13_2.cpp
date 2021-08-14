#include <iostream>
#include <cstring>

class Cd
{
public:
private:
    char* performers;
    char* label;
    int selections; 
    double playtime;
public:
    Cd(const char* st, const char* s2, int n, double x);
    Cd(const Cd& d);
    Cd();
    virtual ~Cd();
    virtual void Report() const;
    Cd& operator=(const Cd& d);
};
Cd& Cd::operator=(const Cd& d)
{
    if (this != &d)
    {
        delete [] label;
        delete [] performers;

        int length = strlen(d.performers);
        performers = new char[length + 1];
        strcpy(performers, d.performers);

        length = strlen(d.label);
        label = new char[length + 1];
        strcpy(label, d.label);

        selections = d.selections;
        playtime = d.playtime;
    }
    return *this;
}
Cd::Cd(const Cd& d) 
{
    int length = strlen(d.performers);
    performers = new char[length + 1];
    strcpy(performers, d.performers);

    length = strlen(d.label);
    label = new char[length + 1];
    strcpy(label, d.label);

    selections = d.selections;
    playtime = d.playtime;
}
void Cd::Report() const
{
    std::cout << "Performers: "
        << performers << std::endl
        << "Label: "
        << label << std::endl
        << "Selections: " 
        << selections << std::endl
        << "Playing time: "
        << playtime << std::endl;
}
Cd::~Cd()
{
    delete [] performers;
    delete [] label;
}
Cd::Cd()
{

    performers = nullptr;
    label = nullptr;
    selections = 0;
    playtime = 0.0;
}
Cd::Cd(const char* s1, const char* s2, int n, double x) : selections(n), playtime(x) //только ради забавы
{
    int length = strlen(s1);
    performers = new char[length + 1];
    strcpy(performers, s1);
    length = strlen(s2);
    label = new char[length + 1];
    strcpy(label, s2);
}

class Classic : public Cd
{
private:
    char* favourite;
public:
    Classic(const char* _fv = "Null", const char* s1 = "Null", const char* s2 = "Null", int n = 0, double x = 0.0);
    ~Classic();
    virtual void Report() const override;
    Classic(const Classic& t0);
    Classic& operator=(const Classic& t0);
};
Classic& Classic::operator=(const Classic& t0)
{
    if (this != &t0) {
        delete [] favourite;
        favourite = new char[strlen(favourite) + 1];
        strcpy(favourite, t0.favourite);
        Cd::operator=(t0);
    }
    return *this;
}
Classic::Classic(const Classic& t0) : Cd(t0)
    //работает конструктор копирования по умолчанию для базового класса
{
    favourite = new char[strlen(t0.favourite) + 1];
    strcpy(favourite, t0.favourite);
}
void Classic::Report() const
{
    std::cout << "Favourite: " << favourite << std::endl;
    Cd::Report();
}
Classic::Classic(const char* _fv, const char* s1, const char* s2, int n, double x) : Cd(s1, s2, n, x)
{
    favourite = new char[strlen(_fv) + 1];
    strcpy(favourite, _fv);
}

Classic::~Classic()
{
    delete [] favourite;
}
void Bravo(const Cd& disk)
{
    disk.Report();
}
int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
            "Alfred Brendel", "Philips", 2, 57.17);
    Cd* pcd = &c1;
    std::cout << "Using object directly:\n";
    c1.Report();
    c2.Report();
    std::cout << "Using type cd* pointer to objects:\n";
    pcd->Report();
    pcd = &c2;
    pcd->Report();
    std::cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    std::cout << "Testing assignment #1: \n";
    Classic copy = c2;
    copy.Report();
    std::cout << "Testing assignment #2: \n";
    Classic copyy;
    copyy = c2;
    copyy.Report();
}
