#include<iostream>


// << and >> operators behave differently when left argument istream or ostream  


struct Complex
{
	double re = 0.0;
	double im = 0.0;

	Complex( double re_arg ) : re(re_arg) {}
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
	
    // three-way comparison C++20
    /*
        if we want to compare different types ( char* and string without conversion char*->string)
        -> we need do define every operator (<, > , <=, ...) for every possible pair of different arguments
        operator spaceship works as following:
        we need to define operator<
        a > b;
        if operator> defined, then call it
        else if operator<=> defined, then 'call it'
        operator<=> is fast ( for example if we are comparing strings)
        <=> returns {greater, lower, equal}
        
        predicate= is equivalence realtion + 4) for any function f: a = b -> f(a) = f(b) 
        
        std::strong_ordering // equal means that object are identical 
        std::weak_ordering there is no forth property of predicate= -> it can return "EQUAL", even if obects are different, 
        std::partial_ordering
        
        string has weak_ordering because capacity can be different

        std::weak_ordering is the same as weak ordering in math, but when object are not comparable in math, then are equal in std::weak_ordering
    
		if you defines operator<=> non-default, then operators <, >, <=, >= defines by the compiler, but operators == and != are not
		because ( for strings ) we can firstly compare sizes and then compares strings ( so != and == would be not efficient if they would implemented through < )
	*/
	
    std::weak_ordering operator<=>( const Complex& other) const = default; // all comparison operators will be defined lexicographically 
	
	
	bool operator==(const Complex& other) const = default; // comparison of fields
	    
    std::weak_ordering operator<=>(const char* other) const
    {
        return std::weak_ordering::equivalent;
        // now you can compare string and char*, char* and string with any comparison operator

    }
    
	
	
	
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

// == <-> a <= b && a => b

// map ( sort ) requires comparator ( only operator<, remaining operators are expressed through < )

// operator, for scalar product?

// you can't change priority of operators, you can't create your own symbol for operators, you can't change order of evaluation of operators


struct UserId
{
	int value = 0;
	
	UserId& operator++() // it is preferable to use prefix increment, it is faster
	{
		++value;
		return *this;
	}
	
	// for BigInteger prefix ++ should be O(1) amortized ( if we call a lot of ++, there is will be very small amount of reallocations )
	
	UserId operator++(int) // we have to accept fake int argument
	{
		UserId copy = *this; // always O(n) for BigInteger
		++value;
		return copy;
	}
}

struct greater // functional class, functor ( not in math )
{
	bool operator()(int x, int y) const
	{
		return x > y;
	}
}


int main()
{
	std::vector<int> v(30);
	
	std::sort(v.begin(), v.end(), greater() ); // greater() is a functional object
	// functinonal objects can use fields
	// syntactically there is no difference between function and object witl operator()
	
	Complex c(1.0);
	
	c + 3.1; // c.operator+(3.1);
	3.14 + c; // error: no match for ‘operator+’ (operand types are ‘double’ and ‘Complex’)
	
	Complex a(1);
	Complex b(1);
	
	// a + b = c; // a + b is rvalue, but it is your custom type, so it is okay to assign to rvalue
	// by default all methods can be applied to rvalue and lvalue ( operator= also )
 	// first solution: const Complex operator+ ( only before C++11 )
	// second solution: 

	
}



     
