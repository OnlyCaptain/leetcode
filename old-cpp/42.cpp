#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, size = height.size();
        if (size == 0) return 0;
        vector<int> leftMax(size, 0), rightMax(size, 0);
        leftMax[0] = height[0];
        rightMax[size-1] = height[size-1];
        for (int i = 1; i < size; i ++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        for (int i = size-2; i >= 0; i --) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        for (int i = 0; i < size; i ++) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
};

int main() {

}