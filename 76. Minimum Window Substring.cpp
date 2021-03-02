#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() == 0 || s.size() == 0) return "";
        unordered_map<char, int> mapping;
        int less = 0, size = s.size(), minLen = INT_MAX, left = 0, right = 0;
        string ans = "";
        for (auto i:t) {
            if (!mapping.count(i)) less ++;
            mapping[i] ++;
        }
        for (;right < size; right ++) {
            if (mapping.count(s[right])) {
                mapping[s[right]] --;
                if (mapping[s[right]] == 0) less --;
            }
            while (less == 0) {
                if (less == 0) {
                    if (minLen > right-left+1) {
                        ans = s.substr(left, right-left+1);
                    }
                    minLen = min(minLen, right-left+1);
                } 
                if (mapping.count(s[left])) {
                    mapping[s[left]] ++;
                    if (mapping[s[left]] == 1) less ++;
                }
                left ++;
            }
        }
        return ans;
    }
};

int main() {
    
}