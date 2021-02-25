#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int row = matrix.size(), col = matrix[0].size();
        int start_i = 0, start_j = col-1;
        while (start_i < row && start_j >= 0) {
            if (matrix[start_i][start_j] == target) return true;
            if (matrix[start_i][start_j] > target) start_j --;
            else start_i ++;
            
        }
        
        return false;
    }
};

int main() {

}