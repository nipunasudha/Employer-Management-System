#include<iostream>
#include "ManagementSystem.h"

using namespace std;


int main() {
    cout << "Welcome to the program!" << endl;
    ManagementSystem managementSystem(10);
    managementSystem.addEmployee("EM01,A,31,34000,10");
    managementSystem.addEmployee("EM06,F,39,400,100");
    managementSystem.addEmployee("TR05,F,39,400,100");
    managementSystem.addEmployee("EM07,I,35,54000");
    managementSystem.addEmployee("EM11,G,41,24000");
    cout << managementSystem.getDetails("TR05") << endl;
    cout << managementSystem.removeEmployee("TR05") << endl;
    cout << managementSystem.getDetails("TR05") << endl;


    cout << "END\n";
    return 0;


}
