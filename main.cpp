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
            getLast()->setNextNode(newNode);
        }
    }

    Node *getLast() {
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
    link.addNode("Nipuna", 123);
    link.addNode("Chamod", 456);
    cout << link.getLast()->K << endl;
    return 0;


}
