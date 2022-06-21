********************************************************

                    Functions

********************************************************

    * A program may be broken up into manageable functions
    

::function::
    - a collection of statements that performs a specific task

    -A named section of code intended to accomplish a simple and specific task


Reasons to write functions:
---------------------------
divide and conquer - dividing a program up into smaller sections 
                            in order to solve the problem

code reuse      - writing code once that is reused 
                        multiple times throughout the program

           Manibo says:
        /* Readability - 
         * Reusability - Dont repeat yourself
         * Collaboration - working together
         */



::function call::
    - a statement that causes a function to execute


return_type function_name(
        param_type1 param_name1,
        param_type2 param_name2...)
{
    // statements
    [return return_value;]
}

        function names:
        -- cannot use a keywork or reserved word
        -- cannot use spaces
        -- any case works,



::function definition::
    - contains the statements that make up the function

    (1) Return type - data type of the value that is sent from the function
    (2) Name    - give a descriptive name like with variables
    (3) Parameter list  - list of variables that hold values being passed to the function
    (4) Body    - set of statements that the function performs enclosed in {}








**      void functions      **

            * it isn't necessary for all functions to return a value
            eg:
                void displayMessage()           <--------------  function header
                {
                    cout << "Hellow from the function displayMessage.\n";
                }
    
        ~~ Notice that there's no return statement



    "Calling   a   Function"
        - a function is executed when it is called
        - main() is called automatically when the program starts
        - all other functions must be executed with function call statements

        - when a function is called, the program branches to that 
                    function and executes the statements in the body
      
********************************
        Function Prototypes
********************************
AKA function declarations

    void displayMessage();      <----- notice the semicolon at the end
                                        and no definition of what the
                                            function does

    void displayValue(int);    <---- notice you don't need the full name of
                                    the parameters, just the data types 



********************************
  Sending Data into a Function
********************************
 
        * When the function is called, the program may send values
                        into the function
        * Values sent into the function are called arguments
        * variables that receive those values are called parameters

void function1(parameters1)
{
    statements...
    function2(argument1);       // arguments sent to a function
}

void function2(parameterX, paramY, pZ)  // parameters receive the arguments
{   
    statements...  // ^^ each parameter must have a data-type 
}

argument1 is passed into function 2
argument1 is copied into function2's  " parameterX "   variable

parameter variables are initialized to the value 
        of their corresponding arguments

parameters are passed IN ORDER

parameters have SCOPE
    - scope is limited to the body of the function that uses it



function1(int x); // error!
function2(x);       // correct!



********************************
     Passing Data by Value
********************************

    * When an argument is passed into a parameter, only a copy of the arguement's value is passed
    * Changes to the parameter do not affect the original argument
    * when only a copy is passed to a function, it is said to be
                <<  Passed by Value >>


********************************
     The return Statement
********************************

    * The return statement causes a function to end immediately
    * the function immediately terminates
    * control of the program returns to the statement that called the function
    
    -- A function may send a value back to the 
                part of the program that called the function
    
    Functions that return a value are appropriately known as
            :: Value-Returning Functions ::


            double x;
            x = pow(4.0, 2.0);
                
                calls the pow function
                passes 4.0 and 2.0 as arguments
                the function calculates the value of 4.0 raised to the power of 2.0
                the function returns the value 16
                the value 16 is assigned to the variable x by the = operator

    must decide what type of value function will return when
        the function is being declared/defined

    void function, which does not return a value, 
        uses keyword void in the function header


    int sum(int num1, int num2)       // <--------------- int function
    {
        int result;     // variables defined inside a function are << local variables >>
        result = num1 + num2;
        return result;              //  <-------- returns an int where the function was called
    }

    
///////////////////////
//      syntax      //
//////////////////////

                                        * (expression) can be a :
    return expression;                  *       variable,
                                        *       literal
                                        *       mathematical expression
///////////////////////                 *       boolean (true/false)
//     end syntax    //
//////////////////////

                                        
********************************
   Local and Global Variables
