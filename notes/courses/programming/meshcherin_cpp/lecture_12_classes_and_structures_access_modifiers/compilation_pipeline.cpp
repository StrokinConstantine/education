#include <iostream>

/**
 * DEMONSTRATION OF OVERLOAD RESOLUTION AND ACCESS CONTROL
 * 
 * This example shows how C++ compilers:
 * 1. First perform overload resolution
 * 2. Then check access permissions
 * 3. Fail only if the best match is inaccessible
 */

class math
{
	
private:

    // Private overload - only accessible within class
    void f(int) { std::cout << "Private f(int) called\n"; }

public:

    // Public overloads - accessible anywhere
    void f(float) { std::cout << "Public f(float) called\n"; }
    void f(double) { std::cout << "Public f(double) called\n"; }

};

int main()
{
    math algebra;

    // CASE 1: Exact match with public member
    // algebra.f(1);    // Error: matches f(int) but it's private ( error: ‘void math::f(int)’ is private within this context )
    
    // CASE 2: Best match is private (compile error)
	algebra.f(1.0f);  // Calls f(float) - exact match, public access
    
    // CASE 3: Conversion to public member
    algebra.f(1.0);   // Calls f(double) - exact match, public access

    return 0;
}