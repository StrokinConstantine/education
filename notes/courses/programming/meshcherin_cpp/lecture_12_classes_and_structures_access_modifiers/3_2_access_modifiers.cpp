/*
	friends ( classes and functions ) can access private members
	friend relation is not symmetric, is not transitive
	
	do not use friend keyword, bad code style
*/

#include <iostream>

class C
{
private: // you can access y only within C
  int x = 2;

private:
  int y = 5;


	friend void g( C ); // function friend
	friend void h ( C c ) // definition right here, it is okay, but do not write like that
	{
		std::cout << c.x << std::endl;
	}
	
	friend class D;
	friend struct F;
	
};


struct F
{
	
};

class D
{
	
};

void g( C c )
{
	std::cout << c.x << std::endl;
}



class C1
{
private:
	class Inner
	{
	public:
		int x = 1;
	private:
		int y = 2;
	};

public:
	Inner f()
	{
		return Inner();
	}
	
};

class C2
{
private:
	void f ( float )
	{
		
	}

public:
	void f ( int )
	{
		
	}
	
	void f ( double )
	{
		
	}
};


int main()
{
	C2 c2;
	
	c2.f( 2 );
	// c2.f( 2.0f );
	c2.f( 2.0 );
	
	C1 c;
	// c.x; // error: ‘int C::x’ is private within this context; access error ( it occurs only after checking existence of name and ODR )
  
	// C1::Inner in; // error: ‘class C1::Inner’ is private within this context
	std::cout << c.f().x << std::endl;
	std::cout << (int&)(c); // undefined behavior
  
}