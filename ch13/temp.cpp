// 
#include <iostream>
using namespace std;

class Umbrella
{
    private:
        bool is_open = false;
        string color;
    public:
        void toggle()
        {
            if (is_open)
                is_open = false;
            else
                is_open = true;
        }
        void set_color(string c)
        {
            color = c;
        }
};


int main()
{







}
