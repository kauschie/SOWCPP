//////////////////////////////////////////////////////////
//              ADVANCED FILE OPERATIONS                //
//////////////////////////////////////////////////////////

    Concept:
            
        A file is a collection of data that is usually stored on a computer's disk. Data can be saved
            to files and then later reused


,-:: Review of File Stream Data Types ::-,

    ifstream    ::      Input File Stream - this data type can be used only to read data from files
                                                into memory

    ofstream    ::      Output File Stream - this data type can be used to create files and write data to them

    fstream     ::      File Stream - this data type can be used to create files, write data to them, and
                                        read data from them.


***************************************
         Using Fstream Objects
***************************************

::::::::::::::
  Definition
::::::::::::::

    fstream dataFile;

::::::::::::::
   End Def
::::::::::::::


// fstream.open() function requires 2 args
//  (1)     string containing name of the files
//  (2)     file access flag that indicates the mode to access file
//
// eg.

dataFile.open("info.txt", ios::out);        // ios::out -> output mode  :   allows data to be written

dataFile.open("info.txt", ios::in);         // ios::in -> input mode    :   allows data to be read from file


**********************************************************
flag            :               action
**********************************************************

ios::app        :       Append mode. If the file already exists, its contents are preserved and all output
                            is written to the end of the file. Causes file to be created if it does not exist
                            by default.

ios::ate        :       If file exists, goes to the end of it. Output may be written anywhere in the file.

ios::binary     :       Binary mode. When a file is opened in binary mode, data are written to or read from it
                            in pure binary format.

ios::in         :       Input mode. Data will be read from the file. If the file does not exist, it will not
                            be created, and the open function will fail.

ios::out        :       Output mode. Data will be written to the file. By default, the file's contents will 
                        be deleted if it already exists.

ios::trunc      :       If the file already esists, its contents will be deleted (truncated). This is the
                            default mode used by ios::out


    Concept:

            You can combine flags with the  <<    |    >>  operator

        dataFile("info.txt", ios::out | ios::app);




   *
   *    The file contents appear as a stream of characters
   *
   *    J-o-n-e-s-\n-S-m-i-t-h-\n-<EOF>
   *
   *                              ^^^^^
   *                  Very last character is an end-of-file marker
   *


**********************************************************
    File Open Modes with ifstream and ofstream Objects
**********************************************************

    ofstream    ::  oOo - opened for output only - data can be written but not read from the file
                    oOo - if the file does not exist it is created
                    oOo - if it already exists, its contents are deleted (the file is truncated)


    ifstream    ::  oOo - opened for input only - data can be read but not written to the file
                    oOo - the file's conents will be read from its beginning.
                    oOo - if it doesn't exists, the open function fails

    
    ** 
    **   Can's change that files can only be read / written to
    **
    **   Can still supply file access flags as optional args 
    **


    ofstream outputFile;
    outputFile.open("values.txt", ios::out|ios::app);   // specifies to append to existing contents


**********************************************************
    Checking for a File's Existence before Opening It
**********************************************************

    fstream dataFile;
    dataFile.open("values.txt", ios::in);
    if (dataFile.fail())
    {
        dataFile.open("values.txt", ios::out);
        // continue to process..`
    }
    else    // the file already exists
    {
        dataFile.close();
        cout << "The file values.txt already exists.\n";
    }


**********************************************************
              Opening file from definition
**********************************************************

fstream dataFile("names.txt", ios::in | ios::out);
ifstream inputFile("info.txt");
ofstream outputFile("addresses.txt");
ofstream dataFile("customers.txt", ios::out | ios::app);

        // you can still test for errors using this technique (eg)


    ifstream inputFile("SalesData.txt");
    if (!inputFile)
        cout << "Error opening SalesData.txt\n";



**********************************************************
              File Output Formatting
**********************************************************

    Concept:
        
        File output may be formatted the same way that screen output is formatted

        (eg)
            outputFile << fixed << setprecision(2);


**********************************************************
         Passing File Stream Objects to Functions
**********************************************************

    Concept:
            
        File stream objects may be passed by reference to functions

            * should always be passed by reference

    bool openFileIn(fstream &file, string name)
    {
        bool status;
        file.open(name, ios::in);
        if (file.fail())
            status = false;
        else
            status = true;
        return status;
    }


