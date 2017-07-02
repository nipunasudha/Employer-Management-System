#include<iostream>
#include "People.h"
#include "HashTable.h"

using namespace std;


int main() {
    cout << "Welcome to the program!" << endl;
    SalariedEmployees se("Nipuna", 20, 20000);
    HourlyEmployees he("Kasun", 20, 8000, 6);
    Trainee tr("Wimal", 20, 20000, 6);
    HashTable ht(8);
    ht.put(&se);
    ht.put(&he);
    ht.put(&tr);
    cout << ht.get("Nipuna")->getMonthlyPay() << endl;
    cout << ht.get("Kasun")->getMonthlyPay() << endl;
    cout << ht.get("Wimal")->getMonthlyPay() << endl;

    return 0;


}
