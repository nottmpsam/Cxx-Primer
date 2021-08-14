#include <iostream>
#include <cstring>
class Plorg
{
    enum {LEN = 19};
    char name[LEN];
    int CI;
public:
    void showPlorg() const;
    Plorg(const char *_name = "Plorga", int _CI = 50);
    void reCI(int _CI);
};
Plorg::Plorg(const char *_name, int _CI)
{
    CI = _CI;
    strncpy(name, _name, LEN-1);
    name[LEN-1] = '\0';
    if (strlen(_name) > LEN)
        std::cerr << __PRETTY_FUNCTION__ << " Overflow: strncpy(...)"
            << std::endl;
}
void Plorg::reCI(int _CI)
{
    CI = _CI;
}
void Plorg::showPlorg() const
{
    std::cout << "Name: " << name 
        << " | Contentment index: " 
        << CI << std::endl;
}
int main()
{
    Plorg a;
    a.showPlorg();
    a = Plorg("Star", 100);
    a.showPlorg();
    a.reCI(99);
    a.showPlorg();
    return 0;
}
