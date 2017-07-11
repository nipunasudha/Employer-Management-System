#include<iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "ManagementSystem.h"
void cls(){
    cout << "\033[2J\033[1;1H";
}
vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str); // Turn the string into a stream.
    string tok;
    if (str.find(' ') == string::npos){
        internal.push_back(str);
        return internal;
    }
    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }

    return internal;
}

using namespace std;
int main() {
    string rawcmd;
    vector<string> cmd;
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
    getline(cin, rawcmd);
    cls();
    while(true){ 
        cout << "=== Main menu ==="<<endl; 
        try{
            getline(cin, rawcmd);
            cmd=split(rawcmd,' ');
            if(cmd.at(0)=="q"){
                break;
            }else if(cmd.at(0)=="p"){
                cout<<cmd.at(1)<<endl;
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
