//////////////////////////////
///// STRUCTURED DATA ////////
//////////////////////////////

** Abstract Data Types (ADT)**
        o data types created by the programmer
        o have their own range (domain) of data and sets of operations
            that may be performed on them

<< Abstraction >>
    -- general model of something


Primitive Data Types
    -- data types that are defined as a basic part of the language

    data type defines:
        o   what values a var may hold (range / factional vs integer)
        o   what type of operations may be performed on it

    
    primitive data types are abstract in this sense:
        int x = 1, y = 2, z = 3;

        - 3 separate instances of an int


    Concept: 
        
        C++ allows you to group several variables together into a single item called a 
                            << structure >>


***************************************
              Structures
***************************************

// syntax \\

struct tag                              // name of the structure
{
    variable declaration;               // declares << members >> of the function
    // ... more declarations
    //       may follow...
};                                                  // notice the semi colon!

// end - syntax \\


eg:)

struct PayRoll
{
    int empNumber;      // Employee number
    string name;        // Employee's name
    double hours;       // Hours worked
    double payRate;     // Hourly pay rate
    double grossPay;    // Gross pay
};

       /*   PayRoll Structure Insight:
        *
        *       has 5 members: empNumber, name, hours, payRate, grossPay
        */

    Notes:

        this does not define any variables, it simply tells the compiler what a PayRoll
            structure is made of.


Defining a PayRoll object:

//format:

tag varName;

//end format

eg)

PayRoll deptHead;
    -- or --
PayRoll deptHead, foreman, associate;



***************************************
     Accessing Structure Members 
***************************************

    Concept:

        -- the dot operator (.) allows you access to the structure members in a program


    eg.)

    deptHead.empNumber = 475;
    foreman.empNumber = 897;            // can use them just like regular variables
    associate.empNumber = 729;

    

***************************************
     Initializing a Structure
***************************************

    Concept:
        
        -- The members of a structure variable may be initialized with starting values when
        the structure variable is defined

//consider:

struct CityInfo
{
    string cityName;
    string state;
    long population;
    int distance;
};

//then a CityInfo structure maybe initialized as such:

CityInfo location = {"Ashville", "NC", 8000, 28};


// you do not need to provide initializers for all variables

CityInfo location = {"Tampa"};

CityInfo location = {"Atlantai", "GA"};

CityInfo location = {"Knoxville", "TN", , 90};      // ILLEGAL!!!!



****************************************
          Arrays of Structures
****************************************
    Concept: Arrays of structures can simplify some programming tasks

    * A single array of structures can be used in place of several arrays or regular vars

    Assume:

struct BookInfo
{
    string title, 
           author, 
           publisher;
    double price;
};

// the following defines an array of BookInfo variables:

BookInfo bookList[20];

// elements can be accessed with subscripts:

booklist[1].title = "The Kama Sutra";

for (int i = 0; i < 20; i++)
{
    cout << booklist[index].title << endl;
    cout << booklist[index].author << endl;
}


*************************************
    Initializing Array of Structs
*************************************

suppse:

struct PayInfo
{
    int hours;
    double payRate;
};

PayInfo workers[NUM_WORKERS] = {
                                 {10, 9.75},
                                 {15, 8.62},
                                 {40, 15.65}
                                };           
       // can initialize all or part of the elements in the array / structs

*************************************
        Nested Structures
*************************************

    Concept:
        It's possible for a structure variable to be a member of another structure variable

// for example:

struct Costs
{
    double wholeSale;
    double retail;
};

struct Item
{
    string partNum;
    string description;
    Costs pricing;              // Notice the Costs structure object declared within a struct
};  

// then you could declare an Item variable like so:

Item widget;

// accessing the members of the pricing variable
widget.pricing.wholeSale = 100.0;
widget.pricing.retail = 150.0;




*************************************
      Structs as Function Args
*************************************

    Concept: structure variables may be passed as arguments to functions
 

    -- individual members of a structure variable may be used as function arguments
    -- NOTE::   must declare before any functions attempt to use the item as a parameter

// suppose we declare a Rectangle struct as so:
struct Rectangle;
{
    double length;
    double width;
    double area;
};

// also, suppose we have a function defined within the same program:
double multiply(double x, double y)
{
    return x * y;
}

// declare a Rectangle object like so:
Rectangle box;

// then..
box.area = multiply(box.length, box.width);     // struct members passed as variables to function


    /*                                                          *\
     * Sometimes it's more convenient to pass an entire struture*
     *                                                          */

void showRect(Rectangle r)
{
    cout << r.length << endl;           // r's members contain *** A COPY *** of box's members
    cout << r.width << endl;
    cout << r.area << endl;
}

// Then, we can call the function like so:

showRect(box);
    

