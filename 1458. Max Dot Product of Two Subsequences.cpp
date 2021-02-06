#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        vector<vector<int>> mat(size1+1, vector<int>(size2+1, INT_MIN));
        for (int i = 1; i <= size1; i ++) {
            for (int j = 1; j <= size2; j ++) {
                int cur_dot = nums1[i-1]*nums2[j-1];
                mat[i][j] = max({cur_dot, mat[i-1][j-1]+cur_dot, mat[i-1][j], mat[i][j-1]});
            }
        }
        return mat[size1][size2];
    }
};

int main() {

}