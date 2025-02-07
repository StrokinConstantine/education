#include <iostream>


// since C++11 you can define custom literal suffixes

struct C1
{
	int x;
	int y;
	
	
	void f1()
	{
		
	}
	
	/*
		you cannot change fields in const methods ( call non-const methods of fields )
	
	*/
	
	void f2() const // const after signature
	{
		
	}	
	
	void f3() const // const after signature
	{
		std::cout << "f3 const" << std::endl;
	}
	
	void f3() // overloading by const property
	{
		std::cout << "f3 not const" << std::endl;
	}
};


struct C2
{
	// find methods changes splay tree structure, so we should label fields of tree as mutalbe  ( mutable is needed when object is constant from user point of view, but in reality object changes inner structure )
	
	static int X; // x will be in static memory ( there is two types of static memory, one variables initialized before start of the program ( they are located in binary file ) and other during the program ( for them compiler will write sum of their sizes in binary and in start of execution memory for them will be allocated in data )  )
	
	// static int y = 3; // error: ISO C++ forbids in-class initialization of non-const static member ‘C2::y’
	// static int yy; // not definition
	
	static const int yyy = 5; // okay
	
	mutable int x = 2; // anti const, means x will not be const
	int& ref = x;
	
	void f1( int y ) const // now compiler should make all fields const, but there is a reference ( = pointer ) -> const does not mean anything for reference 
	{
		++ref; 
		ref = y;
	}
	
	static void f2() // cannot be const, f2 will be in text
	{
		std::cout << "abc" << std::endl;
	}
	
};

class singleton
{
private:
	static singleton* ptr; // declaration
	singleton() {}
	singleton(const singleton&) = delete;
	singleton& operator=( const singleton& ) = delete;
public:
	static singleton& getObject()
	{
		if ( ptr == nullptr )
			ptr = new singleton();
		return *ptr;
	}
};

singleton* singleton::ptr = nullptr; // we can't initialize static non-const fields of a class

// declarations in .h, definitions in .cpp

// extern to only declare variable

int C2::X = 2; // definition of static variables is made in cpp


struct Latitude
{
	double value;
	Latitude ( double value ) : value ( value ) {} // now compiler can implicitly convert double to Latitude
	
	
	
};

// unsigned long long, const char*, long double as arguments

Latitude operator"" _l( unsigned long long x )
{
	return Latitude( 1.2 );
}

// contextual conversion of 'if' ( int <-> bool )

struct Longitude
{
	double value;
	
	explicit operator double () const // since C++11 now we cannot implicitly convert Longitude to double, but we can use static_cast<double>(  )
	{
		// static_cast can do standard conversion and conversions defined by a programmer
		return this->value;
		
		// code style: constructor has only one argument -> make it explicit
		// also make cast operators explicit
		
	}
	
	/*
	
	this is awful:
	
	explicit operator double&()
	{
		return this->value;
	}
	*/
};

struct another_double
{
	double value;
	explicit another_double ( double value ) : value ( value ) {} // now we cannot call constructor implicitly, cannot convert double -> another_double implicitly

	operator double () const // now we can implicitly convert another_double to double
	{
		return this->value;
	}
};

void test_f1 ( Latitude l )
{
	
}
void test_f2 ( Longitude l )
{
	
}

void test_f3 ( another_double l )
{
	
}
int main()
{
	
	
	Latitude l = 123_l;
	
	"asdf"s; // s - literal suffix for std::string
	
	const C1 c11 = C1();
	
	// c11.f1(); // error: passing ‘const C1’ as ‘this’ argument discards qualifiers [-fpermissive]
	
	c11.f2();
	c11.f3(); // error: increment of member ‘C1::x’ in read-only object
	
	C1 c12 = C1();
	
	c12.f3();
	
	const C1& c12c = C1();
	
	c12c.f3();
	
	const C2 c22 = C2();
	C2 c33 = C2();
	
	c22.f1( 2 );  // more likely undefined behavior, because x is const 

	C2::f2();
	
	// -fsanitize=address,undefined,leak
	
	// 'explicit' is need for constructors and type conversion operators 
	
	// C++ has strong typing
	
	test_f1( 12.2 ); // okay	
	// test_f2( 12.2 ); // error: could not convert ‘1.2199999999999999e+1’ from ‘double’ to ‘Longitude’
	// test_f3( 12.2 ); // error: could not convert ‘1.2199999999999999e+1’ from ‘double’ to ‘another_double’
	
	
}
