// This program demonstrates the range-based for loop
#include <iostream>
#include <string>
using namespace std;

int main()
{
   string planets[] = { "Mercury", "Venus", "Earth", "Mars",
                        "Jupiter", "Saturn", "Uranus",
                        "Neptune", "Pluto (a dwarf planet)" };

    cout << "Here are the planets:\n";

    for (string planet : planets)
        cout << planet << endl;

    return 0;
}




