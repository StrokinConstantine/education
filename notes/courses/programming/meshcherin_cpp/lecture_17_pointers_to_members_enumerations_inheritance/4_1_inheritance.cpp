#include <iostream>


// In the oriented graph representing friend relations, the number of edges is equal to the number of occurrences of the word 'friend' in the code

struct a
{
private: // available for friends
	int z;
	
	void f1() {} // do not use this-> for fields in C++
	
protected: // available for friends, inheritors
	int x;
	
public:
	void f() {}

};

/*
	the difference between availability and visibility
	in structures by default everything is public, including parents
	private inheritance: only I and my friends know about parents
	protected inheritance: only I and my friends and inheritors know about parents
*/

struct b : a // public inheritance because b is a structure, scope of b is a subscope of a
{
	int y; // here z and f1 are visible, but not available
	void g()
	{
		// here compiler trying to find z in class scope, he finds it, but z is not available
		// std::cout << z;
		std:: cout << x; 
	}
};

class c : a {}; // private inheritance
class d : public a {}; // private inheritance


class x
{
protected:
	int a;
	
	// friend class z;
	// friend class y;
	// friend int main();
};

class y : protected x // now y has a part x
{
	// friend class z;
	int b;
	
public:

	void g()
	{	x x_1 = x();
		std::cout << a << std::endl;
		// x_1.a; error: ‘int x::a’ is protected within this context
	}

};

class z : protected y
{
	int c;
	
public:
	
	void f( x& x_1 )
	{
		std::cout << a << std::endl;
		// x_1.a; // error: ‘int x::a’ is protected within this context
	}
};


int main()
{
	z z_1;
	x x_1 = x();
	
	z_1.f( x_1 );
	
	//  z_1.a; // error: ‘int x::a’ is inaccessible within this context
}