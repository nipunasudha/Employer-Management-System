#include<iostream>
#include "HashTable.h"

using namespace std;


int main() {
    cout << "Welcome to the program!" << endl;
    HashTable ht(10);
    ht.put("Ngfgg", 1612);
    ht.put("gfdgg", 2312);
    ht.put("gdfgdf", 332);
    ht.put("bbb", 44612);
    ht.put("fdggdfg", 582);
    ht.put("gdfgdf", 63422);
    ht.put("gfdsgd", 7802);
    ht.put("dgfgdf", 8242);
    cout << ht.get("bbb") << endl;
    ht.remove("bbb");
    return 0;


}
