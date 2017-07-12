//
// Created by NIPUNA on 7/2/2017.
//
#include<vector>
#include "HashTable.h"
#include "Utils.h"
int HashTable::getSize() const {
    return size;
}

HashTable::HashTable(int size) : size(size) {
    link = new LinkedList[size];
}

Person *HashTable::get(string K) {
    Node *foundNode = link[hash(K)].findNode(K);
    return foundNode != nullptr ? foundNode->getV() : nullptr;
}

void HashTable::put(Person *V) {
    string K = V->getId();
    link[hash(K)].addNode(K, V);
}

bool HashTable::remove(string K) {
    getAll();
    //return link[hash(K)].deleteNode(K);

    //cout<<hash(K)<<"="<<link[hash(K)].traverse().at(0)->getName();
    return true;
}
vector<Person*> HashTable::getAll(){
    vector<Person*> v={};
    for(int i=0;i<size;i++){
        cout<<"+"<<endl;
        vector<Person*> results=link[i].traverse();
        cout<<results.size()<<endl;
        if(results.size()>0){
            utils::concatVec(v,results);
            cout<<link[i].traverse().at(0)->getName()<<endl;
        }
    }
    cout << "The size of all is "<<v.size()<<endl;
    return v;
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


//GUIDE
//HashTable ht(10);
//ht.put("Ngfgg", 1612);
//ht.put("gfdgg", 2312);
//ht.put("gdfgdf", 332);
//ht.put("bbb", 44612);
//ht.put("fdggdfg", 582);
//ht.put("gdfgdf", 63422);
//ht.put("gfdsgd", 7802);
//ht.put("dgfgdf", 8242);
//cout << ht.get("bbb") << endl;
//ht.remove("bbb");
