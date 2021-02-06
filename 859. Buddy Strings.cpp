#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        int size = A.length(), noEqual = 0;
        deque<char> nA, nB;
        if (B.length() != size) return false;
        for (int i = 0; i < size; i ++) {
            if (A[i] != B[i]) {
                noEqual ++;
                nA.push_front(A[i]);
                nB.push_back(B[i]);
            }
        }
        if (noEqual == 2) {
            while (!nA.empty()) {
                if (nA.front() != nB.front()) return false;
                nA.pop_front(); nB.pop_front();
            }
            return true;
        } 
        else if (noEqual == 0) {
            unordered_map<char, int> history;
            for (int i = 0; i < size; i ++) {
                if (history.count(A[i])) 
                    return true;
                history[A[i]] ++;
            }
        }
        return false;
    }
};