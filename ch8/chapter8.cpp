********************************************
        Searching and Sorting Arrays
********************************************
Concept:
>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  >>  Search Algorithm  <<
<<<<<<<<<<<<<<<<<<<<<<<<<<<<
            -- a method of locating a specific item in a larger collection of data


////////////////////////
//   Linear Search   //
////////////////////////

    -- uses a loop to sequentially step through the array starting with the first element
    -- compares each element with the value being searched for
                oo    stops when the value is found or end of array
    -- returns -1 if no value is found in the algorithm
                oo    (because -1 is not a valid subscript)

params:
    int arr[]   // array to be searched
    int size    // size of arr
    int value   // value to search for

int linearSearch (const int arr[], int size, int value)
{
    int index = 0;          // used as a subscript to search the array
    int position = -1;      // to record the position of the search value
    bool found = false;     // flag to indicate if the value was found

    while (index < size && !found)
    {
        if (arr[index] == value)
        {
            found = true;       // set the flag
            position = index;   // record the value's subscript
        }
        index++;
    }
    return position;
}



::::Advantages::::

    -- simple to understand
    -- doesn't require data to be stored in any particular order


::::Disadvantages::::

    -- inefficient
            oo  in large arrays (think 50,000+), it would have to search through every element
            oo  on average, elements are just as likely to be near the beginning as the end
    -- If an array as N items, the linear search will locate an item in N/2 attempts
            oo  50,000/2 = 25,000 iterations to find the item on average(if it is even in the array!)
            oo  max attempts = N = 50,000 iterations!

    *** should not be used on very large arrays



/////////////////////////
//    Binary Search    //
/////////////////////////

    -- requres the array be sorted in order
    -- starts with the element in the middle
            oo  compares to see in what half of the array the value falls
    -- if the desired value wasn't found, procedure is repeated and the middle value
            of the desired half is searched again and compared
    -- repeated until the value is found or the search yields no results


    *** in this way, half of the data is eliminated every search
    

    (3) index variables:
            - first     \___ mark the boundaries of the portion of the array currently being searched  
            - last      /
            - middle  ------- halfway point is calculated and stored in this var


params:
    int array[]   // array to be searched
    int numElems    // size of arr
    int value   // value to search for


int binarySearch(const int array[], int numElems, int value)
{
    int first = 0,              // first array element
        last = numElems - 1,    // Last array element
        middle,
        position = -1;          // position of search value
    bool found = false;

    while (!found && first <=last)
    {
        middle = (first + last) / 2;    // calculate midpoint
        if (array[middle] == value)     // if value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (array[middle] > value)     // if value is in lower half
            last = middle -1;
        else                                // if value is in the upper half
            first = middle + 1;
    }
    return position;
}



:::: Advantages ::::
     -- much more efficient than the linear search
     -- y = 2^n ; where 
                y = number of elements that can be searched
                n = the number of searches
        eg)
            2^(16) = 65,536
                oo  you can search through 65,536 elements in just 16 searches!


>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 >>  Sorting Algorithms <<
<<<<<<<<<<<<<<<<<<<<<<<<<<<<

    -- technique for stepping through the an array and rearranging its contents in some order
    -- ascending / descending order



/////////////////////////
//     Bubble Sort     //
/////////////////////////

    -- as it makes passes through and compares the elements of the array,
            certain values "bubble" toward the end of the array with each pass.

params:
    array[] // array to sort
    size    // size of the array

void bubbleSort(int array[], int size)
{
    int maxElement;
    int index;

    for(maxElement = size -1; maxElement >  0; maxElement--)        // start at the last element and work your way to the beginning of the array
    {
        for (index = 0; index < maxElement; index++)                // for every index until the last element
            {
                if (array[index] < array[index + 1]                 // 
                        {
                            swap(array[index], array[index+1]);
                        }
            }
    }
}

:::: swap() ::::
   -- need to declare a third variable to use a temporary storage location in memory

void swap(int &a, int &b)           // need to use reference variables in order to
{                                   // change the values
    int temp = a;
    a = b;
    b = temp;
}



        ** simple but inefficient
                oo  values move by only one element at a time toward their final destination

/////////////////////////
//    Selection Sort   //
/////////////////////////

    -- moves items immediately to their final position in the array
    -- searches through the array and finds the smallest value and moves it to the start
    -- goes to the next spot and searches for the next smalles value and moves it to element 1
    -- continues until it finishes

void selectionSort(int array[], int size)
{
    int minIndex, minValue;                         // declare vars for smallest index and smallest value

    for (int start = 0; start < size-1; start++)   // begin at first element and go until last element
    {
        minIndex = start;                  // initialize smallest to starting value and starting index
        minValue = array[start];
        for (int index = start + 1; index < size; i++) // start search as the next sequential element until end
            if (array[index] < minValue)            // if current position is smaller than smallest 
            {
                minValue = array[index];            // remember value and index and continue until end
                minIndex = index;
            }
        swap(array[minIndex], array[start]);        // swap starting value with the smallest
    }               // repeat until every element is sorted by incrementing the start var
}
