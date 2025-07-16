#include <iostream>

// A simple class that demonstrates functionality by printing a message
class printer
{
public:
    // Prints "Hello." to standard output
    void print_hello_to_std_out() const
    {
        std::cout << "Hello." << std::endl;
    }
};

// A basic smart pointer implementation demonstrating the arrow operator
template <typename T>
class smart_pointer
{
    T* ptr;  // Raw pointer being managed
    
public:
    // Constructor takes ownership of the provided pointer
    explicit smart_pointer(T* pointer) : ptr(pointer) {}
    
    // Destructor automatically releases the managed memory
    ~smart_pointer() { delete ptr; }
    
    // Overloaded arrow operator provides access to the managed pointer's members

	const T* operator->() const  // Return const pointer for const method
    {
		if( ptr == nullptr )
			std::cerr << "Attempt to dereference null pointer." << std::endl;
        return ptr;  // Returning nullptr despite the warning
    }
    
	T* operator->()
    {
		if( ptr == nullptr )
			std::cerr << "Attempt to dereference null pointer." << std::endl;
        return ptr;  // Returning nullptr despite the warning
    }
	
    // Deleted copy operations to prevent double deletion
    smart_pointer(const smart_pointer&) = delete;
    smart_pointer& operator=(const smart_pointer&) = delete;
};

int main()
{
    // Create a smart pointer managing a new printer instance
    smart_pointer<printer> smart_ptr( new printer() );

    // Demonstrate arrow operator usage - both forms are equivalent
    smart_ptr->print_hello_to_std_out();  // Equivalent to: (smart_ptr.operator->())->print_hello_to_std_out()
    (smart_ptr.operator->())->print_hello_to_std_out();  // Explicit form showing what happens behind the scenes

    smart_pointer<printer> smart_ptr_to_nothing( nullptr );
	
	smart_ptr_to_nothing->print_hello_to_std_out(); // Calling a member function through a null pointer is UB
	static_cast<printer*>( nullptr )->print_hello_to_std_out(); // warning: ‘this’ pointer is null [-Wnonnull]
	
	smart_pointer<bool> another_smart_ptr_to_nothing( nullptr );
	// another_smart_ptr_to_nothing->print_hello_to_std_out(); // error: request for member ‘print_hello_to_std_out’ in ‘* another_smart_ptr_to_nothing.smart_pointer<bool>::operator->()’, which is of non-class type ‘bool’

    return 0;
}