/*********************************************************
/
/           Arrays and Vectors 
*********************************************************/

    ** Arrays hold multiple values of the same data type

    type name[#];
    (eg)
        int days[6];

    days - name of the array
    6 - array size declarator (the number of elements)

    # declarator must be a constant integer expression with a value greater than 0

            -- literal or named constant

    size of the array = size of an individual element * number of elements



//  Individual elements of an array are assigned unique subscripts that
//  are used to access the array
    
        * subscripts always start with 0


you can use variables to represent array elements
eg.
    const int MAX_NUMBER = 6;
    int intArr[MAX_NUMBER];
    
    for (int counter = 0; count < MAX_NUMBER; count++)
        cout << intArr[count] << endl;

    *** loops over count and uses counter variable to represent the array indices 


// Array Initialization


    const int MONTHS = 12;
    int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; <--- array initialized

                        ** initialization list
    // partial array initialization
    //

    int days[7] = {1, 4, 6};

                /// *** INCORRECT *****   int days[7] = {1,,,5,7,,};


// Implicit Array Sizing
//
    ** The size declarator can be omitted if an array initialization list is provided

    int days[] = {1,2,3,4,5};

        -- days would be initialized to have 5 elements



// writing contents from an array:
//
 outputFile.open("outputFilePathHere.txt");
 for (count = 0; count < ARRAY_SIZE; count++)
      outputFile << array[count] << endl;

// reading contents from an array:

    while (count < ARRAYSIZE && inputFile >> array[count])      // check if out of bounds of array
        count++;                    // inputFile >> array[count] returns false if EOF so it
                                    // executes (writing line to array element) and if true count++



***********************************
        No  Bounds Checking
***********************************

    ** c++ does not prevent you from overwriting an array's bounds
    
    writing subscripts beyond the boundaries of an array
        int intArr[5];
        intArr[6] = 1;  // this element does not exist but c++ allows the program to write beyond
                        // the bounds




***********************************
    Watch for off-by-one Errors       
***********************************

    // this code has an off-by-one error
    int numbers[100];
    for (int count = 1; count <= 100; count++)
        numbers[count] = 0;                         // does not write numbers[0]
                                                    // mistakenly writes to numbers[100]
                                                    //      which DOES NOT EXIST




***************************************
    Range-based     FOR     loop
***************************************

// syntax \\

for (dataType rangeVariable : array)
    statement;
    

    --or--

for (dataType rangeVariable : array)
{
    statement1;
    statement2;
    ...
}

// end - syntax \\


        dataType :  data type of the range variable.
                ** This must match the data type of the array elements

        rangeVariable : name of the range variable
                  -- receives the value of a different array element during each loop iteration

        array : name of an array on which you wish the loop to operate
                -- loop iterates once for every item in the array

example:

    int numbers[] = {3, 6, 9};          // implicit declaration
    for (int val : numbers)             // range based for loop
        cout << val << endl;                    



***************************************************
    Modifying an Array with a Range-Based for Loop
***************************************************

    -- range variable only contains a copy of an array element
            ** Need to declare the range variable as a reference

        int numbers[5];
        for (int &val : numbers)
        {
            cout << "Enter an integer value: ";
            cin >> val;
        }
    
***************************************************
  Range based for loop    VS    regular for loop
***************************************************
    range based for loop
        
            ** use when you need to step through the contents of an array

    regular for loop

            ** use when you need the subscript for some purpose



-- Array elements are processed just like any other variable
            amount[count--];
            amount[count]++;
            ++amount[3];
            amount[2]--;



***********************
array without brackets
***********************

    seen as the array's beginning memory address

    
oldValues[4] = {1,2,3,4};
newValues[4];
    newValues = oldValues       //   WRONG!!!!!!!!

    ****you cannot copy arrays like this****

    newValues referrs to the array's starting memory address (e.g. 8012)
    oldValues referrs to its own starting memory address (e.g. 8020)

    does not work because you cannot change the starting memory address of the array


**************************
summing values in an array
**************************

int total;                  // initialize accumulator outside of loop
for (int val : arrayName)
    total += val;



**************************
Partially filled arrays
**************************

    * array size is not always known at the time of initialization
    * use a counter when adding data to the array to keep track of how many vars are added
    * use sentinel value to mark the end of the array
    * in conditional statement, make use of short circuit evaluation


**************************
  Using parallel Arrays
**************************

    * By using the same subscript, yo can build relationships between 
    *       data stored in two different arrays

    e.g. two related arrays for payroll
    (1) hours worked for each employee
    (2) pay rate for the employee

    int hourse[NUM_EMPLOYEES];
    double payRate[NUM_EMPLOYEES];
    for (int index = 0; index < NUM_EMPLOYEES; index++)
        double grossPay = hours[index] * payRate[index];



*****************************
Arrays as function arguments 
*****************************

    *   pass the name of the array
    *   function accepts the array with paramater defined like so:
           
           void showValue(int arrayNameHere[], int arraySize); // prototype
           int main()
           {
              showValue(numArray, 8)
           }

    * Array is passed by reference
    * address of numArray is being copied into the arrayNameHere parameter
     

    //      Use  << const >>  keyword in declaration to prevent changes to an array      \\
    //
    //      void showValue(const int nums[], int size)
    //      {
    //          statements;
    //      }
    //
    

    *  attempting to modify an array declared const will throw compile time errors




*****************************
    Two Dimensional Arrays
*****************************
    
    * AKA 2D Arrays
    * Several identical arrays put together
    * useful for storing multiple sets of data
    
    int scores[3][3];

    scores[0][0] scores[0][1] scores[0][2]      // think of it as rows and columns
    scores[1][0] scores[1][1] scores[1][2]
    scores[2][0] scores[2][1] scores[2][2]

    * usually step through with nested loops


   initializing 2D arrays:

        int hours[3][2] = {{8.5}, {7,9}, {6,3}}

                --      OR      --
        int hours[3][2] = {{8,5},           // extra braces that separate rows are not required
                            {7,9},          // recommended to use them
                            {6,3}};

        hours[0][0] == 8
        hours[0][1] == 5
        hours[1][1] == 9
        hours[2][0] == 6
        and so on


*******************************
Passing Two Dimensional Arrays
*******************************

    **  parameter type must contain a size declarator from the number of columns
    **  if using a var is should be a global const so that the prototype has access to it
    **  parameter for cols should be in prototype and definition header

    void showArray(const int numbers[][COLS], int rows);


*******************************
   Summing across two arrays
*******************************

    ** switch vars in nested loops to sum across columns vs rows

    eg)

    double scores[num_students][num_scores]
    
    for (int col = 0; col < num_scores; col++)    // this averags class grade for each test
        total = 0;
        for (int row = 0; row < num_students; row++)
            total += scores[row][col];
        
    for (int row = 0; row < num_students; row++)
        total = 0;
        for (int col = 0; col < num_scores; col++)
            total += scores[row][col];                  // this averages test grades for each student


