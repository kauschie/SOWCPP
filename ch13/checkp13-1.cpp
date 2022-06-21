// checkpoints beginning on 13.1
#include <iostream>
using namespace std;


int main()
{
    // checkp# 13.1
    // false

    // checkp# 13.2
    // B, void RetailItem::setPrice(double p)

    // checkp# 13.3
    // A) public member functions access private variables

    // checkp# 13.4
    //class RetailItem
       // void setPrice(double);
   
    // C, soap.setPrice(1.49);

    // checkp# 13.5
    class Date
    {
        private:
            int month;
            int day;
            int year;

        public:
            void setMonth(int);
            void setDay(int);
            void setYear(int);
            int getMonth();
            int getDay();
            int getYear();
    };

    return 0;
}
