******************************************************************
                    Introduction to Classes
******************************************************************
                    
    Concept:
    
        Procedural              vs.         Object Oriented Programming


centered on procedures that                 centered around the objects
take placed in a program                    created from abstract data types



    ~~~~~~
    Object  ->      has both data and procedures
    ~~~~~~

    object's data => attributes
    procedures => member functions      // called << methods >> in other programming languages

                
                ** addresses problem that can result from separation of code and data through
                        <^>  Encapsulation
                                -- combining of data and code into a single object

                        <^>  Data Hiding
                                -- hiding an objects data from the code outside of the object

            -- only the objects member functions may alter data in the object
                    * provides indirect access to the object's data
                    

    
            oOo~    Object Reusability
                 
                  -- not a standalone program, but used by programs that need its service

    =======
     class   ~~>    code that specifies the attributes and member functions that a particular
    =======         type of object may have


            * a class is not an object, it is a description of an object
                    -- think: blueprint or cookie cutter

        
        oOo~~<> each object that is created from a class is called an     <<< instance >>>

        

    Concept:
    
        In c++, the class is the construct primarily used to create objects


// Syntax \\

class ClassName
{ 
    declaration;
    //... more declarations             // for vars and functions that are members of the class
    // may follow...
};                              // don't forget the semicolon


  ** OR  **

class ClassName
{
    private:                            //  ACCESS SPECIFIER
        // declarations of private          ** can only be access by public member functions
        // members appear here.
    public:                             //  ACCESS SPECIFIER
        // Declarations of public           ** can be called by statements outside the class
        // members appear here
    private:                             //  ACCESS SPECIFIER
        // don't have to be in order
        // don't have to all be under same access specifier
};


// End Syntax \\


eg.)

class Rectangle
{   
    double width;                           // member are private by default
    double length;                          // private members can't be accessed outside the class
};                          


            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              const with member functions
            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


    double getWidth() const;
    
            * specifies that the function will not change any data stored in the calling object
            * only in the member function declaration


    ::::::::::::::::::::::::::::

         the ( :: ) operator            ==>  scope resolution operator

    ::::::::::::::::::::::::::::


   
    used to indicate the scope of a member function if it's placed outside of the class



            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                Private Member Functions
            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
        Concept:
            
            Like member variables, a private member function may only be called 
                    from a function that is a member of the same class

    
        * sometimes internal functions are necessary for data processing that 
                should not be called outside of the function


            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                  Avoiding Stale Data
            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    * Variables that are dependant on other data may become << stale >>
    
Suppose:
    class Rectangle
        private:
            length;
            width;
            area;           // dependent on length and width
        public:
            void setWidth();    // can update width and area may not get updated
                                // it is referred to as 'stale' because the area would not
                                // actually be the current length and width
            void setLength();
            void setArea();
            double getArea();   // returning the area avoids the chance of 'stale' data

        
    :::::     Solution:    ::::::::
            
            oOo-->  whenever possible, return the calculated data



***************************
    Pointers to Objects
***************************


    Rectangle myRectangle;              // a rectangle object
    Rectangle *rectPtr = nullptr;       //  Note: this variable is not an object
                                        // it holds the address to a Rectangle Object
    rectPtr = &myRectangle;             // recPtr now points to myRectangle
    
    rectPtr->setWidth(12.5);        // -> dereferences pointer and accesses setWidth member function
                                    // 12.5 is now stored in myRectangle's width member variable
    rectPtr->setLength(4.8);


      

                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                Dynamically allocated Objects
                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


                                
                           Rectangle *rectPtr = nullptr;

                           // dynamically allocate a Rectangle Object
                           rectPtr = new Rectangle;

                           // Store values in the objects width and length
                           rectPtr->setWidth(10.0);
                           rectPtr->setLength(15.0);

                           // delete the object from memory
                           delete rectPtr;
                           rectPtr = nullptr;

                
            /*
             * If using smart pointers (c++11 and up) you can avoid using delete statements
             * because the smart pointer will automatically delete them */

                        #include <memory>

                        unique_ptr<Rectangle> kitchen(new Rectangle);
                        unique_ptr<Rectangle> bedroom(new Rectangle);
                        unique_ptr<Rectangle> den(new Rectangle);

                        // then this line is unnecessary


                
