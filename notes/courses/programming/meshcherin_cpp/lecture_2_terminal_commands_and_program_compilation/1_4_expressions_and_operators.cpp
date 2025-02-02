#include <iostream>

/*
	in global scope there is only declarations
	in local scope ( not in class scope, not in namespace scope ) there is also expressions and control statements
	statements separated by semicolon
	statement:
		declaration
		expression ( x + 5; cout << x; )
		control statement
	
	binary operators ( arithmetic, bitwise, logical, comparison ): ( result is rvalue, left-associative for all types )
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

	assignment operators: ( result is lvalue, right-associative for all types )
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

    a*a*a*a != (a*a)*(a*a) for float
    for float precedence depends on how we are calculating result, so compiler does not optimize such expressions
    since C++17 short-cicuit evaluation property keeps for used defined types
*/

void f ( int ) {}
void f ( double ) {}
void g ( int, int ) {}

int h( void )
{
    std::cout << 1 << std::endl;
    return 1;
}

int i( void )
{
    std::cout << 2 << std::endl;
    return 2;
}

int j( void )
{
    std::cout << 3 << std::endl;
    return 3;
}



int main ( void )
{
    std::cout << ( h() * i() + j() * h() + j() * i() ); // order of evaluation can be any
    
    
    
    
	int x, y, z;
	
	std::cout << ( x = y ) << std::endl;
	std::cout << ( ( x = y ) = z ) << std::endl;
	
	x = y; // lvalue
	x = y = z; // lvalue
	x + y; // rvalue
	x += y += 5;

    ++x; // lvalue = new x
    x++; // rvalue = old x

    // ++ operator accepts only lvalue as an argument

    ++( x = 5);
    // ++x++; // = ++(x++) because postfix operations has priority over prefix operations; error: lvalue required as increment operand
    // x+++++y; // lexical parser work by principle 'I take as many characters as possible as long as these characters form a valid token'
    ++++x; // ++(++x); greedy lexical parser
    /*
        lexical parser algorithm:
            x+++++y;
            x okay, identifier
            x+ not okay -> x is the first lexeme
            + okay, operator +
            ++ okay, operator ++
            +++ not okay -> ++ is the second lexeme
            + okay, operator +
            ++ okay, operator ++
            +++ not okay -> ++ is the third lexeme
            + okay, operator +
            +y not okay -> + is the forth lexeme
            y okay, identifier
            y; okay -> y; is the fifth lexeme

        prefix of identifier is considered as identifier:
            int a;
            i okay, identifier
            in okay, identifier
            int okay, identifier
            'int ' okay, keyword
    */

    1 ? true : false; // casts first argument to bool, short-circuit evaluation

    bool b;
    // ( b ? x++ : ++x ) = 1; // error: lvalue required as left operand of assignment
    b? x++ : 1; // okay, we are not mixing rvalue and lvalue
    ( b ? x : ++x ) = 1; // okay, we are not mixing rvalue and lvalue
    // ( false ? x++ : ++x ) = 1; // error: lvalue required as left operand of assignment; also compilation error because it is syntax error
    ( false ? x++ : ++x ); // okay
    int integer; float floating_point_number;
    false ? 1 : 1.0;
    
    f ( b ? 1 : 1.0 ); // f( double will be called, because type of ( b ? 1 : 1.0 ) expression is double ) 

    // operator ,
    b, integer; // evaluates b, only then evaluates integer and returns integer, has the same value type as integer
    ( b, integer ) = 1;
    
    g ( x++, x++ ); // order of evaluation can be any
    f( ( x++, x++ ) );
    
    // C++ Operator Precedence
    
    // Order of evaluation
    
    // Sequenced before rules
    
    /*
        assymetric, transitive, pair-wise relationship between evaluations within the same thread
        
        A < B <-> B > A evaluation of A will be complete before evaluation of B begins
        A !< B and B < A evaluation of B will be complete before evaluation of A begins
        A !< B and B !< B: unsequenced or indeterminately sequenced
        
        f( g(), h() ); g, h < f
        
        since C++17 in every simple assignment expression E1 = E2 and every compound assignment expression E1 @= E2, every value computation and side effect of E2 is sequenced before every value computation and side effect of E1
    */
    
    x++ * y++ + ++x;
    
    x = 0;
    
    // x++: side effect ( change of x ) and value computation ( return value ) 
    
    
    
    ++x = x++; // until C++17 x can be 0, 1 or 2, because there was no order between side effects and value computations for operator =
    
	++x = x++; // since C++17 it is okay
	
	i = ++i + i++; // undefined behavior
}