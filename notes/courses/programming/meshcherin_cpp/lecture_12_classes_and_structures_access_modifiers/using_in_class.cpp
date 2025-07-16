#include <iostream>

class using_in_class
{

private:
	
	using aliased_int_fast64_t = int_fast64_t; // Alias a type
	using aliased_std_string = std::string;
	// using std::cout; // error: using-declaration for non-member at class scope
	// using namespace std; // error: expected nested-name-specifier before ‘namespace’
	
	aliased_int_fast64_t field_int = 1; // Default initialization
	aliased_std_string field_string = "abc";
	
public:

	// You cannot write expressions at class scope
	// 32; // error: expected unqualified-id before numeric constant

	// You cannot declare namespaces at class scope
	// namespace N {} // error: expected unqualified-id before ‘namespace’
	
	explicit using_in_class(aliased_int_fast64_t a, aliased_std_string b); // Declaration
	
	void print_fields() const; // Declaration

};

int main()
{
	
	return 0;
}