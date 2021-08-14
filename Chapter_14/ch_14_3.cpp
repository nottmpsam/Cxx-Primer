#ifndef CH_14_3_H
#define CH_14_3_H
template <typename T>
class Queue
{
private:
    struct Node {
        T elem;
        Node* next;
        Node(T _elem, Node* _next = nullptr) : elem(_elem), next(_next) {}
    };
    const int qSize;
    //preemptive definitons to prevent public copying
    Queue(const Queue<T> &q) : qSize(0) {}
    Queue& operator=(const Queue<T> &q) { return *this; }
    int count;
public:
    Node* front;
    Node* rear;
    Queue(int _qSize = 10);
    //можно без explicit, т.к конструктор копирования и оператор присваивания находятся в private :)
    virtual ~Queue();
    bool isEmpty() const { return front == nullptr; }
    bool isFull() const { return count == qSize; }
    int queueCount() const { return count; }
    bool enqueue(const T &);
    bool dequeue(T &);
};
template <typename T>
bool Queue<T>::dequeue(T& elem)
{
    if (isEmpty()) {
        return false;
    }
    --count;
    elem = front->elem;
    Node* temp = front;
    front = front->next;
    if (count == 0) {
        rear = nullptr;
    }
    delete temp;
    return true;
}
template <typename T>
bool Queue<T>::enqueue(const T& elem)
{
    if (isFull()) {
        return false;
    }
    ++count;
    if (isEmpty()) {
        rear = front = new Node(elem);
    } else {
        rear->next = new Node(elem);
        rear = rear->next;
    }
    return true;
} 
template <typename T>
Queue<T>::Queue(int _qSize) : qSize(_qSize)
{
    rear = front = nullptr;
    count = 0;
}
template <typename T>
Queue<T>::~Queue()
{
    Node* temp;
    while (front) {
        temp = front;
        front = front -> next;
        --count; //maybe it will useful
        delete temp;
    }
}

#endif
