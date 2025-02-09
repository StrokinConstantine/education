#include <iostream>
#include <cassert>

// O(1) in the best case, O(n) in the average case, O(n) in the worst case
bool search_in_array ( const int32_t* array, const size_t array_size, int32_t value_to_search )
{
	// loop invariant: array[0], ..., array[i - 1] does not contain value to search
	for ( size_t i = 0; i < array_size; ++i )
		if ( array[i] == value_to_search )
			return true;
	return false;
}

int main()
{
	int32_t array_1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
	int32_t array_2[] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 }; 
	int32_t array_3[]{ 1, 1, 1, 1, 1, 1, 2, 2, 2, 2 };
	
	int32_t* dynamic_array_1 = new int32_t[20];
	int32_t* dynamic_array_2 = new int32_t[20];
	
	for ( int32_t i = 0; i < 20; ++i )
	{
		dynamic_array_1[i] = ( 1 << i );
		dynamic_array_2[i] = dynamic_array_1[i] * 5;
	}
	
	assert( search_in_array( array_1, 10, 1 ) );
	assert( search_in_array( array_1, 10, 11 ) == false );
	assert( search_in_array( array_1, 10, -1 ) == false );

	assert( search_in_array( array_2, 10, 11 ) );
	assert( search_in_array( array_2, 10, -1 ) == false );
	assert( search_in_array( array_2, 10, 234 ) == false );

	assert( search_in_array( array_3, 10, 2 ) );
	assert( search_in_array( array_3, 10, 54 ) == false );
	assert( search_in_array( array_3, 10, -1 ) == false );

	assert( search_in_array( dynamic_array_1, 20, 32 ) );
	assert( search_in_array( dynamic_array_1, 20, 1024 ) );
	assert( search_in_array( dynamic_array_1, 20, -1 ) == false );

	assert( search_in_array( dynamic_array_2, 10, 20 ) );
	assert( search_in_array( dynamic_array_2, 10, 320 ) );
	assert( search_in_array( dynamic_array_2, 10, -1 ) == false );
	
	delete[] dynamic_array_1;
	delete[] dynamic_array_2;
	
}