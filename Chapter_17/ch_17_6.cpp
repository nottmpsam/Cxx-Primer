#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <sstream>
class abstr_emp
{
    std::string fname;
    std::string lname;
    std::string job;
public:
    abstr_emp();
    abstr_emp(const std::string &fn, const std::string &ln, const std::string &jb);
    virtual void showAll(std::ostream& = std::cout) const;
    virtual void setAll();
    friend std::ostream & operator<<(std::ostream &os, const abstr_emp &t0);
    virtual ~abstr_emp() = 0;
    virtual void writeBinary(std::ofstream &) const;
    virtual void readBinary(std::ifstream &);
    enum classkind{Employee, Manager, Fink, Highfink};
};
void abstr_emp::readBinary(std::ifstream &in) 
{
    size_t size;

    in.read((char*)&size, sizeof(size));
    fname.resize(size);
    in.read((char*)&fname[0], size);

    in.read((char*)&size, sizeof(size));
    lname.resize(size);
    in.read((char*)&lname[0], size);

    in.read((char*)&size, sizeof(size));
    job.resize(size);
    in.read((char*)&job[0], size);
}
void abstr_emp::writeBinary(std::ofstream &os) const
{
    size_t size = fname.size();

    os.write((char*)&size, sizeof(size));
    os.write((char*)&fname[0], size);

    size = lname.size();
    os.write((char*)&size, sizeof(size));
    os.write((char*)&lname[0], size);

    size = job.size();
    os.write((char*)&size, sizeof(size));
    os.write((char*)&job[0], size);
}
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
void abstr_emp::showAll(std::ostream& os) const
{
    os << *this;
}
class employee: public abstr_emp
{
public:
    employee();
    employee(const std::string &fn, const std::string &ln, const std::string &jb);
    virtual void showAll(std::ostream&os = std::cout) const override { abstr_emp::showAll(os); }
    virtual void setAll() override { abstr_emp::setAll(); };
    virtual void writeBinary(std::ofstream& os) const override { 
        abstr_emp::writeBinary(os);
    }
    virtual void readBinary(std::ifstream&in) override {abstr_emp::readBinary(in);} 
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
    virtual void data(std::ostream& = std::cout) const;
    virtual void set();
public:
    manager();
    manager(const std::string &fn, const std::string &ln, const std::string &jb, int ico = 0);
    manager(const manager &m) : abstr_emp(m) { inchargeof = m.inchargeof; }
    virtual void showAll(std::ostream& = std::cout) const override;
    virtual void setAll() override;
    virtual void writeBinary(std::ofstream&) const override;
    virtual void readBinary(std::ifstream&in) override;//{abstr_emp::readBinary(in);} 
};
manager::manager()  : inchargeof(0) { }
manager::manager(const std::string &fn, const std::string &ln, const std::string &jb, int ico) 
    : abstr_emp(fn, ln, jb), inchargeof(ico) { }
