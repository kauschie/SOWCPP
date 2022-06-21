#ifndef NUMBERLIST_H
#define NUMBERLIST_H

class NumberList
{
private:
    // Declare a structure for the list
    struct ListNode
    {
        double value;       // the value in this node
        struct ListNode * next; // to point to the next node
    };

    ListNode * head;        // list head pointer

public:
    // constructor
    NumberList()
    {
        head = nullptr;
    }

    // destructor
    ~NumberList();

    // linked list operations
    void appendNode(double);
    void insertNode(double);
    void deleteNode(double);
    void displayList() const;
};


#endif
