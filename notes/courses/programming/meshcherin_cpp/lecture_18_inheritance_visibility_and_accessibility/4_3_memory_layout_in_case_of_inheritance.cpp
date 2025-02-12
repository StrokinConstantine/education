#include <iostream>

// ctors and dtors in case of inheritance



class a_1
{
public:

	int x;
	
	a_1( int x_arg ): x( x_arg ) { std::cout << " a_1 ctor body " << std::endl; }
	
	a_1() { std::cout << " a_1 default ctor body " << std::endl; }
	
	// in destructor body fields still alive and parent fields still alive
	~a_1() { std::cout << " a_1 dtor body " << std::endl; } // firstly dtor body will be executed, then fields will be destroyed, then parent destructor will be executed

	// to do: add copy constructors
	
	
	// it is allowed to implicit cast b_1 to a_1
	// copy constructors do not inherit
	a_1( const a_1& other ): x (other.x)  { std::cout << "a_1 copy ctor" << std::endl; }
	
	// b_1 will generate copy ctor ( it copy a_1 as it needed and then it copy all fields ( call copy ctors from all fields ) )
};

/*
	when you create b_1, firstly a_1 will be created ( fields of a_1 will be initialized, then constructor body will be executed ), then fields of b_1 will be initialized, then constructor body will be executed 

*/

class b_1 : public a_1 // b = { int, int32_t }
{
public:

	int64_t y; // can be placed only in addresses divisible by 8
	
	b_1( int64_t y_arg ): y( y_arg ) {} // here default constructor of a_1 will be called
	
	b_1( ): a_1(0), y( 0 ) { std::cout << " b_1 ctor body " << std::endl; }
	
	~b_1() { std::cout << " b_1 dtor body " << std::endl; }
};

class a_2
{
	void f() {} // non-virtual methods do not affect sizeof( class ) 
};

class b_2 : a_2
{
	int32_t y;
	
	void g() {}
	
	~b_2() { std::cout << " b_2 dtor body " << std::endl; }
};


class b_3 : b_1
{
public:
	class a_1 a_1_var = 1;
	int a = -1;
	
	using b_1::b_1; // we can use all b_1 constructors ( except copy ctors ) to create b_3, b_3 fields will be initialized by default
	// what will be with copy constructor
	
	// template <typename... Args>
	// b_3(int y, Args... args) : b_1(args...), a_1(y) {} 
	
	b_3() : b_1(), a_1_var(  ) { std::cout << " b_3 ctor body " << std::endl; }
	
	~b_3() { std::cout << " b_3 dtor body " << std::endl; }
};

int main()
{
	std::cout << sizeof( class b_1 ) << std::endl; // 16
	std::cout << sizeof( class a_2 ) << std::endl; // 1, because different objects have different addresses by C++ standard
	std::cout << sizeof( class b_2 ) << std::endl; // 4, because of EBO ( empty base optimization )
	
	b_3 b_3_var = b_3();
	
	b_3_var.a = 3;
	
	b_3 b_3_var_2 = b_3_var; 
	
	std::cout << b_3_var.a << std::endl;
	std::cout << b_3_var_2.a << std::endl;
}