#include <stdio.h>
#include <stdbool.h>

#define mystr hello
#define res #mystr

#define x1 "Hello"
#define x2 " World"
#define str(i) x##i /* ## allows us to form symbol names dynamically */







int main( int argc, char** argv )
{
	
	puts( res ); /* puts("hello") */
	puts( str(1) ); /* <-> puts( x1 );*/
}


#define pair(T) pair_##T // backslashes are used to escape the newline character
#define DEFINE_PAIR(T)\
	struct pair(T) {\
		T fst;\
		T snd;\
	};\

bool pair_##T##_any( struct pair(T) pair, bool (*predicate)(T) ){\
	return predicate( pair.fst ) || predicate( pair.snd ); \
}

#define any(T) pair_##T##_any

DEFINE_PAIR(int)

bool is_positive( int x ){ return x > 0; }



void parametric_polymorphism( void )
{
	struct pair(int) obj;
	
	obj.fst = 1;
	obj.snd = -1;
	
	printf( "%d\n", any(int)( obj, is_positive ) );
}



struct parent
{
	const char* field_parent
}

struct child
{
	struct parent base;
	const char* field_child;
}

void parent_print( struct parent* this )
{
	printf( "%s\n", this->field_parent );
}

void inclusion( void )
{
	struct child c;
	c.base.field_parent = "parent";
	c.field_child = "child";
	
	parent_print( (struct parent*) &c );

}