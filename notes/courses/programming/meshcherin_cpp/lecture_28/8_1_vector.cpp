#include <iostream>
#include <vector>
#include <cstdint>

// 8_containers

// TODO: add constructors with allocators 

// библиотека boost 

// we can use memcpy, but it will not work if T has a pointer or reference to its field ( std::string has one )

// task : list on stack allocator that faster than standard list

template <typename T, typename allocator = std::allocator<T>>
// class vector : private allocator { to EBO
class vector
{
    T* arr;      // Pointer to the underlying array
    size_t sz;   // Current number of elements (size)
    size_t cap;  // Current capacity (allocated memory)
    allocator alloc;
	
	//since C++20: attribute [[no_unique_address]:
	// [[no_unique_address]] allocator alloc;
	
	
    void reserve(size_t new_cap) {
        if (new_cap <= cap)
            return;  // No need to reallocate if we have enough capacity
		
        // BAD PRACTICE 1: Using new T[new_cap]
        // T* new_arr = new T[new_cap];
        // Problems:
        // 1. Requires T to have a default constructor (which may not exist)
        // 2. Unnecessarily constructs 'new_cap' default objects
        // 3. Wastes performance constructing objects we'll overwrite
		
        // Allocate raw memory - may throw std::bad_alloc
        // Note: Exception safety is preserved here because if allocation fails,
        // no existing resources are affected
		
		
        // T* new_arr = reinterpret_cast<T*>(new char[new_cap * sizeof(T)]);  // Still problematic
        //T* new_arr = alloc.allocate( new_cap ); 
		std::allocator_traits( alloc )::allocate( alloc, new_cap );
		std::allocator_traits( alloc )::allocate( new_cap );
		
		// allocate, deallocate есть в allocator_traits просто для симметрии, хотя в аллокаторе они должны быть.
		
        size_t i = 0;
		
        try {
            // Copy existing elements using placement new
            for (; i < sz; ++i) {
                // BAD PRACTICE 2: Direct assignment to uninitialized memory
                // new_arr[i] = arr[i];
                // Undefined Behavior:
                // - No T object exists at new_arr[i] yet
                // - Assignment operator requires valid objects on both sides
                
                // CORRECT APPROACH: Placement new construction
                // new (new_arr + i) T(arr[i]);  // Constructs T object in-place
                alloc.construct( new_arr + i, arr[i] );
				
                // Important notes about placement new:
                // 1. Doesn't allocate memory (uses pre-allocated space)
                // 2. The placement new itself cannot throw
                // 3. However, T's copy constructor might throw
            }
			
            // Difference from push_back:
            // Here we're copying existing elements, while push_back would do:
            // try { new (new_arr + sz) T(new_value); } catch(...) {...}
            
        } catch(...) {
            // Exception safety cleanup:
            // If any constructor throws, we must:
            // 1. Destroy all successfully constructed objects
            for (size_t j = 0; j < i; ++j) 
                // (new_arr + j)->~T();  // Explicit destructor call
               alloc.destroy( new_arr + j );
			   // Note: Destructors must not throw (undefined behavior if they do)
            // 2. Free the allocated memory
            //delete[] reinterpret_cast<char*>(new_arr);  // delete won't throw
            alloc.deallocate( new_arr, new_cap );
			// 3. Propagate the exception
            throw;
        }
        
        // Cleanup old array:
        // Destroy all existing objects
        for (size_t i = 0; i < sz; ++i)
            //(arr + i)->~T();
			alloc.deallocate( arr + i, new_cap );
        // BAD PRACTICE 3: Incorrect deallocation
        // delete[] arr;
        // Problems:
        // 1. We allocated as char[] but are deleting as T[]
        // 2. The array size prefix (if any) would be incorrect
        // 3. Will try to call destructors on wrong number of elements
        
        // CORRECT APPROACH: Match allocation type
        // delete[] reinterpret_cast<char*>(arr);
        alloc.deallocate( arr, cap );
        // Update vector state
        arr = new_arr;
        cap = new_cap;
    }
    
    void push_back(const T& value)
    {
        if (sz == cap)
        {
            // Growth policy: double capacity or start with 1
            reserve(cap > 0 ? cap << 1 : 1);
        }
        
        // Exception safety consideration:
        // If the constructor throws during element construction, we must undo all reservations
        // This is why implementing push_back via resize would be problematic
        new (arr + sz) T(value);  // Placement new construction
       ++ sz;  // Only increment size after successful construction
    }
	
    // Note: Missing other important methods:
    // 1. Destructor to clean up all elements
    // 2. Copy/move operations (Rule of Five)
    // 3. Element access methods (at, operator[])
    // 4. Iterators
};




template<>
class vector<bool>  // The infamous vector<bool> specialization
{
    char* arr;      // Stores bits packed into bytes (8 bits per char)
    size_t sz;      // Number of bits (not bytes!)
    size_t cap;     // Capacity in bits (not bytes!)

    // Proxy class for bit manipulation
    struct bit_reference
    {
        char* cell;             // Points to the byte containing the bit
        uint8_t bit_index_in_cell;  // Bit position (0-7)

        bit_reference(char* cell, uint8_t index) 
            : cell(cell), bit_index_in_cell(index) {}

        // Assignment operator that modifies the actual bit
        bit_reference operator=(bool b)
        {
            if (b)
                *cell |= (1 << bit_index_in_cell);   // Set bit
            else
                *cell &= ~(1 << bit_index_in_cell);  // Clear bit
            
            return *this;  // Returns a copy (required for chaining: v[1] = v[2] = true)
        }

        // Implicit conversion to bool
        operator bool() const
        {
            return *cell & (1 << bit_index_in_cell);  // Test bit
        }
    };

public:
    // Returns a proxy object, not a direct bool reference
    bit_reference operator[](size_t i)
    {
        return bit_reference{arr + i / 8, i % 8};  // byte offset + bit position
    }

    // ===== Why This Breaks Container Rules =====
    // 1. Doesn't return a true reference (bool&)
    // 2. operator[] returns a temporary proxy
    // 3. Not a standard container due to space optimization
};


template <typename T>
void debug(T) = delete;

// debug(var); // Trick to make compiler say the type name of var

int main()
{
	
	std::vector<bool> v(10);
	
	v[5] = true; // v[5] - rvalue, so we assign to rvalue here!
	
	return 0;
}