#ifndef CLION_EMPLOYEE_HASHTABLE_H
#define CLION_EMPLOYEE_HASHTABLE_H

#include<string>
#include "LinkedList.h"

using namespace std;

class HashTable {
private:
    int size;
public:
    LinkedList *link;

    int getSize() const;

    HashTable(int size);

    int get(string K);

    void put(string K, int V);

    void remove(string K);

    unsigned hash(string str);
};


#endif //CLION_EMPLOYEE_HASHTABLE_H
