#include "project.hpp"
#include "registry.hpp"
#include <iostream>

using namespace std;
int main(){
    Registry R;
    int choice = -1;
    
    while (choice != 0){
        cout<<"===========Menu To Protfolio=========="<<endl;
        cout<<"Option 1. Register a new Project"<<endl
        <<"Option 2. View Registered Repositories"<<endl
        <<"Option 3. View Platform-Wide Metrics"<<endl
        <<"Option 0. Exit"<<endl;
        
        cout<<"Enter Your choice = "<<endl;
        cin>>choice;
        
        if(choice == 1)
        {
            cin.ignore();
            string title;
            cout<<"Enter Your Project Title: "<<endl;
            getline(cin,title);
            
            
            string language;
            cout<<"Enter Language Used: "<<endl;
            getline(cin,language);
            
            
            double version;
            cout<<"What's the Current version: "<<endl;
            cin>>version;
            cin.ignore();
            Project p(title,language,version);
            R.addProject(p);
            cout<<endl;
        }
        else if(choice == 2) {
            R.viewRegistry();
            cout<<endl;
        }
        else if(choice == 3){
            R.showGlobalStats();
            cout<<endl;
        }  
        else if(choice == 0) 
        {
            return -1;
        }
    }

    return 0;
}