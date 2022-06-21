// Checkpoint ##
//
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>  // for srand() and rand()
#include <ctime>    // for time()
using namespace std;

int main()
{
    int answer;      // holds the answer to the guessing game
    int guess;
    unsigned seed = time(0);        // set the current time = to seed
    srand(seed);            // seed the srand variable with the current time
                            // so that rand() generates a random number
    int choice;
    const int MIN_VALUE = 1;        // default min value 1
    const int MAX_VALUE = 10;         // default max value 10

    
    cout << "-- Welcome to the random number guessing game!! --\n";
    cout << "The current range of numbers is from "
        << MIN_VALUE << " to " << MAX_VALUE;
    cout << "1. Play the game with these settings\n"
        << "2. Change the range of values\n"
        << "3. Quit the game.\n"
        << "Enter 1, 2 or 3 here: ";

    while (!(cin >> choice) || choice < 1 || choice > 3)
    {
        cout << "I didn't understand your choice.\n"
            << "Please try again. Enter 1, 2 or 3: ";
    }

        
    switch (choice)
    {
        case 2: cout << "Enter a new minimum value: ";
                while (!(cin >> MIN_VALUE) || (MIN_VALUE < 0))
                    {
                        cout << "Enter a number greater than 0: ";
                    }
                cout << "Enter a new maximum value: ";
                while (!(cin >> MAX_VALUE) || (MIN_VALUE >= MAX_VALUE))
                    {
                        cout << "Enter a value greater than " 
                            << MIN_VALUE << ": ";
                    }

        case 1: answer = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
                do
                {
                    cout << "Enter a value between "
                    << MIN_VALUE << " and " << MAX_VALUE << ": ";
                    cin >> guess;
                    if (guess > answer)
                    {
                        cout << "lower\n";
                    }
                    else if (guess < answer)
                    {
                        cout << "higher\n";
                    }
                    else if (guess == answer)
                    {
                        cout << "Congratulations!! " << guess
                            << " is the correct answer!\n";
                        return 0;
                    }
                    else
                    {
                        cout << "I didn't understand that answer\n";
                    }
                } while (guess != answer);
        case 3: cout << "Thank you for playing!\n";
                return 0;
    }
    return 0;
}
