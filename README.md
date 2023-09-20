# s expressions in C++

Type system for s expressions in C++, including a very basic parser to go from the text representation to the object representation.

Example usage can be found in ```main.cpp```

To parse an s-expression call ```exp* parse(std::string)``` from parsing.hpp.
An expression parsed can either be an ```atom``` or ```pair```, both of which are represented as subclasses of ```exp```. As of now everything which is an atom is stored as a string, using a subclass of ```atom``` called ```sstring```.

Access constituants of pairs using calls to the pair object's ```car``` and ```cdr``` methods. 

```c++
exp* example1 = parse("(define x 1)");
exp* car_example1 = example1 -> car(); //atom define
exp* cdr_example1 = example1 -> cdr(); //pair(x, pair(1, '()))


