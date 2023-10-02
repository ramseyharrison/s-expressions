#include "parser.hpp"
#include <iostream>
#include <vector>

int main(){
  //example usage type pair : (define x 1)
  //this is represented internally as follows:
  //pair("define", pair("x"), pair("1",NULL))
  //car and cdr work as expected on pairs
  parser("#t"). get_result() -> print();
}
