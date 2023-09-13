#include "types.hpp"
exp::exp() {};

atom::atom() {};

sint::sint(int intval) : value(intval)  {};

sstring::sstring(std::string stringval) : value(stringval) {};

pair::pair() {}

pair::pair(exp* carval, exp* cdrval) : car(carval), cdr(cdrval) {};

exp* pair::get_car() { return car;}

exp* pair::get_cdr() { return cdr;}
