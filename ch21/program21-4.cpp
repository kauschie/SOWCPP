#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

int main()
{
    IntBinaryTree tree;

    cout << "Inserting nodes. ";
    tree.insertNode(5);
    tree.insertNode(8);
    tree.insertNode(3);
    tree.insertNode(12);
    tree.insertNode(9);
    cout << "Done.\n";

    // display the values
    cout << "Here are the values in the tree:\n";
    tree.displayInOrder();

    // delete the value 8.
    cout << "Deleting 8...\n";
    tree.remove(8);

    // deleting the value 12
    cout << "Deleting 12...\n";
    tree.remove(12);

    // display the values.
    cout << "Now, here are the nodes:\n";
    tree.displayInOrder();
    return 0;
}
