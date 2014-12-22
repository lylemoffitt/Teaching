/* 
 ^_START
 
 This is a comment block. Anything that appears inside this block will be kept 
 as plain text. You cannot put another comment inside a comment block.
 
 The character pairs pointed to by the START and END denote the start and end of
 the block.
 
 v_END
 */

/* This is also a comment block */

//This is a single line comment. Anything folloing the "//" is part of the comment

//Any line starting with a '#' is a 'directive'. Directives are special commands
//  for the compiler, they are evaluated at compile-time before anything else.
#warning Only pre-defined directives can be used.
#warning A /*comment*/ or //comment following a #warning is plain text.


#ifdef THIS_ONCE_DEFINED
#warning THIS_ONCE_DEFINED is defined
#else
#warning THIS_ONCE_DEFINED is not defined
#endif
/* ___Task___
 You will notice that both of the above warnings will appear when you compile. 
 1) Why is this? Why not only one? How can the condition be both true and flase? 
 
 It is the case that this block of directives could not be anywhere else in 
 this file and still achive the effect of producing both #warnings. 
 2) Why? What if it were after the definition of 'THIS_ONCE_DEFINED'?
 */


#ifndef THIS_ONCE_DEFINED//This is a "conditional directive". It tests if the
                         //  following symbol, in this case "THIS_ONCE_DEFINED",
                         //  is NOT already defined. 
                         //If the evaluation proves true (as it does here), then
                         //  the succeeding lines are evaluated by the compiler.
                         //If the evaluation proves false, as it does when the 
                         //  [[ #include "learn.cpp" ]]  is processed, the compiler
                         //  ignores all suddeeding lines until a #else, #elif, or #endif
                         //  is encountered.
                         //These are always seen at the tops of header (*.h) 
                         //  files, because they are #include'd by other files.



#define THIS_ONCE_DEFINED//This is a "define directive" it simply defines the 
                         //  following symbol name in the current compilation 
                         //  unit. This definition, with the conditional at the 
                         //  top and the top forms what is called a "header guard".
                         //They prevent the compiler from re-processing headers 
                         //  that have already been included.
/* ___Task___
 There are limititations on the format of this name. What are they? Provide some
 examples of valid names, each should demonstrate a different rule.
 */
#define A_VALID_NAME_EXAMPLE// Valid b/c ....



#define stringify( expr ) #expr
/* ___Task___
 In addition to it's use as a header guard, the #define directive can also be 
 used to define a "macro function". These are function that can be used to 
 replace code with other code at compile time. For example the above function 
 macro will replace anything of the form:   
         stringify( expr )
 with all the text that follows the macro declaration until the first newline 
 is encoundered. The word 'expr' is a macro function variable, and when used, the 
 variable will expand to whatever is in its place. The '#' in the expansion tells
 the compiler to turn the expression into a literal string.
 
 1) What is printed when this code is evaluated? 
     {
        printf( stringify( hello world ) );
     }
 2) What makes these macro functions different from regular functions?
 */


#define debug( expr )               \
do{ printf                          \
    (   debug_string    ,           \
        __FILE__    ,               \
        __LINE__    ,               \
        #expr                       \
    );                              \
    std::cout<<(expr)<<std::endl;   \
}while(0)
/* ___Task___
 This is another macro function, it's spread across multiple lines. It contains 
 some spedial macros that are already defined. Example:
 
    __FILE__    This expands to the full filepath of the file in which 
                this macro is expanded.
    __LINE__    This expands to the line number of the file in which this
                macro is expanded.
 
 1) What is the purpose of the '\' on each line?
 2) Why is it ok that this macro refers to function 'printf' before it is ever
    defined (when the header <stdio.h> is #include'd)?
 3) Where can this macro be used?
 */

#include <stdio.h>//This is an "include directive", it tells the compiler where
                  //    to find the definitions for the symbols (function names,
                  //    .. variable names, constants, etc.)
                  //Any number of "#includes" may be added. They should not 
                  //    include the same files.
                  //The "<" and ">" around the word "stdio.h" signify that the 
                  //    inscluded file is a system library and should be looked 
                  //    for on the system include path. 
                  //The files that you find listed on http://cplusplus.com/ are
                  //    these kind of files.
