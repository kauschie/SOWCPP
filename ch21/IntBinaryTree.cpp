#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    if (nodePtr == nullptr)
        nodePtr = newNode;      // insert the node
    else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode);
    else
        insert(nodePtr->right, newNode);
}

void IntBinaryTree::insertNode(int num)
{
    TreeNode *newNode = nullptr; // pointer to a new node

    // create a new node and store num in it
    newNode = new TreeNode;
    newNode->value = num;
    newNode->left = newNode->right = nullptr;

    // insert the node.
    insert(root, newNode);
}

void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << endl;
        displayInOrder(nodePtr->right);
    }
}

void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        cout << nodePtr->value << endl;
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << endl;
    }
}

bool IntBinaryTree::searchNode(int num)
{
    TreeNode *nodePtr = root;

    while(nodePtr)
    {
        if (nodePtr->value == num)
            return true;
        else if (num < nodePtr->value)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return false;
}

void IntBinaryTree::remove(int num)
{
    deleteNode(num, root);
}

void IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr)
{
    if (num < nodePtr->value)
        deleteNode(num, nodePtr->left);
    else if (num > nodePtr->value)
        deleteNode(num, nodePtr->right);
    else
        makeDeletion(nodePtr);
}

void IntBinaryTree::makeDeletion(TreeNode *&nodePtr)
{
    // define a temporary pointer to use in reattaching
    // the left subtree
    TreeNode *tempNodePtr = nullptr;

    if (nodePtr == nullptr)
        cout << "cannot delete empty node.\n";
    else if (nodePtr->right == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;    // reattach the left child
        delete tempNodePtr;
    }
    else if (nodePtr->left == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;   // reattach the right child
        delete tempNodePtr;
    }
    // if the node has two children
    else
    {
        // move one node to the right
        tempNodePtr = nodePtr->right;
        // go to the end left node
        while(tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;
        // reattach the left subtree
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;

        // reattach the right subtree
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }

}

void IntBinaryTree::destroySubTree(TreeNode *nodePtr)
{
    if (nodePtr)
    {
        if (nodePtr->left)
            destroySubTree(nodePtr->left);
        if (nodePtr->right)
            destroySubTree(nodePtr->right);
        delete nodePtr;
    }
}

/*
private:
    void insert(TreeNode *&, TreeNode *&):
    void destroySubTree(TreeNode *);
    void deleteNode(int, TreeNode *&);
    void makeDeletion(TreeNode *&);
    void displayInOrder(TreeNode *) const;
    void displayPreOrder(TreeNode *) const;
    void displayPostOrder(TreeNode *) const;

public:

    // Binary Tree Operations
    void insertNode(int);
    bool searchNode(int);
    void remove(int);
    void displayInOrder() const
    { displayInOrder(root); }

    void displayPreOrder() const
    { displayPreOrder(root); }

    void displayPostOrder() const
    { displayPostOrder(root); }
                                                            */
