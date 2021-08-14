// stack.h -- class definition for the stack ADT
#include <iostream>

typedef long long Item;
class Stack
{
private:
    int stackSize;
    Item* elems;
    int top;  //last of index
public:
    Stack(int _stackSize = 10);
    Stack(const Stack &st);
    ~Stack();
    bool isempty() const { return  top == 0; } 
    bool isfull() const { return stackSize == top; }
    // push() returns false if stack already is full, true otherwise
    bool push(const Item & item);   // add item to stack
    // pop() returns false if stack already is empty, true otherwise
    bool pop(Item & item);          // pop top into item
    Stack & operator=(const Stack &st);
    int getIndex() { return top; }
};
bool Stack::pop(Item & item)
{
    if (isempty()) {
        item = 0;
        return false;
    }
    item = elems[--top];
    return true;
}
bool Stack::push(const Item & item)
{
    if (isfull()) {
        return false;
    }
    elems[top++] = item;
    return true;
}
Stack & Stack::operator=(const Stack &st)
{
    if (this != &st) {
        delete [] elems;
        stackSize = st.stackSize;
        top = st.top;
        elems = new Item[stackSize];
        for (int i = 0; i < top; ++i)
            elems[i] = st.elems[i];
    }
    return *this;
}
Stack::Stack(const Stack &st)
{
    stackSize = st.stackSize;
    elems = new Item[stackSize];
    top = st.top;
    for (int i = 0; i < top; ++i) 
        elems[i] = st.elems[i];
}
Stack::~Stack() {
    delete [] elems;
}

Stack::Stack(int _stackSize)
{
    top = 0;
    stackSize = _stackSize;
    elems = new Item[stackSize];
}

int main()
{
    int n;
    std::cout << "Enter range of stack: ";
    std::cin >> n;
    Stack stack(n);
    std::cout << "Enter values of stack(any symbols to quit): " << std::endl;
    Item q;
    int i;
    for (i = 0; i < n; ++i) {
        if (!(std::cin >> q)) {
            std::cin.clear();
            while (std::cin.get() != '\n')
                continue;
            break;
        }
        stack.push(q);
    }
    Stack stack_2 = stack;
    for (int j = 0; j < i; ++j) {
        stack_2.pop(q);
        std::cout << q << " ";
    }
    std::cout << std::endl;
    Stack stack_3;
    stack_3  = stack;
    for (int j = 0; j < i; ++j) {
        stack_3.pop(q);
        std::cout << q << " ";
    }
    return 0;
}
