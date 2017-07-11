//
// Created by NIPUNA on 7/3/2017.
//

#include <vector>
#include "People.h"

Person::Person(const string &id, const string &name, int age) : id(id), name(name), age(age) {
//    cout << "PER created\n";

}

const string &Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

const string &Person::getId() const {
    return id;
}


SalariedEmployee::SalariedEmployee(const string &id, const string &name, int age, int monthly_salary) :
        Person(id, name, age), monthly_salary(monthly_salary) {
//    cout << "SE created\n";
}

int SalariedEmployee::getMonthlyPay() {
    return monthly_salary;
}

string SalariedEmployee::getInformation() {
    return "ID : " + getId() +
           "\nName : " + getName() +
           "\nAge : " + to_string(getAge()) +
           "\nSalary : " + to_string(getMonthly_salary());


}

int SalariedEmployee::getMonthly_salary() const {
    return monthly_salary;
}

HourlyEmployee::HourlyEmployee(const string &id, const string &name, int age, int hourly_rate, int hours_worked) :
        Person(id, name, age), hourly_rate(hourly_rate), hours_worked(hours_worked) {
//    cout << "HE created\n";
}

int HourlyEmployee::getMonthlyPay() {
    return hours_worked * hourly_rate;
}

int HourlyEmployee::getHourly_rate() const {
    return hourly_rate;
}

int HourlyEmployee::getHours_worked() const {
    return hours_worked;
}

string HourlyEmployee::getInformation() {
    return "ID : " + getId() +
           "\nName : " + getName() +
           "\nAge : " + to_string(getAge()) +
           "\nPay Rate : " + to_string(getHourly_rate()) +
           "\nWork Hours : " + to_string(getHours_worked());


}


Trainee::Trainee(const string &id, const string &name, int age, int monthly_allowance, int duration) :
        Person(id, name, age), monthly_allowance(monthly_allowance), duration(duration) {
//    cout << "TR created\n";
}

int Trainee::getMonthlyPay() {
    return monthly_allowance;
}

int Trainee::getMonthly_allowance() const {
    return monthly_allowance;
}

int Trainee::getDuration() const {
    return duration;
}

string Trainee::getInformation() {
    return "ID : " + getId() +
           "\nName : " + getName() +
           "\nAge : " + to_string(getAge()) +
           "\nAllowance : " + to_string(getMonthly_allowance()) +
           "\nDuration : " + to_string(getDuration());


}




//GUIDE
//SalariedEmployee se("Nipuna", 20, 20000);
//HourlyEmployee he("Kasun", 20, 8000, 6);
//Trainee tr("Wimal", 20, 20000, 6);
//HashTable ht(8);
//ht.put(&se);
//ht.put(&he);
//ht.put(&tr);
//cout << ht.get("Nipuna")->getMonthlyPay() << endl;
//cout << ht.get("Kasun")->getMonthlyPay() << endl;
//cout << ht.get("Wimal")->getMonthlyPay() << endl;