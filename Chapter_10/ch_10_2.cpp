#include <iostream>
#include <string>
#include <cstring>
class Person
{
    enum {LIMIT = 25}; 
    std::string lname;
    char fname[LIMIT];

public:
    Person() { lname = ""; fname[0] = '\0'; }
    Person(const std::string & _lname, const char *fn = "Heyyou<3");
    void Show() const; //name surname
    void FormalShow() const; //surname name
};
void Person::Show() const 
{
    std::cout << "First name: " << fname  << " "
        << "Last name: " << lname
        << std::endl;
}
void Person::FormalShow() const 
{
    std::cout << "Last name: " << lname << " "
        << "First name: " << fname 
        << std::endl;
}
Person::Person(const std::string & _lname, const char *fn) 
{
    lname = _lname;
    strncpy(fname, fn, LIMIT - 1); 
    fname[LIMIT-1] = '\0';
    if (strlen(fn) >= LIMIT) { 
        std::cerr << __PRETTY_FUNCTION__ << " (Overflow: strncpy(...))" << std::endl;
    }
}
int main()
{
    /*
    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");
    one.Show();
    one.FormalShow();
    std::cout << "********" << std::endl;
    two.Show();
    two.FormalShow();
    std::cout << "********" << std::endl;
    three.Show();
    three.FormalShow();
    std::cout << "********" << std::endl;
    */
    Person one ("11", "22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222");
    return 0;
}
