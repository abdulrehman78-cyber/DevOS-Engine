#ifndef AUTHGATE_HPP
#define AUTHGATE_HPP

#include "user.hpp"
#include <bits/stdc++.h>
using namespace std;
class AuthGate
{
private:
    User activeUser;
    bool isLocked;

public:
    AuthGate(User u)
    {
        activeUser = u;
        isLocked = true;
    }

    void attemptAccess(string username, string enteredKey)
    {
        if (activeUser.getUserName() == username && activeUser.validateKey(enteredKey) == 1)
        {
            isLocked = false;
            cout << "Access Granted!!!" << endl;
            return;
        }
        cout << "Permission denied wrong Credentials!!!" << endl;
    }
    string getStatus(){
        if(isLocked) return "System is: LOCKED!!";
        return "System is: UNLOCKED!!";
    }
};
#endif