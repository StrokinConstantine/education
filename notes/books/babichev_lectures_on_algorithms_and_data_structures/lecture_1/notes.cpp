/*
	algorithm efficiency := ability of the algorithm to use limited amount of resources
	for algorithms without loops descriptive compexity roughly correlates with computational complexity
	the main parameter N := the parameter that most strongly influencing the speed of execution of the algorithm ( size of an input array, string size, ...)
	if there is several parameters, we will try to make a function out of them that defines a one generalized parameter
	theta( f(n) ) := set of functions that grows at the same rate as f(n)
	if algorithm complexity is theta( N^2 ), then for large N algorithm compexity is just a function c*N^2 ( c - constant amortization coefficient  )
	O( f(n) ) := set of funcitons that bounded by c*f(n)
	
	1 < log(x) < x^n < exp(x)
*/