/**
 * Demonstrates default template arguments in:
 * 1. User-defined templates
 * 2. STL components
 * 
 * Key properties:
 * - Work similarly to function default arguments
 * - Must be rightmost parameters
 * - Can depend on previous template parameters
 */

#include <iostream>
#include <map>
#include <vector>
#include <functional>
#include <set>
#include <memory>

// Example 1: Basic default template argument
template <typename T = int>  // Default type
class box
{
    T value;
public:
    box(T v = T{}) : value(v) {}
    void print() { std::cout << value << "\n"; }
};

// Example 2: Multiple parameters with defaults
template <typename T = double, typename container = std::vector<T>>
class data_processor
{
    container data;
public:
    void add(T val) { data.push_back(val); }
    void show() {
        for (const auto& v : data) std::cout << v << " ";
        std::cout << "\n";
    }
};

// Example 3: Default non-type template argument
template <int n = 10>
void repeat_message(const char* msg)
{
    for (int i = 0; i < n; ++i) std::cout << msg << " ";
    std::cout << "\n";
}

int main() {
    // Using defaults
    box<> first_box;          // T = int
    box<double> second_box(3.14);
    first_box.print();        // 0 (default int)
    second_box.print();        // 3.14

    data_processor<> processor;  // T=double, container=vector<double>
    processor.add(1.1);
    processor.add(2.2);
    processor.show();    // 1.1 2.2

    repeat_message("Hi");  // Uses n=10

    // STL EXAMPLES ======================================

    // 1. std::map's default comparator
    std::map<int, std::string> first_map;  // Equivalent to:
    std::map<int, std::string, std::less<int>> second_map;

    // 2. std::function's default allocator
    std::function<void()> func;  // Uses default allocator

    // 3. std::vector's default allocator
    std::vector<int> vec;  // Uses std::allocator<int>

    // 4. std::less as default comparator
    std::set<int> set;  // std::less<int> by default

    // 5. std::shared_ptr's default deleter
    std::shared_ptr<int> ptr(new int(5));  // Uses std::default_delete<int>

    // ADVANCED EXAMPLE ==================================
    // Default template argument depending on previous parameter
    template <typename T, typename U = T*>
    class node {
        T value;
        U next;  // Defaults to pointer-to-T
    };
}

/**
 * KEY RULES:
 * 1. Defaults must be rightmost parameters
 *    template <typename T = int, typename U>  // Error
 * 
 * 2. Common STL defaults:
 *    - Containers: std::allocator<T>
 *    - Ordered containers: std::less<Key>
 *    - Smart pointers: std::default_delete<T>
 *    - std::function: default allocator
 * 
 * 3. Defaults can be overridden:
 *    std::map<int, string, std::greater<int>>  // Reverse order
 */