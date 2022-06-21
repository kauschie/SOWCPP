**********************************
    Instance and Static Members
**********************************

    Concept:
        Each instance of a class has its own copies of the class's instance variables

        if:

        a member variables is declared static, 
                all instances of that class have access to that variable

        if:

        a mamber function is declared static,
                it may be called without any instances of the class being defined.


    Definitions:

     (((   Instance Variables   )))
                
                Each instance of a class has its own individual copy of the variable


    (((   Static Member Variables   )))

                If a member varible is declared static, there will be only one copy of the

                    member variable in memory


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        Static Member Variables
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

::::::Syntax::::::

class ClassName
{
    private:                                // declared within the class
        static dataType variableName;       // note only one instance of this will be created acrossed
};                                          // all instances of the class

dataType ClassName::variableName = value;       // defined and instantiated outside of the class definition

:::::End Syntax::::::

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        Static Member Functions
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

::::::Syntax::::::

class ClassName
{
    private:
        static ReturnType FunctionName (ParameterTypeList);         // prototype inside class
};

ReturnType ClassName::FunctionName(ParameterList)
{
   //  Note: static functions can only access static member variables
}


( eg )


class Budget
{
    private:
        static double corpBudget;
    public:
        static void mainOffice(double); // static member function
};

double Budget::corpBudget = 0;

void Budget::mainOffice(double d)
{   corpBudget += d;    )


    Notes:

        *   A static Member Function cannot alter any nonstatic member data in its class
        *   Even though member variables are defined in the class, they are declared outside of the class
        *           -- this means they exist for the lifetime of the program
        *           -- come into existance before any instances of the class are created
        *   Static member functions can be called before any instances of the class are created
        *   Static member functions can thus access static member variables before classes are defined in memory


    Calls to static member functions do not use regular dot notation
            
            o   Need to use the scope resolution operator


( eg )

    double amount = 10;
    Budget::mainOffice(amount);         // notice the scope resolution operator in the call to Budget
    
    ******************
        if an instance of an object exists, you can call it with dot notation like any other member function

( eg )

   Budget divisions[4]; 
    divisions[0].mainOffice(500);



**********************************
        Friends of Classes
**********************************

    Concept:
    
        A friend is a function or class that is not a member of a class
                but has access to the private members of the class

        *   Must be declared as such by granting it access
                - classes keep a "list" of their friends
                        only the external functions/classes on the list are granted access

::::::Syntax::::::

class ClassName
{
    public:
        friend ReturnType FunctionName (ParameterTypeList);         // prototype inside class
};


( eg )

class Budget
{
    public:
        // Friend function from class AuxiliaryOffice
        friend void AuxiliaryOffice::addBudget(double, Budget &);
};                              // Notice: The Budget object being passed by reference!


    
    ** Forward Declaration of the Budget Class **

            * tells the compiler that a class named Budget will be declared later on in the program
            * Necessary because the compiler will process the Auxil.h file before
            *       it processes the Budget class declaration


**********************************
         Copy Constructors 
**********************************

    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
           Memberwise Assignment 
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    Concept:

        The = operator may be used to assign one object's data to another object
        - or - to initialize one object with another object's data

( eg )
    
    Rectangle box1(10.0, 10.0);
    Rectangle box2(20.0, 20.0);
    
    Rectangle box3 = box1;      // Memberwise assignment 
    box2 = box1;                // memberwise assignment occurs 


    
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
           The Copy Constructor
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    Concept:

        A copy constructor is a special constructor that is called whenever a new object
            is created and initialized with another object's data

        ( eg ) 

            * a class has pointer variables
                    oo memberwise assignment would cause the address to get copied over as well
                            -- as a result, both objects would have a pointer that points to the same address
                            -- if delete is called on the pointer, it would free the memory for both obj's

