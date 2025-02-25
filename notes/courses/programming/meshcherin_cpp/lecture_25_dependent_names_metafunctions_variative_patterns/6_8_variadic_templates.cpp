#include <iostream>

template <typename... /*... means declaration of package of types here*/ types> // package of types
void f( types... tx ) // unpacking of types, now tx is package of variables 
{
	// g(tx...); // unpacking of tx
}

void print() {}

template <typename head, typename... tail> 
void print( const head& head_z, const tail&... tail_z ) 
{
	std::cout << "sizeof:" << sizeof...( tail_z ) << std::endl; // operator, size of package ( of types or variables )
	std::cout << head_z << std::endl; 
	print(tail_z...);
	
}





// O(n), compiler will instantiate all structures, lazy evaluation will be made in runtime
template <typename first, typename second, typename... tail> 
struct is_homogeneous 
{
	static constexpr bool value = std::is_same_v<first, second> &&
		is_homogeneous<second, tail...>::value;
};

template <typename first, typename second>
struct is_homogeneous<first, second> 
{
	static constexpr bool value = std::is_same_v<first, second>;
};





int main()
{
	
	
	std::cout << is_homogeneous<int, int>::value << std::endl;
	std::cout << is_homogeneous<int, float>::value << std::endl;
	std::cout << is_homogeneous<int, int, int>::value << std::endl;
	std::cout << is_homogeneous<int, int, float>::value << std::endl;
	
	print(1,2,3,4);
}