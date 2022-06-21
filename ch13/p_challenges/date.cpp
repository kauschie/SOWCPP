#include "date.h"
#include <iostream>
#include <string>

Date::Date(int m, int d, int y)
{
   month = m;
   day = d;
   year = y;
   set_month();
}


void Date::set_month()
{
    std::string months[12] = {"January", "February", "March", "April", 
                                "May", "June", "July", "August", 
                                "September", "October", "November", "December"};

    str_month = months[month-1]; 
}

std::string Date::int_print()
{
    
    return (std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year));
}

std::string Date::mdy_print()
{
    // std::cout << str_month << ' ' << day << ", " << year << std::endl;

    return (str_month + " " + std::to_string(day) + ", " + std::to_string(year));
}

std::string Date::dmy_print()
{
    //std::cout << day << ' ' << str_month << ' ' << year << std::endl;

    return (std::to_string(day) + " " + str_month + " " + std::to_string(year));
}

