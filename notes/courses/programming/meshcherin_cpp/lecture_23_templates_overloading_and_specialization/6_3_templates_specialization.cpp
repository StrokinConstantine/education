#include <iostream>

// for specific types template behaves differently 

// graph of "more specific" relation 



template <typename T>
class vector
{
	T* arr;
};

// full specialization (for classes) <>
template <>
class vector<bool>
{
	char* arr;
};




template <typename T, typename U>
struct S{ S(){ std::cout << "T, U" << std::endl; } };

// partial specialization (for classes)
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







// functions

/*
	function overloading != template funcitons specialization

*/

// for functions specialization := template <> ...
// for functions there in no partial specialization

template <typename T, typename U>
void f(T, U)
{
	std::cout << "f T U" << std::endl;
}

template<typename T>
void g(T, T, T)
{
	std::cout << "g T T T" << std::endl;
}

template <> // specialization for f(T, U)
void f(int, int)
{
	std::cout << "f int int" << std::endl;
}

template <typename T>
void f(T, T)
{
	std::cout << "f T T" << std::endl;
}

template <> // specialization for f(T, T)
void f(int, int)
{
	std::cout << "f int int" << std::endl;
}




// 3 overloaded candidates ( template version 1, template version 2 ( with specialization ), non-template version 3 )
// firstly compiler resolutes overloading -> specialization resolution ( maybe )

template <typename T, typename U>
void h(T, U)
{
	std::cout << "h T U" << std::endl;
}
template <typename T>
void h(T, T)
{
	std::cout << "h T T" << std::endl;
}
template <> // specialization for h(T, T) (closer from top)
void h(int, int) // but if it would h(int, double), it would be specialization for h(T, U)
{
	std::cout << "h int int" << std::endl;
}

void h(int, int)
{
	std::cout << "non-template h int int" << std::endl;
}







int main()
{
	h( 1.0, 1.0 );
	h( 1.0, 1.0f );
	
	
	
	
	 
	f(1, 1); // depends on declaration order ( not exactly )

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