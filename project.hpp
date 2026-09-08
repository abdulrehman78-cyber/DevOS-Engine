#ifndef PROJECT_HPP
#define PROJECT_HPP
#include <iostream>
#include <string>
using namespace std;
class Project
{
    string title;
    string language;
    double version;

public:
    Project();
    Project(string title, string language, double version);
    // Getters
    string getTitle();
    string getLanguage();
    double getVersion();

    // Display Function
    void display();
    // Operator== Powers
    bool operator==(const Project &other);
};
#endif