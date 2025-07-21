#include <iostream>

/**
 * CLASS TEMPLATE SPECIALIZATION DEMONSTRATION
 * ===========================================
 * 
 * Shows various specialization patterns for class templates:
 * - Full specialization
 * - Partial specialization
 * - Type transformation specializations
 */

//------------------------------------------------------------------
// PRIMARY TEMPLATE AND SPECIALIZATIONS FOR STRUCT S
//------------------------------------------------------------------

// Base template with two type parameters
template <typename T, typename U>
struct S { S(){ std::cout << "T, U\n"; } };

/**
 * Partial specialization for identical types (W, W)
 * @tparam W Type used for both template parameters
 * @note This is more specialized than the base template
 */
template <typename W>
struct S<W, W> { S(){ std::cout << "W, W\n"; } };

/**
 * Partial specialization when first parameter is int
 * @tparam W Type of second parameter
 */
template <typename W>
struct S<int, W> { S(){ std::cout << "int, W\n"; } };

/**
 * Partial specialization when second parameter is int
 * @tparam W Type of first parameter
 */
template <typename W>
struct S<W, int> { S(){ std::cout << "W, int\n"; } };

/**
 * Full specialization for <int, int>
 * @note Causes ambiguity with S<W,W> and S<int,W>/S<W,int>
 */
template <>
struct S<int, int> { S(){ std::cout << "int, int\n"; } };

//------------------------------------------------------------------
// TYPE TRANSFORMATION SPECIALIZATIONS (STRUCT SS)
//------------------------------------------------------------------

// Base template
template <typename T>
struct SS {};

/**
 * Specialization for references (deleted constructor)
 * @note "reference > const" in specialization matching
 */
template <typename T>
struct SS<T&> { SS() = delete; };

/**
 * Specialization for const-qualified types
 * @note Matches const T before base template
 */
template <typename T>
struct SS<const T> { SS(){ std::cout << "const T\n"; } };

/**
 * Specialization for pointer types
 * @note "pointer > const" in specialization matching
 * @note For SS<int* const>, T is int* (top-level const is ignored)
 */
template <typename T>
struct SS<T*> { SS(){ std::cout << "T*\n"; } };

//------------------------------------------------------------------
// FUNCTION TEMPLATE RULES
//------------------------------------------------------------------

/**
 * Key Differences from Class Templates:
 * - Function templates cannot be partially specialized
 * - Overloading is used instead of partial specialization
 * - Full specializations are allowed but behave differently
 * - Specialization matching follows "closest from top" rule
 */

// Base template with two type parameters
template <typename T, typename U>
void f(T, U) { std::cout << "f T U\n"; }

// Overload (not specialization!) for same types
template <typename T>
void f(T, T) { std::cout << "f T T\n"; }

// Full specialization of f(T, U) for <int, int>
template <>
void f(int, int) { std::cout << "f int int\n"; }

// Full specialization of f(T, T) for <int, int>
template <>
void f(int, int) { std::cout << "f int int\n"; }

//------------------------------------------------------------------
// FUNCTION TEMPLATE OVERLOAD RESOLUTION DEMO
//------------------------------------------------------------------

/**
 * Demonstration of "closest from top" specialization rule:
 * - Specializations are matched against the nearest compatible template above them
 * - This is an implementation detail rather than a formal C++ rule
 */

// Base template
template <typename T, typename U>
void h(T, U) { std::cout << "h T U\n"; }

/**
 * Specialization for h(int, int)
 * @note Matches h(T, U) because it's the closest compatible template above
 */
template <>
void h(int, int) { std::cout << "h int int\n"; }

// Overload for identical types
template <typename T>
void h(T, T) { std::cout << "h T T\n"; }

/**
 * Specialization for h(int, double)
 * @note Matches h(T, U) template
 */
template <>
void h(int, double) { std::cout << "h int double\n"; }

// Non-template function overload
void h(int, int) { std::cout << "non-template h int int\n"; }

//------------------------------------------------------------------
// USAGE EXAMPLES
//------------------------------------------------------------------

int main() {
    // Function template tests
    h(1,1);         // Calls non-template h(int,int)
    h(1.0,1.0);     // Calls h(T,T)
    h(1.0,1.0f);    // Calls h(T,U)
    f(1,1);         // Depends on declaration order
    
    // Class template tests
    S<float,double> a1;  // T,U
    S<float,float> a2;   // W,W
    S<int,float> a4;     // int,W
    S<int,int> a3;       // int,int (ambiguous without full specialization)
    
    // Type transformation tests
    SS<const int*> a5;   // T* with T=const int, pointer > const 
    SS<int* const> a6;   // T* with T=int (top-level const ignored)
    // SS<const int&> a7; // T& with T=const int, reference > const
}

