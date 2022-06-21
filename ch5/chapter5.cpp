*********************************
 Increment / Decrement Operators
*********************************

***Increment***

num = num + 1;          ==          num--   or   --num
num += 1;

// whatever the value of num is, add one to it
// 
//  Standard form for a counter / accumulator
//
// variable = variable + delta;
// 

***Decrement***

num = num - 1;          ==          num--   or   --num
num -= 1;

Postfix vs Prefix

num++ is different from ++num

num++ does the addition after the expression finished executing
++num does the addition before the expression finishes executing



**** Operand of ++ and -- needs to be an lvalue
        c = ++(a*b);        // ERROR!


*********************************
  Using ++ and -- in arithmetic
*********************************

the increment and decrement operators can also be used on variables in mathematical expressions.

a = 2;
b = 5;
c = a * b++;
cout << a << " " << b << " " << c;

--------displays--------

        2 6 10

------------------------

the +1 doesn't occur until after the expression is finished evaluating


*********************************
  Using ++ and -- in relations
*********************************

x = 10;
if (x++ > 10)
    cout << "x is greater than 10.\n";

      /* (1) The value is tested to determine if it is greater than 10
       * (2) x is incremented
       *
       * Because the increment operator is used in postfix mode, the comparison happens first
       * and the expression evaluates to false
       */


*********************************
        The while loop
*********************************

    2 parts:
        (1): An expression that is tested for a true or false value
        (2): a statement or block that is repeated as long as the expression is true


~~~Syntax~~~

while (expression)              <------ loop header
    statement;                  <-----  body of the loop and a conditionally executed statement


while (expression)
{
    statement1;
    statement2;
    ...
}

while (number<5)                    // number is the ** Loop control variable **
{                                   //    -- it controls the number of times that the loop iterates
    cout << "Hello\n";
    number++;                       // number is also a counter
}

        /* Notes on the while loops:
         *          -- the while loop is known as a   pretest   loop
         *                  -tests its expression before each iteration
         */

/*****************************************
 * Rules for using WHILE statements
 * (1) - boolean expression should be true the first time
 * (2) - something should change the boolean expression within the loop
 * (3) - preserve any kind of input data by using a counter
******************************************/

--------------
Infinite Loops
--------------
    -- Loops that do not have a way of stopping
            * loops must contain within themselves a way to terminate
   

----------------
input validation
----------------

cout << "Enter a number between 1-100: ";
cin >> number                                       // ~~ Priming Read - provides first value to test
while (number<=1 || number>=100)
{
    cout << "Error: Enter a value in the range 1-100: ";
    cin >> number;
}



        Example of a    /*   USER CONTROLLED LOOP     */


 
----------------
Counters
----------------

    A counter is a variable that is regularly incremented or decremented 
        each time a loop iterates.

        ** variables defined inside a function have no guaranteed starting value




*********************************
        The do while loop
*********************************


    ** the do while loop is a posttest loop
            -- its expression is tested after the first and each subsequent iteration


//      syntax          \\

    do
        statment;
    while (expression);


    do
    {
        statement1;
        statement2;
        ...
    } while (expression);          //       <------------- must be terminated with a semicolon


//      end syntax      \\

             * do while loops execute AT LEAST once
             * hits the block immediately and then tests (post test)
             * everything a while loop can do, a do-while can do as well
             * excellent for <<< input validation >>>



*********************************
          The for loop
*********************************

    - ideal for performing a known number of interations


two different kinds of loops

    /* 
     * Conditional Loops - executes as a long as a particular condition occurs
     
     * Count Controlled Loops - a loop that repeats itself a specific number of times
    */
    ** Count Controlled Loops require: **
           1. Initialize a counter variable to a starting value
           2. Test the counter variable by comparing it to a maximum value.
                    - when it reaches the max value the loop terminates
           3. It must update the counter variable each iteration
                    - generally by incrementing the variable

        The for loop specifically designed as a count controlled loop

            - the for loop is a pretest loop

//          Syntax          \\

        for (initialization; test; update)          // Loop Header
            statement;

        for (initialization; test; update)          // Loop Header
        {
            statement1;
            statement2;
            ...
        }

//          end syntax      \\

            /*
             * initialization expression
             *      - normally used to initialize a counter variable to its starting value
             *              note: this is only done once
             *  
             * test expression
             *      - expression that controls the execution of the loop as long as it's true
             *      - *pretest loop* so the expression is evaluated first before the loop begins
             *
             * update expression
             *      - executes at the end of each iteration.
             *      - typically this expression increments the loop's counter variable
             */


