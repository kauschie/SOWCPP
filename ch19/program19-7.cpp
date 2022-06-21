#include <iostream>
#include "IntQueue.h"
using namespace std;

int main()
{
    const int MAX_VALUES = 5;
    int x = 2;

    IntQueue iQueue(MAX_VALUES);

    do
    {
    cout << "Enqueuing " << MAX_VALUES << " items...\n";
    for (int index = 0; index < MAX_VALUES; index++)
    {
        iQueue.enqueue(index);
    }

    // attempt to enqueue one more item
    cout << "Now attempting to enqueue again...\n";
    iQueue.enqueue(MAX_VALUES);

    // dequeue and retrieve all items in the queue
    cout << "The values in the queue were:\n";
    while (!iQueue.isEmpty())
    {
        int value;
        iQueue.dequeue(value);
        cout << value << endl;
    }
} while (x-- > 0);

    return 0;
}
