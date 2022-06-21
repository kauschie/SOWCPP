// this program demonstrates a simple append operation
// on a linnked list
#include <iostream>
#include "NumberList.h"

using namespace std;

int main()
{
    // define a NumberList object
    NumberList list;

    // append some values to the list.
    list.appendNode(2.5);
    list.appendNode(7.9);
    list.appendNode(12.6);

    cout << "Here are the initial values:\n";
    list.displayList();
    cout << endl;

    // delete the middle node
    cout << "Now deleteing the node in the middle.\n";
    list.deleteNode(7.9);

    cout << "Here are the nodes left.\n";
    list.displayList();
    cout << endl;

    // delete the last node
    cout << "Now deleteing the last node.\n";
    list.deleteNode(12.6);

    cout << "Here are the nodes left.\n";
    list.displayList();
    cout << endl;

    // delete the remaining node
    cout << "Now deleteing the only remaining node.\n";
    list.deleteNode(2.5);

    cout << "Here are the nodes left.\n";
    list.displayList();

    return 0;

}
