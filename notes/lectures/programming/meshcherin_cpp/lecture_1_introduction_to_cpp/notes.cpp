/*
	C -> C++
	International C++ Standard
	C++23 <- C++20 <--- C++17 <-- C++14 <- C++11 <---- C++03 <- C++98
	We will write on C++20
*/


// 1.1 Command line and compiler

// 1.2 Types and their operations

/*
	C++ is a statically typed programming language (all types are known in CT)
	
	Fundamental types
	
	Integral types (signed or unsigned)
		int <-> signed <-> signed int; at least 2 bytes (usually 4 bytes) [-2^31; 2^31 - 1]; 2^31 = 2147483648
		long;
		long long; usually 8 bytes
		short; usually 2 bytes
		char; 'a' + 'b'
		size_t; (unsigned long long), it is enough to index the entire RAM
	
	Fixed width integer types
		int8_t
		uint8_t
		...
		int64_t
		uint64_t
	
	std::byte (since C++17)

	int <-> bool
	true -> 1; false -> 0
	zero -> false; non-zero -> true

	bool; 1 byte, vector<bool> ? 
	
	Floating point types
		float
		double
		long double
	The larger the number in modulus, the greater the discreteness
	int to double cast is ok
*/

/*
	std::string s = "abc"; // null-terminated strings
	s[4]; // UB
	
	in C++ efficiency > security
	
	operator[](size_t)
	.at(size_t); s.at(1) = 'x'; // exception will be thrown instead of UB (a bit slower because of checking)
	+
	+=
	.push_back(char)
	.pop_back()
	.front() // s.back() = 'y';
	.back()
	
	s.size() - 1 // overflow
	
	std::vector<int> v;

	operator[](size_t) // O(1)
	.at(size_t) // O(1)
	.push_back(  ) // O(1) amortized <-> lim (total time / number of all attempts) = const; In worst case O(n) because of reallocation
	.pop_back() // always O(1), because of absence of reallocation
	.front()
	.back()
	.shrink_to_fit() // since C++11; drop unused memory
	.clear() do not clears memory
	.reserve(size_t) to work with vector without reallocation 
	.resize(size_t, char)
	.capacity()
	
	v.reserve(10);
	v[9]; // UB
	
	std::list
	std::forward_list since C++11
	std::deque just as std::vector, but with push_front(), pop_front(  )
	
	
*/