#include <string>
#include <sstream>
#include <variant>
#include <iostream>

class exp {
public:
    exp();

    virtual std::string to_string() = 0;

    virtual exp *car() = 0;

    virtual exp *cdr() = 0;

    void print();
};

class atom : public exp {
public:
    atom();

    exp *car();

    exp *cdr();
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

class sboolean : public atom {
public:
    sboolean(char c);

    bool get_value();

    std::string to_string();

private:
    bool value;
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

class sidentifier : public sstring {
public:
    sidentifier(std::string);
};

class pair : public exp {
public:
    pair();

    pair(exp *, exp *);

    std::string to_string();

    exp *car() override;

    exp *cdr();

private:
    exp *get_car();

    exp *get_cdr();

    exp *car_val;
    exp *cdr_val;
};
