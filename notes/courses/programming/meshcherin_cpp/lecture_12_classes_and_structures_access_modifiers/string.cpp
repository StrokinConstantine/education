#include <cstring>
#include<iostream>


class string
{
	char* arr = nullptr;
	size_t size = 0;
	size_t capacity = 0;
	
public:
	
	string() = default;
	
	string( size_t n, char c ): arr( new char[n + 1] ), size( n ), capacity( n + 1 )
	{
		memset( arr, c, n ); // godbolt
		
		std::fill( arr, arr + size, c ); // same efficiency as memset( arr, c, n );
		// for i < n make one operation for every byte, memset and std::fill can make one operation for every machine word ( -> in 8 times faster )
		arr[size] = '\0';
	}
	
	// since C++11
	// the main rule: if you have at least one constructor for std::initializer_list and you create object with {}, firstly compiler try to call constructors for std::initializer_list, only then other constructor will be considered, if there is no constructors, it means aggregate initialization
	// must have if we have references or constants
	string( std::initializer_list<char> list ) // by value, there is guarantee that std::initializer_list is lightweight type and so copying it is trivial ( copy of initializer list does not imply copy of every list element )
		: arr( new char[list.size() + 1] )
		, size( list.size() )
		, capacity( size + 1 )
		{
			std::copy( list.begin(), list.end(), arr );
			arr[size] = '\0';
			std::cout << "init list" << std::endl;
		}
	
	~string() // for every object destructor must be call only one time, if it is not true, then it is undefined behavior
	{
		delete[] arr;
	}
	
	string( const string& other ): arr( new char[other.capacity] ), size( other.size ), capacity( other.capacity )
	{
		memcpy( arr, other.arr, size + 1 ); // <-> std::copy, make one operation for every machine word ( for primitives )
		// std::copy calls copy constructors, memcpy just copies memory
		// strcpy copies by one byte
		// memmove gives guarantee that if there was an intersection ( memcpy will give an undefined behavior ), the result will be correct
	}
	

	



	string& operator=( string other )
	{
		swap(other);
		return *this;
	}
	
	void swap( string& other )
	{
		std::swap(arr, other.arr); // O(1)
		std::swap(size, other.size); // O(1)
		std::swap(capacity, other.capacity); // O(1)
	}
	
	char& operator[](size_t index)
	{
		return arr[index];
	}
	
	const char& operator[](size_t index) const
	{
		return arr[index];
	}
	
};


int main()
{
	const string str( 10,  'a' );
	
	std:: cout << str[1] << std::endl;
	
	str[1] = 'b'; 
	
	std:: cout << str[1] << std::endl;
	
	return 0;
}