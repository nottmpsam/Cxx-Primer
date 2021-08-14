#include <iostream>

struct customer
{
    char fullname[35];
    double payment;
    mutable double currentSum;
};

typedef customer Item;

class Stack
{
private:
    enum {MAX = 10};    // constant specific to class
    Item items[MAX];    // holds stack items
    int top;            // index for top stack item
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    // push() returns false if stack already is full, true otherwise
    bool push(const Item & item);   // add item to stack
    // pop() returns false if stack already is empty, true otherwise
    bool pop(Item & item);          // pop top into item
    int getSum() const;
};

Stack::Stack()    // create an empty stack
{
    top = 0;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const Item & item) 
{
    if (top < MAX)
    {
        item.currentSum = 0;
        items[top++] = item;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item & item)
{
    if (top > 0)
    {
        --top;
        if (top - 1 < 0) {
            items[0].currentSum += items[0].payment;
        } else {
            items[top-1].currentSum += items[top].payment;
            items[top-1].currentSum += items[top].currentSum;
        }
        item = items[top];
        return true;
    }
    else
        return false; 
}
int main()
{
    customer arr[3] = {{"Sam", 12.0}, {"Paul", 8.0}, {"Kristy", 10.0}};
    Stack stack;
    for (int i = 0; i < 3; ++i) {
        stack.push(arr[i]);
    }
    std::cout << "***" << std::endl;
    for (int i = 0; i < 3; ++i) {
        stack.pop(arr[i]);
    }
    std::cout << "~~~" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << arr[i].fullname << std::endl;
    }
    std::cout << arr[2].currentSum << std::endl;
    return 0;
}
