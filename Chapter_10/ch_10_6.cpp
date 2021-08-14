#include <iostream>
class Move
{
    double x;
    double y;
    public:
    Move(double a = 0, double b = 0);
    void showmove() const;
    Move add(const Move&m) const;
    void reset(double a = 0, double b = 0);
};
Move::Move(double a, double b)
{
    x = a;
    y = b;
}
Move Move::add(const Move&m) const
{
    Move temp(m.x + x, m.y + y);
    return temp;
}
void Move::showmove() const
{
    std::cout << "(" << x << "," << y
        << ")"<< std::endl;
}
void Move::reset(double a, double b)
{
    x = a;
    y = b;
}
int main()
{
    Move a;
    std::cout << "a: ";
    a.showmove();
    a.reset(1,2);
    std::cout << "a: ";
    a.showmove();
    Move b (3, 4);
    std::cout << "b: ";
    b.showmove();
    b.reset();
    b.reset(4,4);
    std::cout << "a: ";
    b.showmove();
    Move c = a.add(b);
    std::cout << "c: ";
    c.showmove();
    return 0;
}

