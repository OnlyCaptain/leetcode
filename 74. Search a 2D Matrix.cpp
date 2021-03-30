class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m*n-1, medium = (left+right)/2;
        while (left <= right) {
            medium = left + (right - left)/2;
            if (matrix[medium/n][medium%n] == target) return true;
            if (matrix[medium/n][medium%n] < target) {
                left = medium + 1;
            }
            else right = medium - 1;
        }
        return false;
    }
};