//
// Created by NIPUNA on 7/3/2017.
//

#ifndef CLION_EMPLOYEE_MANAGEMENTSYSTEM_H
#define CLION_EMPLOYEE_MANAGEMENTSYSTEM_H

#include <string>
#include <vector>
#include "HashTable.h"
#include "Utils.h"

using namespace std;

class ManagementSystem {
    private:
        HashTable *employeeHt;
        HashTable *traineeHt;
    public:
        ManagementSystem(int size);
        vector<Person*> getAllConcat();
        string makeNameList();
        string makePayList();
        string makeTotal();
        string getDetails(string id);

        string removeEmployee(string id);

        bool addEmployee(string raw);

        int getPersonType(vector<string> v);

        bool isEmployer(string id);

};

#endif //CLION_EMPLOYEE_MANAGEMENTSYSTEM_H
