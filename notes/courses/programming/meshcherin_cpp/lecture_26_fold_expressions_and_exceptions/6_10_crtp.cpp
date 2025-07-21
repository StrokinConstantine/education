#include <iostream>

// curiously recursive template pattern

template <typename T>
struct A
{
	// T x; // error: ‘A<T>::x’ has incomplete type
	
//	T* y; // we only need declaration to make a pointer
	
	// T& z; // error: uninitialized reference member in ‘struct A<B>’
	
	void interface() 
	{
		static_cast<T*>(this)->implementation();
	}
	

/*	static void static_func()
	{
		T::static_sub_func();
	}*/
};

struct B : A<B>
{
	void implementation()
	{
		std::cout << "B::implementation" << std::endl;
	}

	//static void static_sub_func();
};

template <typename T>
void f(  A<T>& a)
{
	a.interface();
}

int main()
{
	
	B b;
	std::cout << &b << std::endl;
	
//	std::cout << b.y << std::endl;
	
	
	b.implementation();
	b.interface();
	
	A<B> a;
	
	std::cout << &a << std::endl;
	
//	std::cout << a.y << std::endl;
	
	
	
	a.interface();
	
	f<B>( b );
	
	return 0;
}