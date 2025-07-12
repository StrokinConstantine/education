#include <iostream>

// using namespase std; // do not do this, because names can overlap

int main()
{
	{
		int x;
		
		std::cin >> x;
		std::cout << x + 5;
	}
	return 0; // since C++11 compiler will add "return 0;" at the end of main ( 0 returns to bash )
}