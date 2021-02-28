#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int index = 0, ans = 0, size = items.size();
        if (size == 0) return 0;
        if (ruleKey == "type") index = 0;
        else if (ruleKey == "color") index = 1;
        else index = 2;
        for (int i = 0; i < size; i ++) {
            if (items[i][index] == ruleValue) ans ++; 
        }
        return ans;
    }
};

int main() {

}