#include <iostream>#include <cassert>// basic compile time computations// compiler has limit of depth of recursivetemplate instantiation// -ftemplate-depth=1000000000 -> g++: internal compiler error: Segmentation fault signal terminated program cc1plustemplate< size_t n >class fibonacci{public:	static constexpr size_t value = fibonacci<n - 1u>::value + fibonacci<n - 2u>::value;; // O(n)	};template<>class fibonacci<0>{public:	static constexpr size_t value = 0;};template<>class fibonacci<1>{public:	static constexpr size_t value = 1;};template<int n, int d>struct is_prime_helper{	static constexpr bool value = n % d == 0 ? false : is_prime_helper<n, d - 1>::value;};template <int n>struct is_prime_helper<n, 1>{	static constexpr bool value = true;};template <int n>struct is_prime // O(n) in time and space{	static constexpr bool value = is_prime_helper<n, n - 1>::value; };template <>struct is_prime<1>{	static constexpr bool value = false;};template<int n>const bool is_prime_meta_function = is_prime<n>::value;template <typename T>struct S{	using A = int;};template <>struct S<double>{	static constexpr double A = 2;};template <typename T>void f(){	S<T>::A * x; // declaration or expression? }int main(){		f<int>();							assert( true ); // false -> std::abort		static_assert( is_prime_meta_function<257> ); // false -> compile time error		int x = 1;		// static_assert( x ); // error: non-constant condition for static assertion			// in matrix::det static_assert( n == m );		// only for primes n you can divide matrices ( if Z/Zn is a field )		std::cout << fibonacci<11>::value << std::endl;	std::cout << is_prime<257>::value << std::endl;		std::cout << is_prime_meta_function<257> << std::endl;}