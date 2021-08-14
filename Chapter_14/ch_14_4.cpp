#include <iostream>
#include <cstring>

class Person
{
    std::string name;
    std::string surname;
public:
    Person(const std::string &_name = "", const std::string &_surname = "") : name(_name), surname(_surname) {}
    virtual ~Person();
    virtual void show() const;
    virtual void set() { std::cin >> *this; }
    friend std::istream & operator>>(std::istream &in, Person &);
};
Person::~Person()
{
}
std::istream& operator>>(std::istream &in, Person &t0)
{
    std::cout << "Enter name: ";
    std::getline(in, t0.name);
    std::cout << "Enter surname: ";
    std::getline(in, t0.surname);
    return in;
}
void Person::show() const
{
    std::cout << name << " "
        << surname  << std::endl;
}
class Gunslinger: virtual public Person
{
    double time;
    int notches;
protected:
    void data() const;
    void get();
public:
    Gunslinger(const std::string &_name = "", const std::string &_surname = "", double _time = 0.0, int _notches = 0)
        : Person(_name, _surname), time(_time), notches(_notches) { }
    double draw() const { return time; }
    double& draw() { return time; }
    int& getNotches() { return notches; }
    int getNotches() const { return notches; }
    virtual void show() const override;
    virtual void set()  override { std::cin >> *this; }
    friend std::istream & operator>>(std::istream &in, Gunslinger &t0);
};
void Gunslinger::get()
{
    std::cout << "Enter time to ready: ";
    std::cin >> time;
    std::cout << "Enter notches on gun: ";
    std::cin >> notches;
}
std::istream & operator>>(std::istream &in, Gunslinger &t0)
{
    in >> (Person &) t0;
    t0.get();
    return in;
}
void Gunslinger::data() const
{
    std::cout << "Draw: " << time 
        << std::endl
        << "Notches: " << notches << std::endl;
}
void Gunslinger::show() const
{
    Person::show();
    data();
}
class PokerPlayer: virtual public Person
{
protected:
    void data() const;
    void get();
    struct Card
    {
        std::string suit;
        std::string figure;
        Card(const std::string &_suit = "", const std::string &_figure = "") : suit(_suit), figure(_figure) {}
    };
public:
    Card card;
    PokerPlayer(const std::string &_name = "", const std::string &_surname = "", const std::string &_suit = "",
            const std::string &_figure = "") : Person(_name, _surname), card(_suit, _figure) {}
    const Card& draw() const { return card; }
    Card& draw() { return card; }
    virtual void show() const override;
    virtual void set()  override { std::cin >> *this; }
    friend std::istream & operator>>(std::istream &in, PokerPlayer &t0);
};
void PokerPlayer::get()
{
    std::cout << "Enter suit of card: "; 
    std::cin >> card.suit;
    std::cout << "Enter card figure: ";
    std::cin >> card.figure;
}
std::istream & operator>>(std::istream &in, PokerPlayer &t0)
{
    in >> (Person&) t0;
    t0.get();
    return in;
}
void PokerPlayer::data() const
{
    std::cout << "Card suit: " <<
        card.suit << std::endl
        << "Card figure: " <<
        card.figure << std::endl;
}
void PokerPlayer::show() const
{
    Person::show();
    data();
}

class BadDude: public Gunslinger, public PokerPlayer
{
public:
    BadDude(const std::string &_name = "", const std::string &_surname = "",
            const std::string &_suit = "", const std::string &_figure = "",
            double _time = 0.0, int _notches = 0) 
        : Person(_name, _surname), PokerPlayer(_name, _surname, _suit, _figure),
          Gunslinger(_name, _surname, _time, _notches) 
    {
    }
    const Card& cdraw() const;
    double& cdraw();
    virtual void show() const override;
    virtual void set()  override { std::cin >> *this; }
    friend std::istream & operator>>(std::istream &in, BadDude &t0);
};
std::istream & operator>>(std::istream &in, BadDude &t0)
{
    in >> (Person &) t0;
    t0.Gunslinger::get();
    t0.PokerPlayer::get();
    return in;
}
const PokerPlayer::Card& BadDude::cdraw() const
{
    return PokerPlayer::draw();
}
double& BadDude::cdraw()
{
    return Gunslinger::draw();
}
void BadDude::show() const 
{
    Person::show();
    Gunslinger::data();
    PokerPlayer::data();
}

int main()
{
    const int n = 4;
    Person* a[n];
    int i;
    for (i = 0; i < n; ++i) {
        char choice;
        std::cout << "Enter choice to select character:\n"
            << "s: simple person g: sniper " 
            << "p: poker player  c: combo(sniper + poker player)\nq: quit\n";
        std::cin >> choice;
        while (strchr("sgpqc", choice) == NULL) {
            std::cout << "Please enter s, g, p, c or q again: ";
            std::cin >> choice;
        }
        if (choice == 'q') {
            break;
        }
        switch(choice) 
        {
            case 's': a[i] = new Person; break;
            case 'p': a[i] = new PokerPlayer; break;
            case 'g': a[i] = new Gunslinger; break;
            case 'c': a[i] = new BadDude; 
        }
        std::cin.get();
        a[i]->set();
    }
    std::cout << "Entered people:\n";
    std::cout << n << " " << i << std::endl;
    for (int j = 0; j < i; ++j) {
        a[j]->show();
    }
    for (int j = 0; j < i; ++j) {
        delete a[j]; 
    }
    return 0;
}
