*****************************
        POINTERS
*****************************

    Concept:
        
        The address operator (&) returns the address of a variable

            -- each byte of memory has a unique << address >> 
            -- a variables address is the address of the variables first byte

 
:::::::::::::::::::
 Pointer Variables
:::::::::::::::::::

    * data type to hold memory addresses
        o shortened to just 'pointers'
        o can indirectly manipulate data utilizing them

    -- identify specific locations in the computer's memory
    -- "points" to some piece of data stored in computer's memory

    similar to arrays and reference variables

    similar to reference variables but operate at a lower level
        -- c++ does not automatically do as much work for you

    - need to write code that fetches memory address and store it in pointer variable
    - code should specify that the value should be stored in the location referenced
            by the pointer and not the pointer variable itself

    common scenarios of use:
            - dynamic memory allocation
                    o writing a func that needs to work with an unknown amount of data
                    o allows you to create complex data structs in memory while program is running
            - useful in algorithms that manipulate arrays / certain types of strings
            - used in OOP for creating and working with objects and sharing access to those objects


// Definition \\

    int *ptr;

    -- or --

    int* ptr;       // should not go uninitialized

    int* ptr = nullptr;     // initialize to NULL or 0 if using a compiler before C++11


//  End  def  \\

        -- (*) indicates that ptr is a pointer variable
        -- int datatype indicates that ptr can be used to hold the address of an integer

        "pointer to an integer variable"



        NEVER a good idea to to define without initializing it
            
            -- if you inadvertantly use an uninitialized pointer variable,
                    you will be affecting some unknown location in memory
        
        THEREFOR, good idea to initialize point variables with the special value nullptr



::::::::::::::::::::::
assigning values to ptr
::::::::::::::::::::::


    int x = 25;
    int* ptr = nullptr;

    ptr = &x;           // assigns the address of x to the pointer ptr
    cout << *ptr << endl;  // displays 25  (the value of x
    cout << ptr << endl; // displays 0x61fe14


::::::::::::::::::::::::::
indirection operator (*)
::::::::::::::::::::::::::

        (*)  << defrefereces >> the pointer
        
                -- when a variable is dereferenced, you are working with the VALUE the ptr is pointing to
                -- 0x61fe14
                


examples:

    ptr = &x;       // assigns the address of x to ptr
    *ptr += y       // increments x by y
    ptr = &y;       // assigns address of y to ptr
    



*********************************************
  Relationship between Arrays and Pointers
*********************************************

    Concept:

        Array names can be used as pointers, and pointers can be used as array names

>>> Array names are really pointers   <<<

    short numbers[] = {10, 20, 30, 40, 50};

    cout << *numbers // output is 10  so...  *(numbers+0) or number[0]
    cout << *(numbers+1) // output is 20     numbers[1]
    and so on...

    pointers dont work like regular variables in mathematical expressions...

        - actually adding the value >>>> times the size of the data type being referenced <<<<
        *(numbers+1) is actually *(numbers + 1*2)
        *(numbers+2) is actually *(numbers + 2*2) (times 2 because numbers is an array of shorts
                                                    and shorts are 2 bytes in size)

        PARENTHESES ARE CRITICAL WHEN ADDING VALUES TO POINTERS

    int numbers[1,2,3,4,5];
    int* intPtr;

    intPtr = numbers;       // notice there's no &
                                    //   array name alone is the address

    intPtr[3] = 4;      // subscripts with the pointer
    *(numbers+2) = 3;       // pointer notation with array name


:::::::::::::::::::::::::::::::
using & with subcripted numbers
:::::::::::::::::::::::::::::::


    &numbers[1]             //  gets the address of numbers[1]
    


    /* Only difference between arrays and pointers:
     *      - you cannot change the address that an array name points to
     *      - array names are <<< pointer constants  >>>
    */
     



:::::::::::::::::::::::::::
 oo Pointer Arithmetic oo
:::::::::::::::::::::::::::

    Concept:
        ** Some mathematical operations may be performed on pointers


    int set[4] = {5, 10, 15, 20};
    int* numPtr = set;              // numPtr assigned first int address of set

    cout << *(numPtr) << endl;       // outputs 5, numPtr now is the address of set[1]
    numPtr++;                            // size of one int is added to numPtr
    cout << *numPtr << endl;        // outputs 10
    numPtr--;                           // size of one int is subtracted from numPtr
    cout << *numPtr << endl;        // outputs 5
    


    ////////    valid pointer arithmetic operators      \\\\\\\\\\\\\
    
                numPtr++          numPtr--

                numPtr + 2        numPtr - 3
                
                numPtr+= 5        numPtr -= 2

                (numPtr - num2Ptr)




:::::::::::::::::::::::::::::
 oo Initializing Pointers oo
:::::::::::::::::::::::::::::

    Concept:
        -- can be initialized with the address of an existing object


    int myValue;
    int* pint = &myValue;

    int ages[20];
    int* pint = ages;

    float myFloat;
    int* pint = &myFloat        //  ILLEGAL!!!!!!!!!



    Concept:

        -- pointers can be initialized in the same statement as other variables of the same type


    int myValue, *intPtr = &myValue;        // declares intPtr on the same line as myValue
                                            // initializes it to the address of myValue 
    
    double readings[20], *marker = readings;        // initializes marker to the address of readings[0]
                                                // in the same line that readings is declared
                                                
        
    int* pint = &myValue;               // ILLEGAL!!!!!!!  int myValue; 



