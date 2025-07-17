/**
 * Demonstration of:
 * - mutable members
 * - static members
 * - const member functions
 * - reference members in const contexts
 */
 
struct C2 {
    /**
     * MUTABLE MEMBERS:
     * Used when an object is logically constant (from the user's perspective)
     * but needs to modify internal state (e.g., caching, splay tree rotations)
     * 
     * mutable overrides const qualification for this specific member
     */
    mutable int x = 2;  // Can be modified even in const member functions
    int& ref = x;       // Reference to mutable member

    /**
     * STATIC MEMBERS:
     * Exist once per class (not per instance)
     * Stored in static memory with two initialization phases:
     * 1. Compile-time initialized (in .data/.rodata sections)
     * 2. Runtime initialized (zero-initialized in .bss)
     */
    static int X;        // Declaration only (must be defined outside)
    static const int yyy = 5;  // Allowed: const static with compile-time value

    /**
     * CONST MEMBER FUNCTIONS:
     * Can be called on const objects
     * Treats all members as const EXCEPT:
     * - mutable members
     * - References (the reference itself becomes const, not the referred data)
     */
    void f1(int y) const {  // Compiler makes members "const" except special cases
        ++ref;    // Allowed: modifying through reference (not the reference itself)
        ref = y;  // Allowed: reference points to mutable 'x'
    }

    /**
     * STATIC MEMBER FUNCTIONS:
     * - No 'this' pointer
     * - Can only access static members
     * - Stored in .text section (code segment)
     */
    static void f2() {
        std::cout << "abc" << std::endl;
    }
};

// Static member definition (required)
int C2::X = 2;  // Allocated in static storage

/*
 * USAGE EXAMPLES:
 * 
 * const C2 c2 = C2();  // Const object
 * C2 c3 = C2();        // Non-const object
 * 
 * c2.f1(2);    // Legal: modifies mutable 'x' through reference
 *              // Not UB because 'x' is explicitly marked mutable
 * 
 * C2::f2();    // Static member call
 */