#include <stdio.h>


/*
	forward declaration = declaration precedes the definition
	if there is no definition of a tagged type but only a declaration, it is called an incomplete type
	we can only work with pointers to incomplete type, but we can never create variable, dereference pointer or work with arrays of such type
*/


int f ( int ); /* declaration, function protorype */
int g ( int );

struct linked_list; /* incomplete type */

struct linked_list* h(){} /* okay */
struct linked_list i(); /* okay */
struct linked_list j(){} /* error: return type is an incomplete type */


int f ( int ){ return g( 0 ); } /* definition */
int g ( int ){ return f( 0 ); }


int main ( void )
{
	
	return 0;
}