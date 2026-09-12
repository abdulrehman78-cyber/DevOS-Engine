#include "user.hpp"
User::User(){
    username = "";
    securityKey = "";
}
User::User(string username,string securityKey){
    this->username = username;
    this->securityKey = securityKey;
}
string User::getUserName() const{
    return username;
}
bool User::validateKey(string enteredKey) const{
    if(this->securityKey == enteredKey){
        return true;
    }
    return false;
}