**********************************************************
             More Detailed Error Testing
**********************************************************

    Concept:

        All stream objects have error state bits that indicate the condition of the stream

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Bit                 Description
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ios::eofbit            Set when the end of an input stream is encountered
 ios::failbit           Set when an attempted operation has failed
 ios::hardfail          Set when an unrecoverable error has occured
 ios::badbit            Set when an invalid operation has been attempted
 ios::goodbit           Set when all the flags above are not set. Indicates stream is in 
                        good condition.


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Function            Description
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 eof()              Returns true (nonzero) if eofbit flag is set, o/w returns false
 fail()             Returns true (nonzero) if the failbit or hardfail bits are set, o/w false
 bad()              Returns true (nonzero) if badbit flag is set, o/w returns false
 good()             Returns true (nonzero) if the goodbit flag is set, o/w returns false 
 clear()            When called with no args - clears all flags listed above. Can also be called
                    with a specific flag as an argument

**********************************************************
     Member Functions for Reading and Writing Files
**********************************************************

    Concept:

        File stream objects have member functions for more specialized file 
            reading and writing

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    getline() member function
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    - reads an entire line of text
    - can optionally include a delimiter
    - see program12-9.cpp

    getline(dataFile, str, '\n');

    dataFile - file stream object
    str      - data read from the file will be stored here
    '\n'     - delimiter that causes function to stop reading
                   default is '\n' but it can be anything


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    get() member function
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    - reads a single character from the file
    - reads whitespace 
    - see program 12-10.cpp

    inFile.get(ch);

    ch - a single char is read from the file into this character variable


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    put() member function
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    - writes a single charater to the file
    - see program12-11.cpp

    outputFile.put(ch);

    ch - a char variable



*************************************
     Working with multiple files
*************************************

    Concept:
    
        It's possible to have more than one file open at once in a program

    * do so by defining multiple filestream objects

    istream file1, file2, file3;


*************************************
             Binary Files
