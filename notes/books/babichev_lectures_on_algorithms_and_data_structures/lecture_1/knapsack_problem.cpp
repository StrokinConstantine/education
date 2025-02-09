#include <iostream>
#include <cassert>

// O( n*2^n )
int32_t knapsack_problem_brute_force( int32_t* v, int32_t* c, size_t size, int32_t v_max )
{
	size_t i_max = (1 << size); // 2^n
	int32_t c_sum_max = 0;
	
	// for now we do not check trivial cases
	
	// iterate through all subsets of the array ( v and c )
	// loop invariant: c_sum_max contain maximum sum of the array c[0], ..., c[i - 1]
	for ( size_t i = 0; i < i_max; ++i )
	{
		int32_t v_sum = 0;
		int32_t c_sum = 0;
		
		for ( size_t j = 0; j < size; ++j )
		{
			int32_t is_element_contained_in_the_current_iteration_subset = ( ( (1 << j) & i ) != 0 ) ? 1 : 0; 
			v_sum += v[ j ] * is_element_contained_in_the_current_iteration_subset;
			c_sum += c[ j ] * is_element_contained_in_the_current_iteration_subset;
		}

		if ( ( v_sum <= v_max ) && ( c_sum > c_sum_max ) )
			c_sum_max = c_sum;
	}
	
	return c_sum_max;
}

int main()
{
	
	const size_t n_1 = 5;
	int32_t v_max_1 = 100;
	int32_t* v_1 = new int[n_1];
	int32_t* c_1 = new int[n_1];

	v_1[0] = 20;
	v_1[1] = 30;
	v_1[2] = 50;
	v_1[3] = 60;
	v_1[4] = 70;
	
	c_1[0] = 2;
	c_1[1] = 4;
	c_1[2] = 4;
	c_1[3] = 6;
	c_1[4] = 8;
	
	const size_t n_2 = 10;
	
	int32_t v_max_2 = 20;
	int32_t v_2[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int32_t c_2[10] = { 11, 22, 33, 45, 64, 74, 32, 27, 41, 101};
	
	
	assert( knapsack_problem_brute_force( v_1, c_1, n_1, v_max_1 ) == 12 );
	assert( knapsack_problem_brute_force( v_2, c_2, n_2, v_max_2 ) == 238 );
	
	delete[] v_1;
	delete[] c_1;
	
}