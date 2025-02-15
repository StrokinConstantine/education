#include <iostream>
#include <vector>

// pure virtual

// in C++ abstract class = interface

struct Shape // class is abstract, since it has at least one pure virtual method
{
	Shape(){ std::cout << "Shape ctor" << std::endl; }
	
	virtual double area() const = 0; // pure virtual, since virtual and = 0
	
	virtual ~Shape() = default; // can be pure virtual
};

struct Square : Shape
{
	double a;
	
	Square( double a ): a(a) {}
	
	double area() const override
	{
		return a*a;
	}
};

int main()
{
	Square sq(2.0);
	
	std::cout << sq.area() << std::endl;
	
	Shape& sh = sq;
	
	std::cout << sh.area() << std::endl;
	
	
	std::vector<Shape*> v;
	
	v.push_back( new Square(1.0) );
	
	// static polymorphism = function overloading
	// dynamic = overriding
	
	delete v[0];
	
	// Shape sh; // error: cannot declare variable ‘sh’ to be of abstract type ‘Shape’
}