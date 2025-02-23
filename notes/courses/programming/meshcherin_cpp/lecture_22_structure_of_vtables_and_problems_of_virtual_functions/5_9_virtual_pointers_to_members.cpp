#include <iostream>

struct A
{
	int x = 0;
	virtual void f() // first virtual method of A
	{
		std::cout << x << std::endl;
	}
};

struct B
{
	int y = 1;
	virtual void g() // first virtual method of B
	{
		std::cout << y << std::endl;
	}
};

struct D
{
	int t = 1;
	virtual void h() // first virtual method of D
	{
		std::cout << t << std::endl;
	}
};

struct C : A, B, D
{
	int z = 2;
	
	void f() override // first virtual method of C, offset from vtable start is 0
	{
		std::cout << z << std::endl;
	}
	
	void g() override // second virtual method of C, offset from vtable start is 8
	{
		std::cout << z << std::endl;
	}
	void h() override // third virtual method of C, offset from vtable start is 16
	{
		std::cout << z << std::endl;
	}
	
};

struct S
{
	long long a;
	long long b;
};

int main()
{
	void (B::* p)() = &B::g;
	C c;
	B& a = c;
	(a.*p)(); // 2, behaves as virtual
	
	void (C::* p2)() = &D::h;
	void (C::* p3)() = &C::g;
	
	A& aa = c;
	
	
	std::cout << sizeof(p) << std::endl; // 16
	
	// p consists of 16 bytes
	
	S s = reinterpret_cast<S&>(p2);
	S s2 = reinterpret_cast<S&>(p3);

	std::cout << sizeof(s) << ' ' << s.a << ' ' << s.b << std::endl; // 16 1 32 ( 32 - offset from object start )
	
	std::cout << sizeof(s2) << ' ' << s2.a << ' ' << s2.b << std::endl; // 16 17 0 ( 17 ( actually 16) - offset from vtable start = address of method in vtable )
	
	// the 1 in last bit means that pointer is virtual, 0 means method in non-virtual
	// simple method pointers store in first 8 bytes actual method addresses ( they are always even nubmers )
	// virtual pointers store offsets in vtables
}