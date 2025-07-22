#include <iostream>
#include <vector>
#include <set>
#include <iterator>

/*
 * Iterator Categories Hierarchy:
 * 
 * 1. Input Iterator (minimal)
 *    - Supports: *, ++, == (may be single-pass)
 *    - Examples: istream_iterator, single-pass algorithms
 *    - Key limitation: Can't revisit elements
 * 
 * 2. Forward Iterator
 *    = Input Iterator + multi-pass guarantee
 *    - Examples: forward_list, unordered containers
 *    - Can traverse same sequence multiple times
 * 
 * 3. Bidirectional Iterator
 *    = Forward Iterator + --
 *    - Examples: list, set/map
 *    - Can traverse backwards
 * 
 * 4. Random Access Iterator
 *    = Bidirectional Iterator + full arithmetic
 *    - Supports: +, -, +=, -=, <, >, <=, >=
 *    - Examples: vector, deque, array
 *    - Note: deque is random access but not contiguous
 * 
 * 5. Contiguous Iterator (C++17)
 *    = Random Access + memory adjacency
 *    - Guarantees: &*(it + n) == &*it + n
 *    - Examples: vector, array, raw pointers
 * 
 * Key Points:
 * - All standard containers provide iterators
 * - Range-based for uses begin()/end()
 * - Iterator traits available via iterator_traits
 * - Contiguous iterators enable low-level optimizations
 */






template <typename input_iterator>
void find_most_often_number( input_iterator begin, input_iterator end ) // > size/2
{
	auto x = *begin; // not always correct, because it not always the type of elements of the contaner (Bit_reference for vector<bool> )
	
	// iterator traits - знают много чего про iterator, value_type, pointer, reference, iterator_category - категория это пустая структура (тег), нужно только чтобы проверять на равенство их с другими типами и всё
	
	//  typename because it depended name, по умолчанию будет считатся переенной?
	
	// 
	
	typename std::iterator_traits<input_iterator>::value_type y = *begin; // correct
	
}

template <typename T>
void f(T) = delete; 



int main()
{
	
	std::vector<bool> vb(10);


	std::set<int> s;
	
	// auto - since C++11
	
	for ( int x : s ) // since C++11
	{
		
	}
	// syntax sugar for:
	for( std::set<int>::iterator  it = s.begin()  ; it != s.end(); ++it ) // until C++11
	{
		*it;
	}
	
	// alogoritms над последовательностями классифицируется не только по сложности, но и по требованиям на итератор
	
	// std::next_permutation - bidirectional_iterator
	// bubble_sort - forward_iterator
	//std::stable_sort - random_access_iterator
		// std::copy - input_iterator, output_iterator( we can write )
	
	// forward_iterator гарантирует что мы может ходить по последовательности больше одного раза ( требуется умение перейти на следующий элемент, но всё еще смотреть на предыдущий ),  input_iterator так не умеет, у него даже нет постфиксного интератора, ( есть у forward_iterator )
		// input_iterator = один проход последовательности




	// we know that in sequence every number встречается two times, except one number which встречается one time, effective solution - XOR of entire sequence! - input_iterator


	// number that встречается более чем половину раз ( > size/2 ), решить задачу с input_iterator это более строгое условие на алгоритм
 	// решение - аналогия с танцами, очередной человек, если находит пару с отличающимся от него человеком, то он идёт в пару 
	// мы помним 2 числа - число и количество раз которое он встретилось
	// если очередное совпадает, то увеличиваем счетчик, иначе одно из своих чисел отдаём в пару и уменьшаем счетчик, в конце гарантированно останется одно наше число

	// input_iterator <-> однопроходные алгоритмы
	
	// std::lower_bound , bin search - needs only forward_iterator, why? ()
	
	/*
	std::lower_bound
		почему bin search в stl, требует forward_iterator, а не random_access_iterator
		
		подвох: бин поиск работает за log время, но оно log относительно операций над T по стандарту
		на самом деле про бин поиск сказано: он делает log количество сравнений, а сдвиги итератора не учитываются
		
		представьте, что вы делаете  bin search в массиве из очень длинных строк
		сравнение строк очень дорого, поэтому разумно сделать бин поиск на forward_iterator-е, сэкономив на количестве сравнений, так как инкремент итератора дешевый
		А если iterator random access, то алгоритм понимает и делает +=
		
		D std::deque::push_back работает за Constant (not amortized constant) why? 
		Сложность оценивается относительно операций над T, а операции над сырой патятью и pointers не учитывается, т.к. непонятно какая у них сложность
		
		 exception safety = reallocate everything backwards if excpetion is thrown
	
	*/
	return 0;
}