:::::::::::::::::::::::::::::
  xx Comparing Pointers xx
:::::::::::::::::::::::::::::

    Concept:
        -- if one address comes before another address in memory,
                the first address is considered "less than" the second


    * Elements are stored in consecutive memory locations,
    *       Address of element[1] < element[2]

    int arr[5];

    (&arr[0] < &arr[1])       //  True
    (arr < &arr[4])             // true
    (arr == &arr[0])              // true
    &arr[2] != &arr[3]              // true

    

    int numArr[] = {1, 3, 2};
    int* ptr1 = numArr[1];
    int* ptr2 = numArr[2]; 

    ptr1 < ptrs2        // compares address locations - evaluates to TRUE
    *ptr1 < *ptr2       // compares values, evaluates to FALSE


::::::::::::::::::::::::::::::::::
  xx Pointers as Func Params xx
::::::::::::::::::::::::::::::::::

    Concept: A pointer can be used as a function parameter.
                -- gives function access to the original argument
                        oo like a rerference variable

doubleValue(&number);       // function call needs to pass in the address of the variable


void doubleValue(int* number)
{                               // must use pointer!!!!
    return *number *= 2;        // if you dont use indirection operator (*) then
}                               // you are changing the address


    ***  You can also use array addresses as arguments
    

:::::::::::::::::::::::
Pointers to Constants
:::::::::::::::::::::::

const int SIZE = 6;
const double payRates[SIZE] = { 18.55, 17.45, 12.85,
                                14.97, 10.35, 18.89};

void displayPayRates(const double* rates, int size)   // notice the const double pointer*
    for (int count = 0; count < size; count++)
    {
        cout << "Pay rate is $" << *(rates + count) << endl;
    }

        const double   *rates
        \_________/    |_____|> indicates that rates is a pointer
             |
    This is what rates points to

    ** Note: because rates is a pointer to a const, the compiler will not allow us to write
                code that changes the thing that rates points to

        -in passing an address of a constant to a pointer, the pointer variable
                    must be defined as a constant as well.

        -- a pointer to a constant CAN accept the address of a nonconstant item

:::::::::::::::::::::::
 Constant Pointers
:::::::::::::::::::::::

        Pointer to Const:
            * points to a constant item
            * data that pointer points to cannot change
            * pointer can change

        VS:

        Const Pointer:
            * the pointer itself is a constant
            * cannot change once it is initialized

    eg)

        int value = 22;
        int * const ptr = &value;       // const appears AFTER the *

                -- compiler error if ptr's address changes
                -- no error if we use the pointer to change contents of (value)

         int   * const ptr
        \___/  |_____________|> * indicates that ptr is a constant pointer
          ||
    This is what ptr points to



    ** Must be initialized with a starting value

::::::: Const Ptr as a parameter :::::::


    void setToZero(int * const ptr)
    {
        ptr = 0;    // ERROR!! Cannot change the contents of a constant pointer
    }

    void setToZero(int * const ptr)
    {
        *ptr = 0;       //          works
    }


   *** can call the function multiple times with different arguments ***

    int x, y, z;

    setToZero(&x);
    setToZero(&y);
    setToZero(&z);



:::::::::::::::::::::::::::::::
 Constant Pointers to Constants
:::::::::::::::::::::::::::::::

    int value = 22;
    const int * const ptr = &value;     // note: const before and after the *

    
    void displayValues(const int * const numbers, int size)
    {
        for (int i = 0; i < size; i++)
            cout << *(numbers + i) << " ";
    }

        *** ptr is a const pointer:
                -- cannot make ptr point to anything else
        *** ptr is a pointer to const
                -- cannot change contents of value

        - CAN call this function with different arguments



*********************************************
          Dynamic Memory Allocation
*********************************************

        Concept:

            Variables may be created and destroyed while a program is running


    What if you don't know how many variables you need while running the program??

    Dynamimc Memory Allocation    
        -- allowing the program to create its own variables << "on the fly" >>

    ** Only possible through the use of pointers **
    
    - computer requests a chunk of unused memory and the computer returns back the address
    - the newly allocated memory can only by accessed through it's address



/////////////////////////
//    new   operator  //
////////////////////////
    
    int *iptr = nullptr;

    iptr = new datatype;     // operand is the datatype of the variable being created


    -- statement is requesting that the computer allocate enough memory for a new int variable
    -- value may be stored in the new variable by dereferencing the pointer:
        
        *iptr = 25;
   

    ** more practical to create an array

    iptr = new int[100];


        -- if there isn't enough free memory to accomodate the request,
                == program throws an exception and terminates the program

        -- when a program is done using a dynamically allocated chunk of memory,
                it should be released for future use

        delete iptr;    // for single variable

        delete  [] iptr;        // for an array


    *** Failure to release a dynamically allocated memory can cause a program to have a 
            MEMORY LEAK

            ex)

            void grabMemory()
            {
                const int SIZE = 100;
                // Allocate space for a 100 element array of ints
                int *iptr = new int[SIZE];
                // function ends without deleting the memory!
            }

     ** Once the program ends, the iptr variable no longer exists
                -- Memory cannot be accessed or deleted



