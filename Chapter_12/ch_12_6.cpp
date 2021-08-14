#include <iostream>
#include <ctime>
class Customer
{
private:
    long arrive;        // arrival time for customer (момент появления клиента)
    int processtime;    // processing time for customer (время обслуживания клиента)
public:
    Customer() : arrive(0), processtime (0) {}
    void set(long c);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};

void Customer::set(long c)
{
    processtime = std::rand() % 3 + 1;
    arrive = c;
}

typedef Customer Item;

class Queue
{
private:
// class scope definitions
    // Node is a nested structure definition local to this class
    struct Node { Item item; struct Node * next;};
    enum {Q_SIZE = 10};
// private class members
    Node * front;       // pointer to front of Queue
    Node * rear;        // pointer to rear of Queue
    int items;          // current number of items in Queue
    const int qsize;    // maximum number of items in Queue
    // preemptive definitions to prevent public copying
    Queue(const Queue & q) : qsize(0) { }
    Queue & operator=(const Queue & q) { return *this;}
public:
    Queue(int qs = Q_SIZE); // create queue with a qs limit
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item &item); // add item to end
    bool dequeue(Item &item);       // remove item from front
};

// Queue methods
Queue::Queue(int qs) : qsize(qs)
{
    front = rear = NULL;    // or nullptr
    items = 0;
}

Queue::~Queue()
{
    Node * temp;
    while (front != NULL)   // while queue is not yet empty
    {
        temp = front;       // save address of front item
        front = front->next;// reset pointer to next item
        delete temp;        // delete former front
    }
}

bool Queue::isempty() const
{
    return items == 0;
}

bool Queue::isfull() const
{
    return items == qsize;
}

int Queue::queuecount() const
{
    return items;
}

// Add item to queue
bool Queue::enqueue(const Item & item)
{
    if (isfull())
        return false;
    Node * add = new Node;  // create node
// on failure, new throws std::bad_alloc exception
    add->item = item;       // set node pointers
    add->next = NULL;       // or nullptr;
    items++;
    if (!front)      // if queue is empty,
        front = add;        // place item at front
    else
        rear->next = add;   // else place at rear
    rear = add;             // have rear point to new node
    return true;
}

// Place front item into item variable and remove from queue
bool Queue::dequeue(Item & item)
{
    if (!front)
        return false;
    item = front->item;     // set item to first item in queue
    items--;
    Node * temp = front;    // save location of first item
    front = front->next;    // reset front to next item
    delete temp;            // delete former first item
    if (items == 0)
        rear = NULL;
    return true;
}

//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}
int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
// setting things up
    std::srand(std::time(0));    //  random initializing of rand()
    int sizeLine, hours;
    std::cin >> sizeLine >> hours;
    Queue firstLine(sizeLine);
    Queue secondLine(sizeLine);
    long range = 60 * hours;
    double perhour;
    cin >> perhour;
    double average = 60 / perhour; // time between
    Item temp;
    int wait_time = 0;
    int line_wait = 0;
    int line_wait_1 = 0;
    int wait_time_1 = 0;
    int served = 0;
    int currentSum = 0;
    int countCustomer_1min = 0;
    int allserved = 0;
    int sum_line = 0;
    for (int i = 0, j = 0; i < range; ++i, ++j) {
        if (newcustomer(average)) 
        {
            if (!firstLine.isfull() && !secondLine.isfull()) {
                 temp.set(i);
                 if (firstLine.queuecount() <= firstLine.queuecount()) 
                        firstLine.enqueue(temp);
                 else 
                        secondLine.enqueue(temp);
                 ++allserved;
                 ++served;
            }
            if (wait_time <= 0 && !firstLine.isempty()) {
                firstLine.dequeue(temp);
                wait_time = temp.ptime();
                line_wait += i - temp.when();
                currentSum += i - temp.when();
            }
            if (wait_time_1 <= 0 && !secondLine.isempty()) {
                secondLine.dequeue(temp);
                wait_time_1 = temp.ptime();
                line_wait_1 += i - temp.when();
                currentSum += i - temp.when();
            }
        }
        if (wait_time > 0) --wait_time;
        if (wait_time_1 > 0) --wait_time_1;
        if (j == 60) {
            if (currentSum / served<= 1) {
                countCustomer_1min += served;
            }
            j = 0;
            currentSum = 0;
            served = 0;
        }
        sum_line += firstLine.queuecount();
        sum_line += secondLine.queuecount();
    }
    std::cout << "accepted: " << allserved 
        << std:: endl << countCustomer_1min << std::endl;
    std::cout << sum_line  / range << std::endl;
    return 0;
}


