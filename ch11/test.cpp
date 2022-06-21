#include <iostream>
using namespace std;

int main()
{
    enum class Day : unsigned { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY };

   unsigned c = static_cast<unsigned>(Day::MONDAY); 
    cout << c << endl;



    return 0;
}
