#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& matrix, int margin, int start) {
        int i_begin, i_end, j_begin, j_end;
        i_begin = 0+margin; i_end = matrix.size()-1-margin;
        j_begin = 0+margin; j_end = matrix[0].size()-1-margin;
        if (i_begin > i_end || j_begin > j_end) return;
        if (i_begin == i_end) {
            for (int j = j_begin; j <= j_end; j ++) matrix[i_begin][j] = start++;
            return;
        }
        if (j_begin == j_end) {
            for (int i = i_begin; i <= i_end; i ++) matrix[i][j_begin] = start++;
            return;
        }
        int i,j;
        for (j = j_begin; j <= j_end; j ++) matrix[i_begin][j] = start++;
        for (i = i_begin+1; i <= i_end; i ++) matrix[i][j_end] = start++;
        for (j = j_end-1; j >= j_begin; j --) matrix[i_end][j] = start++;
        for (i = i_end-1; i >= i_begin+1; i --) matrix[i][j_begin] = start++;
        dfs(matrix, margin+1, start);
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n,0));
        dfs(matrix, 0, 1);
        return matrix;
    }
};

int main() {

}