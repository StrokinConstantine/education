#include <iostream>
#include <type_traits>

// fold expressions since C++17

template <typename... Types>
struct all_pointers
{
	static const bool value =  ( std::is_pointer_v<Types> && ... ); // unfolds in compile time
};

template <typename Head, typename... Tail>
struct is_homogeneous
{
	static const bool value =  ( std::is_same_v<Head, Tail> && ... ); // unfolds in compile time
};

template<typename Types>
void print (const Types&... types)
{
	
}

int main()
{
	
}