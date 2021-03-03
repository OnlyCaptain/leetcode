#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxOfWindows(vector<bool>& sub) {
        int left = 0, right = 0, sum = 0, ans = 0;
        for (int i = 0; i < sub.size(); i ++) {
            if (sub[i]) sum ++;
            else {
                ans = max(sum, ans);
                sum = 0;
            } 
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int row = matrix.size(), col = matrix[0].size(), ans = 0;
        for (int j = 0; j < col; j ++) {
            vector<bool> sub(row, 0);
            for (int k = j; k < col; k ++) {
                for (int i = 0; i < row; i ++) {
                    sub[i] = sub[i] & matrix[i][k]=='1';               
                }
                ans = max(ans, maxOfWindows(sub));
            }
        }
        return ans;
    }
};

int main() {

}