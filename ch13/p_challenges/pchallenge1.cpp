#include "date.h"
#include "event.h"
#include <iostream>

using namespace std;

int main()
{


   Date d1(5,13,1987);

   cout << d1.int_print() << endl;
   cout << d1.mdy_print() << endl;
     
    

    return 0;
}
