//
// Created by NIPUNA on 7/3/2017.
//

#ifndef CLION_EMPLOYEE_PEOPLE_H
#define CLION_EMPLOYEE_PEOPLE_H

#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    string id;
    int age;
public:
    Person(const string &name, int age);

    const string &getName() const;

    int getAge() const;

    virtual int getMonthlyPay()=0;
};

class SalariedEmployees : public Person {
private:
    int monthly_salary;
public:
    SalariedEmployees(const string &name, int age, int monthly_salary);

    int getMonthlyPay();
};

class HourlyEmployees : public Person {
private:
    int hourly_rate;
    int hours_worked;
public:
    HourlyEmployees(const string &name, int age, int hourly_rate, int hours_worked);

    int getMonthlyPay();
};

class Trainee : public Person {
private:
    int monthly_allowance;
    int duration;
public:
    Trainee(const string &name, int age, int monthly_allowance, int duration);

    int getMonthlyPay();
};

#endif //CLION_EMPLOYEE_PEOPLE_H
