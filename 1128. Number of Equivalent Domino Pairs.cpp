#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    string generateStr(vector<int>& v) {
        string ans;
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i ++) 
            ans += v[i] + '0';
        return ans;
    }
    int chooseTwo(int num) {
        if (num < 2) return 0;
        int ans = 1;
        for (int i = num; i > num - 2; i --) 
            ans *= i;
        return ans/2;
    }
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<string, int> mapping;
        int ans = 0;
        int size = dominoes.size();
        for (int i = 0; i < size; i ++) {
            string cur = generateStr(dominoes[i]);
            mapping[cur] ++;
        }
        for (auto it = mapping.begin(); it != mapping.end(); it ++) {
            ans += chooseTwo(it->second);

        }
        return ans;
    }
};


int main() {

}