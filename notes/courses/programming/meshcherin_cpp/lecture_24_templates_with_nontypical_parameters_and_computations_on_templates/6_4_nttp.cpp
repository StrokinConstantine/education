#include <iostream>
#include <array>
#include <complex>
#include <vector>
#include <stack>

// non-type template parameters ( for now only integral types )

template<typename T, size_t N>
class array
{
	T arr[N]; // array on stack
};

template<size_t M, size_t N, typename field = std::complex<double>>
class matrix {}; // matrix of size M x N with elements of type field

// now matrices 4x1 and 3x2 have different types ( with no implicit conversions between them )

template<size_t N, typename field>
using square_matrix = matrix< N, N, field >; 

template<size_t M, size_t K, size_t N, typename field>
matrix<M, N, field > operator*( const matrix<M, K, field>& a, const matrix<K, N, field>& b ); // declaration of operator without definition
// now if matrices are not matched in size, it will be compilation error

// *= for square matrices
// template function det<N, N>


// template tempate parameters ( template parameters that are templates itself )
// std::stack dispatches methods to inner vector ( or deque )( is that related to our topic? )

template < typename T, template<typename, typename> /*template tempate parameter*/  class container = std::vector > // here until c++17 you must wirte "class" ( typename since C++17 )
class stack
{
	container< T, std::allocator<T> > my_container; 
};


template < typename T, template<typename> /*template tempate parameter*/  class container = std::vector > // here until c++17 you must wirte "class" ( typename since C++17 )
class stack_1
{
	container< T > my_container; 
};

template <typename T>
using myv = std::vector<T>;


int main()
{
	std::array<int, 100> a; // 100 is non-type template parameter
	
	// template parameters must be known on compilation time ( constexpr )
	
	matrix<5,5> m;
	
	square_matrix<5, int> s_m;
	
	int x = 2;
	
	// matrix<x, x> m_1; // error: the value of ‘x’ is not usable in a constant expression
	
	const int y = 2;
	
	constexpr int z = 3; // constexpr ( since C++11 ) for variables means that it is constant known in compilation time

	
	matrix<y, y> m_2; // okay, but sometimes it will not work
	
	stack<int ,std::vector> s; // in reality std::stack, queue, priority_queue, accepts as second argument not template, but specific type:
	
	// adapters: std::stack, queue, priority_queue ( by default adapters to std::deque )
	
	std::stack<int, std::vector<int>> s_1; //okay
	// std::stack<int, std::vector> s_2; //error: type/value mismatch at argument 2 in template parameter list for ‘template<class _Tp, class _Sequence> class std::stack’
	
	
	
	
	// std::vector has 2 parameters: 1 - type, 2 - allocator, by default = std::allocator<T> ( every container has it )
}