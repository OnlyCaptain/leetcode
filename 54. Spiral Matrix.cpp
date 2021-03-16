#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> ans;
public:
    void dfs(vector<vector<int>>& matrix, int margin) {
        int i_begin, i_end, j_begin, j_end;
        i_begin = 0+margin; i_end = matrix.size()-1-margin;
        j_begin = 0+margin; j_end = matrix[0].size()-1-margin;
        if (i_begin > i_end || j_begin > j_end) return;
        if (i_begin == i_end) {
            for (int j = j_begin; j <= j_end; j ++) ans.push_back(matrix[i_begin][j]);
            return;
        }
        if (j_begin == j_end) {
            for (int i = i_begin; i <= i_end; i ++) ans.push_back(matrix[i][j_begin]);
            return;
        }
        int i,j;
        for (j = j_begin; j <= j_end; j ++) ans.push_back(matrix[i_begin][j]);
        for (i = i_begin+1; i <= i_end; i ++) ans.push_back(matrix[i][j_end]);
        for (j = j_end-1; j >= j_begin; j --) ans.push_back(matrix[i_end][j]);
        for (i = i_end-1; i >= i_begin+1; i --) ans.push_back(matrix[i][j_begin]);
        dfs(matrix, margin+1);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        dfs(matrix,0);
        return ans;
    }
};

int main() {

}