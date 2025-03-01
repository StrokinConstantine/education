#include <iostream>



int64_t polynomial_evaluation( int64_t* coefficients, size_t N, int64_t argument, size_t MOD )
{
	int64_t result = coefficients[0];
	
	for ( size_t i = 1; i <= N; ++i )
	{
		result = ( argument * result + coefficients[i] ) % MOD;
	}
	
	
	
	return result;
}



int main()
{
	int32_t N;
	int32_t M;
	size_t MOD;
	
	std::cin >> N;
	std::cin >> M;
	std::cin >> MOD;
	
	int64_t* coefficients = new int64_t[N + 1];
	
	int64_t* arguments = new int64_t[M];
	
	
	for ( size_t i = 0; i <= N; ++i )
	{
		std::cin >> coefficients[i];
	}
	
	for ( size_t i = 0; i < M; ++i )
	{
		std::cin >> arguments[i];
	}
	
	
	for ( size_t i = 0; i < M; ++i )
	{
		std::cout << polynomial_evaluation( coefficients, N, arguments[i], MOD ) << "\n"; ;
	}
	
	
	
	delete[] coefficients;
	delete[] arguments;
	
	return 0;
}