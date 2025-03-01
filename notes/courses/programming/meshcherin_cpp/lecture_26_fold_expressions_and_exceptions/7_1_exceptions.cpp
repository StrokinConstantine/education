#include <iostream>

// templates = compile time, exceptions = runtime

int divide( int a, int b )
{
	if ( b == 0 )
	{
		throw std::logic_error("division by zero");
		// destruction of local variables -> exit function divide -> ...
	}
	return a / b;
}

int main()
{
	// atoi, atol, atoll
	// ERR_NO
	
	// in C++ creation and destruction of object are deterministic, in Java they are not
	
	try
	{
	
	new int64_t[400'000'000'000'000'000]; // new can throw std::bad_alloc
	// dynamic_cast can throw an exception
	// throw, new, dynamic_cast
	} catch ( std::logic_error& err )
	{
		std::cout << err.what() << std::endl;
	}
	
	

	
	
	try // try and catch is more time-consuming operation than new and delete 
	{
		
		// exceptions allow us not to wrap each call to the internal function in checks to see if the function completed without an error
		
		//
	
		divide(1, 0);
	
	} catch ( std::logic_error& err )
	{
		std::cout << err.what() << std::endl;
	}
	
	


	return 0; // error code
}