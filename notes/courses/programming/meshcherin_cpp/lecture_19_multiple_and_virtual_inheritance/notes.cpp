#include <iostream>
#include <cstdint>
class A 
{
public:
	
	
	void f() { std::cout << "A::f" << std::endl; }
};

class B : public A
{
public:
	
	void f() { std::cout << "B::f" << std::endl; }	// in class C there is will be overloading between A::f and B::f
};

class C : private A, public B {}; // warning: direct base ‘A’ inaccessible in ‘C’ due to ambiguity [-Winaccessible-base]
// here we can't access A methods and fields with qualified-id, do not inherit like that

class D : public A {};

class E : private B, public D {}; // diamond problem, проблема ромбовидного наследования

class F
{
public:
	
	
	void f() { std::cout << "F::f" << std::endl; }
};

class G : public A, public F
{
public:
	
	int c;

	void f() { std::cout << "G::f" << std::endl; }
};

/*
	it is allowed to use static_cast<A&>( B ), static_cast<A*>( &B ), static_cast<B&>( A ), static_cast<B*>( &A )
	B : public A ( public inheritance )
	B to A cast:
		copy - implicit cast ( okay, slicing ), static_cast ( okay ), reinterpret_cast ( compilation error )
		pointer - implicit cast ( okay ), static_cast ( okay ), reinterpret_cast ( okay )
		reference - implicit cast ( okay ), static_cast ( okay ), reinterpret_cast ( okay )
		
	A to B cast:
		copy - implicit cast ( compilation error ), static_cast ( compilation error ), reinterpret_cast ( compilation error )
		pointer - implicit cast ( compilation error ), static_cast ( okay, probably undefined behavior ), reinterpret_cast ( okay, probably undefined behavior )
		reference - implicit cast ( compilation error ), static_cast ( okay, probably undefined behavior ), reinterpret_cast ( okay, probably undefined behavior )
	
	private inheritance means that we don't know that B is A ( if we are not friend )
	B : private A ( private inheritance )
	B to A cast:
		copy - implicit cast ( compilation error ), static_cast ( compilation error ( access error ) ), reinterpret_cast ( compilation error )
		pointer - implicit cast ( compilation error ), static_cast ( compilation error ( access error ) ), reinterpret_cast ( okay )
		reference - implicit cast ( compilation error ), static_cast ( compilation error ( access error ) ), reinterpret_cast ( okay )
		
	A to B cast:
		copy - implicit cast ( compilation error ), static_cast ( compilation error ), reinterpret_cast ( compilation error )
		pointer - implicit cast ( compilation error ), static_cast ( compilation error ), reinterpret_cast ( okay, probably undefined behavior )
		reference - implicit cast ( compilation error ), static_cast ( compilation error ), reinterpret_cast ( okay, probably undefined behavior )		

	multiple inheritance ( if compiler sees cycle in graph of inheritance, it is compilation error)
	problem: how to cast C to A and C to B? Shift a pointer
	multiple inheritance in standard library: iostream
	
*/

int main()
{
	C c = C();
	B* p = &c; // implicit conversion, pointer will be shifted ( p != &c after this line )
	
	// c.f(); // error: request for member ‘f’ is ambiguous
	c.B::f(); // okay
	p->f();
	
	E e = E();
	// accessiblitity does not affect names resolution
	// e.f(); // error: request for member ‘f’ is ambiguous
	e.D::f();
	
	// A& a = e; // error: ‘A’ is an ambiguous base of ‘E’
	
	// static_cast< D::A >( e ); // <-> static_cast< A >( e ); since A is not an inner class of D; error: ‘A’ is an ambiguous base of ‘E’
	static_cast< A >( static_cast< D >( e ) ); // okay
	
	// static_cast< D >( B() ); // not okay
	// static_cast< A >( E() ); // error: ‘A’ is an ambiguous base of ‘E’
	
	void( G::*ptr_G_f )() = &G::f; // ptr_A_f stores method address
	void( F::*ptr_F_f )() = &F::f; // ptr_A_f stores method address
	
	// fucntion pointer != method pointer
	
	G g = G();
	
	std::cout << sizeof( ptr_G_f ) << std::endl; // 16 = function pointer + offset
	
	// offset is showing how much the beginning of the object whose method this is (&G::f) is shifted relative to the beginning of the object from which we are calling the function (g)
	
	(g.*ptr_F_f)( );
	
}