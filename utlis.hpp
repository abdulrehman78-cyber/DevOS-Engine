#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <cctype>
using namespace std;
inline void toLowerCaseInPlace(string &str){
    for(char &c : str){
    c = tolower(static_cast<unsigned char>(c));
  }  
}
#endif