***************************
 Why have private members?
***************************


        # some variables and functions can only be meant to be used internally
        # protects members from being inadvertantly altered
        # public members become interface to object


        ** setters/mutators should also be doing data validation



**************************************************
Separating Class Specification from Implementation
**************************************************


    Concept: 
        class declarations are usually stored in their own header files
        
        member function definitions are stord in their own .cpp files

    
    Typical way to store program components:

        (1) class declarations are stored in their own header files
               
                << class specification file >>
                        * a header files that contains a class declaration
                        * usually the same name as the class
                        *   (eg)  Rectangle.h

        (2) member function definitions for a class are stored in a class implementation file
            
                << class implementation file >>
                        * a separate .cpp file containing member function definitions for a class
                        * usually the same name as the class
                        *   (eg) Rectangle.cpp
        (3) Notes:
                o  any program that uses the class should #include the classes header file
                o  the classes .cpp file should be compiled and linked with the main program
                o  can be automated with a project or << make >> utility


        ex) take a look at Rectangle.h

        2 new preprocessor directives:
            #ifndef // INCLUDE GUARD
                    // prevents the header file from being included more than once
                    // stands for " if not defined" 
            #define // ifndef determins whether a specific constant has been defined with #define                
                    // if the constant has already been defined it means the file has been included
                    // defines the constant, if the file has been included the include guard
                    // skips it contents

            #endif      // ends the "if not defined"    or #ifndef

        ** don't want to include the definition twice
        ** if the file hasn't been included yet, include the contents



********************************
    Inline Member Functions
********************************

        //  Member functions that are defined inside of the class body
         
eg)

class Rectangle
{
    private:
        double length, width;
    public:
        double getArea()
        {
            return length * width;
        }
};

        oOo~~>      Inline member functions give increased performance
            
                /* A lot goes on behind the scenes in a function call:
                 *      -- a number of special items (functions return address, values of args etc
                 *              are stored in a section of memory called the <<<  STACK  >>>
                 *      -- local vars are created
                 *      -- essentially, a stage is set for the function call and this takes time
                 *      -- time adds up if the function is repeatedly called or looped over
                 */

            inline expansion: 
                    - compiler replaces call to an inline function with the code of the function itself
                    - can result in increased performance
                    Note: because it can appear multiple times in the code, it can increase the pgorgrams size
                            thus decreasing performance


********************************
        Constructors
********************************

    Concept:
        A constructor is a member function that is automatically called when a class object is created
         in memory (instantiated)

                    * Same name as the class
                    * public
                    * no return type
                            -- constructors are not explicit function calls so it won't return to anywhere

    Think:  initialization routines
    
    Useful for:
        - initializing member variables
        - performing setup routines

class Demo
{
    public:
        Demo(ParameterList);     // Constructor  function declaration
};

Demo::Demo(ParameterList)            // external definition
{
    cout << "Welcome to the constructor!\n";
}




        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            Member Initialization Lists
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Concept:
    you can initialize variables in the constructor like so:

Rectangle::Rectangle()
{
    width = 0.0;
    length = 0.0;
    // more code here
}

or you can use a technique called <<< member initialization list >>>

Rectangle::Rectangle() :                // notice the colon after the parens
    width(0.0), length(0.0)             // member variable with initialized value in parens
{                                       // separated by commas
    // more code here
}
            ** initialization take place before any code is written **




        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
          Passing Arguments to Constructors
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


            * constructors are just like regular functions
                o can accept argument
                o have default arguments
                o be declared inline
                o can be overloaded




        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                Default Constructor
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

                * constructor that takes no arguments

                
     Conecpt:
         A constructor can have parameters and can accept args when an object is created
         
// Rectangle object can then be instantiated like so:

    Rectangle box(13, 14);


        

        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                  Default Arguments 
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class Sale
    private:
        itemCost;
        itemRate;
    public:
        Sale(double cost, double rate = 0.05)
            { itemCost = cost;
              itemRate = rate; }
            
