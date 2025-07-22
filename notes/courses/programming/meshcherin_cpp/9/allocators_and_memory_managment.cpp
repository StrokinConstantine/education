#include <iostream>


// most dumb allocator = std::allocator

// pool-allocator - allocates a lot of memory at once?

// pool allocator allocates big array at once ( operator new called only once  ) , when you call allocates, it gives chunks of this array 

// stack allocator - allocates memory on stack

struct <typename T>
struct allocator {
	
	T* allocate( size_t count ) { // vector call this when reserve
		return reinterpret_cast<T*>( new char[ sizeof(T) * count ] );
	}
	
	void deallocate(T* ptr, size_t count ) { // standard требует чтобы этот count был равен count в allocate
		delete[] reinterpret_cast<char*>(ptr);
	}
	
	template <typename U, typename... Args>
	void construct( U* ptr, const Args&... args ) {
		new (ptr) U(args...);
	}
	
	void destroy(T* ptr) {
		ptr->~T();
	}

	// operator== returns true ( all standard allocators equal)

};


int main() {
	
	
	
	return 0;
}