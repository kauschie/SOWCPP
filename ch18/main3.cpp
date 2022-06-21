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

    list.insertNode(10.5);

    list.displayList();

    return 0;

}
