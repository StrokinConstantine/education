#include <stdio.h>

int main ( void )
{
	// integer promotion
	// int -> u int -> long -> u long -> long long -> u long long -> float -> double -> long double
	
	unsigned char a = 100, b = 100, c = 100;
	
	unsigned char char_result = a + b + c; // = 300 % 259 == 44
	unsigned int int_result = a + b + c; // = 300, because of "convert to int first" rule
	
	unsigned int x = 1e9, y = 2e9, z = 3e9;
	
	unsigned int

	return 0;
}