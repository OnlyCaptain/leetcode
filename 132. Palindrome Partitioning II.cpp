#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int size = s.size();
        vector<vector<bool>> f(size, vector<bool>(size, true));
        for (int i = size-1; i >= 0; i --) {
            for (int j = i+1; j < size; j ++) {
                f[i][j] = f[i+1][j-1] && (s[i] == s[j]);
            }
        }

        vector<int> counts(size, INT_MAX);
        for (int i = 0; i < size; i ++) {
            if (f[0][i]) counts[i] = 0;
            else {
                for (int j = 0; j < i; j ++) {
                    if (f[j+1][i]) {
                        counts[i] = min(counts[i], counts[j] + 1);
                        // break;
                    }
                }
            }
        }
        return counts[size-1];
    }
};
int main() {

}