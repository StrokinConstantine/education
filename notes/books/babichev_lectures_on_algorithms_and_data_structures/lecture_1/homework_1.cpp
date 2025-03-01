#include <iostream>
#include <vector>





std::vector<int16_t> symmetric_difference( std::vector<int16_t>& v_1, std::vector<int16_t>& v_2 )
{
	std::vector<int16_t> output_array;
	
	static int16_t arr[10'000'000] = { 0 };
	
	for ( int16_t i : v_1 )
		++arr[i];
	for ( int16_t i : v_2 )
		++arr[i];
	
	for ( int16_t i = 0; i < 10'000'000; ++i )
		if ( arr[ i ] == 1 )
			output_array.push_back( i );
		
	return output_array;
}






int main()
{
	std::vector<int16_t> array_1;
	std::vector<int16_t> array_2;
	int16_t input;

	while( std::cin >> input )
	{
		if ( input == 0 )
			break;
		array_1.push_back( input );
	}
	
	while( std::cin >> input )
	{
		if ( input == 0 )
			break;
		array_2.push_back( input );
	}
	
	std::vector<int16_t> output_array = symmetric_difference( array_1, array_2 );
	
	for ( auto i : output_array )
		std::cout << i;
}