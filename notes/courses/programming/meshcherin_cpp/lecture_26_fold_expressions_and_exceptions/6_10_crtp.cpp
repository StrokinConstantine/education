#include <iostream>

// curiously recursive template pattern

template <typename T>
struct A
{
	// T x; // error: ‘A<T>::x’ has incomplete type
	
	T* y; // we only need declaration to make a pointer
	
	// T& z; // error: uninitialized reference member in ‘struct A<B>’
	
	void interface() 
	{
		static_cast<T*>(this)->implementation();
	}
	
	static void static_func()
	{
		T::static_sub_func();
	}
};

struct B : A<B>
{
	void implementation()
	{
		std::cout << "B::implementation" << std::endl;
	}

	static void static_sub_func();
};

template <typename T>
void f(  A<T>& a)
{
	a.interface();
}

int main()
{
	
	B b;
	
	b.implementation();
	
	A<B> a;
	
	a.interface();
	
	f<B>( b );
	
	return 0;
}