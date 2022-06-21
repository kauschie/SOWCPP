// a class template for holding a linnked list
// the node type is also a class template
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//********************************************
// the listnode class creates a type used to *
// store a node of the linked list.          *
//********************************************

template <class T>
class ListNode
{
public:
    T value;            // Node value
    ListNode<T> *next;  // pointer to next node

    // constructor
    ListNode(T nodeValue)
    {
        value = nodeValue;
        next = nullptr;
    }
};

template <class T>
class LinkedList
{
private:
    ListNode<T> *head;  // List head pointer

public:
    // constructor
    LinkedList()
    { head = nullptr; }

    ~LinkedList();

    // linked list operations
    void appendNode(T);
    void insertNode(T);
    void deleteNode(T);
    void displayList() const;
};

template <class T>
void LinkedList<T>::appendNode(T newValue)
{
    ListNode<T> *newNode;       // to point to a new node
    ListNode<T> *nodePtr;       // to move through the list

    // allocate a new node and store newValue otherwise
    newNode = new ListNode<T>(newValue);

    // if there are no nodes in the list make the new node
    // the first node in the list
    if(!head)
        head = newNode;
    else
    {
        // initialize nodePtr to head of the list
        nodePtr = head;

        // find the last node in the list
        while(nodePtr->next)
            nodePtr = nodePtr->next;

        nodePtr->next = newNode;
    }
}

// shows the value stored in each node of the linked list
// pointed to by head
template <class T>
void LinkedList<T>::displayList() const
{
    ListNode *nodePtr;  // to move through the list=

    // position nodePtr at the head of the list
    nodePtr = head;

    // traverse the list
    while(nodePtr)
    {
        cout << nodePtr->value << endl;
        nodePtr = nodePtr->next;
    }
}


// insert a node with newValue
template <class T>
void LinkedList<T>::insertNode(T newValue)
{
    ListNode<T> *newNode;                   // a new node
    ListNode<T> *nodePtr;                   // to traverse the list
    ListNode<T> *previousNode = nullptr;    // the previous node

    newNode = new ListNode<T>(newValue);

    // if there are no nodes in the list position it at the head
    if(!head)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    else   // otherwise, insert newNode
    {
        // position nodePtr at the head of the list
        nodePtr = head;
        previousNode = nullptr;

        // skip all nodes whose value is less than newValue
        while (nodePtr != nullptr && nodePtr->value < newValue)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // if the new node is to be the 1st in the list,
        // insert it before all other nodes
        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else    // otherwise insert it after the previous node
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}


#endif
