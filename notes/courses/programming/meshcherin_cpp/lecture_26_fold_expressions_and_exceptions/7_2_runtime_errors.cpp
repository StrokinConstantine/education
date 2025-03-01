#include <iostream>

/*
	low level errors ( OS level errors ):
		segmentation fault ( C++ level reasons: stack overflow, array out of bounds, nullptr dereference )
		floating point exception ( C++ level reasons: division by 0 )
		aborted ( C++ level reasons: std:abort() reason: std::terminate() reasons: uncaught exception, pure virtual function call )
		ctrl + C
		ctrl + D
		illegal instruction

*/

int main()
{
	try
	{
		int a;
		std::cin >> a;
		int d = 1 / a; // when CPU divides by zero it calls OS to handle this exception
		
		// class std::runtime_error : std::exception
		
	// std::logic_error - error by user ( usually user input )
	// std::runtime_error - error without user ( int overflow, file system error, ...) 
		
	} catch ( ... )
	{
		std::cout << "caught" << std::endl;
	}
	
	return 0;
}