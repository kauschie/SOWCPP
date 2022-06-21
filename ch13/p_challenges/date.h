#ifndef DATE_H
#define DATE_H
#include <string>

class Date
{
    private:
        int month, day, year;
        std::string str_month;
        void set_month();

    public:
        Date(int m = 1, int d = 1, int y = 2000);

        std::string int_print();
        std::string mdy_print();
        std::string dmy_print();

        friend void Event::set_date(int m, int d, int y);
};

#endif
