/*
	data ( static memory = global variables, static local variables, string literals used in program )
	text
	stack ( automatic memory = local variables; local var = push in asm; size of stack = constant of operating system = 8 * 2^20 bytes  )
	
	dynamic memory ( allocates in runtime )

*/

#include <iostream>

void f( void )
{
	new int;
}

void g()
{
	static int x = 0; // initialization will be made only during first call of g
}

int main()
{
	// int *p = new int; // request memory from the operating system
	int *p = new int(5); // request memory from the operating system with initialization
	delete p; // free memory, in C++ you should do it by yourself, there is not garbage collector ( Java, C#, Python )
	
	
	
	// int* arr_ptr = new int[10];
	int* arr_ptr = new int[10]{}; // zero
	{
		int* pp = new int(10);
		// memory leak, now we can't free memory; this is not undefined behavior
	}
	
	// delete[] ++arr_ptr; // undefined behavior
	delete[] arr_ptr;
	
	while ( 1 )
	{
		f();
	}
	
	int *pp = new int;
	
	// delete p, pp; // = delete p;
	// delete (p, pp); // = delete pp;
	
	// top, htop
}
