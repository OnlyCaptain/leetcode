#include<iostream>
#include<vector>
#include<unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mapping;
        int size = nums.size();
        if (size == 0) return 0;
        mapping[0] = 1;
        int sum = 0, ans = 0;
        for (int i = 0; i < size; i ++) {
            sum += nums[i];
            if (mapping.count(sum - k))
                ans += mapping[sum - k];
            mapping[sum] ++;
        }
        return ans;
    }
};

int main() {
    map<int,int> mapping;
    // mapping[0] ++;
    cout << mapping[1] << endl;
}