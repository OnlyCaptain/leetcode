#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int size = nums.size(), pre = INT_MIN, count = 0;
        for (int i = 0; i < size-1 && count != 2; i ++) {
            if (nums[i] > nums[i+1]) {
                if (pre > nums[i+1]) nums[i+1] = nums[i];
                count ++;
                pre = nums[i];
            }
        }
        return count != 2;
    }
};

int main() {

}