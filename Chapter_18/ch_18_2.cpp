#include <iostream>

class Cpmv
{
public:
    struct Info
    {
        std::string qcode;
        std::string zcode;
    };
    static int nObjects;
private:
    Info* pi;
public:
    Cpmv();
    Cpmv(std::string q, std::string z);
    Cpmv(const Cpmv& cp);
    Cpmv(Cpmv&& mv);
    ~Cpmv();
    Cpmv& operator=(const Cpmv& cp);
    Cpmv& operator=(Cpmv&& cp);
    Cpmv operator+(const Cpmv& obj) const;
    void displayCpmv() const;
    void showData() const { std::cout << "Address:\t"<< (void*) pi << std::endl; }
};
//в моем случае, gcc компилятор оптимизирует метод + тем, что для lvalue значения, он не создает
// временный объект при возвращении return, (то есть, он сразу его переносит O.o)
Cpmv::Cpmv(Cpmv&&cp)
{
    //wtfxd
    std::cout << "~~~~~~~~~~~~~~~" << std::endl;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    showData();
    std::cout << "Address from:\t" << (void*) cp.pi << std::endl;
    std::cout << "~~~~~~~~~~~~~~~" << std::endl;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
    cp.pi = nullptr;
}

Cpmv& Cpmv::operator=(Cpmv&& cp)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    showData();
    std::cout << "Address from:\t" << (void*) cp.pi << std::endl;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
    cp.pi = nullptr;
    return *this;
}
int Cpmv::nObjects = 0;
void Cpmv::displayCpmv() const
{
    std::cout << "******************************************" << std::endl;
    std::cout
        << "Qcode: \t" << pi->qcode
        << std::endl
        << "Zcode: \t" << pi->zcode
        << std::endl;
    showData();
    std::cout << "*******************************************" << std::endl;
}
Cpmv Cpmv::operator+(const Cpmv& obj) const
{
    std::cout << "***********************" << std::endl;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    Cpmv x(pi->qcode + obj.pi->qcode, 
                    pi->zcode + obj.pi->zcode);
    std::cout << "temp:\t";
    std::cout << "Adress:\t" << (void*)x.pi << std::endl;
    std::cout << "***********************" << std::endl;
    //return Cpmv(pi->qcode + obj.pi->qcode, pi->zcode + obj.pi->zcode);
    return x;
}
Cpmv& Cpmv::operator=(const Cpmv& cp)
{
    std::cout << "***********" << std::endl;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    showData();
    std::cout << "From address:\t" << (void*)cp.pi<<std::endl;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
    std::cout << "***********************" << std::endl;
    return *this;
}
Cpmv::Cpmv() : pi(nullptr)
{
    std::cout << "************************" << std::endl;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    showData();
    ++nObjects;
    std::cout << "nObj:\t" << nObjects << std::endl;
    std::cout << "************************" << std::endl;
}
Cpmv::Cpmv(std::string q, std::string z) 
{
    ++nObjects;
    std::cout << "************************" << std::endl;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    pi = new Info;
    showData();
    std::cout << "nObj:\t" << nObjects << std::endl;
    pi->qcode = q;
    pi->zcode = z;
    std::cout << "************************" << std::endl;
}
Cpmv::Cpmv(const Cpmv& cp)
{
    ++nObjects;
    std::cout << "************************" << std::endl;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    pi = new Info;
    showData();
    std::cout << "nObj:\t" << nObjects << std::endl;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
    std::cout << "************************" << std::endl;
}
Cpmv::~Cpmv()
{
    std::cout << "Deleting: "<<  __PRETTY_FUNCTION__ << std::endl;
    if (pi)
        displayCpmv();
    --nObjects;
    std::cout << "nObj:\t" << nObjects << std::endl;
    delete pi; // if (pi) delete pi; ~~~
}

int main()
{
    {
        Cpmv a("Hello", "World");
        Cpmv b("C++", "Prog");
        Cpmv kek(a+b);
        kek.displayCpmv();
    }
    return 0;
}
