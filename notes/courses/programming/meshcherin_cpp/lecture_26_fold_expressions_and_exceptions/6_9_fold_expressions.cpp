#include <iostream>
#include <type_traits>

// fold expressions since C++17


/*
	fold expressions syntax:
	
	( pack op ... ), ( E op ... ) -> ( E_1 op ( ... op ( E_(N - 1) op E_N ) ) )
	( ... op pack )
	( pack op ... op init )
	( init op ... op pack )
*/

template <typename... Types>
struct all_pointers
{
	static constexpr bool value = /* fold expression */ ( std::is_pointer_v<Types> && ... ); // unfolds in compile time
};

template <typename Head, typename... Tail>
struct is_homogeneous
{
	static constexpr bool value = ( std::is_same_v<Head, Tail> && ... ); // unfolds in compile time
};

template <typename... Types>
void print( const Types&... types )
{
	( std::cout << ... << types ); // ( init op ... op pack )
}


int main()
{
	int&& a = 2;
	
	std::cout << all_pointers<int*, double*, size_t*>::value << std::endl;
	std::cout << all_pointers<int*, double, size_t*>::value << std::endl;
	
	
	print( 1, 2, 3, "2" );
}