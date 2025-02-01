#include <iostream>

/*
	in global scope there is only declarations
	in local scope ( not in class scope, not in namespace scope ) there is also expressions and control statements
	statements separated by semicolon
	statement:
		declaration
		expression ( x + 5; cout << x; )
		control statement
	
	binary operators: ( result is rvalue )
		+
		-
		*
		/
		%
		<<
		>>
		|
		& takes integer and returns integer
		^ 
		&& takes bool and returns bool, short-circuit evaluation ( so v[4] is safe in ( v.size() >= 5 && v[4] == 1 ) )
		|| short-circuit evaluation
		>
		<
		==
		<=
		>=
		!=
		<=> since c++20

	assignment operators: ( result is lvalue )
		=
		+=
		-=
		*=
		/=
		%=
		<<=
		>>=
		|=
		^=
		&=
		
	you can redefine operators for your types
*/

int main ( void )
{
	int x, y, z;
	
	std::cout << ( x = y ) << std::endl;
	std::cout << ( ( x = y ) = z ) << std::endl;
	
	x = y; // lvalue
	x = y = z; // lvalue
	x + y; // rvalue
	x += y += 5;
}