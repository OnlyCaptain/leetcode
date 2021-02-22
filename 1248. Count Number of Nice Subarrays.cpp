#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int oddCount = 0, left = 0, right = 0, ans = 0, size = nums.size();
        deque<int> indexes(k, -1);
        for (right = 0; right < size; right ++) {
            if (nums[right]%2) indexes.push_back(right);
            if (indexes.size() > k) indexes.pop_front();
            if (indexes.front() != -1) {
                ans ++;
                left = indexes.front()-1;
                while (left >= 0 && nums[left]%2==0) {
                    ans ++;
                    left --;
                }
            }
        }
        return ans;
    }
};

int main() {

}