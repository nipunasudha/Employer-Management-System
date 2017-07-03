#include<iostream>
#include "People.h"
#include "HashTable.h"
#include "Utils.h"

using namespace std;

class ManagementSystem {
private:
    HashTable *employeeHt;
    HashTable *traineeHt;
public:
    ManagementSystem(int size) {
        employeeHt = new HashTable(size);
        traineeHt = new HashTable(size);
    }

    string getDetails(string id) {
        Person *foundPerson;
        if (isEmployer(id)) {
            foundPerson = employeeHt->get(id);
        } else {
            foundPerson = traineeHt->get(id);
        }
        return foundPerson ? foundPerson->getInformation() : "Entry not found!";
    }

    string removeEmployee(string id) {
        Person *foundPerson;
        if (isEmployer(id)) {
            return employeeHt->remove(id) ? "Deleted." : "Entry not found!";
        } else {
            return traineeHt->remove(id) ? "Deleted." : "Entry not found!";
        }
    }

    bool addEmployee(string raw) {

        vector<string> v = split(raw, ',');
        switch (getPersonType(v)) {
            case 1:
                employeeHt->put(new SalariedEmployee(v[0], v[1], stoi(v[2]), stoi(v[3])));
                break;
            case 2:
                employeeHt->put(new HourlyEmployee(v[0], v[1], stoi(v[2]), stoi(v[3]), stoi(v[4])));
                break;
            case 3:
                traineeHt->put(new Trainee(v[0], v[1], stoi(v[2]), stoi(v[3]), stoi(v[4])));
                break;
            default:
                return false;
        }

    }

    int getPersonType(vector<string> v) {
        if (isEmployer(v[0])) {
            if (v.size() == 4) {
                return 1;
            } else if (v.size() == 5) {
                return 2;
            } else return 0;
        } else if (!isEmployer(v[0])) {
            return 3;
        } else return 0;
    }

    bool isEmployer(string id) {
        return id.substr(0, 2) == "EM";
    }

};


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
