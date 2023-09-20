#include "parsing.hpp"
#include <iostream>
#include <vector>

int main(){
  //example usage type pair : (define x 1)
  //this is represented internally as follows:
  //pair("define", pair("x"), pair("1",NULL))
  //car and cdr work as expected on pairs
  exp* example1 = parse("(define x 1)");
  exp* car_example1 = example1 -> car();
  exp* cdr_example1 = example1 -> cdr();
  //car_example1 -> print();
  //cdr_example1 -> print();

  //example usage : atoms
  //atoms are as of now stored as strings, but the data type for integers
  //exists already
  //input such as apple, "apple", 123, x123 are represented individually as:
  //atom("apple"), atom("\"apple\""), atom("123"), atom("x123")
  exp* example2 = parse("apple");
  exp* example3 = parse("\"apple\"");
  exp* example4 = parse("x123");

}
