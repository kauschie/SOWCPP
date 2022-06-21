***********************************
            Exceptions
***********************************

  Concept:

      Exceptions are used to signal errors or unexpected events that occur
    while a program is running.

~~~~~~~~~~~~~~~~~~~~
throwing Exceptions
~~~~~~~~~~~~~~~~~~~~
  - an exception is a value or an object that signals an error

double divide(int numerator, int denominator)
{
  if (denominator == 0)
    throw "ERROR: Cannot divide by zero.\n";// causes an exception to be thrown
  else
    return static_cast<double>(numerator) / denominator;
}


// use
throw arg;      // the throw point

  *    When a throw statement is executed:
            - when thrown by a function, the function aborts
            - control is passed to the << exception handler >>

          << exception handler >>
                -- part of the program that handles exceptions


~~~~~~~~~~~~~~~~~~~~
handling Exceptions
~~~~~~~~~~~~~~~~~~~~

  try
  {
    // code here calls functions or object member
    // functions that might throw an exception
  }
  catch(ExceptionParameter)   // exception handlers
  {
    // code here handles the exceptions
  }
  // repeat as many catch blocks as needed

  Program aborts when Exceptions that are not caught:

    (1) try/catch block contains no catch that matches the exception
            parameter type

    (2) exception is thrown outside a try block


*******************************************************
    Object Oriented Exception Handling with Classes
******************************************************
// define an empty class with the exception name
class Rectangle
{
    public:
        class NegativeSize
            { };        // empty class declaration
};

    // then use with a throw statement

    throw NegativeSize();      // causes NegativeSize() object to be
                    // instantiated and then thrown as an exception

try:
    cout << "Area: " << myRectangle.getArea() // could result in error
catch (Rectangle::NegativeSize)     // see NOTES**
    // error handling

                                ((( see program16-2.cpp)))
Notes:
    * Because NegativeSize is declared inside Rectangle, the
        class name must be    << fully qualified >> with scope
        resolution operator

    * noteworthy: we didn't define a NegativeSize class outside the
    class, the catch statement only needs to specify the type of
    exception it handles


Uses:



    * exceptions can then use a boolean flag to catch user input

bool tryAgain = true;

while (tryAgain)
{
    try
    {
        // some iffy code
        tryAgain = false; // unflag boolean if successful
    }
    catch(ClassName::ExceptionClassName)
    {
        // handles exception and loops if unsuccessful
    }
}


*******************************************************
        Extracting Data from the Exception Class
*******************************************************

    Concept:
        * can be accomplished by giving members to exception classes to
            store data in

( eg )

class NegativeWidth
{
private:
    double value;
public:
    NegativeWidth(double val)
    { value = val; }
    double getValue() const
    { return value; }
};

// then when you throw the Object
throw NegativeWidth(w);     // passes arg w to NegativeWidth() ctor
            // constructor stores this value into 'value'

* the class instance carries this member variable to the catch block
    that interprets the exception

catch(Rectangle::NegativeWidth e)
{
    cout << "Error: " << e.getValue()
        << " is an invalid value for the "
        << "rectangle's width.\n";
}

// notice that the catch block defines the parameter object e
// because it is going to use the memberfunction

**********************************
        Unwinding the Stack
**********************************

    Concept:
        - Once an exception is thrown, the function that is currently
            executing will terminate in an attempt to reach a catch block.
        - functions will continue to terminate until it reaches
            a catch block.
        - this is referred to as
                    <<  "Unwinding the stack" >>



    * if an exception is thrown by a member function of a class obj,
        then the class destructor is called.

    * if statements in the try block ( or statements branching from
        the try block) created any other object,
            their destructors are called as well


***********************************
      Rethrowing an Exception
***********************************

    * Nested try blocks require rethrowing the exception to pass on
        exception information

    (eg)
    try
    {
        doSomething();
    }
    catch(exception1)
    {
        // code to handle exception1
    }
    catch(exception2)
    {
        // code to handle exception2
    }

// the following is nested within doSomething()

    try{
        doSomethingElse();
    }
    catch(exception1)
    {
        throw;  // rethrows exception1 again. the catch block in
    }   // the outer try/catch will then handle it

***********************************
      Handling bad_alloc
***********************************

    #include <new>      // exception type is defined in new.h in the
    using namespace std;  // std namespace

    try
    {
        // code that uses the new operator
    }
    catch (bad_alloc)
    {
        // code that responds to the error ( eg )
        cout << "Insufficient memory.\n";
    }

    ((( see program16-6.cpp )))



***********************************
        Template Functions
***********************************

    Concept:
        A function template is a "generic" function that can work
        with any data type. Specification of the function is
        substituted with parameters for data types.
            * when the compiler encounters a call to the function,
            it generates code to handle the specific data types
            used in the call


    * a 'mold' that the compiler uses to generate one or more Funcs

function templates:
    * allow you to write a single function definition that works
        with many different data types
    - don't need to specify actualy types for the paramaters,
        return value or local vars
            o use << type parameters >> to specify a generic type

( eg )
   //vvvvvv template prefix
    template <class T> //<~~~~~ one or more generic data types
    T square(T number)   // that start with class followed by param
    { // ^^^^^^^^^   function header with type params substituted
        return number * number;
    }

    ((( program 16-7.cpp )))
    ((( program 16-7.cpp )))

    oOo~~> All type parameters defined in a function template must
                apppear at least once in the function parameter list.
    oOo~~> templates should appear near the top of the program or
                in a header file


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  Using Operators in Function Templates
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    * operators are fine if the function only uses primitive
        data types
    * you must have overloaded operators when passing in user defined
          datatypes
    * (eg) +-*/ and also <,>,==, etc.


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Function Templates with Multiple Types
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


    * Each type must have its own parameter

    (eg)

template <class T1, class T2>
int largest(const T1 &var1, T2 &var2)
{
    if (sizeof(var1) > sizeof(var2))
        return sizeof(var1);
    else
        return sizeof(var2);
}       ((( program16-9.cpp )))


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Overloading with Function Templates
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template <class T>
T sum(T val1, T val2)
{
    return val1 + val2;
}

template <class T>
T sum(T val1, T val2, T val3)
{
    return val1 + val2 + val3;
}

    * templated functions can also coexist with regular Functions
        as long as the parameter list is different


template <class T1>
double half(T1 number)
{
    return number/2.0;
}


************************
    Class Templates
************************

    Concept:

        Templates may also be used to create generic classes and
            abstract data types. Class templates allow you to created
            one general version of a class without having to duplicate
            code to handle multiple data types

    ((( see SimpleVector.h as well as program16-11.cpp )))



~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Defining Objects of class template
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    * defined like regular objects with the small difference being
        the angle brackets  ' <> '

    * datatype you wish to pass to the type parameter must be specified
            inside the angle brackets

( eg )

    SimpleVector<int> intTable(10); // int will be used for T param
    SimpleVector<double> doubleTable(10);   // double used for T param
        ((( see program16-11.cpp )))


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            Specialized Templates
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    - one that is designed to work with a specific data type

( eg )

class SimpleVector<char *>

    * compiler would know that this version of the SimpleVector is
        indtended for the char * data type
