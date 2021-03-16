#include <list>
#include <vector>
#include <iostream>
using namespace std;

class MyHashSet {
private:
    static const int limit = 1000;
    vector<list<int>> hashSet;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        hashSet.resize(limit);
    }
    
    void add(int key) {
        list<int>& mapping = hashSet[key%limit];
        for (auto it = mapping.begin(); it != mapping.end(); it ++) 
            if (*it == key) return;
        mapping.push_back(key);
    }
    
    void remove(int key) {
        list<int>& mapping = hashSet[key%limit];
        for (auto it = mapping.begin(); it != mapping.end(); it ++) 
            if (*it == key) {
                mapping.erase(it);
                return;
            }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        list<int>& mapping = hashSet[key%limit];
        for (auto it = mapping.begin(); it != mapping.end(); it ++)
            if (*it == key)
                return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main() {
    vector<list<int>> test(100);
}