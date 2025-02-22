

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
	now in [C in D vtable] f address the same as in [B in D vtalbe = D vtable ]
	but we must remember top offset of C in D ( offset of this pointer )
	and if we call f from A object it will lead to D::f call

	when virtual A::f till not overridden in D, we do not need top offset, we just call A::f, but when there is virtual f in D, we need top_offset
	
	C in D vtable: [top_offset][&D_typeinfo][&thunk = [this -= 16(top_offset) call D::f() ]]

	dynamic_cast<B&>( d ); // ptr is pointing to D vtable


	now A is virtual ( C virtual A and B virtual A ), so there is also virtual_offset ( how far from us is there start of virtual parent )
	
	in vtable: top_offset, virtual_offset
	
	D now:
	[ptr1][b][padding][ptr2][c][d][ptr3: A in D vtable ( this ptr3 is here because A is polymorphic, if A is not, then this pointer is not needed )][a]
	
	ptr1: B in D vtable = D vtable
	ptr2: C in D vtable
	ptr3: A in D vtable
	
	if there is also Z : B, C, and Y : D, Z, then there also will be vtable A in Y
	
	every class is just a vertex in graph of inheritance
	for every vertex there is vtable ( for offsets of this) ( vtable depends not only from type itself, but it also depends on parents )

	D vtable now: [virtual_offset ( for A ) = 32] [ top_offset 0] [ &D_typeinfo ] [ &D::f ]
	C in D vtable: [16] [16] [&D::typeinfo] [&C_f_thunk (f) ( because if I call f from C, we need to shift "this ptr" )]
	
	A in D vtable: (no virtual offset because there is no virtual parents )[top_offset = 32] [&D_typeinfo] [&A_f_thunk (f) ]

	there is also construction vtables and virtual table of tables!
*/