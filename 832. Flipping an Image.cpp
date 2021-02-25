#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if (A.size() == 0) return vector<vector<int>>();
        int row = A.size(), col = A[0].size();
        vector<vector<int>> ans(row, vector<int>(col,0));
        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < col; j ++) {
                ans[i][j] = !A[i][col-j-1];
            }
        }
        return ans;
    }
};

int main() {

}