#include <iostream>


struct A
{
	virtual void f( int x = 1 )
	{
		std::cout << "A::f" <<  x << std::endl;
	}
};

struct B : A
{
	void f( int x = 2 ) override
	{
		std::cout << "B::f" <<  x << std::endl;
	}
};


int main()
{
	B b;
	A& a = b;
	
	a.f(); // B::f1
	b.f(); // B::f2
	/*
		we must set default argument in compile time -> type A -> 1
	*/
}