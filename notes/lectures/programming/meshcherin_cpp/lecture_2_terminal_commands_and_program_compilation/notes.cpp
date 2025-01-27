/*
For every literal hardcoded its type

5; // int
0.2; // double
"abc"; // const char*
'a'; // char

Literal suffixes:

	5u; // unsigned int
	
	overflow of int -> UB
	
	overflow of unsigned int -> OKAY
	
	0.2f; // float
	
	
	int x = 5u; // dangerous implicit conversion
	
	// (integer)/(floating point) promotions is ok
	
	int y = 4.9; // y = 4
	
	int + uint is uint
	
	0 - 1u = ?
	
	v.size() - 10 ?
	
	(double) 5; // ok
	
	0x10 = 16
	010 = 8
	0b10 = 2
	
	since C++14 1'000'000
	
	
	
	cd change directory
	pwd print working directory
	
	TAB
	
	cd ../../..
	cd -
	pushd
	popd
	
	mnemonics:
		..
		~
		.
		/
		
	
*/



