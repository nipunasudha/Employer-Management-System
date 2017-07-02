
#ifndef A2DD_H
#define A2DD_H

#include<string>

using namespace std;

class Node {
private:
public:
    string K;
    int V;
    bool isNextSet;
    Node *next;

    Node(string k, int v);

    Node *getNextNode();

    void setNextNode(Node *node);


};


class LinkedList {
private:
public:
    Node *head;
    bool isEmpty;

    LinkedList();

    void addNode(string key, int value);

    Node *findNode(string key);

    bool deleteNode(string key);

    Node *getLastNode();
};


#endif