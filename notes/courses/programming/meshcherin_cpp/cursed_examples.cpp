#include <iostream>

class dog
{
	
	std::string name = "Yura";
	
	friend void h ( dog my_dog ) // Definition of friend function in the class itself
	{
		my_dog.name;
	}
	
};


template <typename T>
void f( T ) {}

template <typename T>
void f( const T& ) {}

// f(0); // error: call of overloaded ‘f(int)’ is ambiguous
// f(non_const_int_var); // error: call of overloaded ‘f(int&)’ is ambiguous

template <typename T>
void g( T& ) {}

template <typename T>
void g( const T& ) {}

// g(non_const_int_var); // T&, exact match beats const conversion

template <typename T>
void h( T ) {}

template <typename T>
void h( T& ) {}

// h(non_const_int_var); // error: call of overloaded ‘h(int&)’ is ambiguous 



void v(int) { std::cout << "non temp" << std::endl;}

template <typename T>
void v (T){ std::cout << "temp" << std::endl;}

int main()
{	

	return 0;
}