/* ___Task___
 There are some system headers missing. Please include them. For each add a
 comment explaining why you added it.
 */
#include "extras.h"


#include "learn.cpp"//This is also an include directive, but instead of referring
                    //  to a system library, it refers to a local library. This 
                    //  is denoted by the quotes around the file name.
                    //When a file is #include'd all the contents of that file 
                    //  are interpreted by the compiler, as if they were copied 
                    //  and pasted right at the line where the "#include" is.
                    //In the case, the file name listed is this one. 


/* ___Task___ 
 There are many types in C/C++. The simplest are called "primitives" or 
 "plain old data". This is because they literally refer to just data (numbers). 
 Remember that to a computer, everything is binary. In the same way, each of 
 these just defines a space big enough to hold a certain range of numbers. 
 Here are some of the basic types. 
 You can find more here: http://www.cplusplus.com/doc/tutorial/variables/
 
    bool        A boolean value (true or false)
    char        An ASCII character. http://www.asciitable.com/
    int         A signed integer, stored as 2's-compliment.
    unsigned    A 'natural' number; i.e. whole and a number (# >= 0)
    float       A 'real' number, stored as a floating point.
    void        No type, no size.
 
 Each of these types can have a modifier. These modifier can change the meaning 
 of the type or perhaps the size. They are generally used in this order.
 
    unsigned    A version of that type without negative numbers
    signed      A version of that type with negative numbers
 
    long        A larger version of the same type
    short       A smaller version of the same type
 
    const       An unmodifiable (read-only) version of the same type
 
    *           A pointer to that type; stores the address of a variable with that type
    &           A referene to a varaible of that type
 
 What other rules regard the use of these modifiers? Try a bunch of combinations 
 and see which ones work, and which don't.
 */

//This is a variable declaration. 
//This variable is global, and can be seen in any function.
//Variable declarations have 5 important parts
const short // (1) Modifiers; part of the type specification of the object
unsigned    // (2) Basic type
equal_chance// (3) Name of the variable, the same rules for name apply as with #define
= 50        // (4) Value assigned to variable at the moment of creation
;           // (5) Semicolon to end the line

/* __ Task __ 
 Below is a more complex variable declaration. Put a commented number next to 
 each part identifying what it is. Include a guess as to what you think it means.
 */
const 
char 
* 
const 
debug_string 
= 
"%s:%03d\n\t[%s] = "
;  


//The following is a 'struct' prototype.
//  http://www.cplusplus.com/doc/tutorial/structures/
//A struct allows the programmer to define a new type as a collection of sub-types.
//It constist of 3 important parts. 
struct  // (1) The keyword 'struct'.
coin    // (2) The name that will be used to idesntify this new structure
;       // (3) A terminating semicolon. This ends the struct prototype and distinguishes
        // it from a struct definition.

//The following is a type defininition or 'typedef'. 
//  http://www.cplusplus.com/doc/tutorial/other_data_types/
//It allows one to define a new type by way of another.
//It constist of 4 important parts. 
typedef     // (1) The keyword 'typedef'
int         // (2) The name of a type that already exists.
named_type  // (3) The name of the new type (that doesn't exist)
;           // (4) A terminating semicolon. 

//The following is called a "function prototype". 
//  http://www.cplusplus.com/doc/tutorial/functions/
//It consists of 4 important parts. 
named_type// (1) The return-type of the function.
          // This is used to specify what kind of data the function will pass back, 
          //  which is important because it's the only data that will ever leave the 
          //  function directly. 
mint_a_coin // (2) The name of the function. This is important, because it 
            // identifies the function and makes it distinct from every other
            // function or variable you create.
(char param1, char param2)// (3) The parameter list, enclosed (with parens) 
                          // and comma delimited. It defines the types of variables
                          // that can be passed into the function, and what their
                          // names will be inside the function.
;// (4) A terminating semicolon. This ends the function prototype and distinguishes
 // it from a function definition.

/* ___Task___
 The above typedef defines the sam type that is returned by the function 
 'mint_a_coin'. That function should return a coin. Change the typedef to so that
 this happens.
 */
 

//The following is a function prototype
void //This function returns nothing 
print_flip(coin);//One parameter is type 'coin' but no name is given


