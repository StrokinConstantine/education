#include <iostream>

struct A
{
	int x = 1;
	
	A( const A& other ) : x(other.x) { std::cout << "A copy ctor"; }
	A() = default;
};

struct B : A
{
	int x = 2; // B has subobject of type A
	B() = default;
};

void f( A& a )
{
	std::cout << a.x << std::endl;
}

void g( A a )
{
	std::cout << a.x << std::endl;
}

void h( A* a )
{
	std::cout << a->x << std::endl;
}

int main()
{
	B b;
	
	f(b); // implicit cast to A&
	// <-> const and non-const
	
	g(b); // slicing, the constructor A( B b ) will be generated ( or A( B& b )? ), subobject of type A will be copied ( through copy ctor )
}