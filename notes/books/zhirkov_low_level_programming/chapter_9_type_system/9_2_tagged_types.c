/*
	tagged types = structures, unions and enumerations
	the fields of the structures do not overlap, but sizeof of a structural type can be greater than the sum of element sizes because of gaps
	all union fields start at the same address
	if you assigned a union field to a value, the standard does not guarantee you anything about the values of other fields
	enumerations based on int
*/

struct pixel /* structure */
{
	uint8_t b;
	uint8_t g;
	uint8_t r;
};

typedef struct pixel pixel; /* do not do it, it hides iformation about the type */

union dword /* uinon */
{
	uint8_t array[2];
	uint16_t integer;
}

union vector_3d
{
	struct
	{
		double x; /* vec.named.x */
		double y;
		double z;
		
	} named;
	double raw[3];
}


union vector_3d_c11 /* since C11, the structures and unions can be anonymous when inside other structures or unions */
{
	struct
	{
		double x; /* vec.x */
		double y;
		double z;
		
	};
	double raw[3];
}

enum light /* enumeration */
{
	RED,
	YELLOW
};



int main ( void )
{
	struct { int16_t a; int8_t b } var_1; /* one-time structure ( anonymous )*/
	
	struct pixel my_pixel_1 = { 1, 2, 3 }; /* structure initialization */
	struct pixel my_pixel_2 = { 0 }; /* all fields will be zero */
	struct pixel my_pixel_3 = { .b = 1, .g = 3 }; /* since C99, unmentioned fields will be initialized to zeros */
	
	var_1.a = 0;
	var_1.b = 3;


}