//The following is a struct definition. It basically defines and object, 
//  what it contains (its data), and what it does (its functions).
struct coin {
    char heads='H',tails='T';//Data can be initialized or not.
    bool heads_up;
    
    void flip();// function prototype
};//end of struct definition


int math(char op, int lhs, int rhs);
int fib(int num);

/* ___Task___
 The function name 'main' is special. There can only ever be one 'main' in any 
 program. It is where the program start and ends. All global variables are 
 allocated at the same time that 'main' is, and before any line inside it is 
 ever executed. When the program exits 'main', the program stops all together.
 
 There are a few function signatures for 'main', which most compilers are 
 configured to recognize. The longest one I know of (and the one defined by the 
 POSIX standard) is shown below. List two others here:
    1)
    2)
 BONUS: List another valid function signature for 'main'
    3)
 
 */
int main(int argc, char ** argv, char ** envp)
{

    //Here are some examples of different ways to initialize variables.
    int v1;         //declared without initialization
    int v2=2;       //declared with assigned value
    int v3=3,v4=4;  //list of variables declared and assigned
    int v5(5);      //direct initialization
    int v6{6};      //list initialization
    
    
    /* ___Task___
     Here are a few different ways to specify a literal value. For each 
     comment next to it with that you think the type and value are. Then use
     'print_type' and 'debug' macros to check. Add the corrections if you're wrong.
     */
    auto l1     = -1; 
    auto l2     = -1U;
    auto l3     = 0xF2; 
    auto l4     = 0123;
    auto l5     = {3};
    auto l6     = {3,4};
    auto l7     (234);
    auto l8     ({3});
    auto l9     = 'H';
    auto l10    = '\n';
    auto l11    = "h";
    auto l12    ("\n"); 
    auto l13    = 123.0234;
    auto l14    = 1E4;
    auto l15    = 1.3e4;
    auto l16    = NULL;
    auto l17    = nullptr;
    
    print_type(l1);
    print_type(l2);
    print_type(l3);
    print_type(l4);
    print_type(l5);
    print_type(l6);
    print_type(l7);
    print_type(l8);
    print_type(l9);
    print_type(l10);
    print_type(l11);
    print_type(l12);
    print_type(l13);
    print_type(l15);
    print_type(l16);
    print_type(l17);

    
    /* ___Task___
     Literal strings can be specified with quotes or without. Both define an
     array of chracters. This is also denoted by the "[]" in the definition.
     The compiler can create an array of the correct size because the array is
     supplied at compile time. An array, btw is just a pointer to a set of values
     allocated adjacent to each other. 
     
     1) What size are the following arrays?
     2) Are s1 and s2 the same size array?
     3) Are the types of s1, s2, and s3 the same?
     4) Are (*s1), (*s2), and (*s3) the same value? 
     */
    char s1[] = "Hello";
    char s2[] = {'H','e','l','l','o','\0'};
    char* s3  = s1;
    
    debug(s1);
    debug(s2);
    debug(s3);
    
    
    /* ___Task___
     A function stops execution in the function it is currently runnig in, and 
        begins execution immediately in the function called. The function called
        is passed the arguments supplied at it's function call.
     When the function returns, the variable 'f1' is initialized with the return
        value of the function.
     What is the type of 'f1'?
     */
    auto f1 = mint_a_coin(s1[0]/*Accesses the 0th element in the array*/,'T');
    
    print_type(f1);
    
    
    
    //Functions can be used to automate tasks, and prevent the writing of
    //  repetitive code. Another way to do this is with loops. 
    //There are three kinds of loops: for, while, and do-while. Each consists of
    //  the same elements
#define init 0//initialization phase; the begining state
#define eval 0//evaluation phase will cause the loop to exit when false
#define incr 0//increment phase advances to the next state
#define act  0//action is performed every time through the loop
    
    //The FOR loop
    for( init; eval; incr ){
        act;
    }
    //The WHILE loop
    init;
    while (eval) {
        act;
        incr;
    }
    //The DO-WHILE loop
    init;
    do{ act;
        incr;
    }while (eval);
    
    /* ___Task___
     Below is a FOR loop that will run 10 times. On each pass 
     it flips a coin and prints the result.
     Create a loop for each of these:
        1) Print 10 fibonacci numbers what have the same first and last number with a WHILE loop
        2) Print the letters of the alphabet with a loop
        3) Use a loop to fill an array up with 20 fibonacci numbers.
        4) Create a DO-WHILE loop that takes 1 second to complete.
     */
    for(int i=0;    //initialize a variable counter at zero
        i<10;       //while that variable has a value less then 10, continue
        i++)        //increment the value of the counter on each pass
    {//Below is a print statement
        std::cout   //Specify that we are printing to standard output
        << i;       //Converts the variable to a string
        coin c;     //Create a new coin
        print_flip(c);
    }
    
    /* ___Task___
     Given the following typedef and for-loop, with regards to changing the type
     of 'loop_type':
        1) How many iterations will be performed if 'loop_type' is 'int'?
        2) Do 'unsigned long' and 'signed long' have the same number of iterations?
        2) What type will yield the shortest number of iterations.
     */
    typedef int loop_type;
    for (loop_type i=1; i!=0 ; i++) {}
    
    
    
    
    return 0;
}

