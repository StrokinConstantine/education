#include<iostream>

bool search_in_array ( int32_t* array, size_t array_size, int32_t value_to_search )
{
	for ( size_t i = 0; i < array_size; ++i )
		if ( array[i] == value_to_search )
			return true;
	return false;
}

int main()
{
	
}