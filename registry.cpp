#include "registry.hpp"
int Registry::totalSystemProjects = 0;

Registry::Registry()
{
    capacity = 5;
    projectCount = 0;
    list = new Project*[capacity];
}
Registry::~Registry() {
    delete [] list;
}

void Registry::addProject(Project *p){
    for(int i = 0;i<projectCount;i++){
        if(*list[i] == *p){
            cout<<"This Project Already exists!!!"<<endl;
            return;
        }
    }
    if(projectCount == capacity){
        capacity = capacity << 1;
        Project* *newArr = new Project*[capacity];
        for(int i = 0;i<projectCount;i++){
            newArr[i] = list[i];
        }
        delete [] list;
        list = newArr;
    }
    list[projectCount] = p;
    cout<<"Project [" <<p->getTitle()<< "] has been added successfully"<<endl;
    projectCount++;
    totalSystemProjects++;
}

void Registry::viewRegistry(){
    for(int i = 0;i< projectCount;i++){
        list[i]->display();
    }
}

void Registry::showGlobalStats(){
    cout<<"Total Projects:"<<totalSystemProjects<<endl;
}

void Registry::saveToFile(const string &filename) const{
    ofstream outFile(filename); //opening a file

    if(!outFile) {
        cout<<"Database error: could not open the file for writing"<<endl;
        return;
    }

    for(int i = 0;i<projectCount;i++){
        outFile << list[i]->serilize()<<endl;
    }

    outFile.close();
    cout << "Data Synchronization Complete. Database updated." << endl;

}   