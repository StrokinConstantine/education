#include <iostream>

int main( void )
{
	
	int x = 0; // there is not operator =, this is initialization 
	int y = 0; // this is declaration, not expression
	
label_1:

	if ( false )
		goto label_1; // do not use goto; you can't use goto to a different scope
	
	
	if ( int z = 0;  y > z ) // since C++17
	{
		
	}
	
	if ( true )
	{
		
	}
	else if ( 1 )
	{
		
	}
	else if ( 1.0 )
	{
		
	}
	else
	{
		
	}
	
	
	switch (x) // switch is better than if for optimization
	{
		case 1:
			break; // control statement, not expression
		case 2:
			break;
		default:
			break;
	}
	
	while ( 0.0 )
	{
		
	}
	
	do {  } while (0);
	
	for ( /* declaration | expression; bool expression; expression */ ; ; )
	{
		break; // exit loop
		continue; // skip left code to the next loop iteration 
	}

	for ( ; ; )
	{
		break;
	}
	
	try {} catch ( int a ) {}
	
}