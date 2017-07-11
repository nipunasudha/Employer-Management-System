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
    Person(const string &id, const string &name, int age);

    const string &getName() const;

    const string &getId() const;

    int getAge() const;

    virtual int getMonthlyPay()=0;

    virtual string getInformation()=0;
};

class SalariedEmployee : public Person {
private:
    int monthly_salary;
public:
    SalariedEmployee(const string &id, const string &name, int age, int monthly_salary);

    int getMonthlyPay();

    int getMonthly_salary() const;

    string getInformation();
};

class HourlyEmployee : public Person {
private:
    int hourly_rate;
    int hours_worked;
public:
    HourlyEmployee(const string &id, const string &name, int age, int hourly_rate, int hours_worked);

    int getHourly_rate() const;

    int getHours_worked() const;

    int getMonthlyPay();

    string getInformation();
};

class Trainee : public Person {
private:
    int monthly_allowance;
    int duration;
public:
    Trainee(const string &id, const string &name, int age, int monthly_allowance, int duration);

    int getMonthly_allowance() const;

    int getDuration() const;

    int getMonthlyPay();

    string getInformation();
};

#endif //CLION_EMPLOYEE_PEOPLE_H
