#include <iostream>
#include "IntQueue.h"
using namespace std;

// int * queueArray; // points to the queue queueArray
// int queueSize;  // the queue size
// int front;      // subscript of the queue front
// int rear;       // subscript of the queue rear
// int numItems;   // number of items in the queue

// constructor
IntQueue::IntQueue(int s)
{
    queueArray = new int[s];
    queueSize = s;
    front = -1;
    rear = -1;
    numItems = 0;
}

// copy constructor
IntQueue::IntQueue(const IntQueue & obj)
{
    // allocate the queue array
    queueArray = new int[obj.queueSize];

    // copy the other object's attributes
    queueSize = obj.queueSize;
    front = obj.front;
    rear = obj.rear;
    numItems = obj.numItems;

    // copy the other object's queue array
    for (int index = 0; index < obj.queueSize; index++)
    {
        queueArray[index] = obj.queueArray[index];
    }

}

// Destructor
IntQueue::~IntQueue()
{
    delete [] queueArray;
}

// Queue Operations
// enqueue inserts a value at the rear of the queue
void IntQueue::enqueue(int num)
{
    if (isFull())
        cout << "The queue is full.\n";
    else
    {
        // calculate the new rear
        cout << "front was: " << front << " rear was: " << rear << endl;
        rear = (rear+1) % queueSize;
        cout << "front is: " << front << " rear is: " << rear << endl;
        // insert new item
        queueArray[rear] = num;
        // update items count
        numItems++;
    }
}

// dequeue removes the value at the front of the queuee and copies
// it into num
void IntQueue::dequeue(int &num)
{
    if (isEmpty())
        cout << "The queue is empty.\n";
    else
    {
        // move front
        cout << "front was: " << front << " rear was: " << rear << endl;
        front = (front + 1) % queueSize;
        cout << "front is: " << front << " rear is: " << rear << endl;
        // retrieve the front item
        num = queueArray[front];
        // update item count
        numItems--;
    }
}

bool IntQueue::isEmpty() const
{
    bool status;

    status=(numItems?false:true);
    return status;
}

bool IntQueue::isFull() const
{
    bool status;
    status = (numItems < queueSize)?false:true;
    return status;
}

void IntQueue::clear()
{
    rear = queueSize-1;
    front = queueSize-1;
    numItems = 0;
}
