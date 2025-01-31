#include <stdio.h>
#include <stdbool.h> /* for bool */

typedef void( *proc_bad )( void ); /* proc ptr = &some_proc; bad definition */
typedef void (proc)( void ); /* proc* ptr = &some_proc; OK; These types can be used to write function declarations */

proc myproc; /* declaration */

int g ( int a ){ return a*a; }

int main ( int argc, char* argv[] )
{
	int i = 0;
	
	/*
		Types in C:
			* predefined numeric types
			* arrays
			* pointers ( also function pointers )
			* structures, enumerations, unions
			* functional types
			* constant types
			* type aliases
	*/
	
	char a1; /* 1 byte; type of 'x' is int ( char in C++ ) */
	char num = 5;
	char null_terminator = '\0';
	
	int a2; /* signed; all integer literals have the int type by default ( U, UL ) */
	
	long long a3; /* 8 bytes */
	
	float a4; /* 4 bytes */
	double a5; /* 8 bytes */
	/* long double a6; since C99; usually 10 bytes */
	
	1 << 48;
	1L << 48; /* 2^48 */
	
	/*
		type casting operations are encoded as assembly instructions, so it has runtime costs
		try to avoid type casting in cycles
	*/
	
	/*
		T -> T*
		& take an address of a variable
		* dereference a pointer
		if a pointer of a type int*, we know that variable has sizeof(int) bytes
		NULL = value for uninitialized pointers
		void* = pointer to any kind of data, cannot be dereferenced
	*/
	
	int arr1[] = {12, 34}; /* array's size is computed by compiler */
	
	long arr2[32] = {0}; /* array is initialized with zeros */
 	
	/*
		The size of array should be fixed 
		arr + sizeof(T) * i; this is why indices start from 0
		arr[i] <-> *(arr + i)
		T arr[] <-> T* arr
		
	*/
	
	int arr3[8] = { [1] = 29 }; /* since C99 */
	
	int whitespace[256] = { [' '] = 1, ['\t'] = 1, ['\f'] = 1, ['\n'] = 1, ['\r'] = 1 };
	
	/* you can use enum values as indices */ 
	
	/*
		suffix _t for type names is reserved by POSIX
		size_t is used to hold array lengths and array indices
		always use size_t for array indices
		
		ls -l -a; the shell will split whole calling string into pieces by spaces, tabs and newline characters and the loader will ensure that main gets this information
		
		sizeof( array ) = size of array in bytes
		
		const T <-> T const
		The const modifier on the left of the asteresk protects the data
		"abc" has type char* ( const char* in C++, so we should use this type for strings )
		"abc"[1] = 32 UB
		
		return_type (pointer_name) ( arg1, arg2, ... )
	*/
	
	for ( i = 0; i < argc; i++ )
		puts( argv[i] );
	
	int const* b1; const int* b2; /* mutable pointer to immutable int */
	int* const b3; /* immutable pointer to mutable int */
	
	apply1( g, 5 );
	
	/* since C99 you can use a format specifier %zu for size_t instead for %lu */
	
	printf("%zu\n", sizeof(void) ); /* 1 */
	printf("%zu\n", sizeof(0) ); /* 4 */
	printf("%zu\n", sizeof('x') ); /* 4 */
	printf("%zu\n", sizeof("hello") ); /* 6 */
	
	int x = 10;
	
	size_t t = sizeof( x = 90 );
	
	printf("%d\n", x ); /* x = 10 */
	
	/*
		you cannot use sizeof to get the size of an array accepted by a function as argument
	*/
	
	
	return 0;
}

void f1 ( int array[10] ) {} /* 10 just a commentary, neither runtime nor compile time checks will be performed */	

void f2 ( int array[ static 10 ] ) {} /* since C99; array will have at least 10 elements; made for optimizations */

int apply1 ( int (f)(int), int x )
{
		return f( x );
}

/* apply1 <-> apply2 */

int apply2 ( int (*f)(int), int x ) 
{
	return f(x);
}