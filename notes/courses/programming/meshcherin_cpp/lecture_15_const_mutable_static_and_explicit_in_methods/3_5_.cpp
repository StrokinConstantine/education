#include <iostream>

struct C1
{
	int x;
	int y;
	
	
	void f1()
	{
		
	}
	
	/*
		you cannot change fields in const methods ( call non-const methods of fields )
	
	*/
	
	void f2() const // const after signature
	{
		
	}	
	
	void f3() const // const after signature
	{
		std::cout << "f3 const" << std::endl;
	}
	
	void f3() // overloading by const property
	{
		std::cout << "f3 not const" << std::endl;
	}
};


int main()
{
	const C1 c11 = C1();
	
	// c11.f1(); // error: passing ‘const C1’ as ‘this’ argument discards qualifiers [-fpermissive]
	
	c11.f2();
	c11.f3(); // error: increment of member ‘C1::x’ in read-only object
	
	C1 c12 = C1();
	
	c12.f3();
}