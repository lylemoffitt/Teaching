

//
// A struct is just a collection of objects. If you think of an array as a set
// of items of the _same_ type, which are accessed by _index_, then a struct is
// just a set of objects of _arbitrary_ type, which are accessed by _name_ .
//
// For example, the following two variables are can be thought of as being
// essentially the same thing:
//
    int var1 [5]  = {1,2,3,4,5};
    struct var2{ int _1,_2,_3,_4,_5; };
//
// Before the 1999 version of C, the syntax for declaring a struct was:
//
    struct _name_of_struct_ {
        _variable_declaration_0;
        _variable_declaration_1;
        .                     .
        .                     .
        .                     .
        _variable_declaration_N;
    };
//
// After that, every time it's declared it needs to be preceded by the keyword
// 'struct'.
//
    struct ratio{ int numerator; int denominator; };
    double eval_ratio( struct ratio * r){// <- declare pointer to struct
        return ( r->numerator / (*r).denominator );
        // above: 2 different syntaxes for accessing the members of
        // a pointer to ratio. The first is the "arrow operator", the second
        // is a dereference of the pointer, followed by the "dot operator" for
        // member access.
    }
    // examples of "aggregate initialization"
    struct ratio r1 = { 1, 2 };
    struct ratio r2 =
    {
        .numerator = 1,
        .denominator = 2
    };
    struct ratio r3;
    r3.numerator = 1;//dot operator to member access
    r3.denominator = 2;

    assert( eval_ratio( & r3 ) == 0.5 );
                    //  ^ = "reference operator" gets address for pointer
//
// A common idiom to get around the need to keep using 'struct' is to use a
// 'typedef' to declare it as a type, i.e.:
//
    typedef     struct ratio    ratio_type;
//
// After that the new type name can be used anywhere just like any other type
// name, like 'int', 'char', etc. A more concise way of doing the above is:
//
    typedef struct { /*data members*/; } new_type;


// An enumeration (or 'enum') is a type which has a limited, and specific set of
// possible values. They are used typically as either a nice way of defining
// constants or as a type-safe way of defining a state flag;
//
// The syntax for declaring an 'enum' is similar to that of a 'struct':
//
    enum enum_name
    {   value_name_0,
        value_name_1 /* optionally give explicit value */ = 3,
        .          .
        .          .
        .          .
        .          .
        value_name_N,
    };
//
// By default the values defined in an 'enum' will start at 0, and increment by
// 1 for each value name, i.e. the following would be the case:
//
    enum trinary_state{ true, false, unknown };
    assert( true    == 0 );
    assert( false   == 1 ); //<- No need to scope to the word
    assert( unknown == 2 );
//
// The names defined in an 'enum' are visible in the scope of the block they are
// declared in. That's why the members of the above 'enum' are accessed by name
// directly, instead of the following:
//
    typedef struct { // typedef an anonymous struct
        enum { true, false, unknown };// containing an anonymous enum
    } tri_bool;// <- name of type
    assert( tri_bool::true    == 0 );
    assert( tri_bool::false   == 1 ); //<- Uses "scope operator" to specify
    assert( tri_bool::unknown == 2 );
//
// The latter means that you can use the identifiers defined in the 'enum' in
// other scopes. In the former case, the identifiers: 'true', 'false', & 'unknown'
// effectively would act as global constants. Everywhere the word "true" would
// show up, it could be interpreted by the compiler as that enum value.
// For example:
//
     int example_1( trinary_state t ){
         int false = 5; // here "false" clearly means this int
         return false; // here "false" is ambiguous
         // does the function return 5 or 1 ?
     }
     int example_2( tri_bool t ){
         int false = 5;
         assert( false != tri_bool::false );
         return false; // "false" is clearly the variable
     }
//
// A union is like a struct, except that all the members of a union occupy the
// same space. For example:
// 
    union int_char {
        int i; char c;
    }
    assert( sizeof(union int_char) == sizeof(int) );
    assert( sizeof(union int_char) >= sizeof(char) );
// 
// Because 'char' is smaller that (or at least the same size as) 'int', the
// total size of the union is as big as its biggest constituent (the 'int').


