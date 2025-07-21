#include <iostream>
#include <map>
#include <concepts> // C++20 concepts

/**
 * TEMPLATES: CODE GENERATION PATTERNS
 * ==================================
 *
 * Analogous to the transition from propositional logic to first-order logic:
 * - Non-template code: Fixed types (propositional)
 * - Template code: Type-quantified patterns (first-order)
 *
 * Key Properties:
 * - Templates are blueprints, not code themselves
 * - Compiler generates concrete implementations when instantiated
 * - Each instantiation creates a distinct function/class
 *
 * TERMINOLOGY
 * -----------
 * - T is called a META-PARAMETER (type parameter)
 * - typename/class introduces type variables in template declarations
 * - Instantiation: Process of generating concrete code from templates
 *
 * COMPILATION PIPELINE
 * -------------------
 * 1. TEMPLATE CODE GENERATION PHASE:
 *    - Compiler identifies all needed instantiations
 *    - Determines for which types to generate implementations
 *
 * 2. TEMPLATE OVERLOAD RESOLUTION:
 *    - Choosesthe best matching template pattern
 *    - May decide template isn't needed if non-template matches better
 *
 * 3. TEMPLATE INSTANTIATION:
 *    - Generates concrete implementations for each required type
 *    - Creates actual function/class definitions
 *
 * 4. FINAL OVERLOAD RESOLUTION:
 *    - Between generated template instantiations and regular functions
 *    - Performs argument deduction and conversion ranking
 *
 * Example Pipeline:
 * swap(a,b) -> [Find swap templates] -> [Deduce T] -> 
 * [Generate swap<int>] -> [Compare with other overloads]
 *
 * ESSENTIAL CHARACTERISTICS
 * ------------------------
 * - Templates = compile-time polymorphism
 * - Meta-parameters enable type abstraction
 * - Zero runtime overhead (all work done at compile-time)
 */

// template <class T> and template <typename T> are 100% equivalent in C++.



/**
 * Generic Swap Function
 * 
 * @tparam T Any copyable type
 * @note For strings/containers, prefer std::swap (O(1) move semantics)
 * @complexity O(3*sizeof(T)) - three copies
 */
template <typename T>
void swap(T& x, T& y) {
    T t = x;
    x = y;
    y = t;
}

// Comparison Functors ==================================

/**
 * Less-than Comparator
 * 
 * @tparam T Type with operator< defined
 * @note Standard ordering for containers
 */
template <typename T>
struct less {
    bool operator()(const T& x, const T& y) const {
        return x < y;
    }
};

/**
 * Greater-than Comparator
 * 
 * @tparam T Type with operator> defined
 * @note Reverse ordering for containers
 */
template <typename T>
struct greater {
    bool operator()(const T& x, const T& y) const {
        return x > y;
    }
};

// Template Aliases =====================================

/**
 * Custom Map Type with Greater Comparator
 * 
 * @tparam T Key and value type (must support operator>)
 * @since C++11
 */
template <typename T>
using mymap = std::map<T, T, std::greater<T>>;

mymap<int> m; // Map with int keys/values, reverse sorted

// Modern Template Features =============================

/**
 * Compile-time Constant
 * 
 * @tparam T Any arithmetic type
 * @since C++14
 */
template<typename T>
constexpr T pi = T(3.1415926535897932385L);

/**
 * Concept-Constrained Template
 * 
 * @tparam T Must be arithmetic type
 * @since C++20
 */
template<std::floating_point T>
T circle_area(T radius) {
    return pi<T> * radius * radius;
}

int main() {

    // C++20 Concept Example
    float area = circle_area(2.0f);
    // double area2 = circle_area("2.0"); // Error: doesn't satisfy floating_point

    // Template Variable Usage
    std::cout << "Float Pi: " << pi<float> << "\n";
    std::cout << "Double Pi: " << pi<double> << "\n";
}