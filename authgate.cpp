#include "authgate.hpp"
AuthGate::AuthGate(User &u){
    activeUser = u;
    isLocked = true;
}
void AuthGate::attemptAccess(string username, string enteredKey){
    if(activeUser.validateKey(enteredKey) && activeUser.getUserName() == username){
        cout<<"Access Granted!!"<<endl;
        isLocked = false;
    }
    else cout<<"Permission Denied!!"<<endl;
}
string AuthGate::getStatus(){
    if(isLocked == true){
        return "System is: LOCKED!!";
    }
    else return "System is: UNLOCKED!!";
}