#include <iostream>

// distinguishing names with numbers at the end is a bad code style

class A
{
public:
	int a;
	
	void f()
	{
		std::cout << "A::f" << std::endl;
	}
};

class I
{
public:
	void g()
	{
		std::cout << "I::g" << std::endl;
	}
};

// now in D will be only one copy of A
class B : public virtual A
{
	int b;
};
class C : public virtual A
{
	int c;
};

class E : public A
{
	
};

class G : public A
{
	
};

// D: ( ptr to A, B ), padding, ptr to A, C, D, A, padding
// B: ptr to A, B, A
// actually this is not pointer to A, this is pointer to a table in static memory which has offsets from object start to every virtual parent
// vtable: B = [12], C = [12], D = [32] ( there is only one vtalbe for every type )
// vtable also contains top offset - offset how far object itself contained from the start of object ( to calculate difference ) 
// pointers will be created for classes which have virtual parents, virtual parent exists -> class is starting with pointer

// there is B in D and C in D vtables ( B top offest is 0 for D, C top offest is 16 for D )

// static_cast is not defined for virtual classes downwards ( A -> D )
// static_cast C -> D?


class D : public B, public C
{
	int d;
};

class F : public C, public E // ptr, C, ( A, E ), virtual A
{
	
};

class J : public virtual A, public I
{
public:
	void f()
	{
		std::cout << "J::f" << std::endl;
	}
	
	void g()
	{
		std::cout << "J::g" << std::endl;
	}
};

class K : public virtual A, public I
{
	
};

class L : public J, public K
{
	
};

// ptr to H vtalbe with offsets for E and G in H, H fields, virtual E ( with A and E fields ), virtual G ( with A and G fields )
class H : public virtual E, public virtual G
{
	
};

// in standard library there is virtual diamond inheritance

int main()
{
	D d;
	d.a; // now this is okay
	
	A& a = d; // now this is okay
	
	std::cout << sizeof( d ) << std::endl;
	
	L l;
	
	l.f(); // with virtual inheritance, if there is multiple ways to the same parent method ( A::f )and there exists way in graph that shadows this method ( J::f ), then other ways do not considered 
	// l.g(); // error: request for member ‘g’ is ambiguous
	
}