void manager::readBinary(std::ifstream& in) 
{
    in.read((char*)&inchargeof, sizeof(inchargeof));
    abstr_emp::readBinary(in);
}
void manager::writeBinary(std::ofstream& os) const
{
    os.write((char*)&inchargeof, sizeof(inchargeof));
    abstr_emp::writeBinary(os);
}
void manager::set()
{
    std::cout << "Enter inchargeof: ";
    std::cin >> inchargeof;
    std::cin.ignore(1000, '\n');
}
void manager::setAll() 
{
    abstr_emp::setAll();
    set();
}
void manager::data(std::ostream& os) const 
{
    os << "inchargeof: " << inchargeof 
        << std::endl;
}
void manager::showAll(std::ostream& os) const
{
    abstr_emp::showAll(os);
    data(os);
}
class fink: virtual public abstr_emp
{
private:
    std::string reportsto;
protected:
    const std::string reportsTo() const { return reportsto; }
    std::string& reportsTo() { return reportsto; }
    virtual void data(std::ostream& = std::cout) const;
    virtual void set();
public:
    fink() { };
    fink(const std::string &fn, const std::string &ln, const std::string &j, const std::string &rpo)
        : abstr_emp(fn, ln, j), reportsto(rpo) { }
    fink(const fink &e) : abstr_emp(e) {
        reportsto = e.reportsto;
    }
    virtual void showAll(std::ostream& = std::cout) const override;
    virtual void setAll() override;
    virtual void writeBinary(std::ofstream&) const override;
    virtual void readBinary(std::ifstream&in) override;
};
void fink::readBinary(std::ifstream& in) 
{
    size_t size;
    in.read((char*)&size, sizeof(size));
    reportsto.resize(size);
    in.read((char*)&reportsto[0], size);
    abstr_emp::readBinary(in);
}
void fink::writeBinary(std::ofstream& os) const
{
    size_t size = reportsto.size();
    os.write((char*)&size, sizeof(size));
    os.write((char*)&reportsto[0], size);
    abstr_emp::writeBinary(os);
}
void fink::set()
{
    std::cout << "Whom do u want to report?: ";
    std::getline(std::cin, reportsto);
}
void fink::setAll() 
{
    abstr_emp::setAll();
    set();
}
void fink::data(std::ostream& os) const
{
    os << "Report to: " << reportsto << std::endl;
}
void fink::showAll(std::ostream& os) const
{
    abstr_emp::showAll(os);
    data(os);
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
    virtual void showAll(std::ostream& = std::cout) const override;
    virtual void setAll() override;
    virtual void writeBinary(std::ofstream&) const override;
    virtual void readBinary(std::ifstream&in) override;
};
void highfink::readBinary(std::ifstream& in)
{
    fink::readBinary(in);   
    manager::readBinary(in);
    abstr_emp::readBinary(in);
}
void highfink::writeBinary(std::ofstream& os) const
{
    fink::writeBinary(os);
    manager::writeBinary(os);
    abstr_emp::writeBinary(os);
}
void highfink::showAll(std::ostream& os) const
{
    abstr_emp::showAll(os);
    fink::data(os);
    manager::data(os);
}
void highfink::setAll() 
{
    abstr_emp::setAll();
    fink::set();
    manager::set();
}
void readFile(std::ifstream&fi)
{
    int temp;
    while (fi.read((char*)&temp, sizeof(temp))){
    abstr_emp*q;
    if (temp == abstr_emp::Employee) {
        q = new employee;
    } else if (temp == abstr_emp::Fink) {
        q = new fink;
    } else if (temp == abstr_emp::Manager){
        q = new manager;
    } else  {
        q = new highfink;
    }
    q->readBinary(fi);
    q->showAll();
    delete q;
    } 
}
int main(int argc, char* argv[])
{
    if (argc == 1) {
        std::cerr << "Error! Enter your file\n";
        exit(EXIT_FAILURE);
    }
    const std::string fileName = argv[1];
    std::ifstream fi(fileName, std::ios_base::in | std::ios_base::binary);
    if (fi.is_open()) {
        std::cout << "Here your data:\n";
        readFile(fi);
        fi.close();
    }
    std::ofstream fo(fileName, std::ios_base::out | std::ios_base::app |
            std::ios_base::binary);
    if (!fo.is_open()) {
        std::cerr << "File didn't open! File name: "
            << fileName << std::endl;
        exit(EXIT_FAILURE);
    }
    int Size = 10;
    abstr_emp* a[Size];
    std::cout << "Size: " << Size << std::endl;
    int i;
    int temp;
    for (i = 0; i < Size; ++i) {
        L:
        std::cout << "Entered: " << i;
        std::cout << "\ne - employee\t"<<"m - manager"
            <<  "\nf - fink\t" << "h - highfink\n";
        std::cout << "q - to quit\t";
        char ch = std::cin.get();
        std::cin.ignore(1000, '\n');
        ch = tolower(ch);
        if (strchr("emfhq", ch) == nullptr) {
            goto L;
        }
        if (ch == 'q') {
            break;
        }
        switch (ch) {
            case 'e': 
                a[i] = new employee;
                temp = abstr_emp::Employee;
                break;
            case 'm':
                a[i] = new manager;
                temp = abstr_emp::Manager;
                break;
            case 'f':
                a[i] = new fink;
                temp = abstr_emp::Fink;
                break;
            case 'h':
                a[i] = new highfink;
                temp = abstr_emp::Highfink;
        }
        a[i]->setAll();
        a[i]->showAll();
        fo.write((char*) &temp, sizeof(temp));
        a[i]->writeBinary(fo);
    }
    fo.close();
    fi.open(fileName);
    std::cout << "\nNow:\n";
    readFile(fi);
    std::cout << "Bye!\n";
    for (int j = 0; j < i; ++j) {
        delete a[j];
    }
    fi.close();
    return 0;
    /*
    if (argc == 1) {
        std::cerr << "Error! Enter your file\n";
        exit(EXIT_FAILURE);
    }
    const std::string fileName = argv[1];
    std::ifstream fi(fileName, std::ios_base::in);
    if (fi.is_open()) 
    {
        std::cout << "Here your data:\n";
        char ch;
        while (fi.get(ch)) {
            std::cout << ch;
        }
        fi.close();
    }
    std::ofstream fo(fileName, std::ios_base::out | std::ios_base::app);
    if (!fo.is_open()) {
        std::cerr << "File didn't open! File name: "
            << fileName << std::endl;
        exit(EXIT_FAILURE);
    }
    
    int Size = 10;
    abstr_emp* a[Size];
    std::cout << "Size: " << Size << std::endl;
    int i;
    for (i = 0; i < Size; ++i) {
        L:
        std::cout << "e - employee\t"<<"m - manager"
            <<  "\nf - fink\t" << "h - highfink\n";
        std::cout << "q - to quit\t";
        char ch = std::cin.get();
        std::cin.ignore(1000, '\n');
        ch = tolower(ch);
        if (strchr("emfhq", ch) == nullptr) {
            goto L;
        }
        if (ch == 'q') {
            break;
        }
        switch (ch) {
            case 'e': 
                a[i] = new employee;
                break;
            case 'm':
                a[i] = new manager;
                break;
            case 'f':
                a[i] = new fink;
                break;
            case 'h':
                a[i] = new highfink;
        }
        a[i]->setAll();
        a[i]->showAll();
        a[i]->showAll(fo);
    }
    fo.close();
    fi.open(fileName);
    std::cout << "And now we have:\n";
    char ch;
    while (fi.get(ch)) {
        std::cout << ch;
    }
    std::cout << "Bye!\n";
    for (int j = 0; j < i; ++j) {
        delete a[j];
    }
    fi.close();
    return 0;*/
}
