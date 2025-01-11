#include <stdio.h>

int main ( void )
{
	char char_a; // signed by default, 1 byte, in 
	'x'; // type of the 'x' literal is int, but it is safe to assign it to a variable of type char; in C++ 'x' has type char. 
	char char_null_terminator = '\0';
	char char_number = 0;
	
	
	int int_a = 129; // signed by default, int 16-bit architectures size equals 2 bytes, in 32 and 64 bit architectures size is 4 bytes.
	signed signed_a; signed int signed_int_a; // <-> int int_a;
	
	1 << 48; // = 0
	1L << 48; // = 2^48
	
	long long_a; // 8 bytes


	float float_a; // 4 bytes
	double double_a; // 8 bytes
	long double long_double_a; // 80 bits
		

	double b = 10.5 * (double)(int_a);
	
	
	char_a = (char) int_a;
	
	putchar(char_a);
	printf("\n%d\n", char_a);
	
	

	return 0;
}