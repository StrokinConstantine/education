#include <cstdint>
#include <iostream>

struct song
{
	uint_least16_t id = ( std::cout << "Object address: " << this << ". Default initialization of 'id' field is done." << std::endl, 10 );
	std::string name = ( std::cout << "Object address: " << this << ". Default initialization of 'name' field is done." << std::endl, "The Shroud" );
	
	explicit song() : id(20) // If you initialize fields like that, default initialization statement will not be computed
	{
		id = 30; // Never initialize fields like that, it is not even initilization, it is just an assignment after initialization
		std::cout << "Object address: " << this << ". Default constructor body executed." << std::endl;
	}
	
	explicit song( uint_least16_t id_param ) :	
		id( ( std::cout << "Object address: " << this << ". Initialization of 'id' field in the constructor with one parameter is done." << std::endl, id_param ) )
	{
		std::cout << "Object address: " << this << ". The constructor with one parameter body executed." << std::endl;
	}
	
	explicit song( uint_least16_t id_param, std::string name_param )  :
		id( ( std::cout << "Object address: " << this << ". Initialization of 'id' field in the constructor with two parameters is done." << std::endl, id_param ) ), 
		name( ( std::cout << "Object address: " << this << ". Initialization of 'name' field in the constructor with two parameters is done." << std::endl, name_param ) )
	{
		std::cout << "Object address: " << this << ".  The constructor with two parameters body executed." << std::endl;
	}
	
	song( const song& song_param ) : 
		id( ( std::cout << "Object address: " << this << ". Initialization of 'id' field in the copy constructor is done." << std::endl, song_param.id ) ), 
		name( ( std::cout << "Object address: " << this << ". Initialization of 'name' field in the copy constructor is done." << std::endl, song_param.name ) )
	{
		std::cout << "Object address: " << this << ".  The copy constructor body executed." << std::endl;
	}
	
	song& operator=( const song& song_param ) // You cannot initialize fields here, it is not a constructor
	{
		if ( this != &song_param ) // Protect against self-assignment
		{  
			id = song_param.id;
			name = song_param.name;
		}
		std::cout << "Object address: " << this << ".  The operator= body executed." << std::endl;
		return *this;
	}
	
	~song() = default;
	
};

void handle_song( song song_param ) // Copy constructor call
{
	
}

int main()
{
	
	song the_end = song(); // Okay,
	
	// Call of the constructor with two parameters
	struct song cave_song{ 1, "Cave Song" }; // Aggregate initialization, but if there is at least one constructor, this is not aggregate initialization, it is constructor call
	class song addiction( 2, "Addiction" ); // Direct initialization
	const song piano_fire = song( 3, "Piano Fire" ); // Direct initialization
	song* santa_monica_dream = new song{ 4, "Santa Monica Dream" }; // Aggregate initialization (C style)
	delete santa_monica_dream;
	
	// There is also value initialization ('explicit' prevents it)

	song keine_liebe = cave_song; // Copy constructor call
	addiction = piano_fire; // The operator= call
	cave_song = cave_song; // The operator= call
	
	handle_song( addiction );
	
	song do_re_mi( 2, "Do Re Mi" );
	// do_re_mi.song(); // error: invalid use of ‘song::song’
	do_re_mi.~song(); // UB
	
	song wicked_game;
	
	
	return 0;
}