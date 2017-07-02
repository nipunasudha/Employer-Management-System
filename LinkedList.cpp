
#include "LinkedList.h"


Node::Node(string k, int v) : K(k), V(v) {
    setNextSet(false);
}

Node *Node::getNextNode() {
    if (isNextSet()) {
        return next;
    } else {
        return nullptr;
    }
}

void Node::setNextNode(Node *node) {
    next = node;
    setNextSet(true);
}

const string &Node::getK() const {
    return K;
}

void Node::setK(const string &K) {
    Node::K = K;
}

int Node::getV() const {
    return V;
}

void Node::setV(int V) {
    Node::V = V;
}

bool Node::isNextSet() const {
    return nextSet;
}

void Node::setNextSet(bool nextSet) {
    Node::nextSet = nextSet;
}


LinkedList::LinkedList() {
    isEmpty = true;
}

void LinkedList::addNode(string key, int value) {
    Node *newNode = new Node(key, value);
    if (isEmpty) {
        head = newNode;
        isEmpty = false;
    } else {
        getLastNode()->setNextNode(newNode);
    }
}

Node *LinkedList::findNode(string key) {
    if (!isEmpty) {
        Node *currentNode = head;
        while (true) {
            if (currentNode->getK() != key) {
                if (!(currentNode->isNextSet())) {
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

bool LinkedList::deleteNode(string key) {
    if (!isEmpty) {
        Node *prevNode = nullptr;
        Node *currentNode = head;
        while (true) {
            if (currentNode->getK() != key) {
                if (!(currentNode->isNextSet())) {
                    return false;
                }
                prevNode = currentNode;
                currentNode = currentNode->getNextNode();
            } else {
                if (prevNode) {
                    prevNode->next = currentNode->getNextNode();
                    prevNode->setNextSet(currentNode->getNextNode() != nullptr);
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

Node *LinkedList::getLastNode() {
    if (!isEmpty) {
        Node *currentNode = head;
        while (true) {
            if (currentNode->isNextSet()) {
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
