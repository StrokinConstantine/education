/*
	functions are located in text

*/

#include <iostream>
#include <algorithm>

bool compare ( int x, int y )
{
	return x < y;
}

void g ( int ) {}
void g ( double ) {}
int h ( int );

void f ( int x = 0; int y = 0 ) // default arguments
{
	
}

// variadic functions ( printf, scanf ); do not use it in C++

int main()
{
	int a[5]{6, 8, 3, 9, 1};
	
	std::sort ( a, a + 5, &compare ); // quick sort with optimizations; if &compare is not linear strict relation of order, it is undefined behavior
	
	// for ( int i = 0; i < 5; i++ )
		// std::cout << a[i] << '\n';
	
	bool (*ptr_to_function_1)(int, int) = &compare;
	bool (*ptr_to_function_2)(int, int) = compare; // function to pointer conversion

	
	// std::cout << (void*) ptr_to_function_1 << std::endl;
	
	// &g; // error: statement cannot resolve address of overloaded function
	
	// std::cout << (void*) &h; // collect2: error: ld returned 1 exit status; 2_4_function_pointers.cpp:(.text+0xac): undefined reference to `h(int)'
	
	void (*ptr_to_function_3)(int) = &g; // okay
	void (*ptr_to_function_4)(double) = &g; // okay
}