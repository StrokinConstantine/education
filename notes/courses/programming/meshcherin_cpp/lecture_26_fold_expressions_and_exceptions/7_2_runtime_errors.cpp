#include <iostream>
#include <vector>
/*
	low level errors ( OS level errors ):
		segmentation fault ( C++ level reasons: stack overflow, array out of bounds, nullptr dereference )
		floating point exception ( C++ level reasons: division by 0 )
		aborted ( C++ level reasons: std:abort() reasons: false assertion, std::terminate() reasons: C++ uncaught exception, pure virtual function call )
		ctrl + C
		ctrl + D
		illegal instruction ( no "return" keyword in function )

*/

int main()
{
	
	std::vector<int> v;
	
	// Python always checks ( with ifs ) your actions, you can not access memory directly
	// 2 / 0 - ( Python interpreter level exception )
	// Floation point exception (core dumped) - message from OS
	
	try
	{
		v[100'000'000] = 1; // undefined behavior
		
	} catch ( ... ) // it is not ... in C functions, and it is not ... in fold expressions
	{
		
	}

	// future and promise in C++
	
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
	
	// in std::exception what() is virtual and destructor is virtual 
	
	return 0;
}