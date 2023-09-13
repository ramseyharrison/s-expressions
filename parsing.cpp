
#include "types.hpp"
#include <cassert>
#include <iostream>

std::string until_next_character(std::string str, int& loc, char c){
  std::string token;
  while(loc < str.length()){
    token += str[loc];
    if(str[loc] == c){
      return token;
    }
    loc++;
  }
  return "";
}
std::string next_token(std::string str, int & loc){
  std::string token;
  while(str[loc] != ' ' && loc < str.length() - 1){
    token += str[loc];
    if(str[loc] == '\"')
      token += until_next_character(str,++loc,'\"');    
    loc++;
  }
  return token;
}
pair* parse_list(std::string str, int loc){
  if(loc >= str.length() - 1)
    return nullptr;
  else{
    //get next token, loc is incremented to end of token
    std::string cdr_str = next_token(str,loc);  
    loc++; 
    while(str[loc] == ' ')
      loc++;   
    return new pair(new sstring(cdr_str),parse_list(str,loc));
  }     
}

exp* parse_atom(std::string str){
  int loc = 0;
  return new sstring(next_token(str,loc));
}

exp* parse(std::string str){
  if(*(str.begin()) == '(' && *(str.end() - 1) == ')'){
    return parse_list(str,1);
  }else{
    return parse_atom(str);
  }
}
