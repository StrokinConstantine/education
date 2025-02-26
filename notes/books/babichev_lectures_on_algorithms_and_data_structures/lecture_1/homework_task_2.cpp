#include <iostream>
#include <cstdint>
#include <set>




int count_common_elements_in_two_arrays(const std::vector<int>& array1, const std::vector<int>& array2) {  
    int i = 0, j = 0;  
    int count = 0;  

    while (i < array1.size() && j < array2.size()) {  
        if (array1[i] == array2[j]) {  
            count++; // Считаем общий элемент  
            i++;  
            j++;  
        } else if (array1[i] < array2[j]) {  
            i++; // Перемещаем указатель массива 1  
        } else {  
            j++; // Перемещаем указатель массива 2  
        }  
    }  

    return count;  
}





int main()
{
	size_t array_1_size;
	size_t array_2_size;
	
	std::cin >> array_1_size;
	std::cin >> array_2_size;
	
	uint64_t* array_1 = new uint64_t[array_1_size];
	uint64_t* array_2 = new uint64_t[array_2_size];
	
	for( size_t i = 0; i < array_1_size; ++i )
		std::cin >> array_1[i]; 
	for( size_t i = 0; i < array_2_size; ++i )
		std::cin >> array_2[i];
	
	std::set<uint64_t> set;
	
	for( size_t i = 0; i < array_1_size; ++i )
		set.insert( array_1[i] );

	for( size_t i = 0; i < array_1_size; ++i )
	{
		size_t size_before_insertion = set.size();
		set.insert( array_2[i] );
		size_t size_before_insertion = set.size();
	}
	delete[] array_1;
	delete[] array_2;
	
}