then you can initialize a sale object like so:

Sale item(10);      // cost is initialized to 10, rate takes the default argument of .05


            
    oOo~~>   if all arguments in the constructor are default arguments
                    ** it becomes the default constructur **

        eg)

        Sale(double cost = 0.0, double rate = 0.05)


    constructor can then be called with no arguments like so:

        Sale saleItem;

                    /*      no arguments were passed to the constructor
                     *              -- default arguments for both params were used
                     *
                     *      because the constructor can be called with no arguments
                     *             :: It is the default constructor ::          */


        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
               Overloading Constructors
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    Concept:
        A class can have more than one constructor

        * constructors can be overloaded like functions
        * as long as each constructor takes a different list of parameters, the compiler can tell them apart

    Sale()  { cout << "Default baby!!!" << endl; }
    Sale(string desc) { description = desc; } 
    Sale(string desc, double c, double r)           // just like functions, as long as param lists
        { description = desc;                       // are different, the compiler can distinguish them
            cost = c;
            rate = r;   }


        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                Constructor Delegation
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

            Concept:

                One constructor can call another. This is known as <<< constructor delegation >>>

( eg )

class Contact
{
    private:
        string name;
        string email;
        string phone;
    public:
        // ctor #1
        Contact() : Contact("", "", "")     // default ctor calls ctor #2
        {  }                                // notice the colon after the function header followed by the 
                                            // call to ctor #2

        // ctor #2
        Contact(string n, string e, string p)
        {   name = n;
            email = e;
            phone = p;  }
        // other member functions
};


********************************
        Destructors
********************************

    Concept: 
        A destructor is a member function that is automatically called when an object is destroyed

            * public member function
            * same name as class
            * no return type (not a callable function)
            * preceeded by a tilde (~) character
            * can't have a parameter list
            * Can only have one destructor (cannot have overloaded destructors because theres no params)

       oo perform shutdown procedures wen the object goes out of existence
                ( eg )  to free memory that was dynamically allocated by the class object


eg)

Sale::~Sale()               // notice the ~
{
        cout << "Destruction baby!!!" << endl;
}   

    When is an object destroyed?
        *   goes out of scope
        *   if dynimically created:
        *           delete is called


********************************
        Arrays of Objects
********************************

    Concept:
        You may define and work with arrays of class objects

    
    o  if you wish to define an array of objects and call a constructor that requires args,
             you must specify the args for each object individually
    o  if there is no default constructor, you must furnish an initializer
    o  if there are fewer initializers than members, the default constructor is used
    o  if a constructor takes more than one arg, the initializer takes the form of a function call
                to the constructor
     

( eg )
// 1st (default)
InventoryItem::InventoryItem() {/*code*/}
// 2nd constructor
InventoryItem::InventoryItem(string desc) {/*code*/}
// 3rd constructor
InventoryItem::InventoryItem(string desc, double price, int qty) {/*code*/}

    InventoryItem inventory[] = {"Hammer", "Wrench", "Pliers"};
                // defines an array of 3 InventoryItem objects called inventory
                // constructor for inventory[0] is called with "Hammer" as it's argument
                // ctor         for inventory[1]   called with "Wrench" ...
                // etc

    
    oOo~~>  If a constructor requires more than one arg, it must look like a function call:
    // uses the third constructor
    InventoryItem inventory[] = { InventoryItem("Hammer", 6.95, 12),
                                  InventoryItem("Wrench", 8.75, 20),
                                  InventoryItem("Pliers", 3.75, 10) };

    oOo~~>  It isn't necessary to call the same constructor for each object in the array:

    InventoryItem inventory[] = { "Hammer",                                 // uses second
                                  InventoryItem("Wrench", 8.75, 20),        // uses third
                                  "Pliers" };                               // uses second


    oOo~~<>     If you do not provide an initialzer, the default constructor will be called:

    InventoryItem inventory[3] = { "Hammer",                                 // uses second
                                  InventoryItem("Wrench", 8.75, 20) };        // uses third
                                        // third object uses default ctor 