ClassName::ClassName(const ClassName &obj)   // copy constructor requires you pass a reference to an object
{                                               // of the same type. Good practice for it to be const as well
    variable = obj.variable;        //  variables can then be assigned using dot notation from parameter
    pointer = new pointerType;      // take care to assign pointer address to a new slab of memory
}

    Rectangle box3 = box1;      // copy constructor would be called
    function(box1);         // copy constructor called when Rectangle object passed by value


        Notes:

    -- Failure to use a reference variable will cause the copy constructor to be indefinitely called
            until the available memory fills up and causes the program to crash

    ** Good practice to make reference object a constant so that theres no modifications to data
    
    oo if a class doesn't have a copy constructor, the default copy constructor is called
                -- default copy constructor performs memberwise assignment 


************************************
        Operator Overloading
************************************

    Concept: C++ allows you to redefine how standard operators work when used with class objects.

    ( eg )
        
        * programming special behavior to occur when using arithmatic


    class.add(5);    // instead of this

    class += 5;     // requires an operator to be overloaded


    
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
       The  (((   this    ))) pointer 
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

            -- a special pointer that is built in
            -- automatically passed as hidden arg to all nonstatic member function calls

        student1.getStudentName();  // this points to student1
        student2.getStudentName();  // this points to student2


    // student2.operator=(student1);            // this would do the same thing
    student2 = student1;    // still performs memberwise assignment    
                            // copy constructor would not be called because 
                            // the copy constructor is just that -- a CONSTRUCTOR
                            // only invoked when an object is created


    // overloaded = operator

const StudentTestScores operator=(const StudentTestScores &right)  // doesn't have to be named right
{   if (this != &right)      // checks for self assignment               
    {
        delete [] testScores;
        studentName = right.studentName;        // notice that studentName doesn't have a . operator
        numTestScores = right.numTestScores;        // this is because the operator is the member function  
        testScores = new double[numTestScores];     // of the left oparand
        for (int i = 0; i < numTestScores; i++)
            testScores[i] = right.testScores[i];
    }
    return *this;
}


    const StudentTestScores :    returns a StudentTestScores object that is const (cannot be modified)
                                could be a void return but you wouldn't be able to string them together
    operator=   :   function's name. Overloads the = operator. Called when an assignment statemtn executes
                        where the object on the left side of the = operator is a StudentTestScores object.
    
    Parameter   : constant reference object named right. - references the object passed in on the right
                    -- reference variable for efficiency purposes. Prevents compiler from making a copy
            ( eg )
                student2 = student1     <~~~~~ references student 1

    student2.operator=(student1);       // these are the same 
    student2 = student1;              // these are the same 
           
        Note:

            Important to check for self assignement especially in classes that dynamically allocate memory



    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                Look Out!   
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

        * you can change the entire meaning of an operator
                -- this is not a good programming practice
        * not all operators can be overloaded



    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      Overloading ++prefix and postfix++ 
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

        *   No need for a parameter because there's only one operand
        *   returns the object that called it


    prefix:

    FeetInches FeetInches::operator++()
    {   ++inches;                       
    return *this;   }                           // return pointer to self`


    postfix:

    FeetInches FeetInches::operator++(int)    // notice the dummy param
    {   FeetInches temp;                    
    inches++;
    return temp;    }                           // return the dummy param



Note:

    The nameless int parameter indicates that the function is designed to be used in postfix mode


    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      Overloading Relational Operators
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

        * should return true or false

    bool FeetInches::operator<(const FeetInches &right) // send in a reference to theobject for efficiency
    {
        if (feet < right.feet)          // check to see if one is less than the other
            return true;
        else 
            return false;       // return the bool
    }



    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
          Overloading << and >>
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

ostream& operator<<(ostream &out, FeetInches &obj)          // returns reference to cout and accepts reference
{                                                               // to cout
   out << obj.feet << " feet, " << obj.inches << " inches";     
   return out;
}

