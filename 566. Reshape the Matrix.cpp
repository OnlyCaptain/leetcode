#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.size() == 0) return nums;
        int m = nums.size(), n = nums[0].size();
        if (n*m != r*c) return nums;
        vector<vector<int>> ans(r, vector<int>(c,0));
        for (int i = 0; i < m*n; i ++) {
            ans[i/c][i%c] = nums[i/n][i%n];
        }
        return ans;
    }
};

int main() {

}