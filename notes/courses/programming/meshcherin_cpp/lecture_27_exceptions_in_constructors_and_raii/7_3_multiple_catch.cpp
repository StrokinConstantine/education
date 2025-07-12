// Online C++ compiler to run C++ program online
#include <iostream>

// 7_3_multiple_catch.cpp


struct A
{
    
};

struct B : A 
{
    
};

struct C {};

struct D : private C
{
    friend int main(); // it will not help
}; // main does not know that C is parent of D


struct E {};
struct F : E {};
struct G : E {};
struct H : F, G {};






int main() {

    // emergency buffer (when exception allocated in static memory)
    // we know size of std::bad_alloc
    
    
    try
    {
        throw 1; // other
    } catch(double d)
    {
     std::cout << "double";   
    } catch(long long d)
    {
     std::cout << "long long";   
    } catch(...)
    {
     std::cout << "other";   
    }
    
    // there is no overloading in catches
    // there is no conversions ( except non-const -> const conversion and parent -> child conversion (parent& -> child&) )
    
    /*
    try
    {
        throw 1; // terminate
    } catch(double d)
    {
     std::cout << "double";   
    } catch(long long d)
    {
     std::cout << "long long";   
    }
    */
    
    try
    {
        B b;
        throw b; // A, because it is first case (from top to the bottom) that came up 
    } catch(A a)
    {
     std::cout << "A";   
    } catch(B b) // warning: exception of type ‘B’ will be caught by earlier handler [-Wexceptions]
    {
     std::cout << "B";    // never be called
    } catch(...)
    {
     std::cout << "other";   
    }
    
    try
    {
        A a;
        throw a; // A
    } catch(A a)
    {
     std::cout << "A";   
    } catch(B b)
    {
     std::cout << "B";   
    } catch(...)
    {
     std::cout << "other";   
    }
    
    try
    {
        A a;
        throw a; // A
    } catch(B b)
    {
     std::cout << "B";   
    } catch(A b)
    {
     std::cout << "A";   
    } catch(...)
    {
     std::cout << "other";   
    }
    
    
    try
    {
        B b;
        throw b; // B
    } catch(B a)
    {
     std::cout << "B";   
    } catch(A b)
    {
     std::cout << "A";   
    } catch(...)
    {
     std::cout << "other";   
    }
    
    
    
    
    try
    {
        D d;
        throw d; // now it will be D, because main does not know that d is child of C
    } catch(C a)
    {
     std::cout << "C";   
    } catch(D b)
    {
     std::cout << "D";   
    } catch(...)
    {
     std::cout << "other";   
    }
    
    
    
    try
    {
        H h;
        throw h; // G "private inheritance" will not chage anything, bu if inheritance is virtual, it will be E (virtual F, virtual G)
    } catch(E e)
    {
     std::cout << "E";   
    } catch(G g)
    {
     std::cout << "G";   
    } catch(F f)
    {
     std::cout << "F";   
    } catch(H h)
    {
     std::cout << "H";   
    } 
    
    
    
    
    
    
    
    return 0;
}