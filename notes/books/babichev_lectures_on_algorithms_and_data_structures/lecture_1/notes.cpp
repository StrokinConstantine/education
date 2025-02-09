/*
	algorithm efficiency := ability of the algorithm to use limited amount of resources
	for algorithms without loops descriptive compexity roughly correlates with computational complexity
	the main parameter N := the parameter that most strongly influencing the speed of execution of the algorithm ( size of an input array, string size, ...)
	if there is several parameters, we will try to make a function out of them that defines a one generalized parameter
	theta( f(n) ) := set of functions that grows at the same rate as f(n)
	if algorithm complexity is theta( N^2 ), then for large N algorithm compexity is just a function c*N^2 ( c - constant amortization coefficient  )
	O( f(n) ) := set of funcitons that bounded by c*f(n)
	1 < log(x) < x^n < exp(x)
	NP ( has no solution with polynomial time )
	Python primitive types do not map explicitly to hardware data types ( as in C++ ), this is handled by another layer - Python interpreter 
	in C++ addition of two integers is often translated into one or two operations by the hardware executor, in Python this may require hundreds of operations
	+ and - are faster than * and /
	<< and >> are faster than * and /
	t = x > 0 is faster that if ( x > 0 ) t = 1; else t = 0;
	if the value of the function f on the sequence x1, ..., xn can be restored from its value on the sequence x1, ..., xn-1 and the element xn, then function f is called inductive
	max(a1, ..., an) is inductive, because max(a1, ..., an) = max( max(a1, ..., an-1), an )
	invariant = constant predicate
	invariants play a crucial role in proving the correctness of algorithms
	automaton := a set of pairs consisting of states and transitions, there is an initial state and final state
	a finite automaton has finite sets of states and transitions
	the input of the automaton is the events that trigger transitions
	a deterministic finite automaton is a finite automaton in which the same sequence of input data leads to the same final state from the same initial state
	functional abstraction := is the separation of functions and methods from thier implementation
	
*/

class sequence
{
public:
	// virtual sequence create_sequence() const = 0;
	// virtual void delete_sequence() const = 0;
	virtual int32_t get_current_element() const = 0;
	virtual void add_element() = 0;
	virtual ~sequence() {}
};

class array
{  
	
}