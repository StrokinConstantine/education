#include <iostream>

void g1 ( const std::string& ) { std::cout << "const";}
void g1 ( std::string& ) { std::cout << "string";} // exact type matching

void g2 ( const std::string ) { std::cout << "const";}
// void g2 ( std::string ) { std::cout << "string";} // error: redefinition of ‘void g2(std::string)’

const int& g3( int x )
{
	return x++; // dandling reference, no lifetime expansion
}

int main ()
{
	int*pt = new int(9);
	
	int** pp = &pt;
	
	// const int** cpp = pp; // error: invalid conversion from ‘int**’ to ‘const int**’ [-fpermissive]
	
	// you can't add const deeper than on 1 level
	
	
	
	const std::string str = "abc";
	g1(str);
	
	// const - type modifier that makes new type which forbids modifying operations
	const int a = 2; // same type as int, but some operations are forbidden now ( =, +=, ++ )
	int const b = a;
		
	int *p;
	const int* pc = p; // int* -> const int*
	
	int x = 2;
	pc = &x;
	
	const int& r_x = x; // constant reference
	const int* ptr_x = &x; // pointer to a constant
	int* const const_ptr_x = &x; // constant pointer
	// there is no 'int& const' type 
	
	// const int* ptr_1 = new const int; // error: uninitialized const in ‘new’ of ‘const int’
	const int* ptr_2 = new const int(2);
	new const int[10]{};
	
	// you can initialize constant references with rvalues
	
	// lifetime expansion, occurs only when you declare local varibles
	const int& x1 = 5;
	const std::string& s = "abc"; // string will be destroyed when lifetime of s ends
	
}


void f1 ( std::string local_copy ) {} // by value ( rvalue and lvalue )
void f2 ( std::string& ref ) {} // by reference ( only lvalue )
void f3 ( const std::string& const_ref ) {} // by constant reference( rvalue and lvalue )

/*
	there is no sense to accept arguments by constant reference of primitive types
	(*ptr_a); is longer than a;
	references are pointers on low level
*/