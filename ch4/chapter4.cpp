Sequence structure 
	* statements are executed in sequence without branching off in another direction

Decision Structure
	* a specific action is taken only when a specific condition exists
	* if the condition does not exist, the action is not performed

*****************************************************************************
                        If statement
*****************************************************************************

// syntax \\

if (expression) statement;


if (expression)
	statement;


if (expression)
{
    statement;
    statement;
}

// end syntax \\


    *if the value of the expression inside the ()'s are true, the very next statement is executed
	*otherwise, it is skipped
    * braced code creates code blocks
    * braces are needed in an if statement if there is more than one statement


******************************************************************************
                        If / Else
******************************************************************************

// syntax \\

if (expression)
{
    statements;
}
else
{
    statements;
}

// end syntax \\

******************************************************************************
                            Nested if statement
******************************************************************************

if (expression)
{
    if (expression)
    {
        statements;
    }
    else 
    {
        statements;
    }
else 
{
    statements;
}


******************************************************************************
                                if / else if
******************************************************************************

if (expression_1)
{
    statements;
}
else if (expression_2)
{
    statements;
}
else
{
    statements
}

    * If expression 1 is true, the rest of the structure is ignored
    * if expression 1 is false, control moves to expression 2.
        - if expression 2 is true, the rest of the structure is ignored
        - as many else if clauses can be entered as necessary
    * else, only the else statement is run

******************************************************************************
                                flag
******************************************************************************

    * a flag is a boolean or integer variable that signals when a condition exists

/********************************************************
 *  name of the boolean flag determines its true/false 
 *  can help simplify boolean flags
 *
 *
 * ***************************************************/

******************************************************************************
                            Logical Operators
******************************************************************************

Operator        Meaning         Effect
  &&              AND           Both expressions must be true
  ||              OR            One or both expressions must be true
  !               NOT           reverses the truth of an operation


    (expression) && (expression)       Truth  Table
        *   must provide complete expressions on both sides of the && operator
        true && flase           =           false
        false && true           =           false
        false && false          =           false
        true && true            =           true

    (expression) || (expression)       Truth  Table
        *   must provide complete expressions on both sides of the || operator
        true || true            =           true
        true || false           =           true
        false || true           =           true
        false || false          =           false

    Short Circuit Evaluation
        * if the left side evaluates to false, the right side will not be checked
        * works for both AND and OR

        !(operand)                      Truth Table
            * Takes an operand and reverses its truth or falsehood
            !True               =           False
            !False              =           True


    Precedence for Logical Operators
         1       !
         2       &&
         3       ||

    *   ! has a higher order of precedence than many of the C++ operators so encapsulate
        its operand in parentheses unless you intend to apply it to a variable

        !(x > 2)  !=  !x > 2

--------
|  Note  |  :          7 < x < 10 
--------  
            would be an illegal expression


strings can be compared 
    - left to right character by character comparison of the ASCII values



******************************************************************************
                    Conditional Operator / Ternary Operator
******************************************************************************

                (expression) ? (expression) : expression;

    * Shorthand method of expressing a simple if/else statement.

ex)                                         Equivalent if/else statement:
              x < 0 ? y = 10 : z = 20;              
                |          |         |
 1st expression is tested  |         |              if (x<0)
                           |         |                  y = 10;
                           |         |              else
2nd expression executes if 1 is true |                  z = 20;
                                     |
                                    |
                                     |
                3rd expression executes if 1 is false

    ** using the value of a ternary expression **

            a = x > 100 ? 0 : 1;

        if (x>100)
           a = 0;
        else
            a = 1;
ex1 )

    hours = hours < MIN_HOURS ? MIN_HOURS : hours;
     
                equivalent to....

    if (hours < MIN_HOURS)
        hours = MIN_HOURS;
    else
        hours = hours;

ex2)

    cout << "Your grade is: " << (score < 60 ? "Fail." : "Pass.");

                equivalent too....

    if (score < 60)
        cout << "Your grade is: Fail.";
    else
        cout << "Your grade is: Pass.";


******************************************************************************
                                Switch / Case      
******************************************************************************

        * The switch statement lets the value of a variable or an expression
                determine where the program will branch.
//  syntax  \\

    switch (IntegerExpression)
    {
        case ConstantExpression:
            statements;
        case ConstantExpression:
            statements;
                           // case statements repeated as necessary
        default:
            statements;
    }

            IntegerExpression: 
                * a variable of any of the integer data types including char
                * an expression whose value is of any of the integer data types

            ConstantExpression:
                * must be of an integer type
                * may be an integer literal
                * may be a named integer constant
                * cannot be a variable or expression

         * Program branches to those statements where the value of the switch
            expression matches that of the case expression.
        ** each expression of each case statement in the block must be unique.
       *** Program branches to 'default' section if none of the case expressions match
            the switch expression (functions like a trailing 'else' statement)
    
    
    use break statements to prevent fallthrough to subsequent cases
            unless that is the desired effect...

    case 1: output1             case 1 results in only output1
        break;
    case 2: output2             case 2 results in output2 and output3
    case 3: output3             case 3 results in only output3
        break;
    case 4: output4             case 4 results in only case4
    default: blarg              all others result in blarg

        
******************************************************************************
                                   Scope
******************************************************************************

    ~~ The scope of a variable is limited to the block in which it is defined

    variables are usually defined at the top of a function
            -- on longer programs it may be better to define them closer
                    to where they are being used

    Local Scope / Block Scope
            * variables defined inside a set of braces
            * may only be used from their definition until the block's
                    closing brace


