#include <iostream>
using namespace std;
class Project
{
    string title;
    string language;
    double version;

public:
    Project()
    {
        title = "";
        language = "";
        version = 0;
    }
    Project(string title, string language, double version)
    {
        this->title = title;
        this->language = language;
        this->version = version;
    }
    // Getters
    string getTitle()
    {
        return title;
    }
    string getLanguage()
    {
        return language;
    }
    double getVersion()
    {
        return version;
    }

    // Display Function
    void display()
    {
        cout << "Project Name: " << getTitle() << endl
             << "Written IN: " << getLanguage() << endl
             << "Version: " << getVersion() << endl;
    }
    // Operator== Powers
    bool operator==(const Project &other)
    {
        return (title == other.title);
    }
};
int main()
{
    return 0;
}