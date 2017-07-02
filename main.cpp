#include<iostream>

using namespace std;

class Node {
private:
public:
    string K;
    int V;
    bool isNextSet;
    Node *next;

    Node(string k, int v) : K(k), V(v) {
        isNextSet = false;
    }

    Node *getNextNode() {
        if (isNextSet) {
            return next;
        } else {
            return nullptr;
        }
    }

    void setNextNode(Node *node) {
        next = node;
        isNextSet = true;
    }


};


class LinkedList {
private:
public:
    Node *head;
    bool isEmpty;

    LinkedList() {
        isEmpty = true;
    }

    void addNode(string key, int value) {
        Node *newNode = new Node(key, value);
        if (isEmpty) {
            head = newNode;
            isEmpty = false;
        } else {
            getLastNode()->setNextNode(newNode);
        }
    }

    Node *findNode(string key) {
        if (!isEmpty) {
            Node *currentNode = head;
            while (true) {
                if (currentNode->K != key) {
                    if (!(currentNode->isNextSet)) {
                        currentNode = nullptr;
                        break;
                    }
                    currentNode = currentNode->getNextNode();
                } else {
                    break;
                }
            }
            return currentNode;
        } else {
            cout << "Linked list is empty!\n";
            return nullptr;
        }
    }

    bool deleteNode(string key) {
        if (!isEmpty) {
            Node *currentNode = head;
            while (true) {
                if (!(currentNode->isNextSet)) {
                    if (currentNode->getNextNode()->K == key) {
                        if (currentNode->getNextNode()->isNextSet) {
                            currentNode->next = currentNode->getNextNode()->getNextNode();
                        } else {
                            currentNode->isNextSet = false;
                        }

                        delete currentNode->getNextNode();
                        return true;
                    }
                } else {
                    if (currentNode->K == key) {
                        delete currentNode;
                        //this is faulty
                    }

                }
            }

        } else {
            cout << "Linked list is empty!\n";
            return false;
        }
    }

    Node *getLastNode() {
        if (!isEmpty) {
            Node *currentNode = head;
            while (true) {
                if (currentNode->isNextSet) {
                    currentNode = currentNode->getNextNode();
                } else {
                    break;
                }
            }
            return currentNode;
        } else {
            cout << "Linked list is empty!\n";
            return nullptr;
        }

    }
};


int main() {
    cout << "Welcome to the program!" << endl;
    LinkedList link;
    link.addNode("nipuna", 123);
    link.addNode("chamod", 456);
    link.addNode("kusal", 356);
    link.addNode("pivi", 783);
    link.addNode("viboda", 120);
    link.addNode("chanaka", 411);
    cout << link.getLastNode()->K << endl;
    cout << link.findNode("pivi")->K << endl;
    return 0;


}
