

class A // what will be if A is not polymorphic?
{
public:

	int a;
	
	virtual void f()
	{
		
	}
};

class B : A
{
public:

	int b;
};

class C : A
{
public:

	int c;
};

class D : public B, public C
{
public:

	int d;
};

/*
	D in memory: [ ptr1 for B and D ][ a ][ b ][ ptr2 ( this ptr is not equal to the previous ) for C ( so we can cast D to C) ][ a ][ c ][ d ][ padding ]
	[vtable for D = vtable B in D]                 and vtable C in D
	pointer to f must be the same, but offset from object start ( offset to actual fields ) must be different 
	in vtable there is information about offset of ptr2 in D object ( top offset, when multiple inheritance )
	 
	non-virtual thunk ( pre-function, located in C in D vtalbe ):
		instead of call f in C in D vtable there is: shift 16 bytes and then call f
		when we try to call f in C we just call f in D, but with remembered offset of fields
	
	s.f(); // compile time error ( B::f or C::f )
	
	void D::f() override {} // now s.f(); okay
	
	and if we call f from A object it will lead to D::f call

	dynamic_cast<B&>( d ); // ptr is pointing to D vtable

*/