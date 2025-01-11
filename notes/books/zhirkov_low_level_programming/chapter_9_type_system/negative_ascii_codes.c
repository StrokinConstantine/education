#include <stdio.h>

int main ( void )
{
	char character = 1;
	
	while ( character )
	{
		printf("%d <-> %c\n", character, character);
		character++;
	}
	return 0;
}