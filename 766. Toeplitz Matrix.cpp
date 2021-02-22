#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < col; j ++) {
                if (i > 0 && j > 0 && matrix[i][j] != matrix[i-1][j-1]) return false;
            }
        }
        return true;
    }
};

int main() {

}