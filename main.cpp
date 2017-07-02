#include<iostream>
#include "People.h"

using namespace std;


int main() {
    cout << "Welcome to the program!" << endl;
    SalariedEmployees se("Nipuna", 20, 20000);
    HourlyEmployees he("Kasun", 20, 8000, 6);
    Trainee tr("Wimal", 20, 20000, 6);


    return 0;


}
