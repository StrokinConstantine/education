// 1.1 Command line and compiler

// 1.2 Types and their operations

/*
	C++ is a statically typed programming language (all types are known in CT)
	
	
		char; 'a' + 'b'

	
	std::byte (since C++17)

	bool; 1 byte, vector<bool> ? 
	
*/

/*
	
	in C++ efficiency > security
	
	
	
	std::multimap // no operator[] and .at(); lower_bound(Key), upper_bound(Key)  (RB tree)
	 
	std::set   (RB tree)
	
	std::multiset  (RB tree)
	
	unordered_map ... unordered_multiset // hash table. insert, delete, search : O(1) in average, in worst case O(n)
	
	O(1) in average <-> lim (total time / number of all attempts) != const; average by input data, but we can choose input data that insert will take O(n) always, in O(1) amortized we can't do that
	
	std::cout << x; <-> <<( std::cout, x );
	
	std::istream 
	
	std::ostream
	
	std::ifstream 
	std::ofstream
	
	std::istringstream ( string as stream )
	std::ostringstream
*/