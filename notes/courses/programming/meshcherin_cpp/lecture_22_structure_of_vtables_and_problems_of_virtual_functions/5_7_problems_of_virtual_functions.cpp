#include <iostream>

struct A
{
	
	// static virtual void f() {} // error: member ‘f’ cannot be declared both ‘virtual’ and ‘static’
	
	int x;
	// virtual void f(); // linking error
	/*
		compiler must generate vtable for A and B and place pointer of f to vtable
		ub = mario
	*/
	
	virtual void h() = 0;
	
	void f()
	{
		std::cout << "A::f" << std::endl;
		h();
	}
	
	A()
	{
		std::cout << "A::A" << std::endl;
		// h(); // linking error 
		/*
			when we call virtual function from a constructor ( or constructor initialization list ), it behaves as non-virtual function
		*/
		//f();
		
		/*
		runtime error:

		pure virtual method called
		terminate called without an active exception
		Aborted
		
		in A vtable instead of &h ( and every pure virtual function ) there is pointer to terminate function ( before terminate std::cout << ), terminate calls abort
		
		g++ -fno-rtti // now dynamic_cast and typeinfo will not work
		
		when polymorphic object is creating, the parent must be created before it
		
		v_pointer = parent_vtable_ptr -> parent fields initialization -> parent constructor -> v_pointer = child_vtable_ptr -> child fields init ...
		dtor:
			
		 <- parent fields destruction <- parent dtor   <- v_pointer = parent_vtable_ptr <- child fields destruction ...
		
		so when we are in parent constructor, v_pointer points to parent vtable
		it is made to not call child method when child is not exists
		
		virtual inheritance case:
			
		we need construction vtables ( mom in son, dad in son )
		
		when mom is creating and son already is not exists, we need pointer for table for mom which creating inside son. v_pointer is equal that thing before mom's fields initialization
		
		virtual table of tables containg all this v_pointers in proper order
		
		*/
	}
	
	virtual ~A()
	{
		f();
	}
	
};



struct B : public A
{
		int x;
		void h() override
		{
			std::cout << "B::h" << x << std::endl;
		}
		
		B() : x(0)
		{
			std::cout << "B::B" << std::endl;
		}
};














int main()
{
	B b;
	
	return 0;
}