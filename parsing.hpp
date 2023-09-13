#include "types.hpp"
#include <cassert>
#include <iostream>

std::string until_next_character(std::string str, int& loc, char c);

std::string next_token(std::string str, int & loc);

pair* parse_list(std::string str, int loc);

exp* parse_atom(std::string str);

exp* parse(std::string str);
