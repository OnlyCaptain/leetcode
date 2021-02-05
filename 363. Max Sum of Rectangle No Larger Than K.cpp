#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    int sumLessThanK(vector<int>& v, int k) {
        int ans = INT_MIN, size = v.size(), sum = 0;
        set<int> minSet{0};
        for (int i = 0; i < size; i ++) {
            sum += v[i];
            auto it = minSet.lower_bound(sum - k);
            if (it != minSet.end()) {
                ans = max(ans, sum - *it);
            }
            minSet.insert(sum);
        }
        return ans;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int ans = INT_MIN, row_size = matrix.size();
        if (row_size == 0) return ans;
        int col_size = matrix[0].size();
        for (int j = 0; j < col_size; j ++) {
            vector<int> subarray(row_size, 0);
            for (int jj = j; jj < col_size; jj ++) {
                for (int i = 0; i < row_size; i ++) 
                    subarray[i] += matrix[i][jj];
                ans = max(ans, sumLessThanK(subarray, k));
            }
        }
        return ans;
    }
};


int main() {

}