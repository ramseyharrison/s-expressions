#include <string>
#include <sstream>
#include <variant>
#include <iostream>
class exp{
public:
  exp();
  virtual std::string print() = 0;
};

class atom : public exp{
public:
  atom();
};

class sint : public atom {
public:
  sint();
  sint(int);
  std::string print(){
    return std::to_string(value);
  }
private:
  int value;
};

class sstring : public atom {
public:
  sstring();
  sstring(std::string);
  std::string print(){
    return value;
  }
private:
  std::string value;
};

class pair : public exp{
public:
  pair();
  pair(exp*, exp*);
  std::string print(){
    return car -> print() + (cdr ? " " + cdr -> print() : "");
  }
  exp* get_car();
  exp* get_cdr();
private:
  exp* car;
  exp* cdr;
};