*************************************

    Concept:

        Binary files contain data that is not necessarily stores as ASCII text


    ~~ opening a file in binary mode ~~

    file.open("stuff.dat", ios::out | ios::binary);     // both output and binary mode
    


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    write and read member functions
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    ------------------------
    write() member function:
    ------------------------
        * used to write binary data to a file

    fileObject.write(address, size);

    fileObject  - name of the file stream object
    address     - starting address of the section of memory that is to be written to the file
                - this address is expected to be the address of a char or a pointer to a char
                - (cast the object to a char if needed)
    size        - the number of bytes to write to memory. The argument must be an integer value

    
    ( eg's )
    
    char letter = 'A';
    file.write(&letter, sizeof(letter));    // size of datatypes vary on systems, best to use sizeof operator

    char data[] = {'A', 'B', 'C', 'D'};
    file.write(data, sizeof(data));




    ------------------------
    read() member function:
    ------------------------
        *  used to read binary data from a file into memory

    fileObject.read(address, size);

    fileObject  - name of the filestream object
    address     - starting address of the section of memory where the data being read from the file
                    is to be stored
                - this address is expected to be the address of a char (or a pointer to a char)
    size        - number of bytes of memory to read from the file. This argument must be an int value

    ( eg's )

    char letter;
    file.read(&letter, sizeof(letter));

    char data[4];
    file.read(data, sizeof(data));


    ((( program12-13.cpp )))


    
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
writing data other than char to binary files
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    read() and write() both expect first arg to be pointer to char

    you must type cast other variables 

    reinterpret_cast<dataType>(value)

        where:
            dataType - the data type that you are converting to
            value    - the value that you are converting

    ( eg )  // int -> char
    
    int x = 65;
    char *ptr = nullptr;
    ptr = reinterpret_cast<char *>(&x);

    // using type cast to pass the address of an int as the first argument to write()
    
    file.write(reinterpret_cast<char *>(&x), sizeof(x));    // contents of x will be written to a binary file

    ( eg ) // int array -> char and write to binary file

    int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    file.write(reinterpret_cast<char *>(numbers), sizeof(numbers));

        // read int array from binary file

    int numbers[10];
    file.read(reinterpret_cast<char *>(numbers), sizeof(numbers));

    ((( see program12-14.cpp )))


***************************************
    Creating Records with Structures
***************************************

    Concept:

        Structures may be used to store fixed-length records to a file


    Note: You should always open files in binary mode to store data structures

   Note2: Structures containing pointers cannot be correctly stored to disk using these techniques
            -- if the structure is read into memory on a subsequent run, it cannot be guaranteed
                that all program vars will be at the same memory locations

  Note3: Strings contain implicit pointers so strings cannot be part of any structs

~~~~~~~~~
  Field  :  An individual piece of data pertaining to a single item
~~~~~~~~~

~~~~~~~~~
  Record  :  A complete set of data about a single item made up of fields
~~~~~~~~~


struct Info             // record`
{
    char name[51];          // field
    int age;
    char address1[51];
    char address2[51];      // field
    char phone[14];
};


Info person1;       // then once all the fields are populated with data the entire var
                    // can be written to disk using the write function
    file.write(reinterpret_cast<char *>(&person1), sizeof(person1));
    


***************************************
        Random Access Files
***************************************

    Concept:
        
        Random access means nonsequentially accessing data in a file

~~~~~~
review
~~~~~~

    all programs so far have been performing <<< sequential file access >>>
        -- files that are opened begin reading or writing at the beginning of the file
                (unless ios::app mode is used)
        -- read / write position advances sequentially through the file's contents


    :: problem ::

          - in order to get to a specific byte of data, 
                    --> all date before it must be read <--

~~~~~~~~~~~~~~~~~~~
random file access
~~~~~~~~~~~~~~~~~~~

    program may immediately jump to any byte in the file without reading the previous bytes        


Think of it like this:

    sequential      -----       random file access
    ----------                  ------------------
    cassette                            CD

    need to fast forward            can jump to different tracks


***************************************
   Changing the read/write position
***************************************

    file.seekp(20L, ios::beg)    // seek put     - used for files opened for output
                                    // put the data
        // 20L == 20Long ; moves to byte 20
        
        // flags:
        // ios::beg ;; offset calculated from beginning of file
        // ios::end ;; offset calculated from end of the file
        // ios::cur ;; offset calculated from current position
        // negative offset for backwards read in the file
        // positive offset for forwards read of the file

    file.seekg(-(5 * sizeof(char), ios::end)) // seek get- used to files opened for input
                                    // get the data
    
    ((( see program12-17.cpp )))


    Note:

        if you read to the end of the file you need to call the clear() member function
            to reset the eof flag or seekg / seekp will not work
    
    long int pos, pos2;
    pos = file.tellp()    // returns as longint the current byte number of write position

    pos2 = file.tellg()    // returns as longing the current byte number of read position





*****************************************************
    Rewinding a Sequential Access File with seekg
*****************************************************

    Concept:    

        Sometimes a file's read position needs to be set back at the beginning of the file 

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Approach 1     -      close and reopen the file
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


    dataFile.open("file.txt", ios::in);     // open the file
    // process file conttents
    dataFile.close();
    dataFile.open("file.txt", ios::in);     // open the file again
    // process file's contents again
    dataFile.close();

    
    oOo~~>      Each time the file is reopened, its read position is located at the beginning of the file
        
        ::: Read Position :::

                ** the byte that the file will read with the next read operation


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Approach 2     -      Rewind the file (move read position back to the beginning
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    * use seekg()
    
    dataFile.open("file.txt", ios::in);     // open the file
    // process file
    dataFile.clear();                       // clear the eof flag
    dataFile.seekg(0L, ios::beg);           // rewind the read position
    // read and process file
    dataFile.close();                       // close the file

        ** clearing eof flag is only necessary if it reads to the end of the file
        ** eliminates need to close and reopen file multiple times




*****************************************************
      Opening a file for both input and output
*****************************************************

    Concept:    you may perform input and output on an fstream file without closing it and reopening it

    ** allows for read and writing of data simultaneously

    fstream file("data.dat", ios::in | ios::out);
    // or with the open function
    file.open("data.dat", ios::in | ios::out);
    file.open("data.dat", ios::in | ios::out | ios::binary);

    ((( see program12-20.cpp -> program12-22.cpp )))