*******************************
     3D arrays and beyond 
*******************************

    * No limit to the dimensionality of an array
    
    double seats[3][5][8]
        -- 3 pages or sets of
                -- 5 rows and
                        -- 8 columns

    ** When writing function that accept multi-dimension arrays as arguments,
            all but the first dimension must be explicitly stated in the parameter list



    
*******************************
        THE STL VECTOR
*******************************

    ** Standard Template Library (STL) offers vector type

    * a vector holds a sequence of values or elements
    * stores its elements in contiguous memory locations
    * can use the subscript operator [] to read individual elements
    * DO NOT HAVE TO DECLARE THE NUMBER OF ELEMENTS THAT THE VECTOR WILL HAVE
    * if you add a value to a vector that is already full, it resizes itself
    * vectors report the number of elements they contain
    * cannot use [] to access an element that doesn't exist

    <<<<    NEED TO #include <vector>     >>>>


    //       Definition      \\

    vetor<int> numbers;

    // no need to define a size but you can if you like

    vecor<int> numbers(10);     // Note the >>>> parens () <<<<  and NOT square brackets []


    // Can also specify an initialization value for the array:
    
    vector<int> numbers(10, 2);     // creates vector of size 10 and initializes each element to 2


    vector<int> numbers { 10, 20, 30, 40};  // 4 element vector with initialized list of values

                    // notice the braces and there is NO ASSIGNMENT OPERATOR

    //        End Definition      \\
    

    Storing and reading elements:

    cout << numbers[0];     // 10 from above

    numbers[3] = 25;        // numbers is {10, 20, 30, 25}



*******************************
    Vector with for loop
*******************************
    vector<int> numbers(5);             // Range Based For Loop
    for (int &num : numbers)        // uses a reference variable to modify vector elements
        cin >> num;
    for (int num : numbers)         // range based for loop
        cout << num;



*******************************
     push_back 
*******************************

    * pushes(adds) the value onto the back of the vector
    * creates a new element if the vector doesn't have a starting size or is full

    vector<int> numbers {5, 10, 15, 20};
    numbers.push_back(25);              // stores the value 25 as the last element in numbers
    for (int i = 0; i < 5; i++)
        cout << numbers[i] << " ";      // displays: 5 10 15 20 25



    vector<int> numbers;
    for (int i = 1; i < 6; i++)         // numbers = {1, 2, 3, 4, 5}
        numbers.push_back(i);

        
*******************************
        Size of an array 
*******************************

    * vectors can report the number of elements they contain
    * .size() member function
    
    numValues = numbers.size();     // numValues contains the number of items in the set

    void showValues(vector<int> vect)                   // func acceps vector as param
    {
        for (int count = 0; count < vect.size(); count++)   // uses .size() to determine length of loop
            cout << vect[count] << endl;
    }



    