/* ___Task___
 This a function definition. Fill it out.
 */
named_type
mint_a_coin (char param1, char param2)
{
    return named_type();
}



/* ___Task___
 The function 'print_flip' flips the coin provided and prints the result.
 fill in the code to do that.
 */
void print_flip(coin)
{
    
}

/* ___Task___
 The function below is the definition of 'flip' declared inside the struct 'coin'.
 The return type is void, and it accepts no arguments. Inside the function, it 
 is possible to access both variables that are defined inside of coin and globally.
 
 Where labeled, there should be an assignment. Change that line so that 'heads_up' 
 is assigned true/false 50 percent of the time.
 
 The variable 'v1' and 'v2' are assigned using the keyword 'auto'. This means 
 that the compiler will automatically choose the type of the variable. Change 
 the declarations so that they each have the proper type/types. 
 */
void coin::flip()
{
    auto v0 = rand();//generates a random number
    auto v1 = v0%100;//cuts that random number down to be less than 100
    auto v2 = (v1 >= equal_chance);
    
    //This is a conditional expression
    if(v2)
    {//If the expression evaluates as true this code is executed
        heads_up = true;
    }else
    {//If the expression evaluates as false this code is executed
        heads_up = false;
    }
}

/* ___Task___
 This is a function that returns the mathematical result of the two arguments
 This function uses a switch statement. A switch statement is like a
 series of IF-ELSE-IF, except much faster becasue the expression is 
 evaluated only once.
 For each put down your guess and a bried explanation before you test. Then 
 explain why you were wrong/right.
 1) What happens if op = 'A'?
 2) What value is returned for each operation if lhs=20 and rhs=3 ?  
 3) What value is returned for each operation if lhs=3 and rhs=20 ?
 4) Change every 'int' to 'float' and repeat 2/3. How do the results differ?
 */
int math(char op, int lhs, int rhs)
{  
    switch(op)
    {
        case '+':   return (lhs+rhs);//add
        case '-':   return (lhs-rhs);//subtract
        case '*':   return (lhs*rhs);//multiply
        case '/':   return (lhs/rhs);//divide
        case '%':   return (lhs%rhs);//modulus
        case '>':   return (lhs>rhs);//greater-than
        case '<':   return (lhs<rhs);//less-than
        case '=':   return (lhs==rhs);//equal
        case '!':   return (lhs!=rhs);//not-equal
        default :   assert(false && "Invalid operation.");
    }
}


/* ___Task___
 This is a recursive function. It is designed to return the Nth fibonacci number.
 1) This function has the wrong types, change them to the right type. Explain.
 2) Write a function 'isfib' that returns TRUE is the number supplied is a number
    in the sequence and false otherwise.
 3) Write a reverse-fibonacci function 'rfib' to return what number in the 
    sequence a given number is. The expression ( NUM == rfib(fib(NUM)) ) should
    always be true. 
 */
int fib(int num)
{
    switch (num) {
        case 0: return 1;
        case 1: return 1;
        default:
            return fib(num) + fib(num-1);
    }
}



/* ___Task___
 Using the '#include' directive multiple times in the same compilation unit 
 means that all the items contained will be duplicated. I prevented this 
 from happening by using the header guards, but forgot an important part. 
 Please add it and a comment on why it's needed.
 */
#endif




