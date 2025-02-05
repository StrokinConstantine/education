/*
	if you don't know which type cast you need, use static_cast

*/

#include <iostream>

int main()
{
	int a = static_cast<int>( 1.2f ); // static_cast - C++ keyword
	
	static_cast<float>( 1 ); // use static_cast for conversions between primitives and implicit conversions
	static_cast<void*>( &a );
	
	/*
		reinterpret_cast interprets bits of variable as variable of another type without changing them
		you can't do reinterpret_cast to new copy, but you can do it to reference or pointer; you can't make new object with reinterpret_cast
		it is better to avoid use reinterpret_cast
		reinterpret_cast can be used when two different structures are bitwise equal, static_cast will copy every field in this situation
		you can reinterpret_cast one pointer to any another pointer
	*/
	long long y = 1729;
	
	std::cout << reinterpret_cast<double&>( y ) << std::endl; // undefined behavior
	
	static_cast<float> ( 1 ); // make new float
	reinterpret_cast<float&> ( 1 ); // look at old int from new point of view
	
	// reinterpret_cast forbids bypass const
	
	/*
		const_cast is used when you need to remove const
	*/
}