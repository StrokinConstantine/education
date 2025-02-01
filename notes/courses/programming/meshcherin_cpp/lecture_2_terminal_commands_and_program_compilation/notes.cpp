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
	
	ctrl + w remove word
	ctrl + u remove line

	cd ../../..
	cd -
	pushd
	popd
	
	mnemonics:
		.. - parent directory
		~ - home directory
		. - current directory
		/ - root directory
		
	ls list ( show files in current directory )
	ls -l 
	
	
	
	drwxrwxrwx 1 root root 4096 datetime:
		* d - file type ( d = directory, - = file, l = link )
		* first rwx - owner rights ( for directories x means that you can open directory, for files x means loading to RAM and execution )
		* second rwx - owner group rights
		* third rwx - other users rights
		* 1 - number of hard links to this file
		
	cat - file to output stream
	vim, nano - text editors
	
	vim:
		i - 
		:!q
	.vimrc - vim configuration file

	g++
	C++ version != g++ version != stdlib version
	
	g++ -o b.out file.cpp
	chmod -x a.out
	chown
	
	./a.out
	a.out - you can execute a.out like that only if you are in standard directory with binaries
	
	echo $PATH
	
*/



