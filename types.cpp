#include <iostream>
#include "types.hpp"


/** exp **/
exp::exp() {};
void exp::print(){
  std::cout << to_string() << std::endl;
}
/** end exp **/

/** atom **/
atom::atom() {};
exp* atom::car(){return this;}
exp* atom::cdr(){return this;}
/** end atom **/

/** sint **/

//constructor 
sint::sint(int intval) : value(intval)  {};

//getter value
int sint::get_value(){return value;}

//to_string
std::string sint::to_string(){return std::to_string(get_value());}

/** end sint **/

/** sstring **/

//constructor
sstring::sstring(std::string stringval) : value(stringval) {};

//getter value
std::string sstring::get_value(){ return value;}

//to_string
std::string sstring::to_string(){ return get_value();}

/** end sstring **/

/** pair **/

//constructor
pair::pair(exp* carval, exp* cdrval) : car_val(carval), cdr_val(cdrval) {};

//getter car
exp* pair::get_car() {return car_val;}

//getter cdr
exp* pair::get_cdr() {return cdr_val;}

exp* pair::car() {return get_car();}

exp* pair::cdr() {return get_cdr();}
//to_string
std::string pair::to_string(){
  return get_car() -> to_string() + (get_cdr() ? " " + get_cdr() -> to_string() : "");
}

/** end pair **/
