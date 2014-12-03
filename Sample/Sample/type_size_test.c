#include <stdio.h>
#include <stdlib.h>

#define psize( _t ) printf("\n sizeof( %s ) \t= %lu", #_t , sizeof( _t ) )

#define NL printf("\n")

int main(int argc, char *argv[]) 
{ 
    psize( void );//no type
    NL;
    psize( char );//character
    NL;
    psize( int );//number
    psize( short );
    psize( long );
    NL;
    psize( float );//real
    psize( double );
    psize( long double );
    NL;
    psize( unsigned char );//unsinged variants
    psize( unsigned int );
    psize( unsigned long int );
    psize( unsigned long long int );
    NL;
    psize( signed char );//signed variants
    psize( signed int );
    psize( signed long int );
    psize( signed long long int );
    NL;
    psize( char* );//pointers
    psize( int* );
    psize( short* );
    psize( long* );
    psize( float* );
    psize( double* );
    psize( void* );
    
    psize( wchar_t );
   
    return 0;
}
/* _________OUTPUT___________
 sizeof( void ) 	= 1

 sizeof( char ) 	= 1

 sizeof( int ) 	= 4
 sizeof( short ) 	= 2
 sizeof( long ) 	= 8

 sizeof( float ) 	= 4
 sizeof( double ) 	= 8
 sizeof( long double ) 	= 16

 sizeof( unsigned char ) 	= 1
 sizeof( unsigned int ) 	= 4
 sizeof( unsigned long int ) 	= 8
 sizeof( unsigned long long int ) 	= 8

 sizeof( signed char ) 	= 1
 sizeof( signed int ) 	= 4
 sizeof( signed long int ) 	= 8
 sizeof( signed long long int ) 	= 8

 sizeof( char* ) 	= 8
 sizeof( int* ) 	= 8
 sizeof( short* ) 	= 8
 sizeof( long* ) 	= 8
 sizeof( float* ) 	= 8
 sizeof( double* ) 	= 8
 sizeof( void* ) 	= 8
 sizeof( wchar_t ) 	= 4
*/
