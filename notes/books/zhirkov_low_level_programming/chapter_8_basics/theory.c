#include <stdio.h> // file is searched in predefinded directories. Using the -I key one can add directories to this list.

#include "myfile.h" // file is also searched in the current directory. gcc -E file.c to see file after preprocessing.




typedef int new_int_typename;

// #define <-> NASM %define




// #define
// 1. Defining global constants

#define MY_CONST 3

// 2. Defining parameterized macro substitutions

#define MACRO_SQUARE( x )( (x)*(x) )

// 3. Defining flags to include or exclude code

void procedure_1 ( int a ) // procedures does not return any values
{
	
}


int f_1 ( void )
{
	// fucntion body = block statements
	// each block defines a lexical scope for variables
	// make variables as local as you can
}

int is_fib ( int n )
{
	int a = 1;
	int b = 1;
	
	if ( n == 1 )
		return 1;
	
	while ( a <= n && b <= n )
	{
		int t = b;
		if ( n == a || n == b )
			return 1;
		b = a;
		a = t + a;
	}
	
	return 0;
}


int main ( void )
{
	// Statements and expressions ( data entities )
	
	// 9 - expression
	// 6, a, (a || 6 + a) - expressions
	// literal = immediate value. 12, 23.2, '2' - ASCII code, "sdf" - pointer to a null-terminated string. 
	
	// expressions, having an address in memeory = lvalue, expressions without an address in memory = rvalue
	
	// 4 = 2; f(4) = 1;
	
	// Statements:
	// 1. Expressions terminated by ";" ( if these invoke no assignments or i/o operations, their impact on the program state is not observable )
	// 2. A block { }, it contains an arbitrary number of sentences.
	// 3. control flow statements: if, for, while, switch.
	
	// %d format specifier for int, %f float
	
	// use puts instead of printf
	
	// Static typing = all types of expressions, variables and literals are known in compile time
	
	int a;
	int b, c;
	int* ptr_a;

	a = b = c; /* <-> */ ( a = ( b = c ) ); // right - associative operation ( rightmost part = most deeply nested )
	
	
	1 ? 2 : 3 // the only one ternary operator
	
	
	sizeof(a); // operator; replace this with the size of variable in bytes
	
	&a; // operator; take address
	
	*ptr_a; // operator; dereference pointer
	
	// -> operator; refer to a field of a structural or union type
	
	++a; // = new a;
	a++; // = old a;
	
	// Logical operators are evaluated in a lazy way.

	// ~ bitwise negation, ^ bitwise binary xor
	
	
	
	if ( 1 ) { } else { }
	
	
	do
	{
		
	} while ( 0 );
	
	
	for ( ; 1 < 0 ; )
	{
		
	}
	
	
	

	
	switch ( a )
	{
		case 1:
		{
			
		}
		break;
		
		case 2: // every case is a label
		{
			
		}
		break;
		
		default:
		break;
	}
	
	
	
	
	
	
	
	return 0;
}