#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <iostream>

class Date;

class Event
{
    private:
        Date * date = nullptr;
        std::string Title;
        
    public:
        // constructors
        Event(std::string t = "no title", int m = 1, int d = 1, int y = 2000);

        //destructors
        ~Event();
        
        // mutators / setters
        void set_title(std::string t);
        void set_date(int m, int d, int y);

        // accessors / getters
        std::string get_date(int n);         // sent with print option
        friend std::ostream& operator<<(std::ostream & out, Date obj);


};

#endif
