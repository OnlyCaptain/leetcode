#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, medium = (left+right)/2;
        if (target == nums[left]) return left;
        else if (target == nums[right]) return right;
        else if (target > nums[right] || target < nums[left]) return -1;
        while (medium != left && medium != right) {
            if (target == nums[medium]) return medium;
            if (target < nums[medium]) right = medium;
            else left = medium;
            medium = (right + left)/2;
        }
        if (target == nums[medium]) return medium;
        return -1;
    }
};

int main() {

}