Concept:
  
    ** passing large structs can cause poor performance due to passing many variables by value
    ** passing by reference does not cause the arguments to need to be copied to the parameters
            ~~ often preferable to pass large structs by reference

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   can also pass by reference
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void getRect(Rectangle &r)
{
    cin >> r.length >> r.width;
    r.area = r.length * r.width;
}



~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    pass by constant reference to prevent access to the large struct
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

   void showItem (const InventoryItem &p)
    {
        cout << "Part Number: " << p.partnum << endl;
        cout << " This function can't alter the parameters because p is a const" << endl;
        //          ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ 
    }


        oOo      more efficient than passing by value because 
                        the amount of time and memory consumed in the 
                            function call is reduced



*************************************
 Returning a struct from a function 
*************************************

    Concept: A function may return a structure

// suppose the following struct:

    struct Circle
    {
        double radius;
        double diameter;
        double area;
    }

// the following function may be defined:

Circle getCircleData()
{
    Circle temp;                // struct defined in function

    temp.radius = 10.0;         // members are assigned values
    temp.diameter = 20.0;
    temp area = 314.159;
    return temp;                // Circle struct is returned
}

// function may be called as such:

myCircle = getCircleData();



:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

Structures Provies a way to return multiple variables from a function

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::





*************************************
        Pointers to Structures
*************************************

    Concept:    You may take the address of a structure variable and create variabels that are
                    pointers to structures.




    Circle myCircle = { 10.0, 20.0, 314.159 };
    Circle *cirPtr = nullptr;           // defined like any other pointer
    cirPtr = &myCircle;         // assigned address of a circle object
                            // cirPtr points to the myCircle structure
    
    
NOTE:   be careful when using the dot operator with the indirection operator
                -- the dot has higher precedence than the indirection operator so....

                *cirPtr.radius = 10;   // WRONG -- tries to derefrence cirPtr.radius 
                (*cirPtr).radius = 10;      // need to use parens


<<<<<<<      C++ has a special operator for derefrencing a structure pointer    >>>>>>


                cirPtr->radius = 10;            // Automatically derefrences the struture pointer 

                        // visually supposed to look like an arrow 
                                        //      indicating a pointer is being used


            void getData(Circle *c)      
            {
                cout << "Enter radius: " << endl;
                cin >> c->radius;               // using struct pointer notation
             // cin >> (*c).radius;             // using dot notation and parens
            }



***************************************
    Dynamically Allocating a struct
***************************************

    oOo     Use the structure pointer and new operator to dynamically allocate a struct    oOo

    Circle *cirPtr = nullptr;       // define a circle pointer
    cirPtr = new Circle;            // dynamically allocate a circle structure
    cirPtr->radius = 10;            // store a value in the radius member


    ::::: Allocate an arraay of structs ::::::

    Circle *circles = nullptr;
    circles = new Circle[5];            // creates 5 circle struct objects
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter radius for circle " << (i+1) << ": ";
        cin >> circles[i].radius;
    }



*******************************************
    When to use ( . ) , ( -> ) and ( * )
*******************************************


    struct GradeInfo
    {
        string name;        // student name
        int *testScores;    // dynamically allocated array
        float average;      // test average
    };


        Note:

        ( -> )  used to derefrence a pointer to a structure,
                        NOT  a pointer that is a member of a structure



        GradeInfo student1;     // declares a GradeInfo struct object

        cout << *student1.testScores;   // displays the value pointed to by testScores member

        GradeInfo *stPtr = nullptr;     // defines a pointer to a GradeInfo structure object

        stPtr = &student1;          // stPtr now points to the student1 GradInfo struct

        *stPtr->testScores      // displays value pointed to by its testscores member

        

        Take Note:

        stPtr->testScores       ==      (*stPtr).testScores


    <<<    So,    >>>

        *stPtr->testScores      ==      *(*stPtr).testScores


 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
       Example Expressions 
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

     Expression                 Description
     -----------                -----------
     s->m                       s is a structure pointer and m is a member
                                you are accessing member m using the structure pointed to by s

     *a.p                       a is a structure variable and p, a pointer, is a member
                                This dereferences the value pointed to by p.

    (*s).m                      s is a structure pointer and m is a member. The * operator derefrences s,
                                causing the expression to access the m member of the structure pointed to by s
                                This expression is the same as s->m

    *s->p                       s is a structure pointer and p, a pointer, is a member of the strucutre pointed
                                to by s. This expression accesses the value pointed to by p. (the -> derefrecnes
                                the s and the * derefrences the p).

    *(*s).p                     s is a structure pointer and p, a pointer, is a member of the structure pointed
                                to by s. This expression accesses the value pointed to by p. (*s) derefrences the
                                structure pointer s and the outermost * derefrences p.
                                This is equivalent to *s->p

    

*******************************************
           Enumerated Data Types
*******************************************

    concept: An enumerated data type is a programmer-defined data type.
                -- consists of values known as enumerators, which represent integer constants


