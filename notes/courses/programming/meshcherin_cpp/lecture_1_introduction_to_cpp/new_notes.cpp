/*
	C -> C++98 -> C++03 -> C++11 -> C++14 -> ... -> C++23
	
	The document that describes C++ standard: International C++ Standard
	
	C++ is a statically typed programming language (all types are known in CT)
*/

#include <iostream>
#include <cstdint>

#include <vector>
#include <list>
#include <forward_list>
#include <map>
#include <queue>
#include <stack>
#include <deque>



template <typename... Types>
void print_types_info( const std::string& title, const Types&... types )
{	
	std::cout << title << std::endl;
	( 
		(
		std::cout << "Type id is " << typeid( types ).name() << ".\n" <<
		"Size of type is " << sizeof( types )  << " bytes.\n" << 
		"Variable value is " << types << ".\n"
		),
		...
	); // ( init op ... op pack )
	std::cout << std::endl;
}

template <typename T, typename U>
void static_cast_and_print( T var )
{
	U casted = static_cast<U>( var );
	std::cout << casted << std::endl;
}


template <typename T>
void print_containter_fields( const T& container )
{
	std::cout << "Capacity: " << container.capacity() << std::endl;
	std::cout << "Size: " << container.size() << std::endl;
}




template <typename T>
void print_container( const T& container )
{
	for ( const auto& element : container )
	{
		std::cout << element << " ";
	}
	std::cout << "\n";
}





int main( void )
{
	print_types_info
		<
		unsigned char, 
		short, // Usually 2 bytes
		unsigned short, 
		int, // Usually 4 bytes
		signed, 
		signed int, 
		unsigned, 
		long,
		unsigned long, 
		long long, // Usually 8 bytes
		unsigned long long,
		size_t // use as array indicies, and address RAM
		>
		(
		"Fundamental integral types", 
		'0',
		077777, // The octal number system
		0xffff, 
		
		0b11111111'11111111'11111111'11111111, // -1
		0b10000000'00000000'00000000'00000000, // -2^31
		0b01111111'11111111'11111111'11111111, // 2^31 - 1

		0xffff'ffff, // 2^32 - 1

		0x7fff'ffff'ffff'ffff, // 2^63 - 1
		0xffff'ffff'ffff'ffff, // 2^64 - 1
		0x7fff'ffff'ffff'ffff, // 2^63 - 1
		0xffff'ffff'ffff'ffff, // 2^64 - 1
		
		0xffff'ffff'ffff'ffff // 2^64 - 1
		);
		
		
	print_types_info
		<
		int16_t, 
		uint16_t, 
		int_fast16_t, // When there is a lot of calculations
		int_least16_t // When memory matters
		>
		(
		"Fixed width integer types", // #include <cstdint>
		0xf,
		0xf,
		0xf,
		0xf
		);
	
	{
		static_cast_and_print<bool, int>( false );
		static_cast_and_print<bool, int>( true );
		static_cast_and_print<int, bool>( 0 );
		static_cast_and_print<int, bool>( 23 );
	}


	
		
	print_types_info
		<
		float, 
		double, 
		long double
		>
		(
		"Floating point types", //	The larger the number in modulus, the greater the discreteness, int to double cast is safe
		0.1f,
		0.1,
		0.1
		);
		
		std::string test_string = "01234"; 
		
		std::cout << static_cast<int>(test_string[0])<< std::endl;
		std::cout << static_cast<int>(test_string[1])<< std::endl;
		std::cout << static_cast<int>(test_string[5])<< std::endl; // UB, null-terminated for backward compatibility with C



		print_containter_fields( test_string );
		
		test_string[0]; // O(1)
		
		test_string.at( 1 ) = '9'; // exception will be thrown instead of UB (a bit slower because of checking)
		
		test_string = test_string + "5";
		
		test_string += "6";
		
		test_string.push_back( '7' );
		
		test_string.pop_back();
		//test_string.pop_front();
		
	test_string.front() = 'f';
		
	test_string.size() - 1; // potential overflow
	
	std::vector<int> test_vector;

//	test_vector[0]; // O(1)
	
//	test_vector.at(2); // O(1)
	
	test_vector.push_back(1); // O(1) amortized <-> lim (total time / number of all attepmts) = const, In worst case O(n) because of reallocation
	
	test_vector.push_back(2); 
	test_vector.push_back(5); 
	
	print_container( test_vector );
	
		test_vector.push_back(3); 
	
	
	test_vector.pop_back(); // always O(1), because of absence of reallocation
	test_vector.front();

	test_vector.shrink_to_fit(); // since C++11; drop unused memory
	
	test_vector.clear(); // do not clears memory
	
	
	
	test_vector.reserve( static_cast<size_t>( 100 ) ); //  to work with vector without reallocation 
	
	test_vector[99]; // UB
	
	test_vector.resize( static_cast<size_t>( 100 ), 'c' );
	
	test_vector.capacity();
	

	
	std::list<int> test_list;
	
	std::forward_list<int> forward; // Since C++11
	
	
	
	std::deque<int_fast16_t>  test_deque; // just as vector, but with push_front(), pop_front()
	
	test_deque[0]; // O(1) how?
	

	// not containers
	
	std::stack<int_fast16_t> test_stack; // adapter to std::deque (or std::vector?)
	
	std::queue<int_fast16_t> test_queue;
	
	std::priority_queue<int_fast16_t> test_priority_queue; // heap implemented on array, adapter to deque
	
	
	
	std::map<int_fast16_t, double> test_map;
	
	test_map[0]; // if value was not exist, operator[] creates default value, O( log n ) balanced search tree (RB tree)
	test_map.at(0); // exception instead of creation default value
	test_map.find( 0 );
	test_map.insert( std::pair<int_fast16_t, double>( 1, 1.0 ) );
	test_map.erase( 0 );

	return 0;
}