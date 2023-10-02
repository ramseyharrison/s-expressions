# scheme s expressions in C++

parser and object representation for s expressions representing scheme syntax.

As of now there are three types of atoms :
1)integers
2)identifiers(as defined in the scheme grammar)
3)strings, which begin and end with quotation marks

to parse an s-expression, call a new instance of parser class with the string to parse.
The parsed expression can be retrieved by calling the get_result method instance method from the parser class.

