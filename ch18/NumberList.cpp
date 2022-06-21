#include "NumberList.h"
#include <iostream>

using namespace std;

void NumberList::appendNode(double num)
{
    ListNode *newNode; // to point to a new node
    ListNode *nodePtr; // to move through the List

    // allocate a new node and store num there:
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr;

    // if there are no nodes in the list
    // make newNode the first node.

    if(!head)
        head = newNode;
    else    // otherwise, insert newNode at the end.
    {
        // initialize nodePtr to head of list.
        nodePtr = head;

        // find the last node in the list
        while(nodePtr->next)
        {
            nodePtr = nodePtr->next;
        }
        // insert newNode as the last node
        nodePtr->next = newNode;
    }
}

void NumberList::displayList() const
{
    ListNode * nodePtr = head;

    while (nodePtr)
    {
        cout << nodePtr->value << endl;
        nodePtr = nodePtr->next;
    }
}

void NumberList::insertNode(double num)
{
    ListNode * newNode;
    ListNode * nodePtr;
    ListNode * previousNode = nullptr;

    // allocate a new node and store num there
    newNode = new ListNode;
    newNode->value = num;

    // if there's no nodes in the list make newNode the first node
    if (!head)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    else    // otherwise insert a new node
    {
        // position nodePtr at the head of the list
        nodePtr = head;

        // initialize previousNode to nullptr
        previousNode = nullptr;

        // skill all nodes whose value is less than num
        while(nodePtr != nullptr && nodePtr->value < num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // if the new node is to be the first
        // insert it before all other nodes
        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nullptr;
        }
        else    // else insert it after the previousNode
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }

    }
}

void NumberList::deleteNode(double num)
{
    ListNode *nodePtr;  // to traverse the list
    ListNode *previousNode; // to point to the previous node

    // if the list is empty, do nothing
    if (!head)
        return;

    // determine if the first node is the one.
    if (head->value == num)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        // initialize nodePtr to head of list
        nodePtr = head;

        // skip all nodes whose value member is not equal to num
        while(nodePtr != nullptr && nodePtr->value != num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // if nodePtr is not at the end of the list,
        // link the previous node to the node after
        // nodePtr, then delete nodePtr;

        if (nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

NumberList::~NumberList()
{
    ListNode *nodePtr;  // to traverse the list
    ListNode *nextNode; // to point to the next node

    // poisition nodePtr at the head of the List
    nodePtr = head;

    // while nodePtr is not pointing to the end of the list...
    while(nodePtr != nullptr)
    {
        // save a pointer to the next node
        nextNode = nodePtr->next;

        // delete the current node
        delete nodePtr;

        // position nodePtr at the next node;
        nodePtr = nextNode;
    }
}
