#include <iostream>

// virtual function := we can call it from parent reference ( and child function will be called )
// virtual function := decision which function will be called is made in runtime
// for every function except virtual, this decision is made in compile time

// variable can't change type in runtime, but object under variable can: B b; A& b_ref = b;

struct A
{
	virtual void f()
	{
		std::cout << "A::f" << std::endl;
	}
	virtual ~A() = default; // by doing only this we have made type A polymorphic
};

struct B : A
{
	void f() override
	{
		std::cout << "B::f" << std::endl;
	}
	
	void g()
	{
		std::cout << "B::g" << std::endl;
	}
};

struct Z {};


/*
	memory layout of polymorphic objects
	this is not C++ standard
	ABI ( application binary interface ) - describes how the compiler arranges objects and functions in memory
	every polymorphic type has one vtable ( in static memory )
	vtable contains addresses of virtual member functions of its type ( and addresses of virtual parents )

	vtable solves the problems of both virtual inheritance and virtual functions 
*/

struct C
{
	virtual void f() {} 
	virtual void g() {}
	
	// void g() {}
	
	int x;
	
	
	/*
		C vtable: [&C::typeinfo] [&C::f] [&C::g]
	
		&C::typeinfo - pointer to string
	
		C::typeinfo - string, typename of C in static memory
	*/
};

struct D
{
	virtual void f() {}
};

struct E
{
	virtual void f() {}
	void g() {}
	int x = 0; // sizeof ( E ) = 16 because of alignment: [&E::f] [int x] [padding]
};


struct F : E// [&F::f] [int x] [int y]
{

	// F vtable: [&F::typeinfo] { [&F::f], [&F::h] }
	void f() override
	{
		
	}
	
	virtual void h() {} // non-virtual functions are located in .text
	
	int y = 0;
	
	
};

struct G // [int b] G is non-polymorphic type, so we can't dynamic_cast<H&>( g ), but we can static_cast<H&>( g )
{
	int a;
	
	void g()
	{
		
	}
};

struct H : G // [ptr] [int a] [int b]
{
	int b;
	
	virtual void f()
	{
		
	}
};

struct I : H // [ptr] [int a] [int b] [int c] [padding]
{
	int c;
	
	void f() override
	{
		
	}
};

int main()
{
	F f;
	E& f_ref = f;
	
	f_ref.f();
	f_ref.E::f(); // this call will be resolved in compile time
	
	// dynamic_cast is going into vtable to view typeinfo
	
	/*
	compiler sees that f is virtual, then he can't translate this into call &f
	address of non-virtual function is known on linking stage ( compiler leaves &f and linker substitutes actual &f value )
	address of actual virtual function that will be called is known in runtime
	virtual function call: call address located in vtable of this object ( 2 dereferences instead of 1 for non-virtual function )
	
	
	*/
	
	std::cout << sizeof( D ) << std::endl; // 8 = size of one pointer to vtable ( to &D::f )
	
	
	
	
	
	// dynamic_cast = is performed in runtime
	// dynamic_cast can throw an exception std::bad_cast, while static_cast will give an undefined behavior
	// dynamic_cast is an expensive operation, because it is needed to go to pointer ( which is stored in our object ), find table, and find there what type it is, and find out can we do dynamic_cast cast or not, if we can, we shit pointer
	// RTTI = Runtime type information
	// for polymorphic types compiler has a structure which holds what type it is ( every polymorphic type has hidden pointer to this structure )
	// typenames are stored in static memory, compiler compares strings ( or pointers? )

	B b;
	A a;
	A& b_ref = b;
	
	dynamic_cast<B&>(b_ref).f(); // correct dynamic_cast
	dynamic_cast<B&>(b_ref).g(); // correct dynamic_cast
	
	
	B* b_ptr = dynamic_cast<B*>(&b_ref); // if b_ref is object of type B, it is okay, otherwise it will return nullptr
	
	std::cout << b_ptr << std::endl;
	
	B* a_ptr = dynamic_cast<B*>(&a); // dynamic_cast works only for types with virtual functions ( polymorphic types )
	
	// for non-polymorphic types it is impossible to know real object type in compile time
	
	// polymorphic types has special information in runtime which needed to know object type
	
	std::cout << a_ptr << std::endl; // nullptr
	
	
	// operator typeid
	
	typeid( a ); // typeid returns std::type_info, std::type_info has method name() and operator==
	
	// typeid also works for non-polymorphic types, but then it just returns variable type 
	
	
	std::cout << typeid( b ).name()  << std::endl; // 1B, 1 is length 1B is монглированное? name
	std::cout << typeid( a ).name()  << std::endl;
	
	// c++filt, we can find real typename from 1B
	
	// if with initialization
	if ( B* b_ptr_2 = dynamic_cast<B*>(&b_ref); b_ptr_2  ) {} else {}
	
	// we always can do dynamic_cast from any polymorphic type to void*, from non-polymorphic it is not allowed, so we can check if type is polymorphic
	
	// we can do dynamic_cast upwards even for non-polymorphic types ( as static_cast )
	
	// dynamic_cast can do cast to the side ( from father to mother  ) ( from polymorphic )
	
	// cast downwards for polymorphic types: dynamic_cast - okay, static_cast - compile time error, reinterpret_cast - undefined behavior
	// cast to the side from polymorphic type: dynamic_cast - okay, static_cast - compile time error, reinterpret_cast - undefined behavior
}


