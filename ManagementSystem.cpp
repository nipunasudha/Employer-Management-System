//
// Created by NIPUNA on 7/3/2017.
//

#include "ManagementSystem.h"

ManagementSystem::ManagementSystem(int size) {
    employeeHt = new HashTable(size);
    traineeHt = new HashTable(size);
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

