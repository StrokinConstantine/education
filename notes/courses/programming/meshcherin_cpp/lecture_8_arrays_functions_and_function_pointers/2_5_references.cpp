#include <iostream>

int f ( int& a ) // on the low level function probably accepts pointer
{
	++a;
}

int f ( int a )
{
	
}

int& g ( int& a )
{
	int b;
	return b; // dandling reference = undefined behavior
}

int& g ( )
{
	static int y = 0
	return y; // okay, class field also okay
}

int& h ()
{
	int * ptr = new int(1);
	return *p
}

int main()
{
	int& dynamic_int = h(); // int dynamic_int = h(); would be runtime error
	delete &dynamic_int; // okay
	
	int a;
	
	int b = a; // lvalue to rvalue conversion 
	
	g ( a ) = 1; // v[ a ] = 1 ( [] returns reference )
	
	b = g ( a ); // lvalue to rvalue conversion 
	
	int x = 5;
	int& y = x; // reference to x
	
	y++; // <-> x++;
	
	int z = 5;
	y = z; // <-> x = z;
	
	int& t = y; // <-> int& t = x; there is no references to references; reference to reference = reference or compile time error
	
	&y; // <-> &x; type of &y is int*, type int&* is not exists
	
	
	std::string s1 = "abc";
	std::string s2 = s1; // new object, copy of s1 ( s1.copy() in Java )
	
	// in Java s2 = s1 means that s2 and s1 are equal references to the same object, but in C++ there is no gc
	
	{
		std::string& ref_s1 = s1;
		// when ref_s1 lifetime ends, s1 is not destroyed
	}
	
	// f ( z ); // error: call of overloaded ‘f(int&)’ is ambiguous
	f ( 2 ); // okay
	
	// int& ref_1; // error: ‘ref_1’ declared as reference but not initialized
	// int& ref_2 = 5; // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’

	++x; // not returns int, but int& ( as = and * ), because int means new copy of int
	
	int* p = &x;
	int*& p2 = p;
	
	p = new int(5);
	
	delete p2; // okay
	
	int arr_1[10];
	int (&ref_to_arr_1)[10] = a;
	// array of references does not exist
	// vector of references does not exist
	
	int (&ptr_f)(int) = f;
}