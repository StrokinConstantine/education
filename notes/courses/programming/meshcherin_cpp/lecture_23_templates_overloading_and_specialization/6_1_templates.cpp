#include <iostream>
#include <map>
// same code for different types ( templates in C++ = generics in Java )



// swap<long long>( a, d); // we cannot initialize non-constant reference with rvalue
	
	
	
	/*
	first task of compiler: for which type T generate swap( , )?
	second task: which conversion is better?
	
	( choice of template (template overloading resolution) ( or decision that template is not needed ) -> template instantiation -> overloading resolution of everyting ( between generated code and functions ) )
	
	first compilation stage: for which types generate templates? (template code generation)
	
*/
	






template <typename T> // quantifier ( for every type T ), meta-parameter	

void swap( T& x, T& y ) // O( 3*n ) for strings, bad. How to solve?
{
	T t = x;
	x = y;
	y = t;
}


template <typename T>
T max( T x, T y ) // template function
{
	return x > y ? x : y;
}


template <typename T>
struct less
{
		bool operator()( const T& x, const T& y ) const 
		{
			return x < y;
		}
};

template <typename T>
struct greater
{
		bool operator()( const T& x, const T& y ) const 
		{
			return x > y;
		}
};

// since C++11 template using
template <typename T> // code style: (T), (U, V) or not? 
using mymap = std::map<T, T, std::greater<T>>; // in std::greater (T, T) <-> T < T? 

mymap<int> m;

// since C++14 constant template variables, example

// since C++20 template concept, example

int main()
{
	int a = 0; 
	long long b = 1;
	int c = 2;
	long long d;
	// swap( a, b ); // error: no matching function for call to
	
	swap(a, c);
	swap(b, d);
	
	
	swap<long long>( b, d);
	
	
}