#include <iostream>

class C
{
private: // you can access y only within C
  int x = 2;

private:
  int y = 5;

};

int main()
{
  C c;
  // c.x; // error: ‘int C::x’ is private within this context; access error ( it occurs only after checking existence of name and ODR )
  
  std::cout << (int&)(c); // undefined behavior
  
}