********************************
        
    * A local variable is defined inside a function and is not accessible outside the function.
    * A global variable is defined outside all functions and is accessible to
    *       all functions in its scope
    
   <<<  Local Variables >>>

            * defined inside a function and are local to that function
            * hidden from statements in other functions (normally can't access them)
    
        ~~ Local Variable Lifetime ~~
                * local var only exists while function is executing (lifetime)
        
    *****ANY VALUE STORED IN A LOCAL VARIABLE IS LOST BETWEEN CALLS TO THE FUNCTION*****

    [initilize local variables with parameter values]

    int sum(int num1, int num2)
    {
        int result = num1 + num2;
        return result;
    }

    <<< Global Variables >>>

            * Any variable defined outside all the functions in a program
            * scope == variable definition --> end
            * initialized to 0 unless explicitly initialized
            * char variables are initialized to NULL
            
            ** Generally want to avoid using global variables.
                    - make debugging difficult bc it could be accessed anywhere
                    - func's using global vars are dependant on them when reused
                            so they need to be redesigned
                    - global vars make a program hard to understand
                            -- need to be aware of all the other parts of a program
        Global Constants
            ** An excellent idea because they don't change

   <<< static variables >>>

            * local variables that retain their value after the function terminates
            * exist for the lifetime of the program even though their scope is the
            *           the function that they were defined in
            * all static variables are initialized to 0 by default
            * initialization only occurs one time no matter how many function calls

    
********************************
        Default Arguments
********************************

    * Default arguments are passed to parameters automatically if no arg is provided in function call
    * Must be a literal value or a named constant

void showArea(double = 20.0, double = 10.0);        // function prototype


void showArea(double length = 20.0, double width = 10.0);        // function prototype
                                                        // you can optionally include the var names

        ** not all parameters need to have default values

void calcPay(int empNum, double hours = 40.0, double payRate);  // ERROR!!!

        ** vars with default values must be defined LAST
    



        Because the parameters are optional, they can be optionally passed

        *Legal*                                 Not Legal
    -------------------                         -----------------
    showArea();                                 showArea( , 5.5);
    showArea(12.0);                             calcPay(12.0, ,50)
    showArea(12.0, 5.5);

        when an argument is left out to use the default value, all args afterwards
                    need to be left out as well
                    

***********************************************
    Using Reference Variables as Parameters
***********************************************

        * When used as parameters, reference variables allow a function
        *       to access the parameter's original argument. Changes to the parameter
        *       are also made to the argument.
        
    
  <<< reference variable >>>
    
        an alias for another variable

        *defined like regular variables prefixed with &
        //                                                   NOTE:       
        void doubleNum(int &refVar)             //  &refVar is referred to as:
        {                                       //      a reference to an int
            refVar *= 2;
        }

        void doubleNum(int &);
        void doubleNum(int&);

        :::: NOTES::::

            * &refVar is referred to as <<    a reference to an int     >>
            * the ampersand must appear in both the prototype and the header

            * be aware if you're passing by reference vs value
            * source of many bugs


            
***********************************************
            Overloading Functions
***********************************************

    *** Two or more functions may have the same name, 
                --- as long as their parameter list is different
                -alternative to having two different function names
    
        double calcPay(double, int);
***********************************************

    *** Two or more functions may have the same name, 
                --- as long as their parameter list is different
                -alternative to having two different function names
    
        double calcPay(double, int);
        double calcPay(int);

        would be two different function calls due to overloading.

    (((   Function Signature   )))

                - the name of the function and the data types of the function's parameters in the proper order

                -signatures-
                calcPay(double,int)
                calcPay(double)
                
                function call gets matched up with the signatures
                    ** notice the return type is not in the signature
                    this means that these functions cannot be used in the same program

                int square(int number);
                double square(int number);
                


***********************************************
         The     exit()    Function
***********************************************

        exit(0);                // 0 commonly interpreted as program success
        exit(EXIT_FAILURE);     // named constants in <cstdlib> that indicate program failure
        exit(EXIT_SUCCESS);     // or success under the current operating system
            
            * causes the program to terminate, regardless of which function
            *       or control mechanism is executing.
            * returns the integer value outside the program to indicate whether the
            *       program ended with failure or successfully


            **#include <cstdlib>


***********************************************
                Stubs and Drivers
***********************************************
    * tools to aid in debugging programs that use functions
    * allow to test individual functions in a program in isolation
                from the rest of the parts of the progrm
   

    ~~  stub   ~~
------------------------

    * dummy function that is called instead of the actual function is represents

        -- usually displays a text message saying that it was called and nothing more

    void showFees(double memberRate, int months)
    {
        cout << "The showFees function was called with "
            << "the following arguments:\n"
            << "memberRate: " << memberRate << endl
            << "months: " << months << endl;
    }


        ** replacing actual function allows you to isolate different parts of the program


    ~~  driver   ~~
------------------------
    
    * program that tests a function simply by calling it

        -- if the function accepts arguments, the drivers passes test data
    
        -- if the function returns a value, the driver displays it on screen
