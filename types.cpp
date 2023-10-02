#include <iostream>
#include "types.hpp"


/** exp **/
exp::exp() {};
void exp::print(){
  std::cout << to_string() << std::endl;
}

/** atom **/
atom::atom() {};
exp* atom::car(){return this;}
exp* atom::cdr(){return this;}

/** sint **/

//constructor 
sint::sint(int intval) : value(intval)  {};

//getter value
int sint::get_value(){return value;}

//to_string
std::string sint::to_string(){return std::to_string(get_value());}

/** sboolean **/
//constructor
sboolean::sboolean(char c){
    value = (c == 't') ? true : false;
}

//getter
bool sboolean::get_value(){return value;}

//to_string

std::string sboolean::to_string(){
  return (value) ? "#t" :  "#f";
}

/** sstring **/

//constructor
sstring::sstring(std::string stringval) : value(stringval) {};

//getter value
std::string sstring::get_value(){ return value;}

//to_string
std::string sstring::to_string(){ return get_value();}


/** sidentifier **/
sidentifier::sidentifier(std::string stringval) : sstring(stringval){}

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

