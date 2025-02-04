#include <iostream>
#include <vector>

void f ( int* ) {}
// void f ( int[1] ) {} // error: redefinition of 'void f(int*)'


void f ( int(*)[5] ) {}

void f ( int** ) {} // array of pointers = 
// void f ( int*[5] ) {} // error: redefinition of ‘void f(int**)’

int main()
{
	int arr_1[10];
	int arr_2[10] = { 1, 2, 3 };
	int arr_3[] = { 1, 2, 3 };
	int arr_4[10] = {  };
	int arr_5[10]{1, 2};
	
	arr_2[0];
	arr_2[10]; // undefined behavior
	arr_2[-1]; // undefined behavior
	
	// int arr_6[10'000'000]; // stack overflow
	static int arr_7[10'000'000]; // okay
	
	*( arr_2 + 1); // array to pointer conversion
	
	arr_2[1];
	*(arr_2 + 1);
	1[arr_2];
	*(1 + arr_2);
	int* ptr = arr_2 + 2;
	
	// int* and int[] are different types, but they are equal as function parameters
	// when we call function array as a parameter becomes pointer 
	
	std::cout << ptr[-1] << "\n";
	std::cout << sizeof( ptr ) << "\n"; // 8
	std::cout << sizeof( arr_1 ) << "\n"; // 40
	// arr_2 = arr_5; // error: invalid array assignment
	
	int* dynamic_arr_1 = new int[100]; // returns pointer
	
	// int* ptr = new int;
	// delete[] ptr; // undefined behavior
	// delete dynamic_arr_1; // undefined behavior
	
	std::cout << *( (dynamic_arr_1 - 1) ) << "\n";
	std::cout << *( (dynamic_arr_1 - 2) ) << "\n"; // approximately sizeof(int) * 100 on Linux, but on Windows there is no number that makes sense
	std::cout << *( (dynamic_arr_1 - 3) ) << "\n";
	std::cout << *( (dynamic_arr_1 - 4) ) << "\n";
	
	/*
		Difference of delete an delete[].
		To free an array we should remember its length ( delete[] do it ).
		So it practice, array length is located somewhere ( probably before actual array elements, and probably there is also the offset ).
		So delete[] looks at number before array. But delete just frees one memory cell.
	*/
	
	delete[] dynamic_arr_1;

	std::vector<int> v(10);
	// v[-1] = 500'000; // Aborted; double free or corruption (out) on Linux
	// vector tried to free 500'000 elements
	 
	// delete[] &v[0]; // Aborted; free(): double free detected in tcache 2 on Linux
	
	
	// variable length arrays are forbidden in C++, because otherwise offsets ( of functions, ... ) should be computed in runtime
	
	int arr_8[5][5];
	int* arr_9[5]; // array of 5 pointers to int
	int (*arr_ptr_1)[5]; // pointer to array of 5 integers
	
	// C style strings
	
	char* s = "sdf"; // char* in C, stored in static memory ( read only? ); in C++ const char*
	
	"abc\0d";
	 
	s[3] = 'd'; // Segmentation fault
	
	std::cout << s << "\n";
	
}