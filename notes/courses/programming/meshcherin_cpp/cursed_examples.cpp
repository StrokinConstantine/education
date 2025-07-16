#include <iostream>

class dog
{

private:

	std::string name = "Yura";
	
	friend void h ( dog my_dog ) // Definition of friend function right in the place
	{
		my_dog.name;
	}
	
};


int main()
{
	
	
	return 0;
}