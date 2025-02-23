#include <iostream>

template <typename T>
void f( T x) { std::cout << "T" << std::endl; }

void f(int x) { std::cout << "int" << std::endl; }

template <typename T>
void g( T x) { std::cout << "gT" << std::endl; }

void g(int x) { std::cout << "gint" << std::endl; }

// template <typename T>
// void f( T x) { std::cout << "T" << std::endl; } // error: redefinition of ‘template<class T> void f(T)’


// in std::map default argument is std::less<key>
template  <typename T, typename U = int> // default template argument
U h(T x)
{
	std::cout << 1;
	return 0;
}

template  <typename T, typename U> // default template argument
U i(T x)
{
	std::cout << 1;
	return 0;
}


template <typename T>
void j( T x) { std::cout << "T" << std::endl; }

template <typename T>
void j( T& x) { std::cout << "T&" << std::endl; }

template <typename T>
void k( T x) { std::cout << "T" << std::endl; }

template <typename T>
void k( const T& x) { std::cout << "const T&" << std::endl; }

template <typename T>
void l( T& x) { std::cout << "T&" << std::endl; }

template <typename T>
void l( const T& x) { std::cout << "const T&" << std::endl; }

int main()
{
	int x = 0;
	f(x); // int, the particular is better than the general
	// choice of f(T) of f(int) is made before template code generation
	
	long y;
	g(y); // gT, the particular is better than the general but exact mathing is better than any cast
	
	f<int>(x); // here compiler must generate template code for f
	
	h<int>(x); // T = int 
	
	// variable type != object type
	
	// i<int>(x); //  error: no matching function for call to ‘i<int>(int&)’ 
	// i(x); //   error: no matching function for call to ‘i(int&)’ 

	j(2);
	// j(x); // error: call of overloaded ‘j(int&)’ is ambiguous
	
	// k(2); // error: call of overloaded ‘k(int)’ is ambiguous
	// k(x); // error: call of overloaded ‘k(int&)’ is ambiguous
	
	l(x); // T&, exact matching, const T& is needed constructor
	
} 


class A
{
	template <typename T>
	A( T& )
	{
		// this constructor will consume copy constructor with signature ( const A& )
	}
};