#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
// presum Idea, Solution 1
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int size = nums.size(), sum = 0, minLen = INT_MAX;
//         vector<int> minSet{0};
//         for (int i = 0; i < size; i ++) {
//             sum += nums[i];
//             auto it = upper_bound(minSet.begin(), minSet.end(), sum-target);
//             if (it == minSet.begin()) {
//                 if (sum == target) {
//                     minLen = min(minLen, i-0+1);
//                 }
//             }
//             else {
//                 int index = it - minSet.begin() - 1;
//                 minLen = min(minLen, i-index+1);
//             }
//             minSet.push_back(sum);
//         }
//         for (auto item:minSet) cout << item << " ";
//         cout << endl;
//         if (minLen == INT_MAX) return 0;
//         return minLen;
//     }
// };


// Sliding Windows, Solution 2
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, minLen = INT_MAX, sum = 0, size = nums.size();
        for (right = 0; right < size; right ++) {
            sum += nums[right];
            while (sum >= target) {
                minLen = min(minLen, right-left+1);
                sum -= nums[left];
                left ++;
            }
        }
        if (minLen == INT_MAX) return 0;
        return minLen;
    }
};


int main() {
    vector<int> minSet{1,3,5,7,9,10,11,12};
    auto it = lower_bound(minSet.begin(), minSet.end(), 1);
    cout << (bool)(it == minSet.begin()) << endl;
    cout << it-minSet.begin() << endl;
    cout << minSet[it-minSet.begin()] << endl;
    for (auto it:minSet) cout << it << " ";
    cout << endl;
}