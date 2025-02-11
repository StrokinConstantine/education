#include <iostream>

class x
{
public:

	int a;
	
	void f( int )
	{
		std::cout << "1" << std::endl;
	}
};

class y : public x
{
public:

	int b;
	
	void f( ) // the particular is preferable to the general
	{
		// shadowing of a function, not overloading
		std::cout << "2" << std::endl;
	}
	
	// x::f is visible from here
};

class z : public y
{
public:

	using x::f;

	int a = 3;
};

int main()
{
	class y y_1;
	
	// searching for candidates for overloading -> overloading resolution -> accessebility 

	y_1.f( );
	y_1.x::f( 1 );
	
	class z z_1;
	
	std::cout << z_1.a;
}