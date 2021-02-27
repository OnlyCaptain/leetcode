#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 递归
// class Solution {
// public:
//     int longestSubstring(string s, int k) {
//         int left = 0, right = 0, ans = 0;
//         int mapping[26] {0};
//         for (int i = 0; i < s.size(); i ++)
//             mapping[s[i]-'a'] ++;
//         vector<int> indexes;
//         indexes.push_back(-1);
//         for (int i = 0; i < s.size(); i ++) {
//             if (mapping[s[i]-'a'] < k) indexes.push_back(i);
//         }
//         indexes.push_back(s.size());
//         if (indexes.size() == 2) return s.size();
//         for (int i = 0; i < indexes.size()-1; i ++) {
//             int left = indexes[i]+1, limits = indexes[i+1];
//             if (limits - left < k) continue;
//             ans = max(ans, longestSubstring(s.substr(left, limits-left), k));
//         }
//         return ans;
//     }
// };

// 滑动窗口
class Solution {
public:
    int longestSubstring(string s, int k) {
        if (k == 1 || s.size() == 0) return s.size();
        int ans = 0;
        for (int t = 1; t <= 26; t ++) {
            int total = 0, left = 0, right = 0, less = 0;
            int mapping[26]{0};
            for (; right < s.size(); right ++) {
                if (mapping[s[right]-'a'] == 0) {
                    total ++;
                    less ++;
                }
                mapping[s[right]-'a'] ++;
                if (mapping[s[right]-'a'] == k) less --;
                if (less == 0) ans = max(ans, right-left+1);
                while (total > t) {
                    mapping[s[left]-'a'] --;
                    if (mapping[s[left]-'a'] == 0) {
                        less --;
                        total --;
                    } 
                    else if (mapping[s[left]-'a'] == k-1) less ++;
                    left ++;
                }
            }
        }      
        return ans;
    }
};


int main() {

}