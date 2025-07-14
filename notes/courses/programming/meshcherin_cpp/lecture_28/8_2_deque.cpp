#include <iostream>
#include <deque>
#include <vector>
#include <cstdint>


int main()
{
	
	std::vector<uint8_t> test_vector_1(10);
	
	uint8_t*ptr_1 = &test_vector_1[5];
	
	std::cout << test_vector_1.size() << " " << test_vector_1.capacity() << " " << test_vector_1[11] << std::endl; 
	
	test_vector_1.push_back(1); // pointer invalidation, because vector most probably reallocated (cap -> 20)
	
	std::cout << test_vector_1.size() << " " << test_vector_1.capacity() << " " << test_vector_1[11] << std::endl; 
	
	// now p points to freed memory 
	std::cout << *ptr_1;
	
	
	std::vector<uint8_t> test_vector_2(10);
	
	uint8_t& ptr_2 = &test_vector_2[5];
	
	test_vector_2.push_back(1); // reference invalidation, because vector most probably reallocated (cap -> 20)
	
	// now reference  points to freed memory ( because ref will be implemented as pointer )
	std::cout << *ptr_2;
	
	// vector invalidates references and pointers after it was changed ( pop_back() does not invalidate, except the element you poped )
	// shrink_to_fit also  invalides because of reallocation ( not every OS supports function (free only part of memory (unused memory to shrink_to_fit)) )
	
	
	
	//  deque hasn't got this property of invalidation of pointers and reference ( this is why deque is used in adapters like stack, priority_queue, ... )
	
	// it is easy to implement deque as cyclic array, but it will invalidates pointers
	// ( extend array in both sides in case of reallocation  )
	
	// stack, queue, priority_queue - adapters to containers?  by default to deque, can be to vector, to your container 

	// stack - template< typename T, typename: std::deque<T> > why? это typename, а не template, т.е. это фиксированный тип, мы не передаем вторым параметром шаблон, у контейнера может быть больше одного шаблонного параметра, и мы изначально не знаем, со сколькими шаб параметрами мы имеем дело (готовый контейнер а не конкретный тип)
	
	// there is formal definition of container
	
	// куча на массиве -  priority_queue
	
	// stack has two methods: void pop() and T top() to avoid unnesessary copy if you want only do pop ( because popped element no longer exist, so we can't return reference (dandling reference?) )
	
	// iterators = generalized indexation
	
	
	
	return 0;
}