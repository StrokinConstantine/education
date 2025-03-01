

// O(n) memory since the maximum number of function frames that are created is equal to the depth of recursion
uint64_t fibonacci( uint64_t n ) // O(n) memory and O( phi^n ) time
{
	if ( n == 0lu ) return 0lu;
	if ( n == 1lu ) return 1lu;
	return fibonacci( n - 2lu ) + fibonacci( n - 1lu );
}


// the algorithm remains recursive, but the recursion tree becomes degenerate
uint64_t fibonacci_upgrade_1( uint64_t n ) // O(n) memory and O( phi^n ) time
{
	static const uint64_t MAX_N = 1000lu;
	
	static uint64_t array[MAX_N];
	
	if ( n == 0lu ) return 0lu;
	if ( n == 1lu ) return 1lu;
	if ( array[n] > 0 ) return array[n];
	return fibonacci( n - 2lu ) + fibonacci( n - 1lu );
}

