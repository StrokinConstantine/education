#include <iostream>
#include <vector>

// 1.3 Declarations, definitions and scopes.

std::string str; // global scope

int a; // global variables initialize with default values ( a = 0 )

void f( int );
void f( int ); // okay
void f( int );
// int f( int ); // error: ambiguating new declaration of ‘int f(int)’


void g( int8_t );
void g ( int64_t ); // overloading

/*
	One Definition Rule (ODR) = every enity used in program should be defined only one time ( not for namespaces )
	we can redefine a class ( and a structure ) in different translation units ( files ), but only if definitions are semantically equal
	definition -> declaration
	in class all methods are considered declared
	for variables definition -> declaration, only if there is no keyword ( extern ) that says that it is not

*/


static int i; // definition, we made int i available only in current translation unit

void f( int x )
{
	// int x; // error: declaration of ‘int x’ shadows a parameter
	int b; // definition, but not initialization
	int c = 1; // definition and initialization
	
	{
		
		
		// do something
	}
	
	{
		// do something
	}
}

class C
{
	int a; // class scope
};


struct S;

union U;

namespace N
{ 
	int x = 5;
	int c = 6;
	int a; // namespace scope
} // to make names of your entities do not overlap

namespace N
{
	int b; // namespace scope
	int d = 12;
	int e = 9;
	int f = 3;
	extern int dd; // declaration and not definition
}

extern int dd; // declaration and not definition
extern int dd; // declaration and not definition

namespace NN
{
	// using N::x;
	int b = 5; // namespace scope
	int c = 6;
	int e = 1;
	int f = 4;
	
	namespace NNN
	{
		int c;
	}
	
	namespace NN
	{  
		int b;
	
		namespace NN
		{
			int x;
		}
		
	
	}
}

namespace NN
{
	namespace NN
	{
		int c;
	}
}

void b( void )
{
	NN::NNN::c;
	NN::NN::NN::x;
	NN::NN::b;
	NN::NN::c;
}

namespace X::X // since C++17
{
	
}


// using namespace N; // access to all entities in namespace N 





using N::d;

template <typename T>
using v = std::vector<T>;

// overloading
void h( double ){ std::cout << "double" << std::endl; }
// void h( float ){ std::cout << "f" << std::endl; }
void h( int ){ std::cout << "i" << std::endl; }
void h( long ){ std::cout << "l" << std::endl; }
void h( long long ){ std::cout << "ll" << std::endl; }
void h( long unsigned ){ std::cout << "lu" << std::endl; }
void h( long long unsigned ){ std::cout << "llu" << std::endl; }



int x = 7;

int main()
{
	x; // unqualified-id
	N::x; ::x; // qualified-id
	
	// promotion has priority over conversion: float -> double > float -> int
	// conversion has priority over user defined conversion
	// compiler translates every function call to jump to particular address
	
	h(0.1);
	h(0.1f);
	h(1);
	h(1L);
	h(1LU);
	h(1LL);
	h(1LLU);
	
	
	
	/*
		point of declaration = point in code from which the variable name starts to work
		in case of int x = x; point of declaration is immediately after 'int x', it means that int x = x; <-> int x; 
		reading uninitialized variable -> undefined behaviour
	*/
	int x = x;
	// std::cout << x;
	
	
	
	// program = ( after preprocessing ) sequence of declarations
	// in some cases you can add your functions to std namespace ( hash function for unordered_map )	
	
	using N::a; // access a in namespace N
	
	// std::cout << a;
	
	using std::cout;
	
	using vi = std::vector<int>; // ( using = typedef++ )
	// using N::x;

	
	// cout << a;
	
	// keywords: using, int, return, ...
	
	
	int x1;
	
	//int x = 23;
	
	// cout << ::x;
	
	for ( int i = 0; i < 10; i++ ) // initialization , condition and iteration are in loop scope
	{
		int x1 = i; // okay, but now we can't access outer x1
		// std::cout << ::x1; // global x1
	}
	
	{
		{
			// it is OK to create block structure inside a function
		}
	}
	
	{
		
	}
	
	// using namespace N; // int b defined here
	int b = 1; // okay
	
	using N::c;
	// int c = 1; // error: ‘int c’ conflicts with a previous declaration
	
	// cout << b; // local variable d
	
	int d = 13; // okay
	
	// cout << d; // local variable d
	
	using namespace NN;
	using namespace N; // okay
	
	using N::f; // okay
	
	// using f = std::vector<int>; // error: ‘using f = class std::vector<int>’ redeclared as different kind of entity
	
	{
		using f = std::vector<int>; // okay
		f my_var;
		// you ca
		int bb;
		// int bb; // error: redeclaration of ‘int bb’
		
	}
	
	// cout << f; // f from NN
	// cout << e; // error: reference to ‘e’ is ambiguous
	
	

}