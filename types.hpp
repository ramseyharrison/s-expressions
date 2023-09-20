#include <string>
#include <sstream>
#include <variant>
#include <iostream>
class exp{
public:
  exp();
  virtual std::string to_string() = 0;
  virtual exp* car() = 0;
  virtual exp* cdr() = 0;
  void print();
};

class atom : public exp{
public:
  atom();
  exp* car();
  exp* cdr();
};

class sint : public atom {
public:
  sint();
  sint(int);
  std::string to_string();
private:
  int get_value();
  int value;
};

class sstring : public atom {
public:
  sstring();
  sstring(std::string);  
  std::string to_string();
private:
  std::string get_value();
  std::string value;
};
class pair : public exp{
public:
  pair();
  pair(exp*, exp*);
  std::string to_string();
  exp* get_car();
  exp* get_cdr();
  exp* car() override;
  exp* cdr();
private:
  exp* car_val;
  exp* cdr_val;
};
