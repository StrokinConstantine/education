/*

https://youtu.be/C-j-CjAKibs?si=pZbBxRbpip9cRA6e

java Main 3 2 1
3, 2, 1 are strings
java -jar Main.jar

import static java.lang.Math.*

final int MY_CONST = 0;

condition ? expr : expr;

x - int or enum.


switch( x )
{
	case 1: 
		expr_1;
		break;
		
	case 2, 3:
	default: expr;
	
}


switch( x )
{
	case 1 -> expr_1;
		
	case 2, 3 -> expr_2;
	default: expr;
	
}

var y = switch( x )
{
	case 1 -> 2;
		
	case 2, 3 -> { calc_result; yield result;};
	default: expr;
	
};

for (int i = 0, j = 0; i < 10 && j < 10; ++i, ++j)
{
	System.out.println("%d * %d = %d", i, j, i * j);
}


for ( def_variable : iterable ) expr;

break label;
continue label;

block of code creates scope of variables

long x;
{
int x; // ok	
}

VARARGS

public static void printMessage (String ...msg)
{
	for(String s: msg){
	}
}

Ref- and valuable data types


String s1 = new String("1");
String s2 = new String("1");

String s3 = "Name";
String s4 = "Name";

s3 == s4; // true, because of cash

s1 == s2 // false, references are distinct

Operator new

int[] x = null;

int[] x; // x.length;

int[][] matrix; <-> int[] matrix [];

*/