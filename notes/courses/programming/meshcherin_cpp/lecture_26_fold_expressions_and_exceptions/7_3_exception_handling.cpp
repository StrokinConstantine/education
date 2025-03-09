#include <iostream>


struct A
{
	A() { std::cout << "creation of " << this << std::endl; }
	
	A( const A& a) { std::cout << "copying " << &a << " to " << this << std::endl; }
	
	~A() { std::cout << "destruction of " << this << std::endl; }
};

void f( int x )
{
	A a;
	if ( x == 0 )
		throw a; // a will be copied to dynamic memory, __cxa_allocate_exception - standard 
	// if it is bad_alloc, compiler has reserved place in static memory for exceptions
}

int main()
{
	// uncaught exception = UB -> destructors may not be called
	// throw of an exception is 100 times more time-consuming than virtual function call
	
	// std::endl -> flush of output buffer of sout ( string -> buffer -> sout )

	// flush of buffer leads to output
	try
	{
	
		try
		{
			f( 0 );
		} catch ( A a ) // copying dynamic 'a' to stack
		{
			std::cout << "caught" << &a << std::endl;
			// here dynamic "a" will be destroyed
			// __cxa_free_exception
			
			// throw; // throw; in catch means to continue throwing 
			throw a; // destroy old 'a', create new 'a'
		} catch ( A a )
		{
			
		}
	
	} catch ( A a )
	{
		std::cout << "caught" << &a << std::endl;
		throw a;
	}
	
	


	
	
	
}