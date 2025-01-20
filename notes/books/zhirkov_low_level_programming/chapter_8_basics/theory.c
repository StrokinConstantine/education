#include <stdio.h>


typedef int new_int_typename;



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
	// literal = immediate value
	
	// expressions, having an address in memeory = lvalue, expressions without an address in memory = rvalue
	
	// 4 = 2; f(4) = 1;
	
	
	if ( 1 )
	{
		
	}
	else
	{
		
	}
	
	
	do
	{
		
	} while ( 0 );
	
	
	for ( ; 1 < 0 ; )
	{
		
	}
	
	
	
	int a;
	
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