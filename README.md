# s expressions in C++

Type system for s expressions in C++, including a very basic parser to go from text representation to the object representation.

Example usage is exemplified in main.cpp

To parse an s-expression call exp* parse() from parsing.hpp.
An expression parsed can either be an atom or pair, both of which are represented as subclass of exp called atom and pair. As of now everything which is an atom is stored as a string, using a subclass of atom called sstring.

Access constituants of pairs using calls to the pair object's car and cdr methods. 

```c++
exp* example1 = parse("(define x 1)");
exp* car_example1 = example1 -> car(); //atom define
exp* cdr_example1 = example1 -> cdr(); //pair(x, pair(1, '()))


