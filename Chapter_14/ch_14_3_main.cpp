#include <iostream>
#include <cstring>
#include "workermi.h"
#include "ch_14_3.h"

const int SIZE = 2;

int main()
{
   using std::cin;
   using std::cout;
   using std::endl;
   using std::strchr;

   Worker * lolas[SIZE];
   Queue<Worker*> line;
   int ct;
   for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the employee category:\n"
            << "w: waiter  s: singer  "
            << "t: singing waiter  q: quit\n";
        cin >> choice;
        while (strchr("wstq", choice) == NULL)
        {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch(choice)
        {
            case 'w':   lolas[ct] = new Waiter;
                        break;
            case 's':   lolas[ct] = new Singer;
                        break;
            case 't':   lolas[ct] = new SingingWaiter;
                        break;
        }
        cin.get();
        lolas[ct]->Set();
        line.enqueue(lolas[ct]);
    }

    cout << "\nHere is your staff:\n";
    int i;
    Worker* temp;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        line.dequeue(temp);
        temp->Show();
    }
    for (i = 0; i < ct; i++)
        delete lolas[i];
    cout << "Bye.\n";
    // cin.get();
    // cin.get();
    return 0;
}
