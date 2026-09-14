#ifndef USER_HPP
#define USER_HPP
#include <bits/stdc++.h>
using namespace std;
class User{
    private:
    string username;
    string securityKey;

    public:
    User(){
        username = "";
        securityKey ="";
    }
    User(string username,string securityKey){
        this->username = username;
        this->securityKey = securityKey;
    }


    string getUserName() const{
        return username;
    }

    bool validateKey(string enteredKey)  const{
        if(this->securityKey == enteredKey){
            return true;
        }
        return false;
    }

};
#endif