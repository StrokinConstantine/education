#include <iostream>






class strange
{
	int& r; // std::string has one
	int x;
	
	Strange( int y ) : x(y), r( x ) {} 
};






template <typename T>
class vector
{
	T* arr;
	size_t sz;
	size_t cap;
	
	void reserve( size_t new_cap )
	{
		if ( new_cap <= cap )
			return;
		
		
		// T* new_arr = new T[new_cap];
		// but T may not containt default constructor, even if it contain constructor, we don't want to create objects, we just need to allocate memory for them
		
		T* new_arr = nullptr;
		new_arr = reinterpret_cast<T*>( new char[ new_cap * sizeof(T) ] ); // still bad
	
	
		size_t i = 0;
		try{
		

		// new can thron an exception ( std::bad_alloc ), but we can do nothing here, because we will corrupt nothing
		for (  ; i < size; ++i )
		{
			// new_arr[i] = arr[i]; // UB, there is no T elements under new_arr pointer 
			// An object must be constructed (e.g., via new, placement new, or automatic initialization) before any operation 
			// we can use memcpy, but it will not work if T has a pointer or reference to its field ( std::string has one )
			
			new ( new_arr + i ) T( arr[i] ); // placement new ( create object on some address )
			
			// placement new do not throw exceptions, because it do not ask for memory
			
			// T constructor can thrown an exception -> we need to delete everything we allocated
			
		}
		
		// here is the difference between push_back and reserve, here push_back containts:
		
		// try new (new_arr + sz) T( new_value )
		
	} catch(...)
	{
		for ( size_t oldI = 0; oldI < i; ++oldI ) 
		{
			(new_arr + oldI)->~T(); // dtors do not throw exceptions
		}
		
		delete[] reinterpret_cast<char*>( new_arr );// delete do not throw exceptions
		
		throw;
	}
		
	
	
		for ( size_t i = 0; i < sz; ++i )
		{
			(arr + i)->~T();
		}
		
		// delete[] arr; will not work  ( delete calls destructors, and as we created array of chars, it placed their amount ( and this is not amount of T elements in the array ) in the left of array, so delete[])
		delete[] reinterpret_cast<char*>( arr );
		
		arr = new_arr;
		cap = new_cap;
		
	}
	
	
	void push_back( const T& value )
	{
		if ( sz == cap )
		{
			reserve( cap > 0 ? cap << 1 : 1 );
		}
		
		// now we want to place new element, if it will throw an exception, we must reset everything
	
		// resize, at, [] is obvious
	}
	
};

struct S
{
	int x;
	
	S(int x) : x(x) {}
};


template<>
class vector<bool> // analogue of Cantor function in math? It breaks a lot of rules
{
	char* arr;
	size_t sz;
	size_t cap;
	
public:
	
	
	
};


int main()
{
	
	size_t a = 1;
	
	std::cout << a << std::endl;
	
	a = (a << 2);
	
	std::cout << a << std::endl;
	
	return 0;
}