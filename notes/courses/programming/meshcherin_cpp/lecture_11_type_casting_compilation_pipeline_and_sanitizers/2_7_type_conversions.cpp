#include <iostream> // in iostream there is almost only declarations, definitions are in .o file in standard directory

int main() 
{
  // it is better to avoid type conversions
  
  long long y = 1729;
  double& d = reinterpret_cast<double&>(y); // undefined behavior
  
  d = 1.0f;
  
  // std::cout << d << std::endl;
  // std::cout << y << std::endl;
  
  y;
  long long *p = &y;
  // std::string* str = reinterpret_cast<std::string*>(p);
  // std::cout << *str;
  
  // reinterpret_cast forbids bypass const
  // you can use const_cast to bypass const only when you know when real variable is not const ( only to pointer or reference )
  // it is better to not use reinterpret_cast and const_cast
  
  const int c = 5; 
  
  int& cc = const_cast<int&>(c); // undefined behavior, because you are trying to bypass const 
  
  cc++;
  std::cout << c << std::endl;
  
  /*
    C style cast ( do not use it )
    C style cast:
      try const_cast,
      if it is compilation error, then try static_cast,
      if it is compilation error, then try static_cast with const_cast,
      if it is compilation error, then try reinterpret_cast,
      if it is compilation error, then try reinterpret_cast with const_cast
  */
  
  // dynamic_cast
  
  // 1.cpp -> preprocessing -> 1.cpp -> compilation -> 1.asm -> assembler -> 1.o ( object file with CPU instructions ) -> linking -> a.out
  // in 1.o some functions can be undefined, linker substitutes function definitions where they are called
  /*
    #inlclude ( <> search in stdndard directories, "" search in current or specified directory )
    #if
    #pragma ( to add or remove particular warning, or to turn on optimizator )
    
  */
  
  // g++ -v; gcc is a conveyor
  // cc1plus = c++ compiler
  // collect2 = linker wrapper
  
  // g++ -E 1.cpp > out.cpp; -E = only preprocessing ( try it with using namespace std; )
  // g++ -S 1.cpp = preprocessing + compilation
  // -c to get object file
  // hd 1.o = hexdump
  // .cpp, .s = assembler, .o = object file
  
  // try to compile programs with undefined behavior on godbolt.org
  
  /*
    g++ -fsanitize=address -g
    g++ will add a lot of checks on memory read/write operations and if program crash in runtime, you will get a detailed message about an error
    -g to see code line number
    with sanitizers your code will slow down by 5-10 times
    -fsanitize=leak
    -fsanitize=undefined
  */
  
}