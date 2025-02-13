
/*
	it is allowed to use static_cast<A&>( B ), static_cast<A*>( B ), static_cast<B&>( A ), static_cast<B*>( A )
	B : public A ( public inheritance )
	B to A cast:
		copy - implicit cast ( okay, slicing ), static_cast ( okay ), reinterpret_cast ( compilation error )
		pointer - implicit cast ( okay ), static_cast ( okay ), reinterpret_cast ( okay )
		reference - implicit cast ( okay ), static_cast ( okay ), reinterpret_cast ( okay )
		
	A to B cast:
		copy - implicit cast ( compilation error ), static_cast ( compilation error ), reinterpret_cast ( compilation error )
		pointer - implicit cast ( compilation error ), static_cast ( okay, possibly undefined behavior ), reinterpret_cast ( okay, possibly undefined behavior )
		reference - implicit cast ( compilation error ), static_cast ( okay, possibly undefined behavior ), reinterpret_cast ( okay, possibly undefined behavior )
*/

class A{};

class B : A {};