:::Example:::

    (1): Perform the initialization
      |
      |     (2): Evaluate the test expression (true = step 3, false = terminate loop)
      |          |
      |          |
for (count = 0; count < 5; count++)
    cout << "Hello" << endl; |   <------------ (3): execute the body of the loop
                             |
                             |
                            (4): perform update expression and go to (2)


**************************************************************
     using the for loop versus the while or do while loop
**************************************************************

    use the for loop:
        * in any situation that clearly requires an initialization
        * uses a false condition to stop the loop
        * and requires an update to occur at the end of each loop iteration
    


    certain while loops can be made into for loops:


    int num = MIN_NUMBER;   // ( initialization )
    while (num <= MAX_NUMBER) //  (test expression)
    {
        cout << num << "\t\t" << (num * num) << endl;
        num++;      // update expression
    }


         :::This is the same as:::


         while (num=MIN_NUMBER; num<=MAX_NUMBER; num++)
            cout << num << "\t\t" << (num * num) << endl;


    ~~Defining a variable in the for loop~~
        defining a variable is possible in the initialization expression
                ** beware of it's scope. it will be unavailable outside the loop


    for (int count = 1; i <=10; i++)
        cout << count << endl;
    cout << "count is now " << count << endl;       //      error



    :::using multiple variables in a for statement:::
    
    int x, y;
    for (x = 1, y = 1; x <= 5; x++, y++)
    {
        cout << x << " plus " << y
            << " equals " << (x+y)
            << endl;
    }


    :::: eliminating terms in the for loop:::::

    int num = 1;
    for ( ; num <= maxValue; )
    {
    num++;
    }
    

    ~~ Running Total
            
            - sum of numbers that accumulates with each iteration of a loop. The variable used to
                keep the running total is called an  <<  accumulator  >> 

    
    ~~ Sentinel
        
            - a special value that marks the end of a list of values
            - signals that there are no more values to be entered.
            - when the loop encounters the sentinel, the loop terminates

    

**************************************************************
                    When to use each loop 
**************************************************************

:::: while loop ::::
    - pretest conditional loop
    - ideal in situations where you do not want the loop to iterate if
            the condition is false from the beginning
    ex)
        - validating input that has been read
        - reading lists of data determined by a sentinel value

:::: do-while loop ::::
    - postest conditional loop
    - ideal in situations where you want the loop to iterate at least once
    ex)
        - repeating a menu

:::: for loop ::::
    - pretest loop
    - built in functions for initializing, testing and updating
    - counter variable can control the number of iterations
    ex)
        - ideal when the exact number of iterations is known


**************************************************************
                        Break / Continue
**************************************************************


    break;      

        /* breaks out of the current loop
         * if nested, only breaks out of the immediate loop
         */

    continue;

        /* causes current iteration of the loop to end immediately
         * all statements after appearance are ignored */

            while loop:
                * jumps to test expression at the top of the loop
                * if expression is true, next iteration begins
            do-while loop:
                * program jumps to test expression at the bottom of the loop
            for loop:
                * causes update expression to be executed
                * test expression is then evaluated
        

**************************************************************
                        Nested Loops
**************************************************************

    - an inner loop goes through all of its iterations for each iteration of an outer loop
    - inner loops complete their iterations faster than outer loops
    - to get total number of iterations, multiply the number of iterations of all the loops

    for (int i = 1, i <= 5, i++)
    {
        for int (j = 1, j <= 5, j++)
        {
            cout << i << " - " << j << endl;
        }
    }   // output
          /*1 - 1
            1 - 2
            1 - 3
            1 - 4
            1 - 5
            2 - 1
            2 - 2
            ...*/



    
**************************************************************
                Using Files for Data Storage
**************************************************************
    
    * When a program needs to save data for later use, it writes the data
         in a file. The data can then be read from the file at a later time.

    * eg. word processors, image editors, games, spreadsheets, web browsers (cookies)

    :: Output File :: 
        - a file to which data is written
        ** writing/saving data to disk
        - copies data from variables in RAM to the file

    :: Input File ::
        - file in which data is read
        * reading data from the file
        - copies data from the file into a variable in RAM

