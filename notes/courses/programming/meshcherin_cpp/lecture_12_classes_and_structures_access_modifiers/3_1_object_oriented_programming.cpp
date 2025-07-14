/*
 * Structures vs. Classes in C++:
 * -----------------------------
 * - Nearly identical in functionality, differ only in default access:
 *   - struct: 
 *     * Members public by default
 *     * Inheritance public by default
 *   - class:
 *     * Members private by default
 *     * Inheritance private by default
 *
 * Member Functions (Methods):
 * --------------------------
 * - Non-static methods implicitly receive:
 *   - Hidden first parameter 'this' (a T* pointer)
 *   - Points to current object instance
 *   - Type depends on method const-ness:
 *     * T* for regular methods
 *     * const T* for const methods
 *
 * Key Implications:
 * ----------------
 * - Method calls obj.func() transform to func(&obj)
 * - Const correctness affects 'this' pointer type
 * - Explains why member functions can access object data
 */
 
#include <iostream>
#include <cstdint>

struct obj
{
	void print()
	{
		std::cout << "obj::print()" << std::endl;
	}
};

struct smart_ptr_to_obj
{
    obj* ptr;

    smart_ptr_to_obj( obj* p ) : ptr(p) {}
	~smart_ptr_to_obj() { delete ptr; }
	
	obj* operator->()
	{
		return ptr;
	}
};




class using_in_class_example;

class using_in_class_example
{

private:
	
	using my_fast_int64 = int_fast64_t; // Alias a type
	using string = std::string;
	// using std::cout; // error: using-declaration for non-member at class scope
	// using namespace std; // error: expected nested-name-specifier before ‘namespace’
	
	my_fast_int64 field_int64 = 1; // Default initialization
	string field_string;
	
public:

	// You cannot write expressions at class scope
	// 32; // error: expected unqualified-id before numeric constant

	// // You cannot declare namespaces at class scope
	// namespace N {} // error: expected unqualified-id before ‘namespace’
	
	explicit using_in_class_example(my_fast_int64 a, string b); // Declaration
	
	void print_fields() const; // Declaration

};

using_in_class_example::using_in_class_example(my_fast_int64 a, string b) : field_int64(a), field_string(b) {}

void using_in_class_example::print_fields() const // qualified-id
{
	std::cout << "Object address (this): " << this << std::endl;
	std::cout << "Field values: " << this->field_int64 << ", " << this->field_string << "." << std::endl;
	
	field_int64; // Implicit
	this->field_int64; // Explicit
}

class alignment_in_class_example
{

private:

    // Three 4-byte integers (aligned at 4-byte boundaries)
    // No padding needed between them since they are the same type

	int32_t first_field_int32 = 1; // Offset: 0 bytes
	int32_t second_field_int32 = 2; // Offset: 4 bytes
	int32_t third_field_int32 = 3; // Offset: 8 bytes
	
    // 8-byte double (aligned at 8-byte boundary)
    // Requires 4 bytes of padding before it (since 12 % 8 != 0)
	double field_double = 23.4; // Offset: 16 bytes (after padding)

    // Inner class declaration + field definition
	class inner_class_and_field_declaration
	{
		int8_t some_field;
	} field_with_inner_class_type;  // Field of type inner_class_and_field_declaration
	
	 // Anonymous inner class + field definition
	class
	{
		int8_t some_field;
	} field_with_anonymous_class_type; // Field of an unnamed type

    // The compiler preserves field order, so:
    // - reinterpret_cast to a bitwise-identical struct is possible
    // - The first field's address == the object's address
	
public:

	 // Inner class declaration (unused)
	class [[maybe_unused]] inner_class_declaration
	{
		int8_t some_field;
	};

	void first_function () const; // Member function declaration
	
	void second_function() const; // Member function declaration
	
};

// Member function definitions
void alignment_in_class_example::first_function() const
{
	std::cout << "first_function has been called" << std::endl;
	second_function(); // No forward declaration needed (class scope is fully visible)
	this->second_function(); // this has type T*, arrow operator can be overloaded
	(*this).second_function(); //  *this has type T&, dot operator cannot be overloaded
}

void alignment_in_class_example::second_function() const
{
	std::cout << "second_function has been called" << std::endl;
}

int main( void )
{
	
	using_in_class_example a( 1, "abc" );
	a.print_fields();
	
	alignment_in_class_example b;
	b.first_function();
	
	
    // Local structure with default values
    struct local_structure
	{
        uint_fast8_t x = 1;  // Default initialization
        double y = 2.0;  // Default initialization
    };
	
	// Aggregate initialization examples
	// Aggregate initialization works as long as structure has no constructors and fields are public
	
	[[maybe_unused]] struct local_structure  loc_struct_comp{ 3, 6.0 }; // Complete initialization
	[[maybe_unused]] struct local_structure loc_struct_part{ 8 };       // Partial initialization (y will be 2.0)
  
	
	[[maybe_unused]] struct alignment_in_class_example::inner_class_declaration some_var;
  
    // Structure size and alignment demonstration
    struct alignment
	{
        int8_t a = 1;    // 1 byte
        // 7 bytes padding (on 64-bit systems)
        double b = 2.0;    // 8 bytes
        int16_t c = 3;   // 2 bytes
        // 6 bytes padding (on 64-bit systems)
    };
	
    std::cout << "Size of struct alignment: " << sizeof( alignment ) << " bytes.\n";
    std::cout << "Alignment rules:\n";
    std::cout << "- Compiler places n-byte variables at addresses multiples of n (for n = 2^k)\n";
    std::cout << "- Classes are typically aligned to 8-byte boundaries on 64-bit systems\n";
  
	
	alignment alignment_var;
	[[maybe_unused]] alignment* alignment_var_ptr = &alignment_var;
	alignment_var.a; // If a is uninitialized, it is UB
	
	
	// Demonstrating operator precedence: . and -> have priority over unary operators
    struct Demo
	{
        int_least16_t x = 42;
        int_least16_t* ptr = &x;
	};
    
	Demo d;
    Demo* d_ptr = &d;

    // Example 1: . has higher precedence than *
    int_least16_t n1 = *d.ptr;   // Equivalent to *(d.ptr), NOT (*d).ptr
    std::cout << "n1: " << n1 << ".\n";  // Output: 42

    // Example 2: -> has higher precedence than &
    int_least16_t* n2 = &d_ptr->x;  // Equivalent to &(d_ptr->x), NOT (&d_ptr)->x
    std::cout << "n2: " << *n2 << ".\n";  // Output: 42
	
	
	smart_ptr_to_obj sp( new obj );
	
	sp->print(); // Is interpreted as ( sp.operator->() )->print()
	( sp.operator->() )->print();
	return 0;
}