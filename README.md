# scheme s expressions in C++

parser and object representation for s expressions representing scheme syntax.

As of now there are three types of atoms :
1. integers
2. identifiers(as defined in the scheme grammar)
3. strings, which begin and end with quotation marks
4. booleans
to parse an s-expression, call a new instance of the ```parser``` class with the string to parse as the argument to the constructor.
The result of the parse can then be retrieved by calling the ```get_result``` instance method from the parser class. An example is found in ```main.cpp```

