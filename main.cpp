#include "project.hpp"
#include "registry.hpp"
#include <iostream>

using namespace std;
int main(){
    Project p1("miniShell", "C", 1.0);
    Project p2("nobleFinance", "HTML , CSS ,JAVASCRIPT", 1.0);

    Registry publicHub;
    Registry privateHub;

    // Load up the private hub
    privateHub.addProject(p1);
    privateHub.addProject(p2);

    cout << "\n=== PUBLIC HUB REGISTRY ===" << endl;
    publicHub.viewRegistry();

    cout << "\n=== PRIVATE HUB REGISTRY ===" << endl;
    privateHub.viewRegistry();

    cout << "\n=== SYSTEM WIDE TELEMETRY ===" << endl;
    Registry::showGlobalStats();

    return 0;
}