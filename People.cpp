//
// Created by NIPUNA on 7/3/2017.
//
#include "People.h"


Person::Person(const string &name, int age) : name(name), age(age) {
    cout << "PER created\n";

}

const string &Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}


SalariedEmployees::SalariedEmployees(const string &name, int age, int monthly_salary) :
        Person(name, age), monthly_salary(monthly_salary) {
    cout << "SE created\n";
}

int SalariedEmployees::getMonthlyPay() {
    return monthly_salary;
}


HourlyEmployees::HourlyEmployees(const string &name, int age, int hourly_rate, int hours_worked) :
        Person(name, age), hourly_rate(hourly_rate), hours_worked(hours_worked) {
    cout << "HE created\n";
}

int HourlyEmployees::getMonthlyPay() {
    return hours_worked * hourly_rate;
}


Trainee::Trainee(const string &name, int age, int monthly_allowance, int duration) :
        Person(name, age), monthly_allowance(monthly_allowance), duration(duration) {
    cout << "TR created\n";
}

int Trainee::getMonthlyPay() {
    return monthly_allowance;
}
