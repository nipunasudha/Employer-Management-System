
#ifndef A2DD_H
#define A2DD_H

#include<string>

using namespace std;

class Node {
private:
    string K;
    int V;
    bool nextSet;
public:
    Node *next;

//==================================
    const string &getK() const;

    void setK(const string &K);

    int getV() const;

    void setV(int V);

    bool isNextSet() const;

    void setNextSet(bool nextSet);

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