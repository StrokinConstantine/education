#include <iostream>

/**
 * Friend Access Rules:
 * 
 * - Friend classes/functions can access private members
 * - Friendship is neither symmetric nor transitive:
 *   * If A declares B as friend, B does not automatically
 *     grant access to A (not symmetric)
 *   * If A friends B and B friends C, A does not grant
 *     access to C (not transitive)
 * 
 * Note: Overuse of 'friend' breaks encapsulation and
 *       should generally be avoided in good design.
 */
 
 int main()
 {
	 return 0;
 }