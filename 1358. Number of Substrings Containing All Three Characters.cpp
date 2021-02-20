#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int len = s.size(), ans = 0;
        int last[3] = {-1,-1,-1};
        for (int i = len-1; i >= 0; i --) {
            last[s[i] - 'a'] = i;
            if (last[0] != -1 && last[1] != -1 && last[2] != -1) {
                ans += len - max({last[0], last[1], last[2]});
            }
        }
        return ans;
    }
};

int main() {

}