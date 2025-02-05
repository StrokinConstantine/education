/*
  in C++ structures and classes are almost the same ( in structure everything is public by default, in class everything is private by default )

*/

#include <iostream>

// classes and structures, encapsulation
/*
  inside a class you cannot write expressions, declare namespaces, but you can use usings
  using:
    to alias a type
    to get a variable from namespace
    to get all entities from namespace
  
  methods = functions that implicitly accepts object as the first argument
  . and -> have priority over unary operators
*/

struct s_1;

class c_1;


struct s_1
{
  using str = std::string;
  
  int32_t x = 1; // default value is 1
  // padding of 4 bytes
  double y = 32.2; // field
  
  void f(int y) // method
  {
    std::cout << x + y;
    ff(); // you do not need forward declaration in class scope
  }
  
  
  void ff()
  {}
  
  void method(); // declaration
  
};

void s_1::method() // qualified-id
{
  this->ff();
  ff();
  this; // self in Python
  *this;
}


struct s_2
{
  // there is no padding because int32_t are placed in memory in addresses of multiples of 4
  int32_t x1;
  int32_t x2;
  int32_t x3;
  
  struct s_3 // we declared structure, but we do not declared a field, so sizeof( struct s_3 ) = 12
  {
    char c;
  };
  
  struct s_4
  {
    char c;
  } s; // here we declared a field s
  
  // inner class
  struct
  {
    char c;
  } ss; // here we declared a field s of anonymous structure
  
};

// compiler is not changing the order of fields, so you can do reinterpret_cast to bitwise equal structure or to the first field of the structure


int main()
{
  // local class
  struct s_5
  {
    int x = 1;
    int y = 2;
  }
  
  struct s_2::s_3;
  struct s_1 s_1_var1{ 2, 2.2 }; // aggregate initialization
  struct s_1 s_1_var2{ 2 }; // aggregate initialization, y = default value
  
  // aggregate initialization works as long as structure has no constructors and fields are public 
  
  s_1_var1.x; // you cannot redefine operator "."
  
  s_1_var1.x; // if x is uninitialized, it is undefinded behavior
  
  // sizeof ( structure ) = sum by all fields of sizeof( field ) + alignment

  std::cout << sizeof( struct s_2 );
  // compiler places 8-byte variables in addresses which are multiples of 8
  // also compiler places structures in addresses which are multiplies of 8
  
}