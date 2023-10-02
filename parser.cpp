#include "parser.hpp"
#include <cassert>
exp *parser::get_result() {
    return parse_result;
}

std::string parser::remaining_input() {
    return std::string(it,input.end());
}
parser::parser(std::string inputval) : input(inputval), it(input.begin()) {
    parse_result = atom_or_pair();
}


void parser::next() { it++; }

//adds iterator to buffer and increments iterator
void parser::add() { buffer += *(it++); }

exp* parser::atom_or_pair() {
    if (*(input.begin()) == '(' && *(input.end() - 1) == ')') {
        return pair();
    } else {
        return atom();
    }
}

exp* tokens_to_pair(std::vector<exp*>::iterator it,std::vector<exp*>::iterator end){
    if(it == end)
        return nullptr;
    return new pair(*it, tokens_to_pair(it + 1,end));
}

void whitespace(std::string::iterator &it){
    while(*it == ' ')
        it++;
}

exp* make_pair(std::string input_string){
    std::string::iterator it = input_string.begin();
    std::vector<exp*> token_values;
    whitespace(it);
    while(it != input_string.end()){
        std::string to_parse = std::string(it,input_string.end());
        parser* temp = new parser(to_parse);
        token_values.push_back(temp -> get_result());
        input_string = temp -> remaining_input();
        it = input_string.begin();
        whitespace(it);
    }
    return tokens_to_pair(token_values.begin(),token_values.end());
}

exp *parser::pair() {
    return make_pair(std::string(input.begin() + 1,input.end() - 1));
}

exp *parser::atom() {
    if (see_initial()) {//we're expecting an identifier
        add();
        return identifier();
    }else if (see_boolean()) {//if found the iterator is pushed forward by one
        add();//set token to t or f and pass it to the constructor
        assert(buffer.length() == 1);
        assert(buffer[0] == 't' || buffer[0] == 'f');
        return new sboolean(buffer[0]);
    }else if(see_quote()){
        return string();
    }else if(see_digit()){
        return integer();
    }
    return nullptr;
}

bool parser::see_quote(){
    return (*it == '\"');
}
exp *parser::string(){
    buffer += *it++;
    while(it != input.end()){
        if(*it == '\"' && *(it - 1) != '\\'){
            return new sstring(buffer += *(it++));
        }
        buffer += *it;
        it++;
    }
    return nullptr;
}
exp *parser::identifier() {
    while (see_subsequent()) {
        add();
    }
    return new sidentifier(buffer);
}

bool parser::see_initial() {
    if (isalpha(*it))
        return true;
    else {
        switch (*it) {
            case '!':
            case '$':
            case '%':
            case '&':
            case '*':
            case '/':
            case ':':
            case '<':
            case '=':
            case '>':
            case '?':
            case '~':
            case '_':
            case '^':
                return true;
            default:
                return false;
        }
    }
}

bool parser::see_subsequent() {
    return see_initial() || see_digit() || (*it == '.') || (*it == '+') || (*it == '-');
}

exp *parser::integer(){
    while(see_digit()){
        buffer += *it++;
    }
    return new sint(stoi(buffer));
}

bool parser::see_digit() {
    return isdigit(*it);
}

bool parser::see_boolean() {
    if ((*it == '#' && (*(it + 1) == 't')) || (*(it + 1) == 'f')) {
        next();
        return true;
    }
    return false;
}
