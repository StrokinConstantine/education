#include <iostream>
#include <cstdint>
#include <set>

int main()
{
	size_t array_1_size;
	size_t array_2_size;
	
	std::cin >> array_1_size;
	std::cin >> array_2_size;
	
	uint64_t* array_1 = new uint64_t[array_1_size];
	uint64_t* array_2 = new uint64_t[array_2_size];
	
	for( size_t i = 0; i < array_1_size; ++i )
		std::cin >> array_1[i]; 
	for( size_t i = 0; i < array_2_size; ++i )
		std::cin >> array_2[i];
	
	std::set<uint64_t> set;
	
	for( size_t i = 0; i < array_1_size; ++i )
		set.insert( array_1[i] );

	for( size_t i = 0; i < array_1_size; ++i )
	{
		size_t size_before_insertion = set.size();
		set.insert( array_2[i] );
		size_t size_before_insertion = set.size();
	}
	delete[] array_1;
	delete[] array_2;
	
}