#include<iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include "Utils.h"
#include "ManagementSystem.h"
using namespace std;
int main() {
    string rawcmd;
    vector<string> cmd;
    utils::cls();

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
    getline(cin, rawcmd);
    utils::cls();
    while(true){ 
        cout << "---------------------------------------"<<endl; 
        cout << "Enter a command or q to exit.\nX:/>"; 
        try{
            getline(cin, rawcmd);
            cmd=utils::splitt(rawcmd,' ');
            cout<<endl;
            if(cmd.at(0)=="q"){
                break;
            }else if(cmd.at(0)=="add"){
                cout<<managementSystem.addEmployee(cmd.at(1))<<endl;
            }else if(cmd.at(0)=="remove"){
                cout<<managementSystem.removeEmployee(cmd.at(1))<<endl;
            }else if(cmd.at(0)=="view"){
                cout<<managementSystem.getDetails(cmd.at(1))<<endl;
            }else{
                cout<<"Invalid command."<<endl;
            }
        }catch(...){

            cout<<"Invalid command (E)"<<endl;
        }
    }

    //cout << managementSystem.getDetails("TR05") << endl;
    //cout << managementSystem.removeEmployee("TR05") << endl;
    //cout << managementSystem.getDetails("TR05") << endl;


    cout << "Program Ended.\n";
    return 0;


}
