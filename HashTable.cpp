//
// Created by NIPUNA on 7/2/2017.
//

#include "HashTable.h"

int HashTable::getSize() const {
    return size;
}

HashTable::HashTable(int size) : size(size) {
    link = new LinkedList[size];
}

int HashTable::get(string K) {
    return link[hash(K)].findNode(K)->getV();
}

void HashTable::put(string K, int V) {
    link[hash(K)].addNode(K, V);
}

void HashTable::remove(string K) {
    link[hash(K)].deleteNode(K);
}

unsigned HashTable::hash(string str) { //FROM STACKOVERFLOW
    const char *s = str.c_str();
    unsigned int A = 54059;
    unsigned int B = 76963;
    unsigned int FIRSTH = 37;

    unsigned h = FIRSTH;
    while (*s) {
        h = (h * A) ^ (s[0] * B);
        s++;
    }
    return h % getSize();
}
