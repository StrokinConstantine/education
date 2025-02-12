#include <iostream>

/*
	using x::a; ( int a; ) <-> int a;

	using namespace std; < int a;
	
	using x::f ( there is can be a lot of functions with name f ), so using x::f < void f( int ){  }

*/
class x
{
public:

	int a;
	
protected:

	
	
	void f( double )
	{
		std::cout << "1" << std::endl;
	}
	
	int f (int ){}
};

class y : public x
{
private:

	// using x::a; // we made x::a private
	
	// x::a; // expression in class definition = compile time error
	
public:

	int b;
	int a = 7;
	using x::f; // if f is protected in parent, here we can make f public 
	
	void f( int ) // the particular is preferable to the general
	{
		// shadowing of a function x::f, not overloading
		std::cout << "2" << std::endl;
	}
	
	// x::f is visible from here
};

class z : public y
{
private:

	using y::f; // here we made f private
	
public:

	// using x::a; // new declaration of a will be considered as redeclaration

	int a = 3; // it is okay
	
	// void f( x& x_ref ) { x_ref.a; }// x here will be considered as local x in z context, so this is compile time error
	void f( ::x& x_ref ) {} // okay, x will be considered as external typename 
};

int main()
{
	class y y_1;
	
	// searching for candidates for overloading ( viable candidates ) -> overloading resolution ( best candidate ) -> accessebility
	// visible = in the same scope, accessible = you have access 

	// y_1.f( );
	// y_1.x::f( 1 ); // qualified-id to access a shadowed function, if there is several x::f functions, overloading will be
	
	y_1.f( 1 );
	
	class z z_1;
	
	std::cout << z_1.x::a << std::endl;; // shadowed field, accessebility has no effects on overloading resolution
	
	std::cout << z_1.a << std::endl;;
	std::cout << z_1.y::a << std::endl;;
	std::cout << z_1.y::x::a << std::endl;
	
	// z_1.f( 1.0 ); // error: ‘void x::f(double)’ is protected within this context
	// z_1.x::f( 1.0 ); // error: ‘void x::f(double)’ is protected within this context
	z_1.y::f( 1.0 ); // okay
	
	
	
}