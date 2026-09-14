#include "project.hpp"
#include "registry.hpp"
#include "utlis.hpp"
#include "authgate.hpp"
#include <bits/stdc++.h>

using namespace std;
int main()
{
    
    //Taking the details
    string username, password;
    cout << "==== Admin Subsystem Setup =====" << endl;
    cout << "Register Admin Username: " << endl;
    getline(cin, username);
    toLowerCaseInPlace(username);

    cout << "Regsiter the password" << endl;
    getline(cin, password);

    User admin(username, password);
    AuthGate gate(admin);

    LOGIN_START:
    // login verification
    cout << "\n=== DEVOS SECURE INTERFACE LOGIN ===" << endl;
    cout << "Enter Username" << endl;
    getline(cin, username);
    toLowerCaseInPlace(username);

    cout << "Enter Password" << endl;
    getline(cin, password);

    gate.attemptAccess(username, password);
    cout<<"Welcome Dear "<<username<<endl;
    
    if (gate.getStatus() == "System is: UNLOCKED!!")
    {
        Registry R;
        int choice = -1;

        while (choice != 0)
        {

            cout << "===========Menu To Protfolio==========" << endl;
            cout << "Option 1. Register a new Project" << endl
                 << "Option 2. View Registered Repositories" << endl
                 << "Option 3. View Platform-Wide Metrics" << endl
                 << "Option 0. Exit" << endl;

            cout << "Enter Your choice = " << endl;
            cin >> choice;

            if (choice == 1)
            {
                cin.ignore();
                string title;
                cout << "Enter Your Project Title: " << endl;
                getline(cin, title);

                string language;
                cout << "Enter Language Used: " << endl;
                getline(cin, language);

                double version;
                cout << "What's the Current version: " << endl;
                cin >> version;
                cin.ignore();


                Project p = Project(title, language, version);
                R.addProject(p);
                cout << endl;

                
            }
            else if (choice == 2)
            {
                R.viewRegistry();
                cout << endl;
            }
            else if (choice == 3)
            {
                R.showGlobalStats();
                cout << endl;
            }
            else if (choice == 0)
            {
                R.saveToFile("database.txt");
                return -1;
            }
        }
    }
    else{
        string c;
        cout << "System remains locked. Terminal execution halted." << endl;
        cout<< "If you want to try again press R"<<endl;
        cin>>c;
        toLowerCaseInPlace(c);
        if(c == "r")
        goto LOGIN_START;
        else return -1;
    }

    return 0;
}