#include <iostream>

typedef int Item;

class simpleList
{
public:
    class Node
    {
    public:
        Item key;
        Node* next;
        Node(int _key = 0, Node* _next = nullptr) { key = _key; next = _next; }
    };
    simpleList();
    ~simpleList();
    void addItem(Item value);
    bool isEmpty() const;
    void visit(void (*pf) (Item &item));
    void showList() const;
private:
    Node* root;
};
void simpleList::visit(void (*pf) (Item &item))
{
    Node* t = root;
    while (t) {
        pf(t->key);
        t = t->next;
    }
}
simpleList::~simpleList()
{
    Node * t = nullptr;
    while (root) {
        t = root;
        root = root->next;
        delete t;
    }
}
simpleList::simpleList()
{
    root = nullptr;
}
void simpleList::showList() const
{
    Node* q = root;
    while (q) {
        std::cout << q->key << " ";
        q = q->next;
    }
    std::cout << std::endl;
}
bool simpleList::isEmpty() const 
{
    return root == nullptr;
}
void simpleList::addItem(Item value)
{
    if (isEmpty()) {
        root = new Node(value);
        return;
    }
    Node* q = root;
    while (q->next) {
        q = q->next;
    }
    q->next = new Node(value);
}
void sumToEach(Item &key) {
    key+=key;
}
int main()
{
    simpleList q;
    srand(time(0));
    int n = rand () % 10;
    for (int i = 0; i < n;++i) {
        int temp = rand() % 20;
        q.addItem(temp);
    }
    q.showList();
    void (*pf)(Item &key) = sumToEach;
    q.visit(pf);
    q.showList();
}
