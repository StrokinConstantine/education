#include <iostream>

// for specific types template behaves differently 

// graph of "more specific" relation 







template <typename T>
class vector
{
	T* arr;
};

// full specialization <>
template <>
class vector<bool>
{
	char* arr;
};








template <typename T, typename U>
struct S{ S(){ std::cout << "T, U" << std::endl; } };

// partial specialization
template <typename W> // for every W if T == U
struct S<W, W> { S(){ std::cout << "W, W" << std::endl; } }; // meta-signature that is specific type of template <typename T, typename U>

template <typename W>
struct S<int, W> { S(){ std::cout << "int, W" << std::endl; } };

template <typename W>
struct S<W, int> { S(){ std::cout << "W, int" << std::endl; } };

template <>
struct S<int, int> { S(){ std::cout << "int, int" << std::endl; } };
// S has 2 template parameters, we cannot change that



template <typename T>
struct SS {};
template <typename T>
struct SS<T&> { SS() = delete; }; // specialization for references
template <typename T>
struct SS< const T> { SS(){ std::cout << "const T" << std::endl; } };
// for some specializations we can delete ctors
template <typename T>
struct SS< T*> { SS(){ std::cout << "T*" << std::endl; } };

int main()
{
	int x = 0;
	// more specific specialization is most preferred 
	S<float, double> a1;
	S<float, float> a2;
	// S<int, int> a3; //  error: ambiguous template instantiation for ‘struct S<int, int>’
	// instantiation = template code generation
	
	S<int, float> a4;
	
	// now this is okay
	S<int, int> a3;
	
	// SS<const int&> a; // T&; reference > const
	
	SS<const int*> a5; //<-> T = const int; 
	SS<int * const> a6; //T = int*
	 
}