/*
	explicit typing = we always annotate data with types
	implicit typing
	Python = strong dynamic typing ( no implicit conversions, 1 if True else "3" + 2 is ok )
	JavaScript = weak dynamic typing
	C = static weak typing ( all types are known in compile time, type checking during compile time )
	OCaml = static strong typing
	
	Types of polymorphism:
		Parametric polymorphism, where a function accepts an additional argument, defining the type of argument ( generic functions in Java or C# are example of parametric compile-time polymorphism )
		Inclusion, when function behave in the same way for type and subtype ( subtype polymorphism in OOP )
		Overloading
		Coercion, where a conversion exists from X to Y and a function accepting an argument of type Y is called with an argument of X
*/