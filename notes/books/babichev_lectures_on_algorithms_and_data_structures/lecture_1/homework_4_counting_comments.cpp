#include <iostream>
#include <cstdint>

enum class state : int_fast8_t
{
	OUTSIDE_COMMENT = 0,
	
	INSIDE_COMMENT_OF_TYPE_1,
	READING_THE_BEGINNING_OF_COMMENT_OF_TYPE_1,
	READING_THE_ENDING_OF_COMMENT_OF_TYPE_1,
	
	INSIDE_COMMENT_OF_TYPE_2 ,
	
	INSIDE_COMMENT_OF_TYPE_3,
	READING_THE_BEGINNING_OF_COMMENT_OF_TYPE_3,
	
	INSIDE_COMMENT_OF_TYPE_4
};

std::string toString(state st) {  
    switch (st) {  
        case state::OUTSIDE_COMMENT:  return "OUTSIDE_COMMENT";  
        case state::INSIDE_COMMENT_OF_TYPE_1: return "INSIDE_COMMENT_OF_TYPE_1";  
        case state::READING_THE_BEGINNING_OF_COMMENT_OF_TYPE_1: return "READING_THE_BEGINNING_OF_COMMENT_OF_TYPE_1";  
        case state::READING_THE_ENDING_OF_COMMENT_OF_TYPE_1: return "READING_THE_ENDING_OF_COMMENT_OF_TYPE_1";  
        case state::INSIDE_COMMENT_OF_TYPE_2:  return "INSIDE_COMMENT_OF_TYPE_2";  
        case state::INSIDE_COMMENT_OF_TYPE_3: return "INSIDE_COMMENT_OF_TYPE_3";  
        case state::READING_THE_BEGINNING_OF_COMMENT_OF_TYPE_3: return "READING_THE_BEGINNING_OF_COMMENT_OF_TYPE_3";  
        case state::INSIDE_COMMENT_OF_TYPE_4: return "INSIDE_COMMENT_OF_TYPE_4";  
        default:           return "Unknown";  
    }  
}  


int main()
{
	
	std::string line;
	std::string text;
	
	enum state current_state = state::OUTSIDE_COMMENT;
	
	while ( std::getline(std::cin, line) )
	{
		if ( line.empty() )
			break;
		
		text += line;
		text += "\n";
	}
	
	uint_fast32_t count_of_comments_of_type_1 = 0u;
	uint_fast32_t count_of_comments_of_type_2 = 0u;
	uint_fast32_t count_of_comments_of_type_3 = 0u;
	uint_fast32_t count_of_comments_of_type_4 = 0u;
	
	std::cout << "TEXT:" << text;
	
	for ( size_t i = 0; i < text.size(); ++i )
	{
		//std::cout << "i:" << text[i] << std::endl;
		
		std::cout << toString(current_state) <<  " " <<static_cast<int>(text[i]) <<  " " << text[i] << std::endl;
		
	
		
		if ( current_state == state::OUTSIDE_COMMENT )
		{
			if ( text[i] == '(' )
			{
				current_state = state::READING_THE_BEGINNING_OF_COMMENT_OF_TYPE_1;
			}
			else if ( text[i] == '{' )
			{
				current_state = state::INSIDE_COMMENT_OF_TYPE_2;
			}
			else if ( text[i] == '/' )
			{
				current_state = state::READING_THE_BEGINNING_OF_COMMENT_OF_TYPE_3;
			}
			else if ( text[i] == '\"' )
			{
				current_state = state::INSIDE_COMMENT_OF_TYPE_4;
			}
		}
		else if ( current_state == state::INSIDE_COMMENT_OF_TYPE_1 )
		{
			if ( text[i] == '*' )
			{
				current_state = state::READING_THE_ENDING_OF_COMMENT_OF_TYPE_1;
			}
			
		}
		else if ( current_state == state::READING_THE_BEGINNING_OF_COMMENT_OF_TYPE_1 )
		{
			if ( text[i] == '*' )
			{
				current_state = state::INSIDE_COMMENT_OF_TYPE_1;
			}
			else if ( text[i] == '\"' )
			{
				current_state = state::INSIDE_COMMENT_OF_TYPE_4;
			}
			else 
			{
				std::cout << text[i] << std::endl;
				current_state = state::OUTSIDE_COMMENT;
			}
		}
		else if ( current_state == state::READING_THE_ENDING_OF_COMMENT_OF_TYPE_1 )
		{
			if ( text[i] == ')' )
			{
				current_state = state::OUTSIDE_COMMENT;
				++count_of_comments_of_type_1;
			}
			else 
			{
				current_state = state::INSIDE_COMMENT_OF_TYPE_1;
			}
		}
		else if ( current_state == state::INSIDE_COMMENT_OF_TYPE_2 )
		{
			if ( text[i] == '}' )
			{
				current_state = state::OUTSIDE_COMMENT;
				++count_of_comments_of_type_2;
			}
		}
		else if ( current_state == state::INSIDE_COMMENT_OF_TYPE_3 )
		{
			if ( text[i] == '\n' )
			{
				current_state = state::OUTSIDE_COMMENT;
				++count_of_comments_of_type_3;
			}
		}
		else if ( current_state == state::READING_THE_BEGINNING_OF_COMMENT_OF_TYPE_3 )
		{
			if ( text[i] == '/' )
			{
				current_state = state::INSIDE_COMMENT_OF_TYPE_3;
			}
			else 
			{
				current_state = state::OUTSIDE_COMMENT;
			}
		}
		else if ( current_state == state::INSIDE_COMMENT_OF_TYPE_4 )
		{
			if ( text[i] == '\"' )
			{
				current_state = state::OUTSIDE_COMMENT;
				++count_of_comments_of_type_4;
			}
		}
		
	}
	

	
	std::cout << toString(current_state) <<  " " << std::endl;
	
	std::cout << count_of_comments_of_type_1 << ' '
		<< count_of_comments_of_type_2 << ' '
		<< count_of_comments_of_type_3 << ' '
		<< count_of_comments_of_type_4;

	return 0;
}