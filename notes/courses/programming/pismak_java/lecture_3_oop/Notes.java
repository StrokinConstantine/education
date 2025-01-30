import java.util.Objects;

public class Notes
{
	private static int test_field_1; // initialization after loading
	
	public static void main(String[] args)
	{
		B b = new B();
		
		/*
			Polymorphism:
				* override
				* overload
				* abstract classes
				* return type covariants
		
			function signature = name + arguments
			overload = change of argument types
			
			If class is abstract, we can declare methods as abstract, and we can't create objects
			In interfaces all methods are abstract public
			All fields of interface can be only public static
			
			name of the interface = Runnable, Pushable, ..., action + able
			default methods ( with default implementation )
		
			Interfaces don't have a state
			
			instanceof operator checks object type ( getClass() return data type )
			
			Object:
				* int hashCode // identifier ( collisions )
				* boolean equals
				* Object clone
				* void finalize
				* String toString
				* wait / notify / notifyAll
				
			class System
			{
				...
				public static final out = null; // JVM initializes System.out by itself
				...
			}
			
			There is no enums in bytecode, it is just syntactic sugar.
			
			Enum: ( synthetic methods, implementation will be generated during RT )
				* name
				* ordinal
				* valueOf
				* values
				

		*/
		
		
		
	}
	
	
	static
	{
		// static initialization block
		// execution after loading by ClassLoader 
		// usually is used to initialize static fields 
		test_field_1 = 10;
		main(null);
		System.exit(-1); // JVM will never call main
	}
	
}

class A // compiler will add "extends Object"
{
	private String string;
	
	{
		// initialization block
		// execution before any constructor
		System.out.println("A initialization block");
	}
	
	public A()
	{
		super(); // class Object
		System.out.println("A constructor");
	}
	
	public A method(){ return new B(); }
	
	
	public boolean equals(Object o)
	{
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;
		A a = (A) o;
		return Objects.equals(string, a.string);
	}
	
}

class B extends A
{
	{
		System.out.println("B initialization block");
	}
	
	public B()
	{
		super();
		System.out.println("B constructor");
	}
	
	@Override
	public B method(){ return new B(); } // covariants
}

// java -verbose to see loaded classes by ClassLoader

interface Person
{
	void speak();
}

enum Colour1
{
	RED,
	GREEN
}

interface Glowable
{
	void glow();
} 

enum Colour2 implements Glowable
{
	RED("red"), // object is created by JVM
	GREEN("green")
	{
		public void blink(){} // static initialization block?
		
		@Override
		public void glow() {}
	};
	
	private String name;
	
	Colour2(String name) // execution after loading by ClassLoader
	{
		this.name = name;
	
	}
	public String getName(){ return this.name; }
	
	public void glow(){}
}
// <->
/*

// public static final Colour2 RED;

class Colour2 extends Enum
{
	Colour2 RED = new Colour2("red");
	Colour2 GREEN = new Colour2("green");
}
*/