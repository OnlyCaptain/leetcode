#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxd, mind;
        int left = 0, right = 0, ans = 0, size = nums.size();
        for (right = 0; right < size; right ++) {
            // push 
            while (!maxd.empty() && maxd.back() < nums[right]) maxd.pop_back();
            while (!mind.empty() && mind.back() > nums[right]) mind.pop_back();
            maxd.push_back(nums[right]);
            mind.push_back(nums[right]);
            // push end

            if (maxd.front() - mind.front() <= limit) {
                ans = max(ans, right-left+1);
            }
            else {
                // pop the element nums[left], which means the sliding windows slides.
                if (maxd.front() == nums[left]) maxd.pop_front();
                if (mind.front() == nums[left]) mind.pop_front();
                left ++;
            }
        }
        return ans;
    }
};