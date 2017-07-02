
#ifndef LINKEDLIST
#define LINKEDLIST

#include<string>
#include "People.h"

using namespace std;

class Node {
private:
    string K;
    Person *V;
    bool nextSet;
    Node *next;
public:

//==================================
    const string &getK() const;

    void setK(const string &K);

    Person *getV() const;

    void setV(Person *V);

    bool isNextSet() const;

    void setNextSet(bool nextSet);

    void setNext(Node *next);

//-------------------------
    Node(string k, Person *v);

    Node *getNextNode();

    void setNextNode(Node *node);


};


class LinkedList {
private:
public:
    Node *head;
    bool isEmpty;

    LinkedList();

    void addNode(string key, Person *value);

    Node *findNode(string key);

    bool deleteNode(string key);

    Node *getLastNode();
};


#endif