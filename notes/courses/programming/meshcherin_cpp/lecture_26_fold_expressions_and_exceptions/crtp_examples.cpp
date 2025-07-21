#include <iostream>


// Добавляем функциональность через CRTP
template<typename T>
struct Printable {
    void print() const {
        std::cout << static_cast<const T*>(this)->data() << "\n";
    }
};

struct User : Printable<User> {
    std::string data() const { return "User Data"; }
};

struct Document : Printable<Document> {
    std::string data() const { return "Document Text"; }
};




template <typename head, typename... tail> 
void print_t( const head& head_z, const tail&... tail_z ) 
{
	//std::cout << "sizeof:" << sizeof...( tail_z ) << std::endl; // operator, size of package ( of types or variables )
	
	//std::cout << head_z << std::endl; 
	head_z.print();
	
	if constexpr ( sizeof...( tail_z ) > 0 )
		print_t(tail_z...);
	
}





int main()
{
	
	User u;
Document d;
	
	print_t( u , d );
	
	return 0;
}