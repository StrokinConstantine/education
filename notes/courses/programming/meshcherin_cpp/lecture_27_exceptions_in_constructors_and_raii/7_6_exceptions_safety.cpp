#include <iostream>

// 7_6_exception_safety.cpp

// exception specification (specificator noexcept)
void f() noexcept // since C++11, f does not throw exceptions, otherwise std::terminate
{
    
}


template <typename T>
void g() noexcept( std::is_reference_v<T> /* compile time condition */ )  
{
	
}
// noexcept( noexcept( Allocator() ) ) - depend on noexceptance of constructor

template <typename T>
void h() noexcept(  noexcept(   g<T>(); )    )  // оператор внутри, снаружи спецификатор
{

		 noexcept( g<int>() ); // operator noexcept(), does not evaluate expression, just understatnd's is it noexcept
 
		 
		 // all operators are noexcept except new , dynamic_cast, typeid, throw.
}


void ff() noexcept try {
	
} catch ( ... )
{
	// okay
}

// std::vector<T, Allocator>::operator[] - not noexcept why? 

//semantic of noexcept not just about exceptions

// semantic is about nothing bad will happen after calling the method



// every function can not return value, but throw an exception 


// There are four levels of exception guarantee

// 1 nofthrow

// 2 strong : functions after exception returns previous state of the program, ( возвращает всё назад, как-будто мы не вызывали функцию (и только потом пробрасывает исключение наверх)
// std::vector::push_back

// ( destructors  are noexcept by default since C++11 ) 

