#ifndef REGISTRY_HPP
#define REGISTRY_HPP
#include "project.hpp"
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
class Registry
{
private:
    Project *list;
    int capacity;
    int projectCount;
    inline static int totalSystemProjects = 0; // It is like a global tracker

public:
    Registry()
    {
        capacity = 5;
        projectCount = 0;
        list = new Project[capacity];
    }
    ~Registry()
    {
        delete[] list;
    }

    void addProject(Project p)
    {
        for (int i = 0; i < projectCount; i++)
        {
            if (list[i] == p)
            {
                cout << "This Project already exist!!" << endl;
                return;
            }
        }
        if (projectCount == capacity)
        {
            capacity = capacity * 2;
            Project *newArr = new Project[capacity];
            for (int i = 0; i < projectCount; i++)
            {
                newArr[i] = list[i];
            }
            delete[] list;
            list = newArr;
        }
        list[projectCount] = p;
        cout << "Project [" << p.getTitle() << "] has been added successfully" << endl;
        projectCount++;
        totalSystemProjects++;
    }

    
    void viewRegistry()
    {
        for (int i = 0; i < projectCount; i++)
        {
            list[i].display();
            cout << endl;
        }
    }


    void saveToFile(const string &filename) const
    {
        ofstream outFile(filename); // open a file
        if (!outFile)
        {
            cout << "Database error: could not open the file for writing" << endl;
            return;
        }
        for (int i = 0; i < projectCount; i++)
        {
            outFile << list[i].serilize();
            outFile<<endl; 
        }
        outFile.close();
        cout << "Data Synchronization Complete. Database updated." << endl;
    }

    static void showGlobalStats()
    {
        cout << "Total Projects:" << totalSystemProjects << endl;
    }
};
#endif
