#ifndef REGISTRY_HPP
#define REGISTRY_HPP
#include "project.hpp"
#include <fstream>
class Registry{
    private:
    Project* *list;
    int capacity;
    int projectCount;
    static int totalSystemProjects; //It is like a global tracker

    public:
    Registry();
    ~Registry();

    void addProject(Project *p);
    void viewRegistry();
    void saveToFile(const  std::string &filename) const;

    static void showGlobalStats();

};
#endif
