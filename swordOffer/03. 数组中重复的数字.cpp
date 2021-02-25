#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; i ++) {
            while (nums[i] != i) {
                int tmp = nums[i];
                if (nums[tmp] == tmp) return tmp;
                nums[i] = nums[tmp];
                nums[tmp] = tmp;
            }
        }
        return 0;
    }
};