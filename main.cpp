#include<iostream>
#include"LinkedList.h"

using namespace std;



int main() {
    cout << "Welcome to the program!" << endl;
    LinkedList link;
    link.addNode("nipuna", 123);
    link.addNode("chamod", 456);
    link.addNode("kusal", 356);
    link.addNode("pivi", 783);
    link.addNode("viboda", 120);
    link.addNode("chanaka", 411);
    cout << link.getLastNode()->getK() << endl;
    cout << link.findNode("chanaka") << endl;
    cout << link.deleteNode("chanaka") << endl;
    cout << link.findNode("chanaka") << endl;
    cout << link.getLastNode()->getK() << endl;


    return 0;


}
