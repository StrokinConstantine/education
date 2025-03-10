#include <iostream>

// 7_5_exceptions_in_constructors.cpp






void f() try
{
    
} catch(...)
{
    
}




struct A
{
    A() { std::cout << "A ctor: " << this << std::endl; }
    A(const A& a) { std::cout << "A copy ctor: " << this << std::endl; }
    ~A() { std::cout << "A dtor: " << this << std::endl; }
};


struct S
{
    A a;
    S(int x) { std::cout << "S ctor: " << this << std::endl;
        if (x == 0)
            throw 1;  // s dtor will not be called
            // therefore we should wrap field "a" with raii, to correctly destroy a. Destructors of fields will be called, but destructor of S will not
        
    }
    S(const S& s) { std::cout << "S copy ctor: " << this << std::endl; }
    ~S() { std::cout << "S dtor: " << this << std::endl; }
};

struct T
{
    A* a; // we should use smart pointer to avoid memory leak
    T(int x) : a(new A())
    {
        std::cout << "T ctor: " << this << std::endl;
        if (x == 0) throw 1;
    }
    
    ~T()
    {
        std::cout << "T dtor: " << this << std::endl;
        delete a;
    }
};


struct B
{
    B(int x) { std::cout << "B ctor: " << this << std::endl;
        if (x == 0)
            throw 1;
    }
    B(const B& b) { std::cout << "B copy ctor: " << this << std::endl; }
    ~B() { std::cout << "B dtor: " << this << std::endl;  }
};


struct R
{
    B a1;
    B* a;
    B a2;
    // try for initializer list: function try block
    R(int x) try: a1(2), a(new B(x)), a2(x)
    // exception thrown in initializer list
    // a1 is created, a2 is not
    // dtor of a1 will be called and dtor of a2 is not
    
    {
        std::cout << "R ctor: " << this << std::endl;
    } catch (...)
    {
        std::cout << "caught in init list" << std::endl;
        // for ctors: automatically throw;
        // implicit throw;
    }
    
    ~R()
    {
        std::cout << "R dtor: " << this << std::endl;
        delete a;
    }
};

void throw_exception()
{
    throw 1;
}



struct C
{
    ~C() noexcept(false) // now we can throw exceptions from here
    {
std::cout << std::uncaught_exceptions() << std::endl;
        try
        {
            throw_exception();
        } catch( long a)
        {
            std::cout <<"E#"<< std::endl;
        }
        
    }
};


        




void throw_multiple_exceptions()
{
    C c1;
    C c2;
    C c3;
   //throw 1;
}


int main()
{
    
    
    std::cout << std::uncaught_exceptions() << std::endl;
    
    try
    {
        S s(0); 
    } catch(...)
    {
        
    }
    try
    {
        T t(0); // memory leak
    } catch(...)
    {
        
    }
    
    try
    {
        R r(0); 
    } catch(...)
    {
        
    }
    
    try
    {
        C c;
    } catch(...)
    {
        std::cout << "!" << std::endl;
    }
    
    try
    {
        // C c; // destructor of c will throw another exception -> terminate
        // throw 2;
        
      throw_multiple_exceptions(); // since C++17
    } catch(...)
    {
        std::cout << "!" << std::endl;
    } 
    
    
    
    
   // std::terminate();
    
    // R r_1(0); // terminate
    
    
    
    // if exception is thrown in destructor when another exception is throwing -> std::terminate(); (until C++11)
    // since C++11 you can not throw exceptions from destructors
    
    return 0;
}