#include <iostream>
#include <cassert>

bool dfa( const std::string&s )
{
	enum { OUT, IN_1, IN_2, END, ERROR } state = OUT;
	
	for ( char c : s )
		if ( state == IN_1 && c == '\'' ) state = END;
		else if ( state == IN_2 && c == '"' ) state = END;
		else if ( state == OUT && c == '\'' ) state = IN_1;
		else if ( state == OUT && c == '"' ) state = IN_2;
		else if ( state == END ) state = ERROR;
	return state == END; 
}

int main()
{
	assert( dfa("'123'") );
	assert( !dfa("'123") );
	assert( dfa("'123\"\"'") );
	assert( !dfa("\"'123'\"''") );
	assert( !dfa("\"'123'\"\"\"") );
}