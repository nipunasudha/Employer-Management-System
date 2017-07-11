#include<iostream>
#include <fstream>
#include "ManagementSystem.h"
void cls(){
    cout << "\033[2J\033[1;1H";
}
using namespace std;
int main() {

    string cmd;
    cls();
    cout << "=== Welcome to the Employee Management System ===\n----------------------------" << endl;
    cout << "Reading records from the file...\n" << endl;
    ManagementSystem managementSystem(10);
    string s;
    ifstream f1("userdata");
    while(getline(f1,s)){
        cout<< s<<endl;
        managementSystem.addEmployee(s);
    }
    cout << "\nLoading data OK!\nPress Enter to Continue...\n----------------------------"<<endl;
    getline(cin, cmd);
    cls();
    while(true){ 
        cout << "=== Main menu ==="<<endl; 
        getline(cin, cmd);
        if(cmd=="q"){
            break;
        }else if(cmd=="p"){
            
        }else{
            cout<<"Invalid command."<<endl;
        }
    }

    //cout << managementSystem.getDetails("TR05") << endl;
    //cout << managementSystem.removeEmployee("TR05") << endl;
    //cout << managementSystem.getDetails("TR05") << endl;


    cout << "Program Ended.\n";
    return 0;


}
