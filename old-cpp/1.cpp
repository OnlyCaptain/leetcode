#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> history;
        vector<int> ans;
        int size = nums.size();
        for (int i = 0; i < size; i ++) {
            if (history.count(target-nums[i])) {
                ans.push_back(history[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            history[nums[i]] = i;
        }
    }
};

int main() {

}