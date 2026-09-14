#ifndef PROJECT_HPP
#define PROJECT_HPP
#include<bits/stdc++.h>
using namespace std;
class Project
{
    string title;
    string language;
    double version;

public:
    Project(){
        title = "";
        language = "";
        version = 0.0;
    }
    
    Project(string title, string language, double version){
        this->title = title;
        this->language = language;
        this->version = version;
    }
    string serilize() const{
        ostringstream os;
        os << title << "|"<<language<<"|"<<fixed <<setprecision(2)<<version;
        return os.str();
    }
    // Getters
    string getTitle(){
        return title;
    }
    string getLanguage(){
        return language;
    }
    double getVersion(){
        return version;
    }

    // Display Function
    void display(){
        cout << "Project Name: " << title << endl
         << "Written IN: " << language << endl
         << "Version: " << version << endl;
    }
    // Operator== Powers
    bool operator==(const Project &other){
        if(title == other.title) return true;
        return false;
    }
};
#endif