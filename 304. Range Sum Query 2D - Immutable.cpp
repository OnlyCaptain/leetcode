#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

class NumMatrix {
public:
    int** matrix_sum;
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size()==0 || matrix[0].size() == 0) return;
        matrix_sum = new int*[matrix.size()+1];
        for (int i = 0; i < matrix.size()+1; i ++) {
            matrix_sum[i] = new int[matrix[0].size()+1];
            memset(matrix_sum[i], 0, sizeof(int)*(matrix[0].size()+1));
        }
        for (int i = 0; i < matrix.size(); i ++) {
            for (int j = 0; j < matrix[0].size(); j ++) {
                matrix_sum[i+1][j+1] = matrix_sum[i][j+1] + matrix_sum[i+1][j] - matrix_sum[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return  matrix_sum[row2+1][col2+1] - matrix_sum[row1][col2+1] - matrix_sum[row2+1][col1] + matrix_sum[row1][col1];
    }
};


int main() {

}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */