#include <iostream>
#include <cstring>
class abstr_emp
{
    std::string fname;
    std::string lname;
    std::string job;
public:
    abstr_emp();
    abstr_emp(const std::string &fn, const std::string &ln, const std::string &jb);
    virtual void showAll() const;
    virtual void setAll();
    friend std::ostream & operator<<(std::ostream &os, const abstr_emp &t0);
    virtual ~abstr_emp() = 0;
};
abstr_emp::abstr_emp() 
{ }
abstr_emp::abstr_emp(const std::string &fn, const std::string &ln, const std::string &jb) : fname(fn), lname(ln), job(jb)
{ }
abstr_emp::~abstr_emp()
{ }
std::ostream & operator<<(std::ostream &os, const abstr_emp &t0)
{
    os << t0.fname
        << " " << t0.lname << std::endl
        << "Job: " << t0.job << std::endl;
    return os;
}
void abstr_emp::setAll()
{
    std::cout << "Enter first name: ";
    std::getline(std::cin, fname);
    std::cout << "Enter last name: ";
    std::getline(std::cin, lname);
    std::cout << "Enter job: ";
    std::getline(std::cin, job);
}
void abstr_emp::showAll() const
{
    std::cout << *this;
}
class employee: public abstr_emp
{
public:
    employee();
    employee(const std::string &fn, const std::string &ln, const std::string &jb);
    virtual void showAll() const override { abstr_emp::showAll(); }
    virtual void setAll() override { abstr_emp::setAll(); };
};
employee::employee() : abstr_emp()
                       //по умолчанию вызывается итак
{ }
employee::employee(const std::string &fn, const std::string &ln, const std::string &jb) : abstr_emp(fn, ln, jb)
{ }
class manager: virtual public abstr_emp
{
    int inchargeof;
protected:
    int inChargeOf() const { return inchargeof; }
    int& inChargeOf() { return inchargeof; }
    virtual void data() const;
    virtual void set();
public:
    manager();
    manager(const std::string &fn, const std::string &ln, const std::string &jb, int ico = 0);
    manager(const manager &m) : abstr_emp(m) { inchargeof = m.inchargeof; }
    virtual void showAll() const override;
    virtual void setAll() override;
};
manager::manager()  : inchargeof(0) { }
manager::manager(const std::string &fn, const std::string &ln, const std::string &jb, int ico) 
    : abstr_emp(fn, ln, jb), inchargeof(ico) { }
void manager::set()
{
    std::cout << "Enter inchargeof: ";
    std::cin >> inchargeof;
}
void manager::setAll() 
{
    abstr_emp::setAll();
    set();
}
void manager::data() const 
{
    std::cout << "inchargeof: " << inchargeof 
        << std::endl;
}
void manager::showAll() const
{
    abstr_emp::showAll();
    data();
}
class fink: virtual public abstr_emp
{
private:
    std::string reportsto;
protected:
    const std::string reportsTo() const { return reportsto; }
    std::string& reportsTo() { return reportsto; }
    virtual void data() const;
    virtual void set();
public:
    fink() { };
    fink(const std::string &fn, const std::string &ln, const std::string &j, const std::string &rpo)
        : abstr_emp(fn, ln, j), reportsto(rpo) { }
    fink(const fink &e) : abstr_emp(e) {
        reportsto = e.reportsto;
    }
    virtual void showAll() const override;
    virtual void setAll() override;
};
void fink::set()
{
    std::cout << "Whom do u want to report? : ";
    std::getline(std::cin, reportsto);
}
void fink::setAll() 
{
    abstr_emp::setAll();
    set();
}
void fink::data() const
{
    std::cout << "Report to: " << reportsto << std::endl;
}
void fink::showAll() const
{
    abstr_emp::showAll();
    data();
}
class highfink: public manager, public fink
{
public:
    highfink() { }
    highfink(const std::string &fn, const std::string &ln, const std::string &j, const std::string &rpo, int ico)
        : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) { }
    highfink(const fink &f, int ico) : abstr_emp(f), fink(f) { inChargeOf() = ico; }
    highfink(const manager &m , const std::string &rpo) : abstr_emp(m), manager(m)  {  reportsTo() = rpo;  }
    highfink(const highfink &h) : abstr_emp(h), manager(h), fink(h)  { }
    virtual void showAll() const;
    virtual void setAll();
};
void highfink::showAll() const
{
    abstr_emp::showAll();
    fink::data();
    manager::data();
}
void highfink::setAll() 
{
    abstr_emp::setAll();
    fink::set();
    manager::set();
}
int main()
{
    employee em("Trip", "Hummer", "Thumper");
    std::cout << em;
    em.showAll();

    std::cout << "*****" << std::endl;
    manager ma ("Amorphia", "Spindragon", "Nuancer", 5);
    std::cout << ma << std::endl;
    ma.showAll();

    std::cout << "*****" << std::endl;
    fink fi ("Matt", "Oggs", "Oiler", "Juno barr");
    std::cout << fi << std::endl;
    fi.showAll();

    std::cout << "*****" << std::endl;
    highfink hf(ma, "Curly Kew");
    hf.showAll();

    std::cout << "*****" << std::endl;
    highfink lol = hf;
    lol.showAll();
    std::cout << "*****" << std::endl;

    std::cout << "Press a key for next  phase:\n";

    std::cin.get();
    highfink hf2;
    hf2.setAll();

    std::cout << "Using an abstr_emp* pointer:\n";
    abstr_emp* tri[4] = {&em, &fi, &hf, &hf2};
    for (int i = 0; i < 4; ++i) {
        tri[i]->showAll();
    }
    return 0;
}
