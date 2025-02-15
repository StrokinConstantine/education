#include <iostream>

/*
	virtual function: function that works like inheritor version
	you can redeclare any function
*/

struct A
{
	void f()
	{
		std::cout << "A::f" << std::endl;
	}
};

struct B : A
{
	void f()
	{
		std::cout << "B::f" << std::endl;
	}
};

// C is the polymorphic type, since it has at least one virtual function
// we can't change return type of virtual function
struct C
{
	virtual void f()
	{
		std::cout << "C::f" << std::endl;
	}
	
	virtual ~C() = default;
};


// D is also the polymorphic type, since f is also virtual automatically
struct D : C
{
	int*p = new int(0);
	
	void f()
	{
		std::cout << "D::f" << std::endl;
	}
	
	
	~D()
	{
		delete p;
	}
};


struct E : C
{
	int override = 4; // okay, override and final is not keywords, it is context-depended keywords
	int final = 4;
	
	void f() const // this function is not virtual since signatures are different
	{
		
	}
	
	virtual void f( int ) const // this is also not overrides C::f
	{
		
	}
	
	virtual void f() override final// good code style to override, it helps to avoid errors ( since C++11 )
	{
		// final forbids inheritors to override f
		// final can add efficiency ( optimization )
		// final == override final ( write only override or final )
		// write only virtual < override < final
	}
};



struct F
{
	virtual void f() const 
	{
		std::cout << "F::f" << std::endl;
	}
	void g() const // not virtual
	{
		std::cout << "F::g" << std::endl;
	}	
};

struct G : F
{
private:
	void f() const override 
	{
		std::cout << "G::f" << std::endl;
	}
public:
	virtual void g() const // now g is virtual ( F::g still not virtual )
	{
		std::cout << "G::g" << std::endl;
	}
};

struct H final : G // now we cannot inherit from H ( since C++11 )
{
	void f() const final 
	{
		std::cout << "H::f" << std::endl;
	}
	void g() const final // virtual for G::g
	{
		std::cout << "H::g" << std::endl;
	}
};

struct I
{
	virtual void f() const 
	{
		std::cout << "I::f" << std::endl;
	}
	
	virtual void g() const 
	{
		std::cout << "I::g" << std::endl;
	}
};

struct J
{
	void f() const 
	{
		std::cout << "J::f" << std::endl;
	}
	
	virtual void g() const 
	{
		std::cout << "J::g" << std::endl;
	}
};

struct K : I, J
{
	// this f considered as virtual for I::f
	void f() const  override 
	{
		std::cout << "K::f" << std::endl;
	}
	
	// now g is virtual for I and J
	void g() const override
	{
		std::cout << "K::g" << std::endl;
	}
};


int main()
{
	K k;
	I& i = k;
	J& j = k;
	
	i.g();
	j.g();
	
	
	
	B b;
	A& a = b;
	// a.f(); // A::f, because type of a is A
	
	D d;
	C& c = d;
	// c.f(); // D::f, because C::f is virtual, in Java everything is virtual, D::f can be virtual or not

	C* c_1 = &d;
	// c_1->f();
	
	C c_2 = d;
	// c_2.f();
	
	C* c_3 = new D();
	delete c_3; // destructor of C will be called, since ~C(){} is not virtual, so this is memory leak
	
	// delete = call of destructor, then memory deallocation ( free only deallocates memory )
	// new = memory allocation + call of constructor above allocated memory ( malloc only allocates memory )

	E e = E();
	C& c_4 = e;
	c_4.f();
	
	G g;
	F& f = g;
	f.f(); // we can bypass privacy here, because virtual functions is a runtime phenomenon and privacy is compile time
	// which virtual function will be called is defined in runtime
	
	int x;
	// std::cin >> x;
	
	F fff;
	
	F& ff = ( x % 2 ? fff : g ); // it is okay because f and g have the same parent
	
	ff.f();
	
}