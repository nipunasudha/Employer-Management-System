//
// Created by NIPUNA on 7/3/2017.
//
#include "Utils.h"
#include "ManagementSystem.h"

ManagementSystem::ManagementSystem(int size) {
    employeeHt = new HashTable(size);
    traineeHt = new HashTable(size);
}
vector<Person*> ManagementSystem::getAllConcat(){

    vector<Person*> v={};
    utils::concatVec(v,employeeHt->getAll());
    utils::concatVec(v,traineeHt->getAll());
    return v;
}
string ManagementSystem::makeNameList(){
    vector<Person*> v=getAllConcat();
    string nameList="ID     Name\n--------------------\n";
    for(int i=0;i<v.size();i++){
       nameList+=v[i]->getId() +"  "+ v[i]->getName()+"\n";
    }
    return nameList;
}
string ManagementSystem::makePayList(){
    vector<Person*> v=getAllConcat();
    string payList="ID     Name     Pay Amount\n-------------------------------\n";
    for(int i=0;i<v.size();i++){
       payList+=v[i]->getId() +"  "+ v[i]->getName()+"  "+ to_string(v[i]->getMonthlyPay())+"\n";
    }
    return payList;
}
string ManagementSystem::getDetails(string id) {
    Person *foundPerson;
    if (isEmployer(id)) {
        foundPerson = employeeHt->get(id);
    } else {
        foundPerson = traineeHt->get(id);
    }
    return foundPerson ? foundPerson->getInformation() : "Entry not found!";
}

string ManagementSystem::removeEmployee(string id) {
    Person *foundPerson;
    if (isEmployer(id)) {
        return employeeHt->remove(id) ? "Deleted." : "Entry not found!";
    } else {
        return traineeHt->remove(id) ? "Deleted." : "Entry not found!";
    }
}

bool ManagementSystem::addEmployee(string raw) {

    vector<string> v = utils::splitt(raw, ',');
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

int ManagementSystem::getPersonType(vector<string> v) {
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

bool ManagementSystem::isEmployer(string id) {
    return id.substr(0, 2) == "EM";
}