Three steps must be taken when a file is used by a program
    (1) Open the file
            - creates a connection between the file and the program
            - opening an output file usually creates the file and allows
                    the program to write to it
            - opening an input file allows the program to read data
                    from the file
    (2) Process the file
            - read data from file
            - write data to file
    (3) Close the file
            - after the program is finished with the file
                it must be << closed >> 
            - closing a file disconnects the file from the program

    *   Need to         #include <fstream>
            
        <fstream> defines data types for :
                << ofstream >>  - output file stream
                    (creating a file and writing to it)
                << ifstream >> - input file stream 
                    (want to open an existing file and read from it)
                << fstream >> - file stream 
                    (open files for reading, writing or both)

    *   Need to declare one of these objects   
            - the object is "linked" with an actual file on disk
            - the operations that may be performed depend on
                    the data type chosen

**************************************************************
                           Types of Files 
**************************************************************

    * 2 Types of Files:
        (1) Text

            - contains data that has been encoded in text
            - eg ASCII or Unicode
            - if the file contains numbers they are stored as 
                    a series of characters
            - may be opened in a text editor

        (2) Binary
            - contains data that hasn't been converted to text.
            - cannot view with a text editor

    * FILE ACCESS METHODS 

    - sequential-access file
            - you access data from the beginning to the end
            - cannot jump around
            - think cassette tape

    - random-access file
            - can jump directly to any piece of data without
                    reading the data before it
            - think cd player or mp3 player

    * File Stream Object
        - an object that is associated with a specific file
        - provides a way for the program to work with that file
        - called a "stream" object because a file can be
            thought of as a stream of data
        - stream of data may be sent to cout and displayed on screen
        - may be sent to file stream object which writes data to file (like cin)
        

 
**************************************************************
           Creating a File Object and Opening a File
**************************************************************

    * file stream object must be created
    * file must be opened and linked to the file stream object
    
    ifstream inputFile;                 // defines an ifstream type object
    inputFile.open("Customers.txt");    // calls the object's {open()} member function
                       //   the {open} function opens the Customers.txt file and
                       //   links it with the inputFile object
                       //   after this code executes, you will be able to use
                       //   inputFile object to read data from the Customers.txt file

    ofstream outputFile;                // defines an ofstream type object and calls it outputFile
    outputFile.open("Employees.txt");   // calls outputFile's open member function with
                            // the string "Employees.txt" as an argument
                            // at this point Employees.txt is created and links it with the 
                            // outputFile object
                            // after this executes, you can use outputFile object to write
                            // data to Employees.txt
            // NOTE ** If the file already exists.. the existing file will be deleted and a new one
            //          will be created with the same name
                    
        * can use absolute file path in file argument

    single line declarations:
        ifstream inputFile("Customers.txt");
        ofstream outputFile("Employees.txt");

            
    
**************************************************************
                       Closing a file
**************************************************************

    * program's files are automatically closed when the program shuts down
    * good practice to write statements to close them for 2 reasons:
                (1) most OS's store data in a << file buffer >> before 
                        it's written to file.                    ::file buffer:: 
                            - small holding section of memory to which file-bound
                                data is first written. When buffer is full the data is 
                                written to disk. 
                    <^> closing the file causes any data in the buffer to be written
                (2) some OS's limit the number of files open at one time
       
    
    inputFile.close()       // calling the {close()} member function closes the file


**************************************************************
               Writing data to a File
**************************************************************

    * use the stream insertion operator (<<)

    outputFile << "Hello World!\n"
    

**************************************************************
               Reading Data from a File
**************************************************************

    * use the stream extraction (>>) operator 

    outputFile >> name;

    
    File data is read oneline at a time
        the << read position >> is just after the '\n' character

    data stored to files is encoded as text using a scheme such as ASCII or Unicode
        - data stored as number are actually stored as text

    >> operator automatically converts text to numeric data



**************************************************************
               Detecting the End of the File
**************************************************************
    
    /* most of the time you don't know when the end 
               of the file is going to be when reading a file
     * error will occur if the program attempts to read beyond the end of the file
     * ( >> ) operator not only reads data but returns a true or false value
                indicating whether the data was succesfully read


    while ( inputFile >> inputVariable )
        {
            does stuff while true
            terminates loop when EOF is reached as the result is fale
        }
    */

**************************************************************
               Detecting File Open Errors
**************************************************************
    * file may not always exist or open
    * if (inputFile) 
    *       // File Object returns bool true if 
    *           //the file was opened successfully
    *       // 
    * if (inputFile.fail())
    *   // fail() member function returns true if the file 
    *  //             failed to open
    *  you shuold always test to make sure the file was opened correctly
    *       - user should be informed if the file could not be opened