// Begin:: definition   \\

    enum TypeName { One or more enumerators };
                                // enumerators are not in quotes.. they are NOT STRINGS
                                // must be valid C++ identifiers

// End:: definition     \\

        * keyword   enum
        ** followed by name of type (eg. Day)
        *** list of identifiers inside braces
        **** terminated with a semicolon


    enum Day { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY };
               // MONDAY, TUESDAY... etc known as  <<< enumerators >>>
                //   internally assigned integer constants beginning with 0
                //   so MONDAY is stored in memory as the number 0
                //      TUESDAY is stored in memory as the number 1
                //
                //  dont need to be capitalized but because they represent constants
                //  its best practice to capitalize them
    // following statement defines workDay as a variable of the Day type:

    Day workDay;                // declares a workDay variable of type Day
    
    Day workDay = WEDNESDAY             //      can only assign one of the specified enumerators to the var

    cout << workDay << endl;            // outputs 2 because WEDNESDAY is assigned 2 internally 



    :::::::::::::::::::::::::::::::::::::::::::::::::::
    Must static caste if trying to store as int directly
    :::::::::::::::::::::::::::::::::::::::::::::::::::

    workDay = 3;        // Error!!

    workDay = static_cast<Day>(3);      // same as workDay = Thursday


    :::::::::::::::::::::::::::::::::::::::::::::::::::
           Can assign enumerator to an int 
    :::::::::::::::::::::::::::::::::::::::::::::::::::
    
    int x = THURSDY;
    cout << x << endl;  // outputs: 3

    Day workDay = FRIDAY;
    int y = workDay;
    cout << y << endl;      // outputs 4




    
            

*******************************************
      Comparing Enumerated Data Types
*******************************************

    FRIDAY > THURSDAY       // true
                            // FRIDAY stored in memory as 4 and THURSDAY as 3

    FRIDAY == 4     // true




*******************************************
        Anonymous Enumerated Types
*******************************************

    ** when you do not need to define variables of an enumerated type, you can make it << anonymous >>

:::::::::::::
 Definition   ==>   an enumerated type that does not have a name
:::::::::::::

    enum { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY };

            o  Creates the enumerators, we just can't use the data type
            o Monday still == 0, TUESDAY == 1, etc...


      ???    don't try and perform math operations on them    ???


      Day day1, day2;
      day1 = TUESDAY;
      day2 = TUESDAY+1;     // Error!
                    // TUESDAY is really 1 so 1+1 results in the integer 2
                    // integer 2 cannot be assigned to a Day variable because c++ cannot
                    // implicitly convert an int to a Day variable

    day2    = static_cast<Day>(day1+1);     // static casting as a Day type works ~




*******************************************
 Specifying Integer Values for Enumerators
*******************************************

    Suppose:
        
        you wanted the enumerators to be equal to specific values

// you can assign a specific constant in the declaration
    enum Water { FREEZING = 32, BOILING = 212 };

       // leaving out the assignment causes a defualt value to be given:

enum Colors { RED, ORANGE, YELLOW = 9, GREEN, BLUE };

    // RED == 1, ORANGE == 2, YELLOW == 9, GREEN == 10, BLUE == 11

    
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Enumerators must be unique in the same scope
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


        enum Presidents { MCKINLEY, ROOSEVELT, TAFT };
        enum VicePresidents { ROOSEVELT, FAIRBANKS, SHERMAN };  // Error!!!

        // The following also causes an error within the same scope:
        
     enum Status { OFF, ON };
        const int OFF = 0;          // error!!!!




*********************************************
 Declaring and Defining Var in One Statement
*********************************************

    enum Car { PORSCHE, FERRARI, JAGUAR };      // definition
    Car sportsCar;                              // declaration

    enum Car { PORSCHE, FERRARI, JAGUAR } sportsCar;    // defintion and declares sportsCar
    enum Car { PORSCHE, FERRARI, JAGUAR } myCar, yourCar; // definition and declares 2 Car variables:
                                                            // myCar and yourCar
                                                            //
    



*********************************************
      Strongly Typed Enums (enum class)
*********************************************

    ** gets around the limitation of having multiple enumerators with the same name

    enum class Presidents { MCKINLEY, ROOSEVELT, TAFT };
    enum class VicePresidents { ROOSEVELT, FAIRBANKS, SHERMAN };

            // compiles without error
            
    must use the  ::     operator
        Presidents prez = Presidents::ROOSEVELT;
        VicePresidents vp = VicePresidents::ROOSEVELT;


        ** must use static_cast if you want to retrieve the integer value

        
    cout << static_cast<int>(Presidents::TAFT) << endl;     // displys the Presidents::TAFT enumerator


    
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    when using strongly typed enum, you can choose data type other than int
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    enum class Day : char { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY };

        // declares an enum that uses the char data type

