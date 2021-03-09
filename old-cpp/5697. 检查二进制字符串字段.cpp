#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        if (s.size() == 0) return false;
        if (s[0] == '0') return false;
        int i = 0;
        for (; i < s.size(); i ++) {
            if (s[i] == '0') break;
        }
        for (; i < s.size(); i ++) {
            if (s[i] == '1') return false;
        }
        return true;
    }
};