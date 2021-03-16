#include <iostream>
#include <vector>
#include <list>
using namespace std;

class MyHashMap {
private:
    static const int base = 1000;
    vector<list<pair<int,int>>> hashMap;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        hashMap.resize(base);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        list<pair<int,int>>& curMap = hashMap[key%base];
        for (auto it = curMap.begin(); it != curMap.end(); it ++) {
            if ((*it).first == key) {
                (*it).second = value;
                return;
            }
        }
        curMap.push_back(pair<int,int>(key,value));
        return;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        list<pair<int,int>>& curMap = hashMap[key%base];
        for (auto it = curMap.begin(); it != curMap.end(); it ++) {
            if ((*it).first == key) {
                return (*it).second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        list<pair<int,int>>& curMap = hashMap[key%base];
        for (auto it = curMap.begin(); it != curMap.end(); it ++) {
            if ((*it).first == key) {
                curMap.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main() {

}