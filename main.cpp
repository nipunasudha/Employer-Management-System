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
//            cout << "Linked list is empty!\n";
            return nullptr;
        }
    }

    bool deleteNode(string key) {
        if (!isEmpty) {
            Node *prevNode = nullptr;
            Node *currentNode = head;
            while (true) {
                if (currentNode->K != key) {
                    if (!(currentNode->isNextSet)) {
                        return false;
                    }
                    prevNode = currentNode;
                    currentNode = currentNode->getNextNode();
                } else {
                    if (prevNode) {
                        prevNode->next = currentNode->getNextNode();
                        prevNode->isNextSet = currentNode->getNextNode() != nullptr;
                    } else {
                        if (currentNode->getNextNode()) {
                            head = currentNode->getNextNode();
                        } else {
                            isEmpty = true;
                        }
                    }
                    delete currentNode;
                    return true;
                }
            }
        } else {
//            cout << "Linked list is empty!\n";
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
//            cout << "Linked list is empty!\n";
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
    cout << link.findNode("chanaka") << endl;
    cout << link.deleteNode("chanaka") << endl;
    cout << link.findNode("chanaka") << endl;
    cout << link.getLastNode()->K << endl;


    return 0;


}
