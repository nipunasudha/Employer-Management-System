#include<iostream>
#include"LinkedList.h"

using namespace std;

class HashTable {
private:
    int size;
public:
    LinkedList *link;

    int getSize() const {
        return size;
    }

    HashTable(int size) : size(size) {
        link = new LinkedList[size];
    }

    int get(string K) {
        return link[hash(K)].findNode(K)->getV();
    }

    void put(string K, int V) {
        link[hash(K)].addNode(K, V);
    }

    void remove(string K) {
        link[hash(K)].deleteNode(K);
    }

    unsigned hash(string str) { //FROM STACKOVERFLOW
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
};


int main() {
    cout << "Welcome to the program!" << endl;
    HashTable ht(10);
    ht.put("Ngfgg", 1612);
    ht.put("gfdgg", 2312);
    ht.put("gdfgdf", 332);
    ht.put("bbb", 44612);
    ht.put("fdggdfg", 582);
    ht.put("gdfgdf", 63422);
    ht.put("gfdsgd", 7802);
    ht.put("dgfgdf", 8242);
    cout << ht.get("bbb") << endl;
    ht.remove("bbb");
    return 0;


}
