#include <iostream>
#include <cstdlib>

// templates = compile time, exceptions = runtime

int divide( int a, int b )
{
	if ( b == 0 )
	{
		throw std::logic_error("division by zero");
		// destruction of local variables -> exit function divide -> ...
	}
	
	// .at() can throw std::out_of_range
	// 1 / 0 is CPU level exception ( FPE )
	
	return a / b;
}

int main()
{
	// std::abort(); // Aborted
	
	int a = 1/0;
	std::cout << a << std::endl;
	// atoi, atol, atoll
	// ERR_NO
	
	// in C++ creation and destruction of objects are deterministic, in Java it is not
	
	// early detection of errors = the key to good code
	
	void* ptr = malloc(1'000'000'000);
	
	std::cout << "ptr = " << ptr << std::endl;
	
	free(ptr);
	
	delete ( new int(2) );
	
	try
	{
	
	// new int64_t[400'000'000'000'000LL]; // new can throw std::bad_alloc
	// dynamic_cast can throw an exception
	// throw, new, dynamic_cast, typeid - the only four operators which can throw an exception
	// new can throw std::bad_alloc
	// dynamic_cast can throw an exception ( cast to reference ) std::bad_cast
	// typeid of nullptr dereference
	
	} catch ( std::logic_error& err )
	{
		std::cout << err.what() << std::endl;
	} catch ( std::bad_alloc& err )
	{
		std::cout << err.what() << std::endl;
	}
	
	
	// include errono.h? 
	
	
	try // try and catch is more time-consuming operation than new and delete 
	{
		
		// exceptions allow us not to wrap each call to the internal function in checks to see if the function completed without an error
		
		//
	
		divide(1, 0);
	
	} catch ( std::logic_error& err )
	{
		std::cout << err.what() << std::endl;
	}
	
	// std::terminate - function is called by C++ runtime when:
	// exception is thrown and not caught
	// ...
	// std::terminate understands what happened and usually prints type of exception and .what() 

	// std::abort ( C function ) - is called after terminate, makes low level operation which asks OS for kill the program

	return 0; // error code
}