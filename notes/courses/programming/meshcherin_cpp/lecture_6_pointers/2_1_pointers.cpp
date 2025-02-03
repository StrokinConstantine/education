#include <iostream>
#include <vector>
#include <cstdio> // = #include <stdio.h>; c = C library
/*
	variables can be stored not only in RAM, but also in CPU cash or hard drive
*/

int main ( void )
{
	int x = 0; // located in memory with address equal to 4n ( double 8n )
	int* px = &( x ); // * is a part of the type, & : lvalue -> rvalue
	int y = *( px ); // * is operator of dereference, * returns lvalue
	
	px + 1; // + : ( T*, int ) -> T*; = px + sizeof( T ) * 1
	
	using std::cout;
	
	++px;
	px++;
	--px;
	
	std::vector<int> v = { 1, 2, 3, 4, 5 }; // std::vector guarantee that elements located contiguous
	
	int* p = &v[0]; // postfix > prefix
	
	cout << *p  << "\n" << *(p+1) << "\n";
	
	p += 2;
	
	
	// pointer can be dead reference
	
	cout << &v[1] - &v[5] << "\n"; // <, <=, ==, >, >=
	
	int z; double zz;
	
	// &z << &zz; // error: invalid operands of types 'int*' and 'double*' to binary 'operator<<'
	
	*(&z + 1); // undefined behavior
	
	nullptr; // NULL in C, #define NULL 0
	
	
	scanf("%d", z);
	 
}