#include <iostream>
#include <string>

using namespace std;

int numChars(char search, string str, unsigned int subscript);

int main()
{
    unsigned int index = 0;
    string str = "abcddddef";

    // display the number of times the letter 'd' appears
    cout << "The letter d appears " << numChars('d',str, index)
        << " times.\n";


    return 0;
}

int numChars(char search, string str, unsigned int subscript)
{
    if (subscript >= str.length())
    {
        // base case: end of the string is reached
        return 0;
    }
    else if (str[subscript] == search)
    {
        // recursive case: a matching char was found.
        // return 1 + the number of times the search
        // char appears in the rest of the string
        return (1 + numChars(search, str, subscript+1));
    }
    else
    {
        // recursive case: a matching character was found
        // return 1 + the number of times the search
        // character appears in the rest of the string
        return numChars(search, str, subscript+1);
    }
}
