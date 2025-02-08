#include<iostream>


// << and >> operators behave differently when left argument istream or ostream  


struct Complex
{
	double re = 0.0;
	double im = 0.0;

	Complex( double re ) : re(re) {}
	Complex( double re, double im ) : re( re ), im( im ) {}

/*
	Complex operator+( const Complex& other ) const
	{
		return Complex( re + other.re, im + other.im );
	}
*/	
	// if you want define binary symmetric operators then declare them outside the class, do not make them members of class


	Complex& operator+=( const Complex& other )
	{
		// *this = *this + other; // awful, *this + other is new object, then assignment, += fast, + slow					
		this->re += other.re;
		this->im += other.im;
		return *this;
	}
	
	// operator spaceship ( since C++20 )
	// Three-way comparison
	// auto operator<=>( const Complex& other ) = default;
	auto operator<=>( const Complex& other ) = default;
	
	Complex& operator=( const Complex& other ) & // applied only to lvalue, since C++11
	{
		
	}
	// Complex& operator=( const Complex& other ) && {} // applied only to rvalue
	
};

// we return reference, because we want use << multiple times at one line, non-const because operator changes ostream
std::ostream& operator<< ( std::ostream&, const Complex& )
{
	// output string by one char in loop
}
std::istream& operator>> ( std::istream&, Complex& );
// in BigInteger use should make operator>> as friend, because it changes fields


// return value optimization
/*
	if you return local variable ( not a function argument ) without any expressions, compiler will optimize that: he will create this variable where it should be after return

*/
Complex operator+( const Complex& a, const Complex& b )
{
	Complex result = a; // coping
	result += b; // no coping ( if it is a string, then reallocation can be, so coping )
	return result; // no coping
	//return Complex( a.re + b.re, a.im + b.im );
}

/*

redundant O(n) coping 

Complex operator+( const Complex& a, const Complex& b )
{
	Complex result = a;
	return result += b; // coping
}
*/

/*

redundant O(n) coping

Complex operator+( Complex a, const Complex& b )
{
	return a += b; // coping
}
*/



bool operator<( const Complex& a, const Complex& b)
{
	return ( a.re < b.re ) || ( ( a.re == b.re ) && ( a.im < b.im ) );
}

bool operator>( const Complex& a, const Complex& b)
{
	return b < a;
	// return !( a < b || a == b )
}
bool operator<=( const Complex& a, const Complex& b)
{
	return !( b < a ); // same as !( a < b ), compiler will inline
	// return !( a < b || a == b )
}
bool operator>=( const Complex& a, const Complex& b)
{
	return !(a < b);
	// return !( a < b || a == b )
}
bool operator>=( const Complex& a, const Complex& b)
{
	return a.re == b.re || a.im == b.im;
	// return !( a < b || a == b )
}

// == <-> a <= b && a => b

// map ( sort ) requires comparator ( only operator<, remaining operators are expressed through < )

// operator, for scalar product?

// you can't change priority of operators, you can't create your own symbol for operators, you can't change order of evaluation of operators

int main()
{
	Complex c(1.0);
	
	c + 3.1; // c.operator+(3.1);
	3.14 + c; // error: no match for ‘operator+’ (operand types are ‘double’ and ‘Complex’)
	
	Complex a(1);
	Complex b(1);
	
	a + b = c; // a + b is rvalue, but it is your custom type, so it is okay to assign to rvalue
	// by default all methods can be applied to rvalue and lvalue ( operator= also )
 	// first solution: const Complex operator+ ( only before C++11 )
	// second solution: 

	
}