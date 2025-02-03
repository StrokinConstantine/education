#include <iostream>
#include <vector>
/*
	formal language = vocabulary + syntax + semantics
	lexical parser divides code into array of tokens, then compiler trying to understand what is that ( declaration, expression or control statement )
		declaration -> where is the type and what is declaring there
		expression -> parse tree ( operator with the lowest priority := operator which will be on the top of the parse tree ) -> semantic binding
		
	:: not operator ( just concatenates tokens )
	you can define your literal suffixes since C++11
	int main ( void ) { } // tokens[] = { "int", "main", "(", "void", ")", "{", "}" };
	compile time errors: lexical errors < syntax errors < semantic errors
	infinite loop with no change of external state = undefined behavior
	
	The as-if rule
	
	clang++
	
	g++:
		-Wunused-value - show all warnings of this type
		-Wall - show all warnings
		-Wextra - show extra warnings
		-Wpedantic - show pedantic warnings
		-Werror - make all warnings into errors
		-Wno-error=unused-value - make unused-value errors into warnings
 
*/

#pragma GCC diagnostic push  
#pragma GCC diagnostic ignored "-Wunused-value"

#pragma GCC diagnostic pop 

bool ub_1()
{
	int table[4] = { 0 };
	// there is no undefined behavior, so we never access table[4], so loop never gets to the end, so we can always return true
	// there is no undefined behavior, so in table[4] can be anything, so we can consider that table[4] equal to 1, so we always return true
	for ( int i = 0; i <= 4; i++ )
		if ( table[i] == 1 )
			return true;
	return false;
}



int f () { std::cout << 1; return 0; }
int g () { std::cout << 2; return 1; }
int h ( int, int ) { return 2; }

int main ( void )
{
	h( f(), g()  ); // unspecified behavior
	
	// int x; // tokens[] = { "int", "x", ";" };
	// std::cin >> x; // tokens[] = { "std", "::", "cin", ">>", "x", ";" };
	// std::cout << x + 5; // tokens[] = { "std", "::", "cout", "<<", "x", "+", "5" }; 
	
	
	// @; // error: stray '@' in program; lexical error
	
	// 6ab; // error: unable to find numeric literal operator; semantic error
	// 1+; // error: expected primary-expression before ';'; syntax error
	
	// expressions are divided into subtypes; on the top level expression = operator_1_with_lowest_priority ( expression_2, expression_2 ); expression = operator_2 ( expression_3, expression_3 )
	
	// std::cout << ("123" * 5); // error: invalid operands of types 'const char [4]' and 'int' to binary 'operator*'; semantic error
	
	// int arr[0b101];
	// arr[50000] = 2;	// Segmentation fault; runtime error
	
	std::vector<int> a(10);
	// std::cout << a[100000]; // Segmentation fault; runtime error
	
	// int y = 0;
	
	// std::cout << 5 / y; // Floating point exception; error in CPU; runtime error
	
	float z = 0;
	
	std::cout << 1 / z << std::endl; // inf
	std::cout << 0 / z << std::endl; // -nan
	
	// Aborted; runtime error
	// there is function in stdlib std::abort, call of std::abort leads to termination of your program by operating system
	
	// a.at(1) = 13; // Aborted
	// a[-1] = 1000; // Aborted; double free or corruption (out); in this statement we corrupted vector ( how? )
	
	// Undefined behavior
	
	a[10] = 1; // undefined behavior
	/*
		olympiad programming problem consists of condition for tests
		you wrote your program under the assumption that test conditions are met
		if test conditions not met, your program gives undefined behavior

		condition for tests = C++ Standard
		your C++ program = test for program
		program = compiler
	*/
	
	int a1; std::cout << a1; // undefined behavior

	a1++ + ++a1; // undefined behavior
	

	
	
	
	// -O3 g++ flag for aggressive optimization
	for ( int i = 0; i < 300; ++i )
	{
		std::cout << i << ' ' << i * 12'345'678 << std::endl;
		// there is no undefined behavior, no int overflow, so i < 174, so loop condition is always true, so it is infinite loop
	}
	
	
}