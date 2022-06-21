#ifndef INTQUEUE_H
#define INTQUEUE_H

class IntQueue
{
private:
    int * queueArray; // points to the queue queueArray
    int queueSize;  // the queue size
    int front;      // subscript of the queue front
    int rear;       // subscript of the queue rear
    int numItems;   // number of items in the queue
public:
    // constructor
    IntQueue(int);

    // copy constructor
    IntQueue(const IntQueue&);

    // Destructor
    ~IntQueue();

    // Queue Operations
    void enqueue(int);
    void dequeue(int &);
    bool isEmpty() const;
    bool isFull() const;
    void clear();
};

#endif