istream& operator>>(istream &in, FeetInches &obj)       
{
    cout << "Feet: ";
    in >> obj.feet;
    return in;
}


    
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              Overloading []
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int& IntArray::operator[](const int& sub)    // must return a reference to an int 
{                                           // or it can't be an lvaleue in expressions like:
    if (sub < 0 || sub > arraySize)         //  array[5] = 26;
        subscriptError();
    return aptr[sub];                       // returns the reference
}



    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
             Object Conversion 
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// calculates deciamal equivalent of FootInches objectv
FeetInches::operator double()           // notice that there's no return type becaue it will always return double
{                                       //  
    double temp = feet;             
    temp += (inches/12);
    return temp;                        // returns the double version
}

then you could use like this:

FootInches distance;
double d;

d = distance;




************************************
            Aggregation
************************************

    Concept:
        
        Aggregation occurs when a class contains an instance of another class.


    class Instructor
    {
        // instructor class
    }
    class TextBook
    {
        // textbook class
    }
    class Course                            // aggregate class -- contains other class instances
    {
        private:
            Instructor instructor;      // course has an instructor
            TextBook textbook;          // course has a textbook
        // rest of class        // notice**  the HAS A relationship
    }



***************************************
 Rvalue References and Move Semantics
***************************************

    Concept:
        
        A move operation transfers resources from a source object to a target object.
        A move operation is appropriate when the source object is temporary and is about to be destroyed.

                ** greatly increases performance of assignment operations


    int x;              // x is created here and is alive during its scope

    x = 2 * 6;          // system evaluates expression on the right side of the = operator
                        // gets the value of 2*6 and stores the result, 12, as a temporary value
                        // copies the value to the x variable
                        // after statement executes, temporary variable is no longer needed so it gets destroyed
                    

    The same thing happens with a return from a function:

    int square(int a)                   // a is created and 5 is copied to it
        return a * a;                   //

    int main()
    {
        int x = 0;                    {  // 1) Square is called and value 5 is passed
                                      {  // 2) square calculates 5*5 and stores 25 as a temp value
        x = square(5);      ~~~~~~~>  {  // 3) temp value is assigned to the var x 
        cout << x << endl;            {  // 4) temp value is destroyed as system no longer needs it
        return 0;
    }


    ((((     lvalues      ))))

                definition:  values that persist beyond the statement that created them and have 
                                names that make them accessible to other statements in the program.

    ((((     rvalues      ))))

                definition: values that are temporary and cannot be accessed beyond the statement
                                that created them.


    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            Rvalue References 
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

            recall:
                reference variable is a variable that refers to the memory location of another variable

        int x = 34;

    // lvalue reference
        int & ref = x;      // ampersand indicates a reference
        
                *     referred to as an lvalue reference because it can only refer to lvalues

    // rvalue reference
        int && rvalRef = square(5);         // reference var that can only refer to temp objects that would
            cout << rvalRef << endl;        // otherwise have no name

        Note:

                the (   &&    ) operator 

            *   You are giving a name to a temporary value
        
        int x = 0;
        int && rvalRef = x;     // ERROR!   not allowed


            * rvalRef is no longer an rvalue
            * a temporary object can have at most one lvalue reference pointing to it
                        -- you can be sure it isn't being used elsewhere

    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              Move Semantics 
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

            * computer does a lot of work behind the scenes when args are passed into 
                    and returned from function
            
                    ( eg )  
                        - allocating memory
                        - copying variables
                        - creating / destroying temp variables


        // Move Assignment
        Person& operator=(Person&& right)   // takes an rvalue as a parameter
        {                                   // can't be const because the swap modifies it
            if (this != &right)
                swap(name, right.name);     // from #include <algorithm>. swaps values at their mem locations
        }

        // Move Constructor

        Person(Person&& temp)
        {
            name = name.temp;           // steal the name pointer
            temp.name = nullptr;            // nullify pointer
                                        // needs to be left in a state where destructor wont cauase an error
                                        // be deleting it a second time
        }


        When should you use????

            *   When writing a class that contains a pointer to outside data
            *       you should include:
            *               (o) copy constructor
            *               (o) move constructor
            *               (o) copy assignment operator
            *               (o) move assignment operator
            *
            *               * if you write one then you need to write all

