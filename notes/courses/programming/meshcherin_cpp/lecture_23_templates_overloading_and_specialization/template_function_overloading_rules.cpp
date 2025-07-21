/**
 * TEMPLATE FUNCTION OVERLOADING RULES & COMPILATION PIPELINE
 * =========================================================
 *
 * OVERLOAD RESOLUTION PRIORITIES:
 * 1. Exact non-template match > Template specialization
 *    Example: f(int) wins over f(T) when passing int
 *
 * 2. Exact template match > Conversion-requiring match
 *    Example: f<long>(long) wins over f(int) when passing long
 *    ("Exact match beats any conversion")
 *
 * 3. More specialized template > Less specialized template
 *    Example: const T& is more specialized than T
 *
 * 4. Non-const reference > Const reference for non-const arguments
 *    Example: f(T&) wins over f(const T&) for non-const lvalues
 *
 * COMPILATION PIPELINE:
 * 1. TEMPLATE RESOLUTION PHASE:
 *    - Find all potential overload candidates (templates + non-templates)
 *    - Perform template argument deduction where applicable
 *
 * 2. TEMPLATE INSTANTIATION:
 *    - Generate concrete function implementations
 *    - Only instantiates templates that are actually needed
 *
 * 3. OVERLOAD RESOLUTION:
 *    - Compare all viable candidates (instantiated templates + regular functions)
 *    - Apply priority rules to select best match
 *
 * 4. FUNCTION SELECTION:
 *    - Finalize the chosen function
 *    - Check access permissions (public/private)
 *    - Verify const-correctness
 *
 * KEY NOTES:
 * - Templates are not functions - they're blueprints for code generation
 * - SFINAE (Substitution Failure Is Not An Error) occurs during phase 1
 * - Access checking happens LAST (after overload resolution)
 */

#include <iostream>

int main()
{
    return 0;
}