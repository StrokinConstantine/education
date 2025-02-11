#include<iostream>

struct s
{
	int x;
	double y;
	
	void f( int z )
	{
		std::cout << 2 + z;
	}
};

enum e_1 // do not write it
{
		WHITE, // <-> global int WHITE = 0;
		GREY,
		BLACK
};

enum class e_2 : int8_t // since C++11, this is not global
{
	WHITE = 0,
	GREY = 23,
	BLACK
	
};

int main()
{
	int s::* p = &s::x; // pointer to s::x, p is just an offset from start of the class
	s s_1{1, 2.0};
	
	std::cout << ( s_1.*p = 7 ); // operator.*
	
	s* ps = &s_1;
	
	std::cout << ps->*p; // operator->*
	
	void ( s::* ptr )(int) = &s::f;
	
	(s_1.*ptr)( 3 );
	
	(ps->*ptr)( 3 ); // signals and slots in Qt
	// you can overload -> and ->*
	
	int e1 = WHITE;
	e_1 e2 = WHITE;
	
	e_2 e3 = e_2::WHITE;
}