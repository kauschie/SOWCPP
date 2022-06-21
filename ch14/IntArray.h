#include <iostream>
#include <cstdlib>  // for the exit function
using namespace std;

class IntArray
{
    private:
        int *aptr;                  // ptr to the array
        int arraySize;               // holds the array size
        void subscriptError();       // Handles the invalid subscripts
    public:
        IntArray(int);                  // constructor
        IntArray(const IntArray &);      // copy constructor
        ~IntArray();                    // destructor

        int size() const                // returns array size
            { return ArraySize; }       

        const IntArray operator=(const IntArray &); // Overloadd = operator
        int& operator[](const int &);               // overloaded [] operator
};

IntArray::IntArray(int s)
{
   arraySize = s;
   aptr = new int[s];
   for (int count = 0; count < s; count++)
       *(aptr + count) = 0;
}

IntArray::IntArray(const IntArray &obj)
{
    arraySize = obj.arraySize;
    aptr = new int[arraySize];
    for (int count = 0; count < arraySize; count++)
        *(aptr + count) = *(obj.aptr + count);
}

IntArray::~IntArray()
{
    if (arraySize > 0)
    { delete [] aptr;
        aptr = nullptr; }
}

void IntArray::subscriptError()
{   
    cout << "ERROR: Subscript out of range.\n";
    exit(0);
}

const IntArray IntArray::operator=(const IntArray &right)
{
    if (this != &right)
    {
        delete [] aptr;
        arraySize = right.arraySize;
        aptr = new int[arraySize];
        for (int i = 0; i < arraySize; i++)
        {
            aptr[i] = right.aptr[i];
        }
    }
    return *this;
}

int& IntArray::operator[](const int& sub)
{
    if (sub < 0 || sub > arraySize)
        subscriptError();
    return aptr[sub];
}


int main()
{

    const int SIZE 10;  // array size
    Intarray table(SIZE);

    // Store values in the array
    for (int x = 0; x < SIZE; x++)
        table[x] = (x * 2);
    
    for (int x = 0; x < SIZE; x++)
        cout << table[x] << " ";
    cout << endl;
    
    for (int x = 0; x < SIZE; x++)
        table[x] = table[x] + 5;

    for (int x = 0; x < SIZE; x++)
        cout << table[x] << " ";
    cout << endl;

    for (int x = 0; x < SIZE; x++)
        table[x]++;

    for (int x = 0; x < SIZE; x++)
        cout << table[x] << " ";
    cout << endl;

    return 0;
}
