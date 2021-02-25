#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> mat(m+1, vector<int>(n+1,0));
        mat[0][0] = 1;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                mat[i+1][j] += mat[i][j];
                mat[i][j+1] += mat[i][j];
            }
        }
        return mat[m-1][n-1];
    }
};

int main() {

}