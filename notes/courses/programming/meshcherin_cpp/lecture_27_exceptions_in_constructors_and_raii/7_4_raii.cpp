#include <iostream>

// 7_4_raii
// resource acquisition is initialization
// acquisition = ctor, destruction = dtor


// ifstream ofstream - open() in ctor, close() in dtor


//exceptions is needed to not cover function calls with 100 ifs of checking errors

void g(int y)
{
	if (y == 0)
	{
		throw 1;
	}
}


void f(int x)
{
	int *p = new int(x); // allocate memory
	g(*p); // exception thrown -> no deallocation
	
	// solution 1: do not use exception at all
	// solution 2: smart pointers 

	
	delete p; // deallocate
}




template <typename T>
struct Wrapper // smart pointer, unique_ptr, it frees memory itself, when object is destroyed 
{
    T *p;
    Wrapper(T* p) : p(p) {}
    Wrapper( const T& w) = delete; // we cannot copy (because of double free)
    Wrapper& operator=(const Wrapper& w) = delete;
    
    ~Wrapper(){ delete p; }
    
    T& operator*()
    {
        return *p;
    }
    // unique_ptr, unique because there is no more than one pointer that points on the same object
	// you cannot copy it, so accept it by reference
	
    // void reset() zeros the object
    
	// do not create two unique_ptrs on the same object
	
	// you can copy shared_ptr, it stores pointer of how much share_ptrs points to the same object
	
	// string, vector, shared_ptr - most useful
};

void g(int y)
{
    if(y == 0)
    {
        throw 1;
    }
}

void h(Wrapper<int> wr)
{
    if (*wr == 0)
    {
        throw 1;
    }
}

void f(int x)
{
    int* p = new int(x);
    g(*p);
    // problem: g can throw an exception and it will lead to memory leak -> do not use exceptions, or use OOP (Wrapper)
    delete p;
    
    Wrapper<int> w(new int(x));
    
    g(*p); // now w will be destroyed

    // new problem:
    
    h(p);
    // if we accept p by value, it will lead to memory leak
    // so we can not copy this pointer
}


int main()
{
    // you can copy shared_ptr, in counts how many shared_ptrs point to the same resource
}