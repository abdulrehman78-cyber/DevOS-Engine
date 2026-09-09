#ifndef AUTHGATE_HPP
#define AUTHGATE_HPP

#include "user.hpp"
#include <iostream>
#include <string>
#include <cctype>
class AuthGate{
    private:
    User activeUser;
    bool isLocked;

    public:
    AuthGate(User &u);

    void attemptAccess(string username,string enteredKey);
    string getStatus();

};
#endif