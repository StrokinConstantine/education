#include <iostream>

// task: list with allocator,  stack_allocator


// most dumb allocator = std::allocator

// pool-allocator - allocates a lot of memory at once?

// pool allocator allocates big array at once ( operator new called only once  ) , when you call allocates, it gives chunks of this array 

// stack allocator - allocates memory on stack

// free_list_allocator: when you ask for nodes, allocator allocates them, but when you free them, allocator stores them in "free nodes " list, and when you want add nodes again, it gives you free nodes (frof free nodes list)

// Let accept array by reference (or pointer ) in allocator constructor


/*
 копирование аллокатора обычно не подразумевает копирование пула, подразумевается что аллокатор легковесный объект для копирования 
 
 shared_ptr<>? для аллокатора? чтобы удалить пул?

отдельный класс - пул, для управления выделенным массивом ,запретить копировать пул. А в аллокаторе хранить указатель на пул.





*/


// container -> allocator_traits -> allocator -> operator new -> malloc -> OS





// allocator_traits -  предопределяет многие функции и юзинги для всех аллокаторов, чтобы не пришлось их писать заново в каждом аллокаторе
// construct, destroy, rebind - этих функций нет в allocator, они есть в allocator_traits

// containers must обращаться не к аллокатору, а к allocator_traits


template <typename allocator>
struct allocator_traits {
	
	template <typename U, typename... Args>
	static void construct( allocator alloc, U* ptr, const Args&... args ) {  // static as all other methods, because we will never create allocator_traits objects
		
		
		if constexpr ( /* allocator has method construct */ ) {
			// alloc.construct(ptr, args...);
		} else {
			new (ptr) U(args...);
		}
		

	}
	
	// struct rebind_alloc работает как rebind for all allocators, but allocator can define its rebind, and this funciton will call it, otherwise ...
};









struct <typename T>
struct allocator {
	
	// usings, value_type ,pointer_type ...
	
	T* allocate( size_t count ) { // vector call this when reserve
		return reinterpret_cast<T*>( new char[ sizeof(T) * count ] );
	}
	
	void deallocate(T* ptr, size_t count ) { // standard требует чтобы этот count был равен count в allocate
		delete[] reinterpret_cast<char*>(ptr);
	}
	
	template <typename U, typename... Args> // because we need to construct T on allocator<node>  in list. We do not want to create allocator<T> every time again, when we want to construct T in allocator<node>
	void construct( U* ptr, const Args&... args ) { 
		new (ptr) U(args...); // construct is not always just placement new
	}
	
	template <typename U>
	void destroy(U* ptr) {
		ptr->~U();
	}

	// operator== returns true ( all standard allocators equal)


	// meta-function
	
	
	template <typename U>
	allocator( allocator<U> ) { } // possibility to construct from another allocator with any template type
	
	
	template <typename U>
	struct rebind {
		using other = allocator<U>;
	};

};

// why not do make allocator as template template parameter?
// template <typename T, template<typename> allocator = std::allocator >
// we cannot do that, because allocator has another template parameters, and they can be not types, but also numbers
// template <typename T, template<typename...> allocator = std::allocator > // this will not help, because we can have numbers


template <typename T, typename allocator = std::allocator<T>>

class list {
	
	struct base_node {
		base_node* prev;
		base_node* next;
	};
	
	struct node : base_node {
		T value;
	};
	
	
	base_node fake_node;
	size_t count;
	//allocator alloc;pe

	typename allocator::template rebind<node>::other alloc; // double depended name
	// typename allocator rebind<node>::other alloc;
	
	list( const allocator& alloc ) : fake_node(), count(),  alloc( alloc ) /* construct from another allocator with any template type */ {
		
	}
};






int main() {
	
	std::array<char, 1'000'000> arr;
	
	StackAllocator<int> alloc(arr);
	
	std::list<int, StackAllocator<int>> lst; // list on stack

	// Problems: list allocates not ints, but nodes:, unordered_map allocates array of pointers and forward_list 
	// -> we need to allocate another type ( not T )
	
	// in C++17 solution: allocator is non-template
	
	static_assert( sizeof( std::vector<int> ) == 24 ); // because of EBO
	
	return 0;
}