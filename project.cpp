#include "project.hpp"
Project::Project()
{
    title = "";
    language = "";
    version = 0;
}
Project::Project(string title, string language, double version)
{
    this->title = title;
    this->language = language;
    this->version = version;
}
// Getters
string Project::getTitle()
{
    return title;
}
string Project::getLanguage()
{
    return language;
}
double Project::getVersion()
{
    return version;
}
// Display Function
void Project::display()
{
    cout << "Project Name: " << getTitle() << endl
         << "Written IN: " << getLanguage() << endl
         << "Version: " << getVersion() << endl;
}
// Operator== Powers
bool Project::operator==(const Project &other)
{
    return (title == other.title);
}

string Project::serilize() const
{
    ostringstream oss;
    oss << title << "|" << language + "|" << fixed<<setprecision(1) << (version);
    return oss.str();
}