#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        deque<int> nums;
        while (n >= 10) {
            nums.push_front(n%10);
            n /= 10;
        }
        nums.push_front(n%10);
        if (nums.size() <= 1) return -1;
        vector<int> rightMax(nums.size(), 0);
        int size = nums.size(), i = size-2;
        rightMax[size-1] = nums[size-1];
        for (; i >= 0; i --) {
            rightMax[i] = (nums[i] > rightMax[i+1])?nums[i]:rightMax[i+1];
            if (rightMax[i] > nums[i]) {
                sort(nums.begin()+i+1, nums.end());
                for (int j = i+1; j < size; j ++) {
                    if (nums[j] > nums[i]) { 
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
                break;
            }
        }
        if (i == -1) return -1;
        sort(nums.begin()+i+1, nums.end());
        long long ans = 0;
        for (int i = 0; i < nums.size(); i ++) {
            ans *= 10;
            ans += nums[i];
        }
        if (ans > INT_MAX) return -1;
        return ans;
        
    }
};

int main() {

}