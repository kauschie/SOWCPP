#include <iostream>
using namespace std;

int main()
{
    /* 
     * if (x > y)
     *      z = 1;
     * else
     *      z = 20;
     */
    // z = x > y ? 1 : 20;

    /*
     *  if (temp > 45)
     *      population = base * 10;
     *  else
     *      population = base * 2;
     */
    // population = ((temp > 45) ? (base*10) : (base*2))

    /*
     *  if (hours > 40)
     *      wages *= 1.5;
     *  else
     *      wages *= 1;
     */

    // wages *= (hours > 40 ? 1.5 : 1);

    /*
     *  if (result >= 0)
     *      cout << "The result is positive.\n";
     *  else
     *      cout << "The result is negative.\n";
     */


    int result;

    cout << "Enter a number: ";
    cin >> result;
    cout << "The result is " << (result >= 0 ? "positive" : "negative");
    

    return 0;
}

/* just for fun
 *
 * cout << "Class is " << (password == "remembered" ? "so chill" : "like drowning puppies");
 *
