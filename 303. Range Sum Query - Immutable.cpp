#include <iostream>
#include <vector>
using namespace std;


class NumArray {
public:
    vector<int> presum;
    NumArray(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i ++) {
            sum += nums[i];
            presum.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0) return presum[j];
        return presum[j]-presum[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

int main() {
    
}