#include<iostream>

using namespace std;

class Person {
private:
    string name;
    string id;
    int age;
public:
    Person(const string &name, int age) : name(name), age(age) {
        cout << "PER created\n";

    }

    const string &getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    virtual int getMonthlyPay()=0;
};

class SalariedEmployees : public Person {
private:
    int monthly_salary;
public:
    SalariedEmployees(const string &name, int age, int monthly_salary) :
            Person(name, age), monthly_salary(monthly_salary) {
        cout << "SE created\n";
    }

    int getMonthlyPay() {
        return monthly_salary;
    }
};

class HourlyEmployees : public Person {
private:
    int hourly_rate;
    int hours_worked;
public:
    HourlyEmployees(const string &name, int age, int hourly_rate, int hours_worked) :
            Person(name, age), hourly_rate(hourly_rate), hours_worked(hours_worked) {
        cout << "HE created\n";
    }

    int getMonthlyPay() {
        return hours_worked * hourly_rate;
    }
};

class Trainee : public Person {
private:
    int monthly_allowance;
    int duration;
public:
    Trainee(const string &name, int age, int monthly_allowance, int duration) :
            Person(name, age), monthly_allowance(monthly_allowance), duration(duration) {
        cout << "TR created\n";
    }

    int getMonthlyPay() {
        return monthly_allowance;
    }
};

int main() {
    cout << "Welcome to the program!" << endl;
    SalariedEmployees se("Nipuna", 20, 20000);
    HourlyEmployees he("Kasun", 20, 8000, 6);
    Trainee tr("Wimal", 20, 20000, 6);


    return 0;


}
