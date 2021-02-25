#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> mat(m+1, vector<int>(n+1,0));
        mat[0][0] = grid[0][0];
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i+1<m) {
                    if (mat[i+1][j] == 0) mat[i+1][j] = mat[i][j]+grid[i+1][j];
                    else mat[i+1][j] = min(mat[i][j]+grid[i+1][j], mat[i+1][j]);
                }
                if (j+1<n) {
                    if (mat[i][j+1] == 0) mat[i][j+1] = mat[i][j]+grid[i][j+1];
                    else mat[i][j+1] = min(mat[i][j]+grid[i][j+1], mat[i][j+1]);
                }
            }
        }
        return mat[m-1][n-1];
    }
};

int main() {

}