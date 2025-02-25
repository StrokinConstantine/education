#include <iostream>
#include <array>

// in C++20 number of context where dependent name is obvious typename was reduced ( you do not need always write "typename" )

// syntax parsing -> template instantiating

template <typename T>
struct S
{
	// using A = int;
	template <int N>
	using A = std::array<int, N>;
};


// two phase translation
/*
	first phase: before T substitution compiler looks on syntax and base semantic ( independent from T )
	second phase: after T substitution
	( if you want find errors in code, just instantiate your template )
*/

int x;

template <typename T>
void f()
{
	// S<T>::A * x; // declaration or expression? 
	// A is dependent name ( typename or variable )
	
	// by default all dependent names parsed as expressions
	
	// typename S<T>::A* y; // now this will be syntactically parsed as declaration
	
	// typename S<T>::A < 10 >  x; // A < 10 > x or A<10> x
	
	typename S<T>:: template A < 10 >  x; // now with "template" syntax parser will understand that this is template
}


template<typename T>
struct SS
{
	template<int N>
	void foo(int) {} // dependent name
};

template<typename T>
void bar(int x, int y)
{
	SS<T> s;
	
	
	// s.foo<5>( x + y ); // error: invalid operands of types ‘<unresolved overloaded function type>’ and ‘int’ to binary ‘operator<’
	
	s.template foo<5>( x + y ); // okay, expression not s.foo < 5 > ( x + y )
}




template <typename T>
struct B
{
	int t = 0;
};

template<>
struct B<double>
{
	//int t() {}
};

template <typename T>
struct C : B<T>
{
	void f()
	{
		// ++t; // error: ‘t’ was not declared in this scope
		++(this->t); // use this pointer for parent members when parent class is a template
		++(B<T>::t); // also okay
	}
};




int main()
{
	
	// C c; // error: class template argument deduction failed
	
	C<int> c1;
	c1.f();

	// C<double> c2;
	// c2.f();
	
	
	bar<int>(2,3);	
	f<int>();
	// f<double>(); //  error: ‘typename S<double>::A’ names ‘constexpr const double S<double>::A’, which is not a type
	
}