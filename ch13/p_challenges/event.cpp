#include <string>
#include "event.h"

class Date;
        
Event::Event(std::string t = "no title", int m = 1, int d = 1, int y = 2000)
{
    date = new Date(m,d,y);
    title = t;    
}
        
void Event::set_title(std::string t)
{
    title = t;
}
         
void Event::set_date(int m, int d, int y)
{
    date.month = m;
    date.day = d;
    date.year = y;
}


Event::~Event()
{
    delete date;
    date = nullptr;
}

string get_date(int n)         // sent with print option
{
    std::string s;
    if (n == 1)
    {
        s = date.int_print();
    }
    else if (n == 2)
    {
        s = mdy_print();
    }
    else if (n == 3)
    {
        s = dmy_print();
    }
}

ostream& operator<<(ostream & out, Date obj)
{

    return out;
}

