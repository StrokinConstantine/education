#include <iostream>
#include <type_traits> // since C++11

// functions that accept types ( and return type or value )


// since C++11 std::is_same
template <typename T, typename U>
struct is_same
{
	static constexpr bool value = false;
};

template<typename T> // specialization
struct is_same<T, T> 
{
	static constexpr bool value = true;
};

template<typename T, typename U>
void f(T x,  U y)
{
	// if ( typeid(x) == typeid(y) ) {} // runtime check
	
	// this "if" will be computed in runtime
	if ( is_same<T, U>::value )
	{
		// x = y; // error: cannot convert ‘std::__cxx11::basic_string<char>’ to ‘double’ in assignment
	} 
	
	// since C++17 this "if" will be computed in compile time
	if constexpr ( is_same<T, U>::value ) 
	{
		x = y; // okay, syntax has checked, but semantic has not ( almost )
	} 
}

// we don't know what type it is, T or T&

// is_const, is_pointer, is_reference, is_array - metafunctions

template <typename T>
struct remove_reference // remove_pointer, remove_const
{
	using type = T;
};

template <typename T>
struct remove_reference<T&>
{
	using type = T;
};


template <typename T>
struct remove_const
{
	using type = T;
};

template <typename T>
struct remove_const<const T>
{
	using type = T;
};




struct false_type
{
	static constexpr bool value = false;
	// to not repeat this line of code, we can inherit from this metafunction, to get field "value = false"
};




struct true_type
{
	static constexpr bool value = true;
};

template <typename T>
struct is_array : false_type {};

template <typename T>
struct is_array<T[]> : true_type {};

template <typename T, std::size_t N>
struct is_array<T[N]> : true_type {};



template <typename T>
struct is_member_pointer_helper : false_type {};

template <typename T, class U> // member of class U of type T
struct is_member_pointer_helper<T U::*> : true_type {};

template <typename T>
struct is_member_pointer : is_member_pointer_helper<typename std::remove_cv<T>::type> {}; // remove const and volatile

// the T[] and T[N] are different types (T[] is the array of unknown length)

template <typename T, T t>
struct integral_constant
{
	static constexpr T value = t;
};

// std::decay ( destroy ), function reference, function pointer, array -> pointer


template <typename T>
void g()
{
	typename remove_reference<T>::type x;
}



template <bool B, typename T, typename F> // meta ternary operator
struct conditional
{
	using type = F;
};

template <typename T, typename F>
struct conditional<true, T, F>
{
	using type = T;
};


// since C++14 template usings for all type_traits
template <bool B, typename T, typename F>
using conditional_t = typename conditional<B, T, F>::type;


// since C++14 template variables
template <typename T, typename U>
constexpr bool is_same_v = is_same<T, U>::value;



int main()
{
	
	
	
	constexpr bool val = true;
	
	
	
	typename conditional<val, int, double>::type my_var_2; 
	
	conditional_t<val, int, double> my_var; // since C++14, instead of previous line of code
	
	
	
	
	// since C++11 template using
	
	std::cout << is_same<double, int>::value << std::endl;
	std::cout << is_same<double, double>::value << std::endl;
	
	f<double, std::string> (1, "2");
	
	int a;
	int& b = a;
	
	remove_reference<int&>::type x; 
	
	int* ptr;
	int*& ptr_ref = ptr;
	
	
	false_type ft;
	
	std::cout << is_array<int>::value << std::endl;
	std::cout << is_array<int[]>::value << std::endl;
	std::cout << is_array<int*>::value << std::endl;
	
	std::cout << is_member_pointer<int false_type::*>::value << std::endl;
	std::cout << is_member_pointer<int>::value << std::endl;
	
	// std::rank = recursive template, which finds array dimension
	
	std::cout << std::rank<int[1][2][3][2]>::value << std::endl;
	
}