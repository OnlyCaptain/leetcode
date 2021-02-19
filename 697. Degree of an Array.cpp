#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, pair<int, int>> indexes;
        unordered_map<int, int> counts;
        for (int i = 0; i < nums.size(); i ++) {
            if (indexes.count(nums[i])) indexes[nums[i]].second = i;
            else indexes[nums[i]] = pair<int,int>(i,0);
            counts[nums[i]] ++;
        }
        int ans = INT_MAX, val = 0, degree = 0;
        for (auto it = counts.begin(); it != counts.end(); it ++) {
            if (degree <= (*it).second) {
                ans = min(ans, indexes[(*it).first].second - indexes[(*it).first].first);
                degree = max(degree, (*it).second);
            }
        }
        return ans;
    }
};

int main() {

}