class A
{
	
	// static virtual void f() {} // error: member ‘f’ cannot be declared both ‘virtual’ and ‘static’
	
	int x;
	// virtual void f(); // linker error
	/*
		compiler must generate vtable for A and B and place pointer of f to vtable
	*/
};



class B : public A
{
	
};

int main()
{
	B b;
	
	return 0;
}