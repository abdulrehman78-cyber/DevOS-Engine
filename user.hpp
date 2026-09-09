#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include <string>
#include <cctype>
using namespace std;
class User{
    private:
    string username;
    string securityKey;

    public:
    User();
    User(string username,string securityKey);


    string getUserName() const;

    bool validateKey(string enteredKey)  const;

};
#endif