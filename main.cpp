#include "parser.hpp"
#include <iostream>
#include <vector>

int main(){
  parser("(define x 100)") . get_result() -> car() -> print();
  
}
