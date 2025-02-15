#include <iostream>
#include <vector>

// pure virtual

// in C++ abstract class = interface

struct Shape // class is abstract, since it has at least one pure virtual method
{
	Shape(){ std::cout << "Shape ctor" << std::endl; }
	
	virtual double area() const = 0; // pure virtual, since virtual and = 0
	virtual double perimeter() const = 0;
	
	virtual ~Shape() = default; // can be pure virtual
};


double Shape::perimeter() const { return 0.0; } // we can define pure virtual function, but we still cannot create objects of abstract class Shape



struct Square : Shape
{
	double a;
	
	Square( double a ): a(a) {}
	
	double area() const override
	{
		return a*a;
	}
	
	double perimeter() const override
	{
		return 4*a;
	}
};

struct B : Square
{
	B( double a ): Square(a) {}
	
	double area() const override
	{
		return a*a*a;
	}
	
	double perimeter() const override
	{
		return 6*a*a;
	}
};

int main()
{
	
	
	
	Square sq(2.0);
	
	std::cout << sq.area() << std::endl;
	
	Shape& sh = sq;
	
	std::cout << sh.area() << std::endl;
	
	B b(3.0);
	
	
	std::cout << b.area() << std::endl;
	std::cout << b.Square::area() << std::endl; // cancel virtuality
	std::cout << b.Shape::perimeter() << std::endl; // cancel virtuality
	
	std::vector<Shape*> v;
	
	v.push_back( new Square(1.0) );
	
	// static polymorphism = function overloading
	// dynamic = overriding
	
	delete v[0];
	
	// Shape sh; // error: cannot declare variable ‘sh’ to be of abstract type ‘Shape’
}